#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
// #include "Login_Logout.cpp"
using namespace std;
void Header1(){
system("color 0a");
system("cls");
cout<<" ____    _____   _   _   ____    _____   _   _   _____        __  __        ____        ____   __   __  ____    _____   _____   __  __ "<<endl;
cout<<"/ ___|  |_   _| | | | | |  _ \\  | ____| | \\ | | |_   _|      |  \\/  |      / ___|      / ___|  \\ \\ / / / ___|  |_   _| | ____| |  \\/  |"<<endl;
cout<<"\\___ \\    | |   | | | | | | | | |  _|   |  \\| |   | |        | |\\/| |     | |  _       \\___ \\   \\ V /  \\___ \\    | |   |  _|   | |\\/| |"<<endl;
cout<<" ___) |   | |   | |_| | | |_| | | |___  | |\\  |   | |        | |  | |  _  | |_| |       ___) |   | |    ___) |   | |   | |___  | |  | |"<<endl;
cout<<"|____/    |_|    \\___/  |____/  |_____| |_| \\_|   |_|        |_|  |_| (_)  \\____|      |____/    |_|   |____/    |_|   |_____| |_|  |_|"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
}
// ==================================================================== Validation Functions ====================================================================
// validation ID
bool isValidAge(const string &str){
    if (str.empty()) return false;
    for (char c : str){
        if(!isdigit(c)) return false;
    }
    return true;
}
int getValidatedID() {
    string input;
    int ID;
    while(true){
        cout << "\t\t\t[👤 ] => Enter ID: ";
        getline(cin , input);

        if(!isValidAge(input)) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Please enter id......." << endl;
        } else {
            ID = stoi(input);
            if (ID < 0 || ID > 12000){
                cout << "\t\t\t\t\t\t\t\t\t\t\t [!]ID must be between 0 and 12000. Please try again. " << endl;
            } else {
                break;
            }
        }

    }
    return ID;
}
// validation Score
float getValidatedScore() {
    string input;
    float Score;

    while(true){
        cout << "\t\t\t[👤 ] => Enter Score: ";
        getline(cin , input);

        if(!isValidAge(input)) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Please enter Score......." << endl;
        } else {
            Score = stoi(input);
            if (Score < 0 || Score > 100){
                cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Age must be between 0 and 100. Please try again. " << endl;
            } else {
                break;
            }
        }

    }
    return Score;
}
// validation Name
string getValidatedName() {
    string fullName;
    bool isValid;

    while (true) {
        cout << "\t\t\t[👤 ] => Enter Name: ";
        getline(cin, fullName);

        isValid = true;
        if (fullName.empty()) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Please enter a  name......\n";
            isValid = false;
        } else {
            for (char c : fullName) {
                if (!isalpha(c) && !isspace(c)) {
                    isValid = false;
                    cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Invalid name. Only letters and spaces are allowed." << endl;
                    break;
                }
            }
        }

        if (isValid) {
            return fullName;
        }
    }
}
// validation room
string getValidatedRoom() {
    string fullRoom;
    bool isValid;

    while (true) {
        cout << "\t\t\t[👤 ] => Enter Room: ";
        getline(cin, fullRoom);

        isValid = true;
        if (fullRoom.empty()) {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Please enter a  Room......\n";
            isValid = false;
        } else {
            for (char c : fullRoom) {
                if (!isalpha(c) && !isspace(c)) {
                    isValid = false;
                    cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Invalid Room. Only letters and spaces are allowed." << endl;
                    break;
                }
            }
        }

        if (isValid) {
            return fullRoom;
        }
    }
}
// validation Gender
string getValidatedGender() {
    
    string gender;
    while (true) {
        cout << "\t\t\t[👤 ] => Enter Gender (M/F): ";
        getline(cin, gender);
        if (gender == "M" || gender == "F") {
            return gender; // Return valid gender
        } else if(gender.empty())  {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Please input a gender......." << endl;
        } else {
            cout << "\t\t\t\t\t\t\t\t\t\t\t [!]Invalid gender. Please enter 'M' for Male or 'F' for Female." << endl;
        }
    }
}


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
        // cout << "\t\t\t[👤 ] Enter ID: ";
        // cin >> ID;
        // cin.ignore();
        // cout << "\t\t\t[👤 ] Enter Name: ";
        // getline(cin, Name);
        // cout << "\t\t\t[👤 ] Enter Gender: ";
        // cin >> Gender;
        // cin.ignore();
        // cout << "\t\t\t[👤 ] Enter Room: ";
        // getline(cin, Room);
        // cout << "\t\t\t[👤 ] Enter Score: ";
        // cin >> Scorre;
        // cin.ignore();
        ID = getValidatedID();
        Name = getValidatedName();
        Gender = getValidatedGender()[0];
        Room = getValidatedRoom();
        Scorre = getValidatedScore();
        
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
    Header1();
    system("color 4");
    cout << "\t\t\t[👤 ] Add Student:\n";
    Student s;
    s.InputInfo();
    students.push_back(s);
    SaveAllToCSV("Excel.csv");
    cout << "\n\t\t\t[✅] Student added successfully.\n";
    system("pause");
    system("cls");
    Header1();
  
}

void ViewAllStudents() {
    system("cls");
    Header1();
    system("color 3");
    if (students.empty()) {
        cout << "\t\t[!] No students found.\n";
        return;
    }
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\n\t\t\t[👤 ] Student " << i + 1 << ":\n";
        students[i].ShowInfo();
    }
    system("pause");
    system("cls");
    Header1();
}

void SearchStudent() {
    system("cls");
    Header1();
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
    system("pause");
    system("cls");
    Header1();
}

void UpdateStudent() {
    system("cls");
    Header1();
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
    system("pause");
    system("cls");
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
    system("pause");
    system("cls");
    Header1();
}