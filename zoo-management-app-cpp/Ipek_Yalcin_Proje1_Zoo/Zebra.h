#pragma once
#include <string>
#include <vector>
#include "Hayvan.h"
using namespace std;

class Zebra : public Hayvan { // Hayvan sinifinin ozellikleri kalitim ile Zebra sinifinda aktif hale gelir.

public:
	void Besle() override; // Hayvan sinifindan kalitim ile gecen Besle() fonksiyonu override ile Zebraya göre özellestirilir.

};