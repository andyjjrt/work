/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "BJackPlayer.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(const char *player_name) {

  name = player_name;
  points = 0;
  open_first_card = false;

}

// start the black jack game with a new card
void
BJackPlayer::start(void) {
  int rand_id = rand() % 52;
  Card newCard(rand_id);
  cards.push_back(newCard);
  points += newCard.getPoint();
}

// add a new card to the current hand.
// need to protect the array from overflowing
void 
BJackPlayer::addCard(Card card) {
  
}

// add a new card to the current hand.
// need to protect the array from overflowing
void 
BJackPlayer::addCard() {
  int new_id = rand() % 52;
  Card new_card(new_id);
  cards.push_back(new_card);
  points += new_card.getPoint();
}

// get the total points of the current hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

int
BJackPlayer::totalPoints(void) const {
  return points;
}

// set the status of the first card

void
BJackPlayer::openFirstCard() {
  open_first_card = true;
}

// print the current hand to the screen graphically

void 
BJackPlayer::showCards() const {
  int ncards = cards.size();
  int print_card = 0;
  const char player_display[12] = "Player     ";
  for(int i = 0; i <= (ncards-1) / 5; i++, print_card += 5){
    for(int j = 0; j < 11; j++){
      cout << player_display[j] << " ";
      for(int k = print_card; k < print_card + 5 && k < ncards; k++){
        for(int l = 0; l < 11; l++){
          // This section use PrintMyID() as template
          char *str= new char;
          if(k == 0){
            if(open_first_card){
              sprintf(str, "%c", card[cards[k].getPip()][j][l] == 'x' ? cardAbbrev[cards[k].getSuit()] : card[cards[k].getPip()][j][l]);
            }else{
              sprintf(str, "%c", ' ');
            }
          }else{
            sprintf(str, "%c", card[cards[k].getPip()][j][l] == 'x' ? cardAbbrev[cards[k].getSuit()] : card[cards[k].getPip()][j][l]);
          }
          // If the card is HEART or DIAMOND, print red word, otherwise, print black
          AnsiPrint(str,cardColor[cards[k].getSuit()],white, false, false);
          delete str;
        }
        cout << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}