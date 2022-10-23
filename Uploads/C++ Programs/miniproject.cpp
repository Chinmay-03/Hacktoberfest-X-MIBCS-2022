#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<fstream>
using namespace std;

class Student
{
            private:
                int roll;
                char name[20];
                float per;
            public:
                void get();
                void getupdate();
                void put();
                void add();
                void display();
                void search(int key);
                void Delete(int key);
                void update(int key);        

};
void Student ::get()
{
    cout<<"\n\t Enter roll,name,percentage of student:";
    cin>>roll;
    cin>>name;
    cin>>per;
}
void Student ::getupdate()
{
    cout<<"\n\t Enter name,percentage of student to update the record:";
    cin>>name;
    cin>>per;
}
void Student ::put()
{
    cout<<"\n\t"<<setiosflags(ios::left)<<setw(5)<<roll<<setw(20)<<name<<setw(5)<<per;
}
void Student ::add()
{
    Student objs; //student class object created
    fstream objf; //fstream class object created to put data in file
    objf.open("data.txt",ios::app|ios::binary); //open file in append (enter data at end eof) or binary mode
    objs.get(); //accept data from user
    objf.write((char*)&objs,sizeof(objs)); //address of objs data is copied in char pointer(typecast) record written
    if(objf.good()) //check if record added succesfully
    {
        cout<<"\n\t Record added succesfully"; //return zero if not added
    }
    objf.close(); //file close
}

void Student ::display()
{
    Student objs;
    fstream objf; //input stream
    objf.open("data.txt",ios::in|ios::binary); //open file in display or binary mode
    while(objf.read((char*)&objs,sizeof(objs))) //point first character of file read all character till size 
    {
        objs.put();
    } //return zero at eof
    objf.close();
}

void Student ::search(int key)
{
    int x=0;
    Student objs;
    fstream objf; //input stream
    objf.open("data.txt",ios::in|ios::binary); //open file in display or binary mode
    while(objf.read((char*)&objs,sizeof(objs))) //point first character of file read all character till size 
    {
        if(objs.roll==key)
        {
            objs.put();
            x++;
        }
    } //return zero at eof
    objf.close();
    if(x==0)
    {
         cout<<"\n\t Record not found";
    }
    else
    {
        cout<<"\n\t Record found"<<x<<"times";
    }
}

void Student ::Delete(int key)
{
    int x=0;
    Student objs;
    fstream objf; //input stream
    fstream objt;
    objf.open("data.txt",ios::in|ios::binary); //open file in display or binary mode
    objt.open("temp.txt",ios::out|ios::binary);
    while(objf.read((char*)&objs,sizeof(objs))) //point first character of file read all character till size 
    {
        if(objs.roll==key)
        {
            x++;
        }
        else
        {
             objt.write((char*)&objs,sizeof(objs)); 
        }
    } //return zero at eof
    objf.close();
    objt.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
    if(x==0)
    {
         cout<<"\n\t Record not found";
    }
    else
    {
        cout<<"\n\t Record deleted";
    }
}

void Student ::update(int key)
{
    int x=0;
    Student objs;
    fstream objf; //input stream
    fstream objt;
    objf.open("data.txt",ios::in|ios::binary); //open file in display or binary mode
    objt.open("temp.txt",ios::out|ios::binary);
    while(objf.read((char*)&objs,sizeof(objs))) //point first character of file read all character till size 
    {
        if(objs.roll==key)
        {
            x++;
            objs.getupdate();
            objt.write((char*)&objs,sizeof(objs)); 
        }
        else
        {
             objt.write((char*)&objs,sizeof(objs)); 
        }
    } //return zero at eof
    objf.close();
    objt.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
    if(x==0)
    {
         cout<<"\n\t Record not found";
    }
    else
    {
        cout<<"\n\t Record updated";
    }
}
int main()
{
    int ch;
    char c;
    Student obj;
    int roll;
    do{
        system("clear");
        cout<<"\n\t ********************************";
        cout<<"\n\t MENU";
        cout<<"\n\t ********************************";
        cout<<"\n\t 1. Add";
        cout<<"\n\t 2. Display";
        cout<<"\n\t 3. Search";
        cout<<"\n\t 4. Delete";
        cout<<"\n\t 5. Update";
        cout<<"\n\t 6. Exit";
        cout<<"\n\t ********************************";
        cout<<"\n\t Enter your choice(1-6):";
        cin>>ch;
        cout<<"\n\t ********************************";
        switch(ch)
        {
            case 1:
                obj.add();
                break;
            case 2:
                cout<<"\n\t ********************************";
                cout<<"\n\t"<<setiosflags(ios::left)<<setw(5)<<"roll"<<setw(20)<<"name"<<setw(5)<<"per";
                cout<<"\n\t ********************************";
                obj.display();
                cout<<"\n\t ********************************";
                break;
            case 3:
                cout<<"\n\t Enter the roll number to search the record:";
                cin>>roll;
                obj.search(roll);
                break;
            case 4:
                cout<<"\n\t Enter the roll number to delete the record:";
                cin>>roll;
                obj.Delete(roll);
                break;
            case 5:
                cout<<"\n\t Enter the roll number to update the record:";
                cin>>roll;
                obj.update(roll);
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Invalid Input";
        }

        cout<<"\n\t Do you want to continue (y/n):";
        cin>>c;

    } while(c=='y'||c=='Y');
    return 0;
    
}