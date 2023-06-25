#define _CRT_SECURE_NO_WARNINGS

#include "bin.h"

using namespace std;


void menu() {
    cout << "\n**********************************************************************************************************" << endl;
    cout << "\t1 = ñòâîðèòè á³íàðíèé ôàéë" << endl;
    cout << "\t2 = äîäàòè êàòàëîã êíèã ó ôàéë" << endl;
    cout << "\t3 = âèêîíàòè çàâäàííÿ" << endl;
    cout << "\t0 = çàê³í÷èòè ïðîãðàìó" << endl;
    cout << "**********************************************************************************************************" << endl;
    cout << "\nÎáåðè âàð³àíò ðîáîòè ç ôàéëàìè: ";
}

string createBinaryFile() {
    string filename;
    cout << "Ââåä³òü ³ì'ÿ ôàéëó: ";
    cin >> filename;
    ofstream outFile(filename, ios::out | ios::binary);
    if (!outFile) {
        cerr << "Ïîìèëêà ïðè ñòâîðåíí³ á³íàðíîãî ôàéëó." << filename << endl;
        exit(1);
    }
    outFile.close();
    cout << "Á³íàðíèé ôàéë " << filename << " óñï³øíî ñòâîðåíî!" << endl;
    return filename;
}

struct Book {
    char title[100];
    char date_written[100];
    int year_published;
};

void addBookToCatalog(const string& filename) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Ïîìèëêà â³äêðèòòÿ á³íàðíîãî ôàéëó. " << filename << endl;
        exit(1);
    }

    int k;
    cout << "\nÂâåä³òü ê³ëüê³ñòü êíèã: "; cin >> k;
    for (int i = 0; i < k; i++) {
        Book book;
        cout << "\nÂâåä³òü íàçâó êíèãè: ";
        cin.ignore(); // Ïðîïóñêàºìî ñèìâîë íîâîãî ðÿäêà â áóôåð³ ââåäåííÿ
        cin.getline(book.title, 100);
        cout << "Ââåä³òü äàòó íàïèñàííÿ êíèãè (íàïðèêëàä 10.10.2010): ";
        cin.getline(book.date_written, 100);
        cout << "Ââåä³òü ð³ê âèäàííÿ(ÿêùî òâ³ð íå âèäàíî, òî - 0): ";
        cin >> book.year_published;

        file.seekp(0, ios::end);
        file.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    file.close();
}

void readCatalog(const string& filename) {
    ifstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cerr << "Ïîìèëêà â³äêðèòòÿ á³íàðíîãî ôàéëó. " << filename << endl;
        exit(1);
    }

    Book book;
    char month_str[3];
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        cout << "Íàçâà: " << book.title << endl;
        cout << "Äàòà íàïèñàííÿ: " << book.date_written << endl;
        cout << "Ð³ê âèäàííÿ: " << book.year_published << endl;
        cout << endl;
    }

    inFile.close();
}