#include<iostream>
#include<limits>
#include<windows.h>
#include "Login_Logout.cpp"
using namespace std;
const string FILENAME = "Excel.csv";
int main(){
    students = Student::ReadFromCSV("Excel.csv");
    if (students.empty()) {
        cout << "\t\t\t[!] No students found in the file.\n";
    } else {
        cout << "\t\t\t[✔] Students loaded successfully.\n";
    }

    SystemAuth auth;
    string name;
    string pws;

    int choice , choice1, choice2;
    SetConsoleOutputCP(CP_UTF8);
    Teacher t;
  
  
  
    do{
        Header();
        Option();
        // cin>>choice;
            try {
            cin >> choice;
            if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Invalid input. Please enter a number.");
            }
            switch (choice) {
                case 2:
                 do {
                    Header();
                    Option1();
                    try{
                        cin>>choice1;
                        if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw runtime_error("Invalid input. Please enter a number.");
                        }
                    switch (choice1) {
                        case 1:
                            SignUp(auth);
                            system("pause");
                            break;
                        case 2:
                            Student(auth);
                            system("pause");
                            break;
                        case 3:
                            cout << "\t\t\t[↩] Returning to main menu...\n";
                            break;
                        default:
                            cout << "\t\t\t[!] Invalid choice. Please try again.\n";
                    }
                    }catch (const runtime_error& e) {
                        cout << "[!] " << e.what() << endl;
                        }
                } while (choice1 != 3);
                case 1:
                    do {
                        Header();
                        Option1_1();
                        try{
                            cin>>choice2;
                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                throw runtime_error("Invalid input. Please enter a number.");
                            }
                        switch (choice2) {
                            case 1:
                                t.loginTeacher();
                                system("pause");
                                break;
                            case 2:
                                cout << "\t\t\t[↩] Returning to main menu...\n";
                                break;
                            default:
                                cout << "\t\t\t[!] Invalid choice. Please try again.\n";
                        }
                        }catch(const runtime_error& e) {
                            cout << "[!] " << e.what() << endl;
                        }
                    } while (choice2 != 2);
                    break;

                case 3:
                    cout << "\t\t\t[➖] Exiting...\n";
                    break;

                default:
                    cout << "\t\t\t[!] Invalid choice. Please try again.\n";
        }
        } catch (const runtime_error& e) {
        cout << "[!] " << e.what() << endl;
        }

   }while(choice != 3);


    return 0;
}