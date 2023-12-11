#include <iostream>
#include <string>
#include "Hayvan.h"

using namespace std;

string Hayvan::getAd() const { // get fonksiyonlari ile istenilen degiskenler dondurulur.
	return ad;

}

string Hayvan::getTur() const {
	return tur;

}

int Hayvan::getYas() const {
	return yas;

}

bool Hayvan::getBeslendi() const {
	return Beslendi;
}

void Hayvan::setAd(const string& yeniAd) { // set fonksiyonlari ile degiskene, parametredeki yeni deger atanir.
	ad = yeniAd;

}

void Hayvan::setTur(const string& yeniTur) {
	tur = yeniTur;

}

void Hayvan::setYas(const int& yeniYas) {
	yas = yeniYas;

}

void Hayvan::setBeslendi() {
	Beslendi = true;
}

void Hayvan::Besle() {

	cout << "\n//" << getAd() << " adli hayvan yemek yedi.//\n";
	setBeslendi(); // Besle() islemi gerceklestiginde setBeslendi() ile Beslendi true degeri alir. 

}