# <h1 align="center">Laporan Praktikum Modul VII QUEUE</h1>
<p align="center">Lutfiana Isnaeni Lathifah 2311102165</p>

## Dasar Teori
Queue disebut juga antrian dimana data masuk di satu sisi dan keluar di sisi yang lain. Karena  itu, queue bersifat FIFO (FirstIn FirstOut). Antrian (Queue) merupakan suatu kumpulan data yang penambahan elemennya (masuk antrian) hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang/rear) atau disebut juga enqueue yaitu apabila seseorang masuk ke dalam sebuah antrian. Jika seseorang keluar dari antrian/penghapusan (pengembalian elemen) dilakukan lewat ujung yang lain (disebut dengan sisi depan/front) atau disebut juga dequeue yaitu apabila seseorang keluar dari antrian. Jadi, dalam antrian menggunakan prinsip “masuk pertama keluar pertama” atau disebut juga dengan prinsip FIFO (first in first out). Dengan kata lain, urutan keluar akan sama dengan urutan masuknya [1].

Sistem antrian adalah teori yang menyangkut studi matematis dari antrian–antrian atau baris–baris penungguan. Formasi baris–baris penungguan ini tentu saja merupakan suatu pelayanan melebihi kapasitas yang tersedia apabila kebutuhan akan suatu pelayanan melebihi kapasitas yang tersedia untuk menyelenggarakan pelayanan itu [2].

## Guided 

### 1. [Guided]

```C++
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

Kode di atas digunakan untuk mengelola antrian (queue) sederhana menggunakan array. Antrian ini dapat menampung hingga lima 
Antrian ini dapat menampung hingga lima elemen dan memiliki beberapa fungsi dasar untuk pengelolaan antrian. Fungsi-fungsi 
tersebut meliputi isFull() untuk memeriksa apakah antrian penuh, isEmpty() untuk memeriksa apakah antrian kosong, enqueueAntrian(string data) untuk
menambahkan elemen ke antrian jika tidak penuh, dan dequeueAntrian() untuk menghapus elemen paling depan dari antrian jika tidak kosong. Selain itu, terdapat 
fungsi countQueue() yang menghitung jumlah elemen dalam antrian, clearQueue() yang menghapus semua elemen dalam antrian, dan viewQueue() 
yang menampilkan semua elemen dalam antrian beserta posisinya. Kode ini juga mendemonstrasikan penggunaan fungsi-fungsi tersebut dalam fungsi main()
engan menambahkan elemen, menampilkan isi antrian, menghitung jumlah elemen, menghapus elemen, dan menghapus semua elemen dari antrian. Secara keseluruhan, 
kode ini menunjukkan cara dasar untuk mengelola antrian menggunakan array dan menyediakan antarmuka untuk berinteraksi dengan antrian tersebut melalui berbagai 
operasi yang umum digunakan. 

## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
// Lutfiana Isnaeni Lathifah 
// 2311102165

#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data dan referensi ke node berikutnya
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isFull() {
        // Antrian berbasis linked list tidak pernah penuh kecuali kehabisan memori
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue data:" << endl;
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
        if (i == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Andi");
    q.enqueue("Maya");
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%207/img/ss%20output%20unguided%201.png)

Kode di atas digunakan untuk mengimplementasikan struktur data antrian (queue) menggunakan linked list. Kelas Queue didefinisikan dengan dua
pointer, head dan tail, untuk melacak awal dan akhir antrian. Fungsi enqueue menambahkan elemen baru ke akhir antrian. Jika antrian kosong, elemen baru 
menjadi elemen pertama dan terakhir; jika tidak, elemen baru ditambahkan di akhir. Fungsi dequeue menghapus elemen dari depan antrian, memperbarui head, dan 
jika antrian kosong setelah penghapusan, tail diatur menjadi nullptr. Metode isEmpty digunakan untuk memeriksa apakah antrian kosong, sedangkan count 
menghitung jumlah elemen dalam antrian dengan iterasi dari head ke tail. Metode clear mengosongkan antrian dengan menghapus semua elemen menggunakan
dequeue. Metode view mencetak semua elemen dalam antrian dari depan ke belakang, dan mencetak "(empty)" jika antrian kosong. Dalam fungsi main, 
beberapa operasi dasar antrian diuji: menambahkan elemen, menghapus elemen, menampilkan elemen, dan menghitung ukuran antrian untuk memastikan semua 
fungsi bekerja dengan benar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%207/img/ss%20full%20program%20unguided1.png)

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
// Lutfiana Isnaeni Lathifah
// 2311102165

#include <iostream>
using namespace std;

struct Node {
    string nama; // Nama mahasiswa
    string NIM; // NIM mahasiswa
    Node* next; // Pointer ke node berikutnya
};

Node* front = nullptr; // Pointer ke node depan antrian
Node* back = nullptr; // Pointer ke node belakang antrian

bool isEmpty() {
    return front == nullptr; // Antrian kosong jika front adalah nullptr
}

void enqueueAntrian(string nama, string NIM) {
    Node* newNode = new Node{nama, NIM, nullptr}; // Buat node baru
    if (isEmpty()) {
        front = back = newNode; // Jika antrian kosong, front dan back menunjuk ke node baru
    } else {
        back->next = newNode; // Tambahkan node baru di belakang antrian
        back = newNode; // Perbarui pointer back
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front; // Simpan node depan untuk dihapus
        front = front->next; // Pindahkan front ke node berikutnya
        delete temp; // Hapus node depan
        if (front == nullptr) {
            back = nullptr; // Jika antrian kosong setelah dequeue, set back ke nullptr
        }
    }
}

int countQueue() {
    int count = 0; // Inisialisasi penghitung
    Node* temp = front; // Mulai dari node depan
    while (temp != nullptr) {
        count++; // Tambah penghitung untuk setiap node
        temp = temp->next; // Pindah ke node berikutnya
    }
    return count; // Kembalikan jumlah node
}

void clearQueue() {
    while (!isEmpty()) {
        dequeueAntrian(); // Hapus semua node satu per satu
    }
}

void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Node* temp = front; // Mulai dari node depan
    int index = 1;
    while (temp != nullptr) {
        cout << index << ". Nama: " << temp->nama << ", NIM: " << temp->NIM << endl; // Tampilkan data di setiap node
        temp = temp->next; // Pindah ke node berikutnya
        index++;
    }
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    }
}

int main() {
    enqueueAntrian("Andi", "123456");
    enqueueAntrian("Maya", "654321");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%207/img/ss%20output%20unguided%202.png)

Kode di atas digunakan untuk mengimplementasikan struktur data antrian (queue) yang menyimpan informasi tentang mahasiswa, yaitu nama dan NIM. 
Antrian ini mengikuti prinsip FIFO (First In, First Out), di mana mahasiswa yang pertama kali masuk ke antrian akan menjadi yang pertama kali keluar. 
Setiap elemen dalam antrian diwakili oleh sebuah node yang berisi atribut nama, NIM, dan pointer ke node berikutnya. Kode ini mencakup berbagai fungsi
untuk mengelola antrian, termasuk menambahkan mahasiswa ke antrian (enqueueAntrian), menghapus mahasiswa dari antrian (dequeueAntrian), memeriksa 
apakah antrian kosong (isEmpty), menghitung jumlah elemen dalam antrian (countQueue), mengosongkan antrian (clearQueue), dan menampilkan semua elemen
dalam antrian (viewQueue). Dengan menggunakan linked list, antrian ini tidak dibatasi oleh ukuran tetap seperti pada array, memungkinkan fleksibilitas
untuk menambah atau menghapus elemen sesuai kebutuhan hingga batas memori yang tersedia. Kode ini juga mencakup fungsi main untuk menguji operasi-operasi
tersebut dengan menambahkan, menghapus, dan menampilkan elemen dalam antrian. 

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%207/img/ss%20ful%20program%20unguided%202.png)

## Kesimpulan
Queue merupakan struktur data yang bersifat FIFO (First In First Out), di mana elemen data ditambahkan di satu ujung (rear) dan dihapus di ujung lain (front). Proses penambahan elemen disebut enqueue, sementara proses penghapusan elemen disebut dequeue. Sistem antrian mempelajari formasi dan dinamika baris penungguan, khususnya dalam konteks pelayanan yang melebihi kapasitas yang tersedia, sehingga memerlukan analisis matematis untuk pengelolaannya. Dengan demikian, antrian memastikan bahwa elemen yang pertama masuk adalah elemen yang pertama keluar, menjaga urutan proses sesuai dengan kedatangan.

## Referensi
[1]	Agam Rizky, “PENERAPAN ALGORITMA QUEUE PADA APLIKASI PEMESANAN OBAT BERBASIS MOBILE PADA APOTEK ARUBA FARMA DEPOK,” pp. 1168-1177, Aug. 2023.

[2]	Yovi Apridiansyah(, “Aplikasi Antrian Pembayaran Uang Kuliah Berbasis Android Menggunakan Algoritma Fifo Di Universitas Muhammadiyah Bengkulu,” vol. 3, pp. 91–103, Jul. 2021.
