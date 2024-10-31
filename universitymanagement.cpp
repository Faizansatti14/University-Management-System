#include<iostream>
#include<cstring>
#include<fstream>
#include<conio.h>
using namespace std;
int pass(int n) //Function used to get passwords check them and return wether it is correct or not
{
    char password[12];//variable to store password
    char ch;
    int cmp;
    cout<<"Enter password\n";
    for(int i=0;;)
    {
        ch=getch();//getch is a function which takes in character but doesnot display it
        password[i]=ch;//storing the entered character in password
        if(ch==13)//13 is the ascii value of new line hence when enter is pressed it exits the for loop
        {
            password[i]='\0';
            break;
        }
        cout<<"*";//as we dont display the characte * is being displayed
        i++;
    }
    switch(n)//takes the control to required department
    {
        case 3:
        {
            cmp=strcmp(password,"academic");
            if(cmp==0)//checking the acadamic password
            {
                return 1;
            }
            break;
        }
        case 4:
        {
            cmp=strcmp(password,"department");
            if(cmp==0)//checking department password
            {
                return 1;
            }
            break;
        }
        case 5:
        {
            cmp=strcmp(password,"hrmaneger");
            if(cmp==0)//checking hr password
            {
                return 1;
            }
            break;
        }
        case 6:
        {
            cmp=strcmp(password,"finance");
            if(cmp==0)//checking finance passsword
            {
                return 1;
            }
            break;
        }
        case 7:
        {
            cmp=strcmp(password,"library");
            if(cmp==0)//checking library password
            {
                return 1;
            }
            break;
        }
    }
    return 0;//If the passwords are correct to the respective departments it returns 1
    //if not returns 0
}
class student
{
    protected://protected members of the student class
    char name[30];//name of the student
    int marks[6],att[6],dept_code;//marks attendence and department code
    int pay; //fee paid vairiable
    public://public members
    char usn[11];//usn is made public as it can get access anywhere in the program usn is 'university serial number' 
    student()//constructor
    {
        strcpy(name,"\0");
        strcpy(usn,"\0");
        pay=0;
        dept_code=0;
        for(int i=0;i<6;i++)
        {
            marks[i]=0;
            att[i]=0;
        }
    }
    void change_code(int n)//This function helps in changing the department
    {
        dept_code=n;
    }
    void add_stu() //Helps to add new student
    {
        system("cls");
        cout<<"Enter name: ";
        cin.ignore();
        cin.getline(name,25);
        cout<<"Enter Usn: ";
        cin.getline(usn,11);
        cout<<"Enter dept_code\n1.CSE\n2.Civil\n3.ECE\n4.EEE\n5.ISE\n6.Mech\n7.TCE\nEnter choice:";
        cin>>dept_code;
        while (dept_code>7||dept_code<1)
        {
            cout<<"Enter a valid code: ";
            cin>>dept_code;
        }
        cout<<"Student added successfully \n";
        getch();
    }
    void change_pay_marks()//Helps to change the payment to pending when new sem starts 
    {
        pay=0;
        for(int i=0;i<6;i++)
        {
            marks[i]=0;
            att[i]=0;
        }
    }
    int return_pay()//Returns whether fee is paid or not
    {
        return pay;
    }
    void put_name()//Displays the name and usn of students
    {
        cout<<name<<"\t\t"<<usn<<"\n";
    }
    void assign_marks() //helps to assign the marks of student
    {
        system("cls");
        cout<<"Name: "<<name<<"\n";
        cout<<"Usn: "<<usn<<"\n";
        cout<<"Enter marks and attendence\n";
        for(int i=0;i<6;i++)
        {
            cout<<"Subject "<<i+1<<" marks: ";
            cin>>marks[i];
            cout<<"Attendence: ";
            cin>>att[i];
        }
        cout<<"marks and attendence entered successfully\n";
    }
    void put_details() //Displays all the details of the student
    {
        system("cls");
        cout<<"Name: "<<name<<endl;
        cout<<"Usn: "<<usn<<endl;
        cout<<"Marks:";
        for(int i=0;i<6;i++)
        {
            cout<<"\nSubject "<<i+1<<": "<<marks[i];
        }
        cout<<"\nDepartment: ";
        switch (dept_code)
        {
            case 1:cout<<"CSE\n";break;
            case 2:cout<<"Civl\n";break;
            case 3:cout<<"ECE\n";break;
            case 4:cout<<"EEE\n";break;
            case 5:cout<<"ISE\n";break;
            case 6:cout<<"Mech\n";break;
            case 7:cout<<"TCE\n";break;
            default: cout<<"No branch assigned\n";
        }
        cout<<"Fee payemt: ";
        if (pay==1)
        {
            cout<<"Paid\n";
        }
        else
        {
            cout<<"Pending\n";
        }
        getch();
    }
    void pay_fee() //function helps to pay the fee of the student
    {
        system("cls");
        if(pay==1)
        {
            cout<<"Fee already paid\n";
            getch();
            return;
        }
        cout<<"Press 1 to pay fee: ";
        cin>>pay;
        if(pay==1)
        {
            cout<<"Payment successful\n";
        }
        else 
        cout<<"Payment declined\n";
        getch();
    }
    int return_dept_code() //returns the department code
    {
        return dept_code;
    }
};
class faculty
{
    protected://protected members of class faculty
    int dept_code,payment,t_code;//department, wether salary is paid, designation
    double sal;//salary of the faculty
    public:
    char fname[30];//Name is public as it should be accessed from anywhere in program
    faculty()//constructor
    {
        strcpy(fname,"\0");
        dept_code=0;
        payment=0;
        t_code=0;
        sal=0;
    }
    void change_dept(int n)//Helps to change department
    {
        dept_code=n;
    }
    void put_name()//Puts the name of faculty
    {
        cout<<fname<<endl;
    }
    int return_pay()//Returns wether salary is paid
    {
        return payment;
    }
    void change_pay(int n)//changes the payment value when salary paid
    {
        payment=n;
    }
    int return_dept_code()//returns department
    {
        return dept_code;
    }
    void add_fac()//helps adding new faculty
    {
        system("cls");
        cout<<"Enter faculty name: ";
        cin.ignore();
        cin.getline(fname,30);
        cout<<"Enter dept_code\n1.CSE\n2.Civil\n3.ECE\n4.EEE\n5.ISE\n6.Mech\n7.TCE\nEnter choice: ";
        cin>>dept_code;
        while (dept_code>7||dept_code<1)
        {
            cout<<"Enter a valid code: ";
            cin>>dept_code;
        }
        cout<<"Enter designation code\n1.HOD\n2.Professor\n3.Asst. Professor\nEnter choice: ";
        cin>>t_code;
        while(t_code>3||t_code<1)
        {
            cout<<"Enter a valid designation code: ";
            cin>>t_code;
        }
        cout<<"Enter salary: ";
        cin>>sal;
        cout<<"Faculty added successfully";
        getch();
    }
    void put_details()//Prints all the details of faculty
    {
        system("cls");
        cout<<"Name: "<<fname;
        cout<<"\nDesignation: ";
        switch (t_code)
        {
            case 1:cout<<"HOD\n";break;
            case 2:cout<<"Professor\n";break;
            case 3:cout<<"Asst. Professor\n";break;
            default:cout<<"Designation not assigned\n";
        }
        cout<<"\nDepartment: ";
        switch (dept_code)
        {
            case 1:cout<<"CSE\n";break;
            case 2:cout<<"Civl\n";break;
            case 3:cout<<"ECE\n";break;
            case 4:cout<<"EEE\n";break;
            case 5:cout<<"ISE\n";break;
            case 6:cout<<"Mech\n";break;
            case 7:cout<<"TCE\n";break;
            default: cout<<"No branch assigned\n";
        }
        cout<<"Salary: "<<sal<<endl;
        cout<<"Salary status: ";
        if(payment==1)
        cout<<"delivered\n";
        else
        cout<<"Pending\n";
        getch();
    }
    void pay_slip()//Prints their pay slip 
    {
        system("cls");
        cout<<"Salary: "<<sal<<endl;
        cout<<"Employee provident fund (6%): "<<sal*0.06<<endl;
        cout<<"Professional tax (8%): "<<sal*0.08<<endl;
        cout<<"Insurence [sss] (3%): "<<sal*0.03<<endl;
        cout<<"Receving: "<<sal*0.83<<endl;
        getch();
    }
};
class print//class used to print the list of students and faculty [no direct use] It is inherited by all other classes
{
    protected:
    student s;//object of student class
    faculty f;//object of faculty class
    public:
    void print_list_stud()//Prints list of all students
    {
        system("cls");
        ifstream fin;
        fin.open("studentdata.dat",ios::binary|ios::in);//file opend only in 'in' mode as nothing to write in it
        if (!fin)
        {
            cout<<"file could not be opened\n";
            return;
        }
        cout<<"The list of students are:\n";
        while(fin.read((char *) &s, sizeof(student)))
        {
            s.put_name();
        }
        fin.close();
        getch();
    }
    void print_list_fac()//prints list of all faculty
    {
        system("cls");
        ifstream fin;
        fin.open("facultydata.dat",ios::binary|ios::in);//file opend only in 'in' mode as nothing to write in it
        if (!fin)
        {
            cout<<"file could not be opened\n";
            return;
        }
        cout<<"The list of faculty are:\n";
        while(fin.read((char *) &f, sizeof(faculty)))
        {
            f.put_name();
        }
        fin.close();
        getch();
    }
};
class academic:public print//academic class This looks after the marks of the students
{
    public:
    void add_marks()//function helps in adding marks of student
    {
        system("cls");
        char usn[11];
        int flag=0,cmp;
        fstream file;
        cout<<"Enter USN: ";
        cin.ignore();
        cin.getline(usn,11);
        file.open("studentdata.dat",ios::binary|ios::in|ios::out);
        if(!file)
        {
            cout<<"Unable to open file\n";
            return;
        }
        while(file.read((char *) &s, sizeof(student))&&flag==0)
        {
            cmp=strcmp(usn,s.usn);
            if(cmp==0)
            {
                s.assign_marks();
                long long unsigned int pos=(-1)*sizeof(student);
                file.seekp(pos,ios::cur);
                file.write((char *) &s, sizeof(student));
                flag=1;
            }
        }
        file.close();
        if(flag==0)
        {
            cout<<"USN not found\n";
        }
        getch();
    }
};
class department//Department will have the list of students and faculty in each department and helps in changing department
{
    int dept,dept_chek;
    int f_s;
    student s;
    faculty f;
    public:
    void print_list()//prints the required list
    {
        system("cls");
        ifstream fin;
        cout<<"Enter dept_code\n1.CSE\n2.Civil\n3.ECE\n4.EEE\n5.ISE\n6.Mech\n7.TCE\nEnter choice:";
        cin>>dept;
        while (dept>7||dept<1)
        {
            cout<<"Enter a valid code: ";
            cin>>dept;
        }
        cout<<"1.Student or 2.faculty : ";
        cin>>f_s;
        while(f_s!=1&&f_s!=2)
        {
            cout<<"Enter valid choice: ";
            cin>>f_s;
        }
        if(f_s==1)
        {
            system("cls");
            fin.open("studentdata.dat",ios::in);
            if(!fin)
            {
                cout<<"Error in opening file\n";
                return;
            }
            cout<<"The list\n";
            while(fin.read((char *) &s, sizeof(student)))
            {
                dept_chek=s.return_dept_code();
                if(dept==dept_chek)
                {
                    s.put_name();
                }
            }
            fin.close();
            getch();
        }
        else if(f_s==2)
        {
            system("cls");
            fin.open("facultydata.dat",ios::binary|ios::in);
            if(!fin)
            {
                cout<<"Error in opening file\n";
                return;
            }
            cout<<"The list\n";
            while(fin.read((char *) &f, sizeof(faculty)))
            {
                dept_chek=f.return_dept_code();
                if(dept_chek==dept)
                {
                    f.put_name();
                }
            }
            fin.close();
            getch();
        }
    }
    void stud_change()//Helps in changing the department of student
    {
        system("cls");
        char usn[11];
        int flag=0,dept_code;
        fstream file;
        file.open("studentdata.dat",ios::in|ios::out);
        if(!file)
        {
            cout<<"Unable to open file\n";
            return;
        }
        cout<<"Enter USN: ";
        cin.ignore();
        cin.getline(usn,11);
        while(file.read((char *) &s, sizeof(student))&&flag==0)
        {
            if(strcmp(usn,s.usn)==0)
            {
                cout<<"1.CSE\n2.Civil\n3.ECE\n4.EEE\n5.ISE\n6.Mech\n7.TCE\nEnter new branch: ";
                cin>>dept_code;
                while(dept_code>7||dept_code<1)
                {
                    cout<<"Enter valid choice: ";
                    cin>>dept_code;
                }
                dept_chek=s.return_dept_code();
                if(dept_code==dept_chek)
                {
                    cout<<"You entered same choice\n Enter new: ";
                    cin>>dept_code;
                }
                s.change_code(dept_code);
                long long signed int pos=(-1)*sizeof(student);
                file.seekp(pos,ios::cur);
                file.write((char *) &s, sizeof(student));
                flag=1;
                cout<<"Change department Successful\n";
            }
        }
        file.close();
        if(flag==0)
        {
            cout<<"Student with that usn not found\n";
        }  
        getch();
    }
    void fac_change()//helps in changing the department of faculty
    {
        system("cls");
        char name[30];
        int flag=0,dept_code;
        fstream file;
        file.open("facultydata.dat",ios::in|ios::out);
        if(!file)
        {
            cout<<"Unable to open file\n";
            return;
        }
        cout<<"Enter Name: ";
        cin.ignore();
        cin.getline(name,30);
        while(file.read((char *) &f, sizeof(faculty))&&flag==0)
        {
            if(strcmp(name,f.fname)==0)
            {
                cout<<"1.CSE\n2.Civil\n3.ECE\n4.EEE\n5.ISE\n6.Mech\n7.TCE\nEnter new branch: ";
                cin>>dept_code;
                while(dept_code>7||dept_code<1)
                {
                    cout<<"Enter valid choice: ";
                    cin>>dept_code;
                }
                dept_chek=f.return_dept_code();
                if(dept_code==dept_chek)
                {
                    cout<<"You entered same choice\n Enter new: ";
                    cin>>dept_code;
                }
                f.change_dept(dept_code);
                long long signed int pos=(-1)*sizeof(faculty);
                file.seekp(pos,ios::cur);
                file.write((char *) &f, sizeof(faculty));
                flag=1;
                cout<<"Change department Successful\n";
            }
        }
        file.close();
        if(flag==0)
        {
            cout<<"Faculty with that name not found\n";
        }  
        getch();
    }
};
class hr:public print//Hr adds delets the student and faculty
{
    public:
    void new_stud()//adding new student
    {
        ofstream fout;
        fout.open("studentdata.dat",ios::binary|ios::app);
        s.add_stu();
        fout.write((char *) &s, sizeof(student));
        fout.close();
    }
    void new_fac()//adding new faculty
    {
        ofstream fout;
        fout.open("facultydata.dat",ios::binary|ios::app);
        f.add_fac();
        fout.write((char *) &f, sizeof(faculty));
        fout.close();
    }
    void delete_stud()//deleting a student
    {
        system("cls");
        ifstream fin;
        ofstream fout;
        char usn[11];
        int flag=0,cmp;
        fin.open("studentdata.dat",ios::binary|ios::in);
        if(!fin)
        {
            cout<<"Cannot open file\n";
            return;
        }
        cout<<"Enter usn to delete: ";
        cin.ignore();
        cin.getline(usn,11);
        fout.open("temp.dat",ios::binary);
        fin.seekg(0,ios::beg);
        while(fin.read((char *) &s, sizeof(student)))
        {
            cmp=strcmp(usn,s.usn);
            if(cmp==0)
            {
                flag=1;
            }
            else
                fout.write((char *) &s, sizeof(student));
        }
        if(flag==0)
        {
            cout<<"Record not found\n";
        }
        else
        {
            cout<<"Student deleted successfully\n";
        }
        fin.close();
        fout.close();
        remove("studentdata.dat");
        rename("temp.dat","studentdata.dat");
        getch();
    }
    void delete_fac()//deleting a faculty
    {
        system("cls");
        ifstream fin;
        ofstream fout;
        char name[30];
        int flag=0,cmp;
        fin.open("facultydata.dat",ios::binary|ios::in);
        if(!fin)
        {
            cout<<"Cannot open file\n";
            return;
        }
        cout<<"Enter name to delete: ";
        cin.ignore();
        cin.getline(name,30);
        fout.open("temp.dat",ios::binary);
        fin.seekg(0,ios::beg);
        while(fin.read((char *) &f, sizeof(faculty)))
        {
            cmp=strcmp(name,f.fname);
            if(cmp==0)
            {
                flag=1;
            }
            else
                fout.write((char *) &f, sizeof(faculty));
        }
        if(flag==0)
        {
            cout<<"Record not found\n";
        }
        else
        {
            cout<<"faculty deleted successfully\n";
        }
        fin.close();
        fout.close();
        remove("facultydata.dat");
        rename("temp.dat","facultydata.dat");
        getch();
    }
};
class finance:public print//It looks after the fee of the student and salary of faculty
{
    int chek,reset,f_s;
    public:
    void print_list()//Prints the required record
    {
        ifstream fin;
        cout<<"1.fee paid students list\n2.Salary pending faculty list\nEnter choice: ";
        cin>>f_s;
        while(f_s!=1&&f_s!=2)
        {
            cout<<"Enter valid choice: ";
            cin>>f_s;
        }
        if(f_s==1)
        {
            system("cls");
            fin.open("studentdata.dat",ios::binary|ios::in);
            if(!fin)
            {
                cout<<"Error in opening file\n";
                return;
            }
            cout<<"The list\n";
            while(fin.read((char *) &s, sizeof(student)))
            {
                chek=s.return_pay();
                if(chek==1)
                {
                    s.put_name();
                }
            }
            fin.close();
        }
        else if(f_s==2)
        {
            system("cls");
            fin.open("facultydata.dat",ios::binary|ios::in);
            if(!fin)
            {
                cout<<"Error in opening file\n";
                return;
            }
            cout<<"The list\n";
            while(fin.read((char *) &f, sizeof(faculty)))
            {
                chek=f.return_pay();
                if(chek!=1)
                {
                    f.put_name();
                }
            }
            fin.close();
        }
        getch();
    }
    void pay_sal()//Pays the salary to faculty
    {
        system("cls");
        char name[30];
        int flag=0;
        fstream file;
        file.open("facultydata.dat",ios::binary|ios::in|ios::out);
        if(!file)
        {
            cout<<"Unable to open file\n";
            return;
        }
        cout<<"Enter faculty name: ";
        cin.ignore();
        cin.getline(name,30);
        while(file.read((char *) &f, sizeof(faculty))&&flag==0)
        {
            if(strcmp(name,f.fname)==0)
            {
                f.change_pay(1);
                long long signed int pos=(-1)*sizeof(faculty);
                file.seekp(pos,ios::cur);
                file.write((char *) &f, sizeof(faculty));
                flag=1;
                cout<<"Payment Successful";
            }
        }
        file.close();
        if(flag==0)
        {
            cout<<"Faculty with that name not found\n";
        }  
        getch();
    }
    void reset_sem()//Reset to a new sem [fee and salary will be unpaid]
    {
        ifstream fin;
        ofstream fout;
        cout<<"Are you sure to reset(1/2): ";
        cin>>reset;
        while(reset!=1&&reset!=2)
        {
            cout<<"Enter valid choice: ";
            cin>>reset;
        }
        fin.open("studentdata.dat",ios::binary);
        if(!fin)
        {
            cout<<"Error in opening file\n";
            return;
        }
        fout.open("temp.dat",ios::binary);
        while(fin.read((char *) &s,sizeof(student)))
        {
            s.change_pay_marks();
            fout.write((char *) &s,sizeof(student));
        }
        fin.close();
        fout.close();
        remove("studentdata.dat");
        rename("temp.dat","studentdata.dat");
        fin.open("facultydata.dat",ios::binary);
        if(!fin)
        {
            cout<<"Error in opening file\n";
            return;
        }
        fout.open("temp.dat",ios::binary);
        while(fin.read((char *) &f,sizeof(faculty)))
        {
            f.change_pay(0);
            fout.write((char *) &f,sizeof(faculty));
        }
        fin.close();
        fout.close();
        remove("facultydata.dat");
        rename("temp.dat","facultydata.dat");
        cout<<"Reset successful";
        getch();
    }
};
struct book//A structure of book
{
    char bookname[100];
    int taken;
};
class inv_lib//library management
{
    book b;
    public:
    void print_books()//Prints the list of books in library 
    {
        system("cls");
        ifstream fin;
        fin.open("books.dat",ios::binary);
        if(!fin)
        {
            cout<<"Error in opening file";
            return;
        }
        while(fin.read((char *) &b, sizeof(book)))
        {
            cout<<b.bookname<<endl;
        } 
        getch();
    }
    void add_book()//Adds new books
    {
        int check;
        check= pass(7);//It is password protected as only librarian only can add books
        if(check==0)
        {
            cout<<"\nWrong password";
            getch();
            return;
        }
        system("cls");
        ofstream fout;
        fout.open("books.dat",ios::binary|ios::app);
        cout<<"Enter book name: ";
        cin.ignore();
        cin.getline(b.bookname,100);
        b.taken=0;
        fout.write((char *) &b, sizeof(book));
        fout.close();
        cout<<"Book added successfully\n";
        getch();
    }
    void borrow()//Helps to borrow books
    {
        system("cls");
        fstream file;
        int found=0,chek;
        char name[100];
        file.open("books.dat",ios::binary|ios::in|ios::out);
        cout<<"Enter book name: ";
        cin.ignore();
        cin.getline(name,100);
        while(file.read((char *) &b, sizeof(book))&&found==0)
        {
            chek=strcmp(name,b.bookname);
            if(chek==0)
            {
                found=1;
                if(b.taken==1)//If book already borrowed says so
                {
                    cout<<"The book has been borrowed\n";
                    break;
                }
                long long signed int pos=(-1)*sizeof(book);
                b.taken=1;
                file.seekp(pos,ios::cur);
                file.write((char *) &b,sizeof(book));
                cout<<"Book borrowed successfully";
            }
        }
        file.close();
        if(found==0)
        {
            cout<<"Book not found\n";
        }
        getch();
    }
    void return_book()//Helps to return the book
    {
        system("cls");
        fstream file;
        int found=0,chek;
        char name[100];
        file.open("books.dat",ios::binary|ios::in|ios::out);
        cout<<"Enter book name: ";
        cin.ignore();
        cin.getline(name,100);
        while(file.read((char *) &b, sizeof(book))&&found==0)
        {
            chek=strcmp(name,b.bookname);
            if(chek==0)
            {
                found=1;
                if(b.taken==0)//If the book not at all borrowed then says so
                {
                    cout<<"The book is in the library\n";
                    break;
                }
                long long signed int pos=(-1)*sizeof(book);
                b.taken=0;
                file.seekp(pos,ios::cur);
                file.write((char *) &b,sizeof(book));
                cout<<"Book returned successfully";
            }
        }
        file.close();
        if(found==0)
        {
            cout<<"Book not found\n";
        }
        getch();
    }
};
void student_works()//Has the student menu
{
    system("cls");
    char usn[11]; 
    fstream file;
    int found=0,choice=0,cmp;
    student s;
    file.open("studentdata.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout<<"Error in opening student data\n";
        return;
    }
    cout<<"Enter USN: ";
    cin.ignore();
    cin.getline(usn,11);
    while(file.read((char *) &s, sizeof(student))&&found==0)
    {
        cout<<s.usn;
        cmp=strcmp(usn,s.usn);
        if(cmp==0)
        {
            found=1;
            while(choice!=3)
            {
                system("cls");
                cout<<"\n\n\n\t\t\t\tSTUDENT MENU\n\n\t\t1.See details\n\t\t2.Pay fee\n\t\t3.Return back\n\t\tEnter choice: ";
                cin>>choice;
                while(choice>3||choice<1)
                {
                    cout<<"Enter valid choice: ";
                    cin>>choice;
                }
                switch(choice)
                {
                    case 1:s.put_details();
                    break;
                    case 2:{s.pay_fee();
                    long long signed int pos=(-1)*sizeof(student);
                    file.seekp(pos,ios::cur);
                    file.write((char *) &s, sizeof(student));}
                    break;
                    case 3:
                    file.close();
                    return;
                }
            }
        }
    }
    file.close();
    if(found==0)
    {
        cout<<"record not found\n";
        getch();
    }
}
void faculty_works()//The faculty menu
{
    system("cls");
    char name[30];
    ifstream fin;
    int found=0,choice=0;
    faculty f;
    fin.open("facultydata.dat",ios::binary);
    if(!fin)
    {
        cout<<"Error in opening student data\n";
        return;
    }
    cout<<"Enter name: ";
    cin.ignore();
    cin.getline(name,30);
    while(fin.read((char *) &f, sizeof(faculty))&&found==0)
    {
        if(strcmp(name,f.fname)==0)
        {
            found=1;
            while(choice!=3)
            {
                system("cls");
                cout<<"\n\n\n\t\t\t\tFACULTY MENU\n\n\t\t1.See details\n\t\t2.Pay slip\n\t\t3.Return back\n\t\tEnter choice: ";
                cin>>choice;
                while(choice>3||choice<1)
                {
                    cout<<"Enter valid choice: ";
                    cin>>choice;
                }
                switch(choice)
                {
                    case 1:f.put_details();
                    break;
                    case 2:f.pay_slip();
                    break;
                    case 3:fin.close();
                    return;
                }
            }
        }
    }
    fin.close();
    if(found==0)
    {
        cout<<"faculty not found\n";
        getch();
    }
}
void acadamic_works()//Acadamic department menu
{
    academic a;
    int choice;
    while(1)
    {
        system("cls");
        cout<<"\n\n\n\t\t\t\tACADAMIC MENU\n\n\t\t1.Print list of students\n\t\t2.Print list of Faculty\n\t\t3.Add marks of student\n\t\t4.Return to menu\n\t\tEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:a.print_list_stud();
            break;
            case 2:a.print_list_fac();
            break;
            case 3:a.add_marks();
            break;
            case 4:return;
            default:cout<<"Wrong choice\n";
        }
    }
}
void dept_works()//Department management menu
{
    department d;
    int choice;
    while(1)
    {
        system("cls");
        cout<<"\n\n\n\t\t\t\tDEPARTMENT MENU\n\n\t\t1.Print record\n\t\t2.Change student department\n\t\t3.Change faculty department\n\t\t4.Return\n\t\tEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:d.print_list();
            break;
            case 2:d.stud_change();
            break;
            case 3:d.fac_change();
            break;
            case 4: return;
            default:cout<<"Wrong choice\n";
            getch();
        }
    }
}
void hr_works()//Hr menu
{
    hr h;
    int choice;
    while(1)
    {
        system("cls");
        cout<<"\n\n\n\t\t\t\tHR MENU\n\n\t\t1.Print list of students\n\t\t2.Print list of Faculty\n\t\t3.New student\n\t\t4.new faculty\n\t\t5.Delete student\n\t\t6.delete faculty\n\t\t7.Return\n\t\tEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:h.print_list_stud();
            break;
            case 2:h.print_list_fac();
            break;
            case 3:h.new_stud();
            break;
            case 4:h.new_fac();
            break;
            case 5:h.delete_stud();
            break;
            case 6:h.delete_fac();
            break;
            case 7:return;
            default:cout<<"Wrong choice\n";
        }
    }
}
//finance functions menu
void finance_works()
{
    finance F;
    int choice;
    while(1)
    {
        system("cls");
        //Printing menu
        cout<<"\n\n\n\t\t\t\tFINANCE MENU\n\n\t\t1.Print list of students\n\t\t2.Print list of Faculty\n\t\t3.pay salary to faculty\n\t\t4.Print record\n\t\t5.Reset sem\n\t\t6.Return\n\t\tEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:F.print_list_stud();
            break;
            case 2:F.print_list_fac();
            break;
            case 3:F.pay_sal();
            break;
            case 4:F.print_list();
            break;
            case 5:F.reset_sem();
            break;
            //Going to privious menu
            case 6:return;
            default:cout<<"Wrong choice\n";
        }
    }
}
//Visiting library function
//Helps choose choises from its own menu
void vist_lib()
{
    inv_lib l;
    int choice;
    while(1)
    {
        system("cls");
        //Printing library menu
        cout<<"\n\n\n\t\t\t\tLIBRARY\n\n\t\t1.Add book\n\t\t2.Borrow book\n\t\t3.Return book\n\t\t4.Print books\n\t\t5.Return\n\t\tEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            //Takes us to add books to the file
            case 1:l.add_book();
            break;
            //Helps us to borrow the book
            case 2:l.borrow();
            break;
            //Helps us to return the book
            case 3:l.return_book();
            break;
            //Prints all the list of the books
            case 4:l.print_books();
            break;
            //Exit to previous menu
            case 5:return;
            default:cout<<"Wrong choice\n";
        }
    }
}
//Menu function
void menu()
{
    int choice,sub_choice,i=1,check;
    while(i=1)
    {
        system("cls");
        //Printing Menu
        cout<<"\n\n\n\t\t\tMENU\n\n\t\t1.Student\n\t\t2.Faculty\n\t\t3.Acadamic Department\n\t\t4.Department Management\n\t\t5.HR\n";
        cout<<"\t\t6.Finance Department\n\t\t7.Visit library\n\t\t8.Exit\n\t\tEnter your choice: ";
        //Taking choice
        cin>>choice;
        while(choice>8||choice<1)
        {
            cout<<"Enter valid choice: ";
            cin>>choice;
        }
        switch(choice)
        {
            //When student option is selected
            case 1: student_works();
                break;
            //When faculty option is selected
            case 2: faculty_works();
                break;
            //When Acadamic option is selected
            case 3: 
                //Password function is called
                check=pass(choice);
                //Can go to the function only when password is correct
                if(check==1)
                    acadamic_works();
                else
                    cout<<"\nWrong password";
                break;
            //When Department option is choosen
            case 4: 
                check=pass(choice);
                if(check==1)
                    dept_works();
                else
                    cout<<"\nWrong password";
                break;
            //When HR option is called
            case 5: 
                check=pass(choice);
                if(check==1)
                    hr_works();
                else
                    cout<<"\nWrong password";
                break;
            //When finance option is chosen
            case 6: 
            check=pass(choice);
                if(check==1)
                    finance_works();
                else
                    cout<<"\nWrong password";
                break;
            //When visit library is choosen
            case 7: vist_lib();
                break;
            //Exit
            case 8: return;
            default: cout<<"\nWrong choice\n";
        }
        getch();
    }
}
//Main function
int main ()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tDr. Ambedkar Institute of technology\n";
    cout<<"\n\t\tSubject: Object Oriented Programming\n";
    cout<<"\n\t\tSubject code: 18CS42\n";
    cout<<"\n\t\tSection:A \t\t Batch:A1";
    cout<<"\n\n\t\tUNIVERSITY MANAGEMENT SYSTEM\n";
    cout<<"\nDONE BY:\n";
    for(int i=1;i<10;i++)
    {
        cout<<"\n\t1DA19CS00"<<i;
    }
    for(int i=10;i<=20;i++)
    {
        cout<<"\n\t1DA19CS0"<<i;
    }
    getch();
    menu();
    system("cls");
    cout<<"\nProgram completed";
    cout<<"\nRedirecting to terminal...";
    getch();
    system("cls");
    return 0;
}
//Program without comments: 1186 lines
