#include <algorithm>
#include <string>
#include <map>
#include "Player.h"
#include <time.h>
std::map<Suit, std::string> suitName{ {SPADE,"Spade"},{CLUB,"Club"},{DIAMOND,"Diamond"},{HEART,"Heart"} };
void Pull(Player& player, std::vector<Card>& pool, bool isPlayer);
void Result(Player& player, Player& dealer);
int main()
{
	srand((unsigned int)time(NULL));
	//カードプール初期化
	std::vector<Card> CardPool;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			Card card(static_cast<Suit>(i), j);
			CardPool.emplace_back(card);
		}
	}
	//プレイヤーの初期化
	Player player;
	Player dealer;
	for (int i = 0; i < 2; i++)
	{
		Pull(player, CardPool, true);
		Pull(dealer, CardPool, false);
	}
	while (true)
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Dealer:" << suitName[dealer.GetCard(0).GetSuit()] << " " << dealer.GetCard(0).GetNumber() << std::endl;
		std::cout << "Player:";
		for (int i = 0; i < player.GetNumberofCard(); i++)
		{
			std::cout << suitName[player.GetCard(i).GetSuit()] << " " << player.GetCard(i).GetNumber() << ", ";
		}
		std::cout << std::endl;
		std::cout << "Pull a card? (y/n):";
		char c;
		std::cin >> c;
		if (c == 'y') {
			Pull(player, CardPool, true);
			if (player.GetPoints() > 21) {
				Result(player, dealer);
				break;
			}
		}
		else if (c == 'n') {
			while (dealer.GetPoints() < 17) {
				Pull(dealer, CardPool, false);
			}
			Result(player, dealer);
			break;
		}
	}
	return 0;
}

void Pull(Player& player, std::vector<Card>& pool, bool isPlayer)
{
	Card card = player.PullCard(pool);
	int cardNumber = card.GetNumber();
	if (cardNumber == 1)
	{
		if (isPlayer)
		{
			std::cout << "You pulled " << suitName[card.GetSuit()] << " " << card.GetNumber() << "." << std::endl;
			std::cout << "Choose points y->1 n->11 :";
			while (true)
			{
				char c;
				std::cin >> c;
				if (c == 'y')
				{
					player.AddPoints(1);
					break;
				}
				else if (c == 'n')
				{
					player.AddPoints(11);
					break;
				}
			}
		}
		else
		{
			if (player.GetPoints() <= 10)
			{
				player.AddPoints(11);
			}
			else
			{
				player.AddPoints(1);
			}
		}
	}
	else
	{
		player.AddPoints(cardNumber);
	}
}
void Result(Player& player, Player& dealer) {
	std::string result;
	if (player.GetPoints() > 21) {
		result = "You Lose";
	}
	else if (dealer.GetPoints() > 21) {
		result = "You Win";
	}
	else if (player.GetPoints() > dealer.GetPoints()) {
		result = "You Win";
	}
	else if (player.GetPoints() < dealer.GetPoints()) {
		result = "You Lose";
	}
	else {
		result = "Draw";
	}
	std::cout << "------result------" << std::endl;
	std::cout<< "Dealer:";
	int dealerPoints = 0;
	for (int i = 0; i < dealer.GetNumberofCard(); i++)
	{
		std::cout << suitName[dealer.GetCard(i).GetSuit()] << " " << dealer.GetCard(i).GetNumber() << ", ";
		dealerPoints += dealer.GetCard(i).GetNumber();
	}
	std::cout << "Points:" << dealerPoints;
	std::cout << std::endl;
	std::cout << "Player:";
	int playerPoints = 0;
	for (int i = 0; i < player.GetNumberofCard(); i++)
	{
		std::cout << suitName[player.GetCard(i).GetSuit()] << " " << player.GetCard(i).GetNumber() << ", ";
		playerPoints += player.GetCard(i).GetNumber();
	}
	std::cout << "Points:" << playerPoints;
	std::cout << std::endl;
	std::cout << result << std::endl;
}