#include <iostream>
using namespace std;
 
struct Kendaraan {
    string plat;
    string jenis;
    string namaPemilik;
    string alamat;
    string kota;
};
 
int main() {
    Kendaraan k;
 
    k.plat = "DA1234MK";
    k.jenis = "RUSH";
    k.namaPemilik = "Andika Hartanto";
    k.alamat = "Jl. Kayu Tangi 1";
    k.kota = "Banjarmasin";
 
    cout << "a. Plat Nomor Kendaraan : " << k.plat << endl;
    cout << "b. Jenis Kendaraan      : " << k.jenis << endl;
    cout << "c. Nama Pemilik         : " << k.namaPemilik << endl;
    cout << "d. Alamat               : " << k.alamat << endl;
    cout << "e. Kota                 : " << k.kota << endl;