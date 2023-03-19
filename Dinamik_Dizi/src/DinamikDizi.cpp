#include "DinamikDizi.hpp"
#include <iostream>
#include <iomanip>

DinamikDizi::DinamikDizi()
{
    m_boyut = 5;
    m_kullanilan = 0;
    m_adres = new int[m_boyut];
}

DinamikDizi::~DinamikDizi()
{
    delete[] m_adres;
}

int DinamikDizi::boyut() const
{
    return m_boyut;
}

int DinamikDizi::kullanilan() const
{
    return m_kullanilan;
}

int DinamikDizi::degerGetir(int sira) const
{
    if(sira < 0 || sira >= m_kullanilan)
    {
        cout << "Sinir asiri problemi!!" << endl;
    }
    else
        return m_adres[sira];
}

void DinamikDizi::sonaEkle(int yeniSayi)
{
    if(m_kullanilan >= m_boyut || m_kullanilan < 0)
        genislet(m_boyut);

    m_adres[m_kullanilan] = yeniSayi;
    m_kullanilan++;
}

void DinamikDizi::arayaEkle(int yeniSayi)
{
    cout << "  Sira No: ";
    int sira;
    cin >> sira;

    if(sira >= 0 && sira <= m_kullanilan)
    {
        if(m_kullanilan >= m_boyut || m_kullanilan < 0)
            genislet(m_boyut);
        
        for (int i = m_kullanilan - 1; i >= sira; i--)
            m_adres[i + 1] = m_adres[i];

        m_adres[sira] = yeniSayi;
        m_kullanilan++;
    }
    else
    {
        cout << "Yanlis sira girdiniz!!" << endl;
    }
}

void DinamikDizi::cikar()
{
    cout << "  Sira no: ";
    int sira;
    cin>>sira;
    if(sira >= 0 &&
        m_kullanilan > 0 &&
        sira < m_kullanilan)
    {
        for (int i = sira; i < m_kullanilan - 1; i++)
            m_adres[i] = m_adres[i + 1];

        m_kullanilan--;
    }
    else 
    {
        cout << "Cikar(): sira hatali girdiniz!!" << endl;
    }
}

void DinamikDizi::genislet(int ekBoyut)
{
    int* yeniAdres = new int[m_boyut + ekBoyut];

    for (int i = 0; i < m_kullanilan; i++)
        yeniAdres[i] = m_adres[i];

    delete[] m_adres;
    m_adres = yeniAdres;
    m_boyut += ekBoyut;
    
}

ostream& operator<<(ostream& os, const DinamikDizi& dizi)
{
    os << "|";
    for (int i = 0; i < dizi.boyut(); i++)
        os << setw(3) << i << setw(1) << "|";
    os << endl << "|";
    
    for (int i = 0; i < dizi.boyut(); i++)
        os << setw(3) << "---" << setw(1) << "|";
    os << endl << "|";

    for (int i = 0; i < dizi.kullanilan(); i++)
        os << setw(3) << dizi.degerGetir(i) << setw(1) << "|";

    for (int i = dizi.kullanilan(); i < dizi.boyut(); i++)
        os << setw(3) << "Bos" << setw(1) << "|";

    os << endl << endl;
    return os;
}