# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Lutfiana Isnaeni Lathifah IF-11-E</p>

## Dasar Teori

Pengertian Tipe Data Array
Data Array adalah kumpulan-kumpulan variabel yang menyimpan data dengan tipe yang sama atau data-data yang tersusun secara linear dimana di dalamnya 
terdapat elemen dengan tipe yang sama. Indeks dalam array menyatakan elemen yang disimpan dan panjang atau length menyatakan total elemen yang tersimpan.
Indeks dari elemen array  dimulai dari 0. Dalam array, untuk membedakan satu variabel dengan variabel lain bedasarkan subscript, bilangan dalam kurung  siku[...]
disebut subscript. dengan subscript masing-masing elemen dapat diakses. Dalam menyusun fungsi array ada 3 struktur, yaitu kumpulan data dengan tipe sama, gunakan indeks
untuk mengakses setiap elemen, dan simpan di tempat yang bersambungan.

Berikut merupakan jenis-jenis array:

1. Array satu dimensi
   
   Array satu dimensi adalah jenis array dasar yang terdiri dari beberapa kolom elemen. Dalam satu baris tersusun dari beberapa elemen-elemen yang sama.
   Keunggulan dari array satu dimensi adalah mudah digunakan dan mudah dibaca sehingga paling umum digunakan. Perlu diingat elemen pertama ditandai dengan indeks 0,
   elemen keempat di indeks 3, dan seterusnya.

   TipeData NamaArray [jumlah elemen]

2. Array Dua Dimensi
   
   Array dua dimensi merupakan perluasan dari array satu dimensi sehingga array dua dimensi terdiri dari kolom dan baris atau berbentuk matrix. Maka harus perhatikan nomor baris dan kolom.

   TipeData NamaArray [jumlah baris][jumlah kolom]

   Contohnya algoritma [5][4] menyatakan nilai 5 berarti jumlah baris, nilai 4 berarti kolom. artinya array tersebut menampung 20 elemen. kelebihan dari array dua dimensi yaitu
   dapat menyimpan data yang lebih kompleks.

3. Array Multidimensi
   
   Array multidimensi digunakan untuk ke array yang lebih dari dua dimensi atau lebih. Bentuknya memiliki banyak dimensi sehingga untuk menentukan posisi elemen data tidak menggunakan
   indeks namun menggunakan key atau string. String merupakan array dari karakter. Dalam penulisan string menggunakan tanda petik ganda “…”, sedangkan karakter menggunakan tanda
   petik tunggal ‘…’. Pada string selalu diakhiri dengan angka nol dalam penulisan.

   TipeData NamaArray [Elemen1][Elemen2][Elemen3]

   Kegunaan Array adalah dapat menyelesaikan masalah matriks, mudah dalam menerapkan algoritma sorting, penjadwalan CPU, diterapkan sebagai tabel pencarian di komputer.

   
## Guided 


### 1. [Program Input Array 3 Dimensi]

```C++
#include <iostream>
using namespace std;
// PROGAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr [2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x <<"] [" << y <<"][" << z <<"] = ";
                cin >> arr [x] [y][z];
            }
        }
    }
    cout << endl;
    // Ouput array
    for (int x = 0; x<2; x++ )
    {
        for (int y=0; y<3; y++)
        {
            for (int z=0; z<3; z++)
            {
                cout << "Input Array[" << x <<"] [" << y <<"][" << z <<"] = " << arr [x][y][x] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;

    // Tampilkan array
    for (int x= 0; x <2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr [x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}

```

Kode di atas digunakan untuk memasukkan nilai ke dalam array tiga dimensi dan kemudian mencetak nilai tersebut. Di bagian main(), array tiga dimensi arr dideklarasikan dengan ukuran 2x3x3. 
Kemudian, terdapat dua loop bersarang untuk mengisi array tersebut dengan nilai yang dimasukkan oleh pengguna. Setelah itu, program mencetak nilai array tersebut.


### 2. [Mencari Nilai Maksimum Pada Array]

```C++

#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array [a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i= 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}

```

Kode di atas meminta pengguna untuk memasukkan panjang array, kemudian meminta pengguna untuk memasukkan sejumlah angka sesuai dengan panjang array yang telah ditentukan. 
Setelah semua angka dimasukkan, program akan mencari nilai maksimum dalam array tersebut beserta lokasinya, dan kemudian mencetak nilai maksimum beserta lokasinya tersebut.



## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user! Data Array: 1 2 3 4 5 6 7 8 9 10. Nomor genap: 2, 4, 6, 8, 10. Nomor Ganjil: 1, 3, 5, 7, 9]

```C++

#include <iostream>
using namespace std;
int main()
{
    // Deklarasi array
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Menampilkan data array 
    cout << "Data Array: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl << endl;

    //Menampilkan nomor genap
    cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++)
    {
        if (data [i] % 2 == 0)
        {
            cout << data [i] << ", ";

        }
    }
    cout << endl << endl;

    // Menampikan nomor ganjil 
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++)
    {
        if (data[i] % 2 == 1) 
        {
            cout << data[i] << ", ";
        }
    }
    cout << endl;

    return 0;
    }
```

#### Output:
![Screenshot 2024-03-18 143750](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/8c6ea58f-b01f-4204-932c-31858a292462)


Program di atas adalah penggunaan array dan loop dalam bahasa pemrograman C++. Pertama, program mendeklarasikan sebuah array yang
bernama `data` dengan panjang 10 dan menginisialisasinya dengan urutan angka dari 1 hingga 10. Setelah itu, program menampilkan isi array tersebut dengan menggunakan sebuah loop for.
Kemudian, program memulai loop pertama untuk mencetak nomor genap dari array `data`. Dalam loop ini, setiap elemen array diperiksa apakah genap atau tidak menggunakan operator modulo (%). Jika sisa pembagian elemen dengan 2 adalah 0, maka elemen tersebut dianggap sebagai nomor genap dan dicetak. Setelah itu, program mencetak garis baru untuk memisahkan output. Selanjutnya, program memulai loop kedua untuk mencetak nomor ganjil dari array `data`. Dalam loop ini, setiap elemen array diperiksa apakah ganjil atau tidak menggunakan operator modulo (%). Jika sisa pembagian elemen dengan 2 adalah
1, maka elemen tersebut dianggap sebagai nomor ganjil dan dicetak. Setelah mencetak semua nomor ganjil, program mengakhiri eksekusi.

#### code screenshot:
![Screenshot (34)](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/77ee45cb-e3ba-452c-a3b7-255f651466ca)


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user

```C++

#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel untuk menyimpan dimensi array
    int x_165, y_165, z_165;

    // Input dimensi array dari user
    cout << "Masukkan jumlah baris: ";
    cin >> x_165;
    cout << "Masukkan jumlah kolom: ";
    cin >> y_165;
    cout << "Masukkan panjang array: ";
    cin >> z_165;

    // Deklarasi array dengan dimensi yang diinputkan user
    int arr[x_165][y_165][z_165];

    // Input elemen array
    for (int i = 0; i < x_165; i++)
    {
        for (int j = 0; j < y_165; j++)
        {
            for (int k = 0; k < z_165; k++)
            {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
    // Output array
    cout << endl << "Data Array: " << endl;
    for (int i = 0; i < x_165; i++)
    {
        for (int j = 0;  j < y_165; j++)
        {
            for (int k = 0; k < z_165; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}

```

#### Output:
![Screenshot 2024-03-18 143348](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/f1e3d585-bd9a-4cc9-b365-93aba7de43ab)

Program diatas untuk memasukkan dimensi array tiga dimensi: jumlah baris, jumlah kolom, dan panjang array. Setelah menerima input dari pengguna, program mendeklarasikan array tiga dimensi dengan 
dimensi yang ditentukan. Kemudian, program meminta pengguna untuk memasukkan nilai-nilai elemen array satu per satu. Setelah semua elemen array diisi, program menampilkan isi array tersebut ke 
layar dalam format yang terstruktur sesuai dengan dimensinya. Program ini memanfaatkan nested loop untuk mengakses dan mengisi setiap elemen array sesuai dengan indeks baris, kolom, dan panjang yang sesuai.

#### code screenshot:
![Screenshot (33)](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/51f20f6e-4e6f-40d9-aa31-0055d4e06233)


### 3. [ Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++

#include <iostream>
using namespace std;
int main()
{
  int n_165;
  cout << "Masukkan jumlah elemen array: ";
  cin >> n_165;

  int arr[n_165];
  cout << "Masukkan elemen array: ";
  for (int i_165 = 0; i_165 < n_165; i_165++)
  {
    cin >> arr[i_165];
  }
  int max = arr[0], min = arr[0], jumlah = 0;
  for (int i_165 = 1; i_165 < n_165; i_165++)
  {
    if (arr[i_165] > max)
    {
      max = arr[i_165];
    }
    if (arr[i_165] < min)
    {
      min = arr[i_165];
    }
    jumlah += arr[i_165];
  }
  float rata = (float) jumlah /n_165;
  cout << "Nilai maksimum: " << max << endl;
  cout << "Nilai minimum: " << min << endl;
  cout << "Nilai rata-rata: " << rata << endl;

  return 0;
}

```

#### Output:
![Screenshot 2024-03-18 142813](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/92c38503-2c00-4d38-b2de-2bc0f28fead8)


Program diatas adalah contoh sederhana dari sebuah program C++ yang meminta pengguna untuk memasukkan sejumlah elemen array, dan kemudian melakukan beberapa operasi untuk menemukan nilai maksimum, nilai minimum, dan rata-rata dari elemen-elemen tersebut.

Pertama-tama, program meminta pengguna untuk memasukkan jumlah elemen array melalui pesan "Masukkan jumlah elemen array:". Setelah itu, pengguna diminta untuk memasukkan nilai-nilai elemen array satu per satu.
Kemudian, program melakukan iterasi melalui array yang telah diisi, mencari nilai maksimum dan minimum, serta menghitung jumlah total dari semua elemen array.

Setelah nilai-nilai tersebut ditemukan, program menghitung rata-rata dengan cara membagi jumlah total elemen dengan jumlah elemen array.

Akhirnya, program menampilkan nilai maksimum, nilai minimum, dan nilai rata-rata menggunakan perintah cout.


#### code Screenshot:
![Screenshot (32)](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/assets/162521063/1ef3fafb-a466-4c4f-943a-639bd54d9b37)


## Kesimpulan
Array adalah struktur data yang menyimpan kumpulan elemen dengan tipe data yang sama atau tersusun secara linear. Setiap elemen dalam array diakses melalui indeks yang dimulai dari 0, dan panjang array menunjukkan jumlah total elemen yang tersimpan.

Jenis-jenis array meliputi:

1. Array satu dimensi, yang terdiri dari satu baris elemen dengan indeks dimulai dari 0.

2. Array dua dimensi, yang terdiri dari baris dan kolom, membentuk matriks.

3. Array multidimensi, yang memiliki lebih dari dua dimensi dan menggunakan key atau string untuk menentukan posisi elemen data.

Kelebihan array termasuk kemampuannya untuk menyimpan data yang kompleks, seperti dalam matriks, serta kemudahannya dalam penerapan algoritma sorting dan penjadwalan CPU. Array juga dapat digunakan sebagai tabel pencarian di dalam komputer.
## Referensi
https://itbox.id/blog/array-adalah/
