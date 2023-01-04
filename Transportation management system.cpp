#include <fstream>   //header file for file handling
#include <iomanip>   //manipulating the output
#include <windows.h> // to access Win32API
#include <conio.h>   // to provide console input/output
#include <ctype.h>   //to handle characters
#include <stdlib.h>  // standard library
#include <iostream>  // standard input/output stream
#include <string>    // to use string functions
using namespace std;
void gotoXY(int x, int y);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
static int a; // class specifications

class staff_login;
class student_login;
//base class
class register_now
{
    string name[10];
public:
    int notice();
    int instructionsform();
    int registration_form();
    int confirmform();
    int routes();
    friend student_login;
    friend staff_login;

    //default coonstructor
    register_now(){};
};
// class for student login
// it includes various functions available for student

//INHERITENCE:
//student_login is inheriting from register_now class
//derived class 1
class student_login: public register_now
{
public:
    int login();
    int allotmentform();
    int contactdetails();
    int complaints();
    friend register_now;

    //default coonstructor
    student_login(){};
};
// class for staff login
// it includes various functions available for staff
//INHERITENCE:
//staff_login is inheriting from register_now class
//derived class 2
class staff_login: public register_now
{
public:
    int login();
    int complaintbox();
    int notice();
    int allot_staffr();

    //default coonstructor
    staff_login(){};
};
// function to login for staff
// takes username and password for login
// displays various options available

int staff_login::login()
{
    register_now r1;
    staff_login s1;
    student_login s2;

    int u;
    string a[100], user1, user2, user3;
    char line[80];
    system("cls");

    cout << "\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
    cin >> user1;
     int i = 0;
    char pwd[5];

    cout << "                    PASSWORD:";

    while (i < 4)
    {
        pwd[i] = getch();
        putchar('*');
        ++i;
    }

    int j = 0;

    user2 = pwd;
    user3 = user1 + user2;
    ifstream fil5;
    fil5.open("login.txt", ios::out);
    while (fil5)
    {
        // to read the text line by line
        fil5.getline(line, 80);
        a[j] = line;
        j++;
    }

    for (int k = 0; k < 50; k++)
    {
        if (a[k] == user3)
        {
            while (1)
            {
                system("cls");
                cout << "\n\n WELCOME TO " << user1;
                cout << "\n\n\n\n\n\n                     1.Complaint Box"
                     << "\n                     2.Edit notice";
                cout << "\n                     3.Alloted staff";
                cout << "\n                     4.To LOGOUT";
                cout << "\n\n\n Select Your Option: ";
                cin >> u;
// using switch case to iterate through various options
                switch (u)
                {
                case 1:
                    system("COLOR 0F");
                    s1.complaintbox();
                    break;
                case 2:
                    system("COLOR 0F");
                    s1.notice();
                    break;
                case 3:
                    system("COLOR 0F");
                    s1.allot_staffr();
                    break;
                case 4:
                    system("COLOR 0F");
                    system("cls");
                    cout << "\n\n\n\n\n\n\n           LOADING PLEASE WAIT ... ";
                    Sleep(5);
                    return 0;
                default:
                    return 0;
                }
            }
        }
    }

    system("cls");
    cout << "\n\n\n      SORRY,"
         << "\n      invalid username or password";

    Sleep(3);
    return 1;
}

// to enter notice

int staff_login::notice()
{
    system("cls");

    fstream fin;
    fin.open("notice.txt", ios::out | ios::app);
    fin << endl;

    string mystr;

    // to read the text line by line
    getline(cin, mystr);
    cout << "Enter the Notice :";

    // to read the text line by line
    getline(cin, mystr);
    fin << mystr;
    cout << "\n\n\n\nEnter any key to return main menu :";
    getch();
    return 1;
}

// displays complaints entered by student if any

int staff_login::complaintbox()
{
    char ch[80];
    system("cls");

    ifstream fin6;
    fin6.open("complaintbox.txt", ios::in);
    while (fin6)
    {
        // to read the text line by line
        fin6.getline(ch, 80);
        cout << ch;
    }
    cout << "\n\n\n\n\n\n   Enter the any key to return to main menu";

    getch();
    return 1;
}

// displays info of alloted staff
//  from text file "allotedstaff.txt"

int staff_login::allot_staffr()
{
    system("cls");
    char ch[100];

    ifstream fin6;
    fin6.open("allotedstaff.txt", ios::in);

    while (fin6)
    {
        // to read the text line by line
        fin6.getline(ch, 100);

        cout << ch;
        cout << endl;
    }

    cout << "\n\n\n\n\n\n   Enter the any key to return to main menu";

    getch();
    return 1;
}

// login function for students
//  displays various options
// and enter choice

int student_login::login()
{
    register_now r1;
    staff_login s1;
    student_login s2;

    int u;
    string a[100], user1, user2, user3;

    char line[80];

    system("cls");

    cout << "\n\n\n\n\n\n\n\n\n\n                    USERNAME:";
    cin >> user1;
    int i = 0;
    char ch;
    char pwd[5];
    cout << "                    PASSWORD:";

    while (i < 4)
    {
        pwd[i] = getch();
        putchar('*');
        ++i;
    }

    int j = 0;
    user2 = pwd;
    user3 = user1 + user2;

    ifstream fil5;
    fil5.open("login.txt", ios::out);

    while (fil5)
    {
        // to read the text line by line
        fil5.getline(line, 80);
        a[j] = line;
        j++;
    }

    for (int k = 0; k < 50; k++)
    {
        if (a[k] == user3)
        {
            while (1)
            {
                system("cls");
                cout << "\n\n WELCOME TO " << user1;
                cout << "\n\n\n\n\n                  1.Allotment form";
                cout << "\n                  2.Complaint"
                     << "\n                  3.Staff contact details";
                cout << "\n                  4.To LOGOUT";
                cout << "\n\n\n\n\n\n Select Your Option: ";
                cin >> u;

                // using switch case to iterate through various options
                switch (u)
                {
                case 1:
                    s2.allotmentform();
                    break;
                case 2:
                    s2.complaints();
                    break;
                case 3:
                    s2.contactdetails();
                    break;
                case 4:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n            PLEASE WAIT ... LOADING";
                    Sleep(5);
                    return 0;
                default:
                    exit;
                }
            }
        }
    }
    system("cls");
    cout << "\n\n\n      SORRY,"
         << "\n      invalid username and password";

    Sleep(3);
    return 1;
}

// prints allotment status

int student_login::allotmentform()
{
    system("cls");
    string j, tem[10];

    int i, d;
    cout << "Enter your Username :";

    cin >> j;
    ifstream f8;

    f8.open("list_of_students", ios::in);
    f8.seekg(0, ios::beg);

    while (!f8.eof())
    {
        i++;
        string temp;
        f8 >> temp;
        if (temp == j)
        {
            d = f8.tellg();
            break;
        }
    }
    int y = d + 6;
    int l = 0;
    while (d != y)
    {
        d++;
        string temp;
        f8 >> temp;
        tem[l] = temp;
        l++;
    }
    system("cls");
     cout.setf(ios::left, ios::adjustfield);
    cout << endl
         << endl
         << "     NAME :" << tem[0];
    cout << "                  FATHER NAME :" << tem[1];
    cout << endl
         << endl
         << "     Ph_no:" << tem[2];
    cout << "                   ADDRESS:" << tem[3];
    cout << endl
         << endl
         << "     Alloted seat Number:" << tem[4];
    cout << endl
         << endl
         << endl
         << "\n            Total amount DUE : Rs " << tem[5] << "|-" << endl
         << endl;

    cout << "Enter any key to return back to menu :";
    getch();
    return 1;
}

// helps students to file complaints
//  in case any issue arises

int student_login::complaints()
{
    char ch;
    system("cls");

    ofstream fin9;
    fin9.open("complaintbox.txt", ios::app);
    fin9 << endl;

    string mystr;

    // to read the text line by line
    getline(cin, mystr);
    cout << "Enter the Complaint :";
    getline(cin, mystr);

    fin9 << mystr;
    cout << "\n\n\nEnter any key to return back to menu :";
    getch();
    return 1;
}

// function to display contact details to contact in case of any emergency

int student_login::contactdetails()
{
    system("cls");
    cout << "\n\n\n   Miss Shanaya Raichand "
         << "\n   Room no:K-201,"
         << "\n  KYP,BPL,MP";
    cout << "\n   Phone no: 987XXXXXX";

    cout << "\n\n\n   Mr Rishabh Bajaj "
         << "\n   Room no:D-321,"
         << "\n  KYP,BDL,MP";
    cout << "\n   Phone no: 693XXXXXX";

    cout << "\n\n\n\nEnter any key to return back to menu :";
    getch();
    return 1;
}

// member functions definitions of register_now class
// prints the general instructions
// user can move to registration process only after accepting these instructions

int register_now::instructionsform()
{
    system("cls");
    cout << "\n          ";
    char b[] = "Read the following Instructions\n";
    int x = strlen(b);

    for (int i = 0; i < x; i++)
    {
        Sleep(5);
        cout << b[i];
    }

    char ch[100];
    char a;

    ifstream ins1;
    ins1.open("instructions.txt", ios::in);

    while (ins1)
    {
        // to read the text line by line
        ins1.getline(ch, 100);
        cout << ch;
        cout << endl;
    }

    cout << "To accept the above instructions press Y : ";
    cin >> a;

    if (a == 'y' || a == 'Y')
    {
        registration_form();
    }

    else
    {
        system("cls");
        cout << "\n\n\n\n\n               sorry,YOU ENTERED A WRONG CHOICE.....";

        Sleep(1);
        system("cls");
    }
}

// to register for new student or staff
//  takes input of details from user
//  and stores in respective text files

int register_now::registration_form()
{
    string password;
    char pwd[5];
    int i = 0;
    system("cls");
    a++;

    fstream fil5;
    fil5.open("login.txt", ios::out | ios::app);
    cout << "              \n";
    char b[] = "REGISTRATION FORM\n";

    int x = strlen(b);
    for (int i = 0; i < x; i++)
    {
        Sleep(5);
        cout << b[i];
    }
    cout << endl
         << endl
         << setw(5) << "NAME :";
    cin >> name[0];

    cout << setw(40) << "FATHER NAME :";
    cin >> name[1];

    cout << endl
         << setw(10) << "Ph_no:";
    cin >> name[2];

    cout << setw(35) << "ADDRESS:";
    cin >> name[3];
    cout << endl
         << setw(5) << "Select seat Number:" << endl;
    int count = 1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 3)
            {
                cout << "   ";
            }
            cout << setw(4) << count << "  ";
            count++;
        }
        cout << endl;
    }
    cout << " ";

    for (int i = 51; i <= 60; i++)
    {
        cout << setw(3) << i;
    }

    string user4;
    cin >> name[4];

    cout << "\n staff or student: ";
    cin >> user4;

    // if user is student
    // then this set of codes will execute

    if (user4 == "student" || "STUDENT")
    {
        cout << endl
             << endl
             << "Your username :";
        cout << name[0];
        cout << endl
             << "PASSWORD :";

        while (i < 4)
        {
            pwd[i] = getch();
            putchar('*');
            ++i;
        }
        password = pwd;
        fil5 << name[0];
        fil5 << password << "\n";
        cout << endl;

        name[5] = "11000";
        cout << name[5];
        fil5.close();

        fstream fil2;
        fil2.open("list_of_students", ios::in | ios::out | ios::app);
        fil2.seekg(74);
        fil2 << name[0] << "          ";
        fil2.setf(ios::left,ios::adjustfield);

        for (int i = 0; i < 6; i++)
        {
            fil2.setf(ios::left, ios::adjustfield);
            fil2 << setw(20) << name[i];
            count++;
        }
        fil2 << endl;
        Sleep(5);
    }

    else
    {
        // if user is staff
        // then this set of code will run

        if (user4 == "staff" || "STAFF")
        {
            cout << endl
                 << endl
                 << "Your username :";
            cout << name[0];
            cout << endl
                 << "PASSWORD :";


            while (i < 4)
            {
                pwd[i] = getch();
                putchar('*');
                ++i;
            }

            password = pwd;
            fil5 << name[0];
            fil5 << password << "\n";
            cout << endl;

            name[5] = "11000";
            cout << name[5];
            fil5.close();

            fstream fil2;

            // opening the file in append mode
            fil2.open("list_of_students", ios::in | ios::out | ios::app);

            // using seekg() funtion
            // to place the pointer at desired location
            fil2.seekg(74);

            fil2 << name[0] << "          ";
            fil2.setf(ios::left,ios::adjustfield);

            for (int i = 0; i < 6; i++)
            {
                fil2.setf(ios::left, ios::adjustfield);
                fil2 << setw(20) << name[i];
                count++;
            }

            fil2 << endl;
            Sleep(500);
        }
    }

    confirmform();
}

// to print the confirmed details of form

int register_now::confirmform()
{
    char ch;
    system("cls");

    char sentzz[] = "          ******CONFIRM FORM******";
    int x;

    int size;
    size = strlen(sentzz);

    for (x = 0; x < size; x++)
    {
        Sleep(5);
        cout << sentzz[x];
    }
    cout.setf(ios::left, ios::adjustfield);
    cout << endl
         << endl
         << "     NAME :" << name[0];
    cout << "                  FATHER NAME :" << name[1];
    cout << endl
         << endl
         << "     Ph_no:" << name[2];
    cout << "                   ADDRESS:" << name[3];
    cout << endl
         << endl
         << "     Alloted seat Number:" << name[4];
    // cout<<endl<<endl<<"     Your username :"<<"CBIT"<<a;
    cout << endl
         << endl
         << endl
         << "            Total amount to be paid : Rs 11,000|- on or before 25th july" << endl
         << endl
         << endl;

    /*fil2.seekg(0,ios::end);
     int b=fil2.tellg();
     fil2.seekg(-100,ios::end);
     while(fil2)
     {
         int a=fil2.tellg();
         cout<<"NAME:";
         if(a!=b)
         {
             fil2.get(ch);
             cout<<ch;
         }*/
    int a;
    Sleep(4);

    cout << endl
         << endl
         << "    THANK YOU!    ";

    return 0;
}

// to display various routes

int register_now::routes()
{
    char ch[100];
    system("cls");

    fstream fil4;
    fil4.open("ROUTES.txt", ios::in);

    while (fil4)
    {
        // to read the text line by line
        fil4.getline(ch, 100);
        cout << ch;
        cout << endl;
    }
}

// to display notice on console

int register_now::notice()
{
    system("cls");
    char ch[100];

    ifstream f2;
    f2.open("notice.txt", ios::in);

    while (f2)
    {
        // to read the text line by line
        f2.getline(ch, 100);
        cout << ch;
        cout << endl;
    }

    //cout << "\n\n\n Enter any to return back to menu :";
    //getch();
    return 1;
}

int main()
{
    int q;
    do {


    char clg[500];
    system("COLOR 0F");

    while (1)
    {
        system("cls");
        cout << endl
             << endl;

        fstream f2;
        f2.open("institute.txt", ios::in);

        while (f2)
        {
            f2.getline(clg,500);
            cout << clg;
            cout<<endl;
        }

        Sleep(1);
        system("COLOR 0");
        char a[] = "           *****STUDENT TRANSPORT MANAGEMENT****          ";

        int size;
        size = strlen(a);

        for (int i = 0; i < size; i++)
        {
            Sleep(2);
            cout << a[i];
        }
        int c = 1;

        cout << endl
             << endl;
        Sleep(0);

        cout << "\n                    \t\t1.REGISTER NOW \n                    \t\t2.STAFF LOGIN \n                    \t\t3.STUDENT LOGIN \n"
             << "                    \t\t4.NOTICES\n"
             << "                    \t\t5. ROUTES";


        for (int i = 0; i < 1; i++)
        {
            int x = 16;
            int y = 10;

            for (y = 12; y < 21; y++)
            {
                gotoXY(x, y);
                 cout <<"*";

                Sleep(1);
                // gotoXY(x,y);
                // cout << "*";
            }

            y = 21;
            for (x = 16; x < 63; x++)
            {
                gotoXY(x, y);
                cout << "*";

                Sleep(2);
                // gotoXY(x,y);
                // cout << " ";
            }
            for (y = 12; y < 22; y++)
            {
                gotoXY(x, y);
                cout << "*";

                Sleep(1);
                // gotoXY(x,y);
                // cout << " ";
            }
        }
        for (int i = 0; i < 1; i++)
        {
            //creating objects of classes
            //register_now r1;
            staff_login s1;
            student_login s2;

            int ch;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "\nSelect Your Option :";
            cin >> ch;
            fstream f1;

            // COLOR is for setting background and text colour
            // 0 is for black background
            // F is for white text

            // using switch case to iterate through various options
            switch (ch)
            {
            case 1:
                system("COLOR 0F");
                s1.instructionsform();
                break;

            case 2:
                system("COLOR 0F");
                s1.login();
                break;

            case 3:
                system("COLOR 0F");
                s2.login();
                break;

            case 4:
                system("COLOR 0F");
                s1.notice();
                break;

            case 5:
                system("COLOR 0F");
                s1.routes();
                break;

            default:
                cout << "Enter valid choice!!";
                break;
            }
        }
        cout<<endl<<"Enter 1 to go back to main menu, else press 0  ";
        cin>>q;
    }


    }while (q==1);
    //getch();
    return 0;
}

// to go to a specific cursor position
//  takes co-ordinates x and y as input

void gotoXY(int x, int y)
{
    // Locates column
    CursorPosition.X = x;

    // Locates Row
    CursorPosition.Y = y;

    // Sets position for next thing to be printed
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}
