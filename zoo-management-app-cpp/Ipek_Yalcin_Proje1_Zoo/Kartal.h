#pragma once
#include <string>
#include <vector>
#include "Hayvan.h"
using namespace std;

class Kartal : public Hayvan { // Hayvan sinifinin ozellikleri kalitim ile kartal sinifinda aktif hale gelir.

public:
	void Besle() override; // Hayvan sinifindan kalitim ile gecen Besle() fonksiyonu override ile Kartala göre özellestirilir.

};