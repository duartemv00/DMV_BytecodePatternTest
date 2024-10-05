
#include "../Public/VM.h"
#include "../Public/Globals.h"

void VM::interpreter(char bytecode[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        char instruction = bytecode[i];

        switch(instruction)
        {
        // SET AND GET STATS INSTRUCTIONS
        case INT_LITERAL:
            int value;
            value = bytecode[++i];
            push(value);
            break;
            
        case SET_HEALTH:
            int amountHealth;
            amountHealth = pop();
            int entityToSetHealth;
            entityToSetHealth = pop();
            setHealth(entityToSetHealth, amountHealth);
            break;

        case GET_HEALTH:
            int entityToGetHealth;
            entityToGetHealth = pop();
            push(getHealth(entityToGetHealth));
            break;
            
        case SET_STRENGTH:
            int amountStrength;
            amountStrength = pop();
            int entityToSetStrength;
            entityToSetStrength = pop();
            setStrength(entityToSetStrength, amountStrength);
            break;

        case GET_STRENGTH:
            int entityToGetStrength;
            entityToGetStrength = pop();
            push(getStrength(entityToGetStrength));
            break;
            
        case SET_AGILITY:
            int amountAgility;
            amountAgility = pop();
            int entityToSetAgility;
            entityToSetAgility = pop();
            setAgility(entityToSetAgility, amountAgility);
            break;

        case GET_AGILITY:
            int entityToGetAgility;
            entityToGetAgility = pop();
            push(getAgility(entityToGetAgility));
            break;
            
        case PLAY_SOUND:
            playSound(pop());
            break;
            
        case SPAWN_PARTICLE:
            spawnParticles(pop());
            break;
            
        // ARITHMETIC OPERATIONS INSTRUCTIONS
        case ADD:
        {
            int a = pop();
            int b = pop();
            push(a + b); printf("a + b = %d\n", a + b);
            break;
        }
            
        case DIVIDE:
        {
            int a = pop();
            int b = pop();
            push(a / b);
            break;
        }
            
        default: break;
            
        }
    }
}

void VM::push(int value)
{
    // Check for stack overflow
    assert(stackSize_ < MAX_STACK_SIZE); // If this fails, the program will crash
    stack_[stackSize_++] = value; // Push value onto stack
}

int VM::pop()
{
    // Make sure stack is not empty
    assert(stackSize_ > 0); // If this fails, the program will crash
    return stack_[--stackSize_]; // Pop value from stack
}

void VM::setHealth(int entity, int health)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    warriors[entity]->setHealth(health);
}

int VM::getHealth(int entity)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    return warriors[entity]->getHealth();
}

int VM::getStrength(int entity)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    return warriors[entity]->getStrength();
}

int VM::getAgility(int entity)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    return warriors[entity]->getAgility();
}

void VM::setStrength(int entity, int strength)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    warriors[entity]->setStrength(strength);
}

void VM::setAgility(int entity, int agility)
{
    assert(entity <= getNumberOfWarriors() && entity >= 0);
    warriors[entity]->setAgility(agility);
}

void VM::playSound(int soundId)
{
    // Add code here
}

void VM::spawnParticles(int particleId)
{
    // Add code here
}
