#pragma once
#include <string>
using namespace std;

class Hayvan { // Abstarct sinif olan hayvan sinifi deklare edildi.

private: // Hayvan bilgileri private da saklanir.
	string ad;
	string tur;
	int yas;
	bool Beslendi = false;

public: // Bilgilere erisim get ve set fonksiyonlari ile saglanir.
	string getAd() const;
	string getTur() const;
	int getYas() const;
	bool getBeslendi() const;

	void setAd(const string& yeniAd);
	void setTur(const string& yeniTur);
	void setYas(const int& yeniYas);
	void setBeslendi();
	virtual void Besle();

};