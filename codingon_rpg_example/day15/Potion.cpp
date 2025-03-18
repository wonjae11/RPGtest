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
		cout << "포션 사용! 체력이 " << healthValue << "만큼 회복되었습니다. (남은 포션: "  ")\n";
	}
	else {
		cout << "포션이 없습니다!\n";
	}
}

int Potion::getPotionCount() const {
	return count;
}

void Potion::resetPotions() {
	count = 2;
}