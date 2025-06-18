#include <iostream>
using namespace std;
 
struct Inputan {
    char huruf;
    string kata;
    int angka;
};
 
int main() {
    Inputan data;
 
    cout << "a. Masukkan sebuah huruf = ";
    cin >> data.huruf;
 
    cout << "b. Masukkan sebuah kata = ";
    cin >> data.kata;
 
    cout << "c. Masukkan angka = ";
    cin >> data.angka;
 
    cout << "d. Huruf yang Anda masukkan adalah " << data.huruf << endl;
    cout << "e. Kata yang Anda masukkan adalah " << data.kata << endl;