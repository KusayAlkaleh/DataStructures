#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"

class BagliListe
{
private:
    Dugum* ilk;
public:
    BagliListe();
    ~BagliListe();
    void ekle(int veri);
    void cikar();
    void yazdir();
};

#endif