#include "class.h"

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <fstream>
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
    vector<string> tokens;
    for(size_t i = 0; i < mevcut; ++i) {
        getline(dosya, satir);
        
        tokens = parseLine(satir);

        ad[i] = tokens.at(0);
        ogrNo[i] = tokens.at(1);
        sinav0[i] = stod(tokens.at(2));
        sinav1[i] = stod(tokens.at(3));
        odev[i] = stod(tokens.at(4));
        sinav2[i] = stod(tokens.at(5));

        if(tokens.at(6) == "") {
            devamSayisi[i] = 0;
        }else {
            devamSayisi[i] = stoi(tokens.at(6));
        }
    }
}

void Student::evalAvg() {

    for(size_t i = 0; i < mevcut; ++i) {
        ortalama[i] = average(i);
    }
}

void Student::print() {

    for(size_t i = 0; i < mevcut; ++i) {
        printLine(i);
        cout << (isPass(i) ? "gecti" : "kaldi") << endl;
    }

}

void Student::print(int opt){
    size_t sayac{};
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
        cerr << "Student::print() gecersiz secenek! functions.cpp:"
                << __LINE__ << endl;
        break;

    }
    cout << sayac << " ogrenci " << (opt ? "gecti" : "kaldi") << endl;
}

void Student::print(string& yol) {

    ofstream cikti;
    cikti.open(yol);
    if(!cikti) {
        cerr << yol << " dosyasi acilamadi!" << endl;
        return;
    }

    cikti << "ogrNo,ad,ortalama,gecmeDurumu" << endl;

    for(size_t i = 0; i < mevcut; ++i) {
        cikti << ogrNo[i] << ","
            <<   ad[i] << ","
            << ortalama[i] << ","
            << (isPass(i) ? "gecti" : "kaldi") << endl;
    }
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

    return (ortalama[i] > 50);
}

vector<string> Student::parseLine(string& line) {
    // alınan satırın virgülle vektöre eklenmesi

    vector<string> tokens; // degerlerin listesi
    size_t pos = 0;
    string token;
    string delimiter = ",";

    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line);

    return tokens;
}