#include "IkiliAramaAgac.hpp"

IkiliAramaAgac::IkiliAramaAgac()
{
    kok = 0;
}

void IkiliAramaAgac::ekle(int veri)
{
    ekle(veri, kok);
}

void IkiliAramaAgac::ekle(int veri, Dugum* aktif)
{
    Dugum* yeniDugum = new Dugum(veri);

    if(kok == 0) kok = yeniDugum;
    else if(aktif->veri > veri)
    {
        if(aktif->sol)
            ekle(veri, aktif->sol);
        else
            aktif->sol = yeniDugum;
    }

    else if(aktif->veri < veri)
    {
        if(aktif->sag)
            ekle(veri, aktif->sag);
        else
            aktif->sag = yeniDugum;
    }
    else return;
}

void IkiliAramaAgac::sil(int veri)
{
    sil(veri, kok);
}

void IkiliAramaAgac::sil(int aranan, Dugum* &aktif)
{
    if(aktif == 0) return;

    if(aktif->veri > aranan)
        sil(aranan, aktif->sol);

    else if(aktif->veri < aranan)
        sil(aranan, aktif->sag);
    
    else
    {
        if(aktif->sag && aktif->sol)
        {
            aktif->veri = enBuyuk(aktif->sol);
            sil(aktif->veri, aktif->sol);
        }
        else
        {
            Dugum* silinencek = aktif;

            if(aktif->sag == 0)
                aktif = aktif->sol;
                
            else if(aktif->sol == 0)
                aktif = aktif->sag;
            
            else 
                aktif = 0;

            delete silinencek;
        }
    }
}

int IkiliAramaAgac::enBuyuk(Dugum* aktif)
{
    if(aktif)
        enBuyuk(aktif->sag);
    return aktif->veri;
}

int IkiliAramaAgac::yukseklik(Dugum* aktif)
{
    if(aktif)
        return 1 + max(yukseklik(aktif->sol), yukseklik(aktif->sag));
    return -1;
}

bool IkiliAramaAgac::arama(int veri)
{
    return arama(veri, kok);
}

bool IkiliAramaAgac::arama(int aranan, Dugum* aktif)
{
    if(aktif->veri < aranan)
    {
        if(aktif->sag)
            return arama(aranan, aktif->sag);
        return false;
    }

    else if(aktif->veri > aranan)
    {
        if(aktif->sol)
            return arama(aranan, aktif->sol);
        return false;
    }

    else return true;
}

void IkiliAramaAgac::preOrderYazdirma(Dugum* aktif)
{
    if(aktif)
    {
        cout << aktif->veri << "  ";

        if(aktif->sol)
            preOrderYazdirma(aktif->sol);

        if(aktif->sag)
            preOrderYazdirma(aktif->sag);
    }
}

void IkiliAramaAgac::postOrderYazdirma(Dugum* aktif)
{
    if(aktif)
    {
        if(aktif->sol)
            postOrderYazdirma(aktif->sol);
        
        if(aktif->sag)
            postOrderYazdirma(aktif->sag);

        cout << aktif->veri << "  ";
    }
}

void IkiliAramaAgac::inOrderYazdirma(Dugum* aktif)
{
    if(aktif)
    {
        if(aktif->sol)
            inOrderYazdirma(aktif->sol);
        
        cout << aktif->veri << "  ";

        if(aktif->sag)
            inOrderYazdirma(aktif->sag);
    }
}

Dugum* IkiliAramaAgac::kokGetir()
{
    return kok;
}