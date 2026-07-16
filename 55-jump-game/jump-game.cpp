class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true; 
        }
        if(nums[0]==0){
            return false;
        }
        int maxm=nums[0];
        for(int i=1;i<nums.size();++i){
            if(i<=maxm){
                maxm=max(maxm,i+nums[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};



