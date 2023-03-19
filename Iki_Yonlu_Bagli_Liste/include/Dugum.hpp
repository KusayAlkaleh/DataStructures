#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
    int veri;
    Dugum* sonraki;
    Dugum* onceki;
    
    Dugum(int veri);
};

#endif