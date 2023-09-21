#include "Zone.h"

MoveGroup& operator>>(Zone& lhs, MoveGroup&& rhs)
{
    for (auto it = lhs.cards.begin(); it != lhs.cards.end();)
    {
        if (rhs.matchFound(*it))
        {
            rhs.cards.push_back(std::move(*it));
            it = lhs.cards.erase(it);

            if (rhs.groups.empty())
                break;
        }
        else
            ++it;
    }
    std::cout << "RHS TEMP CALLED\n";
    return rhs;
}

Zone& operator>>(MoveGroup& lhs, Zone& rhs)
{
    for (auto& c : lhs.cards)
        rhs.cards.push_back(std::move(c));

    lhs.cards.clear();

    std::cout << "LHS TEMP CALLED\n";
    return rhs;
}



MoveGroup::MoveGroup(std::initializer_list<Group> grps)
{
    for (auto& g : grps)
        groups.emplace_back(g);
}

bool MoveGroup::matchFound(std::unique_ptr<Card> &c)
{
    for (auto it = groups.begin(); it != groups.end(); it++)
    {
        if (validMatch(*it, c))
        {
            if (!--(it->numCards)) // tick down # of cards left to find in the group, test if 0
                groups.erase(it);

            return true;
        }
    }
    return false;
}

bool MoveGroup::validMatch(Group& g, std::unique_ptr<Card>& c)
{
    return g.numCards > 0 &&
           g.eType == c->getEType() &&
           g.cType == c->getCType();
}

MoveGroup::Group::Group(int nCards, EnergyType et) : numCards(nCards), cType(CardType::ENERGY), eType(et)
{}

MoveGroup::Group::Group(int nCards, CardType ct) : numCards(nCards), cType(ct), eType(EnergyType::ANY)
{}

MoveGroup::Group::Group(int nCards, CardType ct, EnergyType et) : numCards(nCards), cType(ct), eType(et)
{}

bool MoveGroup::Group::operator==(const std::unique_ptr<Card> &c)
{
    return false;
}