
//https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        long long l=-1;//a[l]<=x
        long long r=n; //a[r]>x
        while(l+1<r){
            long long m=(l+r)/2;
            if(v[m]<=x){
                l=m;
            }
            else{
                r=m;
            }
        }
        
        return int(l);
    }
};
