
//neatest
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last = upper_bound(nums.begin(),nums.end(),target)-nums.begin() - 1;
        if(first == nums.size() || nums[first] != target)
        {
            return {-1,-1};
        }
        return {first,last};
    }
};


//or
//using functions lower_bound and upper_bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first=lower_bound(nums.begin(),nums.end(),target);//>=x ,first points to the first apperrance of x
        auto last=upper_bound(nums.begin(),nums.end(),target); //>x, last points to the element after the last appearance of x
        vector<int> ans(2);
        //mind two times bs apply krni e padegi koi bhi case me ek set of l and r first and last appearance nei de sakta
        if(first==nums.end() or *first!=target){ //x is absent 
            ans[0]=ans[1]=-1;
            return ans;
        }

        last--; //points to last x 

        //first present => atleast one x present =>  last also has to be present so we are sure last-- points correctly

        //iterator to index conversion 
        int last_idx=last-nums.begin();
        int first_idx=first-nums.begin();  //using iterator arithematic.
        cout<<last_idx;

        ans[0]=first_idx;
        ans[1]=last_idx;
        return ans;


    }
};

//bs from scratch without using functions
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=-1;          //a[l]<=x at the end if x is present it will be in x (the last one)
        int r=nums.size(); //a[r]>x
        while(l+1<r){
            int m=(l+r)/2;
            if(nums[m]<=target){
                l=m;
            }
            else{
                r=m;
            }
        }
        vector<int> ans(2);
        cout<<l;
        //l returns the index to the last x (a[l]<=x)
        if(l==-1 or nums[l]!=target){ // x is absent in the array
            ans[0]=ans[1]=-1;
            return ans;
        }

        int l1=-1;          //a[l1]<x 
        int r1=nums.size(); //a[r1]=>x at the end if x is present it will be in r1 (the first x)
        while(l1+1<r1){
            int m=(l1+r1)/2;
            if(nums[m]<target){
                l1=m;
            }
            else{
                r1=m;
            }
        }
        cout<<r1;
        //l exists => r1 exists cause ek x hai to first bhi wai last bhi wai
        ans[0]=r1;
        ans[1]=l;




        
        return ans;
        
    }
};
