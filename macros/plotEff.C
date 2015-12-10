#include "RiceStyle.h"
#include "TrackCorrector3D.h"

using namespace std;

void plotEff(){
	
	TFile* file = new TFile("../histo/PbPb_eff_MC_v1.root");
	TrackCorrector3D testload("../histo/PbPb_eff_MC_v1.root");
	testload.load("HITrackCorrections");
	testload.setOption1(true);
	cout << "getWeight: " << testload.getWeight(4.0, 1.0, 50) << endl;
	cout << "d: " << testload.getWeight(4.0,1.0, 100) << endl;

}