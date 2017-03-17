/*
 * Pile.h
 *
 *  Created on: Mar 15, 2017
 *      Author: Can Candan
 */

#ifndef PILE_H_
#define PILE_H_
#include "Card.h"

class Pile {
	Card** cardptrs;
	int rank;
	int idx;
	int firstUp;
public:
	Pile();
	virtual ~Pile();
	void addUnder(Card* card);
	void addCard(Card* card);
	Card* getTop();
	void print();
	int getRank() const;
	void setRank(int rank);
	bool hasRevealed();
};

#endif /* PILE_H_ */
