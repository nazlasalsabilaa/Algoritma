#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

string nama[] = {"Nazla", "Salsabila"};
string nim = "2410817320001";
int n_nama = 2;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void tampilMenu() {
    setColor(10);
    cout << "----------------------" << endl;
    cout << "|";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (3 << 4) | 1);
    cout << "      SORTING       ";
    setColor(10);
    cout << "|" << endl;
    cout << "----------------------" << endl;
    for (int i = 1; i <= 7; i++) {
        setColor(14);
        string pilihan;
        switch(i) {
            case 1: pilihan = " 1. Insertion Sort"; break;
            case 2: pilihan = " 2. Merge Sort"; break;
            case 3: pilihan = " 3. Shell Sort"; break;
            case 4: pilihan = " 4. Quick Sort"; break;
            case 5: pilihan = " 5. Bubble Sort"; break;
            case 6: pilihan = " 6. Selection Sort"; break;
            case 7: pilihan = " 7. Exit"; break;
        }
        if ((int)pilihan.length() < 26) {
            pilihan += string(26 - pilihan.length(), ' ');
        }
        cout << pilihan << endl;
    }
    setColor(10);
    cout << "----------------------" << endl;
    setColor(3);
    cout << "Masukkan Pilihan : ";
}

template<typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSortChar(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeChar(char arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortChar(char arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);
        mergeChar(arr, l, m, r);
    }
}

void shellSortChar(char arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
                arr[j] = arr[j - gap], j -= gap;
            arr[j] = temp;
        }
}

void sortHurufDenganAlgoritma(void (*sortFunc)(char[], int), const string& namaAlgoritma) {
    int totalHuruf = 0;
    for (int i = 0; i < n_nama; i++)
        totalHuruf += nama[i].length();

    char* allHuruf = new char[totalHuruf];
    int index = 0;
    for (int i = 0; i < n_nama; i++) {
        for (char c : nama[i])
            allHuruf[index++] = tolower(c);
    }

    sortFunc(allHuruf, totalHuruf);

    setColor(14);
    cout << namaAlgoritma << ": ";
    for (int i = 0; i < totalHuruf; i++)
        cout << allHuruf[i];
    cout << endl;
    setColor(7);

    delete[] allHuruf;
}

void sortNimQuick(string& nimStr, int low, int high) {
    if (low < high) {
        char pivot = nimStr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (nimStr[j] < pivot) {
                i++;
                swap(nimStr[i], nimStr[j]);
            }
        }
        swap(nimStr[i + 1], nimStr[high]);
        int pi = i + 1;
        sortNimQuick(nimStr, low, pi - 1);
        sortNimQuick(nimStr, pi + 1, high);
    }
}

void sortNimBubble(string& nimStr) {
    int n = nimStr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nimStr[j] > nimStr[j + 1])
                swap(nimStr[j], nimStr[j + 1]);
        }
    }
}

void sortNimSelection(string& nimStr) {
    int n = nimStr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (nimStr[j] < nimStr[minIdx])
                minIdx = j;
        }
        swap(nimStr[i], nimStr[minIdx]);
    }
}

int main() {
    int pilihan;
    do {
        tampilMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                sortHurufDenganAlgoritma(insertionSortChar, "Insertion Sort");
                break;
            case 2: {
                int totalHuruf = 0;
                for (int i = 0; i < n_nama; i++)
                    totalHuruf += nama[i].length();
                char* allHuruf = new char[totalHuruf];
                int idx = 0;
                for (int i = 0; i < n_nama; i++)
                    for (char c : nama[i])
                        allHuruf[idx++] = tolower(c);
                mergeSortChar(allHuruf, 0, totalHuruf - 1);
                setColor(14);
                cout << "Merge Sort: ";
                for (int i = 0; i < totalHuruf; i++)
                    cout << allHuruf[i];
                cout << endl;
                setColor(7);
                delete[] allHuruf;
                break;
            }
            case 3:
                sortHurufDenganAlgoritma(shellSortChar, "Shell Sort");
                break;
            case 4: {
                string nimCopy = nim;
                sortNimQuick(nimCopy, 0, nimCopy.size() - 1);
                setColor(14);
                cout << "Quick Sort: " << nimCopy << endl;
                setColor(7);
                break;
            }
            case 5: {
                string nimCopy = nim;
                sortNimBubble(nimCopy);
                setColor(14);
                cout << "Bubble Sort: " << nimCopy << endl;
                setColor(7);
                break;
            }
            case 6: {
                string nimCopy = nim;
                sortNimSelection(nimCopy);
                setColor(14);
                cout << "Selection Sort: " << nimCopy << endl;
                setColor(7);
                break;
            }
            case 7:
                setColor(7);0
                cout << "Terima Kasih Sudah Mencoba!" << endl;
                break;
            default:
                setColor(12);
                cout << "Pilihan Tidak Valid!" << endl;
                break;
        }

        if (pilihan != 7) {
            cout << endl;
        }

    } while (pilihan != 7);

    return 0;
}