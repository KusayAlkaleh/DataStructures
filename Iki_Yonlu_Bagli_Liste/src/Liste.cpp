#include <iomanip>
#include "Liste.hpp"
using namespace std;

Liste::Liste()
{
    ilk = 0;
}

Liste::~Liste()
{
    Dugum* gec = ilk;

    while (gec != 0)
    {
        Dugum* silinecek = gec;
        gec = gec->sonraki;
        delete silinecek;
    }
}

void Liste::ekle(int veri)
{
    Dugum* yeniSayi = new Dugum(veri);

    if(ilk == 0) ilk = yeniSayi;
    else
    {
        Dugum* gec = ilk;
        while (gec->sonraki != 0)
            gec = gec->sonraki;

        gec->sonraki = yeniSayi;
        yeniSayi->onceki = gec;
    }
}

void Liste::arayaEkle(int sira, int veri)
{
    Dugum* yeniDugum = new Dugum(veri);

    if(ilk == 0 && sira == 0) ilk = yeniDugum;
    else 
    {
        Dugum* aktif = dugumGetir(sira);
        if(aktif == 0) return;
        
        Dugum* onceki = aktif->onceki;
        aktif->onceki = yeniDugum;
        yeniDugum->sonraki = aktif;
        yeniDugum->onceki = onceki;
        if(onceki)
            onceki->sonraki = yeniDugum;
        else
            ilk = yeniDugum;
    }
}

void Liste::cikar()
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

void Liste::cikar(int sira)
{
    if(ilk == 0) return;
    
    Dugum* silinecek = dugumGetir(sira);
    if(silinecek == 0) return;
    else
    {
        Dugum* sonraki = silinecek->sonraki;
        Dugum* onceki = silinecek->onceki;
        delete silinecek;

        if(sonraki)
            sonraki->onceki = onceki;
        if(onceki)
            onceki->sonraki = sonraki;
        else   
            ilk = sonraki;
    }
}

Dugum* Liste::dugumGetir(int sira)
{
    int sayac = 0;

    Dugum* gec = ilk;
    while (sira >= 0 && gec != 0)
    {
        if(sira == sayac) return gec;

        gec = gec->sonraki;
        sayac++;
    }

    return 0;
}

ostream& operator<<(ostream& os, Liste& liste)
{
    os << setw(15) << "Dugum adresi" << setw(15) << "Veri" << setw(15) << "Onceki" << setw(15) << "Sonraki" << endl;
    os << "--------------------------------------------------------------" << endl << endl;
    Dugum* gec = liste.ilk;
    while (gec != 0)
    {
        os << setw(15) << gec << setw(15) << gec->veri << setw(15) << gec->onceki << setw(15) << gec->sonraki << endl;
        gec = gec->sonraki;
    }
    
    os << "--------------------------------------------------------------" << endl;
    return os;
}