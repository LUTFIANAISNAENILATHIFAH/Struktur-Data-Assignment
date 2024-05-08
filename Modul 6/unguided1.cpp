#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;
    string cleanStr;

    // Menghapus karakter non-alfabet dan mengonversi huruf menjadi huruf kecil
    for (char c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }

    int length = cleanStr.length();
    int mid = length / 2;

    // Menyimpan setengah karakter pertama ke dalam stack
    for (int i = 0; i < mid; i++) {
        charStack.push(cleanStr[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang di-pop dari stack
    for (int i = mid + (length % 2); i < length; i++) {
        if (cleanStr[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah Palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan Palindrom." << endl;
    }

    return 0;
}