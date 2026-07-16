class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int last = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (last >= n - 1) return count;
            int val = 0;
            while (i < n && i <= last) {
                val = max(val, i + nums[i]);
                i++;
            }
            last = val;
            count++;
            i--;
        }
        return count;
    }
};