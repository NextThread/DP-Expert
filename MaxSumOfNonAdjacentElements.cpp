//memoization approach
// time complexity ->  O(N)
// space complexity ->  O(N)

int helper(int ind, vector<int>& nums, vector<int>& dp)
{
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + helper(ind-2 , nums, dp);
    int notpick = 0 + helper(ind-1, nums, dp);
    return dp[ind] = max(pick ,notpick);
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size()+1, -1);
    return helper(nums.size()-1, nums, dp);
}



// tabulation approach
//time conplexity -> O(N)
//space complexity -> O(1) // constant space

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1 ; i < nums.size() ; i++)
    {
        int pick = nums[i];
        if(i > 1) pick += prev2;
        int dontpick = 0+prev;
        int curr = max(pick ,dontpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}