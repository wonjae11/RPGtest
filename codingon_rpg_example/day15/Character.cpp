#include "Character.h"

Character::Character(string name, int health, int atkPw) :
	name(name), health(health), maxHealth(health), attackPower(atkPw), potion(2, 30) {};

void Character::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}

void Character::usePotion() {
	potion.usePotion(health, maxHealth);
}

void Character::resetPotions() {
	potion.resetPotions();
}

bool Character::isAlive() {
	return health > 0;
}

void Character::resetHealth() {
	health = maxHealth;
	resetPotions();
}

void Character::showStatus () {
	cout << name << ": Hp - " << health << "/" << maxHealth
		<< " | 공격력: " << attackPower
		<< " | 포션: " << potion.getPotionCount() << "개" << endl;
}

//void Character::resetHealth() {
//	health = maxHealth;
//}

string Character::getName() {
	return name;
}