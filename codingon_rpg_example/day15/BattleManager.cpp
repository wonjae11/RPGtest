#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& player1, unique_ptr<Character>& player2) {
    cout << "���� ����! " << player1->getName() << " vs " << player2->getName() << endl;

    // ���� ������ ���� ������ ����(ù ��° ������)�� �������� ����
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> firstTurn(0, 1);
    uniform_int_distribution<> attackType(0, 100);

    bool firstAttack = firstTurn(gen);

    // �� ĳ������ ü���� 0�� �Ǹ� ���� ����
    while (player1->isAlive() && player2->isAlive()) {
        player1->showStatus();
        player2->showStatus();

        cout << "---------------------------------" << endl;

        // ���� ó��(try - catch)
        try {
            if (firstAttack) {
                // �÷��̾�(ù ��° ĳ����) ����
                cout << player1->getName() << "�� ����! �ൿ�� �����ϼ���.\n";
                cout << "1. ����  2. Ư�� ����  3. ���� ���\n����: ";
                int action;
                cin >> action;

                if (action == 1) {
                    player1->attack(*player2);
                }
                else if (action == 2) {
                    player1->specialAttack(*player2);
                }
                else if (action == 3) {
                    player1->usePotion(); // ���� ��� �߰�
                }
                else {
                    cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n";
                    continue;
                }

                this_thread::sleep_for(chrono::milliseconds(1000));

                // �� ��° ĳ���Ͱ� ��������� �ݰ�
                if (!player2->isAlive()) break;

                // AI (��) ���� (���� ��� �� ��)
                if (attackType(gen) < 70) player2->attack(*player1);
                else player2->specialAttack(*player1);

                this_thread::sleep_for(chrono::milliseconds(1000));
            }
            else {
                // AI (��) ���� ����
                if (attackType(gen) < 70) player2->attack(*player1);
                else player2->specialAttack(*player1);

                this_thread::sleep_for(chrono::milliseconds(1000));

                if (!player1->isAlive()) break;

                // �÷��̾� ����
                cout << player1->getName() << "�� ����! �ൿ�� �����ϼ���.\n";
                cout << "1. ����  2. Ư�� ����  3. ���� ���\n����: ";
                int action;
                cin >> action;

                if (action == 1) {
                    player1->attack(*player2);
                }
                else if (action == 2) {
                    player1->specialAttack(*player2);
                }
                else if (action == 3) {
                    player1->usePotion(); // ���� ��� �߰�
                }
                else {
                    cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n";
                    continue;
                }

                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        }
        catch (const exception& e) {
            // ���� ���� �� ���� �Ұ� ���� ó��
            cout << e.what() << endl;
        }
    }

    cout << "\n ���� ����! ";
    if (player1->isAlive()) cout << player1->getName() << " �¸�!\n";
    else cout << player2->getName() << " �¸�! ���� ����...\n";
}
