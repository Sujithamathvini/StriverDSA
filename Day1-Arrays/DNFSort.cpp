//problem link - https://leetcode.com/problems/sort-colors/
//Approach1 - sorting
//Approach2 - count 0,1,2

//Approach3 - 3 pointer
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int l=0,m=0,h=n-1;
    while(m<=h){
        switch(arr[m]){
                case 0:
                    swap(arr[l++],arr[m++]);
                    break;
                case 1:
                    m++;
                    break;
                case 2:
                    swap(arr[m],arr[h--]);
                    break;
        }
    }
}
//Time complexity - O(n)
//Space Complexity - O(1)
