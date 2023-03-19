#include "Liste.hpp"

int main()
{
    Liste* liste = new Liste();

    while (true)
    {
        system("cls");
        cout << *liste;

        cout << "1- Dugumu Ekle\n"
            << "2- Dugumu Araya Ekle\n"
            << "3- Dugumu Cikar\n"
            << "4- Dugumu Aradan Cikar\n"
            << "5- Cikis\n"
            << " Seceniginzi Islem no: ";
        int secim;
        cin >> secim;

        if(secim == 1)
            liste->ekle(rand() % 100);

        else if(secim == 2)
        {
            cout << "  sira no: ";
            int sira;
            cin >> sira;
            cout << "  Dugumu veri: ";
            int veri;
            cin >> veri;

            liste->arayaEkle(sira, veri);
        }

        else if(secim == 3)
            liste->cikar();

        else if(secim == 4)
        {
            cout << "  sira no: ";
            int sira;
            cin >> sira;
            liste->cikar(sira);
        }

        else if(secim == 5)
            break;
    }
    system("pause");
}