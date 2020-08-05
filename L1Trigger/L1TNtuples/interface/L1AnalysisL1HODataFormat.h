#ifndef __L1Analysis_L1AnalysisL1HODataFormat_H__
#define __L1Analysis_L1AnalysisL1HODataFormat_H__

#include <vector>

namespace L1Analysis {
  struct L1AnalysisL1HODataFormat {
    L1AnalysisL1HODataFormat() { Reset(); };
    ~L1AnalysisL1HODataFormat(){};

    void Reset() {
      nHcalDetIds = 0;
      nHcalQIESamples = 0;
      sumQ = 0 ; 
      hcalDetIdIEta.clear();
      hcalDetIdIPhi.clear();
      hcalQIESample.clear();
      hcalQIESampleAdc.clear();
      hcalQIESampleDv.clear();
      hcalQIESampleEr.clear();
      QIESampleFc.clear();
      QIESampleFc_MPedestals.clear();
      QIESamplePedestal.clear();
      SampleEnergy.clear();
    }

    unsigned int nHcalDetIds;
    unsigned int nHcalQIESamples;
    double sumQ ; 
    std::vector<int> hcalDetIdIEta;
    std::vector<int> hcalDetIdIPhi;
    std::vector<int> hcalQIESample;
    std::vector<int> hcalQIESampleAdc;
    std::vector<int> hcalQIESampleDv;
    std::vector<int> hcalQIESampleEr;
    std::vector<float> QIESampleFc;
    std::vector<float> SampleEnergy;
    std::vector<float> QIESamplePedestal;
    std::vector<float> QIESampleFc_MPedestals;
  };
}  // namespace L1Analysis
#endif
