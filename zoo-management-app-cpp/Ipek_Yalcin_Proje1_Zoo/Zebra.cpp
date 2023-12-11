#include <iostream>
#include <string>
#include "Hayvan.h"
#include "Zebra.h"
using namespace std;

void Zebra::Besle() {
	cout << "\n//" << getAd() << " adli zebra ot yedi.//\n";
	setBeslendi(); // Besle() islemi gerceklestiginde setBeslendi() ile Beslendi true degeri alir. 
}