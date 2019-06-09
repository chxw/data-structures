#include <iostream>
#include <cassert>
#include <string>
#include <stdlib.h>

#include "Card.cpp"
#include "CardDeck.cpp"

CardDeck create_suit(std::string s){
	std::string suit = s;

	Card c1(suit, 1);
	Card c2(suit, 2);
	Card c3(suit, 3);
	Card c4(suit, 4);
	Card c5(suit, 5);
	Card c6(suit, 6);
	Card c7(suit, 7);
	Card c8(suit, 8);
	Card c9(suit, 9);
	Card c10(suit, 10);
	Card c11(suit, 11);
	Card c12(suit, 12);
	Card c13(suit, 13);

	Card cards[13] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13};

	CardDeck deck;

	for(int i = 0; i < 13; i++){
		deck.add(cards[i]);
	}

	return deck;
}

CardDeck create_full_deck(){
	std::string s = "SPADE";
	std::string h = "HEARTS";
	std::string c = "CLUBS";
	std::string d = "DIAMONDS";

	CardDeck spades = create_suit(s);
	CardDeck hearts = create_suit(h);
	CardDeck clubs = create_suit(c);
	CardDeck diamonds = create_suit(d);

	CardDeck full_deck;

	for(int i = 0; i < 13; i++){
		full_deck.add(spades.at(i));
	}

	for(int i = 0; i < 13; i++){
		full_deck.add(hearts.at(i));
	}

	for(int i = 0; i < 13; i++){
		full_deck.add(clubs.at(i));
	}

	for(int i = 0; i < 13; i++){
		full_deck.add(diamonds.at(i));
	}

	return full_deck;
}

Card random_card(CardDeck deck){
	int a = rand() % 51 + 1;

	return deck.at(a);
}

int sum(CardDeck deck){
	int sum = 0;

	for(int i = 0; i < deck.getSize(); i++){
		sum += (deck.at(i)).getNumber();
	}

	return sum;
}

int display_hand(CardDeck deck, std::string whoami){
	int s = sum(deck);
	std::cout << whoami + " hand: " + deck.toString() << std::endl;
	std::cout << s << std::endl;
	return s;
}

int main(){
	CardDeck full_deck = create_full_deck();

	CardDeck player_deck;
	player_deck.add(random_card(full_deck));
	player_deck.add(random_card(full_deck));

	int player_sum = sum(player_deck);

	CardDeck dealer_deck;
	dealer_deck.add(random_card(full_deck));
	dealer_deck.add(random_card(full_deck));

	int dealer_sum = sum(dealer_deck);
	
	while(player_sum <= 21 or dealer_sum <= 21){
		if (player_deck.getSize() == 2){
			player_sum = display_hand(player_deck, "Your");
			dealer_sum = display_hand(dealer_deck, "Dealer");
		}

		if(player_sum == 21 or dealer_sum == 21){
			break;
		}

		std::string user;
		std::cout << "Hit or hold? " << std::endl;
		std::cin >> user;

		if (user == "hit" or user == "HIT" or user == "Hit" or user == "HIt"){
			player_deck.add(random_card(full_deck));
			player_sum = display_hand(player_deck, "Your");
		}
		if (dealer_sum < 19){
			dealer_deck.add(random_card(full_deck));
			dealer_sum = display_hand(player_deck, "Dealer");
		}
		else{
			break;
		}

	}

	if(player_sum > 21){
		std::cout << "You lose!" << std::endl;
	}
	else if (dealer_sum > 21){
		std::cout << "You win!" << std::endl;
	}
	else if (dealer_sum > player_sum){
		std::cout << "You lose!" << std::endl;
	}
	else if (dealer_sum < player_sum){
		std::cout << "You win!" << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}

	return 0;
}