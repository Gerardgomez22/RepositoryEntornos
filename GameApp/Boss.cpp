#include "Boss.h"
#include <cstdlib>
#include <iostream>

Boss::Boss(std::string pTipo, int pValor, int pDamage, int pEnemigo, int pSpecialAttack)
    : Enemy(pTipo, pValor, pDamage, pEnemigo),
    specialAttack(pSpecialAttack),
    specialAttackCooldown(3),
    currentCooldown(0) {
}

// Getters
int Boss::getSpecialAttack() const {
    return specialAttack;
}

int Boss::getSpecialAttackCooldown() const {
    return specialAttackCooldown;
}

int Boss::getCurrentCooldown() const {
    return currentCooldown;
}

// Setters
void Boss::setSpecialAttack(int attack) {
    specialAttack = attack;
}

void Boss::setSpecialAttackCooldown(int cooldown) {
    specialAttackCooldown = cooldown;
}

void Boss::setCurrentCooldown(int current) {
    currentCooldown = current;
}

// Special attack methods
int Boss::bossFinal() const {
    return specialAttack;
}

void Boss::decreaseCooldown() {
    if (currentCooldown > 0) {
        currentCooldown--;
    }
}

bool Boss::canSpecialAttack() const {
    return currentCooldown == 0;
}

int Boss::attack() const {
    // 30% chance of special attack when cooldown is 0
    if (canSpecialAttack() && (std::rand() % 100) < 30) {
        std::cout << getTipo() << " uses a special attack!" << std::endl;
        return bossFinal();
    }
    return getPDamage();
}