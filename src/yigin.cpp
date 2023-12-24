/**
 * @file main.cpp
 * @description Yigin ile ilgili tum islemleri yapar.
 * @course 1-C
 * @assignment 2
 * @date 20.12.2023
 * @author Ali Tekeş	ali.tekes@ogr.sakarya.edu.tr
 */
#include "yigin.h"
Yigin::Yigin()
{
	tepe = -1;
	kapasite = 5;
	asilTepe = -1;
	genislet(5);//dinamik dizi dolduğunda genisletir.
}
Yigin::~Yigin()
{
	delete[] veriler;
	veriler = nullptr;
}
void Yigin::ekle(int veri)
{
	if (dolumu())
	{
		genislet(kapasite);
	}
	tepe++;
	asilTepe++;
	veriler[tepe] = veri;
}
void Yigin::eskiHalineGetir()
{
	tepe = asilTepe;
}
void Yigin::genislet(int boyut)
{
	int* yeniAlan = new int[boyut + kapasite];
	for (int i = 0; i <= tepe; i++)
	{
		yeniAlan[i] = veriler[i];
	}
	veriler = yeniAlan;
	kapasite += boyut;
}
void Yigin::yazdir()
{
	for (int i = 0; i <= tepe; i++)
	{
		cout << veriler[i] << " ";
	}
	cout << endl;
}
bool Yigin::bosmu()
{
	if (tepe == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Yigin::dolumu()
{
	if (tepe == kapasite - 1)
	{
		return true;
	}
	return false;
}
void Yigin::cikar()
{
	tepe--;
	kapasite--;
}
int Yigin::getir(int indis)
{
	if (tepe >= indis)
	{
		return veriler[indis];
	}
	throw out_of_range("Hata:Yiginin sonunu gectiniz!");
}
int Yigin::yigindakiVeriToplami()
{
	int temp = 0;
	for (int i = 0; i <= tepe; i++)
	{
		temp += getir(i);
	}
	return temp;
}
int Yigin::tepeDegeriGetir()
{
	return getir(tepe);
}
