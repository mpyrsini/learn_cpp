// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<vector>
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



// Driver program to test above functions
int main()
{
	
	int array[] = {10, 4, 5, 30, 3, 300};

    MinHeap minHeap(array, 6);
	cout << minHeap.deleteMin() << " ";
	cout <<minHeap.getMin() << " ";
	minHeap.decreaseKey(2, 1);
	cout << minHeap.getMin();
	return 0;
}
