#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#define DEFAULT_HEALTH 100
#define DEFAULT_SPEED 1.0f
#define DEFAULT_ATTACKRANGE 2.0f
#define DEFAULT_ATTACKANGLEUD 45
#define DEFAULT_ATTACKANGLELR 45

#include "DrawnObject.h"
#include "d3dx9.h"
#include "Conversation.h"
#include <fstream>
#include <iomanip>

#define COMPILEDCHARACTEREXT ".cchf"
#define UNCOMPILEDCHARACTEREXT ".rchf"
#define CHARACTERS_DIR "Data/Characters/"
#define UNCOMPILEDCHARACTERS_DIR "Data/Characters/Raw/"

struct BaseCharacterData{
	std::string meshFilename, charname;
	float passion, strength, endurance, intelligence, alacrity; // base stats
	float baseSpeed, baseArmor, baseAttackRange, baseAttackAngleUD, baseAttackAngleLR;
	std::vector<std::string> conversations;
};

class Character: public DrawnObject{
protected:
	std::string name;
	std::string id;

	float passion, strength, endurance, intelligence, alacrity; // base stats
	float baseSpeed, baseArmor, baseAttackRange, baseAttackAngleUD, baseAttackAngleLR;

	int currentHP;
	int currentMana;
	// spells
	// effects

	int numConversations;
	Conversation** conversations;
public:
	Character(void* mesh, void* material, void* texture, int numPieces): DrawnObject(mesh, material, texture, numPieces){ conversations = NULL; numConversations = 0; }

	virtual bool IsPlayer() { return false; }
	bool isCharacter() override { return true; }
	void activate() override;
	std::string activationText() override { return this->name; }

	float EffectivePassion();
	float EffectiveStrength();
	float EffectiveIntelligence();
	float EffectiveEndurance();
	float EffectiveAlacrity();

	// so as to be effected by stats
	int HpMax();
	int ManaMax();
	float Armor(); // logarithmic armor function
	float Speed(); // 1 = normal, 2 = 2x, .5 = 1/2 ... etc
	float AttackRange();
	float AttackAngleUD();
	float AttackAngleLR();

	std::string getName() { return name; }
	std::string getID() { return id; }

	// DIALOG OPTIONS*
	Conversation** GetConversations(int* num) { if(num != NULL){ *num = numConversations; } return conversations; allCharacters.push_back(this); }
	void SetConversations(Conversation** conversations, int num) { this->conversations = conversations; numConversations = num; }

	static Character* FromFile(std::string filename);
	static void CompileCharacter(std::string uncompiledfilename);
	static std::vector<Character*> allCharacters;
	static Character* GetCharacter(std::string name);
};

#endif
