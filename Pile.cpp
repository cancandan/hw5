/*
 * PileQueue.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: Can Candan
 */

#include "Pile.h"

#include <iostream>
using namespace std;

Pile::Pile() {
	// TODO Auto-generated constructor stub
	cards = new Card*[MAX_SIZE];
	front=-1;
	rear=-1;
	rank=-1;
	firstUp=4;
}

bool Pile::IsEmpty() {
	return (front==-1 && rear==-1);
}

bool Pile::IsFull() {
	return (rear+1)%MAX_SIZE == front ? true : false;
}

void Pile::putUnder(Card* c) {
	if(IsFull()) {
		throw domain_error("Pile is full");
	}
	if (IsEmpty()) {
		front = rear = 0;
	} else {
		rear = (rear+1)%MAX_SIZE;
	}
	cards[rear] = c;
}

Card* Pile::getTop() {
	Card* ret;
	if(IsEmpty()) {
		throw domain_error("Pile is empty");
	} else if(front == rear) {
		ret = cards[front];
		rear = front = -1;
	} else {
		ret = cards[front];
		front = (front+1)%MAX_SIZE;
	}
	firstUp--;
	return ret;
}

void Pile::Print() {
	if (IsEmpty()) {
		cout << "Pile Empty" << endl;
		return;
	}
	cout << "Pile " << rank<<": ";
    int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
    for(int i = 0; i <count; i++) {
        int idx= (front+i) % MAX_SIZE;
		if (cards[idx]) {
			cout<< *(cards[idx]) << " ";
		}
		if (firstUp==idx) {
			cout << "* ";
		}
		cout << " ";
	}
	cout << endl;
}

Pile::~Pile() {
	// TODO Auto-generated destructor stub
	cout << "Pile destruct" << endl;

}

int Pile::getRank() const {
	return rank;
}

void Pile::setRank(int rank) {
	this->rank = rank;
}

bool Pile::hasRevealed() {
	return firstUp==0?true:false;
}
