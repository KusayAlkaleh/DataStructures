#ifndef Radix_hpp
#define Radix_hpp
#include "Kuyruk.hpp"
#include "ListeDugum.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

class Radix
{

public:
    Radix(ListeDugum* gec,int adet);
    ~Radix();
    int *sirala();
    void kuyruklariYazdir();

private:
    int maxBasamakSayisiGetir();
    int basamakSayisiGetir(int sayi);
    void kuyrukUzunluklariGetir(int* uzunluklar);
    Kuyruk** kuyruklar;
    int* sayilar;
    int sayiAdedi;
};

#endif