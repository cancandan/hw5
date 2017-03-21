//============================================================================
// Name        : ClockSolitaire.cpp
// Author      : Can Candan
// Version     :
// Copyright   : Your copyright notice
// Description : Using the deck and card objects,
// implement the clock solitaire game https://en.wikipedia.org/wiki/Clock_Patience
//============================================================================

#include <ctime>
#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "Pile.h"
using namespace std;

bool checkPiles(vector<Pile> piles, bool log) {
    bool allOk=true;
    if (log) {cout << "Unrevealed piles: ";}
    for (int i=0;i<13;i++) {
        if (!piles[i].hasRevealed()) {
            if (log) {cout << i << " ";}
            allOk=false;
        }
    }
    if (allOk && log) {cout << "None" << endl;}
    if (log) {cout << endl;}
    return allOk;
}

vector<Pile> createPiles(bool log, Deck* deck) {
	deck->shuffle();
	vector<Pile> piles(13);
	for (int j=0;j<13;j++) {
		piles[j].setRank(j);
		for (int i=0;i<4;i++) {
			Card* c=deck->deal();
			piles[j].putUnder(c);
		}

		if (log) {piles[j].Print();}

	}
	return piles;
}

bool play(bool log) {
    if (log) {cout << "Create piles by dealing cards:" <<endl << endl;}
    Deck* deck= new Deck();
    vector<Pile> piles=createPiles(log, deck);

	int currentPileRank=12;
	Pile* currentPile=&piles[currentPileRank];
	Card* currentCard;
	int revealedKings=0;

    if (log) {cout << endl << "Game begins:" <<endl << endl;}
	while (true) {
		if (log) currentPile->Print();

		currentCard=currentPile->getTop();
		currentPileRank=currentCard->getRank();

		if (currentPileRank==12) {
			revealedKings++;
            if (log) {cout << "King revealed: " << revealedKings << endl << endl;}
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
		currentPile= &piles[currentPileRank];
		currentPile->putUnder(currentCard);
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
	time_t t= time(NULL);

//	1489857622 a winning time
//	time_t t=1489857622;

	cout << "Current Time :" << t << endl << endl;
    srand (t);

//    Pile* piles= createPiles(true);
	play(true);
//    multiplePlays(10000);
    return 0;
}
