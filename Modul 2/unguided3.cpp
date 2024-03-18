#include <iostream>
using namespace std;
int main()
{
  int n_165;
  cout << "Masukkan jumlah elemen array: ";
  cin >> n_165;

  int arr[n_165];
  cout << "Masukkan elemen array: ";
  for (int i_165 = 0; i_165 < n_165; i_165++)
  {
    cin >> arr[i_165];
  }
  int max = arr[0], min = arr[0], jumlah = 0;
  for (int i_165 = 1; i_165 < n_165; i_165++)
  {
    if (arr[i_165] > max)
    {
      max = arr[i_165];
    }
    if (arr[i_165] < min)
    {
      min = arr[i_165];
    }
    jumlah += arr[i_165];
  }
  float rata = (float) jumlah /n_165;
  cout << "Nilai maksimum: " << max << endl;
  cout << "Nilai minimum: " << min << endl;
  cout << "Nilai rata-rata: " << rata << endl;

  return 0;
}