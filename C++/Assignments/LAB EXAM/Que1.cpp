#include <iostream>
using namespace std;

class Student {
private :

    int rollNumber;
    string name;
    double percentage; 
    static int totalStudent;

public :

    Student(int roll, const string& studentName) {
    double percentage = 0;
    totalStudents++;
    cout << "Roll No : " << rollNumber << "Name :" << name << endl;
    }

    Student&(int rollNumber, const string& studentNmae) {
    double percentage = 0;
    totalStudents++;
    cout << "Roll No : " << rollNumber << "Name :" << name << endl;
    }

    ~Sudent(int roll) {
        cout << "Roll Number" << rollNumber;
    }

    void setPercentage(double percent) {
        if(percent >= 0 && percent <= 100){
            cout << percent << endl;
        }

        }

    double getPercentage() const {
            
            return;
        }


    char calculateGrade(double percent) const {

            if(percent >=80) {
                return 'A';
            } else if(percent>=70 && percent<=79){
                return 'B';
            } else if(percent>=60 && percent<=69){
                return 'C';
            } else if(percent>=50 && percent<=59){
                return 'D';
            } esle {

                return 'F';
            }

            }

           friend Stream Operator operator<<(int rollNumer, string& name, double percentage, string grade) {

                cout << "Roll Number" << rollnumber << endl;
                cout << "Name" << Name << endl;
                cout << "percentage" << percentage << endl;
                cout << "Grade" << grade << endl;
           }
            
        

};

int main() {


        vector<Student> s1;
        vector<Student> s2;
        vector<Student> s3;
        vector<Student> s4;
        vector<Student> s5;

        getpercentage();

}