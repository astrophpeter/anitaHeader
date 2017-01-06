#include "TFile.h"
#include "TTree.h"


void sumAll() {

int NUM_OF_RUNS = 367;


//set up cummilitative histogram.
TH1F *tot;
tot = new TH1F("tot", "ImagePeak", 25, 0, 25);
tot->GetXaxis()->SetTitle("Image Peak [header units/1000]");
tot->GetYaxis()->SetTitle("Number of Events");


//Read in first run 0.
TFile *f = TFile::Open("run0/eventHeadFile0.root");
TTreeReader myReader("headTree", f);
TTreeReaderValue<UShort_t> imagePeak(myReader, "imagePeak");

//Fill histogram to with image peak values.
while (myReader.Next()) {
  tot->Fill(*imagePeak/1000,1);
}


//interate over all remaining runs.
for (int i =0; i <= NUM_OF_RUNS; i++) {

char headerFileLoc[150];
sprintf (headerFileLoc, "../../unix/anita3/anita4/flight1617/telem/root/run%d/eventHeadFile%d.root", i, i);

TFile *temp = TFile::Open(headerFileLoc);

//check if run exists
if (temp != 0) {
   printf("fectching data from run%d\n",i);

   // create and fill temp histogram
   TH1F *tempHist;
   tempHist = new TH1F("tot","ImagePeak",25,0,25);
   TFile *temp = TFile::Open(headerFileLoc);
   TTreeReader myReaderTemp("headTree", temp);
   TTreeReaderValue<UShort_t> imagePeakTemp(myReaderTemp, "imagePeak");

   while (myReaderTemp.Next()) {
     tempHist->Fill(*imagePeakTemp/1000,1);
   }


   //add to total histogram.
   tot->Add(tempHist);

   //clear memory.
   temp->Close();
   delete temp;

}
}

//draw cummilitative histogram
tot->Draw();
}
