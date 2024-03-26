# <h1 align="center">Laporan Praktikum Modul 3 Single And Double Linked</h1>
<p align="center">Lutfiana Isnaeni Lathifah</p>
<p align="center">IF-11-E</p>
<p align="center">2311102165</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Latihan Single Linked List]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

Program ini mendefinisikan sebuah struct Node yang memiliki dua anggota: data untuk menyimpan nilai integer, dan next untuk menunjukkan ke node berikutnya dalam linked list. Selain itu, program juga mendeklarasikan dua pointer global, head dan tail, yang menunjukkan kepala (elemen pertama) dan ekor (elemen terakhir) dari linked list.
Program ini menyediakan sejumlah fungsi untuk melakukan operasi pada linked list, seperti menambah elemen di depan (insertDepan), menambah elemen di belakang (insertBelakang), menambah elemen di tengah pada posisi tertentu (insertTengah), menghapus elemen di depan (hapusDepan), menghapus elemen di belakang (hapusBelakang), menghapus elemen di tengah pada posisi tertentu (hapusTengah), mengubah nilai elemen di depan (ubahDepan), mengubah nilai elemen di belakang (ubahBelakang), mengubah nilai elemen di tengah pada posisi tertentu (ubahTengah), menghitung jumlah elemen dalam linked list (hitungList), menampilkan seluruh elemen dalam linked list (tampil), dan menghapus seluruh elemen dari linked list (clearList).
Di dalam fungsi main, program ini menginisialisasi linked list, kemudian melakukan sejumlah operasi seperti menambah, menghapus, dan mengubah elemen-elemen dalam linked list, serta menampilkan hasilnya dengan menggunakan fungsi tampil. Setiap operasi dijalankan sesuai dengan fungsi yang telah didefinisikan sebelumnya.

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/guided1.png)

## Guided 2

### 2. [Latihan Double Lingked List]

```C++

#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas adalah implementasi dari sebuah Double Linked List. Double Linked List adalah struktur data linear di mana setiap elemen disimpan dalam bentuk node yang memiliki dua pointer, yaitu pointer ke node sebelumnya (prev) dan pointer ke node selanjutnya (next). 
Node mendefinisikan sebuah simpul dalam linked list dengan tiga anggota: data untuk menyimpan nilai data, prev untuk menunjukkan ke simpul sebelumnya, dan next untuk menunjukkan ke simpul selanjutnya. Kelas DoublyLinkedList menyediakan berbagai operasi untuk memanipulasi data dalam linked list, seperti menambahkan elemen di awal (metode push), menghapus elemen di awal (metode pop), mengupdate nilai data (metode update), menghapus semua elemen (metode deleteAll), dan menampilkan isi linked list (metode display).
Fungsi main() merupakan penggunaan dari kelas DoublyLinkedList, di mana pengguna diberikan opsi untuk melakukan berbagai operasi pada linked list seperti menambah, menghapus, mengupdate, menghapus semua elemen, dan menampilkan isi linked list. Program akan terus berjalan sampai pengguna memilih opsi untuk keluar. Ini adalah contoh penggunaan praktis dari Doubly Linked List untuk manajemen data dinamis dalam sebuah program.

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/guided2.png)

## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputandari user. Lakukan operasi berikut: a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda. lutfiana 20, John 19, Jane 20, Michael 18, Yusuke 19, Akechi 20, Hoshino 18, Karin 18 b. Hapus data Akechic. Tambahkan data berikut diantara John dan Jane : Futaba 18 d. Tambahkan data berikut diawal : Igor 20 e. Ubah data Michael menjadi : Reyn 18 f. Tampilkan seluruh data]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
using namespace std;

// Node structure
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Class untuk Single Linked List
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Fungsi untuk menyisipkan node di awal
    void insertAwal(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menyisipkan node di belakang
    void insertBelakang(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menyisipkan node di antara dua node
    void insertTengah(string nama, int usia, string nama_sebelum, string nama_setelah) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->nama == nama_sebelum && temp->next->nama == nama_setelah) {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Fungsi untuk menghapus node dengan nama tertentu
    void hapus(string nama) {
        if (head == NULL) {
            cout << "Linked List kosong" << endl;
            return;
        }

        if (head->nama == nama) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->nama == nama) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Data tidak ditemukan" << endl;
    }

   void ubahData(string nama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            temp->nama = namaBaru;
            temp->usia = usiaBaru;
        }
    }

    // Fungsi untuk menampilkan seluruh data
    void tampilkan() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    

    // Masukkan data sesuai urutan
    list.insertAwal("lutfiana", 20);
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    // Hapus data Akechi
    list.hapus("Akechi");

    // Tambahkan data di antara John dan Jane
    list.insertTengah("Futaba", 18, "John", "Jane");

    // Tambahkan data di awal
    list.insertAwal("Igor", 20);

    // Ubah data Michael
    list.ubahData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    list.tampilkan();

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/unguided1.png)

Program di atas mendefinisikan sebuah struktur data Node yang menyimpan informasi tentang nama dan usia seseorang serta alamat dari node berikutnya. Selain itu, terdapat kelas LinkedList yang memiliki beberapa fungsi untuk manipulasi linked list, seperti menyisipkan node di awal, di belakang, di antara dua node, menghapus node berdasarkan nama, mengubah data node berdasarkan nama, dan menampilkan seluruh data dalam linked list. Dalam main() function, linked list dibuat dan diisi dengan beberapa data. Kemudian, beberapa operasi dilakukan seperti penghapusan data, penambahan data di antara dua node tertentu, penambahan data di awal, dan pengubahan data. Hasil akhir dari operasi-operasi tersebut kemudian ditampilkan.
## Unguided 

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga. Nama Produk Harga Originote 60.000 Somethinc 150.000 Skintific 100.000 Wardah 50.000 Hanasui 30.000 Case: 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific 2. Hapus produk wardah 3. Update produk Hanasui menjadi Cleora dengan harga 55.000 4. Tampilkan menu seperti dibawah ini Toko Skincare Purwokerto 1. Tambah Data 2. Hapus Data 3. Update Data 4. Tambah Data Urutan Tertentu 5. Hapus Data Urutan Tertentu 6. Hapus Seluruh Data 7. Tampilkan Data 8. Exit Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini : Nama Produk Harga Originote 60.000 Somethinc 150.000 Azarine 65.000 Skintific 100.000 Cleora 55.00]


```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void tambahData(string nama, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string nama)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                if (current == head && current == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else if (current == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void updateData(string nama, string newNama, int newHarga)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                current->namaProduk = newNama;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void tambahDataUrutanTertentu(string nama, int harga, string namaSebelum, string namaSesudah)
    {
        Node *newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == namaSebelum)
            {
                newNode->prev = current;
                newNode->next = current->next;
                current->next = newNode;
                if (newNode->next != NULL)
                {
                    newNode->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }
                return;
            }
            if (current->namaProduk == namaSesudah && current->next != NULL)
            {
                newNode->prev = current;
                newNode->next = current->next;
                current->next = newNode;
                newNode->next->prev = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void hapusDataUrutanTertentu(string nama)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->namaProduk == nama)
            {
                if (current == head && current == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else if (current == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else if (current == tail)
                {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void hapusSeluruhData()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void tampilkanData()
    {
        Node *current = head;
        cout << "Nama Produk Harga" << endl;
        while (current != NULL)
        {
            cout << current->namaProduk << " " << current->harga << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList linkedList;

    int pilihan;
    string nama, newName, namaSebelum, namaSesudah;
    double harga, newHarga;

    linkedList.tambahData("Originote", 60000);
    linkedList.tambahData("Somethinc", 150000);
    linkedList.tambahData("Skintific", 100000);
    linkedList.tambahData("Wardah", 50000);
    linkedList.tambahData("Hanasui", 30000);

    do
    {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukan menu pilihan anda : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            linkedList.tambahData(nama, harga);
            linkedList.tampilkanData();
            break;
        case 2:
            cout << "Nama Produk yang akan dihapus: ";
            cin >> nama;
            linkedList.hapusData(nama);
            break;
        case 3:
            cout << "Nama Produk yang akan diupdate: ";
            cin >> nama;
            cout << "Nama Baru: ";
            cin >> newName;
            cout << "Harga Baru: ";
            cin >> newHarga;
            linkedList.updateData(nama, newName, newHarga);
            linkedList.tampilkanData();
            break;
        case 4:
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            cout << "Produk Sebelumnya: ";
            cin >> namaSebelum;
            cout << "Produk Setelahnya: ";
            cin >> namaSesudah;
            linkedList.tambahDataUrutanTertentu(nama, harga, namaSebelum, namaSesudah);
            linkedList.tampilkanData();
            break;
        case 5:
            cout << "Nama Produk yang akan dihapus: ";
            cin >> nama;
            linkedList.hapusDataUrutanTertentu(nama);
            linkedList.tampilkanData();
            break;
        case 6:
            linkedList.hapusSeluruhData();
            cout << "Seluruh data telah dihapus." << endl;
            break;
        case 7:
            linkedList.tampilkanData();
            break;
        default:
            cout << "Exit" << endl;
        }
    } while (pilihan != 7);
    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/unguided2.1.png)

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/unguided2.2.png)

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/unguided2.3.png)


![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%203/img/unguided2.4.png)


Program ini adalah sebuah simulasi dari aplikasi toko skincare di Purwokerto yang memungkinkan pengguna untuk melakukan berbagai operasi seperti menambah, menghapus, mengupdate data produk, serta menghapus seluruh data atau menampilkan seluruh produk yang tersedia. Struktur data utamanya adalah Node, yang memiliki informasi tentang nama produk dan harga, serta dua pointer yang menunjuk ke node sebelumnya dan node selanjutnya dalam linked list. Kelas LinkedList mengatur operasi-operasi seperti penambahan data, penghapusan data, pembaruan data, dan operasi khusus seperti penambahan data pada urutan tertentu atau penghapusan data pada urutan tertentu. Dalam main() function, program memulai dengan membuat objek dari kelas LinkedList dan memasukkan beberapa data produk skincare sebagai contoh awal. Kemudian, program meminta input dari pengguna untuk melakukan operasi-operasi yang diinginkan, seperti menambah data baru, menghapus data, mengupdate data, dan lain-lain, dan kemudian menampilkan hasilnya. Perulangan do-while memungkinkan pengguna untuk terus melakukan operasi hingga memilih untuk keluar dari program dengan memilih opsi "Exit".




## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
