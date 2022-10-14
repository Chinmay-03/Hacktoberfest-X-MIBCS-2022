#include <iostream>
#include <queue>
using namespace std;
struct Node{
    public:
    int key;
    Node *left;
    Node *right;

};
Node* createnode(int key){
    Node *node=new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;



    return node;


}
Node* search(Node* root,int key){
    if(root==NULL){
        return NULL;

    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->key==key){
            
            cout<<"HIT"<<endl;

        }
        if(temp->left!=NULL){
            q.push(temp->left);

        }
        if(temp->right!=NULL){
            q.push(temp->right);

        }
        return 0;
    }

}
int main(){
    Node *root=createnode(1);
    cout<<root->key<<endl;
    root->left=createnode(2);
    root->left->left=createnode(4);
    root->right=createnode(3);
    root->right->left=createnode(5);


    Node *node=search(root,4);
    cout<<node->key<<endl;





    return 0;
}