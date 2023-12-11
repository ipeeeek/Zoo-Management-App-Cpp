#include <iostream>
#include <algorithm>
#include <string>
#include "Aslan.h"
#include "Hayvan.h"
#include "HayvanatBahcesi.h"
#include "Kartal.h"
#include "Zebra.h"
using namespace std;


// Hayvan ekleme fonksiyonu:
// Alinan inputlar (ad, tur, yas) dan hayvanin turu belirlenir.
// Ture gore ayri vektorlerde siniflandirilirlar.
// Her eklenen hayvan ayni zamanda hayvanlar vektorune de eklenir.

void HayvanatBahcesi::HayvanEkle(const string& ad, const string& tur, const int& yas) {

	if (tur == "aslan") {
		Aslan* yeniAslan = new Aslan();
		yeniAslan->setAd(ad);
		yeniAslan->setTur(tur);
		yeniAslan->setYas(yas);
		aslanlar.push_back(yeniAslan);
		hayvanlar.push_back(yeniAslan);
	}

	if (tur == "kartal") {
		Kartal* yeniKartal = new Kartal();
		yeniKartal->setAd(ad);
		yeniKartal->setTur(tur);
		yeniKartal->setYas(yas);
		kartallar.push_back(yeniKartal);
		hayvanlar.push_back(yeniKartal);
	}

	if (tur == "zebra") {
		Zebra* yeniZebra = new Zebra();
		yeniZebra->setAd(ad);
		yeniZebra->setTur(tur);
		yeniZebra->setYas(yas);
		zebralar.push_back(yeniZebra);
		hayvanlar.push_back(yeniZebra);
	}

}

// Hayvan ad, tur, yas guncelleme fonksiyonlari:
// Calisma prensipleri aynidir, fonksiyonlarda donen degiskenler farklilik gosterir.
// Input alinir, degiskenlerde saklanir. 
// Inputlarin, hayvanlar vektorunde var olup olmadigi kontrol edilir.
// Var ise hayvanBulundu true degerini alir, ardindan kullanicidan istenen yeni degerler degiskende saklanir.
// Yok ise hayvanBulundu false degerini korur ve hayvanin bulunamadigina dair hata verir.


void HayvanatBahcesi::HayvanAdGuncelle() {

	string eskiAd, yeniAd;
	string eskiTur, yeniTur;
	int eskiYas, yeniYas;

	cout << "\nBilgilerinin duzenlenmesini istediginiz hayvanin sirasiyla adini, turunu ve yasini giriniz: ";
	cin >> eskiAd >> eskiTur >> eskiYas;

	bool hayvanBulundu = false;
	for (Hayvan* hayvan : hayvanlar) {

		if (hayvan->getAd() == eskiAd && hayvan->getTur() == eskiTur && hayvan->getYas() == eskiYas) {

			hayvanBulundu = true;

			cout << "\nYeni adi giriniz: ";
			cin >> yeniAd;

			for (char& c : yeniAd) {
				c = tolower(c);
			}

			if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.

				cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			hayvan->setAd(yeniAd);

			cout << "\n" << eskiAd << "ismi" << yeniAd << " olarak guncellestirildi.\n";
		}

	}
	if (!hayvanBulundu) {

		cout << "\n//Bilgilerini girdiginiz hayvan bulunamadi.\n";
	}


}

void HayvanatBahcesi::HayvanTurGuncelle() {

	string eskiAd, yeniAd;
	string eskiTur, yeniTur;
	int eskiYas, yeniYas;

	cout << "\nBilgilerinin duzenlenmesini istediginiz hayvanin sirasiyla adini, turunu ve yasini giriniz: ";
	cin >> eskiAd >> eskiTur >> eskiYas;

	bool hayvanBulundu = false;
	for (Hayvan* hayvan : hayvanlar) {

		if (hayvan->getAd() == eskiAd && hayvan->getTur() == eskiTur && hayvan->getYas() == eskiYas) {

			hayvanBulundu = true;

			cout << "\nYeni tur ismini giriniz: ";
			cin >> yeniTur;

			for (char& c : yeniTur) {
				c = tolower(c);
			}

			if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.
				cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			hayvan->setTur(yeniTur);

			cout << "\n" << eskiTur << "tur ismi" << yeniTur << " olarak guncellestirildi.\n";
		}

	}
	if (!hayvanBulundu) {

		cout << "\n//Bilgilerini girdiginiz hayvan bulunamadi.";
	}


}

void HayvanatBahcesi::HayvanYasGuncelle() {

	string eskiAd, yeniAd;
	string eskiTur, yeniTur;
	int eskiYas, yeniYas;

	cout << "\nBilgilerinin duzenlenmesini istediginiz hayvanin sirasiyla adini, turunu ve yasini giriniz: ";
	cin >> eskiAd >> eskiTur >> eskiYas;

	bool hayvanBulundu = false;
	for (Hayvan* hayvan : hayvanlar) {

		if (hayvan->getAd() == eskiAd && hayvan->getTur() == eskiTur && hayvan->getYas() == eskiYas) {

			hayvanBulundu = true;

			cout << "\nYeni yasi giriniz: ";
			cin >> yeniYas;

			if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.
				cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}

			hayvan->setYas(yeniYas);

			cout << "\n" << eskiYas << "yas" << yeniYas << " olarak guncellestirildi.";

		}

	}
	if (!hayvanBulundu) {

		cout << "\n//Bilgilerini girdiginiz hayvan bulunamadi.\n";
	}



}

// HayvanlariGoster() fonksiyonu icerisindeki sort() algoritmasi icin her tur kendi arasinda kiyaslanir.
// Biri digerinden kucukse true doner.

bool aslanSirala(const Aslan* aslan1, const Aslan* aslan2) {
	return aslan1->getYas() < aslan2->getYas();
}

bool kartalSirala(const Kartal* kartal1, const Kartal* kartal2) {
	return kartal1->getYas() < kartal2->getYas();
}

bool zebraSirala(const Zebra* zebra1, const Zebra* zebra2) {
	return zebra1->getYas() < zebra2->getYas();
}


// HayvanlariGoster():
// Hayvanlari, her tur kendi icersisinde kucukten buyuge olacak sekilde siralar.
// Siralama icin, STL icinde bulunan algorithm header dosyasindaki sort algoritmasi kullanilmistir.


void HayvanatBahcesi::HayvanlariGoster() {

	// Turler kendi aralarinda siralanir.

	sort(aslanlar.begin(), aslanlar.end(), aslanSirala);

	sort(kartallar.begin(), kartallar.end(), kartalSirala);

	sort(zebralar.begin(), zebralar.end(), zebraSirala);


	for (Aslan* hayvan : aslanlar) { // sort() ile siralanmis aslanlar vektorundeki her aslanin bilgileri yazdirilir.

		cout << "\nAd: " << hayvan->getAd() << "\n";
		cout << "\nTur: " << hayvan->getTur() << "\n";
		cout << "\nYas: " << hayvan->getYas() << "\n";

		if (hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: ";
			hayvan->Besle();
		}
		else if (!hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: " << "Hayvan beslenmedi.\n";
		}

		cout << "\n";
	}

	for (Kartal* hayvan : kartallar) {// sort() ile siralanmis kartallar vektorundeki her aslanin bilgileri yazdirilir.

		cout << "\nAd: " << hayvan->getAd() << "\n";
		cout << "\nTur: " << hayvan->getTur() << "\n";
		cout << "\nYas: " << hayvan->getYas() << "\n";

		if (hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: ";
			hayvan->Besle();
		}
		else if (!hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: " << "Hayvan beslenmedi.\n";
		}

		cout << "\n";
	}

	for (Zebra* hayvan : zebralar) { // sort() ile siralanmis zebralar vektorundeki her aslanin bilgileri yazdirilir.

		cout << "\nAd: " << hayvan->getAd() << "\n";
		cout << "\nTur: " << hayvan->getTur() << "\n";
		cout << "\nYas: " << hayvan->getYas() << "\n";

		if (hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: ";
			hayvan->Besle();
		}
		else if (!hayvan->getBeslendi()) {
			cout << "\nBeslenme durumu: " << "Hayvan beslenmedi.\n";
		}

		cout << "\n";

	}

}


// Turlerin kendi aralarinda harmonik yas ortalamalai hesaplanir.

void HayvanatBahcesi::HarmonikYasOrtala() {

	double aslanToplamYas = 0.0;
	double kartalToplamYas = 0.0;
	double zebraToplamYas = 0.0;

	double aslanHarmonik = 0.0;
	double kartalHarmonik = 0.0;
	double zebraHarmonik = 0.0;

	for (Aslan* aslan : aslanlar) { // Aslanlar vektorundeki her aslanin yasi for dongusu ile toplanir. (Bu islem her tur icin aynidir.)

		aslanToplamYas += 1.0 / aslan->getYas();

	}

	if (aslanlar.size() == 0) {
		cout << "\n\nAslanlarin Harmonik Yas Ortalamasi: Veri Girilmedi"; // Menuden hic aslan verisi eklenmedi ise uyari verilir. (Bu islem her tur icin aynidir.)
	}
	else {

		aslanHarmonik = aslanlar.size() / aslanToplamYas;
		cout << "\nAslanlarin Harmonik Yas Ortalamasi: " << aslanHarmonik; // Veri girildi ise harmonik ortalama, vektordeki eleman sayisinin, toplam yasa bolunmesi ile bulunur ve bulunan deger yazdirilir. (Bu islem her tur icin aynidir.)
	}


	for (Kartal* kartal : kartallar) {

		kartalToplamYas += 1.0 / kartal->getYas();

	}
	if (kartallar.size() == 0) {
		cout << "\nKartallarin Harmonik Yas Ortalamasi: Veri Girilmedi";
	}
	else {

		kartalHarmonik = kartallar.size() / kartalToplamYas;
		cout << "\nKartallarin Harmonik Ortalamasi: " << kartalHarmonik;
	}


	for (Zebra* zebra : zebralar) {

		zebraToplamYas += 1.0 / zebra->getYas();

	}
	if (zebralar.size() == 0) {
		cout << "\nZebralarin Harmonik Yas Ortalamasi: Veri Girilmedi";
	}
	else {

		zebraHarmonik = zebralar.size() / zebraToplamYas;
		cout << "\nZebralarin Harmonik Ortalamasi: " << zebraHarmonik;
	}



}

// Turlerin kendi aralarinda aritmetik yas ortalamalai hesaplanir.

void HayvanatBahcesi::AritmetikYasOrtala() {
	double aslanToplamYas = 0.0;
	double kartalToplamYas = 0.0;
	double zebraToplamYas = 0.0;

	double aslanAritmetik = 0.0;
	double kartalAritmetik = 0.0;
	double zebraAritmetik = 0.0;

	for (Aslan* aslan : aslanlar) { // Aslanlar vektorundeki her aslanin yasi for dongusu ile toplanir, toplanan deger vektordeki eleman sayisina bolunur. (Bu islem her tur icin aynidir.)


		aslanToplamYas += aslan->getYas();
		aslanAritmetik = aslanToplamYas / aslanlar.size();
	}
	if (aslanlar.size() == 0) {
		cout << "\n\nAslanlarin Aritmetik Yas Ortalamasi: Veri Girilmedi"; // Menuden hic aslan verisi eklenmedi ise uyari verilir. (Bu islem her tur icin aynidir.)

	}
	else {
		cout << "\nAslanlarin Aritmetik Yas Ortalamasi: " << aslanAritmetik;
	}

	for (Kartal* kartal : kartallar) {

		kartalToplamYas += kartal->getYas();
		kartalAritmetik = kartalToplamYas / kartallar.size();
	}
	if (kartallar.size() == 0) {
		cout << "\nKartallarin Aritmetik Yas Ortalamasi: Veri Girilmedi";

	}
	else {
		cout << "\nKartallarin Aritmetik Ortalamasi: " << kartalAritmetik;
	}



	for (Zebra* zebra : zebralar) {

		zebraToplamYas += zebra->getYas();
		zebraAritmetik = zebraToplamYas / zebralar.size();
	}
	if (zebralar.size() == 0) {
		cout << "\nZebralarin Aritmetik Yas Ortalamasi: Veri Girilmedi";

	}
	else {
		cout << "\nZebralarin Aritmetik Ortalamasi: " << zebraAritmetik;
	}


}

void HayvanatBahcesi::HayvanBesle() {

	string ad;
	string tur;
	int yas;

	cout << "Beslemek istediginiz hayvanin sirasiyla adini, turunu ve yasini giriniz: "; // Ayni ad, tur ve yasa sahip olabilecek hayvanlar arasinda karisiklik olmamasi icin, beslenmesi istenilen hayvanin ad, tur ve yasi istenir.
	cin >> ad >> tur >> yas;

	bool hayvanBulundu = false;
	for (Hayvan* hayvan : hayvanlar) {

		if (hayvan->getAd() == ad && hayvan->getTur() == tur && hayvan->getYas() == yas) { // Alinan inputlar hayvanlar vektorundeki hayvanlar ile eslesirse hayvanBulundu true degerini alir.

			hayvanBulundu = true;

			hayvan->Besle(); // Hayvan besle fonksiyonu cagirilir.

		}

	}
	if (!hayvanBulundu) { // Hayvan bulunamadi ise hata verilir.

		cout << "\n//Bilgilerini girdiginiz hayvan bulunamadi.";
	}



}