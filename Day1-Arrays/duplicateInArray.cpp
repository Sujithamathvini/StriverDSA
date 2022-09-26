/*
problem link - https://leetcode.com/problems/find-the-duplicate-number/

Approach1 - Sorting //time complexity - O(nlogn + n) , space complexity - O(1)
Approach2 - using freq array //time complexity - O(n) , space complexity - O(n)

Approach3 - Floyd Warshall Algo
time complexity - O(n)
space complexity - O(1)
*/

int findDuplicate(vector<int> &a, int n){
int s=a[0];
    int f=a[0];
    do{
        s=a[s];//one step
        f=a[a[f]];//two steps
    }while(s!=f);//until the collision point is found
    f=a[0];//when s==f then initialize f to a[0]
    while(s!=f){
        s=a[s];
        f=a[f];
    }
    return f;//when the s and f meet eachother that number is the duplicate number
}
