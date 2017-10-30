#include "Plotter.hh"

Plotter::Plotter()
{
  ;
}
void Plotter::Plot(Int_t n,Int_t numOfRun, std::vector<Double_t> t, std::vector<Double_t> x){
  //fOut = new TFile("result.root", "RECREATE");
  
  TMultiGraph *mg = new TMultiGraph();
  mg->SetTitle("BM1D");
  
  
  canv = new TCanvas("canc","display",800,400);
  //TTree *BM1DTree = new TTree("BM1DTree","BM1DTree");
  
  
	
  
  //BM1DTree->Branch("tl",&tl, "tl/D");
  //BM1DTree->Branch("xl",&xl, "xl/D");
  
  
  
  for(int ii= 0; ii < numOfRun; ii++)
  {
		 
		/*for (unsigned int i = 0; i < n; i++)
		{
			tl = t[i];
			xl = x[i];
			BM1DTree->Fill();
		}*/ 
			
			g1 = new TGraph(n,&t[ii*n],&x[ii*n]);
			g1->Draw();
			g1->SetLineColor(ii+1);
			g1->SetTitle("Brownian Movement D=1");
			g1->GetYaxis()->SetTitle("X");
			g1->GetXaxis()->SetTitle("Time");
			g1->SetLineWidth(1);
			g1->SetMarkerColor(1);
			g1->SetMarkerStyle(1);
			
			mg -> Add(g1);
			
			
		
  }
  mg -> Draw();
  
  //g1->Write();
  //BM1DTree->Write();
  //fOut->Close();
  
}

