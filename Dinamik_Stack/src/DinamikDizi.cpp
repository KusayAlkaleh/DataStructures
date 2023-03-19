#include "DinamikStack.hpp"

Stack::Stack()
{
    tepe = -1;
    kapasite = 5;
    veriler = new int[kapasite];
}

Stack::~Stack()
{
    delete[] veriler;
}

void Stack::ekle(int veri)
{
    if(tepe == kapasite -1)
        genislet(kapasite);

    tepe++;
    veriler[tepe] = veri;
}

void Stack::cikar()
{
    if(tepe != -1)
        tepe--;
}

int Stack::getir()
{
    if(tepe != -1)
        return veriler[tepe];

    throw out_of_range("Stack is empty!!");
}

void Stack::genislet(int boyut)
{
    int* yeniAlan = new int[kapasite+boyut];

    for (int i = 0; i <= tepe; i++)
        yeniAlan[i] = veriler[i];
    
    delete[] veriler;

    veriler = yeniAlan;
    kapasite += boyut;
}

bool Stack::bosmu()
{
    if(tepe==-1)
        return true;

    return false;
}

ostream& operator<<(ostream& os, Stack& stack)
{
    os << "tepe -----> ";

    for (int i = stack.tepe; i >= 0; i--)
    {
        os << stack.veriler[i] << endl << "            ";
    }
    os << endl;

    return os;
}