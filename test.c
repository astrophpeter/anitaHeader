#include "TFile.h"
#include "TTree.h"

void test()
{
   // Variables used to store the data
   Int_t     totalSize = 0;

// open the file
   TFile *f = TFile::Open("eventHeadFile127.root");
   if (f == 0) {
   // if we cannot open the file, print an error message and return immediatly
      printf("Error: cannot open root file");
      return;
   }

   // Create tyhe tree reader and its data containers
   TTreeReader myReader("headTree", f);

   TTreeReaderValue<UChar_t> priority(myReader, "priority");

   // Loop over all entries of the TTree or TChain.
   while (myReader.Next()) {
   // Get the data from the current TTree entry by getting
   // the value from the connected reader (eventSize):
   printf("priority: %d \n", *priority);
   }

   Int_t sizeInMB = totalSize;
   printf("Total sum of priorities is : %d \n", sizeInMB);
}
