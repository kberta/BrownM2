#ifndef BM1DProcess_h
#define BM1DProcess_h 1

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "TRandom.h"

class BM1DProcess {
public:
  BM1DProcess(Int_t n); //n is the number of steps
  BM1DProcess(Int_t nP, Int_t nRun, double mean, double sigma);
  ~BM1DProcess();
  
  void SetP0(Double_t p0_new){p0 = p0_new;}
  void SetP1(Double_t p1_new){p1 = p1_new;}

  //void Init();
  void RunMultiple();
  
  std::vector<Double_t> GetT(){return t;}
  std::vector<Double_t> GetX(){return x;}

 private:
 
	void Run(int runCount);
 
  Int_t nSteps;
  Int_t nRun;
  Double_t p0,p1,p2,p3,p4;
  TRandom* randomGenerator;
  TRandom* randomGeneratorGauss;
  double gaussMean, gaussSigma;
  Double_t rand1;
  std::vector<Double_t> t;
  std::vector<Double_t> x;
};
  
#endif  
 
