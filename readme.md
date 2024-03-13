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
   
   . Integer
     Integer atau bilangan bulat adalah tipe data data primitif yang digunakan untuk angka tanpa pecahan. Tipe data ini tidak memiliki pecahan desimal. 
     Bilangan bulat bisa berupa negatif atau positif.
   
   . Floating Point
     floating point adalah tipe data numerik yang menyatakan angka dengan nominal pecahan. contohnya: 98.5, 0.078, 9.36
   
   . character
     Character adalah tipe data yang digunakan untuk menyatakan suatu angka, huruf, atau special character.
     Contohnya: %, 5, q, @
   
   . String
     String adalah tipe data yang menyatakan rangkaian character, angka, atau simbol-dan selalu diperlakukan sebagai teks. Tipe data string tidak bisa
     dipakai untuk operasi perhitungan matematis.
     contohnya: "Halo John Mayer"
     "087912345609", "Lorem Ipsum Dolor Sit Amet"
   
   . Boolean
     Boolean adalah tipe data yang menyatakan true (benar) atau false (salah).
2. Tipe data abstrak merupakan sebuah tipe data yang didefinisikan
   
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


### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
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
