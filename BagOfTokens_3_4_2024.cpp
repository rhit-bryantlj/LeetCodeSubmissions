/*
You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.

Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
Return the maximum possible score you can achieve after playing any number of tokens.

Beats 75.04% of users with C++ in memory
Beats 17.81% users with C++ in runtime 
- poor runtime, good memory usage
  */



class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size() == 0)
            return 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int maxTokenIndex = tokens.size()-1;
        int minTokenIndex = 0;
        bool playable = true;

        while(playable){
            if(power >= tokens[minTokenIndex]){
                power -= tokens[minTokenIndex];
                score++;
                minTokenIndex++;
                if(minTokenIndex == tokens.size())
                    return score;
            } else{
                if(minTokenIndex < maxTokenIndex && score > 0){
                    score--;
                    power += tokens[maxTokenIndex];
                    maxTokenIndex--;
                }else{
                    playable = false;
                }
            }
        }
        return score;
    }
};
