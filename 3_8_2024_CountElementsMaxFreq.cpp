/*
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

Beats 40% of users with C++: Runtime
Beats 59.87% of users wtih C+: Memory
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freqOfNums = 0;
        int highestfreq = 1;
        map<int,int> freqmap; 

        for(int i = 0; i < nums.size(); i++) {
            if(freqmap[nums[i]] != 0){
                freqmap[nums[i]] = freqmap[nums[i]] + 1;
                if(freqmap[nums[i]] > highestfreq)
                    highestfreq = freqmap[nums[i]];
            }
            else
                freqmap[nums[i]] = 1;
        }
        // Get an iterator pointing to the first element in the
        // map
        map<int, int>::iterator it = freqmap.begin();
        while(it != freqmap.end()){
            if(it->second == highestfreq)
                freqOfNums += highestfreq;
            ++it;
        }
        return freqOfNums;
    }
};
