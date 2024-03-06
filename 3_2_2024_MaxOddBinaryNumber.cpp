/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

Beats 59.33% of C++ users Runtime
Beats 77.05% of C++ users Memory
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int numOnes = 0;
        string binaryOfString = "";
        int length = s.length();
        
        for(int i = 0; i < length; i++){
            if (s[i] == '1')
                numOnes++;
        }
        for(int i = 0; i < numOnes-1; i++){
            binaryOfString += '1';
        }
        for(int i = 0; i < length - numOnes; i++){
            binaryOfString += '0';
        }
        binaryOfString += '1';
        return binaryOfString;
    }

};
