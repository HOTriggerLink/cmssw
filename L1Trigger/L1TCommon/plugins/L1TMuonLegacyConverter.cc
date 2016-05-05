// -*- C++ -*-
//
// Package:    L1TMuonLegacyConverter
// Class:      L1TMuonLegacyConverter
// 
/**\class L1TMuonLegacyConverter \file L1TMuonLegacyConverter.cc src/L1TMuonLegacyConverter/src/L1TMuonLegacyConverter.cc
*/
//
// Original Author:  Bortignon Pierluigi
//         Created:  Sun March 6 EDT 2016
//
//


// system include files
#include <memory>

// user include files
#include "L1Trigger/L1TCommon/plugins/L1TMuonLegacyConverter.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Common/interface/OrphanHandle.h"

#include "CondFormats/L1TObjects/interface/L1CaloGeometry.h"
#include "CondFormats/DataRecord/interface/L1CaloGeometryRecord.h"

#include "CondFormats/L1TObjects/interface/L1CaloEtScale.h"
#include "CondFormats/DataRecord/interface/L1EmEtScaleRcd.h"
#include "CondFormats/DataRecord/interface/L1JetEtScaleRcd.h"
#include "CondFormats/DataRecord/interface/L1HtMissScaleRcd.h"
#include "CondFormats/DataRecord/interface/L1HfRingEtScaleRcd.h"
#include "CondFormats/L1TObjects/interface/L1GctJetFinderParams.h"
#include "CondFormats/DataRecord/interface/L1GctJetFinderParamsRcd.h"

#include "CondFormats/L1TObjects/interface/L1MuTriggerScales.h"
#include "CondFormats/DataRecord/interface/L1MuTriggerScalesRcd.h"
#include "CondFormats/L1TObjects/interface/L1MuTriggerPtScale.h"
#include "CondFormats/DataRecord/interface/L1MuTriggerPtScaleRcd.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"


// #include "FWCore/Utilities/interface/EDMException.h"

//
// class decleration
//


//
// constants, enums and typedefs
//
using namespace l1t;


//
// static data member definitions
//

double const L1TMuonLegacyConverter::muonMassGeV_ = 0.105658369 ; // PDG06

//
// constructors and destructor
//
L1TMuonLegacyConverter::L1TMuonLegacyConverter(const edm::ParameterSet& iConfig)
   // : produceMuonParticles_( iConfig.getParameter< bool >(
   //    "produceMuonParticles" ) ),
   //   muonSource_( iConfig.getParameter< edm::InputTag >(
	  // "muonSource" ) ),

// pb: commenting out all things unrelated to muons
 //     produceCaloParticles_( iConfig.getParameter< bool >(
	// "produceCaloParticles" ) ),
 //     isoEmSource_( iConfig.getParameter< edm::InputTag >(
	// "isolatedEmSource" ) ),
 //     nonIsoEmSource_( iConfig.getParameter< edm::InputTag >(
	// "nonIsolatedEmSource" ) ),
 //     cenJetSource_( iConfig.getParameter< edm::InputTag >(
	// "centralJetSource" ) ),
 //     forJetSource_( iConfig.getParameter< edm::InputTag >(
	// "forwardJetSource" ) ),
 //     tauJetSource_( iConfig.getParameter< edm::InputTag >(
	// "tauJetSource" ) ),
 //     isoTauJetSource_( iConfig.getParameter< edm::InputTag >(
	// "isoTauJetSource" ) ),
 //     etTotSource_( iConfig.getParameter< edm::InputTag >(
	// "etTotalSource" ) ),
 //     etHadSource_( iConfig.getParameter< edm::InputTag >(
	// "etHadSource" ) ),
 //     etMissSource_( iConfig.getParameter< edm::InputTag >(
	// "etMissSource" ) ),
 //     htMissSource_( iConfig.getParameter< edm::InputTag >(
	// "htMissSource" ) ),
 //     hfRingEtSumsSource_( iConfig.getParameter< edm::InputTag >(
	// "hfRingEtSumsSource" ) ),
 //     hfRingBitCountsSource_( iConfig.getParameter< edm::InputTag >(
	// "hfRingBitCountsSource" ) ),
     // centralBxOnly_( iConfig.getParameter< bool >( "centralBxOnly" ) ),
     // ignoreHtMiss_( iConfig.getParameter< bool >( "ignoreHtMiss" ) )
{
   using namespace l1extra ;

   // moving inputTag here
   muonSource_InputTag = iConfig.getParameter<edm::InputTag>("muonSource");

   //register your products
   // produces< L1EmParticleCollection >( "Isolated" ) ;
   // produces< L1EmParticleCollection >( "NonIsolated" ) ;
   // produces< L1JetParticleCollection >( "Central" ) ;
   // produces< L1JetParticleCollection >( "Forward" ) ;
   // produces< L1JetParticleCollection >( "Tau" ) ;
   // produces< L1JetParticleCollection >( "IsoTau" ) ;
   produces<MuonBxCollection>("imdMuonsLegacy");
   // produces< L1EtMissParticleCollection >( "MET" ) ;
   // produces< L1EtMissParticleCollection >( "MHT" ) ;
   // produces< L1HFRingsCollection >() ;

   //now do what ever other initialization is needed
   //moving from getByLabel to getByToken
   muonSource_InputToken = consumes<L1MuGMTReadoutCollection>(muonSource_InputTag);
//   consumes<L1MuGMTReadoutCollection>(muonSource_);
   // consumes<L1GctEmCandCollection>(isoEmSource_);
   // consumes<L1GctEmCandCollection>(nonIsoEmSource_);
   // consumes<L1GctJetCandCollection>(cenJetSource_);
   // consumes<L1GctJetCandCollection>(forJetSource_);
   // consumes<L1GctJetCandCollection>(tauJetSource_);
   // consumes<L1GctJetCandCollection>(isoTauJetSource_);
   // consumes<L1GctEtTotalCollection>(etTotSource_);
   // consumes<L1GctEtMissCollection>(etMissSource_);
   // consumes<L1GctEtHadCollection>(etHadSource_);
   // consumes<L1GctHtMissCollection>(htMissSource_);
   // consumes<L1GctHFRingEtSumsCollection>(hfRingEtSumsSource_);
   // consumes<L1GctHFBitCountsCollection>(hfRingBitCountsSource_);
}


L1TMuonLegacyConverter::~L1TMuonLegacyConverter()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
L1TMuonLegacyConverter::produce( edm::Event& iEvent,
			       const edm::EventSetup& iSetup)
{
   using namespace edm ;
   using namespace l1extra ;
   using namespace std ;

   // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   // ~~~~~~~~~~~~~~~~~~~~ Muons ~~~~~~~~~~~~~~~~~~~~
   // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   auto_ptr< MuonBxCollection > imdMuonsLegacy( new MuonBxCollection() );

   if( produceMuonParticles_ )
   {
      ESHandle< L1MuTriggerScales > muScales ;
      iSetup.get< L1MuTriggerScalesRcd >().get( muScales ) ;

      ESHandle< L1MuTriggerPtScale > muPtScale ;
      iSetup.get< L1MuTriggerPtScaleRcd >().get( muPtScale ) ;

      Handle< L1MuGMTReadoutCollection > hwMuCollection ;
      iEvent.getByToken( muonSource_InputToken, hwMuCollection ) ;

      vector< L1MuGMTExtendedCand > hwMuCands ;

      if( !hwMuCollection.isValid() )
	{
	  LogDebug("L1TMuonLegacyConverter")
	    << "\nWarning: L1MuGMTReadoutCollection with " << muonSource_InputTag
	    << "\nrequested in configuration, but not found in the event."
	    << std::endl;
	}
      else
	{
	  if( centralBxOnly_ )
	    {
	      // Get GMT candidates from central bunch crossing only
	      hwMuCands = hwMuCollection->getRecord().getGMTCands() ;
	    }
	  else
	    {
	      // Get GMT candidates from all bunch crossings
	      vector< L1MuGMTReadoutRecord > records = hwMuCollection->getRecords();
	      vector< L1MuGMTReadoutRecord >::const_iterator rItr = records.begin();
	      vector< L1MuGMTReadoutRecord >::const_iterator rEnd = records.end();

	      for( ; rItr != rEnd ; ++rItr )
		{
		  vector< L1MuGMTExtendedCand > tmpCands = rItr->getGMTCands() ;

		  hwMuCands.insert( hwMuCands.end(),
				    tmpCands.begin(),
				    tmpCands.end() ) ;
		}
	    }

//       cout << "HW muons" << endl ;
	  vector< L1MuGMTExtendedCand >::const_iterator muItr = hwMuCands.begin() ;
	  vector< L1MuGMTExtendedCand >::const_iterator muEnd = hwMuCands.end() ;
	  for( int i = 0 ; muItr != muEnd ; ++muItr, ++i )
	    {
// 	 cout << "#" << i
// 	      << " name " << muItr->name()
// 	      << " empty " << muItr->empty()
// 	      << " pt " << muItr->ptIndex()
// 	      << " eta " << muItr->etaIndex()
// 	      << " phi " << muItr->phiIndex()
// 	      << " iso " << muItr->isol()
// 	      << " mip " << muItr->mip()
// 	      << " bx " << muItr->bx()
// 	      << endl ;

	      if( !muItr->empty() ){
		  // keep x and y components non-zero and protect against roundoff.
		  double pt = muPtScale->getPtScale()->getLowEdge( muItr->ptIndex() ) + 1.e-6 ;
		  double eta = muScales->getGMTEtaScale()->getCenter( muItr->etaIndex() ) ;
		  double phi = muScales->getPhiScale()->getLowEdge( muItr->phiIndex() ) ;

		  math::PtEtaPhiMLorentzVector p4( pt,
						   eta,
						   phi,
						   muonMassGeV_ ) ;

		// from L1TMuonProducer.cc - which is the stage2 muon producer:
		// Muon outMu{vec, mu->hwPt(), mu->hwEta(), mu->hwGlobalPhi(), outMuQual, mu->hwSign(), mu->hwSignValid(), iso, mu->tfMuonIndex(), 0, true, mu->hwIsoSum(), mu->hwDPhi(), mu->hwDEta(), mu->hwRank()};

		  Muon outMu{p4, (int)muItr->ptIndex(), (int)muItr->etaIndex(), (int)muItr->phiIndex(), (int)muItr->quality(), muItr->charge(), muItr->isol(), (int)muItr->etaRegionIndex(), 0, true, 0, 0, 0 , (int)muItr->rank() };
		  imdMuonsLegacy->push_back( muItr->bx(), outMu ) ;
		}
	    }
	}
   }
   
   iEvent.put( imdMuonsLegacy, "imdMuonsLegacy" );

} // closing produce

//define this as a plug-in
DEFINE_FWK_MODULE(L1TMuonLegacyConverter);

//    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    // ~~~~~~~~~~~~~~~~~~~~ Calorimeter ~~~~~~~~~~~~~~~~~~~~
//    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//    auto_ptr< L1EmParticleCollection > isoEmColl(
//       new L1EmParticleCollection );

//    auto_ptr< L1EmParticleCollection > nonIsoEmColl(
//       new L1EmParticleCollection );

//    auto_ptr< L1JetParticleCollection > cenJetColl(
//       new L1JetParticleCollection );

//    auto_ptr< L1JetParticleCollection > forJetColl(
//       new L1JetParticleCollection );

//    auto_ptr< L1JetParticleCollection > tauJetColl(
//       new L1JetParticleCollection );

//    auto_ptr< L1JetParticleCollection > isoTauJetColl(
//       new L1JetParticleCollection );

//    auto_ptr< L1EtMissParticleCollection > etMissColl(
//       new L1EtMissParticleCollection );

//    auto_ptr< L1EtMissParticleCollection > htMissColl(
//       new L1EtMissParticleCollection );

//    auto_ptr< L1HFRingsCollection > hfRingsColl( new L1HFRingsCollection );

//    if( produceCaloParticles_ )
//    {
//       // ~~~~~~~~~~~~~~~~~~~~ Geometry ~~~~~~~~~~~~~~~~~~~~

//       ESHandle< L1CaloGeometry > caloGeomESH ;
//       iSetup.get< L1CaloGeometryRecord >().get( caloGeomESH ) ;
//       const L1CaloGeometry* caloGeom = &( *caloGeomESH ) ;

//       // ~~~~~~~~~~~~~~~~~~~~ EM ~~~~~~~~~~~~~~~~~~~~

//       ESHandle< L1CaloEtScale > emScale ;
//       iSetup.get< L1EmEtScaleRcd >().get( emScale ) ;

//       // Isolated EM
//       Handle< L1GctEmCandCollection > hwIsoEmCands ;
//       iEvent.getByLabel( isoEmSource_, hwIsoEmCands ) ;

//       if( !hwIsoEmCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEmCandCollection with " << isoEmSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// //       cout << "HW iso EM" << endl ;

// 	  L1GctEmCandCollection::const_iterator emItr = hwIsoEmCands->begin() ;
// 	  L1GctEmCandCollection::const_iterator emEnd = hwIsoEmCands->end() ;
// 	  for( int i = 0 ; emItr != emEnd ; ++emItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << emItr->name()
// // 	      << " empty " << emItr->empty()
// // 	      << " rank " << emItr->rank()
// // 	      << " eta " << emItr->etaIndex()
// // 	      << " sign " << emItr->etaSign()
// // 	      << " phi " << emItr->phiIndex()
// // 	      << " iso " << emItr->isolated()
// // 	      << " bx " << emItr->bx()
// // 	      << endl ;

// 	      if( !emItr->empty() &&
// 		  ( !centralBxOnly_ || emItr->bx() == 0 ) )
// 		{
// 		  double et = emScale->et( emItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  isoEmColl->push_back(
// 				       L1EmParticle( gctLorentzVector( et, *emItr, caloGeom, true ),
// 						     Ref< L1GctEmCandCollection >( hwIsoEmCands,
// 										   i ),
// 						     emItr->bx() ) ) ;
// 		}
// 	    }
// 	}


//       // Non-isolated EM
//       Handle< L1GctEmCandCollection > hwNonIsoEmCands ;
//       iEvent.getByLabel( nonIsoEmSource_, hwNonIsoEmCands ) ;

//       if( !hwNonIsoEmCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEmCandCollection with " << nonIsoEmSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// //       cout << "HW non-iso EM" << endl ;
// 	  L1GctEmCandCollection::const_iterator emItr = hwNonIsoEmCands->begin() ;
// 	  L1GctEmCandCollection::const_iterator emEnd = hwNonIsoEmCands->end() ;
// 	  for( int i = 0 ; emItr != emEnd ; ++emItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << emItr->name()
// // 	      << " empty " << emItr->empty()
// // 	      << " rank " << emItr->rank()
// // 	      << " eta " << emItr->etaIndex()
// // 	      << " sign " << emItr->etaSign()
// // 	      << " phi " << emItr->phiIndex()
// // 	      << " iso " << emItr->isolated()
// // 	      << " bx " << emItr->bx()
// // 	      << endl ;

// 	      if( !emItr->empty() &&
// 		  ( !centralBxOnly_ || emItr->bx() == 0 ) )
// 		{
// 		  double et = emScale->et( emItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  nonIsoEmColl->push_back(
// 					  L1EmParticle( gctLorentzVector( et, *emItr, caloGeom, true ),
// 							Ref< L1GctEmCandCollection >( hwNonIsoEmCands,
// 										      i ),
// 							emItr->bx() ) );
// 		}
// 	    }
// 	}


//       // ~~~~~~~~~~~~~~~~~~~~ Jets ~~~~~~~~~~~~~~~~~~~~

//       ESHandle< L1CaloEtScale > jetScale ;
//       iSetup.get< L1JetEtScaleRcd >().get( jetScale ) ;

//       // Central jets.
//       Handle< L1GctJetCandCollection > hwCenJetCands ;
//       iEvent.getByLabel( cenJetSource_, hwCenJetCands ) ;

//       if( !hwCenJetCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctJetCandCollection with " << cenJetSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// //       cout << "HW central jets" << endl ;
// 	  L1GctJetCandCollection::const_iterator jetItr = hwCenJetCands->begin() ;
// 	  L1GctJetCandCollection::const_iterator jetEnd = hwCenJetCands->end() ;
// 	  for( int i = 0 ; jetItr != jetEnd ; ++jetItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << jetItr->name()
// // 	      << " empty " << jetItr->empty()
// // 	      << " rank " << jetItr->rank()
// // 	      << " eta " << jetItr->etaIndex()
// // 	      << " sign " << jetItr->etaSign()
// // 	      << " phi " << jetItr->phiIndex()
// // 	      << " cen " << jetItr->isCentral()
// // 	      << " for " << jetItr->isForward()
// // 	      << " tau " << jetItr->isTau()
// // 	      << " bx " << jetItr->bx()
// // 	      << endl ;

// 	      if( !jetItr->empty() &&
// 		  ( !centralBxOnly_ || jetItr->bx() == 0 ) )
// 		{
// 		  double et = jetScale->et( jetItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  cenJetColl->push_back(
// 					L1JetParticle( gctLorentzVector( et, *jetItr, caloGeom, true ),
// 						       Ref< L1GctJetCandCollection >( hwCenJetCands,
// 										      i ),
// 						       jetItr->bx() ) ) ;
// 		}
// 	    }
// 	}


//       // Forward jets.
//       Handle< L1GctJetCandCollection > hwForJetCands ;
//       iEvent.getByLabel( forJetSource_, hwForJetCands ) ;

//       if( !hwForJetCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEmCandCollection with " << forJetSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// //       cout << "HW forward jets" << endl ;
// 	  L1GctJetCandCollection::const_iterator jetItr = hwForJetCands->begin() ;
// 	  L1GctJetCandCollection::const_iterator jetEnd = hwForJetCands->end() ;
// 	  for( int i = 0 ; jetItr != jetEnd ; ++jetItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << jetItr->name()
// // 	      << " empty " << jetItr->empty()
// // 	      << " rank " << jetItr->rank()
// // 	      << " eta " << jetItr->etaIndex()
// // 	      << " sign " << jetItr->etaSign()
// // 	      << " phi " << jetItr->phiIndex()
// // 	      << " cen " << jetItr->isCentral()
// // 	      << " for " << jetItr->isForward()
// // 	      << " tau " << jetItr->isTau()
// // 	      << " bx " << jetItr->bx()
// // 	      << endl ;

// 	      if( !jetItr->empty() &&
// 		  ( !centralBxOnly_ || jetItr->bx() == 0 ) )
// 		{
// 		  double et = jetScale->et( jetItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  forJetColl->push_back(
// 					L1JetParticle( gctLorentzVector( et, *jetItr, caloGeom, false ),
// 						       Ref< L1GctJetCandCollection >( hwForJetCands,
// 										      i ),
// 						       jetItr->bx() ) ) ;
// 		}
// 	    }
// 	}


//       // Tau jets.
// //       cout << "HW tau jets" << endl ;
//       Handle< L1GctJetCandCollection > hwTauJetCands ;
//       iEvent.getByLabel( tauJetSource_, hwTauJetCands ) ;

//       if( !hwTauJetCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctJetCandCollection with " << tauJetSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// 	  L1GctJetCandCollection::const_iterator jetItr = hwTauJetCands->begin() ;
// 	  L1GctJetCandCollection::const_iterator jetEnd = hwTauJetCands->end() ;
// 	  for( int i = 0 ; jetItr != jetEnd ; ++jetItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << jetItr->name()
// // 	      << " empty " << jetItr->empty()
// // 	      << " rank " << jetItr->rank()
// // 	      << " eta " << jetItr->etaIndex()
// // 	      << " sign " << jetItr->etaSign()
// // 	      << " phi " << jetItr->phiIndex()
// // 	      << " cen " << jetItr->isCentral()
// // 	      << " for " << jetItr->isForward()
// // 	      << " tau " << jetItr->isTau()
// // 	      << " bx " << jetItr->bx()
// // 	      << endl ;

// 	      if( !jetItr->empty() &&
// 		  ( !centralBxOnly_ || jetItr->bx() == 0 ) )
// 		{
// 		  double et = jetScale->et( jetItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  tauJetColl->push_back(
// 					L1JetParticle( gctLorentzVector( et, *jetItr, caloGeom, true ),
// 						       Ref< L1GctJetCandCollection >( hwTauJetCands,
// 										      i ),
// 						       jetItr->bx() ) ) ;
// 		}
// 	    }
// 	}


//       // Isolated Tau jets.
// //       cout << "HW tau jets" << endl ;
//       Handle< L1GctJetCandCollection > hwIsoTauJetCands ;
//       iEvent.getByLabel( isoTauJetSource_, hwIsoTauJetCands ) ;

//       if( !hwIsoTauJetCands.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctJetCandCollection with " << isoTauJetSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// 	  L1GctJetCandCollection::const_iterator jetItr = hwIsoTauJetCands->begin() ;
// 	  L1GctJetCandCollection::const_iterator jetEnd = hwIsoTauJetCands->end() ;
// 	  for( int i = 0 ; jetItr != jetEnd ; ++jetItr, ++i )
// 	    {
// // 	 cout << "#" << i
// // 	      << " name " << jetItr->name()
// // 	      << " empty " << jetItr->empty()
// // 	      << " rank " << jetItr->rank()
// // 	      << " eta " << jetItr->etaIndex()
// // 	      << " sign " << jetItr->etaSign()
// // 	      << " phi " << jetItr->phiIndex()
// // 	      << " cen " << jetItr->isCentral()
// // 	      << " for " << jetItr->isForward()
// // 	      << " tau " << jetItr->isTau()
// // 	      << " bx " << jetItr->bx()
// // 	      << endl ;

// 	      if( !jetItr->empty() &&
// 		  ( !centralBxOnly_ || jetItr->bx() == 0 ) )
// 		{
// 		  double et = jetScale->et( jetItr->rank() ) ;

// // 	    cout << "L1Extra et " << et << endl ;

// 		  isoTauJetColl->push_back(
// 					L1JetParticle( gctLorentzVector( et, *jetItr, caloGeom, true ),
// 						       Ref< L1GctJetCandCollection >( hwIsoTauJetCands,
// 										      i ),
// 						       jetItr->bx() ) ) ;
// 		}
// 	    }
// 	}

//       // ~~~~~~~~~~~~~~~~~~~~ ET Sums ~~~~~~~~~~~~~~~~~~~~

//       double etSumLSB = jetScale->linearLsb() ;

//       Handle< L1GctEtTotalCollection > hwEtTotColl ;
//       iEvent.getByLabel( etTotSource_, hwEtTotColl ) ;

//       Handle< L1GctEtMissCollection > hwEtMissColl ;
//       iEvent.getByLabel( etMissSource_, hwEtMissColl ) ;

//       if( !hwEtTotColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEtTotalCollection with " << etTotSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else if( !hwEtMissColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEtMissCollection with " << etMissSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// 	  // Make a L1EtMissParticle even if either L1GctEtTotal or L1GctEtMiss
// 	  // is missing for a given bx.  Keep track of which L1GctEtMiss objects
// 	  // have a corresponding L1GctEtTotal object.
// 	  std::vector< bool > etMissMatched ;

// 	  L1GctEtMissCollection::const_iterator hwEtMissItr =
// 	    hwEtMissColl->begin() ;
// 	  L1GctEtMissCollection::const_iterator hwEtMissEnd =
// 	    hwEtMissColl->end() ;
// 	  for( ; hwEtMissItr != hwEtMissEnd ; ++hwEtMissItr )
// 	    {
// 	      etMissMatched.push_back( false ) ;
// 	    }
      
// 	  // Collate energy sums by bx
// 	  L1GctEtTotalCollection::const_iterator hwEtTotItr =
// 	    hwEtTotColl->begin() ;
// 	  L1GctEtTotalCollection::const_iterator hwEtTotEnd =
// 	    hwEtTotColl->end() ;

// 	  int iTot = 0 ;
// 	  for( ; hwEtTotItr != hwEtTotEnd ; ++hwEtTotItr, ++iTot )
// 	    {
// 	      int bx = hwEtTotItr->bx() ;

// 	      if( !centralBxOnly_ || bx == 0 )
// 		{
// 		  // ET bin low edge
// 		  double etTot =
// 		    ( hwEtTotItr->overFlow() ?
// 		      ( double ) L1GctEtTotal::kEtTotalMaxValue :
// 		      ( double ) hwEtTotItr->et() ) * etSumLSB + 1.e-6 ;

// 		  int iMiss = 0 ;
// 		  hwEtMissItr = hwEtMissColl->begin() ;
// 		  hwEtMissEnd = hwEtMissColl->end() ;
// 		  for( ; hwEtMissItr != hwEtMissEnd ; ++hwEtMissItr, ++iMiss )
// 		    {
// 		      if( hwEtMissItr->bx() == bx )
// 			{
// 			  etMissMatched[ iMiss ] = true ;
// 			  break ;
// 			}
// 		    }

// 		  double etMiss = 0. ;
// 		  double phi = 0. ;
// 		  math::PtEtaPhiMLorentzVector p4 ;
// 		  Ref< L1GctEtMissCollection > metRef ;

// 		  // If a L1GctEtMiss with the right bx is not found, itr == end.
// 		  if( hwEtMissItr != hwEtMissEnd )
// 		    {
// 		      // ET bin low edge
// 		      etMiss =
// 			( hwEtMissItr->overFlow() ?
// 			  ( double ) L1GctEtMiss::kEtMissMaxValue :
// 			  ( double ) hwEtMissItr->et() ) * etSumLSB + 1.e-6 ;
// 		      // keep x and y components non-zero and
// 		      // protect against roundoff.

// 		      phi = caloGeom->etSumPhiBinCenter( hwEtMissItr->phi() ) ;

// 		      p4 = math::PtEtaPhiMLorentzVector( etMiss,
// 							 0.,
// 							 phi,
// 							 0. ) ;

// 		      metRef = Ref< L1GctEtMissCollection >( hwEtMissColl, iMiss ) ;

// // 	       cout << "HW ET Sums " << endl
// // 		    << "MET: phi " << hwEtMissItr->phi() << " = " << phi
// // 		    << " et " << hwEtMissItr->et() << " = " << etMiss
// // 		    << " EtTot " << hwEtTotItr->et() << " = " << etTot
// // 		    << " bx " << bx
// // 		    << endl ;
// 		    }
// // 	   else
// // 	     {
// // 	       cout << "HW ET Sums " << endl
// // 		    << "MET: phi " << phi
// // 		    << " et "<< etMiss
// // 		    << " EtTot " << hwEtTotItr->et() << " = " << etTot
// // 		    << " bx " << bx
// // 		    << endl ;
// // 	     }

// 		  etMissColl->push_back(
// 					L1EtMissParticle(
// 							 p4,
// 							 L1EtMissParticle::kMET,
// 							 etTot,
// 							 metRef,
// 							 Ref< L1GctEtTotalCollection >( hwEtTotColl, iTot ),
// 							 Ref< L1GctHtMissCollection >(),
// 							 Ref< L1GctEtHadCollection >(),
// 							 bx
// 							 ) ) ;
// 		}
// 	    }

// 	  if( !centralBxOnly_ )
// 	    {
// 	      // Make L1EtMissParticles for those L1GctEtMiss objects without
// 	      // a matched L1GctEtTotal object.

// 	      double etTot = 0. ;

// 	      hwEtMissItr = hwEtMissColl->begin() ;
// 	      hwEtMissEnd = hwEtMissColl->end() ;
// 	      int iMiss = 0 ;
// 	      for( ; hwEtMissItr != hwEtMissEnd ; ++hwEtMissItr, ++iMiss )
// 		{
// 		  if( !etMissMatched[ iMiss ] )
// 		    {
// 		      int bx = hwEtMissItr->bx() ;

// 		      // ET bin low edge
// 		      double etMiss =
// 			( hwEtMissItr->overFlow() ?
// 			  ( double ) L1GctEtMiss::kEtMissMaxValue :
// 			  ( double ) hwEtMissItr->et() ) * etSumLSB + 1.e-6 ;
// 		      // keep x and y components non-zero and
// 		      // protect against roundoff.

// 		      double phi =
// 			caloGeom->etSumPhiBinCenter( hwEtMissItr->phi() ) ;

// 		      math::PtEtaPhiMLorentzVector p4( etMiss,
// 						       0.,
// 						       phi,
// 						       0. ) ;

// // 		  cout << "HW ET Sums " << endl
// // 		       << "MET: phi " << hwEtMissItr->phi() << " = " << phi
// // 		       << " et " << hwEtMissItr->et() << " = " << etMiss
// // 		       << " EtTot " << etTot
// // 		       << " bx " << bx
// // 		       << endl ;

// 		      etMissColl->push_back(
// 					    L1EtMissParticle(
// 							     p4,
// 							     L1EtMissParticle::kMET,
// 							     etTot,
// 							     Ref< L1GctEtMissCollection >( hwEtMissColl, iMiss ),
// 							     Ref< L1GctEtTotalCollection >(),
// 							     Ref< L1GctHtMissCollection >(),
// 							     Ref< L1GctEtHadCollection >(),
// 							     bx
// 							     ) ) ;
// 		    }
// 		}
// 	    }
// 	}

//       // ~~~~~~~~~~~~~~~~~~~~ HT Sums ~~~~~~~~~~~~~~~~~~~~

//       Handle< L1GctEtHadCollection > hwEtHadColl ;
//       iEvent.getByLabel( etHadSource_, hwEtHadColl ) ;

//       Handle< L1GctHtMissCollection > hwHtMissColl ;
//       if( !ignoreHtMiss_ )
// 	{
// 	  iEvent.getByLabel( htMissSource_, hwHtMissColl ) ;
// 	}

//       ESHandle< L1GctJetFinderParams > jetFinderParams ;
//       iSetup.get< L1GctJetFinderParamsRcd >().get( jetFinderParams ) ;
//       double htSumLSB = jetFinderParams->getHtLsbGeV();

//       ESHandle< L1CaloEtScale > htMissScale ;
//       std::vector< bool > htMissMatched ;
//       if( !ignoreHtMiss_ )
// 	{
// 	  iSetup.get< L1HtMissScaleRcd >().get( htMissScale ) ;

// 	  if( !hwEtHadColl.isValid() )
// 	    {
// 	      LogDebug("L1TMuonLegacyConverter")
// 		<< "\nWarning: L1GctEtHadCollection with " << etHadSource_
// 		<< "\nrequested in configuration, but not found in the event."
// 		<< std::endl;
// 	    }
// 	  else if( !hwHtMissColl.isValid() )
// 	    {
// 	      LogDebug("L1TMuonLegacyConverter")
// 		<< "\nWarning: L1GctHtMissCollection with " << htMissSource_
// 		<< "\nrequested in configuration, but not found in the event."
// 		<< std::endl;
// 	    }
// 	  else
// 	    {
// 	      // Make a L1EtMissParticle even if either L1GctEtHad or L1GctHtMiss
// 	      // is missing for a given bx. Keep track of which L1GctHtMiss objects
// 	      // have a corresponding L1GctHtTotal object.
// 	      L1GctHtMissCollection::const_iterator hwHtMissItr =
// 		hwHtMissColl->begin() ;
// 	      L1GctHtMissCollection::const_iterator hwHtMissEnd =
// 		hwHtMissColl->end() ;
// 	      for( ; hwHtMissItr != hwHtMissEnd ; ++hwHtMissItr )
// 		{
// 		  htMissMatched.push_back( false ) ;
// 		}
// 	    }
// 	}

//       if( !hwEtHadColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctEtHadCollection with " << etHadSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else if( !hwHtMissColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctHtMissCollection with " << htMissSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// 	  L1GctEtHadCollection::const_iterator hwEtHadItr =
// 	    hwEtHadColl->begin() ;
// 	  L1GctEtHadCollection::const_iterator hwEtHadEnd =
// 	    hwEtHadColl->end() ;

// 	  int iHad = 0 ;
// 	  for( ; hwEtHadItr != hwEtHadEnd ; ++hwEtHadItr, ++iHad )
// 	    {
// 	      int bx = hwEtHadItr->bx() ;

// 	      if( !centralBxOnly_ || bx == 0 )
// 		{
// 		  // HT bin low edge
// 		  double htTot =
// 		    ( hwEtHadItr->overFlow() ?
// 		      ( double ) L1GctEtHad::kEtHadMaxValue :
// 		      ( double ) hwEtHadItr->et() ) * htSumLSB + 1.e-6 ;

// 		  double htMiss = 0. ;
// 		  double phi = 0. ;
// 		  math::PtEtaPhiMLorentzVector p4 ;
// 		  Ref< L1GctHtMissCollection > mhtRef ;

// 		  if( !ignoreHtMiss_ )
// 		    {
// 		      L1GctHtMissCollection::const_iterator hwHtMissItr =
// 			hwHtMissColl->begin() ;
// 		      L1GctHtMissCollection::const_iterator hwHtMissEnd =
// 			hwHtMissColl->end() ;

// 		      int iMiss = 0 ;
// 		      for( ; hwHtMissItr != hwHtMissEnd ; ++hwHtMissItr, ++iMiss )
// 			{
// 			  if( hwHtMissItr->bx() == bx )
// 			    {
// 			      htMissMatched[ iMiss ] = true ;
// 			      break ;
// 			    }
// 			}

// 		      // If a L1GctHtMiss with the right bx is not found, itr == end.
// 		      if( hwHtMissItr != hwHtMissEnd )
// 			{
// 			  // HT bin low edge
// 			  htMiss =
// 			    htMissScale->et( hwHtMissItr->overFlow() ?
// 					     htMissScale->rankScaleMax() :
// 					     hwHtMissItr->et() ) + 1.e-6 ;
// 			  // keep x and y components non-zero and
// 			  // protect against roundoff.

// 			  phi =
// 			    caloGeom->htSumPhiBinCenter( hwHtMissItr->phi() ) ;

// 			  p4 = math::PtEtaPhiMLorentzVector( htMiss,
// 							     0.,
// 							     phi,
// 							     0. ) ;

// 			  mhtRef=Ref< L1GctHtMissCollection >( hwHtMissColl, iMiss );

// // 		   cout << "HW HT Sums " << endl
// // 			<< "MHT: phi " << hwHtMissItr->phi() << " = " << phi
// // 			<< " ht " << hwHtMissItr->et() << " = " << htMiss
// // 			<< " HtTot " << hwEtHadItr->et() << " = " << htTot
// // 			<< " bx " << bx
// // 			<< endl ;
// 			}
// // 	       else
// // 		 {
// // 		   cout << "HW HT Sums " << endl
// // 			<< "MHT: phi " << phi
// // 			<< " ht " << htMiss
// // 			<< " HtTot " << hwEtHadItr->et() << " = " << htTot
// // 			<< " bx " << bx
// // 			<< endl ;
// // 		 }
// 		    }

// 		  htMissColl->push_back(
// 					L1EtMissParticle(
// 							 p4,
// 							 L1EtMissParticle::kMHT,
// 							 htTot,
// 							 Ref< L1GctEtMissCollection >(),
// 							 Ref< L1GctEtTotalCollection >(),
// 							 mhtRef,
// 							 Ref< L1GctEtHadCollection >( hwEtHadColl, iHad ),
// 							 bx
// 							 ) ) ;
// 		}
// 	    }

// 	  if( !centralBxOnly_  && !ignoreHtMiss_ )
// 	    {
// 	      // Make L1EtMissParticles for those L1GctHtMiss objects without
// 	      // a matched L1GctHtTotal object.
// 	      double htTot = 0. ;

// 	      L1GctHtMissCollection::const_iterator hwHtMissItr =
// 		hwHtMissColl->begin() ;
// 	      L1GctHtMissCollection::const_iterator hwHtMissEnd =
// 		hwHtMissColl->end() ;

// 	      int iMiss = 0 ;
// 	      for( ; hwHtMissItr != hwHtMissEnd ; ++hwHtMissItr, ++iMiss )
// 		{
// 		  if( !htMissMatched[ iMiss ] )
// 		    {
// 		      int bx = hwHtMissItr->bx() ;

// 		      // HT bin low edge
// 		      double htMiss =
// 			htMissScale->et( hwHtMissItr->overFlow() ?
// 					 htMissScale->rankScaleMax() :
// 					 hwHtMissItr->et() ) + 1.e-6 ;
// 		      // keep x and y components non-zero and
// 		      // protect against roundoff.

// 		      double phi =
// 			caloGeom->htSumPhiBinCenter( hwHtMissItr->phi() ) ;

// 		      math::PtEtaPhiMLorentzVector p4( htMiss,
// 						       0.,
// 						       phi,
// 						       0. ) ;

// // 		  cout << "HW HT Sums " << endl
// // 		       << "MHT: phi " << hwHtMissItr->phi() << " = " << phi
// // 		       << " ht " << hwHtMissItr->et() << " = " << htMiss
// // 		       << " HtTot " << htTot
// // 		       << " bx " << bx
// // 		       << endl ;

// 		      htMissColl->push_back(
// 					    L1EtMissParticle(
// 							     p4,
// 							     L1EtMissParticle::kMHT,
// 							     htTot,
// 							     Ref< L1GctEtMissCollection >(),
// 							     Ref< L1GctEtTotalCollection >(),
// 							     Ref< L1GctHtMissCollection >( hwHtMissColl, iMiss ),
// 							     Ref< L1GctEtHadCollection >(),
// 							     bx
// 							     ) ) ;
// 		    }
// 		}
// 	    }
// 	}

//       // ~~~~~~~~~~~~~~~~~~~~ HF Rings ~~~~~~~~~~~~~~~~~~~~

//       Handle< L1GctHFRingEtSumsCollection > hwHFEtSumsColl ;
//       iEvent.getByLabel( hfRingEtSumsSource_, hwHFEtSumsColl ) ;

//       Handle< L1GctHFBitCountsCollection > hwHFBitCountsColl ;
//       iEvent.getByLabel( hfRingBitCountsSource_, hwHFBitCountsColl ) ;

//       ESHandle< L1CaloEtScale > hfRingEtScale ;
//       iSetup.get< L1HfRingEtScaleRcd >().get( hfRingEtScale ) ;

//       if( !hwHFEtSumsColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctHFRingEtSumsCollection with " << hfRingEtSumsSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else if( !hwHFBitCountsColl.isValid() )
// 	{
// 	  LogDebug("L1TMuonLegacyConverter")
// 	    << "\nWarning: L1GctHFBitCountsCollection with " << hfRingBitCountsSource_
// 	    << "\nrequested in configuration, but not found in the event."
// 	    << std::endl;
// 	}
//       else
// 	{
// 	  L1GctHFRingEtSumsCollection::const_iterator hwHFEtSumsItr =
// 	    hwHFEtSumsColl->begin() ;
// 	  L1GctHFRingEtSumsCollection::const_iterator hwHFEtSumsEnd =
// 	    hwHFEtSumsColl->end() ;

// 	  int iEtSums = 0 ;
// 	  for( ; hwHFEtSumsItr != hwHFEtSumsEnd ; ++hwHFEtSumsItr, ++iEtSums )
// 	    {
// 	      int bx = hwHFEtSumsItr->bx() ;

// 	      if( !centralBxOnly_ || bx == 0 )
// 		{
// 		  L1GctHFBitCountsCollection::const_iterator hwHFBitCountsItr =
// 		    hwHFBitCountsColl->begin() ;
// 		  L1GctHFBitCountsCollection::const_iterator hwHFBitCountsEnd =
// 		    hwHFBitCountsColl->end() ;

// 		  int iBitCounts = 0 ;
// 		  for( ; hwHFBitCountsItr != hwHFBitCountsEnd ;
// 		       ++hwHFBitCountsItr, ++iBitCounts )
// 		    {
// 		      if( hwHFBitCountsItr->bx() == bx )
// 			{
// 			  break ;
// 			}
// 		    }

// 		  // If a L1GctHFBitCounts with the right bx is not found, itr == end.
// 		  if( hwHFBitCountsItr != hwHFBitCountsEnd )
// 		    {
// 		      // Construct L1HFRings only if both HW objects are present.

// 		      // cout << "HF Rings " << endl

// 		      // HF Et sums
// 		      double etSums[ L1HFRings::kNumRings ] ;
// 		      etSums[ L1HFRings::kRing1PosEta ] =
// 			hfRingEtScale->et( hwHFEtSumsItr->etSum( 0 ) ) + 1.e-6 ;
// 		      etSums[ L1HFRings::kRing1NegEta ] =
// 			hfRingEtScale->et( hwHFEtSumsItr->etSum( 1 ) ) + 1.e-6 ;
// 		      etSums[ L1HFRings::kRing2PosEta ] =
// 			hfRingEtScale->et( hwHFEtSumsItr->etSum( 2 ) ) + 1.e-6 ;
// 		      etSums[ L1HFRings::kRing2NegEta ] =
// 			hfRingEtScale->et( hwHFEtSumsItr->etSum( 3 ) ) + 1.e-6 ;
// 		      // protect against roundoff.

// // 	       cout << "HF Et Sums "
// // 		    << hwHFEtSumsItr->etSum( 0 ) << " = "
// // 		    << etSums[ L1HFRings::kRing1PosEta ] << " "
// // 		    << hwHFEtSumsItr->etSum( 1 ) << " = "
// // 		    << etSums[ L1HFRings::kRing1NegEta ] << " "
// // 		    << hwHFEtSumsItr->etSum( 2 ) << " = "
// // 		    << etSums[ L1HFRings::kRing2PosEta ] << " "
// // 		    << hwHFEtSumsItr->etSum( 3 ) << " = "
// // 		    << etSums[ L1HFRings::kRing2NegEta ]
// // 		    << endl ;

// 		      // HF bit counts
// 		      int bitCounts[ L1HFRings::kNumRings ] ;
// 		      bitCounts[ L1HFRings::kRing1PosEta ] =
// 			hwHFBitCountsItr->bitCount( 0 ) ;
// 		      bitCounts[ L1HFRings::kRing1NegEta ] =
// 			hwHFBitCountsItr->bitCount( 1 ) ;
// 		      bitCounts[ L1HFRings::kRing2PosEta ] =
// 			hwHFBitCountsItr->bitCount( 2 ) ;
// 		      bitCounts[ L1HFRings::kRing2NegEta ] =
// 			hwHFBitCountsItr->bitCount( 3 ) ;

// // 	       cout << "HF bit counts "
// // 		    << hwHFBitCountsItr->bitCount( 0 ) << " "
// // 		    << hwHFBitCountsItr->bitCount( 1 ) << " "
// // 		    << hwHFBitCountsItr->bitCount( 2 ) << " "
// // 		    << hwHFBitCountsItr->bitCount( 3 ) << " "
// // 		    << endl ;

// 		      hfRingsColl->push_back(
// 					     L1HFRings( etSums,
// 							bitCounts,
// 							Ref< L1GctHFRingEtSumsCollection >( hwHFEtSumsColl,
// 											    iEtSums ),
// 							Ref< L1GctHFBitCountsCollection >( hwHFBitCountsColl,
// 											   iBitCounts ),
// 							bx
// 							) ) ;
// 		    }
// 		}
// 	    }
// 	}
//    }

//    OrphanHandle< L1EmParticleCollection > isoEmHandle =
//      iEvent.put( isoEmColl, "Isolated" ) ;

//    OrphanHandle< L1EmParticleCollection > nonIsoEmHandle =
//      iEvent.put( nonIsoEmColl, "NonIsolated" ) ;

//    OrphanHandle< L1JetParticleCollection > cenJetHandle =
//      iEvent.put( cenJetColl, "Central" ) ;

//    OrphanHandle< L1JetParticleCollection > forJetHandle =
//      iEvent.put( forJetColl, "Forward" ) ;

//    OrphanHandle< L1JetParticleCollection > tauJetHandle =
//      iEvent.put( tauJetColl, "Tau" ) ;

//    OrphanHandle< L1JetParticleCollection > IsoTauJetHandle =
//      iEvent.put( isoTauJetColl, "IsoTau" ) ;

//    OrphanHandle< L1EtMissParticleCollection > etMissCollHandle =
//      iEvent.put( etMissColl, "MET" ) ;

//    OrphanHandle< L1EtMissParticleCollection > htMissCollHandle =
//      iEvent.put( htMissColl, "MHT" ) ;

//    OrphanHandle< L1HFRingsCollection > hfRingsCollHandle =
//      iEvent.put( hfRingsColl ) ;
// }

// //math::XYZTLorentzVector
// math::PtEtaPhiMLorentzVector
// L1TMuonLegacyConverter::gctLorentzVector( const double& et,
// 					const L1GctCand& cand,
// 					const L1CaloGeometry* geom,
// 					bool central )
// {
//    // To keep x and y components non-zero.
//    double etCorr = et + 1.e-6 ; // protect against roundoff, not only for et=0

//    double eta = geom->etaBinCenter( cand.etaIndex(), central ) ;

// //    double tanThOver2 = exp( -eta ) ;
// //    double ez = etCorr * ( 1. - tanThOver2 * tanThOver2 ) / ( 2. * tanThOver2 );
// //    double e  = etCorr * ( 1. + tanThOver2 * tanThOver2 ) / ( 2. * tanThOver2 );

//    double phi = geom->emJetPhiBinCenter( cand.phiIndex() ) ;

// //    return math::XYZTLorentzVector( etCorr * cos( phi ),
// // 				   etCorr * sin( phi ),
// // 				   ez,
// // 				   e ) ;
//    return math::PtEtaPhiMLorentzVector( etCorr,
// 					eta,
// 					phi,
// 					0. ) ;
// }     


