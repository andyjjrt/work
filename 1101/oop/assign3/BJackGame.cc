/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackGame.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackGame.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer &bjp, BJackDealer &bjd) : menu(sizeof(menuItems)/sizeof(char *),menuItems), bjplayer(bjp), bjdealer(bjd) {
  game_start = false;
  bjdealer_score = initCredit;
  bjplayer_score = initCredit;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
BJackGame::oneRun() {
  menu.print();
  int answer = menu.getAnswer();

  //This switch-case is for function calling.
  switch(answer){
    case 1:
      this -> moreCard();
      break;
    case 2:
      this -> enough();
      break;
    case 3:
      this -> restart();
      break;
    case 4:
      this -> quit();
      break;
  }

  // This switch-case is for showing cards and the returning value.
  switch(answer){
    case 1:
    case 2:
    case 3:
      bjplayer.showCards();
      bjdealer.showCards();
      return true;
    case 4:
      return false;
  }
  return false;
}

// give the player one more card
// check if we can do that first
void 
BJackGame::moreCard() {
  // If the game hasn't start, then one more card is illegal
  if(!game_start){
    cout << "Game Over" << endl;
    return;
  }
  // It's illegal if you already have 21 points.
  if(bjplayer.totalPoints() >= 21){
    cout << "You are over 21 already" << endl;
  }else{
    Card newCard(bjdealer.giveCard());
    bjplayer.addCard(newCard);
  }
}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void 
BJackGame::enough() {
  // If the game hasn't start, then enough command is illegal
  if(!game_start){
    cout << "Game Over" << endl;
    return;
  }
  bjdealer.addCards(bjplayer.totalPoints());
  bjdealer.openFirstCard();

  // print the game result and count credits
  if(bjdealer.judge(bjplayer.totalPoints()) == win){
    bjplayer_score += betCredit;
    bjdealer_score -= betCredit;
    cout << "You win. Good job.";
  }else if(bjdealer.judge(bjplayer.totalPoints()) == lose){
    bjplayer_score -= betCredit;
    bjdealer_score += betCredit;
    cout << "I win. Try again.";
  }else if(bjdealer.judge(bjplayer.totalPoints()) == tie){
    cout << "It's a Tie.";
  }
  cout << "(You have " << bjplayer_score << " points, I have " << bjdealer_score << " points.)" << endl;

  // end a round;
  game_start = false;
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void 
BJackGame::restart() {

  // prevent the player from stopping game by restart
  if(game_start){
    cout << "Game is not over yet. Choose 'enough' to end a game" << endl;
    return;
  }

  // if one of them has no credits, the game can't start
  if(!bjplayer_score || !bjdealer_score){
    cout << "Sorry. Game over. No loan here." << endl;
    return;
  }
  
  // start a round and initialize the player and dealer.
  game_start = true;
  bjdealer.start();
  bjplayer.start();
  bjplayer.openFirstCard();

  //give cards
  for(int i = 0; i < 2; i++){
    Card newCard(bjdealer.giveCard());
    bjplayer.addCard(newCard);
    bjdealer.addCard();
  }
}


// quit the game
void
BJackGame::quit(){

}

