/* 
Author: Ichhit Joshi, Nam Ngo
Date: Sept 23, 2022
CS271 Fall 2022
*/

#include <iostream>
using namespace std;
#include "minqueue.cpp"

//Pre-condition: an array of size len exists with a required window
template <typename T>
string sliding_window(T arr[], int len, int window){

    MinQueue<int> heap; //stores the elements as a minimum priority queue
    MinQueue<int> heap2; //keeps the elements to be extracted from the heap after the window moves right
    int minValue; //stores the minimun
    
    string str = ""; // stores the list of minimum values as a string

    if(len == 0){
        return str; // returns empty string
    }

    if(window > len){ // validates window
        return str;
    }
    
    for(int i = 0; i < window; i++){
        heap.insert(arr[i]); // pushes the elements into the minimum priority queue
    }

    minValue = heap.min(); //stores minimum value in the current window of heap

    stringstream ss;
    ss << minValue; // convert int value of minValue to a string
    str = str + ss.str(); 
   
    for(int i = window; i < len; i++){ //push the rest elements into the minimum priority queue
    
        if(arr[i-window] == heap.min()){ //extract the leftmost element from the queue if it was the minimum
            heap.extract_min();
        }else{
            heap2.insert(arr[i-window]); //insert the leftmost element into the 2nd heap
        }   

        while (heap2.getSize()!= 0 && heap2.min() == heap.min()) //extract elements from the two heaps until the minimum value are equal
        {
            heap.extract_min();
            heap2.extract_min();
        }

        heap.insert(arr[i]); //push element into the queue
        minValue = heap.min(); //stores minimum value in the current window of heap
       
        stringstream ss;
        ss << minValue; // convert int value of minValue to a string
        str = str + " "; // add a space between the values
        str = str + ss.str();
        
    }

    return str;

}

//Post-condition: A string with the mininum values for the windows in the array is returned