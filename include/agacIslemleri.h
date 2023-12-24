#ifndef AGACISLEMLERI_HPP
#define AGACISLEMLERI_HPP
#include "avlAgaci.h"

class agacIslemleri
{
private:

	void agaciTemizle(avlAgaci*& silinecekAgac);
	avlAgaci* enBuyukTepeyeSahipAgaciGetir();
	avlAgaci* enKucukTepeyeSahipAgaciGetir();
	void AgaciTumAgaclardanKaldir(avlAgaci* silinecekagac);
	int silinecekAgaciTumAgaclardakiYeri(avlAgaci* silinecekagac);
	void agactakiYiginlariIlkHalineCevir();
	void YigindanElemanCikarveAgaciTemizle();
public:
	avlAgaci** tumAgaclar; // pointer dizisi
	agacIslemleri(int toplamAgacSayisi);
	~agacIslemleri();
	int toplamAgacSayisi;
	int diziBoyut;

	void agaciSilveHarfBastir();
	void DosyadanVeriOkuAgacaEkle(string dosyaIsmi);
	void ekranaBastir();
	void sonAgacinBilgileriniGetir();
};

#endif // !AGACISLEMLERI_HPP
