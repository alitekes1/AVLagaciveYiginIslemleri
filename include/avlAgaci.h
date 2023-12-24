#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include <iostream>
#include "dugum.h"
#include "yigin.h"
using namespace std;

class avlAgaci
{
private:
	Dugum* kok;

	Dugum* ekle(int eklencekdeger, Dugum* aktifDugum);
	void postorder(Dugum* aktifDugum);
	void YapraklariBulveYiginaEkle(Dugum* aktifDugum);
	void sil(Dugum*& aktifDugum);
public:
	Yigin* yigin;
	int veritoplami;
	int avlNO;

	avlAgaci(int avlNo);
	~avlAgaci();

	int ara(int aranacakDeger, Dugum* aktifDugum);
	int yukseklik(Dugum* akfifDugum);
	Dugum* sagaDondur(Dugum* akfifDugum);
	Dugum* solaDondur(Dugum* akfifDugum);
	void ekle(int eklenecekdeger);
	void postorder();
	void YapraklariBulveYiginaEkle();
	void sil();
};

#endif