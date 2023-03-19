#include <iostream>
#include "BagliListe.hpp"
using namespace std;

int main()
{
    BagliListe* liste = new BagliListe();
    
    while (true)
    {
        system("cls");
        liste->yazdir();
        cout << "1- Dugum ekle\n" 
            << "2- Dugum cikar\n"
            << "3- Cikis\n"
            << " Secenigiz islem numara: ";
        int secim;
        cin >> secim;

        if(secim == 1)
            liste->ekle(rand() % 100);

        else if(secim == 2)
            liste->cikar();

        else if(secim == 3)
            break;
    }
    
    system("pause");
}