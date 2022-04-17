#include <iostream>
#include <string>

#include <fstream>


using namespace std;
struct Grades {
    char Surname[20];
    int GroupNumber;
    int GradesPhysics;
    int GradesMath;
    int GradesInformatics;
    int GradesChem;
    double AverageGrade;
};

void WriteToFile(Grades* obj, int n) {
    ofstream file;
    file.open("file.txt");
    if (!file.is_open()) {
        cout << "Error!";
    }
    else {
        for (int i = 0; i < n; i++) {
            file << obj[i].Surname << " " << obj[i].GroupNumber << " " << obj[i].GradesPhysics << " " << obj[i].GradesMath << " " << obj[i].GradesInformatics << " " << obj[i].GradesChem << " " << obj[i].AverageGrade << '\n';
        }
    }
    file.close();
}
void InputStructures(Grades* obj, int n) {

    char Surname[20];
    int GradesPhysic, GradesMath, GradesInformatics, AverangeScore, GroupNumber;
    cout << "Input pupils (Surname, GroupNumber, GradesPhysic,GradesMath,GradesInformatics)" << '\n';
    for (int i = 0; i < n; i++) {
        cout << "Surname" << '\n';
        cin >> obj[i].Surname;
        cout << "GroupNumber" << '\n';
        cin >> obj[i].GroupNumber;
        cout << "GradesPhysics" << '\n';
        cin >> obj[i].GradesPhysics;
        cout << "GradesMath" << '\n';
        cin >> obj[i].GradesMath;
        cout << "GradesInformatics" << '\n';
        cin >> obj[i].GradesInformatics;
        cout << "GradesChem" << '\n';
        cin >> obj[i].GradesChem;
        obj[i].AverageGrade = (obj[i].GradesPhysics + obj[i].GradesMath + obj[i].GradesInformatics + obj[i].GradesChem) / 4.0;
        cout << "AverangeScore" << '\n' << obj[i].AverageGrade << '\n';
    }
    WriteToFile(obj, n);

}
int PrintStructures(Grades* obj, int n) {

    cout << '\n';
    int num = 1;
    for (int i = 0; i < n; i++) {
        cout << num << ") " << obj[i].Surname << " " << obj[i].GroupNumber << " " << obj[i].GradesPhysics << " " << obj[i].GradesMath << " " << obj[i].GradesInformatics << " " << obj[i].GradesChem << " " << obj[i].AverageGrade << '\n';
        num++;
    }
    return 0;

}
int aDelete(Grades* obj, int n) {
    int p;
    PrintStructures(obj, n);
    cout << "Enter number ,which you want delete" << '\n';
    cin >> p;
    while (p<1 && p>n - 1) {
        cout << "Enter normal number" << '\n';
        cout << "Enter number,which you want delete" << endl;
        cin >> p;
    }
    for (int j = p - 1; j < n - 1; j++) {
        obj[j] = obj[j + 1];
    }
    --n;
    WriteToFile(obj, n);
    return 0;
}
int menu() {
    int res;
    cout << "=========================" << '\n' << "\nMenu:\n" << '\n';
    cout << 1 << "-" << "Input array of structures" << '\n';
    cout << 2 << "-" << "My task\n";
    cout << 3 << "-" << "Print structures" << '\n';
    cout << 4 << "-" << "Add 1 obj" << '\n';
    cout << 5 << "-" << "Change" << '\n';
    cout << 6 << "-" << "Delete" << '\n';
    cout << 7 << "-" << "To exit\n" << "=========================" << '\n';
    cin >> res;
    return res;
}
void task(Grades* obj, int n) {
    ofstream file;
    file.open("task.txt");
    if (!file.is_open()) {
        cout << "Error!";
    }
    else {
        for (int i = 0; i < n; i++) {
            if (obj[i].GradesInformatics >= 4 && obj[i].GradesMath >= 4) {
                file << obj[i].Surname << " " << obj[i].GroupNumber << " " << obj[i].GradesPhysics << " " << obj[i].GradesMath << " " << obj[i].GradesInformatics << " " << obj[i].GradesChem << " " << obj[i].AverageGrade << '\n';
            }
        }
    }
    file.close();
}



void addobj(Grades*& obj, int& n)
{
    Grades* tempTable = new Grades[n];
    for (int i = 0; i < n; i++)
        tempTable[i] = obj[i];
    delete[]obj;
    n++;
    obj = new Grades[n];
    for (int i = 0; i < n - 1; i++)
        obj[i] = tempTable[i];
    delete[] tempTable;
    cout << "Surname" << '\n';
    cin >> obj[n - 1].Surname;
    cout << "GroupNumber" << '\n';
    cin >> obj[n - 1].GroupNumber;
    cout << "GradesPhysic" << '\n';
    cin >> obj[n - 1].GradesPhysics;
    cout << "GradesMath" << '\n';
    cin >> obj[n - 1].GradesMath;
    cout << "GradesInformatics" << '\n';
    cin >> obj[n - 1].GradesInformatics;
    cout << "GradesChem" << '\n';
    cin >> obj[n - 1].GradesChem;
    obj[n - 1].AverageGrade = (obj[n - 1].GradesPhysics + obj[n - 1].GradesMath + obj[n - 1].GradesInformatics + obj[n - 1].GradesChem) / 4.0;
    cout << "AverageScore" << '\n' << obj[n - 1].AverageGrade << '\n';
    PrintStructures(obj, n);
    WriteToFile(obj, n);
}
int ChangeStructure(Grades* obj, int n) { /// р-1 поставить вместо н-1
    int p;
    int field;
    cout << "What is the number of the structure you want to change?" << endl;
    PrintStructures(obj, n);
    cin >> n;
    while (n<1 && n>n - 1) {
        cout << "Enter normal number" << '\n';
        cout << "What is the number of the structure you want to change?" << endl;
        cin >> n;
    }
    cout << "What field do you want to change? (Surname - 1, Group - 2, GradesPhysic  - 3, GradesMath - 4, GradesInformatics - 5, GradesChem - 6) " << endl;
    cin >> field;
    while (field < 1 && field>5) {
        cout << "Enter normal number" << '\n';
        cin >> field;
    }
    switch (field) {
    case 1:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].Surname;
        break;
    case 2:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].GroupNumber;
        break;
    case 3:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].GradesPhysics;
        obj[n - 1].AverageGrade = (obj[n - 1].GradesPhysics + obj[n - 1].GradesMath + obj[n - 1].GradesInformatics + obj[n - 1].GradesChem) / 4.0;
        break;
    case 4:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].GradesMath;
        obj[n - 1].AverageGrade = (obj[n - 1].GradesPhysics + obj[n - 1].GradesMath + obj[n - 1].GradesInformatics + obj[n - 1].GradesChem) / 4.0;
        break;
    case 5:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].GradesInformatics;
        obj[n - 1].AverageGrade = (obj[n - 1].GradesPhysics + obj[n - 1].GradesMath + obj[n - 1].GradesInformatics + obj[n - 1].GradesChem) / 4.0;
        break;
    case 6:
        cout << "Input new value" << endl;
        cin >> obj[n - 1].GradesChem;
        obj[n - 1].AverageGrade = (obj[n - 1].GradesPhysics + obj[n - 1].GradesMath + obj[n - 1].GradesInformatics + obj[n - 1].GradesChem) / 4.0;
        break;
    }

    WriteToFile(obj, n);
    return 0;
}

int main() {

    int n;
    cout << "Enter number of pupils" << "\n";
    cin >> n;
    Grades* obj = new Grades[n];
    InputStructures(obj, n);
    while (true) {
        switch (menu()) {
        case 1:
            InputStructures(obj, n);
            break;
        case 2:
            task(obj, n);
            break;
        case 3:
            PrintStructures(obj, n);
            break;
        case 4:
            addobj(obj, n);
            break;
        case 5:
            ChangeStructure(obj, n);
            break;
        case 6:
            aDelete(obj, n);
            n--;
            break;
        case 7:
            cout << "Bye";
            delete[]obj;
            return 0;
        }
    }
    delete[]obj;


    return 0;
}