#include <iostream>
#include "BM1DProcess.hh"
#include "Plotter.hh"
#include "TApplication.h"

using namespace std;

int main(int argc, char* argv[])
{
  TApplication App("tapp", &argc, argv);
  Int_t n = 1000;
  double mean = 0.1;
  double sigma = 2;
  Int_t numOfRun = 1000;
  BM1DProcess *myBM1DProcess = new BM1DProcess(n, numOfRun, mean, sigma);
  //myBM1DProcess->Init();
  myBM1DProcess->RunMultiple();
  Plotter* myPlotter = new Plotter();
  myPlotter->Plot(n, numOfRun, myBM1DProcess->GetT(), myBM1DProcess->GetX());

  App.Run();
  return 0;
}
