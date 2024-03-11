/*
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).

Beats 90.48% C++ in runtime
Beasts 13.27% in memory
 */


class Solution {
public:
    int minimumLength(string s) {
        char letter;
        int beginIndex = 0;
        int endIndex = s.size() - 1;
        bool removing = true;

        while(removing){
            letter = s[beginIndex];
            if(letter == s[endIndex]){
                if(beginIndex == endIndex){
                    removing = false;
                    break;
                }
                while(letter == s[beginIndex] && beginIndex <= endIndex)
                    beginIndex++;
                while(letter == s[endIndex] && endIndex >= beginIndex)
                    endIndex--;
            }else{
                removing = false;
            }
        }
        return endIndex - beginIndex + 1;
    }
};
