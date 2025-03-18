#pragma once
#include "Character.h"

class Warrior : public Character {
public:
	Warrior(string name);
	void attack(Character& targer) override;
	void specialAttack(Character& targer) override;
};