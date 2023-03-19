#include <iostream>
#include <iomanip>
#include "BagliListe.hpp"
using namespace std;

BagliListe::BagliListe()
{
    ilk = 0;
}

BagliListe::~BagliListe()
{
    Dugum* gec = ilk;

    while (gec != 0)
    {
        Dugum* silenecek = gec;
        gec = gec->sonraki;
        delete silenecek;
    }
}

void BagliListe::ekle(int veri)
{
    Dugum* yeniSayi = new Dugum(veri);
    if(ilk == 0) ilk = yeniSayi;
    else
    {
        Dugum* gec = ilk;
        while (gec->sonraki != 0)
            gec = gec->sonraki;
    
        gec->sonraki = yeniSayi;
    }
}

void BagliListe::cikar()
{
    if(ilk == 0) return;

    if(ilk->sonraki == 0)
    {
        delete ilk;
        ilk = 0;
    }
    else
    {
        Dugum* gec = ilk;
        while (gec->sonraki->sonraki != 0)
            gec = gec->sonraki;
        
        delete gec->sonraki;
        gec->sonraki = 0;
    }
}

void BagliListe::yazdir()
{
    cout << setw(10) << "Adres" << setw(10) << "Veri" << setw(15) << "Sonraki" << endl; 
    cout << "------------------------------------" << endl;
    Dugum* gec = ilk;
    while (gec != 0)
    {
        cout << setw(10) << gec << setw(10) << gec->veri << setw(15) << gec->sonraki << endl;
        gec = gec->sonraki;
    }
    cout << endl;
}