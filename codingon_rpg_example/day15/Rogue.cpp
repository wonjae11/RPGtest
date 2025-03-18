#include "Rogue.h"

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(0, 100);

Rogue::Rogue(string name) : Character(name, 100, 15) {}

void Rogue::attack(Character& target) {
	cout << name << "이(가) 겁나 빠르게 " << target.getName() << "을(를) 공격합니다." << endl;
	target.takeDamage(attackPower);
}

void Rogue::specialAttack(Character& target) {
	int chance = dist(gen);

	if (chance < 30) {
		cout << name << "이가 급습에 실패했습니다ㅠㅠ" << endl;
	}
	else {
		cout << name << "이(가) " << target.getName() << "급습에 성공했습니다" << endl;
		target.takeDamage(attackPower * 3);
	}
}