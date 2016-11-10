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
        //current def of height of BST:Number of edges on longest path from root to the deepest node.
        //Recursively method to find height of Bianry Tree
        int getHeight_recursively(Node* root){
          //Write your code here
            if(root==NULL)
                return 0;
            if(root->left==NULL && root->right==NULL)
                return 0;   //return 1 for other def
            int ld=getHeight_recursively(root->left);
            int rd=getHeight_recursively(root->right);
            if(ld>rd){
                 return ld+1;
            }else{
                 return rd+1;
             }                       
        }
        
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
                    return height-1;  //return height for other def

                height++;

                // Dequeue all nodes of current level and Enqueue all
                // nodes of next level
                while (nodeCount > 0)
                {
                    Node *tempNode = q.front();
                    q.pop();
                    nodeCount--;
                    if (tempNode->left != NULL)
                        q.push(tempNode->left);
                    if (tempNode->right != NULL)
                        q.push(tempNode->right);
                    
                }
            }
        }
        // label order traversla of BST
        void levelOrder(Node * root){      
        // Create an empty queue for level order tarversal
            queue<Node*> q;

            // Enqueue Root 
            q.push(root);
            while (1)
            {
                // nodeCount (queue size) indicates number of nodes
                // at current lelvel.
                int nodeCount = q.size();
                if (nodeCount == 0)
                    break;
                // Dequeue all nodes of current level and Enqueue all
                // nodes of next level
                while (nodeCount > 0)
                {
                    Node *tempNode = q.front();
                    cout<<tempNode->data<<" ";
                    q.pop();
                    nodeCount--;
                    if (tempNode->left != NULL)
                        q.push(tempNode->left);
                    if (tempNode->right != NULL)
                        q.push(tempNode->right);
                }
            }
  
	}
    void inorder_traversal(Node *root){        
        if(root==NULL){
            return;
        }
        inorder_traversal(root->left);
        cout<<root->data<<" ";
        inorder_traversal(root->right);
    }
    //
    void KthSmallest_util(Node *root,int k,int *count){        
        if(root==NULL || *count>=k){
            return;
        }
        KthSmallest_util(root->left,k,count);
        (*count)++;
        if(*count==k){
            cout<<root->data;
            return;
        }        
         KthSmallest_util(root->right,k,count);
        
    }
    
    void KthLargest_util(Node *root,int k,int *count){
        if(root==NULL || *count >=k){
            return;
        }        
        KthLargest_util(root->right,k,count);
         (*count)+=1;
        if(*count ==k){
            cout<<root->data;
            return;
        }
       
        KthLargest_util(root->left,k,count);
        
    }
   int order_statistic(Node *root,int k){
        int count=0;
        KthSmallest_util(root,k,&count);
        //KthLargest_util(root,k,&count);
        return count;
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
    int height1= myTree.getHeight_recursively(root);
    cout<<height1<<endl;
    int height2= myTree.getHeight_iteratively(root);
    cout<<height2<<endl;
    cout<<"level-oreer\n"<<endl;
    myTree.levelOrder(root);
    cout<<"\nin-order\n"<<endl;
    myTree.inorder_traversal(root);
    cout<<"\n kth smallest"<<endl;
    myTree.order_statistic(root,3);
    return 0;
}
