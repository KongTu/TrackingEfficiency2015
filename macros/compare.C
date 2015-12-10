void compare()
{
//  TFile* f = new TFile("trkEff_highPurity_v4.root");
//  TFile* f1 = new TFile("trkEff_splitting_jet70trk15_highPurity_v4.root");
   TFile* f = new TFile("trkEff_highPurity_v6_pthat220.root");
//  TFile* f1 = new TFile("trkEff_splitting_jet50trk10_mixtriplet_highPurity_v5.root");

//  TFile* f = new TFile("trkEff_splitting_jet50trk10_mixtriplet_highPurity_v5_pthat220.root");
  TFile* f1 = new TFile("trkEff_splitting_jet100trk10_mixtriplet_highPurity_v6_pthat220.root");

  TGraphAsymmErrors* gr_eff = (TGraphAsymmErrors*)f->Get("gEffPt");
  TGraphAsymmErrors* gr_fak = (TGraphAsymmErrors*)f->Get("gFakPt");
 
  TGraphAsymmErrors* gr1_eff = (TGraphAsymmErrors*)f1->Get("gEffPt");
  TGraphAsymmErrors* gr1_fak = (TGraphAsymmErrors*)f1->Get("gFakPt");

  gr_eff->SetMarkerStyle(20);
  gr_eff->SetLineColor(4);
  gr_eff->SetMarkerColor(2);
  gr_fak->SetMarkerStyle(20);
  gr_fak->SetLineColor(4);
  gr_fak->SetMarkerColor(2);
  gr1_eff->SetMarkerStyle(24);
  gr1_eff->SetLineColor(4);
  gr1_eff->SetMarkerColor(4);
  gr1_fak->SetMarkerStyle(24);
  gr1_fak->SetLineColor(4);
  gr1_fak->SetMarkerColor(4);

  TH1D* hDumPt = new TH1D("hDumPt",";p_{T} [GeV/c]",80,1,300.0); hDumPt->SetMaximum(1.0);
  hDumPt->GetXaxis()->CenterTitle(); hDumPt->GetYaxis()->SetTitleOffset(1.8);

  TCanvas* c = new TCanvas("c","c",850,400);
  c->Divide(2,1);
  c->cd(1);
  c->GetPad(1)->SetLogx();
  hDumPt->Draw();
  gr_eff->Draw("PESAME");
  gr1_eff->Draw("PESAME");
  c->cd(2);
  c->GetPad(2)->SetLogx();
  c->GetPad(2)->SetLogy();
  hDumPt->Draw();
  gr_fak->Draw("PESAME");
  gr1_fak->Draw("PESAME");
}
