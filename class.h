#include <cstddef>
#include <ostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Student {

    public:

    Student(size_t);
    ~Student();

    void readFromCSV(ifstream&);
    void evalAvg();
    void print(int, string);

    private:

    void printLine(size_t i); // tek satırı ekrana yazdırmak için
    double average(size_t);
    bool isPass(size_t);
    void writeLine(size_t, ostream&, int);

    size_t mevcut;

    // dinamik diziler
    string * ad;
    string * ogrNo;
    double * sinav0; // ara sınav
    double * sinav1; // ikinci sınav
    double * odev;
    double * sinav2; // final
    int * devamSayisi;
    double * ortalama;
};
