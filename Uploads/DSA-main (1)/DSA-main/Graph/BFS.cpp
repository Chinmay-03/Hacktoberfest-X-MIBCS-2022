#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


// print function arry some arguments such as matrix, number of vertex, strting vertex and visited array

void print(int **arr, int n, int starting_vertex, bool *visited)
{
    queue<int> q;                 // creat queue in which we will store the vertex
    q.push(starting_vertex);      // push sv
    visited[starting_vertex] = true;  // mark sv visited 

    // run while loop untill it gets empty

    while (!q.empty()) {    

        cout << q.front() << " ";             // display q front
        int current_element = q.front();      // store the front into variable
        q.pop();                              // pop the front of queue

        // run the for loop from 1 to n  check every matrix weather it has connection or not along with that it is visited or not 
                                                
        for (int i = 1; i < n; i++) {        
            if (arr[current_element][i] == 1 && !visited[i] && i != current_element){   
                q.push(i);          // if the ith index have edage and not visisted then we will push that index into queue 
                visited[i] = true;  // and mark that index visited
     
            }
        }
    }
}



void BFS( int **arr , bool* visited , int starting_index , int v){
    // in this function we will check first weather it is visited or not by using loop 
    // and will call print function one by one 
    for (int i = 0; i < v; i++){
        if (!visited[i]) {
            print(arr, v, i, visited);
        }
    }
}
int main()
{
    int v, e;                          // v = number of vertices in graph: e= number of edges in graph
    cin >> v >> e;                    // take input from the graph
    int **arr = new int *[v];         // creat dynamic matrix of size v i.e number of vertices 

  // make all value of matrix initially zero 

    for (int i = 0; i < v; i++){
        arr[i] = new int[v];      
        for (int j = 0; j < v; j++){
            arr[i][j] = 0;
        }
    }

// now its the time to store the edages between verices  

    while (e--){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

   // creat the visited array which will help us to know weather the vertex is visited or not 
   // to do this we can either use for loop or memset function to assign all value zero initially, as mentioned below. 

    bool *visited = new bool[v];
    // for (int i = 0; i < v; i++){
    //     visited[i] = false;
    // }
    memset(visited,false,sizeof(visited));

// call the bfs function in which we will pass the  matrix:'arr', 'visited' starting index and number of vertex

    BFS( arr , visited ,0 , v );   
}
