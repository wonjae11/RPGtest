#pragma once
#include <iostream>
#include <memory>
#include "Potion.h"
using namespace std;

class Character {
protected:
	string name;
	int health;
	int maxHealth;
	int attackPower;
	Potion potion;

public:
	Character(string name, int health, int atkPw);

	virtual void attack(Character& target) = 0;
	virtual void specialAttack(Character& target) = 0;

	void takeDamage(int damage);
	bool isAlive();
	void resetHealth();
	void resetPotions();
	void usePotion();
	void showStatus();
	string getName();
};