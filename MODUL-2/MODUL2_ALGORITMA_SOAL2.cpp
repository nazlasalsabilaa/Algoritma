#include <iostream>

const int max = 10;

struct Stack {
    int atas;
    int data[max];
};

Stack Tumpuk;

void inisialisasi() {
    Tumpuk.atas = -1;
}

int penuh() {
    return (Tumpuk.atas == max - 1);
}

int kosong() {
    return (Tumpuk.atas == -1);
}

void input(int data) {
    if (penuh()) {
        std::cout << "Tumpukan Penuh\n"; // Tambah \n
    } else {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        std::cout << "Data " << Tumpuk.data[Tumpuk.atas]
 << " Masuk Ke Stack\n"; // Tambah \n
    }
}

void hapus() {
    if (!kosong()) {
        std::cout << "Data Teratas Sudah Terambil\n"; //
 Tambah \n
        Tumpuk.atas--;
    } else {
        std::cout << "Data Kosong\n"; // Tambah \n
    }
}

void tampil() {
    if (!kosong()) {
        std::cout << "Isi Tumpukan:\n";

        for (int i = Tumpuk.atas; i >= 0; i--) {
            std::cout << "Tumpukan Ke-" << i << " = " <<
 Tumpuk.data[i] << "\n";
        }
    } else {
        std::cout << "Tumpukan Kosong\n"; // Tambah \n
    }
}

void bersih() {
    Tumpuk.atas = -1;
    std::cout << "Tumpukan Kosong !\n"; // Tambah \n
}

int main() {
    inisialisasi();
    input(5);
    input(10);
    input(15);
    tampil();
    hapus();
    tampil();
    bersih();
    tampil();
    return 0;
}