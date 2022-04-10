// https://leetcode.com/contest/weekly-contest-288/problems/largest-number-after-digit-swaps-by-parity/

class Solution {
public:
    int largestInteger(int num) {
        // 1. declare
        string str = to_string(num), ans;
        vector<char> odd, even;
        
        // 2. Vector.push_back()
        for (int i = 0; i < str.size(); i++){
            if ((str[i] - '0') % 2 == 1){
                odd.push_back(str[i]);
            } else {
                even.push_back(str[i]);
            }
        }
        
        // 3. sort and reverse
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        reverse(even.begin(), even.end());
        
        // 4. to ans
        int x = 0, y = 0;
        for (int z = 0; z < str.size(); z++){
            if((str[z] - '0') % 2){
                ans += odd[x++];
            } else {
                ans += even[y++];
            }
        }
        
        // 5. stoi()
        return stoi(ans);
    }
};