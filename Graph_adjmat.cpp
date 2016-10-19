#include <cmath>
#include <cstdio>
#include <vector>
#include<queue>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph{
    private:
        int N;
        int **E;
    public:
    Graph(int vertex):N(vertex){
        E=new int*[N];
        for(int i=0;i<N;i++){
            E[i]=new int[N];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                E[i][j]= 0;
            }
	   }
    }
    ~Graph(){
        for(int i=0;i<N;i++){
            delete [] E[i];
        }
        delete [] E;
        
    }
     bool insertEdge(int x,int y){
         E[x][y]=1;
         E[y][x]=1;
         return true;         
    }
    bool deleteEdge(int x,int y){
         E[x][y]=0;
         E[y][x]=0;
        return true;
    }
    bool isEmpty(){
         return false;
    }
    bool BFS(int startvertex){
        
        bool *visited=new bool[N];
        for (int k = 0; k < N; k++){         
            visited[k] = false;
        }
	 
        queue<int> q;
        q.push(startvertex);
        visited[startvertex]=true;
        //cout<<startvertex<<' ';
        while(!q.empty()){
            int s=q.front();
            cout<<s<<' ';
            q.pop();
            for(int i=0;i<N;i++){
                if(E[s][i]!=0 &&  visited[i]!=true){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
         return true;
    }
    bool DFS(int startvertex,bool * visited){
         return true;
    }
};
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 2);
    g.insertEdge(2, 0);
    g.insertEdge(2, 3);
    g.insertEdge(3, 1);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
