#pragma once
#include <string>

class Character {
protected:
    std::string tipo;
    int valor;
    int pDamage;

public:
    Character(std::string pTipo = "", int pValor = 100, int pDamage = 10);

    // Getters
    std::string getTipo() const;
    int getValor() const;
    int getPDamage() const;

    // Setters
    void setTipo(std::string pTipo);
    void setValor(int pValor);
    void setPDamage(int pDamage);

    void takeDamage(int damage);
    bool isAlive() const;
    virtual int attack() const;
};