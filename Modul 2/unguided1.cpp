#include <iostream>
using namespace std;
int main()
{
    // Deklarasi array
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Menampilkan data array 
    cout << "Data Array: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl << endl;

    //Menampilkan nomor genap
    cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++)
    {
        if (data [i] % 2 == 0)
        {
            cout << data [i] << ", ";

        }
    }
    cout << endl << endl;

    // Menampikan nomor ganjil 
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++)
    {
        if (data[i] % 2 == 1) 
        {
            cout << data[i] << ", ";
        }
    }
    cout << endl;

    return 0;
}