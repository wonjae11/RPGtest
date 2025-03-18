#include "Rogue.h"

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0, 100);

Rogue::Rogue(string name) : Character(name, 100, 15) {}

void Rogue::attack(Character& target) {
	cout << name << "��(��) �̳� ������ " << target.getName() << "��(��) �����մϴ�." << endl;
	target.takeDamage(attackPower);
}

void Rogue::specialAttack(Character& target) {
	int chance = dist(gen);

	if (chance < 30) {
		cout << name << "�̰� �޽��� �����߽��ϴ٤Ф�" << endl;
	}
	else {
		cout << name << "��(��) " << target.getName() << "�޽��� �����߽��ϴ�" << endl;
		target.takeDamage(attackPower * 3);
	}
}