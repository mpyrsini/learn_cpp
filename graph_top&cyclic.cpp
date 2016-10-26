//Given a sorted dictionary of an alien language, find order of characters  if no valid order is found print invalid

#include<iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int min(int x, int y){
	return (x < y)? x : y;
}

// Class to represent a graph
class Graph{
	int V;
	vector<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
	bool isCyclicUtil(int v,bool *visited,int parent);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
	bool isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;      	// Mark the current node as visited.
	vector<int>::iterator i;    // Recur for all the vertices adjacent to this vertex
	for (i = adj[v].begin(); i != adj[v].end(); i++)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);
	Stack.push(v);              // Push current vertex to stack which stores result
}

// The function to do Topological Sort
void Graph::topologicalSort(){
	stack<int> Stack;           
	bool *visited = new bool[V];    // Mark all the vertices as not visited
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);
	// Print contents of stack
	while (Stack.empty() == false){
		cout << (char) ('a' + Stack.top()) << " ";
		Stack.pop();
	}
}

bool Graph::isCyclicUtil(int v,bool *visited,int parent){
    visited[v]=true;
    vector<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            if(isCyclicUtil(*i,visited,v)){
                return true;
            }
        }else if(*i!=parent){
                return true;
        }
    }
    return false;
}

bool Graph::isCyclic(){
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if( isCyclicUtil(i,visited,-1) ){
                return true;
            }
        }
    }
    return false;
}

void printOrder(string words[], int n, int w){
	Graph g(n);         	    //make Graph
	for(int i=0;i<w-1;i++){
	    string word1=words[i],word2=words[i+1];
	    int len=min(word1.length(),word2.length());
	    for(int j=0;j<len;j++){
	        if(word1[j] != word2[j]){
	            g.addEdge(word1[j]-'a',word2[j]-'a');
	            break;
	        }
	    }
	}
	if(!g.isCyclic()){           //check if Directed Acyclic Graph (DAG)
	    cout<<"Not valid";
	}else{
	    g.topologicalSort();    // Print topological sort
	}
}

// Driver program to test above functions
int main(){
	//string words[] = {"caa", "aaa", "aab"};
    int n,w;    
    cin>>w>>n;
    string words[w];
    for(int i=0;i<w;i++){
        cin>>words[i];
    }
	printOrder(words, n, w);
	return 0;
}
