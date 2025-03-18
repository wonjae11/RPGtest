#pragma once
#ifndef POTION_H
#define POTION_H

class Potion {
private:
	int count;	//���� ���� ����
	int healAmountl;	//�������� ȸ���Ǵ� ü�·�

public:
	Potion(int numPotions = 2, int healPercent = 30);
	void usePotion(int& health, int maxHealth);
	int getPotionCount() const;
	void resetPotions();
};

#endif