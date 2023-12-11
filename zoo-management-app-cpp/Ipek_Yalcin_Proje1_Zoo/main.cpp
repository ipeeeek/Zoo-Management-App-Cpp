#include <iostream>
#include <cctype>
#include "Aslan.h"
#include "Hayvan.h"
#include "HayvanatBahcesi.h"
#include "Kartal.h"
#include "Zebra.h"
using namespace std;

int main()
{
    HayvanatBahcesi Zoo;
    int secenek = 0; // Menu secenegi, secenek adli degiskende saklanir.
    bool hayvanEklendi = false; // bool hayvanEklendi, hayvan eklenmedi ise 2, 3, 4 numarali seceneklerin hata verebilmesi icin kontrol edebilme ozelligi saglar.

    while (secenek != 5) {
        cout << "\nMENU\n 1. Hayvan Ekle\n 2. Hayvanlari Goster\n 3. Hayvanlari Besle\n 4. Hayvanlari Duzenle\n 5. Cikis\n\nSeciminizi Yapiniz: ";
        cin >> secenek;

        if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.
            cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Girilen yanlis inputu yok sayar.
            continue;
        }

        switch (secenek) {
        case 1: // Hayvan ekleme islemleri yapilir.
        {
            string ad, tur;
            int yas = 0;

            cout << "\n//DIKKAT: Hayvan ekleme islemini sonlandirmak icin 0 giriniz.//\n";

            while (true) { // 0 girilene kadar hayvan ekleme islemi surer.
                cout << "\nHayvanin adini, turunu ve yasini sirasiyla giriniz: ";
                cin >> ad;

                for (char& c : ad) { // Buyuk harf, kucuk harf duyarliligi saglamamasi icin girilen veriler kucuk harfe donusturulur.
                    c = tolower(c);
                }

                if (ad == "0") { // 0 girilirse donguden cikilir.
                    break;
                }

                if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.

                    cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cin >> tur;

                for (char& c : tur) { // Buyuk harf, kucuk harf duyarliligi saglamamasi icin girilen veriler kucuk harfe donusturulur.
                    c = tolower(c);
                }

                if (cin.fail() || tur != "aslan" && tur != "kartal" && tur != "zebra") {  // Yanlis tipde veri girildiginde uyari verir.
                    cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cin >> yas;

                if (cin.fail()) {  // Yanlis tipde veri girildiginde uyari verir.
                    cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                Zoo.HayvanEkle(ad, tur, yas); // Hata olmaz ise inputlar parametreler ile HayvanEkle fonksiyonuna gonderilir.
                hayvanEklendi = true; // Hayvan eklenirse hayvanEklendi true degerini alir.
            }

            break;
        }

        case 2: // Hayvanlar, harmonik ve aritmetik ortalamalar listelenir.
        {
            if (hayvanEklendi) { // Hayvan eklenip eklenmedigi kontrol edilir. Hayvan eklendi ise islemlere devam edilir.
                cout << "\n--------- Hayvanlar ve Bilgileri ---------\n";
                Zoo.HayvanlariGoster();
                Zoo.AritmetikYasOrtala();
                cout << "\n";
                Zoo.HarmonikYasOrtala();
            }
            else { // Hayvan eklenmedi ise uyari verir.
                cout << "\nHayvan eklenmedigi icin islem gerceklestirilemiyor." << endl;
            }

            break;
        }

        case 3: // Hayvanlari besleme islemi yapilir.
        {
            if (hayvanEklendi) { // Hayvan eklendi ise HayvanBesle fonksiyonu calisir.
                Zoo.HayvanBesle();
            }
            else {
                cout << "\nHayvan eklenmedigi icin islem gerceklestirilemiyor." << endl; // Hayvan eklenmedi ise uyari verir.
            }

            break;
        }

        case 4: // Hayvan duzenleme islemleri yapilir.
        {
            if (hayvanEklendi) { // // Hayvan eklenip eklenmedigi kontrol edilir. 
                int secim;

                cout << "\nDuzenlemek istediginiz bilgiyi secin:\n 1. Hayvanin Adini Guncelle\n 2. Hayvanin Turunu Guncelle\n 3. Hayvanin Yasini Guncelle\n\nSeciminizi Yapiniz: ";
                cin >> secim; // Duzenlenmek istenen bilgi belirlenir.

                if (cin.fail()) { // Yanlis tipde veri girildiginde uyari verir.
                    cout << "\nYanlis turde veri girildi, lutfen tekrar deneyiniz.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                switch (secim) { // Secime gore, fonksiyonlara switch case ile ulasilir.
                case 1:
                {
                    Zoo.HayvanAdGuncelle();
                    break;
                }

                case 2:
                {
                    Zoo.HayvanTurGuncelle();
                    break;
                }

                case 3:
                {
                    Zoo.HayvanYasGuncelle();
                    break;
                }

                default:
                {
                    cout << "\nGecersiz secim. Lutfen tekrar deneyiniz.\n";
                    break;
                }
                }
            }
            else {
                cout << "\nHayvan eklenmedigi icin islem gerceklestirilemiyor." << endl; // Hayvan eklenmedi ise hata verir.
            }

            break;
        }

        case 5: // Programdan cikis islemi.
        {
            cout << "\nProgramdan cikiliyor...";
            break;
        }

        default:
        {
            cout << "\nGecersiz secim. Lutfen tekrar deneyiniz.\n";
            break;
        }
        }

        cout << endl;
    }

    return 0;
}