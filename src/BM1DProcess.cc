#include "BM1DProcess.hh"

BM1DProcess::BM1DProcess(Int_t nP) :  nSteps (nP), nRun(1), p0(0.5), p1(0.3), gaussMean(0), gaussSigma(1)
{
  randomGenerator = new TRandom();
  randomGeneratorGauss = new TRandom();
}

BM1DProcess::BM1DProcess(Int_t nP, Int_t nRun, double mean, double sigma) :  nSteps (nP), nRun(nRun), p0(0.5), p1(0.3), gaussMean(mean), gaussSigma(sigma)
{
  randomGenerator = new TRandom();
  randomGenerator -> SetSeed(0);
  randomGeneratorGauss = new TRandom();
  std::cout << randomGeneratorGauss -> GetSeed() << std::endl;
  randomGeneratorGauss -> SetSeed(0);
}


/*void BM1DProcess::Init(){
  t.push_back(0.0);  //let's start at t=0, x=0, you can change it if you vant, please use Set methods
  x.push_back(0.0);
}*/

void BM1DProcess::Run(int runCount){
	
	double tmpM = gaussMean;
	double tmpS = gaussSigma;
	
	t.push_back(0.0);  //let's start at t=0, x=0, you can change it if you vant, please use Set methods
	x.push_back(0.0);
	
  for (Int_t i = runCount*1000+1; i < nSteps+(runCount*1000);i++)
    {
		if(x[i-1] < 30 && x[i-1] > 20)
		{
			gaussSigma = gaussSigma/5;
		}
		else 
		{
			gaussSigma = tmpS;
		}
		
      rand1 = randomGenerator->Uniform();
	  //std::cout << "Rand unif:" << rand1 << std::endl;
	if(rand1 < p0) {  //step in time, but no step in x
						t.push_back(t[i-1] + 1);
						x.push_back(x[i-1]);
					}
	else
		{//step left or right
			double randGauss = randomGeneratorGauss -> Gaus(gaussMean,gaussSigma);
			//std::cout << "Rand gauss:" << randGauss << std::endl;
			t.push_back(t[i-1]+1);
			x.push_back(x[i-1]+randGauss); //one step right
		
		}
}
}

void BM1DProcess::RunMultiple()
{
	for(int i=0; i<nRun; i++)
	{
		Run(i);
	}
}