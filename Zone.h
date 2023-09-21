#ifndef CARDTEST_ZONE_H
#define CARDTEST_ZONE_H

#include "Card.h"
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>

class MoveGroup;
class Zone
{
public:
    Zone() = default;
    virtual ~Zone() = 0;

protected:
    friend MoveGroup& operator>>(Zone& lhs, MoveGroup&& rhs);
    friend Zone& operator>>(MoveGroup& lhs, Zone& rhs);

    std::vector<std::unique_ptr<Card>> cards;
};

class Hand : public Zone
{

};

class Deck : public Zone
{

};

class MoveGroup : public Zone
{
public:
    struct Group
    {
        Group(int nCards, EnergyType et);
        Group(int nCards, CardType ct);
        Group(int nCards, CardType ct, EnergyType et);

        int numCards;
        CardType cType;
        EnergyType eType;

        bool operator==(const std::unique_ptr<Card>& c);
    };

    // MoveGroup(int nCards, EnergyType et); /**/
    MoveGroup(std::initializer_list<Group> grps);

private:
    std::list<Group> groups;

    bool matchFound(std::unique_ptr<Card>& c);
    static bool validMatch(Group& g, std::unique_ptr<Card>& c);

    friend MoveGroup& operator>>(Zone& lhs, MoveGroup&& rhs);
    friend Zone& operator>>(MoveGroup& lhs, Zone& rhs);
};

#endif
