// Lutfiana Isnaeni Lathifah 
// 2311102165

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    string nim;
    float nilai;
};

class HashTable {
private:
    int size;
    vector<vector<Mahasiswa>> table;

    int hashFunction(string nim) {
        int sum = 0;
        for (char c : nim) {
            sum += c;
        }
        return sum % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    void addData(Mahasiswa mhs) {
        int index = hashFunction(mhs.nim);
        for (Mahasiswa& data : table[index]) {
            if (data.nim == mhs.nim) {
                cout << "Mahasiswa dengan NIM tersebut sudah ada." << endl;
                return;
            }
        }
        table[index].push_back(mhs);
    }

    void removeData(string nim) {
        int index = hashFunction(nim);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index][i].nim == nim) {
                table[index].erase(table[index].begin() + i);
                cout << "Mahasiswa dengan NIM " << nim << " telah dihapus." << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }

    void searchByNIM(string nim) {
        int index = hashFunction(nim);
        for (Mahasiswa& data : table[index]) {
            if (data.nim == nim) {
                cout << "NIM: " << data.nim << " Nilai: " << data.nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }

    void searchByNilaiRange(float start, float end) {
        bool found = false;
        for (vector<Mahasiswa>& data : table) {
            for (Mahasiswa& mhs : data) {
                if (mhs.nilai >= start && mhs.nilai <= end) {
                    cout << "NIM: " << mhs.nim << " Nilai: " << mhs.nilai << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa dengan nilai dalam rentang " << start << " - " << end << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    while (true) {
        cout << "\nPilihan Menu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari Data Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80-90)" << endl;
        cout << "5. Keluar" << endl;

        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        if (choice == 1) {
            Mahasiswa mhs;
            cout << "Masukkan NIM mahasiswa: ";
            cin >> mhs.nim;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> mhs.nilai;
            hashTable.addData(mhs);
        }
        else if (choice == 2) {
            string nim;
            cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
            cin >> nim;
            hashTable.removeData(nim);
        }
        else if (choice == 3) {
            string nim;
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim;
            hashTable.searchByNIM(nim);
        }
        else if (choice == 4) {
            cout << "Mahasiswa dengan nilai antara 80-90:" << endl;
            hashTable.searchByNilaiRange(80, 90);
        }
        else if (choice == 5) {
            cout << "Terima kasih, program selesai." << endl;
            break;
        }
        else {
            cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }

    return 0;
}