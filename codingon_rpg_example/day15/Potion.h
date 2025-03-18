#pragma once
#ifndef POTION_H
#define POTION_H

class Potion {
private:
	int count;	//남은 포션 개수
	int healAmountl;	//포션으로 회복되는 체력량

public:
	Potion(int numPotions = 2, int healPercent = 30);
	void usePotion(int& health, int maxHealth);
	int getPotionCount() const;
	void resetPotions();
};

#endif