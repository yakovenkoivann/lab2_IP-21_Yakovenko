#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>

#include "bin.h"
#include "processBook.h"

using namespace std;

struct Book {
    char title[100];
    char date_written[100];
    int year_published;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inFilename, outFilename;
    cout << "\tsdsdsdsdsd 32" << endl;
    cout << "�������� ���� �� ������� ����� ������: �����, ���� ���������, �� ������� (���� ��� �� ������, �� 0).\n��������� ������� ������� ����� ������.\n��������� � ������� ���� ���������� ��� �����, �������� �� ������ � �������� ������.\n" << endl;
    int flag = 1;
    while (flag != 0) {
        menu();
        cin >> flag;
        switch (flag)
        {
            case 0:
            {
                flag = 0;
                cout << "����� �� ������!" << endl;
            }break;
            case 1:
            {
                inFilename = createBinaryFile();
                addBookToCatalog(inFilename);
                cout << "\n� ���� ������� ����� �����:\n" << endl;
                readCatalog(inFilename);
            }break;
            case 2:
            {
                cout << "\n\t���� �����:" << endl;
                readCatalog(inFilename);
                addBookToCatalog(inFilename);
                cout << "\n\t��������� ���� �����:" << endl;
                readCatalog(inFilename);
            }break;
            case 3:
            {
                cout << "�� ������� ����� ����?" << endl;
                outFilename = createBinaryFile();

                lastCenturyBooks(inFilename, outFilename);
                cout << "\n\t���� �������� �����:" << endl;
                readCatalog(inFilename);
                checkWinterBooks(inFilename);
                cout << "\n\t���� ��������� �����:" << endl;
                readCatalog(outFilename);
            }break;
            default:
                break;
        }
    }

    return 0;
}