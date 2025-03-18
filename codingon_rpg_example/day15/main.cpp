#include <iostream>
#include <memory>
#include "BattleManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
using namespace std;

//����� ���� �Լ� ���� : chooseCharacter(const string& prompt)
unique_ptr<Character> chooseCharacter(const string& prompt) {
	int choice;
	cout << prompt << endl;
	cout << "1. ����" << endl;
	cout << "2. ������" << endl;
	cout << "3. ����" << endl;
	cout << "����: ";
	cin >> choice;

	switch (choice) {
	case 1: return make_unique<Warrior>("����");
	case 2: return make_unique<Mage>("������");
	case 3: return make_unique<Rogue>("����");
	default:
		cout << "������ �߸��ϼ̾��. ���縦 �����ؿ�" << endl;
		return make_unique<Warrior>("����");
	}
}

int main() {
	cout << "�ڵ��� RPG �����ϱ�" << endl;
	//����ڰ� �ڽ��� ĳ���� ����
	unique_ptr<Character> player = chooseCharacter("ũ����� ĳ���͸� �������ּ���: ");
	
	while(true) {
		//����ڰ� ��� ĳ���� ����
		unique_ptr<Character> enemy = chooseCharacter("��� ĳ���͸� �������ּ��� : ");
		
		//BattleManger::startBattle�� ���� ����
		BattleManager::startBattle(player, enemy);

		//�й� �� ���� ����
		if (!player->isAlive()) {
			cout << "������ �����մϴ�" << endl;
			break;
		}
		//�÷��̾ �¸��ϸ� ���ο� ���� �����Ͽ� ���� ���� ����(y / n �Է����� ���� ����)
		char choice;
		cout << "�¸��Ͽ����ϴ�! ������ ����ұ��? (y/n): ";
		cin >> choice;

		if (choice == 'n') {
			cout << "������ �����մϴ�" << endl;
			break;
		}

		player->resetHealth();
	}

}