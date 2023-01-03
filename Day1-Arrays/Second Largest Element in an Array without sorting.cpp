/*

Find Second Smallest and Second Largest Element in an array
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples:

Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.

*/

/** APPROACHES 

Solution 1: (Brute Force) [this approach only works if there are no duplicates]

Intuition: What do we do to find the largest or the smallest element present in an array? We ideally sort them and the first element would be the smallest of all while the last element would be the largest. Can we find the second smallest and second-largest using a similar approach?

Approach:
Sort the array in ascending order
The element present at the second index is the second smallest element
The element present at the second index from the end is the second largest element
Code:

#include<bits/stdc++.h>
using namespace std;
void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    sort(arr,arr+n);
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}
int main()
{
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}
Output:

Second smallest is 2
Second largest is 6

Time Complexity: O(NlogN), For sorting the array

Space Complexity: O(1)

Solution 2(Better Solution)
Intuition: Even though we want to have just the second smallest and largest elements, we are still sorting the entire array for that and thus increasing the time complexity. Can we somehow try to not sort the array and still get our answer?

Approach:
Find the smallest and largest element in the array in a single traversal
After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
Similarly, we would find the largest element which is just smaller than the largest element we just found
Indeed, this is our second smallest and second largest element.
Code:


    #include<bits/stdc++.h>
using namespace std;
void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }

    cout<<"Second smallest is "<<second_small<<endl;
    cout<<"Second largest is "<<second_large<<endl;
}
int main()
{
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}
Output:

Second smallest is 2
Second largest is 6

Time Complexity: O(N), We do two linear traversals in our array

Space Complexity: O(1)

Solution 3(Best Solution)
Intuition: In the previous solution, even though we were able to bring down the time complexity to O(N), we still needed to do two traversals to find our answer. Can we do this in a single traversal by using smart comparisons on the go?

Approach:
We would require four variable : small,second_small,large,second_large. Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

Second Smallest Algo:

If the current element is smaller than ‘small’, then we update second_small and small variables
Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
Once we traverse the entire array, we would find the second smallest element in the variable second_small.
Here’s a quick demonstration of the same.
Second Largest Algo:

If the current element is larger than ‘large’ then update second_large and large variables
Else if the current element is larger than ‘second_large’ then we update the variable second_large.
Once we traverse the entire array, we would find the second largest element in the variable second_large.
Here’s a quick demonstration of the same.
Code:

#include<bits/stdc++.h>
using namespace std;
int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
        int sS=secondSmallest(arr,n);
        int sL=secondLargest(arr,n);
    cout<<"Second smallest is "<<sS<<endl;
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}

Output:

Second smallest is 2
Second largest is 5

Time Complexity: O(N), Single-pass solution

Space Complexity: O(1)

**/

// my code 

#include<bits/stdc++.h>
using namespace std;
int secondLargest(int a[], int n) {
    // my code
    if (n<2)
    return
    int max=-1;
    int secondmax=-1;
    for(int i=0;i<n;i++){
        // this is for finding maximum num
        if(a[i]>max){
            secondmax=max;
            max=a[i];
        }

        // else no num is greater than max then find the secondmax
        else if(a[i]>secondmax && a[i]!=max){
            secondmax=a[i];
        }
    }
    return secondmax;
}


int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
        int sL=secondLargest(arr,n);
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}
