#include <iostream>
#include <cstddef>
using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class BST{
    public:
        Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }
           return root;
           }
        }
        
        int getHeight(Node* root){
          //Write your code here
            if(root==NULL)
                return 0;
            if(root->left==NULL && root->right==NULL)
                return 0;
            int ld=getHeight(root->left);
            int rd=getHeight(root->right);
            if(ld>rd){
                 return ld+1;
            }else{
                 return rd+1;
             }                       
        }
};//End of BST
int main(){
    BST myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    int height= myTree.getHeight(root);
    cout<<height;
    return 0;
}
    
