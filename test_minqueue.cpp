/* 
Author: Ichhit Joshi, Nam Ngo
Date: Sept 23, 2022
CS271 Fall 2022
*/

#include <iostream>
#include "minqueue.cpp"
#include "usecase.cpp"

using namespace std;


void test_insert() {
    try {
        //int test
        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();
        if(mq_str != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++) {
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();
        if(mq_str != "0 2 1 3 6 4 8 10 7 9 25 5") {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }

        //float test
        MinQueue<float> e;
        e.insert(0.5);
        string mq1_str = e.to_string();
        if(mq1_str != "0.5") {
            cout << "Incorrect insert result. Expected 0.5 but got : " << mq1_str << endl;
        }
        float* float_data = new float[10];
        for(int i = 0; i < 10; i++) {
            float_data[i] = 10-i+0.5;
        }
        MinQueue<float> mq1(float_data, 10);
        mq1.insert(25.5);
        mq1.insert(0.5);
        mq1_str = mq1.to_string();
        if(mq1_str != "0.5 2.5 1.5 3.5 6.5 4.5 8.5 10.5 7.5 9.5 25.5 5.5") {
            cout << "Incorrect insert result. Expected 0.5 2.5 1.5 3.5 6.5 4.5 8.5 10.5 7.5 9.5 25.5 5.5 but got : " << mq1_str << endl;
        }

        //char test
        MinQueue<char> e1;
        e1.insert('a');
        string mq2_str = e1.to_string();
        if(mq2_str != "a") {
            cout << "Incorrect insert result. Expected a but got : " << mq2_str << endl;
        }
        char* char_data = new char[3];
        char arr1[] = {'a', 'b', 'c'};
        for(int i = 0; i < 3; i++) {
            char_data[i] = arr1[i];
        }
        MinQueue<char> mq2(char_data, 3);
        mq2.insert('d');
        mq2_str = mq2.to_string();
        if(mq2_str != "a b c d") {
            cout << "Incorrect insert result. Expected a b c d but got : " << mq2_str << endl;
        }

        //string test
        MinQueue<string> e2;
        e2.insert("aa");
        string mq3_str = e2.to_string();
        if(mq3_str != "aa") {
            cout << "Incorrect insert result. Expected aa but got : " << mq3_str << endl;
        }

        string* string_data = new string[3];
        string arr2[] = {"aa", "ba", "ca"};
        for(int i = 0; i < 3; i++) {
            string_data[i] = arr2[i];
        }
        MinQueue<string> mq3(string_data, 3);
        mq3.insert("da");
        mq3_str = mq3.to_string();
        if(mq3_str != "aa ba ca da") {
            cout << "Incorrect insert result. Expected aa ba ca da but got : " << mq3_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }
}

void test_min() {
    try {
        //int test
        MinQueue<int> empty;
        int min = empty.min();
        if(min != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if(min != 1) {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        //float test
        MinQueue<float> empty1;
        float min1 = empty1.min();
        if(min1 != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min1 << endl;
        }
        float* float_data = new float[10];
        for(int i = 0; i < 10; i++){
            float_data[i] = 10-i+0.5;
        }
        MinQueue<float> mq1(float_data, 10);
        min1 = mq1.min();
        if(min1 != 1.5) {
            cout << "Incorrect min result. Expect 0 but got : " << min1 << endl;
        }

        //char test
        MinQueue<char> empty2;
        char min2 = empty2.min();
        if(min2 != 0) {
            cout << "Incorrect min result. Expect 0 but got : " << min2 << endl;
        }
        char* char_data = new char[3];
        char arr1[] = {'a', 'b', 'c'};
        for(int i = 0; i < 3; i++){
            char_data[i] = arr1[i];
        }
        MinQueue<char> mq2(char_data, 3);
        min2 = mq2.min();
        if(min2 != 'a') {
            cout << "Incorrect min result. Expect a but got : " << min2 << endl;
        }

        //string test
        string* string_data = new string[3];
        string arr2[] = {"aa","ba","ca"};
        for(int i = 0; i < 3; i++){
            string_data[i] = arr2[i];
        }
        MinQueue<string> mq3(string_data, 3);
        string min3 = mq3.min();
        if(min3 != "aa") {
            cout << "Incorrect min result. Expect aa but got : " << min3 << endl;
        }


    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
}

void test_extract_min() {
    try {
        //int test
        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();
        if(min != 0 || mq_str != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();
        if(min != 1 || mq_str != "2 3 4 7 6 5 8 10 9") {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }

        //float test
        MinQueue<float> empty1;
        float min1 = empty1.extract_min();
        string mq_str1 = empty1.to_string();
        if(min1 != 0 || mq_str1 != "") {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min1 << " and a queue of : " << mq_str1 << endl;
        }
        float* float_data = new float[10];
        for(int i = 0; i < 10; i++){
            float_data[i] = 10-i+0.5;
        }
        MinQueue<float> mq1(float_data, 10);
        min1 = mq1.extract_min();
        mq_str1 = mq1.to_string();
        if(min1 != 1.5 || mq_str1 != "2.5 3.5 4.5 7.5 6.5 5.5 8.5 10.5 9.5") {
            cout << "Incorrect extract min result. Expected 0 and the queue  2.5 3.5 4.5 7.5 6.5 5.5 8.5 10.5 9.5 but got : " << min1 << " and a queue of : " << mq_str1 << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }
}

void test_decrease_key() {
    try {
        //int test
        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();
        if (mq_str != "") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }
        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();
        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        //float test
        MinQueue<float> empty1;
        empty1.decrease_key(0, 0);
        string mq_str1 = empty1.to_string();
        if (mq_str1 != "") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str1 << endl;
        }
        float* float_data = new float[10];
        for(int i = 0; i < 10; i++){
            float_data[i] = 10-i+0.5;
        }
        MinQueue<float> mq1(float_data, 10);
        mq1.decrease_key(0, -6);
        mq1.decrease_key(9, -1);
        mq_str1 = mq1.to_string();
        if (mq_str1 != "-6 -1 4.5 3.5 2.5 5.5 8.5 10.5 7.5 6.5") {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str1 << endl;
        }
    } catch (exception &e) {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }
}

void test_heapsort() {
    try {
        //int test
        MinQueue<int> empty;
        int* empty_data = new int[0];
        empty.sort(empty_data);

        int* int_data = new int[10];
        for(int i = 0; i < 10; i++){
            int_data[i] = 10-i;
        }
        MinQueue<int> heap(int_data, 10);
        
        heap.sort(int_data);
        string sorted_str = to_string(int_data[0]);
        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }
        if(sorted_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }

        //float test
        MinQueue<float> empty1;
        float* empty_data1 = new float[0];
        empty1.sort(empty_data1);
        float* float_data = new float[10];
        for(int i = 0; i < 10; i++){
            float_data[i] = 10-i+0.5;
        }
        MinQueue<float> heap1(float_data, 10);
        heap1.sort(float_data);
        string sorted_str1 = to_string(float_data[0]);
        for(int i = 1; i < 10; i++) {
            sorted_str1 += (" " + to_string(float_data[i]));
        }
        if(sorted_str1 != "1.500000 2.500000 3.500000 4.500000 5.500000 6.500000 7.500000 8.500000 9.500000 10.500000") {
            cout << "Incorrect heapsort result. Expected 1.500000 2.500000 3.500000 4.500000 5.500000 6.500000 7.500000 8.500000 9.500000 10.500000 but got : " << sorted_str1 << endl;
        } 

        //string test
        MinQueue<string> empty3;
        string* empty_data3 = new string[0];
        empty3.sort(empty_data3);
        string* string_data = new string[3];
        string arr3[] = {"cc", "bb", "aa"};
        for(int i = 0; i < 3; i++){
            string_data[i] = arr3[i];
        }
        MinQueue<string> heap3(string_data, 3);
        heap3.sort(string_data);
        string sorted_str3 = string_data[0];
        for(int i = 1; i < 3; i++) {
            sorted_str3 += (" " + string_data[i]);
        }
        if(sorted_str3 != "aa bb cc") {
            cout << "Incorrect heapsort result. Expected aa bb cc but got : " << sorted_str3 << endl;
        }

    } catch (exception& e) {
        cerr << "Error in sorting : " << e.what() << endl;
    }
}

int main() {
    
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapsort();
    
    cout << "Testing completed" << endl;
    
    return 0;
}
