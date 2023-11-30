#include <iostream>
#include <Windows.h>

using namespace std;

enum Spec { ME, MF, FI, KN };
const char* specStrings[] = { "ME", "MF", "FI", "KN" };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int physoc;
    int mathoc;
    int infroc;
};

// �������� ����������
void inputStudentData(Student& student) {
    cout << "�������: ";
    cin >> student.prizv;

    cout << "����: ";
    cin >> student.kurs;

    cout << "������������ ( ME, MF, FI, KN ): ";
    string specValue;
    cin >> specValue;

    if (specValue == "ME") student.spec = ME;
    else if (specValue == "MF") student.spec = MF;
    else if (specValue == "FI") student.spec = FI;
    else if (specValue == "KN") student.spec = KN;
    else {
        cout << "����������� �������� ��� ������������. �������� ������" << endl;
        return;
    }

    cout << "Գ����: ";
    cin >> student.physoc;

    cout << "����������: ";
    cin >> student.mathoc;

    cout << "�����������: ";
    cin >> student.infroc;
    cout << endl;
}


// ���������� ����������
void fullInfo(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << "������ ���������� ��� �������� " << i + 1 << ":" << endl;
        inputStudentData(students[i]);
    }
}


// ��������� �������
void printTable(const Student students[], int numStudents) {
    
    cout << "������ ��������:" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|  �  |     �������    | ���� |  ������������  |  Գ����  | ���������� | �����������  |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    // ��������� ����� ��� �������� � ������ �������
    for (int i = 0; i < numStudents; ++i) {
        cout << "| " << i + 1 << "   | ";
        cout.width(15); cout << left << students[i].prizv << " | ";
        cout.width(4); cout << students[i].kurs << " | ";
        cout.width(15); cout << left << specStrings[students[i].spec] << " | ";
        cout.width(8); cout << left << students[i].physoc << " | ";
        cout.width(10); cout << left << students[i].mathoc << " | ";
        cout.width(12); cout << left << students[i].infroc << " |" << endl;
    }

    cout << "----------------------------------------------------------------------------------------" << endl;
}


// ��������, �� ������� ��� �����
int GoodStudent(const Student students[], int numStudents) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        
        if (students[i].physoc >= 4 && students[i].mathoc >= 4 && students[i].infroc >= 4) {
            count++;
        }
    }
    return count;
}



// ����� ������� �������� � ���� ������� ��� ����� 4
float calcArg(const Student& student) {
    return (student.physoc + student.mathoc + student.infroc) / 3.0;
}


float calcProcent(const Student students[], int numStudents) {
    int countBelowFour = 0;
    for (int i = 0; i < numStudents; ++i) {
        
        if (calcArg(students[i]) < 4.0) {
            countBelowFour++;
        }
    }
    return (countBelowFour / static_cast<float>(numStudents)) * 100.0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numStudents;
    cout << "����� ������� ��������: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    fullInfo(students, numStudents);

    // ��������� ���������� ��� ��������
    cout << endl;
    printTable(students, numStudents);

    // ������ ������� �������� ��� �����
    int excellentAndGoodCount = GoodStudent(students, numStudents);
    
    cout << endl << "ʳ������ �������� ��� �����: " << excellentAndGoodCount << endl;

    cout << endl << "³������ ��������, � ���� ������� ��� ������ 4: " << calcProcent(students, numStudents) << endl;

    delete[] students;

    return 0;
}
