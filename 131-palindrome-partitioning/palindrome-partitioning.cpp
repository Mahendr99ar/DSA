class Solution {
public:
    bool isPalindrome(const string& s){
        int n = s.size();
        if(n <= 1) return true;
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void backtrack(int idx, vector<string>& cur, vector<vector<string>>& ans, string& s){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            string temp = s.substr(idx, i - idx + 1);
            if(isPalindrome(temp)){
                cur.push_back(temp);
                backtrack(i + 1, cur, ans, s);
                cur.pop_back(); 
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(0, cur, ans, s);
        return ans;
    }
};