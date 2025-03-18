#include "Warrior.h"

Warrior::Warrior(string name) : Character(name, 100, 15) {}

void Warrior::attack(Character& target) {
	cout << name << "��(��) " << target.getName() << "��(��) �����մϴ�." << endl;
	target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
	cout << name << "��(��) " << target.getName() << "��(��) ��� �����մϴ�." << endl;
	target.takeDamage(attackPower * 2);
	takeDamage(5);
}