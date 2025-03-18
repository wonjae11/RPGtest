#pragma once
#include "Character.h"

class Mage : public Character {
private:
	int mana;

public:
	Mage(string name);
	void attack(Character& targer) override;
	void specialAttack(Character& targer) override;
};