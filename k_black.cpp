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
        void DFSutil(int vertex,bool *visited);
        //https://www.youtube.com/watch?v=fpGr2dk3UOo
        bool isCyclicUtil(int v, bool visited[], int parent);
    public:
        Graph(int vertex);
        ~Graph();
        bool insertEdge(int x,int y);
        bool deleteEdge(int x,int y);
        bool BFS(int startvertex);
        bool DFS(int startvertex);
        bool isCyclic();
        int n_black();
};
Graph::Graph(int vertex):N(vertex){
        E=new int*[N];
        for(int i=0;i<N;i++){
            E[i]=new int[N];
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                E[i][j]= -1;
            }
	   }
    }
Graph::~Graph(){
        for(int i=0;i<N;i++){
            delete [] E[i];
        }
        delete [] E;
        
    }
bool Graph::insertEdge(int x,int y){
         E[x][y]=1;
         E[y][x]=1;
         return true;         
    }
bool Graph::BFS(int startvertex){
        
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
                if(E[s][i]!=-1 &&  visited[i]!=true){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
         return true;
    }
void Graph::DFSutil(int vertex,bool *visited){
            visited[vertex]=true;
            cout<<vertex<<' ';
            for(int i=0;i<N;i++){
                if(E[vertex][i]!=-1 && visited[i] != true){
                    DFSutil(i,visited);
                }
            }
        }
bool Graph::DFS(int startvertex){        
        bool *visited=new bool[N];
        for (int k = 0; k < N; k++){         
            visited[k] = false;
        }
        DFSutil(startvertex,visited);
        return true;
}
//We do a DFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, 
bool Graph::isCyclicUtil(int v, bool visited[], int parent){
        visited[v]=true;
        for(int i=0;i<N;i++){
            if(E[v][i]!=-1){    //niegbour i is connected
                if(visited[i] !=true){      //niegbour i is not visited
                    if (isCyclicUtil(i, visited, v))
                        return true;
                }else if(i!=parent){        //niegbour i is visited and not parents  of current vertex,
        // then there is a cycle.
                        return true;
                }
            }
            
        }
        return false;
}
bool Graph::isCyclic(){
        bool *visited=new bool[N];
        for (int k = 0; k < N; k++){         
            visited[k] = false;
        }
    
        for(int i=0;i<N;i++){
            if(!visited[i]){
                if(isCyclicUtil(i,visited,-1)){
                    return true;
                }
            }
        }
        return false;
}

int Graph::n_black(){
    
    bool *visited=new bool[N];
    int *colour=new int[N];
    
    for(int i=0;i<N;i++){
        visited[i]=false;
        colour[i]=0;
    }
    queue<int> q;
    //start bfs from root
    q.push(0);
    visited[0]=true;
    
    bool flag=true;
    colour[0]=1;
    
    while(!q.empty()){
        int v=q.front();
        q.pop();
        if(q.empty()==true){    //change of height occuring
            flag=!flag;
            cout<<flag;
        }
        for(int i=0; (i<N ) && (i!=v); i++ ){
            if(E[v][i]!=-1 ){   //if i is connected
                cout<<i<<' ';
                if(flag==false){    //even height
                    if(visited[i]==true && colour[i]==1){
                        return -1;
                    }else if(visited[i]==false) {
                        q.push(i);
                        colour[i]=2;
                    }
                    
                }else{              //odd height
                    if(visited[i]==true && colour[i]==2){
                        return -1;
                    }else if(visited[i]==false) {
                         colour[i]=1;
                         q.push(i);
                    }
                        
                   
                }
                    
            }
        }
    }
    int count=0;
    cout<<"hi"<<endl;
    for(int i=0;i<N;i++){
        if(colour[i]==2){
            count++;
        }
        cout<<colour[i]<<' ';
    }
    return count;
}
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    //g.insertEdge(2, 3);
    //g.insertEdge(3, 1);
    //g.insertEdge(3, 5);
    //g.insertEdge(5, 2);
    //g.insertEdge(5, 4);
 
    //cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
   // g.BFS(0);
   // cout << "\nFollowing is depth First Traversal (starting from vertex 2) \n";
   // g.DFS(0);
   // g.isCyclic()? cout << "\nGraph contains cycle\n":
    //               cout << "\nGraph doesn't contain cycle\n";
    cout<<g.n_black();
    return 0;
}
