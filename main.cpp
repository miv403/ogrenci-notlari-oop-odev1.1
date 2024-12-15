#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "functions.cpp"

#define DOSYA "./data/notlar.csv"

using namespace std;

void printMenu();
void printTitle();
bool write2FilePrompt();
void getFilePath(string& path);

int main() {

    ifstream notlarDosya;
    notlarDosya.open(DOSYA);
    if(!notlarDosya){
        cerr << "Hata: " << DOSYA << " dosyasi bulunamadi!" << endl;
        return 1;
    }

    // sınıf mevcudunu hesaplama
    size_t mevcut = 0;
    string line;

    // başlık satırını atlama
    getline(notlarDosya, line);
    while(getline(notlarDosya,line)) { mevcut++; }

    // cursor'u başa döndürmek için dosyayı açıp kapatma
    notlarDosya.close();
    notlarDosya.open(DOSYA);

    Student ogrenci(mevcut);

    ogrenci.readFromCSV(notlarDosya);
    cout << DOSYA << " dosyasindan veriler okundu!" << endl;
    notlarDosya.close();
    ogrenci.evalAvg();
    cout << "ortalamalar hesaplandi!" << endl;

    cout << endl << "Hos Geldiniz." << endl;

    string yol = "";
    if(write2FilePrompt()) { // dosyaya yazdirilsin mi?
        getFilePath(yol);
    }

    int opt{};
    do {
        printMenu();
        cin >> opt;
    }while(opt < 0 || opt > 2);

    if(yol == "" && opt < 2) { // ekrana çıktı alma
        printTitle();
        ogrenci.print(opt); // kalan/geçen ekrana çıktı
    } else if(yol == "" && opt == 2) {
        printTitle();
        ogrenci.print(); // parametresiz tüm liste çıktısı
    } else {
        ogrenci.print(opt,yol); // sayi ve string ile çağırma
    }

    return 0;
}

bool write2FilePrompt() {
    char opt{};
    do {
        cout << "sonuclari dosyaya yazdirmak ister misiniz? [E/h]: ";
        cin >> opt;
    }while(opt != 'E' && opt != 'e' && opt != 'H' && opt != 'h');

    return (opt == 'E' || opt == 'e');
}

void getFilePath(string& path) {
    cout << "dosya adini girin: ";
    cin >> path;
}


void printTitle() { // ekran çıktısı başlığı
            cout << setw(12) << setfill(' ') << right;
            cout << "ogrenci no";
            cout << setw(12) << setfill(' ') << right;
            cout << "ad";
            cout << setw(12) << right;
            cout << "ortalama";
            cout << setw(18) << right;
            cout << "gecme durumu" << endl;
            cout << setw(55) << setfill('-') << "" << endl;
}

void printMenu() {
            cout <<  setw(14) << setfill('-') << "" << endl;
            cout << "0. kalanlar" << endl;
            cout << "1. gecenler" << endl;
            cout << "2. tum liste" << endl;
            cout << "? ";
}