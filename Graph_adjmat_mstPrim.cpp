#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
using namespace std;

int min_key(int key[],bool mstSet[],int N){
    int min =100000000 , index;
    for(int i=0;i<N;i++){
        if(mstSet[i]==false && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

class Graph{
    private:
        int N;
        int **E;
    public:
        Graph(int vertex);
        ~Graph();
        bool insertEdge(int x,int y,int w);
        void mstPrim();
};
Graph::Graph(int vertex):N(vertex){
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
Graph::~Graph(){
        for(int i=0;i<N;i++){
            delete [] E[i];
        }
        delete [] E;
        
    }
bool Graph::insertEdge(int x,int y,int w){
         E[x][y]=w;
         E[y][x]=w;
         cout<<"hi";
         return true;  
}
void Graph::mstPrim(){
    
    int parent[N];
    int key[N];
    bool mstSet[N];
    for(int i=0;i<N;i++){
        key[i]=100000;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<N-1;count++){
        int u=min_key(key,mstSet,N);
        mstSet[u]=true;
        for(int v=0;v<N;v++){
            if(E[u][v] && mstSet[v]==false && E[u][v] < key[v]){
                key[v]=E[u][v];
                parent[v]=u;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<i<<" "<<parent[i]<<" "<<E[i][parent[i]]<<endl;
    }
}
// Driver program to test methods of graph class
int main()
{
    cout<<"Hi";
    Graph g(5);
    g.insertEdge(0,1,2);
    g.insertEdge(0,3,6);
    g.insertEdge(1,2,3);
    g.insertEdge(1,3,8);
    g.insertEdge(1,4,5);
    g.insertEdge(2,4,7);
    g.insertEdge(3,4,9);
    
    g.mstPrim();
    cout<<"Hi";
    return 0;
}

/*
     graph[V][V] = {{0, 2, 0, 6, 0},
					{2, 0, 3, 8, 5},
					{0, 3, 0, 0, 7},
					{6, 8, 0, 0, 9},
					{0, 5, 7, 9, 0},
					};

 */
