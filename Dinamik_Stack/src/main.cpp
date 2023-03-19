#include "DinamikStack.hpp"

int main()
{
    Stack stack;
    
    while (true)
    {
        system("cls");
        cout << stack;

        cout << "1- Veri ekle\n"
            << "2- Veri cikar\n"
            << "3- Cikis\n"
            << " Secenigiz islem no: ";
            int secim;
            cin >> secim;
        
        if(secim == 1)
        {
            cout << "  Veri: ";
            int veri;
            cin >> veri;
            stack.ekle(veri);
        }

        else if(secim == 2)
            stack.cikar();

        else if(secim == 3)
            break;
    }
    

    system("pause");
}