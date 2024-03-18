#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel untuk menyimpan dimensi array
    int x_165, y_165, z_165;

    // Input dimensi array dari user
    cout << "Masukkan jumlah baris: ";
    cin >> x_165;
    cout << "Masukkan jumlah kolom: ";
    cin >> y_165;
    cout << "Masukkan panjang array: ";
    cin >> z_165;

    // Deklarasi array dengan dimensi yang diinputkan user
    int arr[x_165][y_165][z_165];

    // Input elemen array
    for (int i = 0; i < x_165; i++)
    {
        for (int j = 0; j < y_165; j++)
        {
            for (int k = 0; k < z_165; k++)
            {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
    // Output array
    cout << endl << "Data Array: " << endl;
    for (int i = 0; i < x_165; i++)
    {
        for (int j = 0;  j < y_165; j++)
        {
            for (int k = 0; k < z_165; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}