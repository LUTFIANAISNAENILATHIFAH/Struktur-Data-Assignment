# <h1 align="center">Laporan Praktikum Modul 5 Hash Table</h1>
<p align="center">  Lutfiana Isnaeni Lathifah 
2311102165
</p>

## Dasar Teori

a)	Pengertian Hash Table
Hash table adalah sebuah struktur data yang terdiri atas sebuah tabel dan fungsi yang bertujuan untuk memetakan nilai kunci yang unik untuk setiap record menjadi angka (hash) lokasi record tersebut dalam sebuah tabel. 

Keunggulan dari struktur hash table ini adalah waktu aksesnya yang cukup cepat, jika record yang dicari langsung berada pada angka hash lokasi penyimpanannya. Akan tetapi pada kenyataannya sering sekali ditemukan hash table yang recordrecordnya mempunyai angka hash yang sama (bertabrakan).

Karena pemetaan hash function yang digunakan bukanlah pemetaan satu-satu, (antara dua record yang tidak sama dapat dibangkitkan angka hash yang sama) maka dapat terjadi bentrokan (collision) dalam penempatan suatu data record. Untuk mengatasi hal ini, maka perlu diterapkan kebijakan resolusi bentrokan (collision resolution policy) untuk menentukan lokasi record dalam tabel. Umumnya kebijakan resolusi bentrokan adalah dengan mencari lokasi tabel yang masih kosong pada lokasi setelah lokasi yang berbentrokan. 

Hash table menggunakan memori penyimpanan utama berbentuk array dengan tambahan algoritma untuk mempercepat pemrosesan data. Pada intinya hash table merupakan penyimpanan data menggunakan key value yang didapat dari nilai data itu sendiri. Dengan key value tersebut didapat hash value. Jadi hash function merupakan suatu fungsi sederhana untuk mendapatkan hash value dari key value suatu data. Yang perlu diperhatikan untuk membuat hash function adalah ukuran array/table size(m), key value/nilai yang didapat dari data(k), hash value/hash index/indeks yang dituju(h)[1]


b)	Fungsi Hash Table Pada Data

1.	Pencarian Cepat: Dapat digunakan untuk mencari data dengan cepat berdasarkan key. Ini sangat berguna dalam aplikasi seperti basis data, kamus, dan cache.

2.	Penyimpanan Data: Hash table dapat digunakan untuk menyimpan data dengan efisien. Data dapat diambil dan dimasukkan ke dalam tabel dengan waktu konstan, asalkan tidak ada collision yang signifikan.
3.	Implementasi Struktur Data Lain: Hash table dapat digunakan untuk mengimplementasikan struktur data lain, seperti set dan map.

c)	Teknik-Teknik Hash Table 

Dalam praktiknya, sedidaknya ada dua teknik umum yang digunakan saat data scientist melakukan hash table. Berikut penjelasannya:

1.	Hashing

Hashing merupakan sebuah proses mengganti kunci yang diberikan atau string karakter menjadi nilai lain. Penggunaan hashing paling populer adalah pada hash table. Hash table menyimpan pasangan kunci dan nilai dalam daftar yang dapat diakses melalui indeksnya. Karena pasangan kunci dan nilai tidak terbatas, maka fungsinya akan memetakan kunci ke ukuran tabel dan kemudian nilainya menjadi indeks untuk elemen tertentu.

2.	Linear Probing

Linear probing merupakan skema dalam pemrograman komputer untuk menyelesaikan collision pada hash table. Dalam skema ini, setiap sel dari hash table menyimpan satu pasangan kunci-nilai. Saat fungsi hash menyebabkan collision dengan memetakan kunci baru ke sel hash table yang sudah ditempati oleh kunci lain, maka linear probing akan mencari tabel untuk lokasi bebas terdekat dan menyisipkan kunci baru. 
Pencarian dilakukan dengan cara yang sama, yaitu dengan mencari tabel secara berurutan, mulai dari posisi yang diberikan oleh fungsi hash, hingga menemukan sel dengan kunci yang cocok atau sel kosong. Hash table adalah struktur data non trivial yang paling umum digunakan. Linear probing dapat memberikan kinerja tinggi karena lokasi referensi yang baik, namun lebih sensitif terhadap kualitas fungsi hash daripada beberapa skema resolusi collision lainnya.

d)	Operasi dalam Stuktur Data Hash Table

1.	Pencarian (Search): Digunakan untuk mencari elemen/data dalam Hash Table berdasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.
2.	Penyisipan (Insertion): Operasi ini digunakan untuk menyisipkan elemen/data baru ke dalam Hash Table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.

3.	Penghapusan (Deletion): Digunakan untuk menghapus elemen/data dari Hash Table berdasarkan kunci atau indeksnya. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.

4.	Update: Operasi ini digunakan untuk mengubah nilai elemen/data yang sudah ada dalam Hash Table. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.

5.	Collision Handling: Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk menangani collision dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.

6.	Resize: Operasi ini digunakan untuk mengubah ukuran Hash Table jika jumlah elemen/data yang disimpan melebihi kapasitas yang ditentukan. Resize dilakukan untuk menjaga efisiensi dan kinerja Hash Table.

7.	Iterasi: Operasi yang digunakan untuk mengakses dan memproses semua elemen/data yang ada dalam Hash Table secara berurutan [2].
















## Guided 

### 1. [Guided 1]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```

Kode di atas adalah implementasi sederhana dari struktur data hash table dengan metode chaining untuk mengatasi kolisi. Hash table memungkinkan penyimpanan dan pencarian 
data efisien berdasarkan kunci. Metode chaining digunakan untuk menangani kolisi. Operasi dasar seperti insertion, searching, deletion, dan traversal diimplementasikan dalam kelas HashTable.


### 2. [Guided 2]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

Kode di atas digunakan  untuk menyimpan nomor telepon berdasarkan nama karyawan. Ini menggunakan vektor sebagai tabel hash, dengan setiap entri berisi 
vektor node hash yang menyimpan nama dan nomor telepon karyawan. Kelas HashMap memiliki metode untuk insertion, removal, searching berdasarkan nama, 
dan print isi hash table. Dalam main, data karyawan dimasukkan, dicari, dan dihapus dari hash table, dengan hasilnya dicetak.


## Unguided 

### 1. [Soal]

C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Hash table adalah struktur data yang memanfaatkan fungsi hash untuk memetakan kunci unik ke dalam tabel, memungkinkan akses cepat ke data berdasarkan kuncinya. Meskipun efisien, collision bisa terjadi jika dua kunci memiliki nilai hash yang sama. Untuk menangani collision, teknik seperti linear probing digunakan. Operasi dasar dalam hash table meliputi pencarian, penyisipan, penghapusan, dan update, sambil memperhatikan penanganan collision, resize, dan iterasi untuk mengelola data secara efisien.

## Referensi
[1]	Fajar Baskoro, “Hash Table,” Jul. 2021.

[2]	Annisa, “Struktur Data Hash Table: Pengertian, Cara Kerja dan Operasi Hash Table,” Sep. 2023.
 


