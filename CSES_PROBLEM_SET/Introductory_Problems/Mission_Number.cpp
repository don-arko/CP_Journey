#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(){
    long long n ;
    vector<long long> v;
    cin>>n;
 
    for(long long i=1; i<=n-1;i++){
        long long temp;
        cin>>temp;
 
        v.push_back(temp);
    }
 
    sort(v.begin(),v.end());
    /*
    //printing the sorted vector
    cout<<endl;
    for(long long i=0;i<=n-2;i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n\n";
 
    */
 
   
    int ans=0;
    for(long long i=0;i<=n-2;i++){
        if(v[i] != i+1){
            ans=i+1;
            break;
        }
    }
    //if we are coming out of this for loop that means  all  n-1 elements (from 1 to n-1 )are properly placed at their correct indices hence no mismatched has occured and since we know exactly one elements is missing so we know the nth element is missing since we found no mismatch till n-1
    //coming out of this for means either ans is 0(if never updated) or something else
 
    if(ans==0){
        ans=n;
    }
 
    cout<<ans;
    
    
    
}
