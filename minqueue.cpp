/* 
Author: Ichhit Joshi, Nam Ngo
Date: Sept 23, 2022
CS271 Fall 2022
*/

#ifndef MIN_QUEUE
#define MIN_QUEUE

#include <iostream>
#include <string> 
#include <sstream>
#include <cmath>

using namespace std;

template <typename T>
class MinQueue
{
    private:
        T* heap; //pointer to an array to store the heap
        int size; // size of the heap
        int maxSize; // size of the array

        int getLeftChild(int i);
        int getRightChild(int i);
        int getParent(int i);
        void heapify(int i);
        void build_min_heap();
        void heapsort(T* A);

    public:
        MinQueue(); 
        MinQueue(T* A, int n);

        int getSize();
        void insert(T x); 
        T min();
        T extract_min();
        void decrease_key(int i, T k);
        void sort(T* A);
        string to_string();
       
};

// Pre-condition: an element with given index exists in the queue
template <typename T>
int MinQueue<T>::getLeftChild(int i){
    /*
    Parameters:
    i : current index in the heap 
    */
   
    return (2*i) + 1;
}
// Post-condition: Index of parent of element at index i is returned

// Pre-condition: an element with given index exists in the queue
template <typename T>
int MinQueue<T>::getRightChild(int i){
    /*
    Parameters:
    i : current index in the heap 



    */

    return (2*i) + 2;
}
// Post-condition: Index of right child of element at index i is returned

// Pre-condition: an element with given index exists in the queue
template <typename T>
int MinQueue<T>::getParent(int i){
    /*
    Parameters:
    i : current index in the heap 



    */

    if(i == 0){
        return -1;
    }
    return (i-1)/2;
}
// Post-condition: Index of right child of element at index i is returned


// Pre-condition: a queue exists
template <typename T> 
int MinQueue<T>::getSize(){
    /*
    Parameters:
    i : current index in the heap 
    */

    return maxSize;
}
// Post-condition: Size of the array that is storing the queue is returned


// Pre-condition: a queue already has at least 1 element
template <typename T>
void MinQueue<T>::heapify(int i){
    /*
    Parameters:
    i : current index in the heap 
    */

    int smallest = i; // assume element at index i is smallest initially
    int left = getLeftChild(i);
    int right = getRightChild(i);

    if(left < size && heap[left] < heap[i]){ //check for which index in the heap has the smallest value
        smallest = left;

    }

    if(right < size && heap[right] < heap[smallest]){ //check for which index in the heap has the smallest value
        smallest = right;
    }

    if(smallest != i){ // if index with smaller value is found
        T temp = heap[smallest]; 
        heap[smallest] = heap[i];
        heap[i] = temp; //swap the index i with the index with smaller value

        heapify(smallest); //
    }

}
// Post-condition: Returns the heap from the i index after maintaining the minimum heap property

// Pre-condition: The queue has atleast 1 element
template <typename T>
void MinQueue<T>::build_min_heap(){
    /*
    Parameters:
    None



    */
    size = maxSize;

    for(int i =floor(size/2); i >= 0 ; i--){
        heapify(i); //maintains minimum heap property for index i
    }

}
// Post-condition: A queue with the minimum heap property is created


// Pre-condition: The queue has atleast one element
template <typename T>
void MinQueue<T>::heapsort(T* A){
    /*
    Parameters:
    A: pointer to an array that needs to be sorted


    */

    build_min_heap(); //maintains the minimum heap property for the heap array


    for(int i = maxSize-1; i >= 0; i--){ //sorts the array in descending order and overwrites A in ascending order
    
        T temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp; //swaps the minimum element with the element at index i

        A[maxSize-i-1] = heap[i]; //overwrites A[maxSize-i-1] with current minimum element 

        size--; //decreases the heap size

        heapify(0); //maintains minimum heap property from the root 
    }

}
// Post-condition: Array A is sorted in ascending order


// Pre-condition: None
template <typename T>
MinQueue<T>::MinQueue(){
    /*
    Parameters:
    None
    */

    maxSize = 0;
    heap = new T[maxSize];
    size = maxSize;

}

//Post-condition: a new empty queue is created

//Pre-condition: None
template <typename T>
MinQueue<T>::MinQueue(T* A, int n){
    /*
    Parameters:
    A: pointer to an array that needs to be added to the queue
    n: size of the array

    */

    heap = new T[n]; //creates an array of size n

    for(int i = 0; i < n; i++){ //copies the contents from A into heap array
        heap[i] = A[i]; 
    }
    
    maxSize = n;
    size = maxSize; //sets size of the heap to the actual size of the array
    build_min_heap(); //maintains minimum heap property for heap
    
}
//Post-condition: a minimum priority queue is created with the elements of A

//Pre-condition: a minimum priority queue exists with atleast 0 elements
template <typename T>
void MinQueue<T>::insert(T x){
    /*
    Parameters:x
    x: element that is to be added in the queue

    */

    if(size == maxSize){
        maxSize++;
        T* temp = new T[maxSize]; //creates a new array with size + 1

        for(int i = 0; i < maxSize-1; i++){ //copies elements from heap into temp array
            temp[i] = heap[i];
        }

        T* temp2 = heap; //temp2 points to heap
        heap = temp; //heap points to the new array
        delete[] temp2; //deallocating space for temp2

   }

   size++;

   T k = x;

   heap[size-1] = std::numeric_limits<T>::max();

   decrease_key(size-1, k); //decreases value at index size to new value k
}
// Post-condition: A new queue is made with the new inserted value

//Pre-condition: a minimum priority queue exists with atleast 0 elements
template <typename T>
T MinQueue<T>::min(){
    /*
    Parameters:
    None

    */

    if (maxSize == 0 ){ //if queue is empty
        return T();
        
    }
    return heap[0];

}
// Post-condition: element at root which is the minimum value is returned

//Pre-condition: a minimum priority queue exists with atleast 0 elements
template <typename T>
T MinQueue<T>::extract_min(){
    /*
    Parameters:
    None



    */

    if (maxSize == 0 ){ //if queue is empty
        return T();
    }

    T min_return = heap[0]; //stores the minimum value
    heap[0] = heap[maxSize-1] ; //stores last element into the root
    maxSize --; //decrements size of array
    heapify(0); //maintains the minimum heap property at root

    size = maxSize; //sets size of the heap to the actual size of the array
    return min_return;

}
// Post-condition: element at root which is the minimum value is returned and popped out of the queue


//Pre-condition: a minimum priority queue exists with atleast 0 elements
template <typename T>
void MinQueue<T>::decrease_key(int i, T k){
    /*
    Parameters:
    i : index of element 
    k : new value to replace

    */

    if(i >= size){ //checks if i is valid
        return;
    }

    if(std::numeric_limits<T>::min() != std::numeric_limits<T>::max()){
        if(k >= heap[i]){
            return;
        }
    }

    heap[i] = k; //sets new value at index i

    while(i > 0 && heap[i] < heap[getParent(i)]){ 
        T temp = heap[getParent(i)];
        heap[getParent(i)] = heap[i];
        heap[i] = temp; //swaps the parent with the element at index i

        i = getParent(i);

    }
 
}
//Post-condition: Returns an updated queue

// Pre-condition: A queue exists
template <typename T>
void MinQueue<T>::sort(T* A){
    /*
    Parameters:
    A: array to sort

    */
   
    heapsort(A); //sorts heap in descending order and array A in ascending order
    build_min_heap(); //converts the sorted heap to maintain the minimum heap property
}
// Post-condition: Sorts array A in ascending order


// Pre-condition: A queue exists
template <typename T>
string MinQueue<T>::to_string(){

    stringstream ss;
    string s = "";
    
    for(int i = 0; i < size; i++){ // converts the element into a string form
        ss.str("");
        ss << heap[i] << " "; 
        s = s + ss.str();
    }
   
    return s.substr(0,s.size()-1);
}
// Post-condition: Returns a string with the elements of the queue in order

#endif
