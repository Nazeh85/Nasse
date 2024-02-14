#pragma once
#include <string>
#include "Type.h"
#include <iostream>

class Pokemon;

class Move {
protected:
    // Privata medlemmar för att representera detaljer om draget
    const std::string name;
    const Type type;
    const int power;

    // Ren virtuell funktion som måste implementeras av härledda klasser
    virtual void execute(Pokemon*, Pokemon*) const = 0;

public:
    // Konstruktor för att initiera attributen i Move-objektet
    Move(const std::string& name, const Type type, const int power);

    // Virtuell destruktor för att möjliggöra korrekt resurshantering i härledda klasser
    virtual ~Move() {};

    // Publik funktion för att utföra draget
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

class PhysicalMove : public Move {
public:
    // Konstruktor som initierar attributen för PhysicalMove-objekt
     PhysicalMove(const std::string& name, const Type type, const int power);

    // Överriden funktion för att implementera utförandet av fysiska drag
     virtual void execute(Pokemon*, Pokemon*) const override;
};

class SpecialMove : public Move {
public:
    // Konstruktor som initierar attributen för SpecialMove-objekt
    SpecialMove(const std::string& name, const Type type, const int power);

    // Överriden funktion för att implementera utförandet av specialdrag
    virtual void execute(Pokemon*, Pokemon*) const override;
};
