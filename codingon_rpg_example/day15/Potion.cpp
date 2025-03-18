#include "Potion.h"
#include <iostream>
using namespace std;

Potion::Potion(int numPotions, int healPercent) : count(numPotions), healAmountl(healPercent) {
}

void Potion::usePotion(int& health, int maxHealth) {
	if (count > 0) {
		int healthValue = (maxHealth * healAmountl) / 100;
		health += healthValue;
		if (health > maxHealth) health = maxHealth;
		count--;
		cout << "���� ���! ü���� " << healthValue << "��ŭ ȸ���Ǿ����ϴ�. (���� ����: "  ")\n";
	}
	else {
		cout << "������ �����ϴ�!\n";
	}
}

int Potion::getPotionCount() const {
	return count;
}

void Potion::resetPotions() {
	count = 2;
}