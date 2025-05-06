#include "Player.h"
#include <iostream>

Player::Player(std::string pName, int pHp, int pDamage)
    : Character(pName, pHp, pDamage), experience(0), level(1) {
}

// Getters
int Player::getExperience() const {
    return experience;
}

int Player::getLevel() const {
    return level;
}

// Setters
void Player::setExperience(int exp) {
    experience = exp;
}

void Player::setLevel(int newLevel) {
    level = newLevel;
}

void Player::gainExperience(int exp) {
    experience += exp;

    // Simple level up mechanism
    if (experience >= 100) {
        level++;
        experience = 0;
        std::cout << getName() << " leveled up to level " << level << "!" << std::endl;
    }
}