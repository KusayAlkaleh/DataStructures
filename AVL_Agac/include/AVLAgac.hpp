#ifndef AVLAgac_hpp
#define AVLAgac_hpp
#include "Dugum.hpp"
#include <iostream>
using namespace std;

class AVLAgac
{

public:
    AVLAgac();
    void ekle(int veri);
    void sil(int veri);

private:
    Dugum* kok;
    int yukseklik(Dugum* aktif);
    Dugum* sagaDondur(Dugum* buyukEbeveyn);
    Dugum* solaDondur(Dugum* buyukEbeveyn);
    Dugum* ekle(int veri, Dugum* aktifDugum);
    Dugum* sil(int veri, Dugum* aktif);
    int enBuyuk(Dugum* aktif);
    int dengesizlikYonu(Dugum* aktif);
};

#endif