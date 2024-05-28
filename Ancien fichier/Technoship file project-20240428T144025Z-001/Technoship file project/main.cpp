#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

void delete_student()
{

    fstream stud;
    fstream temp;

    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char age[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout<<" \n\t enter the phone number to delete record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        if(strcmp(phone,a)==0)
        {
            continue;
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(age,25);
        stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void update_student()
{
    fstream stud;
    fstream temp;

    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [25];
    char age[25];
    char phone [25];
    char a[25];
    cin.ignore();
    cout<<" \n\t enter the phone number to update record : ";
    cin.getline(a,25);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        if(strcmp(phone,a)==0)
        {

            cout<<" \n\tenter new value of record  \n ";
            cout<<" \n name : ";
            cin.getline(name,25);
            cout<<" \n phone : ";
            cin.getline(phone,25);
            cout<<" \n age : ";
            cin.getline(age,25);
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }
        else
        {
            temp<< name<<'|'<<phone<<'|'<<age<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
        temp.getline(phone,25,'|');
        temp.getline(age,25);
        stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void display_all()
{
    char name [25];
    char age[25];
    char phone [25];

    fstream stud;
    stud.open("student.txt",ios::in);

    cout<< " \n\t name \t phone \t age \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<age<<endl;

    }
}
void search_student(   )
{

    fstream stud;
    stud.open("student.txt",ios::in);
    char name [25];
    char age[25];
    char phone [25];
    char a[25];
    cout<<" \n enter the phone to search about it : ";
    cin.ignore();
    cin.getline(a,25);
    int x=0;
    cout<< " \n\t name \t phone \t age \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
        stud.getline(phone,25,'|');
        stud.getline(age,25);
        if(strcmp(phone, a)==0)
        {
            cout<< "\n \t "<< name << "\t"<<phone<<"\t"<<age<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    stud.close();
}
void  insert_student()
{

    char name [25];
    char age[25];
    char phone [25];
    fstream stud;
    stud.open("student.txt", ios::app);
    cin.ignore();
    cout<<" \n name : ";
    cin.getline(name,25);
    cout<<" \n phone : ";
    cin.getline(phone,25);
    cout<<" \n age : ";
    cin.getline(age,25);
    stud<< name<<'|'<<phone<<'|'<<age<<'\n';
    cout<< "done !";
    stud.close();
}

int main()
{
    bool flag=true;
    while (flag)
    {
        cout << " insert : 1 \n search : 2 \n display all : 3 \n update : 4 \n delete :  5 \n write your choose : ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
            insert_student();
            break;
        case 2:
            search_student();
            break;
        case 3:
            display_all();
            break;
        case 4 :
            update_student();

            break;
        case 5 :
            delete_student();
            break;
        default :
            cout << " \n choose right number \n";
        }
        cout << " if you continue to use program press ' y ' \n ";
        char f;
        cin>>f;
        if(f!='y')
        {
            flag=false;
        }
    }
    return 0;
}

