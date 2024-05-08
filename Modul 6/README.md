# <h1 align="center">Laporan Praktikum Modul 6 Stack </h1>
<p align="center">Lutfiana Isnaeni Lathifah  
2311102165</p>

## Dasar Teori

Pengertian Stack

Stack atau dalam Bahasa Indonesia diartikan tumpukan, adalah struktur data linier yang mengikuti prinsip Last In First Out (LIFO). Artinya elemen yang terakhir disisipkan akan menjadi elemen pertama yang keluar. Cara struktur data stack dalam menyimpan sebuah nilai dapat kita bayangkan seperti piring yang disusun rapi secara bertumpuk ke atas. Apabila ingin mengambil piring bagian bawah, harus terlebih dahulu menyisihkan semua piring yang ada di atas.

Jenis-jenis Stack

Berdasarkan kemampuan menyimpan data, struktur data stack dapat dibagi menjadi 2 jenis, yaitu: register stack dan memory stack.

1. Register stack
   
Register stack merupakan stack yang hanya mampu menampung data dalam jumlah yang kecil. Kedalaman maksimum pada register stack cenderung dibatasi karena ukuran unit memorinya sangat kecil dibandingkan dengan memory stack.

2. Memory stack
   
Pada stack jenis ini, kedalaman dari stack cukup fleksibel dan mampu menangani dalam dalam skala yang lebih besar dibandingkan jenis sebelumnya.

Operasi-operasi Dasar pada Stack

Ada beberapa operasi dasar yang bisa kita untuk lakukan terhadap struktur data stack. Operasi-operasi tersebut meliputi

•	Push: Menyisipkan elemen ke bagian atas stack

•	Pop: Menghapus elemen atas dari stack

•	IsEmpty: Memeriksa apakah stack kosong

•	IsFull: Memerika apakah stack sudah penuh

•	Peek: Mendapatkan nilai elemen teratas tanpa menghapusnya [1]

Berikut kelebihan dan kekurangan dari stack :

1. Kelebihan
   
•	membantu mengelola data dengan metode LIFO

•	secara otomatis membersihkan objek

•	tidak mudah rusak

•	ukuran variabel tidak dapat diubah

•	mengontrol memori secara mandiri

2. Kekurangan
   
•	memori stack sangat terbatas

•	ada kemungkinan stack akan meluap atau overflow jika terlalu banyak objek

•	tidak memungkinkan akses acak, karena harus mengeluarkan tumpukan paling atas terlebih dahulu untuk mengakses tumpukan paling bawah [2]. 

## Guided 

### 1. [guided]

```C++
#include <iostream>

using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
```

Program yang disediakan merupakan implementasi struktur data stack. Stack adalah struktur data linear yang mengikuti prinsip Last In First Out (LIFO), di mana elemen yang terakhir dimasukkan adalah yang pertama kali dikeluarkan. Dalam program ini, sebuah array bernama arrayBuku digunakan untuk menyimpan judul-judul buku, dengan ukuran maksimum ditentukan oleh variabel maksimal. Variabel top digunakan sebagai indeks yang menunjukkan posisi teratas dari stack. Program menyediakan beberapa fungsi utama, antara lain pushArrayBuku untuk menambahkan data ke dalam stack, popArrayBuku untuk menghapus data dari stack, peekArrayBuku untuk melihat data pada posisi tertentu dalam stack tanpa menghapusnya, dan changeArrayBuku untuk mengubah data pada posisi tertentu dalam stack. Terdapat pula fungsi destroyArraybuku untuk menghapus semua elemen dalam stack, serta cetakArrayBuku untuk mencetak semua elemen dalam stack dimulai dari elemen teratas. Program juga dilengkapi dengan fungsi-fungsi pendukung lainnya, seperti isFull dan isEmpty untuk memeriksa apakah stack penuh atau kosong, serta countStack untuk mengembalikan jumlah elemen dalam stack. Dengan menggunakan program ini, pengguna dapat dengan mudah mengelola stack berisi judul-judul buku dengan melakukan berbagai operasi dasar stack seperti penambahan, penghapusan, dan pemantauan data.

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.Contoh:Kalimat: iniKalimat tersebut adalah polindrom Kalimat: telkom Kalimat tersebut adalah bukan polindrom Masukan Kalimat: ini tersebut adalah Palindrom]

```C++
// Lutfiana Isnanei Lathifah
// 2311102165

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;
    string cleanStr;

    // Menghapus karakter non-alfabet dan mengonversi huruf menjadi huruf kecil
    for (char c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }

    int length = cleanStr.length();
    int mid = length / 2;

    // Menyimpan setengah karakter pertama ke dalam stack
    for (int i = 0; i < mid; i++) {
        charStack.push(cleanStr[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang di-pop dari stack
    for (int i = mid + (length % 2); i < length; i++) {
        if (cleanStr[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah Palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan Palindrom." << endl;
    }

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%206/SS/output1.png)

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%206/SS/output%20no%201%201.2.png)

Kode di atas digunakan untuk memeriksa apakah sebuah kalimat merupakan palindrom atau tidak. Palindrom adalah suatu kata, frasa, angka, atau urutan karakter lainnya yang dapat dibaca sama baik dari depan maupun dari belakang. Dengan menggunakan struktur data stack, program tersebut dapat membandingkan setiap karakter dari depan dan belakang kalimat untuk menentukan apakah kalimat tersebut merupakan palindrom atau tidak.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%206/SS/full%20program%20no%201.png)

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?ContohKalimat: Telkom Purwokerto Hasil: otrekowrup mokleT Masukkan Kata Telkom Purwokerto Datastack Array: Data otrekowrup moklet]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseLetters(string sentence) {
    stack<char> letters;
    string reversedSentence = "";

    // Memasukkan huruf-huruf dalam kalimat ke dalam stack
    for (char letter : sentence) {
        letters.push(letter);
    }

    // Mengambil huruf-huruf dari stack untuk membentuk kalimat yang terbalik
    while (!letters.empty()) {
        reversedSentence += letters.top();
        letters.pop();
    }

    return reversedSentence;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    string reversedSentence = reverseLetters(sentence);
    cout << "\nHasil: " << reversedSentence << endl;

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%206/SS/ss%20output%20unguided2.png)

kode di atas digunakan untuk membalikkan urutan huruf dalam sebuah kalimat yang dimasukkan oleh pengguna. Program menggunakan struktur data stack untuk menyimpan setiap huruf dari kalimat, dan kemudian mengambil huruf-huruf tersebut dari stack untuk membentuk kalimat yang terbalik. Hasil akhirnya adalah kalimat dengan urutan huruf yang terbalik dari kalimat asli yang dimasukkan oleh pengguna.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%206/SS/full%20program%20no%202.png)



## Kesimpulan
Dengan prinsip Last In First Out (LIFO), stack adalah struktur data linier yang berguna untuk mengelola data dengan urutan yang terakhir dimasukkan akan menjadi yang pertama keluar. Ada dua jenis stack, yaitu register stack dan memory stack. Register stack hanya mampu menampung sedikit data karena batasan ukuran unit memorinya, sedangkan memory stack lebih fleksibel dan dapat menangani skala yang lebih besar. Operasi dasar pada stack meliputi push, pop, IsEmpty, IsFull, dan Peek.

Kelebihan dari stack termasuk kemampuannya dalam mengelola data dengan metode LIFO, membersihkan objek secara otomatis, dan kontrol memori yang mandiri. Namun, kelemahannya adalah memori stack yang terbatas, risiko overflow jika terlalu banyak objek, dan tidak memungkinkan akses acak. Dengan demikian, stack merupakan struktur data yang efektif dalam beberapa konteks, terutama ketika urutan operasi yang terjadi penting, namun juga memiliki batasan dan risiko yang perlu dipertimbangkan dalam penggunaannya.

## Referensi
[1]	Trivusi, “Struktur Data Stack Pengertian, Karakteristik, dan Kegunaannya,” pp. 1–1, Oct. 2022.

[2]	Maulana Adieb, “Memahami Stack Struktur Data yang Memudahkan Programmer Jalankan Tugasnya,” pp. 1–1, Feb. 2021.
 
