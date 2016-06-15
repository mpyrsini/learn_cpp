#include <iostream>
#include <queue>
#include <cstdio>
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
        //height(recursively):def:Number of edges on longest path from root to the deepest node.
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
        //height iterative
        //iterative method
        // Iterative method to find height of Bianry Tree
        int getHeight_iteratively(Node* root){
            // Base Case
            if (root == NULL)
                return 0;

            // Create an empty queue for level order tarversal
            queue<Node*> q;

            // Enqueue Root and initialize height
            q.push(root);
            int height = 0;

            while (1)
            {
                // nodeCount (queue size) indicates number of nodes
                // at current lelvel.
                int nodeCount = q.size();
                if (nodeCount == 0)
                    return height;

                height++;

                // Dequeue all nodes of current level and Enqueue all
                // nodes of next level
                while (nodeCount > 0)
                {
                    Node *tempNode = q.front();
                    q.pop();
                    if (tempNode->left != NULL)
                        q.push(tempNode->left);
                    if (tempNode->right != NULL)
                        q.push(tempNode->right);
                    nodeCount--;
                }
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
    
