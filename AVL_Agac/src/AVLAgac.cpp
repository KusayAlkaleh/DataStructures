#include "AVLAgac.hpp"
#include <cmath>
#include <iostream>
using namespace std;

AVLAgac::AVLAgac()
{
    kok = nullptr;
}

void AVLAgac::ekle(int veri)
{
    kok = ekle(veri, kok);
}

Dugum* AVLAgac::ekle(int veri, Dugum* aktifDugum)
{
    if(aktifDugum == 0)
        return new Dugum(veri);

    if(aktifDugum->veri > veri)
    {
        aktifDugum->sol = ekle(veri, aktifDugum->sol);

        if(yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
        {
            if(aktifDugum->sol->veri > veri)
                aktifDugum = sagaDondur(aktifDugum);

            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum = sagaDondur(aktifDugum);
            }
        }
    }
    
    else if(aktifDugum->veri < veri)
    {
        aktifDugum->sag = ekle(veri, aktifDugum->sag);

        if(yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 0)
        {
            if(aktifDugum->sag->veri > veri)
                aktifDugum = solaDondur(aktifDugum);
            
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum = solaDondur(aktifDugum);
            }
        }
    }

    return aktifDugum;
}


void AVLAgac::sil(int veri)
{
    kok = sil(veri, kok);
}


Dugum* AVLAgac::sil(int veri, Dugum* aktif)
{
    if(aktif == 0)  return 0;

    if(aktif->veri > veri)
        aktif->sol = sil(veri, aktif->sol);

    else if(aktif->veri < veri)
        aktif->sag = sil(veri, aktif->sag);

    else
    {
        if(aktif->sag == 0 && aktif->sol == 0)
        {
            delete aktif;
            aktif = 0;
        }

        else if(aktif->sag == 0)
        {
            Dugum* sil = aktif->sol;
            *aktif = *aktif->sol;
            delete sil;
        }

        else if(aktif->sol == 0)
        {
            Dugum* sil = aktif->sag;
            *aktif = *aktif->sag;
            delete sil;
        }

        else
        {
            aktif->veri = enBuyuk(aktif->sol);
            sil(aktif->veri, aktif->sol);
        }
    }

    int denge = dengesizlikYonu(aktif);

    if(denge > 1)
    {
        if(dengesizlikYonu(aktif->sol) >= 0)
            return sagaDondur(aktif);

        else if(dengesizlikYonu(aktif->sol) < 0)
        {
            aktif->sol = solaDondur(aktif->sol);
            return sagaDondur(aktif);
        }
    }

    else if(denge < -1)
    {
        if(dengesizlikYonu(aktif->sag) >= 0)
            return solaDondur(aktif);

        else if(dengesizlikYonu(aktif->sag) < 0)
        {
            aktif->sag = sagaDondur(aktif->sag);
            return solaDondur(aktif);
        }
    }

    return aktif;
}

int AVLAgac::dengesizlikYonu(Dugum* aktif)
{
    if(aktif == 0)
        return 0;
    return yukseklik(aktif->sol) - yukseklik(aktif->sag);
}

int AVLAgac::enBuyuk(Dugum* aktif)
{
    if(aktif)
        enBuyuk(aktif->sag);
    
    return aktif->veri;
}

int AVLAgac::yukseklik(Dugum* aktif)
{
    if(aktif)
        return 1 + max(yukseklik(aktif->sol), yukseklik(aktif->sag));
    return -1;
}

Dugum* AVLAgac::solaDondur(Dugum* buyukEbeveyn)
{
    Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;

    return sagCocuk;
}

Dugum* AVLAgac::sagaDondur(Dugum* buyukEbeveyn)
{
    Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;

    return solCocuk;
}