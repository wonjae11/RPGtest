#include "Warrior.h"

Warrior::Warrior(string name) : Character(name, 100, 15) {}

void Warrior::attack(Character& target) {
	cout << name << "이(가) " << target.getName() << "을(를) 공격합니다." << endl;
	target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
	cout << name << "이(가) " << target.getName() << "을(를) 쎄게 공격합니다." << endl;
	target.takeDamage(attackPower * 2);
	takeDamage(5);
}