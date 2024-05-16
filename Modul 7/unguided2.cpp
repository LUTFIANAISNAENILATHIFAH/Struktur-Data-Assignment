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