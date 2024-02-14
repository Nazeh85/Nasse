#include "Pokemon.h"
#include "Move.h"

Move::Move(const std::string& name, const Type type, const int power)
    : type(type), name(name), power(power)
{
    if (power < 0) {
        throw std::invalid_argument("Not a valid power for this move");
    }
}
void Move::perform(Pokemon* attacker, Pokemon* defender) const {
    // Kontrollera om attackern är besegrad och inte kan utföra rörelsen
    if (attacker->getHealth() == 0) {
        std::cout << attacker->getName() << " is in a fainted state and can’t move." << std::endl;
        return;
    }
    // Kontrollera om försvararen är besegrad och rörelsen inte kan utföras
    else if (defender->getHealth() <= 0) {
        std::cout << attacker->getName() << " cannot perform a move, " << defender->getName() << " has already fainted." << std::endl;
        return;
    }
    else {
        execute(attacker, defender);
    }

    // Kontrollera om försvararen har besegrats efter rörelsens utförande
    if (defender->getHealth() <= 0) {
        std::cout << defender->getName() << " has fainted." << std::endl;
    }
}


PhysicalMove::PhysicalMove(const std::string& name, const Type type, const int power)
    : Move(name, type, power) {}

void PhysicalMove::execute(Pokemon* attacker, Pokemon* defender) const {

    float basedDamage = (float)power * (attacker->getAttack() / (float)defender->getDefence() / 5.f);
    float multiplier = defender->calculateDamageMultiplier(type);
    float totalDamage = basedDamage * multiplier;
    cout << attacker->getName() << " used " << name << endl;
    defender->reduceHealth(totalDamage);

    if (multiplier == 0) {
        cout << "It does not affect " << defender->getName() << endl;
    }
    else if (multiplier < 1 && multiplier != 0) {

        cout << "It is not very effective..." << endl;
    }
    else if (multiplier > 1) {
        cout << "It is super effective!" << endl;

    }
    //cout << defender->getName() << " now has " << defender->getHealth() << " health remaining." << std::endl;
}

SpecialMove::SpecialMove(const std::string& name, const Type type, const int power)
    :Move(name, type, power) {}

void SpecialMove::execute(Pokemon* specialAttack, Pokemon* specialDefender)const {
    float baseDamage = (float)power * (specialAttack->getSpAttack() / (float)specialDefender->getSpDefence() / 5.f);
    float multiplier = specialDefender->calculateDamageMultiplier(type);
   
    float totalDamage = baseDamage * multiplier;
    cout << specialAttack->getName() << " used " << name << endl;
    specialDefender->reduceHealth(totalDamage);
    if (multiplier == 0) {

        cout << "It does not affect " << specialDefender->getName() << endl;
    }
    else if (multiplier < 1 && multiplier != 0) {

        cout << "It is not very effective..." << endl;
    }
    else if (multiplier > 1) {

        cout << "It is super effective!" << endl;
    }
    //cout << defender->getName() << " now has " << defender->getHealth() << " health remaining." << std::endl;
}
