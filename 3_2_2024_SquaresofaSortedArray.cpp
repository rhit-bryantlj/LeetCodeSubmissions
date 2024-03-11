/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Beats 55.98% of users wtih C++ Runtime
Beats 29.56% of users with C++ Memory
  */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sortedVect(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int square = nums[i] * nums[i];
            sortedVect[i] = square;
        }
        sort(sortedVect.begin(), sortedVect.end());

        return sortedVect;
    }
};
