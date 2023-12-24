#ifndef dugum_h
#define dugum_h

#include <iostream>
using namespace std;

class Dugum
{
public:
    int veri;
    Dugum *sol;
    Dugum *sag;

    Dugum(int veri);
    ~Dugum();
};

#endif