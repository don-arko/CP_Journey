
//https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=-1;   //nums[l]<=target
        int r=nums.size();//nums[r]>target
        while(l+1<r){
            int m=l+(r-l)/2;
            if(nums[m]<=target){
                l=m;
            }
            else{
                r=m;
            }
        }
        //if x<nums[0], l=-1 and the following if block should not get executed.
        //I should take care that i dont access nums[-1]
        if(l!=-1 and nums[l]!=target){ //we should not do this check with l=-1 which is the case when all elements greater than x because that would lead to accessing -1 in the array, that is why additionally l!=-1 check is putted
            l=-1;
        }
        return l;
    }
};
