#include <iostream>
using namespace std;
 
typedef struct node Node;
struct node
{
    int data;
    Node *next_pointer;
};
 
const int n = 5;
Node *adjList[n];
int visited[100] = {0};
Node *create_node();
void insert_in_ending(int value, Node **start);
void linked_list_print(Node *start);
 
void dfs(Node *start){
    if(start == NULL || visited[start->data] == 1) return;
    
    visited[start->data] = 1;
    cout<<start->data<<" ";
    dfs(adjList[start->next_pointer->data]);
}
 
int main(){
 
    for(int i=0;i<5;i++){
        adjList[i] = NULL;
        insert_in_ending(i,&adjList[i]);
    }
 
    int m,k,l;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>k>>l;
        insert_in_ending(k, &adjList[l]);
        insert_in_ending(l, &adjList[k]);
    }
 
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            // cout<<i<<" ";
            // visited[i] = 1;
            dfs(adjList[i]);
        }
        // linked_list_print(start[i]);
    }
 
 
}
 
Node *create_node()
{
    Node *node = (Node *)malloc(sizeof(Node));
 
    if (node == NULL)
    {
        cout << "Error while creating new node" << endl;
    }
    return node;
}
 
void linked_list_print(Node *start)
{
    if (start == NULL)
    {
        cout << "Empty Linked List" << endl;
        exit(1);
    }
    Node *current_node = start;
    while (current_node != NULL)
    {
        cout << current_node->data << " ";
        current_node = current_node->next_pointer;
    }
    cout << endl;
}
 
void insert_in_ending(int value, Node **start)
{
    Node *current_node = *start;
    Node *new_node = create_node();
 
    if (current_node == NULL)
    {
        *start = new_node;
        current_node = new_node;
        current_node->next_pointer = NULL;
    }
    while (current_node->next_pointer != NULL)
    {
        current_node = current_node->next_pointer;
    }
    new_node->data = value;
    current_node->next_pointer = new_node;
    new_node->next_pointer = NULL;
}
