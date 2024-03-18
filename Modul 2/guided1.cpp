#include <iostream>
using namespace std;
// PROGAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr [2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x <<"] [" << y <<"][" << z <<"] = ";
                cin >> arr [x] [y][z];
            }
        }
    }
    cout << endl;
    // Ouput array
    for (int x = 0; x<2; x++ )
    {
        for (int y=0; y<3; y++)
        {
            for (int z=0; z<3; z++)
            {
                cout << "Input Array[" << x <<"] [" << y <<"][" << z <<"] = " << arr [x][y][x] << endl;
            }
        }
        cout << endl;
    }
    cout << endl;

    // Tampilkan array
    for (int x= 0; x <2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr [x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}

