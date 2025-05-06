#include "Game.h"
#include <iostream>
#include <string>

Game::Game() : isGameOver(false), finalBoss("Dragon", 200, 30, 500, 50) {}

// Getters
Player& Game::getPlayer() {
    return player;
}

std::vector<Enemy>& Game::getEnemies() {
    return enemies;
}

Boss& Game::getFinalBoss() {
    return finalBoss;
}

bool Game::getGameOver() const {
    return isGameOver;
}

// Setters
void Game::setPlayer(const Player& newPlayer) {
    player = newPlayer;
}

void Game::setEnemies(const std::vector<Enemy>& newEnemies) {
    enemies = newEnemies;
}

void Game::setFinalBoss(const Boss& newBoss) {
    finalBoss = newBoss;
}

void Game::setGameOver(bool status) {
    isGameOver = status;
}

void Game::run() {
    // Get player name
    std::string playerName;
    std::cout << "Enter your hero's name: ";
    std::getline(std::cin, playerName);

    player = Player(playerName);

    // Create enemies
    enemies = {
        Enemy("Goblin", 50, 10, 50),
        Enemy("Orc", 75, 15, 75),
        Enemy("Troll", 90, 18, 100)
    };

    // Battle sequence
    for (auto& enemy : enemies) {
        std::cout << "\nBattle against " << enemy.getTipo() << std::endl;

        while (enemy.isAlive() && player.isAlive()) {
            // Player attack
            int playerDamage = player.attack();
            enemy.takeDamage(playerDamage);
            std::cout << player.getTipo() << " attacks for " << playerDamage << " damage!" << std::endl;

            if (!enemy.isAlive()) {
                std::cout << "You defeated " << enemy.getTipo() << "!" << std::endl;
                player.gainExperience(enemy.getEnemigo());
                break;
            }

            // Enemy attack
            int enemyDamage = enemy.attack();
            player.takeDamage(enemyDamage);
            std::cout << enemy.getTipo() << " attacks for " << enemyDamage << " damage!" << std::endl;
        }

        if (!player.isAlive()) break;
    }

    // Final Boss Battle
    if (player.isAlive()) {
        std::cout << "\n=== FINAL BOSS BATTLE ===" << std::endl;
        while (finalBoss.isAlive() && player.isAlive()) {
            // Player attack
            int playerDamage = player.attack();
            finalBoss.takeDamage(playerDamage);
            std::cout << player.getTipo() << " attacks for " << playerDamage << " damage!" << std::endl;

            if (!finalBoss.isAlive()) {
                std::cout << "You defeated the Dragon!" << std::endl;
                player.gainExperience(finalBoss.getEnemigo());
                break;
            }

            // Boss attack
            int bossDamage = finalBoss.attack();
            player.takeDamage(bossDamage);
            std::cout << finalBoss.getTipo() << " attacks for " << bossDamage << " damage!" << std::endl;
        }
    }

    // Game result
    if (player.isAlive()) {
        std::cout << "\nCongratulations! You completed the adventure!" << std::endl;
        isGameOver = true;
    }
    else {
        std::cout << "\nGame Over! You were defeated." << std::endl;
        isGameOver = true;
    }
}