//============================================================================
// Name        : ClockSolitaire.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Using the deck and card objects,
//				 implement the clock solitaire game https://en.wikipedia.org/wiki/Clock_Patience
//============================================================================

#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Pile.h"

using namespace std;

bool checkPiles(Pile* piles, bool log) {
	bool allOk=true;
	if (log) {cout << "Unrevelead piles: ";}
	for (int i=0;i<13;i++) {
		if (!piles[i].hasRevealed()) {
			if (log) {cout << i << ", ";}
			allOk=false;
		}
	}
	if (allOk && log) {cout << "None" << endl;}
	if (log) {cout << endl;}
	return allOk;
}

Pile* createPiles() {
	Deck* deck= new Deck();
	deck->shuffle();
	Pile* piles= new Pile[13];

	for (int j=0;j<13;j++) {
		piles[j].setRank(j);
		for (int i=0;i<4;i++) {
			Card* c= deck->deal();
			piles[j].addCard(c);
		}
	}
	return piles;
}

bool play(bool log) {
	Pile* piles= createPiles();

	// start from the central pile
	int rank=12;
	Pile currentPile=piles[rank];
	Card* cptr;

	int revealedKings=0;
	while (true) {
		if (log) {currentPile.print();cout << endl;}
		cptr=currentPile.getTop();
		piles[rank]=currentPile;

		rank=(*cptr).getRank();
		if (rank==12) {
			revealedKings++;
			if (log) {cout << "king revealed: " << revealedKings << endl;}
		}
		if (revealedKings==4) {
			if (checkPiles(piles,log)) {
				if (log) {cout << "Game is won" << endl;}
				return true;
			} else {
				if (log) {cout << "Game is lost" << endl;}
				return false;
			}
		}
		currentPile= piles[rank];
		currentPile.addUnder(cptr);
		piles[rank]=currentPile;
	}
}

void multiplePlays(int numplays) {
	int wins=0;
	for (int i=0;i<numplays;i++) {
		if (play(false)) {
			wins++;
		}
	}
	cout << "Wins: " << wins << " Losses: " << numplays-wins << endl;
	cout << "Ratio wins: " << (double)wins/numplays << ", Theoretical win probability: " << 1.0/13.0 << endl;
}

int main() {
	srand (time(NULL));
//	play(true);
	multiplePlays(10000);
	return 0;
}




