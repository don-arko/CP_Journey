//https://codeforces.com/contest/1097/problem/B

/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


/*-------------------------------------------------------------------------------------------------*/
/*
Editorial: 

The best way to check the condition in the statement is to use bitmasks. Iterate from 0 to 2n−1 and for 
each number consider its binary representation. If the i-th bit of the representation is set to 0, then 
decide to perform the i-th rotation clockwise. In the opposite case, do it counterclockwise. Finally, check 
if the whole angle is a multiple of 360 and if so, output "YES". If no good combination of rotations was found, output "NO".


*/



const int N = 200005;


void solve() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
// basically we have n slots/bits, each time we have two ways either to rotate clockwise or anticlockwise.
    //0-clockwise (-)
    //1-anticlowise (+)
    //generating all combination of cw/acw rotations for the n rotations available.
    //n max = 15 so total of 2^15 combinations are there 
    for(int mask=0;mask<(1<<n);mask++){
        //cout<<"Mask : "<<mask<<" - ";
        int sum=0;
        for(int i=0;i<n;i++){
            if((mask>>i)&1){
                //cout<<1<<" ";
                sum+=a[i]; //adding the counterclockwise angles
            }
            else{
                //cout<<0<<" ";
                sum-=a[i];  //substracting the clockwise angles.
            }
        }
        sum%=360;  //if the addition of three angles is 360 then it is actually 0 degree
        if(!sum){ //when sum=0
            cout<<"YES\n";
            return;
        }
        //cout<<endl;
    }
    cout<<"NO\n";

}





/*-------------------------------------------------------------------------------------------------*/



int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

/*-------------------------------------------------------------------------------------------------*/


    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
