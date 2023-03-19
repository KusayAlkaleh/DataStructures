#ifndef DinamikDizi_hpp
#define DinamikDizi_hpp
#include <iostream>
using namespace std;

class DinamikDizi
{
public:
    DinamikDizi();
    ~DinamikDizi();
    int boyut() const; 
    int kullanilan() const;
    int degerGetir(int sira) const;
    void sonaEkle(int yeniSayi);
    void arayaEkle(int yeniSayi);
    void cikar(); 
    friend ostream& operator<<(ostream& os, const DinamikDizi& dizi); 
private:
    int m_boyut;
    int m_kullanilan;
    int *m_adres;
    void genislet(int ekBoyut);

};
#endif