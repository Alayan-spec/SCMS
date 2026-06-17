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
else cout<<"GRADE F"<<endl; }
        void displayInfo(){
            cout<<"Student Information: "<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"CNIC: "<<cnic<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Contact: "<<contact<<endl;
            cout<<"Roll No: "<<rollno<<endl;
            cout<<"Semester: "<<semester<<endl;
            cout<<"GPA: "<<gpa<<endl;}
        };
<<<<<<< HEAD
    } 
    //part 2
    class course{
        private:
        string coursecode;
        string coursename;
        int credithours;
        int maxcapacity;
        int enrolledcount;
        public:
         course(){
            enrolledcount=0;
         }
         course(string code,string name,int credit,int capacity)
         {
            courseCode=code;
            courseName=name;
            creditHours=credit;
            maxCapacity=capacity;
            enrolledCount=0;
         }
         string getcode(){
            return courseCode;
         }
         string getName(){
            return courseName;
         }
         void enrollStudent(){
            if(enrolledCount>=maxCapacity)
            throw CapacityExceededException();
            enrolledCount++;
            cout<<"Student Enrolled Sucessfully"<<endl;
         }
         bool operator==(Course c){
            if(courseCode ==c.courseCode)
            return true;

            return false;
         }
         operator<<friend ostream&operator<<(ostream&out, Course c)
         {
            out<<"\nCourse Code:"<<
         }
    }
=======
        class faculty:public person {
            private:
            string employeeID;
            string department;
            string designation;
            public:
            faculty(){}
            faculty(string n,string c,int a,string con,string id,string dept,string des):person(n,c,a,con){
                employeeID=id;
                department=dept; }
            void displayInfo(){
                cout<<"Faculty Information: "<<endl;
                cout<<"Name: "<<name<<endl;
                cout<<"Employee ID: "<<employeeID<<endl;
                cout<<"department "<<department<<endl;
                cout<<"designation "<<designation<<endl;    }
        };
        class staff:public person {
            private:
            string staffID;
            string role;
            string salary;
            public:
            staff(){}
            staff(string n,string c,int a,string con,string id,string r,double s):person(n,c,a,con){
                staffID=id;
                role=r;
                salary=s; }
            void displayInfo(){
                cout<<"Staff Information: "<<endl;
                cout<<"Name: "<<name<<endl;
                cout<<"Staff ID: "<<staffID<<endl;
                cout<<"Role: "<<role<<endl;
                cout<<"Salary: "<<salary<<endl;}
    };
    Student students[100];
    faculty faculty members[50];
    staff staff members[50];
    int studentCount = 0;
    int facultyCount = 0;
    int staffCount = 0;
>>>>>>> 0de68080b063f40e107f1eaded6fc27a38b5b639
