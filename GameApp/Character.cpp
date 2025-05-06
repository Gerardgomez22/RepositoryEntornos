#include "Character.h"

Character::Character(std::string pTipo, int pValor, int pDamage)
    : tipo(pTipo), valor(pValor), pDamage(pDamage) {
}

// Getters
std::string Character::getTipo() const {
    return tipo;
}

int Character::getValor() const {
    return valor;
}

int Character::getPDamage() const {
    return pDamage;
}

// Setters
void Character::setTipo(std::string pTipo) {
    tipo = pTipo;
}

void Character::setValor(int pValor) {
    valor = pValor;
}

void Character::setPDamage(int pDamage) {
    pDamage = pDamage;
}

void Character::takeDamage(int damage) {
    valor = (valor - damage < 0) ? 0 : valor - damage;
}

bool Character::isAlive() const {
    return valor > 0;
}

int Character::attack() const {
    return pDamage;
}