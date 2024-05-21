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
