#pragma once
#include <string>
#include "Type.h"
#include <iostream>

class Pokemon;

class Move {
protected:
    // Privata medlemmar f�r att representera detaljer om draget
    const std::string name;
    const Type type;
    const int power;

    // Ren virtuell funktion som m�ste implementeras av h�rledda klasser
    virtual void execute(Pokemon*, Pokemon*) const = 0;

public:
    // Konstruktor f�r att initiera attributen i Move-objektet
    Move(const std::string& name, const Type type, const int power);

    // Virtuell destruktor f�r att m�jligg�ra korrekt resurshantering i h�rledda klasser
    virtual ~Move() {};

    // Publik funktion f�r att utf�ra draget
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

class PhysicalMove : public Move {
public:
    // Konstruktor som initierar attributen f�r PhysicalMove-objekt
     PhysicalMove(const std::string& name, const Type type, const int power);

    // �verriden funktion f�r att implementera utf�randet av fysiska drag
     virtual void execute(Pokemon*, Pokemon*) const override;
};

class SpecialMove : public Move {
public:
    // Konstruktor som initierar attributen f�r SpecialMove-objekt
    SpecialMove(const std::string& name, const Type type, const int power);

    // �verriden funktion f�r att implementera utf�randet av specialdrag
    virtual void execute(Pokemon*, Pokemon*) const override;
};
