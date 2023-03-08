/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include <vector>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str,yellow,red, true, true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}

/**
 * Main Function Call
 */
int main(int argc, char **argv) {

  int ncards=0;  // number of cards to draw 
  const char num_to_flower[4] = {'S', 'H', 'D', 'C'}; // Number to Card's flower character
  if (argc==3) {
    long seed=atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  } else if (argc==2) {
    ncards=atoi(argv[1]);
  } else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // Error when ncards > 52
  if(ncards > 52){
    cout << "Sorry, number of cards can not exceed 52." << endl;
    exit(-1);
  }

  // Get random array from self defined function
  int* cards = CardDraw(ncards);
  // print_card is the index of current printing card
  int print_card = 0;
  /*
    printing devided into four parts:
      1) 5 in a row, use quotient of ncard / 5 to get rows
      2) A card is 11 char height
      3) a row has 5 or less cards
      4) A card is 11 char width
    so I use 4 for-loops to print the output.
  */
  for(int i = 0; i <= (ncards-1) / 5; i++, print_card += 5){
    for(int j = 0; j < 11; j++){
      for(int k = print_card; k < print_card + 5 && k < ncards; k++){
        for(int l = 0; l < 11; l++){
          // This section use PrintMyID() as template
          char *str= new char;
          sprintf(str, "%c", card[cards[k]/4][j][l] == 'x' ? num_to_flower[cards[k]%4] : card[cards[k]/4][j][l]);
          // If the card is HEART or DIAMOND, print red word, otherwise, print black
          if(cards[k]%4 == 1 || cards[k]%4 == 2){
            AnsiPrint(str,red,white, false, false);
          }else{
            AnsiPrint(str,black,white, false, false);
          }
          delete str;
        }
        cout << " ";
      }
      cout << endl;
    }
  }

  // Print my id at the end of the program
  PrintMyID("109703040");

  return 0;

}
