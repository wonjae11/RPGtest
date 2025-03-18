#pragma once
#include "Character.h"
#include <memory>
using namespace std;

class BattleManager {
public:
	static void startBattle(unique_ptr<Character>& player1, unique_ptr<Character>& player2);
};