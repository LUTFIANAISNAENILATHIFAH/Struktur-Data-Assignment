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
