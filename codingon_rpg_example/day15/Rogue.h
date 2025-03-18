#pragma once
#include "Character.h"
#include <random>

class Rogue : public Character {
public:
	Rogue(string name);
	void attack(Character& targer) override;
	void specialAttack(Character& targer) override;
};