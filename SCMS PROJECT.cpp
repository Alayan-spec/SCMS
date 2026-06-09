#include<iostream>
#include<fstream>
#include<string>

using namespace std;
   class exception {
public:
    void showMessage() {
        cout << "Course Capacity Full!" << endl;
    }
   };
class person{
    protected:
    string name;
    string cnic;
    int age;
    string contract;
    public:
    person(){}
    person(string n,string c,int a,string con){
        name=n;
        cnic=c;
        age=a;
        contact=con;
    }
    virtual void displayInfo()=0;
    virtual ~person(){}

    };
    class student:public person {
        private:
        string roll no;
        int semester;
        float gpa;
        public:
        student(){}
        student (string n,string c,int a,string con,string roll,int sem,float g) : person(n,c,a,con)
        {
            rollno=roll;
            semester=sem;
            gpa=g;
        }
        string getRollNo(){
            return rollno;
        }
        float GPA(){
            return gpa;
        }
        void calculateGrade(){
            if(gpa>=3.5)
            cout<<"GRADE A"<<endl;
        else if(gpa>3.0)
        cout<<"GRADE B"<<endl;
    else if(gpa>=2.0)
    cout<<"GRADE C"<<endl;
else cout<<"GRADE F"<<endl;}

        };
    }


