#include<iostream>
using namespace std;

// Print function for graph: it carry four arguments and they are edges, number of vertices 'n', starting vertices 'sv' and visited array  

void print(int** edges, int n, int sv, bool* visited)
{
    cout<<sv<<endl;        // very first we print the starting vertices
    visited[sv]=true;      //  and then mark true in visited array so that we can not print again that particular vertices 

    // Now we will run the loop to traverse through out the graph and print its values 

    for(int i=0;i<n;i++)   
    {   if(i == sv)       // we will check weather the our particular loop is equal to starting vertices 
        {
           continue;      // if yes then we will continue with the loop
        }
         if(edges[sv][i] == 1)     // check weather there is connection is present or not : if yes we will continue
         {  
             if(visited[i])        // check visited matrix it is printed earlier or not : if printed then we will not execute that paticular edges
            {
                continue;
            }
            print(edges,n,i,visited);   // if not visited then we will call our print function in which we will pass the particulae edges and i
         }
    }
}

int main()
{
    int n,e;                              //  two variables for the vertices and edges

    // take inputs and store into them

    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter number of edges:";
    cin>>e;
    
    // dynamically allocate the the twoD array and initialize it with zero

    int** edges= new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++ )
        {
            edges[i][j] = 0;
        }
    }

    // take the connection infromation from the user and put 1 or 0 if there is connection or not 
    
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // creat the bool array in which we will take care of visited vertices 

    bool *visited=new bool[n];

    // initialize all the 0 because they are not visited at this time,

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    print(edges,n,0,visited);  // call the print function

} 
