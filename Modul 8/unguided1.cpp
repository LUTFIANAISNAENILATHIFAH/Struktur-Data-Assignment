// Lutfiana Isnaeni Lathifah 
// 2311102165

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(string kalimat, char huruf) {
    int low = 0;
    int high = kalimat.length() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (kalimat[mid] == huruf) {
            return mid;
        }
        else if (kalimat[mid] < huruf) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // jika huruf tidak ditemukan
}

int main() {
    string kalimat;
    char huruf;
    
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Mengubah kalimat menjadi huruf kecil agar penggunaan Binary Search menjadi valid
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Mengubah huruf yang ingin dicari menjadi huruf kecil
    huruf = tolower(huruf);

    // Melakukan pencarian dengan Binary Search
    int index = binarySearch(kalimat, huruf);

    if (index != -1) {
        cout << "Huruf '" << huruf << "' ditemukan pada indeks ke-" << index << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
} 
