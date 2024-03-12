#include <iostream>
#include <map>
#include <vector>

int main() {
    // Contoh array
    int array[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(array) / sizeof(array[0]);

    // Menggunakan fungsi map
    std::map<int, int> myMap;

    // Mengisi map dengan data dari array
    for (int i = 0; i < arraySize; ++i) {
        myMap[i] = array[i];
    }

    // Menampilkan isi array
    std::cout << "Isi Array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << array[i] << " ";
    }

    // Menampilkan isi map
    std::cout << "\nIsi Map: ";
    for (const auto& pair : myMap) {
        std::cout << pair.second << " ";
    }

    return 0;
}