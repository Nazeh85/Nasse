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
    // Publik konstruktor för att skapa ett Pokemon-objekt med initiala värden
    Pokemon(const string& name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefense);

    // Virtuell destruktor för att möjliggöra korrekt resurshantering i härledda klasser
    virtual ~Pokemon() {};

    // Publika funktioner för att utföra olika handlingar på Pokemon-objektet

    // Funktioner för att utföra olika drag
    void executeMove1(Pokemon* target);
    void executeMove2(Pokemon* target);
    void executeMove3(Pokemon* target);
    void executeMove4(Pokemon* target);

    // Funktion för att reducera Pokemon-objektets hälsa baserat på skada
    void reduceHealth(int damage);

    // Virtuell funktion för att beräkna skade-multiplikatorn baserat på typ
    virtual float calculateDamageMultiplier(Type damagetype);

    // Getter-funktioner för att hämta Pokemon-objektets egenskaper
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
    // Konstruktor som initierar både bas- och härledd klass
    DualTypePokemon(const std::string& name, Type primaryType, Type secondType, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefence);

    // Virtuell destruktor för att möjliggöra korrekt resurshantering i härledda klasser
    virtual ~DualTypePokemon() {};

    // Överriden funktion för att beräkna skade-multiplikatorn baserat på typ för dual-type Pokémon
    float calculateDamageMultiplier(Type damagetype) override;
};