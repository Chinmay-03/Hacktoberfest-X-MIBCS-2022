/*
Name: Omkar khurdal
Roll no: 28
Date: 20th sept 2022
*/
#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;


//Bresenham circle Drawing Algorithm
class brescircle
{
 int x , y , xi , yi , r , del , limit , sig1 , sig2;
 public:
  void circle(int,int,int);
  void mh();
  void md();
  void mv();
};

void brescircle :: circle(int x , int y , int r)
{
 limit=0;
 xi=0;
 yi=r;
 del=2*(1-r);
 while(yi>=limit)
 {
  putpixel(x+xi , y+yi , RED);
  putpixel(x+xi , y-yi , RED);
  putpixel(x-xi , y-yi , RED);
  putpixel(x-xi , y+yi , RED);
  
  if(del<0)
  {
   sig1=((2*del)+(2*yi)-1);
   if(sig1<=0)
   {
    mh();
   }
   
   else
   {
    md();
   }
  }
  
  else if(del>0)
  {
   sig2=((2*del)-(2*xi)-1);
   if(sig2<=0)
   {
    md();
   }
   else
   {
    mv();
   }
  }
  else if(del==0)
  {
   md();
   
  } 
 }
}

void brescircle::mh()
{
 xi=xi+1;
 del=del+2*xi +1;
}

void brescircle::mv()
{
 yi=yi-1;
 del=del- 2*yi +1;
}

void brescircle::md()
{
 xi=xi+1;
 yi=yi-1;
 del=del+2*xi - 2*yi +2;
}

//DDA Line Drawing Algorithm

void DDA_line(int x1,int y1,int x2,int y2,int icolour)
{

 int i;
 float dx,dy,steps,xinc,yinc,X,Y;;
 dx = (x2-x1);
 dy = (y2-y1);
    
 if (fabs(dx)>fabs(dy))
 {
    
  steps = fabs(dx);
 }
    
 else
 {
  
  steps = fabs(dy);
 }
  xinc = dx/steps;
  yinc = dy/steps;
  
  X=x1;
  Y=y1;
  
  
  
  for( i=0; i<steps ; i++)
  {
   putpixel(floor(X),floor(Y),icolour);
   X = X + xinc;
   Y = Y + yinc;
  }   
}


void Program_A()
 {
  brescircle c;
  //outer circle
  c.circle(250,250,150);
  //inner circle
     c.circle(250,250,75);
     //middle triangle
  DDA_line(250,100,120.09619,325,RED);
  DDA_line(250,100,379.90381,325,RED);
  DDA_line(120.09619,325,379.90381,325,RED);
 }

void Program_B()
 {
  brescircle c;
  //outer reactangle
  DDA_line(200,150,600,150,RED);
  DDA_line(200,150,200,450,RED);
  DDA_line(200,450,600,450,RED);
  DDA_line(600,150,600,450,RED);
  //inner diamond
  DDA_line(400,150,200,300,RED);
  DDA_line(400,150,600,300,RED);
  DDA_line(200,300,400,450,RED);
  DDA_line(400,450,600,300,RED);
  //innermost circle
  c.circle(400,300,120);
 }


    
int main()
{
 void DDA_line(int x1,int y1,int x2,int y2,int icolour);
 int Choice;
 int gDriver=DETECT,gMode;  
 cout<<"\t\t\t ****Choice Menu****"<<endl;
 cout<<"-------------------------------------------------------"<<endl;
 cout<<"(1) Display first figure."<<endl;
 cout<<"(2) Display second figure."<<endl;
 cout<<"(3) Exit the program."<<endl;
 cout<<"-------------------------------------------------------"<<endl;
 cout<<"Enter Your Choice :"<<endl;
 cin>>Choice;
 initgraph(&gDriver,&gMode,NULL);

    switch(Choice)
    
  {
   case 1:
    Program_A();
    break;
   
   
   case 2:
    Program_B();
    break;
   
  
   case 3:
    cout<<"Exiting the program.....";
    exit(0);
    break;
   default :
    cout<<"Wrong choice entered , re-execute and enter correct choice!!!";

    exit(0);
    break;
    
  }
    

 getch();
 return 0;
  
}


