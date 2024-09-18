#include<iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long count=1;
    long long max_count=0;
    for(long long i=0; i<s.size();i++){
        count=1;
        if(i<=s.size()-2){               
            while(s[i]==s[i+1]){        //for this comparison to reamin valid there should always be element on rhs and hence putting a limit on i
                count++;
                i++;        //updating i for the next iteration of for 
            }
        }
        else{// when i is on the last element then we dont need to check we already count value of count is 1 which is also is deafult value 
 
        }
        
        //cout<<"current count is "<<count<<endl;
        if(count>max_count){
            max_count=count;
        }
    //due to i++ withing the for i is updated again keep in mind 
    }
    cout<<max_count;
 
}
