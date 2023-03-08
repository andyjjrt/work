/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     QueueTest.cc
   PURPOSE

   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Dec 11, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

#include "AnsiPrint.h"
#include "Queue.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Print my id
 */

void PrintMyID(const char *studId) {

  char *str = new char[strlen(studId) + 5];
  sprintf(str, "ID: %s", studId);
  AnsiPrint(str, yellow, red, true, true);
  cout << endl;
  delete[] str;
}

/**
 * PrintUsage
 */

void PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " [passes [display [seed]]]" << endl;
}

int main(int argc, char **argv) {

  istream *is1 = &cin, *is2 = &cin;

  if (argc > 3) {
    PrintUsage(argv[0]);
    exit(-1);
  } else if (argc > 2) {
    is2 = new ifstream(argv[2]);
    if (is2 == NULL) {
      cerr << "Can't open file " << argv[2] << endl;
      exit(1);
    }
  }
  if (argc > 1) {
    is1 = new ifstream(argv[1]);
    if (is1 == NULL) {
      cerr << "Can't open file " << argv[1] << endl;
      exit(2);
    }
  }
  string line;

  // test integer queue
  Queue<int> *IntQueue1 = new Queue<int>;

  // enqueue exercises on IntQueue1
  int IntQueueNum = 0;
  while(getline(*is1, line)){
    int data = atoi(line.c_str());
    IntQueue1->enqueue(data);
    IntQueueNum++;
  }
  IntQueue1->print();

  // test copy constructor
  Queue<int> IntQueue2 = *IntQueue1;
  IntQueue2.print();

  // test destructor
  delete IntQueue1;

  // dequeue exercises on IntQueue2
  for(int i = 0; i < IntQueueNum; i++){
    IntQueue2.dequeue();
  }

  // dequeue error test on IntQueue2
  IntQueue2.dequeue();
  IntQueue2.print();

  // test character queue
  Queue<char> CharQueue1, CharQueue2;

  // enqueue exercises on CharQueue1
  int CharQueueNum = 0;
  while(getline(*is2, line)){
    char data = line.c_str()[0];
    CharQueue1.enqueue(data);
    CharQueueNum++;
  }
  CharQueue1.print();

  //test assignment operator
  CharQueue2 = CharQueue1;
  CharQueue2.print();

  // dequeue exercise on myCharQ1
  for(int i = 0; i < CharQueueNum; i++){
    CharQueue2.dequeue();
  }
  CharQueue2.print();
  
  PrintMyID("109703040");
  return 0;
}
