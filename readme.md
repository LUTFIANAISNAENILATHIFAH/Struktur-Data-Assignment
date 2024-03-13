# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Lutfiana Isnaeni Lathifah(2311102165)</p>

## Dasar Teori
Tipe data adalah klasifikasi value suatu variabel yang membantu operasi komputer untuk mengenali nilai data tanpa menghasilkan output error. 
Tipe data memudahkan program dalam mendekteksi berbagai jenis informasi. Pada dasarnya komputer hanya memahami bahasa biner yaitu 1 dan 0. Dalam sistem pemograman,
data diklasifikasikan menjadi berbagai jenis agar dapat ditafsirkan, disusun, dan digunakan dalam software.
Macam-macam tipe data dan contoh tipe data
Ada dua macam tipe data, yaitu tipe data primitif dan tipe data composite

1. Tipe Data Primitif
   tipe data primitif adalah tipe data sederhana. Tipe data ini bisa menyimpan satu nilai seperti digit, byte, atau karakter. Beberapa macam tipe data 
   primitif:
   
   - Integer
     Integer atau bilangan bulat adalah tipe data data primitif yang digunakan untuk angka tanpa pecahan. Tipe data ini tidak memiliki pecahan desimal. 
     Bilangan bulat bisa berupa negatif atau positif.
   
   - Floating Point
     floating point adalah tipe data numerik yang menyatakan angka dengan nominal pecahan. contohnya: 98.5, 0.078, 9.36
   
   - character
     Character adalah tipe data yang digunakan untuk menyatakan suatu angka, huruf, atau special character.
     Contohnya: %, 5, q, @
   
   - String
     String adalah tipe data yang menyatakan rangkaian character, angka, atau simbol-dan selalu diperlakukan sebagai teks. Tipe data string tidak bisa
     dipakai untuk operasi perhitungan matematis.
     contohnya: "Halo John Mayer"
     "087912345609", "Lorem Ipsum Dolor Sit Amet"
   
   - Boolean
     Boolean adalah tipe data yang menyatakan true (benar) atau false (salah)
   
2. Tipe data abstrak merupakan sebuah tipe data yang didefinisikan oleh sekelompok operasi atau metode yang dapat dilakukan pada data tersebut.
   Tipe data abstrak tidak mengungkapkan implementasi dari metode tersebut, melainkan hanya memberikan deskripsi fungsional tentang cara kerja dari tipe data tersebut.
   Konsep tipe data abstrak Tipe data abstrak pada dasarnya merupakan sebuah kelas yang digunakan untuk merepresentasikan sebuah objek, yang terdiri dari berbagaI
   tipe data yang didefinisikan bersama dengan metode atau operasi yang diperbolehkan untuk dilakukan pada objek tersebut. Tipe data abstrak menyembunyikan detaiL
   implementasi dari metode atau operasi yang digunakan, sehingga memungkinkan pemrogram untuk menggunakan tipe data tersebut tanpa harus tahu bagaimana detail implementasinya.
   
3. Tipe Data Kolektif
   Koleksi adalah tipe data yang berupa rangkaian atau kumpulan data yang berindeks. Terdapat tiga tipe dasar koleksi di Java yaitu:
   
   . Array : koleksi statis dengan ukuran tetap dan hanya bisa mengelompokkan tipe data yang sama.
   
   . List : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda.
   
   . Map : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda dengan menggunakan pasangan <key, value>.
   
   
## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
using namespace std;
// Main program
int main()
{
char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cin >> op;
// It allow user to enter the operands
cin >> num1 >> num2;
// Switch statement begins
switch (op)
{
// If user enter +
case '+':
cout << num1 + num2;
break;
// If user enter -
case '-':
cout << num1 - num2;
break;
// If user enter *
case '*':
cout << num1 * num2;
break;
// If user enter /
case '/':
cout << num1 / num2;
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! operator is not correct";
} // switch statement ends
return 0;
}

```
### Deskripsi Program
Kode diatas untuk menghitung hasil operasi matematika dasar (+, -, *, /) 
pada dua angka yang diinputkan oleh pengguna,
menggunakan fungsi 'eval ()' yang akan menghitung hasil dari ekpresi yang diberikan.

### 2. [Tipe Data Abstrak]

```C++
[15.53, 13/3/2024] lutfiana: #include <stdio.h>
//Struct
struct Mahasiswa
{
const char *name;
const char *address;
int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
mhs1.name = "Dian";
mhs1.address = "Mataram";
mhs1.age = 22;
mhs2.name = "Bambang";
mhs2.address = "Surabaya";
[15.53, 13/3/2024] lutfiana: mhs2.age = 23;
// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```

### Deskripsi Program
Kode diatas menggunakan struct untuk menyimpan data mahasiswa.
Kode ini mengisi nilai ke dalam struct dan mencetak isi struct tersebut.Dalam kode ini, 
menggunakan struct untuk menyimpan data mahasiswa. Struct ini memiliki tiga anggota:
nama, alamat, dan umur. Kemudian, mengisi nilai ke dalam struct dan mencetak isi struct tersebut.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}

```
### Deskripsi Program
kode diatas menjelaskan tentang penggunaan array. Array yang digunakan bernama "nilai" dengan panjang 5 elemen.
Elemen-elemen array ini diinisialisasi dengan nilai 23, 50, 34, 78, dan 90. Program ini kemudian mencetak isi dari setiap 
elemen dari array menggunakan perintah cout. Hasil dari setiap perintah cout akan dicetak ke layar dengan mencetak teks "Isi array" dan nilai dari setiap elemen array.

## Unguided 


### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan darimateri tipe data primitif!]

```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]
```C++
#include <iostream>
#include <map>
#include <vector>

int main() {
    // Contoh array
    int array[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);

    // Menggunakan fungsi map
    std::map<int, int> myMap;

    // Mengisi map dengan data dari array
    for (int i = 0; i < arraySize; ++i) {
        myMap[i] = array[i];
    }

    // Menampilkan isi array
    std::cout << "Isi Array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }

    // Menampilkan isi map
    std::cout << "\nIsi Map: ";
    for (const auto& pair : myMap) {
        std::cout << pair.second << " ";
    }

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)
## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
