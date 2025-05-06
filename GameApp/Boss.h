#pragma once
#include "Enemy.h"

class Boss : public Enemy {
private:
    int specialAttack;
    int specialAttackCooldown;  // Cambié el nombre para que sea más claro
    int currentCooldown;

public:
    Boss(std::string pTipo = "Dragon", int pValor = 200, int pDamage = 30,
        int pEnemigo = 500, int pSpecialAttack = 50);

    // Getters
    int getSpecialAttack() const;
    int getSpecialAttackCooldown() const;  // Método corregido
    int getCurrentCooldown() const;

    // Setters
    void setSpecialAttack(int attack);
    void setSpecialAttackCooldown(int cooldown);  // Método corregido
    void setCurrentCooldown(int current);

    // Special attack method
    int bossFinal() const;
    void decreaseCooldown();
    bool canSpecialAttack() const;

    // Override attack method to potentially use special attack
    int attack() const override;
};