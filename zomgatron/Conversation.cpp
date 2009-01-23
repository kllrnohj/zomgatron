#include "Conversation.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include "StringUtils.h"
#include "FileUtils.h"
#include "EncryptionUtils.h"
#include "CheckButton.h"
using namespace std;



/*

0101
1111
1010
1111
0101

*/

// manually create (shouldn't be used often if at all)
Conversation::Conversation(ConversationChoice** choices, int numChoices, string text, string name){
	Conversation::allConversations.push_back(this);
	this->name = name;
	this->text = text;
	this->choices = choices;
	this->numChoices = numChoices;
	this->Start();
}

void Conversation::Start(){
	// create the window
	Vector2 position((EngineStatics::Engine->GetWidth() - DIALOG_WIDTH) / 2, (EngineStatics::Engine->GetHeight() - DIALOG_HEIGHT) / 2);
	Window* mainWindow = new Window();
	Quad val;
	val.left = (long)position.x;
	val.top = (long)position.y;
	val.right = val.left + DIALOG_WIDTH;
	val.bottom = val.top + DIALOG_HEIGHT;
	mainWindow->SetRect(val);
	Label* text = new Label(DIALOG_MAXX - DIALOG_FIRSTX, DIALOG_MAXY - DIALOG_FIRSTY - 64, this->text);
	Quad label;
	label.left = DIALOG_FIRSTX + val.left;
	label.top = DIALOG_FIRSTY + val.top;
	label.right = label.left + (DIALOG_MAXX - DIALOG_FIRSTX);
	label.bottom = label.top + (DIALOG_MAXY - DIALOG_FIRSTY - ((CHECKBUTTON_HEIGHT+ 16) * this->numChoices));
	text->SetRect(label);
	mainWindow->GetChildren()->push_back(text);

	for(int x = 0; x < this->numChoices; x++){
		CheckButton* b = new CheckButton(Conversation::MakeConversationChoice);
		Quad button;
		button.top = label.bottom + ((CHECKBUTTON_HEIGHT + 16) * x) + 16; // that gives 2 lines zomg!
		//button.left = label.left + (((DIALOG_MAXX - DIALOG_FIRSTX) - BUTTON_WIDTH) / 2);
		button.left = label.left;
		button.bottom = button.top + CHECKBUTTON_HEIGHT;
		button.right = button.left + CHECKBUTTON_WIDTH;
		b->SetRect(button);
		b->SetInfo(this->choices[x]);
		mainWindow->GetChildren()->push_back(b);
		Label* l = new Label((label.right - label.left) - (button.right - button.left) - 16, 2 * (button.bottom - button.top), this->choices[x]->getChoiceText());
		Quad label2;
		label2.left = button.right+16;
		label2.top = button.top;
		label2.bottom = label2.top + (2 * button.bottom - (label2.top));
		label2.right = label.right;
		l->SetRect(label2);
		mainWindow->GetChildren()->push_back(l);
	}

	this->window = mainWindow;
}
void Conversation::Show(){
	this->window->SetOpen(true);
	EngineStatics::Engine->SetOpenWindow(this->window);
}
void Conversation::Hide(){
	this->window->SetOpen(false);/*
	if(Conversation::game->GetOpenWindow() == this->window){
		Conversation::game->SetOpenWindow(NULL);
	}*/
}
void Conversation::End(ConversationChoice* choice){
	// need to notify dialog system of change in dialog or end of dialog
}

// static management stuff

std::vector<Conversation*> Conversation::allConversations;
void Conversation::CompileConversation(std::string uncompiledfilename){
	ifstream ifile(uncompiledfilename.c_str(), ios::in);
	string compiledFilename(CONVERSATIONS_DIR);
	compiledFilename += StringUtils::FilenameOnly(uncompiledfilename);
	compiledFilename += COMPILEDCONVERSATIONEXT;
	ofstream ofile(compiledFilename.c_str(), ios::out|ios::binary);

	/*
	FORMAT UNCOMPILED:
	actual dialog text
	3
	Hey there how's it going?
	HAPPY_RESPONSE
	Shut the hell up faggot.
	APPALED_RESPONSE
	Sorry, gotta Go!
	NULL

	FORMAT COMPILED: (ENCRYPTION NOT SHOWN)
	actual dialog text
	3
	25Hey there how it going?14HAPPY_RESPONSE
	....etc
	*/

	short len = -1, elen = -1;
	string dialogtext;
	getline(ifile, dialogtext);
	len = dialogtext.length();
	elen = len;
	EncryptionUtils::EncryptDecryptShort(elen);
	char* etext = new char[len];
	memcpy(etext, dialogtext.c_str(), len);
	EncryptionUtils::EncryptBuf(etext, len);
	ofile << elen;
	ofile.write(etext, len);
	ofile << endl;
	delete [] etext;

	short numChoices;
	ifile >> numChoices;
	FileUtils::AbsorbEndline(ifile);

	short compiledNumChoices = numChoices;
	EncryptionUtils::EncryptDecryptShort(compiledNumChoices);
	ofile << compiledNumChoices << endl;

	for(int i = 0; i < numChoices; i++){
		string line1;
		string line2;

		getline(ifile, line1);
		getline(ifile, line2);

		short len1, len2;
		len1 = line1.length();
		len2 = line2.length();
		short elen1 = len1, elen2 = len2;
		EncryptionUtils::EncryptDecryptShort(elen1);
		EncryptionUtils::EncryptDecryptShort(elen2);
		char* eline1 = new char[len1+1];
		char* eline2 = new char[len2+1];
		eline1[len1] = 0;
		eline2[len2] = 0;
		memcpy(eline1, line1.c_str(), len1);
		memcpy(eline2, line2.c_str(), len2);
		EncryptionUtils::EncryptBuf(eline1, len1);
		EncryptionUtils::EncryptBuf(eline2, len2);

		ofile << elen1;
		ofile.write(eline1, len1);
		ofile << elen2;
		ofile.write(eline2, len2);
		ofile << endl;

		delete [] eline1;
		delete [] eline2;
	}

	ifile.close();
	ofile.close();
}
Conversation* Conversation::FromFile(string compiledfilename){
	short sign = 1;
	short var = 1;
	ifstream file;
	file.open(compiledfilename.c_str(), ios::in|ios::binary);
	string name = StringUtils::FilenameOnly(compiledfilename);
	/*file.seekg(0, ios::end);
	long end = file.tellg();
	file.seekg(0, ios::beg);
	char* buf = new char[end];
	file.read(buf, end);*/

	short textlen;
	file >> textlen;
	EncryptionUtils::EncryptDecryptShort(textlen);
	char* text = new char[textlen+1];
	text[textlen] = 0;
	file.read(text, textlen);
	EncryptionUtils::DecryptBuf(text, textlen);
	FileUtils::AbsorbEndline(file);

	short dialogOptionsCount = -1;
	file >> dialogOptionsCount;
	EncryptionUtils::EncryptDecryptShort(dialogOptionsCount);
	ConversationChoice** choices =  new ConversationChoice*[dialogOptionsCount];
	string* choicesResult = new string[dialogOptionsCount];
	
	FileUtils::AbsorbEndline(file);
	for(int i = 0; i < dialogOptionsCount; i++){
		short textLength;
		file >> textLength;
		EncryptionUtils::EncryptDecryptShort(textLength);
		char* buf = new char[textLength+1];
		ZeroMemory(buf, textLength+1);
		file.read(buf, textLength);
		EncryptionUtils::DecryptBuf(buf, textLength);

		short resultLength;
		file >> resultLength;
		EncryptionUtils::EncryptDecryptShort(resultLength);
		char* buf2 = new char[resultLength+1];
		ZeroMemory(buf2, resultLength+1);
		file.read(buf2, resultLength);
		EncryptionUtils::DecryptBuf(buf2, resultLength);

		FileUtils::AbsorbEndline(file);

		choices[i] = new ConversationChoice();
		choices[i]->setChoiceText(std::string(buf));
		choicesResult[i] = string(buf2);
		//choices[i]->setResult(Conversation::GetConversation(std::string(buf2)));

		delete [] buf;
		delete [] buf2;
	}

	file.close();

	Conversation* temp = new Conversation(choices, dialogOptionsCount, string(text), name);

	for(int i = 0; i < dialogOptionsCount; i++){
		if(choicesResult[i] == name){
			choices[i]->setResult(temp);
		}else{
			choices[i]->setResult(Conversation::GetConversation(choicesResult[i]));
		}
	}
	delete [] choicesResult;
	delete [] text;
	return temp;
}
Conversation* Conversation::GetConversation(std::string name){
	if(name == "NULL")
		return NULL;
	for(int x = 0; x < Conversation::allConversations.size(); x++){
		if(allConversations.at(x)->getName() == name)
			return allConversations.at(x);
	}

	// got here means they requested one that's not in memory, I guess we should load it...
	string newFilename(CONVERSATIONS_DIR);
	newFilename += name;
	newFilename += COMPILEDCONVERSATIONEXT;
	if(FileUtils::FileExists(newFilename)){
		// it exists, load it
		return Conversation::FromFile(newFilename);
	}else{
		string newFilename2(UNCOMPILEDCONVERSATIONS_DIR);
		newFilename2 += name;
		newFilename2 += UNCOMPILEDCONVERSATIONEXT;
		if(FileUtils::FileExists(newFilename2)){
			CompileConversation(newFilename2);
			return Conversation::FromFile(newFilename);
		}
	}

	// got here means the file didn't exist, so that conversation simply doesn't exist
	return NULL;
}

void Conversation::MakeConversationChoice(UIBase* caller){
	ConversationChoice* s = (ConversationChoice*) caller->GetInfo();
	// game->openWindow should be the old conversation...
	// so kill that window and go to the next conversation
	EngineStatics::Engine->GetOpenWindow()->SetOpen(false);
	Conversation* c = s->getResult();
	if(c){
		c->Show();
	}
}