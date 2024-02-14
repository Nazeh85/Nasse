#include "Pokemon.h"
Pokemon::Pokemon(const std::string& name, const Type type, const Move* move1,
    const Move* move2, const Move* move3, const Move* move4,
    int health, int attack, int spAttack, int defense, int spDefense)
    : name(name), type(type), move1(move1), move2(move2), move3(move3),
    move4(move4), health(health), attack(attack), spAttack(spAttack),
    defense(defense), spDefense(spDefense)
{
    // Kontrollera om inmatade v�rden f�r h�lsa och egenskaper �r giltiga
    if (health <= 0 || attack <= 0 || spAttack <= 0 || defense <= 0 || spDefense <= 0) {
        throw std::runtime_error("Invalid value must be a positive");
    }
}

void Pokemon::executeMove1(Pokemon* target) {
    // Utf�r drag 1 och anv�nd "perform"-metoden fr�n det tillh�rande Move-objektet
    move1->perform(this, target);
}

void Pokemon::executeMove2(Pokemon* target) {
    // Utf�r drag 2 och anv�nd "perform"-metoden fr�n det tillh�rande Move-objektet
    move2->perform(this, target);
}

void Pokemon::executeMove3(Pokemon* target) {
    // Utf�r drag 3 och anv�nd "perform"-metoden fr�n det tillh�rande Move-objektet
    move3->perform(this, target);
}

void Pokemon::executeMove4(Pokemon* target) {
    // Utf�r drag 4 och anv�nd "perform"-metoden fr�n det tillh�rande Move-objektet
    move4->perform(this, target);
}

void Pokemon::reduceHealth(int damage) {
    // Minska h�lsan med den m�ngd skada
    health -= damage;

    // Se till att h�lsan inte g�r under noll
    if (health < 0) {
        health = 0;
    }
}

float Pokemon::calculateDamageMultiplier(Type damagetype) {
    // Anv�nd TypeChart f�r att h�mta skademultiplikatorn f�r det aktuella skadetypet mot Pokemonens egen typ
    return TypeChart::getDamageMultiplier(damagetype, type);
}

DualTypePokemon::DualTypePokemon(const std::string& name, Type primaryType, Type secondType, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefence ) : Pokemon(name, primaryType, move1, move2, move3, move4, health, attack, spAttack, defense, spDefence), secondType(secondType) {}

float DualTypePokemon::calculateDamageMultiplier(Type damagetype) {
    float multiplier1 = TypeChart::getDamageMultiplier(damagetype, type);
    float multiplier2 = TypeChart::getDamageMultiplier(damagetype, secondType);
    return multiplier1 * multiplier2;
}
