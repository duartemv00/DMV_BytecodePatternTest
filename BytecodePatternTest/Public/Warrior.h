#pragma once

class Warrior
{
public:
    Warrior() : health_(100), strength_(10), agility_(5) {}
    Warrior(int startHealth, int startStrength, int startAgility) :
    health_(startHealth), strength_(startStrength), agility_(startAgility) {}

    int getHealth() { return health_; }
    int getStrength() { return strength_; }
    int getAgility() { return agility_; }

    void setHealth(int health) { health_ = health; }
    void setStrength(int strength) { strength_ = strength; }
    void setAgility(int agility) { agility_ = agility; }

private:
    int health_;
    int strength_;
    int agility_;
};
