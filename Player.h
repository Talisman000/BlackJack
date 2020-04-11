#include <iostream>
#include <vector>
#include "Card.h"
class Player
{
    int points;
    std::vector<Card> cards;
    public:
    Player();
    int GetPoints(){return points;}
    Card PullCard(std::vector<Card> &pool);
    Card GetCard(int n){return cards[n];}
    int GetNumberofCard(){return cards.size();}
    void AddPoints(int p){points += p;}
};
