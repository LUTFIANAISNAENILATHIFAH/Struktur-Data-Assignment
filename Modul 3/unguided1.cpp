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