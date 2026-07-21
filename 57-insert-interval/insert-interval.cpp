class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& a) {
        vector<vector<int>> r;
        int i = 0;
        int n = v.size();
        while (i < n && v[i][1] < a[0]) {
            r.push_back(v[i]);
            i++;
        }
        while (i < n && v[i][0] <= a[1]) {
            a[0] = min(a[0], v[i][0]);
            a[1] = max(a[1], v[i][1]);
            i++;
        }
        r.push_back(a);
        while (i < n) {
            r.push_back(v[i]);
            i++;
        }
        return r;
    }
};