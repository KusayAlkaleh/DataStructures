#ifndef HeapSort_hpp
#define HeapSort_hpp

const int max = 100;
class Heap
{

public:
    Heap();
    void ekle(int veri);
    void cikar();
    int getir();

private:
    int solIndeks(int a);
    int sagIndeks(int a);
    int ebeveynIndeks(int a);

    int veriler[max];
    int ES;

    void heapifyUp(int indeks);
    void heapifyDown(int indeks);

};

#endif
