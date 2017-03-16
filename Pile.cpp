/*
 * Pile.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: Can Candan
 */

#include <iostream>
#include "Pile.h"
using namespace std;

Pile::Pile() {
	// TODO Auto-generated constructor stub
	cardptrs= new Card*[5];
	idx=0;
	firstUp=4;
}

Pile::~Pile() {
	// TODO Auto-generated destructor stub
}

void Pile::addUnder(Card* cardptr) {
	cardptrs[idx]=cardptr;
	if (firstUp==-1) {
		firstUp=idx;
	}
	idx++;
}

int Pile::getRank() const {
	return rank;
}

void Pile::print() {
	cout << "pile " << rank << ": ";
	for (int i=0;i<5;i++) {
		if (i==firstUp) {
			cout << "*";
		}
		if (cardptrs[i]) {
			cout << *(cardptrs[i]);
			cout << ", ";
		}
	}
	cout.flush();
}

void Pile::addCard(Card* card) {
	if (idx==4) {
		throw domain_error("Pile contains max 5 cards");
	}
	cardptrs[idx++]=card;
}

void Pile::setRank(int rank) {
	this->rank = rank;
}

Card* Pile::getTop() {
	Card* top= cardptrs[0];
	for (int i=0;i<5;i++) {
		cardptrs[i]=cardptrs[i+1];
	}
	cardptrs[4]=nullptr;
	idx--;
	if (firstUp!=-1) {
		firstUp--;
	}
	return top;
}

bool Pile::hasRevealed() {
	if (firstUp == 0) {
		return true;
	}
	return false;
}
