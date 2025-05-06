#pragma once
#include "Character.h"

class Enemy : public Character {
private:
    int enemigo;

public:
    Enemy(std::string pTipo = "", int pValor = 50, int pDamage = 10, int pEnemigo = 50);

    // Getter
    int getEnemigo() const;

    // Setter
    void setEnemigo(int valor);
};