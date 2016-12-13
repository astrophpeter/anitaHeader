#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include <fstream>
using namespace std;

void writeToText(){
  TFile *f=new TFile("eventHeadFile127.root"); // opens the root file
  TTree *tr=(TTree*)f->Get("tree"); // creates the TTree object
  tr->Scan(); >scan.log// prints the content on the screen

}
