#include "Pokemon.h"
Pokemon::Pokemon(const std::string& name, const Type type, const Move* move1,
    const Move* move2, const Move* move3, const Move* move4,
    int health, int attack, int spAttack, int defense, int spDefense)
    : name(name), type(type), move1(move1), move2(move2), move3(move3),
    move4(move4), health(health), attack(attack), spAttack(spAttack),
    defense(defense), spDefense(spDefense)
{
    // Kontrollera om inmatade värden för hälsa och egenskaper är giltiga
    if (health <= 0 || attack <= 0 || spAttack <= 0 || defense <= 0 || spDefense <= 0) {
        throw std::runtime_error("Invalid value must be a positive");
    }
}

void Pokemon::executeMove1(Pokemon* target) {
    // Utför drag 1 och använd "perform"-metoden från det tillhörande Move-objektet
    move1->perform(this, target);
}

void Pokemon::executeMove2(Pokemon* target) {
    // Utför drag 2 och använd "perform"-metoden från det tillhörande Move-objektet
    move2->perform(this, target);
}

void Pokemon::executeMove3(Pokemon* target) {
    // Utför drag 3 och använd "perform"-metoden från det tillhörande Move-objektet
    move3->perform(this, target);
}

void Pokemon::executeMove4(Pokemon* target) {
    // Utför drag 4 och använd "perform"-metoden från det tillhörande Move-objektet
    move4->perform(this, target);
}

void Pokemon::reduceHealth(int damage) {
    // Minska hälsan med den mängd skada
    health -= damage;

    // Se till att hälsan inte går under noll
    if (health < 0) {
        health = 0;
    }
}

float Pokemon::calculateDamageMultiplier(Type damagetype) {
    // Använd TypeChart för att hämta skademultiplikatorn för det aktuella skadetypet mot Pokemonens egen typ
    return TypeChart::getDamageMultiplier(damagetype, type);
}

DualTypePokemon::DualTypePokemon(const std::string& name, Type primaryType, Type secondType, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, int attack, int spAttack, int defense, int spDefence ) : Pokemon(name, primaryType, move1, move2, move3, move4, health, attack, spAttack, defense, spDefence), secondType(secondType) {}

float DualTypePokemon::calculateDamageMultiplier(Type damagetype) {
    float multiplier1 = TypeChart::getDamageMultiplier(damagetype, type);
    float multiplier2 = TypeChart::getDamageMultiplier(damagetype, secondType);
    return multiplier1 * multiplier2;
}
