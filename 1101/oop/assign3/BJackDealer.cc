/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackDealer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
}

using namespace std;
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

// constructor 
// nDeck is the number of standard decks that the dealer will deal with
BJackDealer::BJackDealer(int nSet) {
  player = new BJackPlayer("Dealer");
  deck_count = nSet;
}

// distribute a card to the player
// remove the card from the bank if the card has been taken
int
BJackDealer::giveCard() {
  int end = bank[bank.size()-1];
  bank.pop_back();
  return end;
}

// give the dealer one card unconditionally
void 
BJackDealer::addCard() {
  Card newCard(this -> giveCard());
  player->addCard(newCard);
}

// give the dealer as many cards as necessary to exceed the player 
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

void
BJackDealer::addCards(int oppTotal) {
  if(oppTotal > 21){
    while(player->totalPoints() < 17){
      this -> addCard();
    }
  }else{
    while(player->totalPoints() < oppTotal){
      this -> addCard();
    }
  }
}

// Determine who has win the game.
// The total points that the dealer has should be greater than 
// the player at the point this function is called.

result
BJackDealer::judge(int oppTotal) const {
  int myTotal = player->totalPoints();
  if(oppTotal > 21 && myTotal > 21){
    return tie;
  }else if(oppTotal >= 17 && oppTotal <= 21 && myTotal > 21){
    return win;
  }else if(oppTotal > 21 && myTotal >= 17 && myTotal < 21){
    return lose;
  }else if(oppTotal >= 17 && myTotal >= 17){
    if(oppTotal > myTotal){
      return win;
    }else if(oppTotal < myTotal){
      return lose;
    }else{
      return tie;
    }
  }else{
    if(myTotal > 21){
      return tie;
    }else{
      return lose;
    }
  }
}

// start a new game
// before starting a new game, check if there are enough cards left for 
// the next game.

void
BJackDealer::start(void) {
  if(int(bank.size()) < (deck_count * MIN_START_CARD)){
    this -> shuffle();
  }
  player->start();
}

// shuffle the deck of cards
void 
BJackDealer::shuffle(void) {
  bank.clear();
  vector<int>().swap(bank);
  // Everytime I get a new random number, I'll check if its id
  // is already in the array, if exist, discard it and rand again,
  // otherwise put it into the array, and push it's pokour id into
  // the vector.
  int total_count = 52 * deck_count;
  int* ids_ = new int[total_count]();
  int ids_count = 0;
  while(ids_count < total_count){
    int new_card_id = rand() % total_count;
    bool found = false;
    for(int i = 0; i < ids_count; i++){
      if(ids_[i] == new_card_id){
        found = true;
        break;
      }
    }
    if(!found){
      bank.push_back(new_card_id % 52);
      ids_[ids_count++] = new_card_id;
    }
  }
  // Now the vector<int> bank is a set of shuffled cards,
  // but STL vector dosen't provide functions like "pop_front()",
  // so I reverse the vector and use pop() to make it be like pop_front().
  reverse(bank.begin(), bank.end());
}

// reset the seed before shuffling
void
BJackDealer::shuffle(long seed) {
  srand(seed);
  this -> shuffle();
}

// open the dealer's first card 
void 
BJackDealer::openFirstCard(void) {
  player->openFirstCard();
}

// show the dealer's hand to the screen
void 
BJackDealer::showCards(void) const {
  player->showCards();
}

// get the dealer's total points
int BJackDealer::totalPoints(void) const
{
  return player->totalPoints();
}

