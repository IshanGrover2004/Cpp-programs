/*  Implement a class called "Student" with attributes name, roll number, and marks in three subjects.
    Write member functions to calculate the total marks and average marks of the student.   */

#include <iostream>
#include <string>
using namespace std;

class student{
    private:
        string name;
        int roll_number;
        float m1,m2,m3;
        double total_marks,average_marks;

    public:
        void get_info(void){
            cout<<endl<<"Name of student: ";
            cin>>name;

            cout<<"Roll number: ";
            cin>>roll_number;
            
            cout<<"Marks in subject 1 : ";
            cin>>m1;
            cout<<"Marks in subject 2 : ";
            cin>>m2;
            cout<<"Marks in subject 3 : ";
            cin>>m3;
        }

        double total_mark(void){
            total_marks = m1 + m2 + m3;
            return total_marks;
        }
        double average_mark(void){
            average_marks = total_marks / 3;
            return average_marks;
        }


        void display_info(void){
            cout<<endl<<"==============================="<<endl;
            cout<<"Name of student: "<<name<<endl;
            cout<<"Roll number: "<<roll_number<<endl;
            cout<<"Marks in subject 1 : "<<m1<<endl;
            cout<<"Marks in subject 2 : "<<m2<<endl;
            cout<<"Marks in subject 3 : "<<m3<<endl;
            cout<<"Total marks : "<<total_mark()<<endl;
            cout<<"Average marks : "<<average_mark()<<endl;

        }

};

int main(){
    char choice = 'y';
    while(choice=='y' || choice=='Y'){
        student b1;
        b1.get_info();
        b1.display_info();

        cout<<endl;
        cout<<"Do u want to put more data of student(y/n): ";
        cin>>choice;
    }
}