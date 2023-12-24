#ifndef YIGIN_HPP
#define YIGIN_HPP
#include <iostream>
using namespace std;

class Yigin
{
private:
	int tepe;
	int* veriler;
	int kapasite;
	int asilTepe;
	void genislet(int boyut);

public:
	void eskiHalineGetir();
	Yigin();
	~Yigin();
	void ekle(int veri);
	void cikar();
	bool bosmu();
	bool dolumu();
	int getir(int indis);
	void yazdir();
	int yigindakiVeriToplami();
	int tepeDegeriGetir();
	//void geciciCikar();
};

#endif