#include <iostream>

using namespace std;

int tambah(int a, int b)
{
    return a+b;
}

float luasSegitiga(float alas, float t)
{
    return 0.5*alas*t;
}

int main () 
{
  int a = 5;
  int b = 10;

  float alas = 8;
  float t = 15;

  int hasil_penjumlahan = tambah(a, b);
  float hasil_Luas = luasSegitiga(alas, t);

    cout << "Hasil Tambah : " << hasil_penjumlahan << endl;
    cout << "Luas Segitigas : " << hasil_Luas << endl;

    return 0;

}