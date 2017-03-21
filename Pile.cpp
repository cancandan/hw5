/*
 * PileQueue.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: Can Candan
 */

#include "Pile.h"

#include <iostream>
#include <queue>
using namespace std;

Pile::Pile() {
	// TODO Auto-generated constructor stub
	vector<Card*> cards(5);
	firstUp=4;
	rank=-1;
}


void Pile::Print() {
	cout << "Pile " << rank<<": ";
	for (vector<Card*>::iterator it= cards.begin(); it != cards.end(); ++it) {
		Card* p= *it;
		if (p) {
			cout << *p << " ";
		}
	}
	cout << "--firstUp: " << firstUp << endl;
}

void Pile::putUnder(Card* c) {
	cards.push_back(c);
}

Card* Pile::getTop() {
	Card* p=cards.front();
	cards.erase(cards.begin());
	firstUp--;
	return p;
}

Pile::~Pile() {
	// TODO Auto-generated destructor stub
	//cout << "Pile destruct" << endl;

}

int Pile::getRank() const {
	return rank;
}

void Pile::setRank(int rank) {
	this->rank = rank;
}

bool Pile::hasRevealed() {
	return firstUp<=0?true:false;
}

Pile& Pile::operator =(Pile& other) {
	rank=other.rank;
	firstUp=other.firstUp;
	return *this;
}
