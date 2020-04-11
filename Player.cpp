#include "Player.h"
Player::Player(){
    points = 0;
}
Card Player::PullCard(std::vector<Card> &pool)
{
    int pos = rand() % pool.size() + 1;
    Card card = pool[pos];
    pool.erase(pool.begin() + pos);
    cards.emplace_back(card);
    return card;
}

