/*
Implement function
int findMax(int* arr, int length){}
to find the largest element using recursion (with length is the number of elements in integer array arr).
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;

For example:

Test	                                                    Result
int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};             15
cout << findMax(arr, 10);
*/

#include <iostream>
using namespace std;

int findMaxHelper(int* arr, int length, int index) {
    if (index == length - 1) {
        return arr[index];
    }
    
    int maxOfRest = findMaxHelper(arr, length, index + 1);
    
    return (arr[index] > maxOfRest) ? arr[index] : maxOfRest;
}

int findMax(int* arr, int length) {
    return findMaxHelper(arr, length, 0);
}

int main() {
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(arr, 10);
    return 0;
}