#include "L1Trigger/L1TNtuples/interface/L1AnalysisL1HO.h"
#include "CalibFormats/HcalObjects/interface/HcalCoderDb.h"
#include "CalibFormats/CaloObjects/interface/IntegerCaloSamples.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"


L1Analysis::L1AnalysisL1HO::L1AnalysisL1HO() {}

L1Analysis::L1AnalysisL1HO::~L1AnalysisL1HO() {}


void L1Analysis::L1AnalysisL1HO::SetHO(const edm::SortedCollection<HODataFrame>& hoDataFrame , const edm::EventSetup& iSetup) {

  edm::ESHandle<HcalDbService> conditions;
  iSetup.get<HcalDbRecord >().get(conditions);

  for (edm::SortedCollection<HODataFrame>::const_iterator it = hoDataFrame.begin(); it != hoDataFrame.end(); ++it) {
    //get the det ID 
    HcalDetId const& hcalDetId = it->id();

    CaloSamples fc_ts; //fc_ts[i] returns the fC in timeslice i 

    // Load adc to fC conversion
    const HcalQIECoder   *channelCoder =  conditions->getHcalCoder(hcalDetId);
    const HcalQIEShape    * shape        =   conditions->getHcalShape(channelCoder);
    // Load pedestals (in fC)
    HcalCalibrations calibrations =  conditions->getHcalCalibrations(hcalDetId);
    HcalCoderDb coder (*channelCoder, *shape); 
    //;
    coder.adc2fC ( * it, fc_ts );
    
    double sumq = 0.;

    for (int i = 0; i < it->size(); ++i) {
      HcalQIESample hcalQIESample = it->sample(i);
      l1ho_.hcalDetIdIEta.push_back(hcalDetId.ieta());
      l1ho_.hcalDetIdIPhi.push_back(hcalDetId.iphi());
      l1ho_.hcalQIESample.push_back(i);
      l1ho_.hcalQIESampleAdc.push_back(hcalQIESample.adc());
      l1ho_.hcalQIESampleDv.push_back(hcalQIESample.dv());
      l1ho_.hcalQIESampleEr.push_back(hcalQIESample.er());
      l1ho_.QIESampleFc.push_back(fc_ts[i]);
      int capid = it->sample(i).capid();
      l1ho_.QIESamplePedestal.push_back(calibrations.pedestal(capid));
      sumq += fc_ts[i] - calibrations.pedestal(capid);
      l1ho_.QIESampleFc_MPedestals.push_back(fc_ts[i] - calibrations.pedestal(capid));
      l1ho_.SampleEnergy.push_back((fc_ts[i] - calibrations.pedestal(capid))*calibrations.respcorrgain(capid));
      ++l1ho_.nHcalQIESamples;
    }
    l1ho_.sumQ = sumq;
    ++l1ho_.nHcalDetIds;
  }
}
