/*
 * PileQueue.h
 *
 *  Created on: Mar 16, 2017
 *      Author: Can Candan
 */

#ifndef PILE_H_
#define PILE_H_
#include "Card.h"
#include <queue>

#define MAX_SIZE 5

class Pile {
	vector<Card*> cards;
	int firstUp;
	int rank;
public:
	Pile();
	void putUnder(Card* c);
	Card* getTop();
	bool hasRevealed();
	int getRank() const;
	void setRank(int rank);
	void Print();
	virtual ~Pile();
	Pile& operator=(Pile& p);

};

#endif /* PILE_H_ */
