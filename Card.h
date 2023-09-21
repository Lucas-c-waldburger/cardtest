//
// Created by Lower School Music on 9/21/23.
//

#ifndef CARDTEST_CARD_H
#define CARDTEST_CARD_H


enum class EnergyType { WATER, FIRE, GRASS, ELECTRIC, PSYCHIC, FIGHTING, COLORLESS, ONCE_PER_TURN, NONE, ANY };
enum class CardType { ENERGY, PKMN, TRAINER };

class Card
{
public:
    Card(EnergyType et, CardType ct) : eType(et), cType(ct) {};

    EnergyType getEType() { return eType; }
    CardType getCType() { return cType; }

private:
    EnergyType eType;
    CardType cType;
};

class PkmnCard : public Card
{
    PkmnCard(EnergyType et) : Card(et, CardType::PKMN) {};
};

class EnergyCard : public Card
{
    EnergyCard(EnergyType et) : Card(et, CardType::ENERGY) {};
};


#endif //CARDTEST_CARD_H
