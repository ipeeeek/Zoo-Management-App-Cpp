#pragma once
#include <string>
#include <vector>
#include "Aslan.h"
#include "Hayvan.h"
#include "Kartal.h"
#include "Zebra.h"

using namespace std;

class HayvanatBahcesi {

private:
	vector <Aslan*> aslanlar; // Her turu kendi icinde saklamak icin, her tur icin ayri vektor olusturuldu.
	vector <Kartal*> kartallar;
	vector <Zebra*> zebralar;
	vector <Hayvan*> hayvanlar; // Tum hayvanlarin saklandigi hayvanlar adli vektor olusturuldu.


public: // HayvanatBahcesi fonksiyonlari.
	void HayvanEkle(const string& ad, const string& tur, const int& yas);
	void HayvanAdGuncelle();
	void HayvanTurGuncelle();
	void HayvanYasGuncelle();
	void HayvanlariGoster();
	void HarmonikYasOrtala();
	void AritmetikYasOrtala();
	void HayvanBesle();

};