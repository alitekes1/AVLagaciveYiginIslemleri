/**
 * @file main.cpp
 * @description Agaca dair tum islemleri yapar.
 * @course 1-C
 * @assignment 2
 * @date 20.12.2023
 * @author Ali Tekeş	ali.tekes@ogr.sakarya.edu.tr
 */
#include <iostream>
#include <fstream>
#include "agacIslemleri.h"
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

agacIslemleri::agacIslemleri(int toplamAgacSayisi)
{
	diziBoyut = toplamAgacSayisi;
	this->toplamAgacSayisi = toplamAgacSayisi;
	tumAgaclar = new avlAgaci * [toplamAgacSayisi];
}

agacIslemleri::~agacIslemleri()
{
	for (int i = 0; i < toplamAgacSayisi; ++i) {
		delete tumAgaclar[i]; // Bellek sızıntısını önlemek için her AVL ağacını serbest bırakır.
	}
	delete[] tumAgaclar; // AVL ağaç dizisini serbest bırakmır
}
void agacIslemleri::DosyadanVeriOkuAgacaEkle(string dosyaIsmi)
{
	int avlNo = 0;
	ifstream dosya(dosyaIsmi);
	if (dosya.is_open())
	{
		string satir;
		while (getline(dosya, satir))
		{
			istringstream stream(satir);
			int okunandeger;
			avlAgaci* yeniAgac = new avlAgaci(avlNo); // agacin tumagaclar dizisindeki sira no sunu gönderiyoruz
			while (stream >> okunandeger)
			{
				yeniAgac->veritoplami += okunandeger;
				yeniAgac->ekle(okunandeger);		 //agaca dengeli bir şekilde dugum ekliyoruz.
			}
			tumAgaclar[avlNo] = yeniAgac;

			yeniAgac->YapraklariBulveYiginaEkle();
			avlNo++;
		}
	}
	else
	{
		cout << "dosya acilamadi!" << endl;
	}
}

void agacIslemleri::agaciTemizle(avlAgaci*& aktif)
{
	if (aktif == nullptr)
	{
		return;
	}
	aktif->sil();
}

int agacIslemleri::silinecekAgaciTumAgaclardakiYeri(avlAgaci* avlagaci)
{
	for (int i = 0; i < diziBoyut; i++)
	{
		if (tumAgaclar[i] == avlagaci)
		{
			return i;
		}
	}
}
void agacIslemleri::AgaciTumAgaclardanKaldir(avlAgaci* silinecekAgac)
{
	int silindeks = silinecekAgaciTumAgaclardakiYeri(silinecekAgac);
	delete tumAgaclar[silindeks];

	// Silinen elemanın yerine son elemanı kopyala
	tumAgaclar[silindeks] = tumAgaclar[diziBoyut - 1];
	tumAgaclar[diziBoyut - 1] = nullptr; // sondaki elemanı sildiğimiz alanın üzerine yazdığımız için sondaki alanı temizliyoruz.

	diziBoyut--;
}

avlAgaci* agacIslemleri::enKucukTepeyeSahipAgaciGetir()
{
	avlAgaci* minAgac = tumAgaclar[0]; // ilk agacin yiginindaki tepe degeri ald�k.
	int i;
	for (i = 1; i < diziBoyut; i++) // tum yiginlari gezecek
	{
		avlAgaci* geciciAgac = tumAgaclar[i];
		if (!tumAgaclar[i]->yigin->bosmu()) // eğer boş değilse devam. eğer boş ise bu boş yigini silmek için 
		{
			if (minAgac->yigin->tepeDegeriGetir() >= geciciAgac->yigin->tepeDegeriGetir()) // daha küçük tepe degere sahip olan yigini var ise onu minagac a atar.
			{
				minAgac = geciciAgac;
			}
		}
		else
		{
			return tumAgaclar[i];
		}
	}
	return minAgac;
}
avlAgaci* agacIslemleri::enBuyukTepeyeSahipAgaciGetir()
{
	avlAgaci* maksAgac = tumAgaclar[0]; // ilk agaci maks agac olarak kabul ettik
	int i;
	for (i = 1; i < diziBoyut; i++) // t�m yiginlari gezecek
	{
		avlAgaci* geciciAgac = tumAgaclar[i];
		if (!tumAgaclar[i]->yigin->bosmu()) // eğer boş değilse devam. eğer boş ise bu boş yigini silmek için gönderiyoruz.
		{
			if (maksAgac->yigin->tepeDegeriGetir() < geciciAgac->yigin->tepeDegeriGetir()) // daha büyük tepe degere sahip olan yigini var ise onu maks agac a atar.
			{
				maksAgac = geciciAgac;
			}
		}
		else
		{
			return tumAgaclar[i];
		}
	}
	return maksAgac;
}
void agacIslemleri::YigindanElemanCikarveAgaciTemizle()//ismi gayet açık
{
	bool durum = true;
	while (true)
	{
		if (durum)
		{
			avlAgaci* enKucukTepeyeSahipAgac = enKucukTepeyeSahipAgaciGetir();
			Yigin* yigin = enKucukTepeyeSahipAgac->yigin;
			if (!yigin->bosmu())
			{
				yigin->cikar();
			}
			else // eğer yigin boşsa agaci sileceğiz
			{
				int indis = enKucukTepeyeSahipAgac->avlNO;
				agaciTemizle(enKucukTepeyeSahipAgac); // agacın tum dugumleri silinir.

				AgaciTumAgaclardanKaldir(enKucukTepeyeSahipAgac); // agac islemlerindeki tumAgaclar dizisinden kaldırır.

				enKucukTepeyeSahipAgac = nullptr;
				delete enKucukTepeyeSahipAgac;
				agactakiYiginlariIlkHalineCevir(); // silinmeyen agaclarin yiginlarini eski haline cevirir.

				return;
			}
		}
		else
		{
			avlAgaci* enBuyukTepeyeSahipAgac = enBuyukTepeyeSahipAgaciGetir();
			Yigin* yigin = enBuyukTepeyeSahipAgac->yigin;

			if (!yigin->bosmu())
			{
				yigin->cikar();
			}
			else // eğer yigin boşsa agaci sileceğiz
			{
				agaciTemizle(enBuyukTepeyeSahipAgac);// agacın tum dugumleri silinir.

				AgaciTumAgaclardanKaldir(enBuyukTepeyeSahipAgac);

				agactakiYiginlariIlkHalineCevir(); // silinmemis agactaki yiginlari eski haline cevirir
				enBuyukTepeyeSahipAgac = nullptr;
				delete enBuyukTepeyeSahipAgac;
				return;
			}
		}
		durum = !durum;
	}
}
void agacIslemleri::ekranaBastir()
{
	for (int i = 0; i < diziBoyut; i++)
	{
		int fark = tumAgaclar[i]->veritoplami - tumAgaclar[i]->yigin->yigindakiVeriToplami();
		int ascii = fark % 26 + 65;

		cout << static_cast<char>(ascii);
	}
}
void agacIslemleri::agaciSilveHarfBastir()
{
	for (int i = 0; i < toplamAgacSayisi - 1; i++) // son 1 agac kalan kadar seçerek silme işlemine devam ediyoruz.
	{
		YigindanElemanCikarveAgaciTemizle();
		system("cls");
		ekranaBastir();
	}
	system("cls");
}
void agacIslemleri::agactakiYiginlariIlkHalineCevir()
{
	for (int i = 0; i < diziBoyut; i++)
	{
		tumAgaclar[i]->yigin->eskiHalineGetir();
	}
}
void agacIslemleri::sonAgacinBilgileriniGetir()
{
	int fark = tumAgaclar[0]->veritoplami - tumAgaclar[0]->yigin->yigindakiVeriToplami();//son agacın harfini getirir.
	int ascii = fark % 26 + 65;

	cout << "=================================" << endl
		<< "|\t\t\t\t|" << endl
		<< "|\t\t\t\t|" << endl
		<< "|   Son Karakter:" << static_cast<char>(ascii) << "\t\t|" << endl
		<< "|   Sona kalan AVL Agac No=" << tumAgaclar[diziBoyut - 1]->avlNO << "  |" << endl
		<< "|\t\t\t\t|" << endl
		<< "|\t\t\t\t|" << endl
		<< "=================================" << endl;
}