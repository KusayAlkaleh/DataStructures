#ifndef DinamikStack_hpp
#define DinamikStack_hpp
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();
    void ekle(int veri);
    void cikar();
    int getir();
    bool bosmu();
    friend ostream& operator<<(ostream& os, Stack& stack);
private:
    int tepe;
    int kapasite;
    int *veriler;
    void genislet(int boyut);
};

#endif