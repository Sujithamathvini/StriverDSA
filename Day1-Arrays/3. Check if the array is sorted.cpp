/*

Check if an Array is Sorted
Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.

Examples:

Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.


Example 2:
Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.

Here element 5 is not smaller than or equal to its future elements.

*/

#include<bits/stdc++.h>
using namespace std;
bool arraySortedOrNot(int a[], int n) {
    // code here
    // 1st attept - brute force approach
    // problem with this code is size and j=i+1, 
    // if n=5(odd) --> i=4, j=4+1=5 --> this is right but,
    // if n=8(even) --> i=8, j=8+1=9 --> this leads to outofboundError
    // for(int i=0;i<n;i++){
    //     int j=i+1;
    //     if(a[i]==a[j]){
    //         continue;
    //     }
    //     else if(a[i]>a[j]){
    //         return 0;
    //     }
    // }
    // return 1;

    // 2nd attempt - comparing using previous element
    for(int i=1;i<n;i++){
        int j=i-1;
        if(a[i]==a[j]){
            continue;
        }
        else if(a[j]>a[i]){
            return 0;
        }
    }
    return 1;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5}, n = 5;
  printf("%s", isSorted(arr, n) ? "True" : "False");
}
