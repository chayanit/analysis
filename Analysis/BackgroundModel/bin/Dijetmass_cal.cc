#include <iostream>
#include <string>
#include <memory>
#include "TSystem.h"
#include "TFile.h"
#include "TTree.h"
#include "TF1.h"
#include "TH1.h"
#include "TVector3.h"
#include "TRandom3.h"

using namespace std;

int main(int /* argc */, char* /* argv */[]) {
  const auto cmsswBase = static_cast<std::string>(gSystem->Getenv("CMSSW_BASE"));

  const std::string inputFileName =
    "/nfs/dust/cms/user/chayanit/2016Data_05_01_2017/TripleBTagReverseSelection_80X_lowMTrigger_Run2016BtoH-23Sep2016-v2_05_01_2017.root";

  const std::string outputFileName =
    cmsswBase+"/src/Analysis/BackgroundModel/data/2016DataRereco_05_01_2017/TripleBTagReverseSelectionBtoH2016_80X_lowMTrigger_Run2016BtoH-23Sep2016-v2_05_01_2017.root";  
  
  TFile input(inputFileName.c_str(), "read");
  std::unique_ptr<TTree> inputTree(static_cast<TTree*>(input.Get("MssmHbb")));

  TFile output(outputFileName.c_str(), "recreate");
  TTree outputTree("MssmHbb", "MssmHbb");
 
  // could think of using float, but better keeping it in agreement with input:
  double mbb,pt1,pt2,pt3,eta1,eta2,eta3,phi1,phi2,phi3;
  double m12,m13,m23; 
 
  inputTree->SetBranchAddress("ObjM12", &mbb);
  inputTree->SetBranchAddress("LeadPt[0]", &pt1);
  inputTree->SetBranchAddress("LeadPt[1]", &pt2);
  inputTree->SetBranchAddress("LeadPt[2]", &pt3);
  inputTree->SetBranchAddress("LeadEta[0]", &eta1);
  inputTree->SetBranchAddress("LeadEta[1]", &eta2);
  inputTree->SetBranchAddress("LeadEta[2]", &eta3);
  inputTree->SetBranchAddress("LeadPhi[0]", &phi1);
  inputTree->SetBranchAddress("LeadPhi[1]", &phi2);
  inputTree->SetBranchAddress("LeadPhi[2]", &phi3);

  outputTree.Branch("mbb", &mbb, "mbb/D");
  outputTree.Branch("m12", &m12, "m12/D");
  outputTree.Branch("m13", &m12, "m13/D");
  outputTree.Branch("m23", &m12, "m23/D");
  //TH1D *Mbb = new TH1D("mbb","mbb;M_{12} [GeV];Events/20 GeV",60,0.,1200.);
 
  for (int i = 0; i < inputTree->GetEntriesFast(); ++i) {
    inputTree->GetEntry(i);

    TVector3 j12 = 
    m12 = 

    if(mbb > 0.)    
    outputTree.Fill();
  }
  outputTree.Write();
  output.cd();
  output.Close();
  return 0;
}
