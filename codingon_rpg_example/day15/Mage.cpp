#include "Mage.h"

Mage::Mage(string name) : Character(name, 80, 18) {}

void Mage::attack(Character& target) {
	cout << name << "이(가) " << target.getName() << "을(를) 마법으로 공격합니다." << endl;
	target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
	if (mana < 20) throw runtime_error("마나가 부족합니다!");
	cout << name << "이(가) " << target.getName() << "에게 파이어볼을 발사합니다!!!" << endl;
	target.takeDamage(attackPower * 1.5);
}