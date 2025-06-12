#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;



class Student {
public:
    int ID;
    string Name;
    char Gender;
    string Room;
    float Scorre;

    Student() {
        ID = 0;
        Name = "null";
        Gender = 'N';
        Room = "null";
        Scorre = 0.0;
    }

    Student(int ID, string Name, char Gender, string Room, float Scorre) {
        this->ID = ID;
        this->Name = Name;
        this->Gender = Gender;
        this->Room = Room;
        this->Scorre = Scorre;
    }

    void InputInfo() {
        system("cls");
        system("color 6");
        cout << "\t\t\t[👤 ] Enter ID: ";
        cin >> ID;
        cin.ignore();
        cout << "\t\t\t[👤 ] Enter Name: ";
        getline(cin, Name);
        cout << "\t\t\t[👤 ] Enter Gender: ";
        cin >> Gender;
        cin.ignore();
        cout << "\t\t\t[👤 ] Enter Room: ";
        getline(cin, Room);
        cout << "\t\t\t[👤 ] Enter Score: ";
        cin >> Scorre;
        cin.ignore();
    }

    void ShowInfo() const {
        cout << "\t\t\t<|=================================|>\n";
        cout << "\t\t\t<| [👤 ] ID: " << ID <<"        "<< endl;
        cout << "\t\t\t<|=================================|>\n";
        cout << "\t\t\t<| [👤 ] Name: " << Name <<"  "<< endl;
        cout << "\t\t\t<|=================================|>\n";
        cout << "\t\t\t<| [👤 ] Gender: " << Gender <<"  "<< endl;
        cout << "\t\t\t<|=================================|>\n";
        cout << "\t\t\t<| [👤 ] Room: " << Room <<"   "<< endl;
        cout << "\t\t\t<|=================================|>\n";
        cout << "\t\t\t<| [👤] Score: " << Scorre <<"   "<< endl;
        cout << "\t\t\t<|=================================|>\n";
    }

    static vector<Student> ReadFromCSV(const string& filename) {
        vector<Student> result;
        ifstream file(filename);
        if (!file.is_open()) return result;

        string line;
       while (getline(file, line)) {
    istringstream iss(line);
    string idStr, name, genderStr, room, scoreStr;
    getline(iss, idStr, ',');
    getline(iss, name, ',');
    getline(iss, genderStr, ',');
    getline(iss, room, ',');
    getline(iss, scoreStr);

    if (idStr.empty() || scoreStr.empty()) continue;

    Student s;
    try {
        s.ID = stoi(idStr);
        s.Scorre = stof(scoreStr);
    } catch (const std::exception& e) {
        cerr << "[!] Skipping invalid line. Reason: " << e.what() << "\n";
        continue;
    }

    s.Name = name;
    s.Gender = genderStr.empty() ? 'N' : genderStr[0];
    s.Room = room;

    result.push_back(s);
    }
        file.close();
        return result;
    }
};

vector<Student> students;

void SaveAllToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file.\n";
        return;
    }
    for (const auto& s : students) {
        file << s.ID << "," << s.Name << "," << s.Gender << "," << s.Room << "," << s.Scorre << "\n";
    }
    file.close();
}

void AddStudent() {
    system("cls");
    system("color 4");
    cout << "\t\t\t[👤 ] Add Student:\n";
    Student s;
    s.InputInfo();
    students.push_back(s);
    SaveAllToCSV("Excel.csv");
    cout << "\n\t\t\t[✅] Student added successfully.\n";
}

void ViewAllStudents() {
    system("cls");
    system("color 3");
    if (students.empty()) {
        cout << "\t\t[!] No students found.\n";
        return;
    }
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\n\t\t\t[👤 ] Student " << i + 1 << ":\n";
        students[i].ShowInfo();
    }
}

void SearchStudent() {
    system("cls");
    system("color 2");
    cout << "\t\tSearch by (1) ID or (2) Name? > ";
    int option;
    cin >> option;
    cin.ignore();
    bool found = false;

    if (option == 1) {
        int id;
        cout << "\t\tEnter ID: ";
        cin >> id;
        cin.ignore();
        for (const auto& s : students) {
            if (s.ID == id) {
                s.ShowInfo();
                found = true;
                break;
            }
        }
    } else if (option == 2) {
        string name;
        cout << "\t\tEnter Name: ";
        getline(cin, name);
        for (const auto& s : students) {
            if (s.Name == name) {
                s.ShowInfo();
                found = true;
            }
        }
    }

    if (!found) {
        cout << "\t\t[!] Student not found.\n";
    }
}

void UpdateStudent() {
    system("cls");
    system("color 5");
    cout << "\t\tUpdate by (1) ID or (2) Name? > ";
    int option;
    cin >> option;
    cin.ignore();
    bool updated = false;

    if (option == 1) {
        int id;
        cout << "\t\tEnter ID: ";
        cin >> id;
        cin.ignore();
        for (auto& s : students) {
            if (s.ID == id) {
                cout << "\t\t[~] Enter new information:\n";
                s.InputInfo();
                updated = true;
                break;
            }
        }
    } else if (option == 2) {
        string name;
        cout << "\t\tEnter Name: ";
        getline(cin, name);
        for (auto& s : students) {
            if (s.Name == name) {
                cout << "\t\t[~] Enter new information:\n";
                s.InputInfo();
                updated = true;
            }
        }
    }

    if (updated) {
        SaveAllToCSV("Excel.csv");
        cout << "\t\t[✔] Student updated.\n";
    } else {
        cout << "\t\t[!] Student not found.\n";
    }
}

void DeleteStudent() {
    system("cls");
    system("color 4");
    cout << "\t\tDelete by (1) ID or (2) Name? > ";
    int option;
    cin >> option;
    cin.ignore();
    bool deleted = false;

    if (option == 1) {
        int id;
        cout << "\t\tEnter ID: ";
        cin >> id;
        cin.ignore();
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->ID == id) {
                students.erase(it);
                deleted = true;
                break;
            }
        }
    } else if (option == 2) {
        string name;
        cout << "\t\tEnter Name: ";
        getline(cin, name);
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->Name == name) {
                students.erase(it);
                deleted = true;
                break;
            }
        }
    }

    if (deleted) {
        SaveAllToCSV("Excel.csv");
        cout << "\t\t[✔] Student deleted.\n";
    } else {
        cout << "\t\t[!] Student not found.\n";
    }
}