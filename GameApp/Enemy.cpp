
#include "Enemy.h"

Enemy::Enemy(std::string pTipo, int pValor, int pDamage, int pEnemigo)
    : Character(pTipo, pValor, pDamage), enemigo(pEnemigo) {
}

int Enemy::getEnemigo() const {
    return enemigo;
}

void Enemy::setEnemigo(int valor) {
    enemigo = valor;
}