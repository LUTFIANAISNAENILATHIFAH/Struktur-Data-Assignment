# <h1 align="center">Laporan Praktikum Modul 8 Algoritma Searching </h1>
<p align="center"> Lutfiana Isnaeni Lathifah 2311102165 </p>

## Dasar Teori

Algoritma pencarian(searching algorithm) merupakan langkah-langkah atau metode untuk mencari elemen tertentu. Algoritma pencarian digunakan untuk menemukan elemen tertentu dalam kumpulan atau struktur data seperti array, daftar, atau pohon. Terdapat 2 metode dalam algoritma searching, yaitu : [1] 

1.	Sequential Search

Algoritma Sequential search Algoritma Sequential search atau bisa juga disebut pencarian linear atau linear search adalah algoritma pencarian sederhana yang pencariannya dilakukan secara beruntun. Algoritma beruntun merupakan proses yang membandingkan tiap elemen larik satu persatu berurutan, mulai dari elemen awal, sampai dengan elemen yang dicari bisa ditemukan. Algoritma ini bekerja dengan mencocokkan data pada database dengan data yang dicari pencarian dilakukan secara beruntun dari data awal hingga data terakhir. 

Langkah-langkah pencarian dengan sequential search: 

•	Melakukan perbandingan beruntun pada kumpulan data dengan menggunakan keyword atau kata kunci yang akan dicari

•	Pencarian ini melakukan looping atau pengulangan dari data pertama hingga jumlah data ke-n 


•	 Setiap perulangan dilakukan pencocokan data dengan kata kunci yang dicari 

•	Apabila terdapat kecocokan data dengan kata kunci yang di cari maka data berhasil ditemukan dan pencarian di hentikan, sebaliknya apabila tidak ada kecocokan data hingga data terakhir maka pencarian dihentikan dan data tidak ditemukan


2.	Binary Search

Binary search adalah algoritma yang dikembangkan dengan ide dasar berbeda untuk menangani masalah pencarian data pada pemrograman. Binary search bekerja dengan baik untuk pencarian data yang sudah terurut. Berikut langkah-langkah pencarian binary search : 

•	Mengurutkan data terlebih dahulu bisa secara ascending (dari depan ke belakang) atau descending (dari belakang ke depan). 

•	Membagi dua array atau keseluruhan data. Apabila data yang dicari lebih kecil dari data yang terletak di tengah, maka pencarian data akan berlanjut kesebelah kiri. Apabila data yang dicari lebih besar dari data terletak ditengah, maka pencarian data akan berlanjut kesebelah kanan kemudian proses pencarian tersebut akan terus berulang sampai data yang dimaksud atau dicari dapat ditemukan [2].


## Guided 

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data. ]

```C++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke -
                                       " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
Kode tersebut digunakan untuk mencari indeks dari nilai tertentu dalam sebuah array. Dalam program ini, array data dengan 10 elemen diberikan, dan nilai yang ingin dicari adalah 10. Program melakukan iterasi melalui setiap elemen array secara berurutan menggunakan loop for. Jika nilai yang dicari ditemukan, variabel ketemu diatur menjadi true dan loop dihentikan. Setelah iterasi selesai, program menampilkan hasil pencarian, yaitu indeks di mana nilai tersebut pertama kali ditemukan atau pesan bahwa nilai tersebut tidak ada dalam array. Kode ini juga mencetak data array dan hasil pencarian ke layar.


### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search. ]

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```

Kode di atas digunakan untuk mencari suatu angka dalam array menggunakan algoritma Binary Search. Pertama, program mendeklarasikan array arrayData yang berisi 7 elemen acak. Pengguna diminta memasukkan angka yang ingin dicari (cari). Sebelum melakukan pencarian, array diurutkan menggunakan algoritma Selection Sort agar Binary Search dapat bekerja dengan benar. Setelah array diurutkan, program menampilkan array yang telah diurutkan dan melakukan pencarian menggunakan Binary Search. Jika angka yang dicari ditemukan, program akan menampilkan indeks di mana angka tersebut ditemukan; jika tidak, program akan menampilkan pesan bahwa angka tersebut tidak ditemukan.

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
// Lutfiana Isnaeni Lathifah 
// 2311102165

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(string kalimat, char huruf) {
    int low = 0;
    int high = kalimat.length() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (kalimat[mid] == huruf) {
            return mid;
        }
        else if (kalimat[mid] < huruf) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // jika huruf tidak ditemukan
}

int main() {
    string kalimat;
    char huruf;
    
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Mengubah kalimat menjadi huruf kecil agar penggunaan Binary Search menjadi valid
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengubah huruf yang ingin dicari menjadi huruf kecil
    huruf = tolower(huruf);

    // Melakukan pencarian dengan Binary Search
    int index = binarySearch(kalimat, huruf);

    if (index != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << index << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
} 
```


#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20ouput%20unguided%201.png)

Kode di atas digunakan untuk memasukkan sebuah kalimat dan sebuah huruf, dan kemudian melakukan pencarian menggunakan algoritma Binary Search untuk menemukan indeks pertama di mana huruf tersebut muncul dalam kalimat. Sebelum melakukan pencarian, program akan mengubah seluruh huruf dalam kalimat dan huruf yang ingin dicari menjadi huruf kecil agar pencarian berjalan dengan benar. Hasil pencarian akan ditampilkan kepada pengguna, menunjukkan apakah huruf tersebut ditemukan dan diindeks di mana dalam kalimat.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20full%20koding%20unguided%201.png)

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat! ]

```C++
// Lutfiana Isnaeni Lathifah 
// 2311102165

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungJumlahVokal(const string& teks) {
    int jumlahVokal = 0;
    for (char karakter : teks) {
        // Mengubah huruf menjadi huruf kecil untuk memudahkan perbandingan
        char hurufKecil = tolower(karakter);
        // Memeriksa apakah karakter tersebut adalah huruf vokal
        if (hurufKecil == 'a' || hurufKecil == 'e' || hurufKecil == 'i' || hurufKecil == 'o' || hurufKecil == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    string kalimat;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dalam kalimat
    int totalVokal = hitungJumlahVokal(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat adalah: " << totalVokal << endl;

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20output%20unguided%202.png)

Kode di atas digunakan untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. Program meminta pengguna untuk memasukkan sebuah kalimat, kemudian menggunakan fungsi untuk melakukan iterasi melalui setiap karakter dalam kalimat tersebut. Setiap karakter diubah menjadi huruf kecil untuk mempermudah perbandingan, dan jika karakter tersebut adalah salah satu dari huruf vokal ('a', 'e', 'i', 'o', atau 'u'), maka jumlah huruf vokal akan ditambahkan. Hasil akhirnya, yaitu jumlah huruf vokal dalam kalimat, ditampilkan kepada pengguna.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20full%20koding%20unguided%202.png)

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4dengan menggunakan algoritma Sequential Search!]

```C++
//Lutfiana Isnaeni Lathifah 
//2311102165

#include <iostream>

using namespace std;

// Fungsi untuk melakukan pencarian Sequential Search
int cariSequensial(int data[], int ukuran, int target) {
    int hitung = 0;
    for (int i = 0; i < ukuran; ++i) {
        if (data[i] == target) {
            hitung++;
        }
    }
    return hitung;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int ukuran = sizeof(data) / sizeof(data[0]);
    int target = 4;

    // Melakukan pencarian Sequential
    int jumlah = cariSequensial(data, ukuran, target);

    cout << "Banyaknya angka 4 dalam data adalah: " << jumlah << endl;

    return 0;
}
``` 

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20output%20unguided%203.png)

Kode di atas digunakan untuk melakukan pencarian berurutan (Sequential Search) dalam sebuah larik bilangan bulat untuk menghitung berapa kali suatu nilai tertentu muncul. Dalam contoh ini, program mencari berapa kali angka 4 muncul dalam larik bilangan bulat yang telah ditentukan.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%208/ss%20output/ss%20full%20koding%20unguided%203.png)




## Kesimpulan
 Algoritma pencarian adalah metode yang digunakan untuk menemukan elemen tertentu dalam kumpulan atau struktur data seperti array, daftar, atau pohon. Dua algoritma pencarian yang umum digunakan adalah Sequential Search dan Binary Search.

Sequential Search:

- Algoritma ini melakukan pencarian dengan cara membandingkan setiap elemen dalam data secara berurutan, mulai dari elemen pertama hingga elemen terakhir.
  Langkah-langkah Sequential Search meliputi: membandingkan elemen satu per satu dengan kata kunci yang dicari, melakukan pengulangan dari data pertama hingga data ke-n, dan menghentikan pencarian jika data ditemukan atau jika telah mencapai akhir data tanpa menemukan kecocokan.
  
- Sequential Search tidak memerlukan data yang terurut dan cocok digunakan untuk dataset yang kecil atau tidak terurut.

Binary Search:

- Binary Search digunakan pada data yang sudah terurut, baik secara ascending maupun descending.
  
- Algoritma ini bekerja dengan membagi data menjadi dua bagian dan menentukan arah pencarian berdasarkan perbandingan elemen tengah dengan elemen yang dicari. Proses ini berulang hingga data ditemukan atau dipastikan tidak ada dalam dataset.
  
- Binary Search lebih efisien dibandingkan Sequential Search untuk dataset yang besar dan terurut karena mengurangi jumlah perbandingan yang diperlukan.

Jadi Sequential Search dan Binary Search adalah dua metode pencarian yang memiliki kelebihan dan kekurangan masing-masing. Sequential Search sederhana dan tidak memerlukan data terurut, tetapi kurang efisien untuk dataset besar. Binary Search lebih efisien untuk dataset besar, namun hanya dapat digunakan pada data yang sudah terurut. Pemilihan algoritma tergantung pada kondisi data dan kebutuhan efisiensi pencarian.
## Referensi
[1]	Luthfi Delvian, “STRATEGI ALGORITMA - ALGORITMA PENCARIAN,” pp. 1–5, Jan. 2024.

[2]	C. P. P. S. D. T. I. Dian Markuci, “ANALISIS PERBANDINGAN PENGGUNAAN ALGORITMA SEQUENTIAL SEARCH DAN BINARY SEARCH PADA APLIKASI SURAT PERJALANAN DI,” vol. 6, pp. 110–119, Feb. 2022.

