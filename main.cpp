#include "iostream"
#include "vector"

using namespace std;

struct Student
{
    string name;
    int grade;
};

void menu() {
    cout << "Gradebook Manager" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Calculate avarage grade" << endl;
}

Student create_student() 
{
    Student student;
 
    cout << "Enter name: " << endl;
    cin >> student.name;

    cout << "Enter grade: " << endl;
    cin >> student.grade;

    return student;
}

void display_students(vector<Student>* students) 
{  
    for (int i = 0; i < students->size(); i++) {
        cout << "Name: " << students->at(i).name << "  " << "Grade: " << students->at(i).grade << endl;
    }
}

void avarage(vector<Student>* students) 
{
    int sum = 0;
    int avarage = 0;
    for (int i = 0; i < students->size(); i++) {
        sum+=students->at(i).grade;
    }
    cout << "Avarage is " << (students->empty() ? 0 : sum / students->size()) << endl;
}

int main() 
{
    vector<Student> students;
    int choice;

    do {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            students.push_back(create_student());
            break;
        case 2:
            display_students(&students);
            break;
        case 3:
            avarage(&students);
            break;
        }
    } while(choice);

    return 0;
}
