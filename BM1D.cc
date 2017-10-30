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
  double sigma = 1;
  BM1DProcess *myBM1DProcess = new BM1DProcess(n, mean, sigma);
  myBM1DProcess->Init();
  myBM1DProcess->Run();
  Plotter* myPlotter = new Plotter();
  myPlotter->Plot(n, myBM1DProcess->GetT(), myBM1DProcess->GetX());

  App.Run();
  return 0;
}
