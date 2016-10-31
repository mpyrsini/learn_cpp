#include<iostream>
#include <vector>
#include <stack>
#include<climits>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

// A class for Min Heap
class MinHeap{
	vector<int>  heap;
	int heap_size; // Current number of elements in min heap
    void heapifyup(int index);
    void heapifydown(int index);
public:
	MinHeap(int n);
    MinHeap(int arr[],int n);
    MinHeap(const vector<int>& vector);
    
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	
	void insertKey(int key);
	int getMin() { return heap[0]; }
	int deleteMin();
	void decreaseKey(int i, int new_val);
	void deleteKey(int i);
	
};

MinHeap::MinHeap(int n):heap(n),heap_size(n){
}

MinHeap::MinHeap(int arr[],int n):heap(n),heap_size(n){
	 for(int i = 0; i < heap_size; ++i){
        heap[i] = arr[i];
    }
    for(int i=heap_size-1; i>=0; --i){
        heapifydown(i);
    }

}

MinHeap::MinHeap(const vector<int>& vector) : heap(vector){
    heap_size=heap.size();
    for(int i=heap_size-1; i>=0; --i)
    {
        heapifydown(i);
    }
}
// Inserts a new key 'k'
void MinHeap::insertKey(int key){
	// First insert the new key at the end
	heap_size=heap.size();
	heap_size++;
	int i = heap_size - 1;
	heap[i] = key;
    heapifyup(i);
}

void MinHeap::decreaseKey(int i, int new_val){
	heap[i] = new_val;
	while (i != 0 && heap[parent(i)] > heap[i])
	{
	swap(&heap[i], &heap[parent(i)]);
	i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::deleteMin(){
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1){
		heap_size--;
		return heap[0];
	}

	// Store the minimum vakue, and remove it from heap
	int root = heap[0];
	heap[0] = heap[heap_size-1];
	heap_size--;
	heapifydown(0);
	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	deleteMin();
}

void MinHeap::heapifyup(int i){
    if(i==0){   //at root
        return ;
    }
    int p=parent(i);
    if(heap[p]>heap[i]){
        swap(&heap[p], &heap[i]);
        heapifyup(p);
    }
}

void MinHeap::heapifydown(int i){
    
    int l = left(i);
    if(l>=heap.size())
        return; //index is a leaf
	int r = right(i);
	int smallest = i;
	if (l < heap_size && heap[l] < heap[i])
		smallest = l;
	if (r < heap_size && heap[r] < heap[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&heap[i], &heap[smallest]);
		heapifydown(smallest);
	}
}




int min(int x, int y){
	return (x < y)? x : y;
}

// Class to represent a graph
class Graph{
	int V;
	vector<int> *adj;
public:
	Graph(int V);
	void addEdge(int u,int v, int w);
	void PrimMST();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int u,int v, int w){
	adj[v].push_back(w);
}

// The main function that constructs Minimum Spanning Tree (MST)
// using Prim's algorithm
void Graph::PrimMST(Graph g){
    int V = graph->V;// Get the number of vertices in graph
    int parent[V];   // Array to store constructed MST
    int key[V];      // Key values used to pick minimum weight edge in cut
 
   
    struct MinHeap* minHeap =new MinHeap(V);
 
    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }
 
    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0]   = 0;
 
    // Initially size of min heap is equal to V
    minHeap->size = V;
 
    // In the followin loop, min heap contains all nodes
    // not yet added to MST.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum key value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // Store the extracted vertex number
 
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
 
            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
 
    // print edges of MST
    printArr(parent, V);
}
 //http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-mst-for-adjacency-list-representation/
 
// Driver program to test above functions
int main()
{
    // Let us create the graph given in above fugure
    int V = 9;
    Graph g(V);
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
 
    PrimMST(g);
 
    return 0;
}
