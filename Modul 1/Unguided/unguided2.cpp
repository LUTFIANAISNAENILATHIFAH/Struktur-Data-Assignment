#include <iostream>
 
struct Bentuk {
    float panjang, lebar;
     
    /* constructor */
    Shape() {
        panjang = 0;
        lebar = 0;
    }
     
    /* fungsi virtual */
    virtual float luas() {
        return 0;
    }
};

/* struct PersegiPanjang adalah turunan struct Bentuk */
struct PersegiPanjang: Bentuk {
    /* constructor */
    PersegiPanjang() {
        panjang = 0;
        lebar = 0;
    }
     
    /* menulis ulang fungsi virtual */
    float luas() {
        return panjang * lebar;
    }
};

class BentukS {    
protected:
    float m_alas, m_tinggi;
     
public:
    /* constructor */
    ShapeS() {
        m_alas = 0;
        m_tinggi = 0;
    }
     
    /* fungsi virtual */
    virtual float luasS() {
        return 0;
    }
};

class Segitiga: public BentukS {
public:
    /* constructor */
    Segitiga() {
        m_alas = 0;
        m_tinggi = 0;
    }
     
    void setAlas(float alas) {
        m_alas = alas;
    }
     
    void setTinggi(float tinggi) {
        m_tinggi = tinggi;
    }
 
    /* menulis ulang fungsi virtual */
    float luasS() {
        return (1.f / 2.f * m_tinggi * m_alas);
    }
};


int main() {
    struct Bentuk *bentuk1 = new struct PersegiPanjang;
    BentukS *bentuk2 = new Segitiga;
 
     
    bentuk1->lebar = 10;
    bentuk1->panjang = 5;

    static_cast<Segitiga *> (bentuk2)->setAlas(10);
    static_cast<Segitiga *> (bentuk2)->setTinggi(5);
    
    std::cout << "Luas persegi panjang menggunakan Struct : " << bentuk1->luas() << '\n'; 
    std::cout << "Luas segitiga menggunakan Class : " << bentuk2->luasS() << '\n';

    return 0;
}