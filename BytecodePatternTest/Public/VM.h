#pragma once

#include <cassert>
#include <cstdio>

enum Instruction
{
    INT_LITERAL = 0x00,
    SET_HEALTH = 0x01,
    GET_HEALTH = 0x02,
    SET_STRENGTH = 0x03,
    GET_STRENGTH = 0x04,
    SET_AGILITY = 0x05,
    GET_AGILITY = 0x06,
    PLAY_SOUND = 0x07,
    SPAWN_PARTICLE = 0x08,
    ADD = 0x09,
    DIVIDE = 0x10,
};

/*
 * Class VM that interprets bytecode
 */
class VM
{
public:
    VM() : stackSize_(0) {}
    
    void interpreter(char bytecode[], size_t size);
    
private:
    static const int MAX_STACK_SIZE = 128;
    int stackSize_;
    int stack_[MAX_STACK_SIZE];

    void push(int value);
    int pop();
    
    void setHealth(int entity, int health);
    int getHealth(int entity);
    void setStrength(int entity, int strength);
    int getStrength(int entity);
    void setAgility(int entity, int agility);
    int getAgility(int entity);
    void playSound(int soundId);
    void spawnParticles(int particleId);
    
};
