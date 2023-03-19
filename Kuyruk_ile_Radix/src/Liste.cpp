#include "Liste.hpp"
#include "ListeDugum.hpp"
#include <iostream>
using namespace std;

Liste::Liste()
{
    ilk = 0;
}

Liste::~Liste()
{
    ListeDugum* gec = ilk;

    while (gec != 0)
    {
        ListeDugum* sil = gec;
        gec = gec->sonraki;

        delete sil;
    }
}

void Liste::ekle(int veri)
{
    ListeDugum* yeniDugum = new ListeDugum(veri);

    if(ilk == 0) ilk = yeniDugum;
    else
    {
        ListeDugum* gec = ilk;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeniDugum;
    }
}

ListeDugum* Liste::ilkDeger()
{
    if(ilk == 0) return 0;
    
    return ilk;
}

void Liste::yazdir()
{
    ListeDugum* gec = ilk;

    while (gec != 0)
    {
        cout << gec << "   " << gec->veri << "   " << gec->sonraki << "   ";
        gec = gec->sonraki;
    }
    
}