class course {
private:
    string courseCode;
    string courseName;
    int creditHours;
    int maxCapacity;
    int enrolledCount;
public:
        Course() {
        enrolledCount = 0;
    }
    Course(string code, string name, int credit, int capacity)
    {
        courseCode = code;
        courseName = name;
        creditHours = credit;
        maxCapacity = capacity;
        enrolledCount = 0;
    }
    string getCode() {
        return courseCode;
    } 
    string getName() {
        return courseName;
    }
    void enrollStudent() {
        if(enrolledCount >= maxCapacity)
         throw CapacityExceededException();
        enrolledCount++;
        cout<<"Student Enrolled Sucessfully"<<endl;
    }
    bool operator==(Course c) {
     if(courseCode == c.courseCode)
      return true;
        return false;
    }
    Friend ostream& operator<<(ostream& out,  Course c)
    {
     cout<<"\nCourse Code: "<<c.courseCode;
      cout<<"\nCourse Name: " <<c.courseName;
      cout<<"\nCredit Hours: "<<c.creditHours;
      cout<<"\nMax Capacity: "<<c.maxCapacity;
      cout<<"\nEnrolled: "<<c.enrolledCount<<endl;
        return out;
    }
};
class Enrollment {
private:
    string rollNo;
    string courseCode;
    string grade;
public:
    Enrollment() {}
    Enrollment(string r,string c,string g);
    {
        rollNo = r;
        courseCode = c;
        grade = g;
    }
    void DisplayEnrollment() {
     cout<<"\nEnrollment Record"<<endl;
     cout<<"Roll No:" <<rollNo<<endl;
     cout<<"Course Code:" <<courseCode<<endl;
    cout<<"Grade: " <<grade<<endl;
    }
};
Course courses[50];
Enrollment enrollments[200];
int courseCount = 0;
int enrollmentCount = 0;
void addCourse() {
    string code;
    string name;
    int credit;
    int capacity;
    cout<<"Course Code: ";
    cin>>code;
    cin.ignore();
    cout<<"Course Name: ";
    getline(cin,name);
    cout<<"Credit Hours: ";
    cin>>credit;
    cout<<"Max Capacity: ";
    cin>>capacity;
    courses[courseCount] =Course(code,name,credit,capacity);
     courseCount++;
    cout<<"Course Added"<<endl;
}
void DisplayCourses() {
    if(courseCount==0) {
        cout<<"No Courses Found"<<endl;
        return;
    }
for(int i=0;i<courseCount;i++) {
   cout<<courses[i];
    }
}
void searchCourse() {
 string code;
 cout<<"Enter Course Code: ";
    cin>>code;
    for(int i=0;i<courseCount;i++) {
        if(courses[i].getCode()==code) {
            cout<<courses[i];
            return;
        }
    }
    cout<<"Course Not Found"<<endl;
}
void EnrollInCourse() {
    string roll;
    string code;
    string grade;
    cout<<"Student Roll No: ";
    cin>>roll;
    cout<<"Course Code: ";
    cin>>code;
    cout<<"Grade: ";
    cin>>grade;
    try {
        for(int i=0;i<courseCount;i++) {
            if(courses[i].getCode()==code) {
                courses[i].enrollStudent();
                enrollments[enrollmentCount]
                = Enrollment( roll, code,grade);
                enrollmentCount++;
                return;
            }
        }
        cout<<"Course Not Found"<<endl;
    }
    catch(CapacityExceededException e) {
        e.showMessage();
    }
}
void displayEnrollments() {
    for(int i=0;i<enrollmentCount;i++) {
        enrollments[i].
        displayEnrollment();
    }
}
.....................
ssclass libraryitem {
protected:
    int itemID;
    string title;
    string author;
    int publicationYear;
public:
    LibraryItem() {}
    LibraryItem(int id,string t, string a, int year)
    {
        itemID = id;
        title = t;
        author = a;
        publicationYear = year;
    }
    string getTitle() {
    return title;
    }
    int getID() {
    return itemID;
    }
    virtual void checkout() = 0;
    virtual void display() = 0;
    virtual LibraryItem() {}
};
class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int copiesAvailable;
public:
    Book() {}
    Book(int id,
         string t,
         string a,
         int year,
         string is,
         string g,
         int copies)
    LibraryItem(id,t,a,year)
    {
        isbn = is;
        genre = g;
        copiesAvailable = copies;
    }
    void checkout() {
        if(copiesAvailable > 0) {
            copiesAvailable--;  cout<<"Book Issued"<<endl;
        }
        else {
            cout<<"No Copies Available"<<endl;
        }
    }
    void display() {
        cout<<"\n----- BOOK -----"<<endl;
        cout<<"ID: " <<itemID<<endl;
        cout<<"Title: " <<title<<endl;
        cout<<"Author: " <<author<<endl;
        cout<<"Year: "<<publicationYear<<endl;
        cout<<"ISBN: " <<isbn<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"Copies: " <<copiesAvailable<<endl;
    }
};
class Journal : public LibraryItem {
private:
    string issn;
    int volume;
    int issueNumber;
public:
    journal() {}
    journal(int id,
            string t,
            string a,
            int year,
            string is,
            int vol,
            int issue)
            : LibraryItem(id,t,a,year)
    {
        issn = is;
        volume = vol;
        issueNumber = issue;
    }
    void checkout() {
        cout<<"Journal Issued"<<endl;
    }
    void display() {
        cout<<"\n----- JOURNAL -----"<<endl;
        cout<<"ID: "<<itemID<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Year: "<<publicationYear<<endl;
        cout<<"ISSN: " <<issn<<endl;
        cout<<"Volume: "<<volume<<endl;
        cout<<"Issue Number: " <<issueNumber<<endl;
    }
};
Book books[100];
Journal journals[100];
int bookCount = 0;
int journalCount = 0;
void addBook() {
    int id;
    string title;
    string author;
    int year;
    string isbn;
    string genre;
    int copies;
    cout<<"Book ID: ";
    cin>>id;
    cin.ignore();
    cout<<"Title: ";
     getline(cin,title);
    cout<<"Author: ";
    getline(cin,author);
    cout<<"Publication Year: ";
    cin>>year;
    cout<<"ISBN: ";
    cin>>isbn;
    cout<<"Genre: ";
    cin>>genre;
    cout<<"Copies: ";
    cin>>copies;
    books[bookCount] =
    Book(id,title,author, year,isbn, genre,copies);
    bookCount++;
    cout<<"Book Added"<<endl;
}
void displayBooks() {
    if(bookCount==0) {
        cout<<"No Books Found"<<endl;
        return;
    }
    for(int i=0;i<bookCount;i++) {
         books[i].display();
    }
}
void searchBookByTitle() {
    string searchTitle;
    cin.ignore();
    cout<<"Enter Title: ";
    getline(cin,searchTitle);
    for(int i=0;i<bookCount;i++) {
        if(books[i].getTitle()==searchTitle)
        {
            books[i].display();
            return;
        }
    }
    cout<<"Book Not Found"<<endl;
}
void Save Library Data() {
    ofstream file( "library.txt" );
    for(int i=0;i<bookCount;i++) {
        file<<books[i].getID()<<" " <<books[i].getTitle() <<endl;
    }
    file.close();
    cout<<"Library Saved"<<endl;
}
void loadLibraryData() {
    ifstream file9(library.txt" );
    string line;
    cout<<"\nLibrary File Data\n";
    while(getline(file,line) )
    {
        cout<<line<<endl;
    }
    file.close();
}
void issueBook() {
    int id;
    cout<<"Enter Book ID: ";
    cin>>id;
    for(int i=0;i<bookCount;i++) {
        if( books[i].getID() == id )
        {
            books[i].checkout();
            return;
        }
    }
    cout<<"Book Not Found"<<endl;
}
.................................................
class FeeRecord {
private:
    string rollNo;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;
public:
    FeeRecord() {
        semesterFee = 0;
        hostelFee = 0;
        libraryFine = 0;
        totalPaid = 0;
        balance = 0;
    }
    FeeRecord(string roll, double semFee,double hostFee, double fine)
    {
        rollNo = roll;
        semesterFee = semFee;
        hostelFee = hostFee;
        libraryFine = fine;
        totalPaid = 0;
        balance =semesterFee + hostelFee + libraryFine;
    }
    FeeRecord(const FeeRecord &obj) {
        rollNo = obj.rollNo;
        semesterFee =obj.semesterFee;
        hostelFee = obj.hostelFee;
        libraryFine = obj.libraryFine;
        totalPaid = obj.totalPaid;
        balance =obj.balance;
    }
    FeeRecord&operator=(const FeeRecord &obj)
    {
        rollNo = obj.rollNo;
        semesterFee = obj.semesterFee;
        hostelFee =obj.hostelFee;
        libraryFine = obj.libraryFine;
        totalPaid = obj.totalPaid;
        balance = obj.balance;
        return *this;
    }
    void operator-=(double amount) {
        totalPaid += amount;balance -= amount;
    }
    string getRollNo() {
        return rollNo;
    }
    double getBalance() {
        return balance;
    }
    void displayFee() {
        cout<<"\n----- FEE RECORD -----" <<endl;
        cout<<"Roll No: " <<rollNo<<endl;
        cout<<"Semester Fee: " <<semesterFee<<endl;
        cout<<"Hostel Fee: " <<hostelFee<<endl;
        cout<<"Library Fine: " <<libraryFine<<endl;
        cout<<"Total Paid: "<<totalPaid<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
class Invoice {
private:
    static int invoiceCounter;
    int invoiceID;
    string rollNo;
    double amount;
public:
    Invoice() {}
    Invoice(string roll,double amt)
    {
        invoiceCounter++;
        invoiceID =
        invoiceCounter;
        rollNo = roll;
        amount = amt;
    }
    void displayInvoice() {
        cout<<"\n----- INVOICE -----" <<endl;
        cout<<"Invoice ID: " <<invoiceID<<endl;
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Amount:"<<amount<<endl;
    }
    Invoice() {
    }
};
int Invoice::
invoiceCounter = 0;
FeeRecord fees[100];
Invoice invoices[100];
int feeCount = 0;
int invoiceCount = 0;
void addFeeRecord() {
    string roll;
    double semFee;
    double hostFee;
    double fine;
    cout<<"Roll No: ";
    cin>>roll;
    cout<<"Semester Fee: ";
    cin>>semFee;
    cout<<"Hostel Fee: ";
    cin>>hostFee;
    cout<<"Library Fine: ";
    cin>>fine;
    fees[feeCount] = FeeRecord(roll,semFee,hostFee,fine );
    feeCount++;
    cout<<"Fee Record Added" <<endl;
}
void displayFeeRecords() {
    if(feeCount==0) {
        cout<<"No Fee Records" <<endl;
        return;
    }
    for(int i=0;i<feeCount; i++)
    {
        fees[i]. displayFee();
    }
};
void payFee() {
    string roll;
    double amount;
    cout<<"Roll No: ";
    cin>>roll;
    cout<<"Payment Amount: ";
    cin>>amount;
    for(int i=0; i<feeCount; i++)
    {
        if(fees[i]. getRollNo() ==roll )
        {
            fees[i]  -= amount;
            invoices [invoiceCount] = Invoice(roll,amount );
            invoiceCount++;
            cout<<"Payment Recorded" <<endl;
            return;
        }
    }
    cout<<"Student Not Found" <<endl;
}
void displayInvoices() {
    if(invoiceCount==0) {
        cout<<"No Invoices"<<endl;
        return;
    }
    for(int i=0; i<invoiceCount;i++)
    {
        invoices[i].displayInvoice();
    }
    }