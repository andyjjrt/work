/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.cc
   NOTE
     You are asked to design this module.
     You need to draw the given number of cards and print them out.
     Assume that you are given a deck of 52 cards. The cards do not reappear.
     That is, you do not put a card back into the deck after it is drawn.
***************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/*****************************************
  CardDraw(int card_num) returns an array 
*****************************************/

int* CardDraw(int card_num){
  
  // draw_count is the count that has drawn

  int* cards = (int*) calloc(sizeof(int), 52);
  int draw_count = 0;

  /*
    keep checking if the drawn car is in the array,
    if exist, append into the array and draw_count++,
    otherwise, draw again.
    It will make sure the cards don't reappear.
  */

  while(draw_count < card_num){
    int drawcard = (rand() % 52);
    bool is_exist = false;
    for(int i = 0; i < draw_count; i++){
      if(drawcard == cards[i]){
        is_exist = true;
        break;
      }
    }

    if(!is_exist){
      cards[draw_count] = drawcard;
      draw_count++;
    }
  }
  return cards;
}