#include "Mage.h"

Mage::Mage(string name) : Character(name, 80, 18) {}

void Mage::attack(Character& target) {
	cout << name << "��(��) " << target.getName() << "��(��) �������� �����մϴ�." << endl;
	target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
	if (mana < 20) throw runtime_error("������ �����մϴ�!");
	cout << name << "��(��) " << target.getName() << "���� ���̾�� �߻��մϴ�!!!" << endl;
	target.takeDamage(attackPower * 1.5);
}