#ifndef Liste_hpp
#define Liste_hpp
#include "ListeDugum.hpp"

class Liste
{

public:
    Liste();
    ~Liste();
    void ekle(int veri);
    void yazdir();
    ListeDugum* ilkDeger();

private:
    ListeDugum* ilk;

};

#endif