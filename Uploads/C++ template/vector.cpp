#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v1)
{
		for(int i=0;i<v1.size();i++)
        {
         	cout<<v1[i]<<" ";
        	
        }
		cout<<endl;	
}

int main(void)
{
	vector<int> v1;
	int element,size;
	cout<<"\n enter the size of your vector";
    cin>>size;
	for(int i=0;i<size;i++)
    {
    	cout<<"\n enter element "<<i+1<<" to add to this vector";
		cin>>element;
		v1.push_back(element);
	}
	v1.push_back(100);
display(v1);
v1.pop_back();
display(v1);

return 0;
}

