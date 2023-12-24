/**
 * @file avlAgaci.cpp
 * @description AVL agacina dugum ekler,siler,dondurme islemleri ve ekrana yazdirma islemleri yapar.
 * @course 1-C
 * @assignment 2
 * @date 20.12.2023
 * @author Ali Tekeş	ali.tekes@ogr.sakarya.edu.tr
 */
#include "avlAgaci.h"
#include "yigin.h"
#include "algorithm"

avlAgaci::avlAgaci(int avlNo)
{
	kok = 0;
	veritoplami = 0;
	this->avlNO = avlNo + 1;
	yigin = new Yigin();
}

avlAgaci::~avlAgaci()
{
	sil(kok);
	kok = nullptr;

	if (yigin != nullptr) {
		delete yigin;
		yigin = nullptr;
	}
}
void avlAgaci::sil()
{
	sil(kok);
	kok = nullptr; // Kökü null olarak ayarla
}

void avlAgaci::sil(Dugum*& aktif)
{
	if (aktif == nullptr)
	{
		return;
	}
	sil(aktif->sol);
	sil(aktif->sag);
	delete aktif;
	aktif = nullptr;
}
int avlAgaci::yukseklik(Dugum* aktifDugum)
{
	if (aktifDugum)
	{
		return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
	}
	return -1;
}
Dugum* avlAgaci::sagaDondur(Dugum* aktifDugum)
{
	Dugum* solCocuk = aktifDugum->sol;
	aktifDugum->sol = solCocuk->sag;
	solCocuk->sag = aktifDugum;
	return solCocuk;
}
Dugum* avlAgaci::solaDondur(Dugum* aktifDugum)
{
	Dugum* sagCocuk = aktifDugum->sag;
	aktifDugum->sag = sagCocuk->sol;
	sagCocuk->sol = aktifDugum;
	return sagCocuk;
}
void avlAgaci::ekle(int veri)
{
	kok = ekle(veri, kok);
}
int sayi = 0;
Dugum* avlAgaci::ekle(int veri, Dugum* aktifDugum) // özyinelemeli bir fonksiyon
{
	if (aktifDugum == 0)
	{
		return new Dugum(veri);
	}
	else if (aktifDugum->veri < veri)
	{
		aktifDugum->sag = ekle(veri, aktifDugum->sag);
		if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1)
		{
			if (veri > aktifDugum->sag->veri)
				aktifDugum = solaDondur(aktifDugum);
			else
			{
				aktifDugum->sag = sagaDondur(aktifDugum->sag);
				aktifDugum = solaDondur(aktifDugum);
			}
		}
	}
	else if (aktifDugum->veri > veri)
	{
		aktifDugum->sol = ekle(veri, aktifDugum->sol);
		if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
		{
			if (veri < aktifDugum->sol->veri)
				aktifDugum = sagaDondur(aktifDugum);
			else
			{
				aktifDugum->sol = solaDondur(aktifDugum->sol);
				aktifDugum = sagaDondur(aktifDugum);
			}
		}
	}
	return aktifDugum;
}
void avlAgaci::postorder()
{
	postorder(kok);
}
void avlAgaci::postorder(Dugum* aktif)
{
	if (aktif)
	{
		postorder(aktif->sol);
		postorder(aktif->sag);
		cout << aktif->veri << "  ";
	}
}
int avlAgaci::ara(int deger, Dugum* aktifdugum)
{
	if (aktifdugum->veri < deger) // sağ da arayacağız.
	{
		if (aktifdugum->sag)
		{
			return ara(deger, aktifdugum->sag);
		}
		return 0;
	}
	else if (aktifdugum->veri > deger) // solda arayacağız
	{
		if (aktifdugum->sol)
		{
			return ara(deger, aktifdugum->sol);
		}
		return 0;
	}
	else
		return true;
}
void avlAgaci::YapraklariBulveYiginaEkle()
{
	YapraklariBulveYiginaEkle(kok);
}
void avlAgaci::YapraklariBulveYiginaEkle(Dugum* aktifDugum)
{
	if (aktifDugum == 0)
	{
		return;
	}
	if (aktifDugum->sol == 0 && aktifDugum->sag == 0)
	{
		yigin->ekle(aktifDugum->veri);
	}
	if (aktifDugum->sol)
	{
		YapraklariBulveYiginaEkle(aktifDugum->sol);
	}
	if (aktifDugum->sag)
	{
		YapraklariBulveYiginaEkle(aktifDugum->sag);
	}
}