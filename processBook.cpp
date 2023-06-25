#define _CRT_SECURE_NO_WARNINGS

#include "processBook.h"

using namespace std;

struct Book {
    char title[100];
    char date_written[100];
    int year_published;
};

void checkWinterBooks(const string& filename) {
    ifstream inFile(filename, ios::in | ios::binary);

    if (!inFile) {
        cerr << "������� �������� �������� �����. " << filename << endl;
        exit(1);
    }
    int counter = 0;
    Book book;
    char month_str[3];
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        strncpy_s(month_str, book.date_written + 3, 2);
        month_str[2] = '\0';
        if (strcmp(month_str, "12") == 0 || strcmp(month_str, "01") == 0 || strcmp(month_str, "02") == 0) {
            counter++;
        }
    }
    cout << "\nʳ������ ������, ��������� ������ - " << counter << endl;

    inFile.close();
}

void lastCenturyBooks(const string& fIn, const string& fOut) {
    ifstream inFile(fIn, ios::in | ios::binary);

    if (!inFile) {
        cerr << "������� �������� �������� �����. " << fIn << endl;
        exit(1);
    }
    fstream outFile(fOut, ios::in | ios::out | ios::binary);
    if (!outFile) {
        cerr << "������� �������� �������� �����. " << fIn << endl;
        exit(1);
    }

    Book book;
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.date_written[6] == '1' && book.date_written[7] == '9') {
            if (book.year_published < 2000 && book.year_published > 1899) {
                outFile.seekp(0, ios::end);
                outFile.write(reinterpret_cast<const char*>(&book), sizeof(Book));
            }
        }
    }
    outFile.close();
    inFile.close();
}