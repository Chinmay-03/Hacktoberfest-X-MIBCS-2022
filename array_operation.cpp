#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[50],arr1[25],n=0,ch,elem,pos,ch1,flag,n1;
    char ans;
    do
    {
        cout<<"\n Menu";
        cout<<"\n1. Read an Array\n2. Display an Array\n3. Insertion \n4. Deletion\n";
        cout<<"\nEnter your Choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"\nEnter the Size of Array:";
                    cin>>n;
                    cout<<"\n Enter the Elements of Array:";
                    for(int i=0;i<n;i++)
                        cin>>arr[i];
                    break;
            case 2:
                    cout<<"\n The Elements of Array before Insertion:";
                    for(int i=0;i<n;i++)
                        cout<<"\t"<<arr[i];
                    break;
            case 3:
                    cout<<"\nInsertion Menu";
                    cout<<"\n1. Insertion At End\n2. Insertion at Start\n3. Insertion at Position";
                    cout<<"\nEnter your Choice:";
                    cin>>ch1;
                    switch(ch1)
                    {
                        case 1:
                                cout<<"\nEnter element to be added:";
                                cin>>elem;
                                arr[n]=elem;
                                n=n+1;
                                cout<<"\n The Elements of Array After Insertion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        case 2:
                                cout<<"\nEnter element to be added:";
                                cin>>elem;
                                for(int i=n-1;i>=0;i--)
                                    arr[i+1]=arr[i];
                                arr[0]=elem;
                                n=n+1;
                                cout<<"\n The Elements of Array After Insertion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        case 3:
                                cout<<"\nEnter element to be added:";
                                cin>>elem;
                                cout<<"\nEnter the poistion at which element needs to be added:";
                                cin>>pos;
                                for(int i=n;i>=pos;i--)
                                    arr[i]=arr[i-1];
                                arr[pos-1]=elem;
                                n=n+1;
                                cout<<"\n The Elements of Array After Insertion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        default:
                                cout<<"\n Wrong Choice";
                    }
                    break;
            case 4:
                    cout<<"\nDeletion Menu";
                    cout<<"\n1. Deletion At End\n2. Deletion at Start\n3. Deletion at Position";
                    cout<<"\nEnter your Choice:";
                    cin>>ch1;
                    switch(ch1)
                    {
                        case 1:
                                cout<<"Element to be deleted:"<<arr[n-1];
                                n=n-1;
                                cout<<"\n The Elements of Array After Deletion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        case 2:
                                cout<<"\nEnter element to be deleted:"<<arr[0];
                                for(int i=0;i<n;i++)
                                    arr[i]=arr[i+1];
                                n=n-1;
                                cout<<"\n The Elements of Array After Deletion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        case 3:
                                cout<<"\nEnter the poistion at which element needs to be deleted:";
                                cin>>pos;
                                for(int i=pos-1;i<n;i++)
                                    arr[i]=arr[i+1];
                                n=n-1;
                                cout<<"\n The Elements of Array After Deletion:";
                                for(int i=0;i<n;i++)
                                    cout<<"\t"<<arr[i];
                                break;
                        default:
                                cout<<"\n Wrong Choice";
                    }
                    break;
        }
        cout<<"\n Do you Want to Continue(y/n):";
        cin>>ans;
    }while(ans=='y' || ans=='Y');
    return 0;
}
