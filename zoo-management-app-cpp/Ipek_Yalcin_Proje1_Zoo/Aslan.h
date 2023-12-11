#pragma once
#include <string>
#include <vector>
#include "Hayvan.h"
using namespace std;

class Aslan : public Hayvan { // Hayvan sinifinin ozellikleri kalitim ile aslan sinifinda aktif hale gelir.

public:
	void Besle() override; // Hayvan sinifindan kalitim ile gecen Besle() fonksiyonu override ile Aslana göre özellestirilir.

};