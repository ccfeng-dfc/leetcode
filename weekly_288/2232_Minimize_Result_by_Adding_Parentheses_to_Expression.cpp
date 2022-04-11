// https://leetcode.com/contest/weekly-contest-288/problems/minimize-result-by-adding-parentheses-to-expression/
// https://youtu.be/f10jW1ZbPNc BY "Bro Coders"

class Solution {
public:
    string minimizeResult(string expression) {
        // 1. declare
        int ans = INT_MAX, plus;
        string get;
        
        // 2. whereis the '+' sign
        for (int i = 0; i < expression.size(); i++){
            if (expression[i] == '+'){
                plus = i;
                break;
            }
        }
        
        // 3. check ans
        for (int i = 0; i < plus; i++){
            // 3-1 left
            int left = 0;
            for (int j = 0; j < i; j++){
                left = (left * 10) + (expression[j] - '0');
            }
            if (left == 0){
                left = 1;
            }
            
            // 3-2 right
            for (int rt = expression.size() - 1; rt > plus; rt--){
                int right = 0;
                for (int j = rt + 1; j < expression.size(); j++){
                    right = (right * 10) + (expression[j] - '0');
                }
                if (right == 0){
                    right = 1;
                }
                
                // 3-3 midleft and midright
                int midleft = 0, midright = 0;
                for (int j = i; j < plus; j++){
                    midleft = (midleft * 10) + (expression[j] - '0');
                }
                for (int j = plus + 1; j <= rt; j++){
                    midright = (midright * 10) + (expression[j] - '0');
                }
                    // =========================
                int value = left * (midleft + midright) * right;
                    // =========================
                if (value < ans){
                    string str = expression;
                    str.insert(str.begin() + i, '(');
                    str.insert(str.begin() + rt + 2, ')');
                    get = str;
                    ans = value;
                }
            }
        }
        return get;
    }
};