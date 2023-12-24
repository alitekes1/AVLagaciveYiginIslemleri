/**
 * @file main.cpp
 * @description Dugum sınıfının yapıcısı yer alır.
 * @course 1-C
 * @assignment 2
 * @date 20.12.2023
 * @author Ali Tekeş	ali.tekes@ogr.sakarya.edu.tr
 */
#include "dugum.h"

Dugum::Dugum(int veri)
{
	sol = 0;
	sag = 0;
	this->veri = veri;
}

Dugum::~Dugum()
{
	if (sol != nullptr) {
		delete sol;
		sol = nullptr;
	}

	if (sag != nullptr) {
		delete sag;
		sag = nullptr;
	}
}