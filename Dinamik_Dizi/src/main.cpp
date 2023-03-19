#include<iostream>
#include "DinamikDizi.hpp"
using namespace std;

int main()
{
    DinamikDizi dizi;
    
    while (true)
    {
        system("cls");
        cout << dizi;

        cout << "1- Sona Ekle\n"
            << "2- Araya Ekle\n"
            << "3- Diziden cikar\n"
            << "4- Cikis \n"
            << " Bir islem Seciniz: ";
        int secim;
        cin>> secim;

        if(secim == 1)
            dizi.sonaEkle(rand() % 101);
        
        else if(secim == 2)
            dizi.arayaEkle(rand() % 101);
        
        else if(secim == 3)
            dizi.cikar();

        else if(secim == 4)
        {
            cout << "****** Cikis islemi basariyla yapildi ******" << endl;
            break;
        }
    }
    
    system("pause");
}