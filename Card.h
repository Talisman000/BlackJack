enum Suit
{
    SPADE,
    CLUB,
    DIAMOND,
    HEART,
};
class Card
{
    Suit suit;
    int number;
    public:
    Card(Suit s,int n);
    Suit GetSuit(){return suit;}
    int GetNumber(){return number;}
};