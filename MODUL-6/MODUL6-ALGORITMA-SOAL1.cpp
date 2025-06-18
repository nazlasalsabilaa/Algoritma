#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

int main()
{
    int pilihan;
    do {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1: {
            clrscr();
            int data[100];
            int cari = 20;
            int counter = 0;
            int flag = 0;
            int save;
            randomize();
            printf("Generating 100 number . . .\n");
            for (int i = 0; i < 100; i++)
            {
                data[i] = random(100) + 1;
                printf("%d ", data[i]);
            }
            printf("\nDone.\n");

            for (int i = 0; i < 100; i++)
            {
                if (data[i] == cari)
                {
                    counter++;
                    flag = 1;
                    save = i;
                }
            }

            if (flag == 1)
            {
                printf("Data ada, sebanyak %d!\n", counter);
                printf("pada indeks ke-%d\n", save);
            }
            else
            {
                printf("Data tidak ada!\n");
            }
            system("pause");
            break;
        }

        case 2: {
            clrscr();
            int n, kiri, kanan, tengah, temp, key;
            bool ketemu = false;

            cout << "Masukan jumlah data? ";
            cin >> n;
            int angka[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Angka ke [" << i << "]: ";
                cin >> angka[i];
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (angka[j] > angka[j + 1])
                    {
                        temp = angka[j];
                        angka[j] = angka[j + 1];
                        angka[j + 1] = temp;
                    }
                }
            }
           cout << "==============================================================================\n";
            cout << "Data yang telah diurutkan adalah:\n";
            for (int i = 0; i < n; i++)
            {
                cout << angka[i] << " ";
            }         cout << "\n==============================================================================\n";
            cout << "Masukan angka yang dicari: ";
            cin >> key;

            kiri = 0;
            kanan = n - 1;
            while (kiri <= kanan)
            {
                tengah = (kiri + kanan) / 2;
                if (key == angka[tengah])
                {
                    ketemu = true;
                    break;
                }
                else if (key < angka[tengah])
                {
                    kanan = tengah - 1;
                }
                else
                {
                    kiri = tengah + 1;
                }
            }

            if (ketemu == true)
            {
                cout << "Angka ditemukan!\n";
            }
            else
            {
                cout << "Angka tidak ditemukan!\n";
            }
            system("pause");
            break;
        }

        case 3: {
            clrscr();
            cout << "Perbedaan Sequential Searching dan Binary Searching:\n\n";

            cout << "1. Pengertian Sequential Searching:\n";
            cout << "   Sequential Searching adalah metode pencarian elemen dalam data dengan memeriksa satu per satu dari awal hingga akhir.\n";

            cout << "2. Kelebihan Sequential Searching:\n";
            cout << "  - Tidak memerlukan data yang terurut.\n";
            cout << "  - Implementasi sederhana.\n";
            cout << "  - Cocok untuk dataset kecil.\n";
            cout << "  - Dapat digunakan pada struktur data apa pun.\n";
            cout << "  - Tidak memerlukan proses tambahan seperti sorting.\n";

            cout << "3. Kekurangan Sequential Searching:\n";
            cout << "  - Waktu pencarian lebih lama untuk dataset besar.\n";
            cout << "  - Kompleksitas waktu O(n).\n";
            cout << "  - Tidak efisien jika data sering dicari ulang.\n";
            cout << "  - Tidak memanfaatkan struktur data terurut.\n";
            cout << "  - Tidak cocok untuk pencarian cepat.\n\n";

            cout << "4. Pengertian Binary Searching:\n";
            cout << "   Binary Searching adalah metode pencarian data yang sudah diurutkan dengan membagi data menjadi dua bagian untuk mempercepat pencarian.\n";

            cout << "5. Kelebihan Binary Searching:\n";
            cout << "  - Sangat cepat untuk dataset besar.\n";
            cout << "  - Kompleksitas waktu O(log n).\n";
            cout << "  - Jumlah perbandingan lebih sedikit.\n";
            cout << "  - Efisien untuk data statis yang sering dicari ulang.\n";
            cout << "  - Dapat diimplementasikan iteratif atau rekursif.\n";

            cout << "6. Kekurangan Binary Searching:\n";
            cout << "  - Hanya dapat digunakan pada data yang terurut.\n";
            cout << "  - Membutuhkan proses sorting terlebih dahulu.\n";
            cout << "  - Tidak efisien untuk data yang sering berubah.\n";
            cout << "  - Implementasi lebih kompleks dibanding Sequential Search.\n";
            cout << "  - Tidak cocok untuk struktur data yang tidak memiliki indeks.\n\n";

            system("pause");
            break;
        }

        case 4:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
            break;
        }
    } while (pilihan != 4);

    return 0;
}