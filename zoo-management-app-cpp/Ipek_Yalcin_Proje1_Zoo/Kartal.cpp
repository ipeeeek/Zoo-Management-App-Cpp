#include <iostream>
#include <string>
#include "Hayvan.h"
#include "Kartal.h"
using namespace std;

void Kartal::Besle() {
	cout << "\n//" << getAd() << " adli kartal pirzola yedi.//\n";
	setBeslendi(); // Besle() islemi gerceklestiginde setBeslendi() ile Beslendi true degeri alir. 
}