#include "IkiliAramaAgac.hpp"

int main()
{
    IkiliAramaAgac* dene = new IkiliAramaAgac();
    dene->ekle(12);
    dene->ekle(15);
    dene->ekle(17);
    dene->ekle(18);
    dene->ekle(20);
    dene->ekle(32);
    dene->ekle(4);
    dene->ekle(3);
    dene->ekle(2);

    Dugum* ilk = dene->kokGetir();
    Dugum* sag = ilk->sag;
    Dugum* sol = ilk->sol;

    cout << dene->yukseklik(sag) << "   " << dene->yukseklik(sol) << endl;

    system("pause");
}