
// Memoization  (top-down)
// Time Complexity ->  O(N)
// space Complexity -> O(N)

#include<bits/stdc++.h>
int canJump(int i, vector<int>& heights, vector<int>& dp)
{
    int right = INT_MAX;
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int left = canJump(i-1, heights, dp) + abs(heights[i]-heights[i-1]);
    if(i>1)right = canJump(i-2, heights, dp) + abs(heights[i]-heights[i-2]);
    return dp[i] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
    return canJump(n-1, heights, dp);
}


//Tabulation  (bottom-up)
// space optimization technique
// Time complexity -> O(N)
// Space complexity -> O(3)~ O(1) // constant space

#include <bits/stdc++.h>
int canJump(int i, vector<int>& heights)
{
    int prev = 0, prev2 = 0;
    for(int i = 1 ; i < n ; i++)
    {
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = prev2 + abs(heights[i]-heights[i-2]);
        int cur = min(fs, ss);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}