#include "HeapSort.hpp"

Heap::Heap()
{
    ES = 0;
}

int Heap::solIndeks(int a)
{
    return 2*a + 1;
}

int Heap::sagIndeks(int a)
{
    return 2*a +2;
}

int Heap::ebeveynIndeks(int a)
{
    return (a - 1) / 2;
}

void Heap::ekle(int veri)
{
    if(ES == 0) return;

    veriler[ES] = veri;
    ES++;

    heapifyUp(ES - 1);
}

void Heap::heapifyUp(int indeks)
{
    if(indeks == 0) return;

    int eb = ebeveynIndeks(indeks);

    if(veriler[eb] > veriler[indeks])
    {
        int temp = veriler[indeks];
        veriler[indeks] = veriler[eb];
        veriler[eb] = temp;

        heapifyUp(eb);
    }
}


void Heap::cikar()
{
    if(ES == 0)   return;

    veriler[0] = veriler[ES - 1];

    ES--;
    heapifyDown(0);
}

void Heap::heapifyDown(int indeks)
{
    int sol = solIndeks(indeks);
    int sag = sagIndeks(indeks);
    int min;

    if(sag >= ES)
    {
        if(sol >= ES)   return;

        else
            min = sol;
    }

    else
    {
        if(veriler[sag] > veriler[sol])
            min = sol;
        else   
            min = sag;
    }

    if(veriler[indeks] > veriler[min])
    {
        int temp = veriler[indeks];
        veriler[indeks] = veriler[min];
        veriler[min] = temp;

        heapifyDown(min);
    }
}