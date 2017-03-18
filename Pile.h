/*
 * PileQueue.h
 *
 *  Created on: Mar 16, 2017
 *      Author: Can Candan
 */

#ifndef PILE_H_
#define PILE_H_
#include "Card.h"

#define MAX_SIZE 5

class Pile {
	Card** cards;
	int front;
	int rear;
	int firstUp;
	int rank;
public:
	Pile();
	bool IsEmpty();
	bool IsFull();
	void putUnder(Card* c);
	bool hasRevealed();
	Card* getTop();
	void Print();
	virtual ~Pile();
	int getRank() const;
	void setRank(int rank);
};

#endif /* PILE_H_ */
