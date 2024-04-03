# <h1 align="center">Laporan Praktikum Modul 4 LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
<p align="center">Lutfiana Isnaeni Lathifah
  2311102165</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Linked List Non Circular]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>

using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/outputguided1.png)

Kode di atas digunakan untuk membuat dan mengelola sebuah linked list non circular. Program ini menyediakan berbagai fungsi seperti menambahkan elemen di depan, di belakang, di tengah, menghapus elemen di depan, di belakang, di tengah, mengubah nilai elemen di depan, di belakang, atau di tengah, menghitung jumlah elemen dalam list, serta membersihkan seluruh isi list.

### 2. [Linked List Circular]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>

using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
    /// @brief 
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
    head = NULL;
    tail = head;
}
// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}
// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}
// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}
// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}
// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/ssunguided2.png)

Kode di atas digunakan untuk mengimplementasikan operasi dasar pada sebuah single linked list circular yang mencakup operasi seperti penambahan elemen di depan, di belakang, di tengah, penghapusan elemen di depan, di belakang, dan di tengah, serta operasi lain seperti membersihkan seluruh list dan menampilkan isi list.

## Unguided 

### 1. [1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1: • Tampilan Menu: PROGRAM SINGLE LINKED LIST NON-CIRCULAR 1. Tambah Depan 2. Tambah Belakang 3. Tambah Tengah 4. Ubah Depan 5. Ubah Belakang 6. Ubah Tengah 7. Hapus Depan 8. Hapus Belakang 9. Hapus Tengah 10. Hapus List 11. TAMPILKAN 0. KELUAR Pilih Operasi : • Tampilan Operasi Tambah: -Tambah DepanMasukkan Nama : Masukkan NIM : Data telah ditambahkan -Tambah TengahMasukkan Nama : Masukkan NIM : Masukkan Posisi :Data telah ditambahkan • Tampilan Operasi Hapus: -Hapus BelakangData (nama mahasiswa yang dihapus) berhasil dihapus -Hapus TengahMasukkan posisi : Data (nama mahasiswa yang dihapus) berhasil dihapus • Tampilan Operasi Ubah: -Ubah BelakangMasukkan nama : Masukkan NIM : Data (nama lama) telah diganti dengan data (nama baru) -Ubah BelakangMasukkan nama : Masukkan NIM : Masukkan posisi : Data (nama lama) telah diganti dengan data (nama baru) • Tampilan Operasi Tampil Data: DATA MAHASISWA NAMA NIM Nama1 NIM1 Nama2 NIM2 >>> ke 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) Nama NIM Jawad 23300001 [Nama Anda] [NIM Anda] Farrel 23300003 Denis 23300005 Anis 23300008 Bowo 23300015 Gahar 23300040 Udin 23300048 Ucok 23300050 Budi 23300099 >>> ke 3. Lakukan perintah berikut: a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 b) Hapus data Denis c) Tambahkan data berikut di awal: Owi 2330000 d) Tambahkan data berikut di akhir: David 23300100 e) Ubah data Udin menjadi data berikut: Idin 23300045 f) Ubah data terkahir menjadi berikut: Lucy 23300101 g) Hapus data awal h) Ubah data awal menjadi berikut: Bagas 2330002 i) Hapus data akhir j) Tampilkan seluruh data]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
#include <string>

using namespace std;

// Struktur node untuk Linked List
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Class untuk Linked List Circular
class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Fungsi untuk menambahkan node di depan
    void tambahDepan(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Data telah ditambahkan." << endl;
    }

    // Fungsi untuk menambahkan node di belakang
    void tambahBelakang(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Fungsi untuk menambahkan node di tengah
    void tambahTengah(string nama, string nim, string posisi_nama) {
        if (head == nullptr) {
            cout << "Linked List masih kosong, tidak dapat menambahkan di tengah." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;

        Node* temp = head;
        while (temp->nama != posisi_nama && temp->next != head) {
            temp = temp->next;
        }

        if (temp->next == head && temp->nama != posisi_nama) {
            cout << "Data tidak ditemukan, tidak dapat menambahkan di tengah." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Data telah ditambahkan." << endl;
    }

    // Fungsi untuk menghapus node dari depan
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked List kosong, tidak ada yang dihapus." << endl;
            return;
        }

        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
        delete temp;

        cout << "Data pertama telah dihapus." << endl;
    }

    // Fungsi untuk menghapus node dari belakang
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked List kosong, tidak ada yang dihapus." << endl;
            return;
        }

        Node* temp = head;
        Node* last = nullptr;
        while (temp->next != head) {
            last = temp;
            temp = temp->next;
        }

        if (last != nullptr) {
            last->next = head;
        } else {
            head = nullptr;
        }
        delete temp;

        cout << "Data terakhir telah dihapus." << endl;
    }

    // Fungsi untuk menghapus node dari tengah
    void hapusTengah(string nama) {
        if (head == nullptr) {
            cout << "Linked List masih kosong, tidak ada yang dihapus." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->nama != nama && temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == head && temp->nama != nama) {
            cout << "Data tidak ditemukan, tidak ada yang dihapus." << endl;
            return;
        }

        if (prev != nullptr) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }
        delete temp;

        cout << "Data " << nama << " telah dihapus." << endl;
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

    // Fungsi untuk mengubah data
    void ubahData(string nama_lama, string nama_baru, string nim_baru) {
        if (head == nullptr) {
            cout << "Linked List kosong, tidak ada yang diubah." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->nama != nama_lama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data tidak ditemukan, tidak ada yang diubah." << endl;
            return;
        }

        temp->nama = nama_baru;
        temp->nim = nim_baru;

        cout << "Data " << nama_lama << " telah diubah menjadi " << nama_baru << "." << endl;
    }

    // Fungsi untuk menampilkan data
    void tampilkan() {
        if (head == nullptr) {
            cout << "Linked List kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        do {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp
             = temp->next;
        } while (temp != head);
    }
};

int main() {
    LinkedList linkedList;
    int operasi;
    string nama, nim, posisi_nama;
    string nama_lama, nama_baru, nim_baru;


    do {
        // Menampilkan menu
        cout << endl << "PROGRAM SINGLE LINKED LIST CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi: ";
        cin >> operasi;

        switch (operasi) {
                 case 1:
                cout << "Masukkan Nama dan NIM mahasiswa:" << endl;
                cout << "- Tambah Depan" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NIM: ";
                cin >> nim;
                linkedList.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama dan NIM mahasiswa:" << endl;
                cout << "- Tambah Belakang" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NIM: ";
                cin >> nim;
                linkedList.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama dan NIM mahasiswa:" << endl;
                cout << "- Tambah Tengah" << endl;
                cout << "Nama: ";
                cin >> nama;
                cout << "NIM: ";
                cin >> nim;
                cout << "Masukkan Nama Posisi: ";
                cin >> posisi_nama;
                linkedList.tambahTengah(nama, nim, posisi_nama);
                break;
            case 4:
                cout << "Masukkan Nama Baru dan NIM baru:" << endl;
                cout << "- Ubah Depan" << endl;
                cout << "Nama Baru: ";
                cin >> nama_baru;
                cout << "NIM Baru: ";
                cin >> nim_baru;
                cout << "Nama diubah : ";
                cin >> nama_lama;
                linkedList.ubahData(nama_lama, nama_baru, nim_baru);
                break;
            case 5:
                cout << "Masukkan Nama Baru dan NIM baru:" << endl;
                cout << "- Ubah Belakang" << endl;
                cout << "Nama Baru: ";
                cin >> nama_baru;
                cout << "NIM Baru: ";
                cin >> nim_baru;
                cout << "Nama yang diubah : ";
                cin >> nama_lama;
                linkedList.ubahData(nama_lama, nama_baru, nim_baru);
                break;
            case 6:
                cout << "Masukkan Nama Baru dan NIM baru:" << endl;
                cout << "- Ubah Tengah" << endl;
                cout << "Nama Baru: ";
                cin >> nama;
                cout << "NIM Baru: ";
                cin >> nim;
                cout << "Masukkan Nama Posisi: ";
                cin >> posisi_nama;
                linkedList.ubahData(posisi_nama, nama, nim);
                break;
            case 7:
                cout << "- Hapus Depan" << endl;
                linkedList.hapusDepan();
                break;
            case 8:
                cout << "- Hapus Belakang" << endl;
                linkedList.hapusBelakang();
                break;
            case 9:
                cout << "- Hapus Tengah" << endl;
                cout << "Masukkan Nama untuk dihapus: ";
                cin >> nama;
                linkedList.hapusTengah(nama);
                break;
            case 10:
                cout << "- Hapus List" << endl;
                // Kosongkan seluruh list
                linkedList.hapusSeluruhData();
                cout << "Seluruh list telah dihapus." << endl;
                break;
            case 11:
                cout << "- TAMPILKAN" << endl;
                linkedList.tampilkan();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (operasi != 0);

    return 0;
}



```
#### Output:
Output di bawah merupakan output no 1 menu tambah depan
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%201.1.png)

Output di bawah merupakan output menu tambah belakang
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%201.2.png)

Output di bawah merupakan output menu tambah tengah

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%201.3.png)

Output di bawah merupakan output menu ubah depan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.h%20dan%201.4.png)

Output di bawah merupakan output menu ubah belakang

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.f%20dan%201.5.png)

Output di bawah merupakan output menu ubah tengah

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.e%20dan%201.6.png)

Output di bawah merupakan output menu hapus depan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.g%20dan%201.7.png)

Output di bawah merupakan output menu hapus belakang

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.i%20dan%201.8.png)

Output di bawah merupakan output menu hapus tengah 

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.b%20dan%201.9.png)

Output di bawah merupakan output  no 2 menu tampilkan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%202.png)

Output di bawah merupakan output no 3 menu tambah tengah

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.1%20dan%201.3.png)

Output di bawah merupakan output menu hapus tengah

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.b%20dan%201.9.png)

Output di bawah merupakan output menu tambah depan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.c%20dan%201.1.png)

Output di bawah merupakan output menu tambah belakang

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.d%20dan%201.2.png)

Output di bawah merupakan output menu ubah tengah

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.e%20dan%201.6.png)

Output di bawah merupakan output menu ubah belakang

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.f%20dan%201.5.png)

Output di bawah merupakan output menu hapus depan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.g%20dan%201.7.png)

Output di bawah merupakan output menu ubah depan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.h%20dan%201.4.png)

Output di bawah merupakan output menu hapus belakang

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.i%20dan%201.8.png)

Output di bawah merupakan output menu tampilkan

![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/unguided%20output%203.j.png)




Kode di atas merupakan single Linked List Circular untuk menyimpan informasi tentang mahasiswa. Program ini memberikan pengguna kemampuan untuk melakukan berbagai operasi, seperti menambahkan, mengubah, dan menghapus data mahasiswa, serta menampilkan seluruh data yang tersimpan. Program ini menyediakan menu interaktif yang memungkinkan pengguna untuk memilih operasi yang ingin dilakukan. Operasi-operasi tersebut meliputi penambahan data mahasiswa di depan, di belakang, atau di tengah linked list berdasarkan posisi tertentu, pengubahan data mahasiswa yang sudah ada, penghapusan data mahasiswa, baik di depan, di belakang, atau di tengah linked list, serta penghapusan seluruh data yang tersimpan. Linked List Circular yang digunakan di sini, di mana node terakhir dihubungkan kembali ke node pertama, sehingga membentuk suatu siklus untuk memastikan bahwa tidak ada node yang menunjuk ke NULL, sehingga seluruh data terhubung secara terus-menerus dalam linked list. Dengan menggunakan program ini, pengguna dapat dengan mudah mengelola informasi tentang mahasiswa dan melakukan berbagai manipulasi data sesuai kebutuhan mereka.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%204/img/ssunguided.png)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
