#include "BattleManager.h"
#include <random>
#include <chrono>
#include <thread>

void BattleManager::startBattle(unique_ptr<Character>& player1, unique_ptr<Character>& player2) {
    cout << "전투 시작! " << player1->getName() << " vs " << player2->getName() << endl;

    // 난수 생성을 통해 전투의 선공(첫 번째 공격자)을 랜덤으로 결정
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> firstTurn(0, 1);
    uniform_int_distribution<> attackType(0, 100);

    bool firstAttack = firstTurn(gen);

    // 한 캐릭터의 체력이 0이 되면 전투 종료
    while (player1->isAlive() && player2->isAlive()) {
        player1->showStatus();
        player2->showStatus();

        cout << "---------------------------------" << endl;

        // 예외 처리(try - catch)
        try {
            if (firstAttack) {
                // 플레이어(첫 번째 캐릭터) 차례
                cout << player1->getName() << "의 차례! 행동을 선택하세요.\n";
                cout << "1. 공격  2. 특수 공격  3. 포션 사용\n선택: ";
                int action;
                cin >> action;

                if (action == 1) {
                    player1->attack(*player2);
                }
                else if (action == 2) {
                    player1->specialAttack(*player2);
                }
                else if (action == 3) {
                    player1->usePotion(); // 포션 사용 추가
                }
                else {
                    cout << "잘못된 선택입니다. 다시 입력하세요.\n";
                    continue;
                }

                this_thread::sleep_for(chrono::milliseconds(1000));

                // 두 번째 캐릭터가 살아있으면 반격
                if (!player2->isAlive()) break;

                // AI (적) 공격 (포션 사용 안 함)
                if (attackType(gen) < 70) player2->attack(*player1);
                else player2->specialAttack(*player1);

                this_thread::sleep_for(chrono::milliseconds(1000));
            }
            else {
                // AI (적) 먼저 공격
                if (attackType(gen) < 70) player2->attack(*player1);
                else player2->specialAttack(*player1);

                this_thread::sleep_for(chrono::milliseconds(1000));

                if (!player1->isAlive()) break;

                // 플레이어 차례
                cout << player1->getName() << "의 차례! 행동을 선택하세요.\n";
                cout << "1. 공격  2. 특수 공격  3. 포션 사용\n선택: ";
                int action;
                cin >> action;

                if (action == 1) {
                    player1->attack(*player2);
                }
                else if (action == 2) {
                    player1->specialAttack(*player2);
                }
                else if (action == 3) {
                    player1->usePotion(); // 포션 사용 추가
                }
                else {
                    cout << "잘못된 선택입니다. 다시 입력하세요.\n";
                    continue;
                }

                this_thread::sleep_for(chrono::milliseconds(1000));
            }
        }
        catch (const exception& e) {
            // 마나 부족 시 공격 불가 예외 처리
            cout << e.what() << endl;
        }
    }

    cout << "\n 전투 종료! ";
    if (player1->isAlive()) cout << player1->getName() << " 승리!\n";
    else cout << player2->getName() << " 승리! 게임 오버...\n";
}
