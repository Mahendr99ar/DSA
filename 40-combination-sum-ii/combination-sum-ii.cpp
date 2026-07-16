class Solution {
public:

    void findCombination(int ind , int target , vector<int>&arr , vector<int>&ds , vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(ind == arr.size()){
            return;
        }
        if(arr[ind]>target){
            return;
        }
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind+1,target-arr[ind],arr,ds,ans);
            ds.pop_back();
        }
        while(ind+1<arr.size() && arr[ind]==arr[ind+1]){
            ind++;
        }
        findCombination(ind+1,target,arr,ds,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates , ds , ans);
        return ans;
    }
};