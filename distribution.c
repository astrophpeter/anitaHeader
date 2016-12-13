//////////////////////////////////////////////////////////
//      A simple script to plot the distribution        //
//      of variable in the anita eventheaderfile        //
//                  @author Peter McGill                //
//////////////////////////////////////////////////////////
#include "TFile.h"
#include "TTree.h"

void distribution()
{
   // Variables used to store the data
   TH1C *NUM;
   // create the TH1F histogram
   NUM = new TH1C("NUM", "priority", 1000, 0, 100);




  // open the file
   TFile *f = TFile::Open("run127/eventHeadFile127.root");
   if (f == 0) {
   // if we cannot open the file, print an error message and return immediatly
      printf("Error: cannot open root file");
      return;
   }

   // Create tyhe tree reader and its data containers
   TTreeReader myReader("headTree", f);
   // Create array to store priorities
   //TTreeReaderArray<UChar_t> (myReader, "priority");

   // Variable to store single Prioirty value
   TTreeReaderValue<UChar_t> priority(myReader, "priority");

   // Loop over all entries of the TTree.
   while (myReader.Next()) {
   // Get the data from the current TTree entry by getting
   // the value from the connected reader (prioroty):
   //printf("priority: %d \n", *priority);

   NUM->Fill(*priority,1);
   }

   // and draw it:
   NUM->Draw();
}
