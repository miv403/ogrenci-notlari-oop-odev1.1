#include "class.h"

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>


Student::Student(size_t mevcut) 
: mevcut (mevcut){ 

    ad = new string[mevcut];
    ogrNo = new string[mevcut];
    sinav0 = new double[mevcut];
    sinav1 = new double[mevcut];
    odev = new double[mevcut];
    sinav2 = new double[mevcut];
    devamSayisi = new int[mevcut];

    ortalama = new double[mevcut];

    for(int i = 0; i < mevcut; ++i) {
        ad[i] = "";
        ogrNo[i] = "";
        sinav0[i] = 0;
        sinav1[i] = 0;
        odev[i] = 0;
        sinav2[i] = 0;
        devamSayisi[i] = 0;
        ortalama[i] = 0;
    }
}

Student::~Student() {

    delete[] ad;
    delete[] ogrNo;
    delete[] sinav0;
    delete[] sinav1;
    delete[] odev;
    delete[] sinav2;
    delete[] devamSayisi;
    delete[] ortalama;

}

void Student::readFromCSV(ifstream& dosya) {

    string satir;
    getline(dosya, satir);
    string hucre;
    for(size_t i = 0; i < mevcut; ++i) {

        getline(dosya, satir);
        
        stringstream tokens(satir);

        getline(tokens, hucre, ',');
        ad[i] = hucre;
        getline(tokens, hucre, ',');
        ogrNo[i] = hucre;
        getline(tokens, hucre, ',');
        sinav0[i] = stod(hucre);
        getline(tokens, hucre, ',');
        sinav1[i] = stod(hucre);
        getline(tokens, hucre, ',');
        odev[i] = stod(hucre);
        getline(tokens, hucre, ',');
        sinav2[i] = stod(hucre);

        getline(tokens, hucre, ',');
        if(hucre == "") {
            devamSayisi[i] = 0;
        }else {
            devamSayisi[i] = stoi(hucre);
        }
    }
}

void Student::evalAvg() {

    for(size_t i = 0; i < mevcut; ++i) {
        ortalama[i] = average(i);
    }
}

void Student::print(int opt = 2, string yol = ""){

    size_t sayac{};
    if(yol != "") { // dosyaya çıktı alma
        ofstream cikti;
        cikti.open(yol);
        if(!cikti) {
            cerr << yol << " dosyasi acilamadi!" << endl;
            return;
        }

        cikti << "ogrNo,ad,ortalama,gecmeDurumu" << endl;

        for(size_t i = 0; i < mevcut; ++i) {
            writeLine(i, cikti, opt);
        }   
        return;
    }
    switch (opt) {
    case 0:
        for(size_t i = 0; i < mevcut; ++i) {
            if(!isPass(i)) {
                printLine(i);
                cout << "kaldi" << endl;
                sayac++;
            }
        }
        break;
    case 1:
        for(size_t i = 0; i < mevcut; ++i) {
            if(isPass(i)) {
                printLine(i);
                cout << "gecti" << endl;
                sayac++;
            }
        }
        break;
    default:
        for(size_t i = 0; i < mevcut; ++i) {
            printLine(i);
            cout << (isPass(i) ? "gecti" : "kaldi") << endl;
        }
        return;
        break;
    }
    cout << sayac << " ogrenci " << (opt ? "gecti" : "kaldi") << endl;
}

void Student::printLine(size_t i) {
    cout << setw(12) << setfill(' ') << right;
    cout << ogrNo[i];
    cout << setw(12) << setfill(' ') << right;
    cout << ad[i];
    cout << setw(12) << right;
    cout << ortalama[i];
    cout << setw(18) << right;
}

double Student::average(size_t i) {

    return (sinav0[i] + sinav1[i] + odev[i]) * 0.2 + (sinav2[i] * 0.4);
}

bool Student::isPass(size_t i) {

    return (ortalama[i] >= 50);
}

void Student::writeLine(size_t i, ostream& file, int opt = 2) {

    if(opt == 0 && !isPass(i)) {
        file << ogrNo[i] << ","
            << ad[i] << ","
            << ortalama[i] << ","
            << "kaldi" << endl;
    }else if(opt == 1 && isPass(i)) {
        file << ogrNo[i] << ","
            << ad[i] << ","
            << ortalama[i] << ","
            << "gecti" << endl;
    }else if(opt == 2) {
        file << ogrNo[i] << ","
            << ad[i] << ","
            << ortalama[i] << ","
            << (isPass(i) ? "gecti" : "kaldi") << endl;
    }
}
