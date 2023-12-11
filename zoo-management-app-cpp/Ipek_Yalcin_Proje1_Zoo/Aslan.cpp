#include <iostream>
#include <string>
#include "Aslan.h"
#include "Hayvan.h"

using namespace std;

void Aslan::Besle() {
	cout << "\n//" << getAd() << " adli aslan wagyu eti yedi.//\n";
	setBeslendi(); // Besle() islemi gerceklestiginde setBeslendi() ile Beslendi true degeri alir. 
}