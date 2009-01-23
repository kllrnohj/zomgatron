#include "Character.h"
#include "StringUtils.h"
#include "FileUtils.h"

using namespace std;

float Character::EffectivePassion(){
	return passion;
}
float Character::EffectiveStrength(){
	return strength;
}
float Character::EffectiveIntelligence(){
	return intelligence;
}
float Character::EffectiveEndurance(){
	return endurance;
}
float Character::EffectiveAlacrity(){
	return alacrity;
}

// so as to be effected by stats
int Character::HpMax() { 
	return (int)(10.0f * EffectiveEndurance());
}
int Character::ManaMax() {
	return (int)(5.0f * EffectiveIntelligence());
}
float Character::Armor() {
	// NOT YET LOGARITHMIC... THIS SHOULD BE FASTER THOUGH FOR NOW
	return baseArmor + (1.0f + (0.2f * EffectiveEndurance()) + (0.4f * EffectiveAlacrity()));
} // logarithmic armor function
float Character::Speed() {
	return baseSpeed + (0.1f * EffectiveAlacrity());
} // 1 = normal, 2 = 2x, .5 = 1/2 ... etc
float Character::AttackRange(){
	return baseAttackRange + (EffectiveStrength() * 0.1f);
}
float Character::AttackAngleUD(){
	return baseAttackAngleUD + (EffectiveStrength() * 0.5f);
}
float Character::AttackAngleLR(){
	return baseAttackAngleLR + (EffectiveAlacrity() * 0.5f);
}


void DecodeLine(BaseCharacterData* baseData, string line){
	int num;
	string* sides = StringUtils::SplitString(line, ':', &num);
	if(num != 2){
		delete [] sides;
		throw "Invalid raw file line passed to DecodeLine: Not Key-Value.";
	}

	// find out what sides[0] (key) is and set the value accordingly
	if(StringUtils::CaselessCompare(sides[0], "strength")){
		baseData->strength = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "passion")){
		baseData->passion = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "endurance")){
		baseData->endurance = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "intelligence")){
		baseData->intelligence = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "alacrity")){
		baseData->alacrity = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "speed")){
		baseData->baseSpeed = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "armor")){
		baseData->baseArmor = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "attack range")){
		baseData->baseAttackRange= atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "vertical attack reach")){
		baseData->baseAttackAngleUD = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "horizontal attack reach")){
		baseData->baseAttackAngleLR = atof(sides[1].c_str());
	}else if(StringUtils::CaselessCompare(sides[0], "conversation")){
		baseData->conversations.push_back(sides[1]);
	}else{
		delete [] sides;
		throw "Invalid raw file line passed to DecodeLine: Invalid Key.";
	}

	delete [] sides;
}

Character* Character::FromFile(std::string filename){
	ifstream ifile(filename.c_str(), ios::in|ios::binary);
	string name;
	string id = StringUtils::FilenameOnly(filename);
	getline(ifile, name);
	string meshfilename;
	getline(ifile, meshfilename);
	FileUtils::AbsorbEndline(ifile);

	void* materials;
	void* textures;
	void* mesh;
	int numMaterials;
	mesh = EngineStatics::Engine->LoadMeshFromFile(meshfilename.c_str(), &materials, &textures, &numMaterials);

	Character* result = new Character(mesh, materials, textures, numMaterials);
	result->name = name;
	result->id = id;
	ifile >> result->passion;
	ifile >> result->strength;
	ifile >> result->endurance;
	ifile >> result->intelligence;
	ifile >> result->alacrity;
	ifile >> result->baseSpeed;
	ifile >> result->baseArmor;
	ifile >> result->baseAttackRange;
	ifile >> result->baseAttackAngleUD;
	ifile >> result->baseAttackAngleLR;
	vector<Conversation*> conversations;
	string temp;
	FileUtils::AbsorbEndline(ifile);
	while(!ifile.eof()){
		getline(ifile, temp);
		conversations.push_back(Conversation::GetConversation(temp));
		FileUtils::AbsorbEndline(ifile);
	}
	result->numConversations = conversations.size();
	result->conversations = new Conversation*[result->numConversations];
	for(int x = 0; x < result->numConversations; x++){
		result->conversations[x] = conversations.at(x);
	}

	ifile.close();
	return result;
}
void Character::CompileCharacter(std::string uncompiledfilename){
	/*
	STANDARD FORMAT IS A SERIES OF KEY-VALUE PAIRS IN THIS FORMAT:
	strength:1.0
	IT IS CASE INSENSITIVE
	*/
	BaseCharacterData* baseData = new BaseCharacterData();
	string meshname;
	string charname;
	ifstream ifile(uncompiledfilename.c_str(), ios::in);
	getline(ifile, meshname);
	getline(ifile, charname);
	string filename = "Data/X/";
	filename += meshname;
	filename += "/";
	filename += meshname;
	filename += ".x";
	baseData->meshFilename = filename;
	baseData->charname = charname;
	//LPD3DXMESH mesh;
	//LPD3DXMATERIAL materials;
	//D3DXLoadMeshFromX(filename.c_str(), D3DXMESH_MANAGED, d3ddev, NULL, &materials, NULL, NULL, &mesh);
	vector<string> lines;
	while(!ifile.eof()){
		string temp;
		getline(ifile, temp);
		// avoid comments and emptiness
		if(temp.length() > 0 && temp.c_str()[0] != '#'){
			lines.push_back(temp);
		}
	}
	ifile.close();

	for(int x = 0; x < lines.size(); x++){
		DecodeLine(baseData, lines.at(x));
	}

	// now we have all character data in RAM, just save it off to compiled file

	/*
	COMPILED FORMAT IS AS FOLLOWS:
	charname
	meshfilename
	passionstrengthenduranceintelligencealacrityspeedarmorattackrangeverticalattackreachhorizontalattackreach
	conversation
	conversation
	conversation
	*/
	string filenameOnly = StringUtils::FilenameOnly(uncompiledfilename);
	string compiledFilename = CHARACTERS_DIR;
	compiledFilename += filenameOnly;
	compiledFilename += COMPILEDCHARACTEREXT;
	ofstream ofile(compiledFilename.c_str(), ios::out | ios::binary);
	ofile << baseData->charname << endl << baseData->meshFilename << endl;
	ofile << baseData->passion << " " << baseData->strength << " " << baseData->endurance << " " << baseData->intelligence << " " << baseData->alacrity << " " << baseData->baseSpeed << " " 
		<< baseData->baseArmor << " " << baseData->baseAttackRange << " " << baseData->baseAttackAngleUD << " " << baseData->baseAttackAngleLR << endl;
	for(int x = 0; x < baseData->conversations.size(); x++){
		ofile << baseData->conversations.at(x) << endl;
	}

	delete baseData;

	ofile.close();
}
std::vector<Character*> Character::allCharacters;
Character* Character::GetCharacter(std::string name){
	if(name == "NULL")
		return NULL;
	for(int x = 0; x < Character::allCharacters.size(); x++){
		if(allCharacters.at(x)->getName() == name)
			return allCharacters.at(x);
	}

	// got here means they requested one that's not in memory, I guess we should load it...
	string newFilename(CHARACTERS_DIR);
	newFilename += name;
	newFilename += COMPILEDCHARACTEREXT;
	if(FileUtils::FileExists(newFilename)){
		// it exists, load it
		return Character::FromFile(newFilename);
	}else{
		string newFilename2(UNCOMPILEDCHARACTERS_DIR);
		newFilename2 += name;
		newFilename2 += UNCOMPILEDCHARACTEREXT;
		if(FileUtils::FileExists(newFilename2)){
			CompileCharacter(newFilename2);
			return Character::FromFile(newFilename);
		}
	}

	// got here means the file didn't exist, so that conversation simply doesn't exist
	return NULL;
}

void Character::activate(){
	if(numConversations > 0)
		conversations[0]->Show();
}