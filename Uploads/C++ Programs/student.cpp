






#include<iostream>
#include<string.h>
using namespace std;
class student
{
public:   int rno;
          char name[30];
          char std[5];
          char div;
          char dob[15];
          char bloodgrp[4];
          unsigned long int contact;
          char address[200];
          static int count; 
         void getdata();
         friend void display(student); 
        
student()      //constructor
{
  rno=0;
  cout<<"\t Constructor";
  rno=count;
  count++;
}        

static void getcount()     //Static member functiorn
{
cout<<"\n count"<<count;
}

student(student & obj)     //copy constructor
{
rno=obj.rno;
div=obj.div;
contact=obj.contact;
strcpy(name,obj.name);
strcpy(dob,obj.dob);
strcpy(std,obj.std);
strcpy(bloodgrp,obj.bloodgrp);
count++;
}

~student()
{
cout<<"\n DEstructor";
cout<<"\n Destroying the object";
count++;
}

       
};     //End of class

int student::count=0;

void student::getdata()
{
cout<<"\n"<<"Enter roll no: ";
cin>>rno;
cout<<"Enter name: ";
cin>>name;
cout<<"Enter standard: ";
cin>>std;
cout<<"Enter division: ";
cin>>div;
cout<<"Enter date of birth[dd|mm|yyyy]: ";
cin>>dob;
cout<<"Enter contact number: ";
cin>>contact;
cout<<"Enter blood group: ";
cin>>bloodgrp;
};

void display(student obj)
{
cout<<"\n"<<"Roll No: "<<obj.rno<<"\n";
cout<<"Name: "<<obj.name<<"\n";
cout<<"Standard: "<<obj.std<<"\n";
cout<<"Division: "<<obj.div<<"\n";
cout<<"Date of birth: "<<obj.dob<<"\n";
cout<<"Contact No: "<<obj.contact<<"\n";
cout<<"Blood group: "<<obj.bloodgrp<<"\n";
}

int main(){
student s1;

student s2(s1);
s1.getdata();
display(s1);

student *s[50];
int i,n;
cout<<"\n How many student object you want to create";
cin>>n;

for(i=0;i<n;i++)
{
s[i]=new student();
}

for(i=0;i<n;i++)
{
s[i]->getdata();
}

for(i=0;i<n;i++)
{
delete(s[i]);
}

return 0;
} 

