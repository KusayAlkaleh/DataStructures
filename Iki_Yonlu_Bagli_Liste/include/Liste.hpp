#ifndef Liste_hpp
#define Liste_hpp
#include <iostream>
#include "Dugum.hpp"
using namespace std;

class Liste
{
public:
    Liste();
    ~Liste();
    void ekle(int veri);
    void arayaEkle(int sira, int veri);
    void cikar();
    void cikar(int sira);
    friend ostream& operator<<(ostream& os, Liste& liste);
private:
    Dugum* ilk;
    Dugum* dugumGetir(int sira);
};

#endif