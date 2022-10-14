#include <iostream>
using namespace std;

struct Node{

    Node* link[26];
    bool flag=false;

    bool containsKey(char ch)
    {
        return (link[ch-'a']!=NULL);
    }

    Node* get(char c)
    {
        return link[ch-'a'];
    }

    voiid put(char ch, Node* node)
    {
         link[ch-'a']=node;
    }
    
    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }

}
 class Trie{
     private:
         Node *root;
     public:
         
    /* Initalize your data structure here  */

    Trie(){
        root = new Node();
    }

    /* Insert the word in trie */

    void insert(string word){
        Node *node=root;

        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                   node->put(word[i],new Node());
            node= node->get(word[i]);
        }
        node->setEnd();
    }

    /* Return if the word is in the trie */

    bool search(string word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                   return false;
            node= node->get(word[i]);
        }
        if(node->isEnd())
            return true;
        return false;
    }

    /* Return if there is any word in the trie that start with given prefix */
    bool startswith(string prefix)
    {
        Node * node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i]))
                 return false;
            node=node->get(prefix[i]);

        }

        return true;
       
    }

 }



int main() {
    cout<<"Hello World!";
}
