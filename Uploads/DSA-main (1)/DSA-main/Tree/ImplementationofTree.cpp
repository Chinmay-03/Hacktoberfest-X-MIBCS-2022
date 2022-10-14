#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* right;
  Node* left;
  
  Node(int val){
    data=val;
    right=left=NULL;
  }
  
  ~Node(){
    delete left;
    delete right;
  }
}
int main()
{
  struct Node* root= new Node(1);
  root->left = new Node(10);
  root->right = new Node(20);
  root->left->right= new Node(30);
}


               1
             (root)
              / \
             /   \
            /     \
          10      20
          /
         /
        /
       30
