#ifndef IkiliAramaAgac_hpp
#define IkiliAramaAgac_hpp
#include "Dugum.hpp"
#include <iostream>
#include <math.h>
using namespace std;

class IkiliAramaAgac
{

public:
    IkiliAramaAgac();
    void ekle(int veri);
    void sil(int veri);
    bool arama(int veri);
    int yukseklik(Dugum* aktif);
    Dugum* kokGetir();

private:
    Dugum* kok;
    int enBuyuk(Dugum* aktif);
    bool arama(int aranan, Dugum* aktif);
    void ekle(int veri, Dugum* aktif);
    void sil(int aranan, Dugum* &aktif);
    void preOrderYazdirma(Dugum* aktif);
    void postOrderYazdirma(Dugum* aktif);
    void inOrderYazdirma(Dugum* aktif);
};

#endif