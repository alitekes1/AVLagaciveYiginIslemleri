/**
 * @file main.cpp
 * @description Dosyadan veri okur.AVL agacina ekler.
 * @course 1-C
 * @assignment 2
 * @date 20.12.2023
 * @author Ali Tekeş	ali.tekes@ogr.sakarya.edu.tr
 */
#include <iostream>
#include <stdlib.h>
#include "agacIslemleri.h"
using namespace std;

int main()
{
	int diziBoyut = 500;
	string dosyaIsmi = "Veri.txt";

	agacIslemleri* agacislemleri = new agacIslemleri(diziBoyut);

	agacislemleri->DosyadanVeriOkuAgacaEkle(dosyaIsmi); // okunan degerleri AVL agacina dugum olarak ekler ve agacin yapraklarini yigina ekler.
	agacislemleri->ekranaBastir();						// hesaplanan değerin ascii karşılığını ekrana basar
	agacislemleri->agaciSilveHarfBastir();				// verilen algoritmaya uygun şekilde agacı siler ve kalan agaclara göre ascii karşılığını ekrana yazdırır.

	agacislemleri->sonAgacinBilgileriniGetir();

}