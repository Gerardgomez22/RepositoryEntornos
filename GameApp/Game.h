#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include <vector>

class Game {
private:
    Player player;
    std::vector<Enemy> enemies;
    Boss finalBoss;
    bool isGameOver;

public:
    Game();

    // Getters
    Player& getPlayer();
    std::vector<Enemy>& getEnemies();
    Boss& getFinalBoss();
    bool getGameOver() const;

    // Setters
    void setPlayer(const Player& newPlayer);
    void setEnemies(const std::vector<Enemy>& newEnemies);
    void setFinalBoss(const Boss& newBoss);
    void setGameOver(bool status);

    void run();
};