#ifndef __CONVERSATION_H__
#define __CONVERSATION_H__

#define COMPILEDCONVERSATIONEXT ".ccf"
#define UNCOMPILEDCONVERSATIONEXT ".rcf"
#define CONVERSATIONS_DIR "Data/Conversations/"
#define UNCOMPILEDCONVERSATIONS_DIR "Data/Conversations/Raw/"

#include <string>
#include <vector>
#include "Window.h"
#include "DirectX.h"

class Conversation;

class ConversationChoice{
protected:
	std::string choiceText;
	Conversation* result;
public:
	static ConversationChoice* FromFile(std::string filename);
	void setChoiceText(std::string choiceText) { this->choiceText = choiceText; }
	void setResult(Conversation* result) { this->result = result; }
	std::string getChoiceText() { return choiceText; }
	Conversation* getResult() { return result; }
};

class Conversation{
protected:
	int numChoices;
	ConversationChoice** choices;
	Window* window;
	std::string name;
	std::string text;
	// Effect* dialogEffect; // the effect the dialog has on the player
	// Effect* dialogNPCEffect; // the effect the dialog has on the speaker
	// Character* speaker; // the person the player is having the conversation with
	// Character* player; // the ... player...
public:
	// for the static creation from file
	Conversation() { Conversation::allConversations.push_back(this); Start(); }

	/* manually create (shouldn't be used often if at all) */
	Conversation(ConversationChoice** choices, int numChoices, std::string text, std::string name);

	virtual void Start();
	virtual void Show();
	virtual void Hide();
	virtual void End(ConversationChoice* choice);

	// accessors and mutators
	std::string getName() { return name; }
	Window* getWindow() { return window; }
	ConversationChoice** getChoices() { return choices; }
	int getNumChoices() { return numChoices; }

	// static management stuff
	static void CompileConversation(std::string uncompiledfilename);
	static Conversation* FromFile(std::string compiledfilename);
	static std::vector<Conversation*> allConversations;
	static Conversation* GetConversation(std::string name);
	static void MakeConversationChoice(UIBase* caller);
};

#endif
