#include<iostream>
#include<windows.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

#include <conio.h>
#include "Option.cpp"
using namespace std;
void Header(){
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
void Option(){ 
    cout<<"\t\t\t[1] TEACHER 🧑‍🏫"<<endl;
    cout<<"\t\t\t[2] STUDENT 🧑‍🎓"<<endl;
    cout<<"\t\t\t[3] Exite ❕"<<endl;
    cout<<"\t\t\t[🫴 ] Choose an option: ";
}
void Option1(){
    system("color 5");
    cout<<"\t\t\t[1] Sign Up"<<endl;
    cout<<"\t\t\t[2] Login"<<endl;
    cout<<"\t\t\t[3] Back"<<endl;
    cout<<"\t\t\t[🫴 ] Choose an option: ";
    
}
void Option1_1(){
    system("color 5");
    cout<<"\t\t\t[1] Login"<<endl;
    cout<<"\t\t\t[2] Back"<<endl;
    cout<<"\t\t\t[🫴 ] Choose an option: ";
}
void Option2(){

    system("color 5");
    cout<<"\t\t\t[1] Add Student"<<endl;
    cout<<"\t\t\t[2] Search Student  (By ID / Name)"<<endl;
    cout<<"\t\t\t[3] Update Student  (By ID / Name)"<<endl;
    cout<<"\t\t\t[4] Deleted Student (By ID / Name)"<<endl;
    cout<<"\t\t\t[5] View All Student"<<endl;
    cout<<"\t\t\t[6] Back"<<endl;
    cout<<"\t\t\t[🫴 ] Choose an option: ";
}
void StudentOption(){
    system("color 5");
    cout<<"\t\t\t[1] View Room Studying"<<endl;
    cout<<"\t\t\t[2] View Subject to Studying"<<endl;
    cout<<"\t\t\t[3] View Information detail"<<endl;
    cout<<"\t\t\t[4] Back"<<endl;
    cout<<"\t\t\t[🫴 ] Choose an option: ";
}
void ViewRoom(){
    system("cls");
    system("color 2");
    Header();
    cout << "\t\t\t|----------------------------------------------------|" <<endl;
    cout << "\t\t\t| [🧑‍🏫] VIEW ROOM STUDYING                           |"<<endl;
    cout << "\t\t\t|____________________________________________________|" <<endl;
    cout<<"\t\t\t\t[🧑‍🏫] Data Stutor"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫] Fronend Leab"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫] Blookchin"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫] Backend leab"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫] Cyber Security"<<endl;

}
void ViewSubject(){
    system("cls");
    system("color 3");
    Header();
    cout << "\t\t\t|----------------------------------------------------|" <<endl;
    cout << "\t\t\t| [🧑‍🏫] VIEW SUBJECT TO STUDYING                      |"<<endl;
    cout << "\t\t\t|____________________________________________________|" <<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Introduction to Information and Technolgoy"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Programming Fundamental"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Intensive English Program I"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Academic Skill Developmentb"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Multimedia and Web Design"<<endl;
    cout<<"\t\t\t\t[🧑‍🏫]  Networking Fundamental"<<endl;
}
void ViewScore(){
    system("cls");
    system("color 2");
    cout << "\t\t\t Input option to view info detail (1) ID or (2) Name? > ";
    int option;
    cin >> option;
    cin.ignore();
    bool found = false;

    if (option == 1) {
        int id;
        cout << "\t\tEnter ID: ";
        cin >> id;
        cin.ignore();

        for (auto& s : students) {
            if (s.ID == id) {
                s.ShowInfo();
                found = true;
                break;
            }
        }
    }
    else if (option == 2) {
        string name;
        cout << "\t\tEnter Name: ";
        getline(cin, name);

        for (auto& s : students) {
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


struct User {
    string username;
    string password;
};
class UserAuth {
public:
    virtual void signUp(const string& username, const string& password) = 0;
    virtual void login(const string& username, const string& password) = 0;
    virtual void StudentLogin(const string& username, const string& password) = 0;
    virtual ~UserAuth() {}
};
     
class SystemAuth : public UserAuth {
private:
    vector<User> users;
    bool isLoggedIn = false;
    string currentUser;
    const string fileName = "users.txt";

    bool userExists(const string& username) {
        for (const auto& user : users) {
            if (user.username == username)
                return true;
        }
        return false;
    }

    void loadUsersFromFile() {
        users.clear();
        ifstream file(fileName);
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password) {
                users.push_back({username, password});
            }
        }
        file.close();
    }

    void saveUserToFile(const string& username, const string& password) {
        ofstream file(fileName, ios::app);
        file << username << " " << password << endl;
        file.close();
    }

       public:
           SystemAuth() {
               loadUsersFromFile();
           }
           void signUp(const string& username, const string& password) override {
                if (userExists(username)) {
                    cout << "\t\t[!] Username already exists.\n";
                    return;
                }
                users.push_back({username, password});
                saveUserToFile(username, password);
                cout << "\t\t[✔] User signed up successfully.\n";
            }

            void StudentLogin(const string& username, const string& password) override {
               int option;
               for (const auto& user : users) {
                   if (user.username == username && user.password == password) {
                       isLoggedIn = true;
                       currentUser = username;
                       system("cls");
                       cout << "\t\t\t|----------------------------------------------------|" <<endl;
                       cout << "\t\t\t| [✅] Login successful. Welcome Student  " << currentUser <<"    |"<<endl;
                       cout << "\t\t\t|____________________________________________________|" <<endl;
                       do{
                           StudentOption();
                        try{
                        cin >> option;
                        if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw runtime_error("Invalid input. Please enter a number.");
                        }
                          switch (option) {
                            case 1:
                                    system("cls");
                                    Header();
                                    ViewRoom();
                                    system("pause");
                             break;
                            case 2:
                                    system("cls");
                                    Header();
                                    ViewSubject();
                                    system("pause");
                            break;
                            case 3:
                                    ViewScore();
                             break;
                            case 4:cout << "\t\t[✔] Exiting...\n"; break;
                            default: cout << "\t\t[!] Invalid option.\n"; break;
                            }
                        }catch (const runtime_error& e) {
                        cout << "[!] " << e.what() << endl;
                        }
                         } while (option != 4);
                        return;
                   }
               }
               cout << "Invalid username or password.\n";
           }
           void login(const string& username, const string& password) override {
            //    int option;
            //    for (const auto& user : users) {
            //        if (user.username == username && user.password == password) {
            //            isLoggedIn = true;
            //            currentUser = username;
            //            system("cls");
            //            cout << "\t\t\t|----------------------------------------------------|" <<endl;
            //            cout << "\t\t\t| [✅] Login successful. Welcome Theacher  " << currentUser <<"    |"<<endl;
            //            cout << "\t\t\t|____________________________________________________|" <<endl;
            //            do{
            //                Option2();
            //                try{
            //                    cin >> option;
            //                    if(cin.fail()){
            //                     cin.clear();
            //                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //                     throw runtime_error("Invalid input. Please enter a number.");
            //                    }

                          
            //                cin.ignore();
            //               switch (option) {
            //                 case 1:AddStudent(); break;
            //                 case 2:SearchStudent(); break;
            //                 case 3:UpdateStudent(); break;
            //                 case 4:DeleteStudent(); break;
            //                 case 5:ViewAllStudents(); break;
            //                 case 6:cout << "\t\t[✔] Exiting...\n"; break;
            //                 default: cout << "\t\t[!] Invalid option.\n"; break;
            //              }
            //             }catch(const runtime_error& e){
            //                 cout << "[!] " << e.what() << endl;
            //             }
            //           } while (option != 6);
            //            return;
            //        }
            //    }
            //    cout << "Invalid username or password.\n";
           }
          
};
string getHiddenInput() {
    string pin;
    char ch;
    while ((ch = _getch()) != '\r') {  // '\r' is the Enter key
        if (ch == '\b') {  // Handle backspace
            if (!pin.empty()) {
                cout << "\b \b";  // Erase the last asterisk
                pin.pop_back();  // Remove last character from the string
            }
        } else {
            pin.push_back(ch);  // Add character to the string
            cout << '*';   // Print asterisk
        }
    }
    cout << endl;  // Move to the next line after Enter is pressed
    return pin;
}
   void Login(SystemAuth& auth) {
           cin.ignore();
           string username, password;
           cout << "\t\t\t[👤 ] Enter username: ";
           getline(cin, username);
           cout << "\t\t\t[🔑 ] Enter password: ";
           getline(cin, password);
           auth.login(username, password);
}

 
void SignUp(SystemAuth& auth) {
           cin.ignore();
           string username, password;
           cout << "\t\t\t[👤 ] Enter username: ";
           getline(cin, username);
           cout << "\t\t\t[🔑 ] Enter password: ";
           password = getHiddenInput();
           auth.signUp(username, password);
}       
       void Student(SystemAuth& auth) {
           cin.ignore();
           string username, password;
           cout << "\t\t\t[👤 ] Enter username: ";
           getline(cin, username);
           cout << "\t\t\t[🔑 ] Enter password: ";
           password = getHiddenInput();
           auth.StudentLogin(username, password);
}  




class Teacher {
private:
    string name = "Teacher";
    string pwd = "123456";

public:
    Teacher() {}

    Teacher(string name, string password) {
        this->name = name;
        this->pwd = password;
    }

    void loginTeacher() {
        string username, password;
        while (true) {
            system("cls");
            Header();
            cout << "\n\t\t\t\t\t\t+---------------------------------------------------------+\n";
            cout << "\t\t\t\t\t\t|                      Teacher Login                      |\n";
            cout << "\t\t\t\t\t\t+---------------------------------------------------------+\n";
            cout << "\t\t\t\t\t\t => Enter username: ";
            cin >> username;
            cout << "\t\t\t\t\t\t => Enter password: ";
            password = getHiddenInput();
            if (username == name && password == pwd) {
                cout << "\n\t\t\t\t\t\t[✔] Login successful!\n";
                break;
            } else {
                cout << "\n\t\t\t\t\t\t[!] Invalid credentials. Try again.\n";
                system("pause");
            }
        }

        showTeacherMenu();
    }

    void showTeacherMenu() {
        int option;
        do {
            system("cls");
            Header();
            Option2();
            cin >> option;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[!] Invalid input. Please enter a number.\n";
                system("pause");
                continue;
            }
            switch (option) {
                case 1: AddStudent(); break;
                case 2: SearchStudent(); break;
                case 3: UpdateStudent(); break;
                case 4: DeleteStudent(); break;
                case 5: ViewAllStudents(); break;
                case 6: cout << "\n\t\t\t[✔] Exiting Teacher Menu...\n"; break;
                default: cout << "[!] Invalid option.\n"; break;
            }

        } while (option != 6);
    }
}; 

