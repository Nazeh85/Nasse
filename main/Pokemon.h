#pragma once
#include <string>
#include "Type.h"
#include "Move.h"
#include <stdexcept>
using namespace std;

class Pokemon {
private:
   
    const Move* move1;
    const Move* move2;
    const Move* move3;
    const Move* move4;

    const std::string name;
    int health;
    int attack;
    int spAttack;
    int defense;
    int spDefense;
protected:
    const Type type;
public:
    // Publik konstruktor f�r att skapa ett Pokemon-objekt med initiala v�rden
    Pokemon(const string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefense);

    // Virtuell destruktor f�r att m�jligg�ra korrekt resurshantering i h�rledda klasser
    virtual ~Pokemon() {};

    // Publika funktioner f�r att utf�ra olika handlingar p� Pokemon-objektet

    // Funktioner f�r att utf�ra olika drag
    void executeMove1(Pokemon* target);
    void executeMove2(Pokemon* target);
    void executeMove3(Pokemon* target);
    void executeMove4(Pokemon* target);

    // Funktion f�r att reducera Pokemon-objektets h�lsa baserat p� skada
    void reduceHealth(int damage);

    // Virtuell funktion f�r att ber�kna skade-multiplikatorn baserat p� typ
    virtual float calculateDamageMultiplier(Type damagetype);

    // Getter-funktioner f�r att h�mta Pokemon-objektets egenskaper
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    int getSpAttack() const { return spAttack; }
    int getDefence() const { return defense; }
    int getSpDefence() const { return spDefense; }
    string getName() const { return name; }
    
};

class DualTypePokemon : public Pokemon {
private:
    const Type secondType;
public:
    // Konstruktor som initierar b�de bas- och h�rledd klass
    DualTypePokemon(const std::string& name, Type primaryType, Type secondType, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefence);

    // Virtuell destruktor f�r att m�jligg�ra korrekt resurshantering i h�rledda klasser
    virtual ~DualTypePokemon() {};

    // �verriden funktion f�r att ber�kna skade-multiplikatorn baserat p� typ f�r dual-type Pok�mon
    float calculateDamageMultiplier(Type damagetype) override;
};