/*
Maximum Subarray Sum
problem link - https://leetcode.com/problems/maximum-subarray/

Approach1 - three loop //Time complexity - O(n^3) , Space complexity - O(1)
Approach2 - two loop //Time complexity - O(n^2) , Space complexity - O(1)

Approach3 - Kadane's Algo 
Time complexity - O(n)
Space complexity - O(1)
*/

int maxSubArray(vector<int>& nums) {
        //Kadane's algo
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum,maxi);//gives the maximum of maxi and current sum
            /*if(sum>maxi){
            maxi=sum;
            }
            */
            if(sum<0)
                sum=0;
        }
        return maxi;
}
