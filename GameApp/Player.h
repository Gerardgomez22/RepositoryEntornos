#pragma once
#include "Character.h"

class Player : public Character {
private:
    int experience;
    int level;

public:
    Player(std::string pName = "", int pHp = 100, int pDamage = 20);

    
    int getExperience() const;
    int getLevel() const;

    
    void setExperience(int exp);
    void setLevel(int newLevel);

    void gainExperience(int exp);
};