#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
	map<string,int> m1;
	//m1.insert({{"ashi",84},{"ayra",80}});
	m1["kanu"]=90;
	m1["abhay"]=91;
	m1["tanu"]=77;
	m1["shreya"]=87;
	m1["surbhi"]=92;
	
	
	//inserting using insert function
	map<string,int>::iterator iter;
	for(iter=m1.begin();iter!=m1.end();iter++)
	{
		cout<<(*iter).first<<"\t"<<(*iter).second<<"\n";
		
   }	


return 0;
}
