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
Editorial:- 

Here we will use binary search on the answer. Let's we check the current answer equals to cur. 
Then the objective function must be realized in the following way. Let's store in the variable
cnt how many grams of the magic powder we need to bake cur cookies. Let's iterate through the 
ingredients and the current ingredient has the number i. Then if a[i]·cur > b[i] let's make 
cnt = cnt + a[i]·cur - b[i]. If after looking on some ingredient cnt becomes more than k the 
objective function must return false. If there is no such an ingredient the objective function must return true.
If the objective function returned true we need to move the left end of the binary search to the cur,
else we need to move the right end of the binary search to the cur.




Did the Implementation and check function on my own after reading the editorial  of the easier version.
Bs on ans : we will try to give an random ans x i.e. if we could make x cookies or not and we need to maximise x.
The good function returns good - 1 if we could make atleast x nos of cookies or else false
Monotonocity if f(x)-true then f(x-1) - true i.e. if we could make x no. of cookies we can always make x-1 no. of cookies cause kam ingredient chahiye hoga .

TTTTTTTTTTTFFFFFFFFFFFFFFFF
---------------------------->x

we are looking for the last T

*/
const int N = 200005;
int n,k;
vi req,have;
bool good(int x){
    //Will see if I could make atleast x cookies or not i.e. if each of the n ingredient is atleast avaible for x cookies
    int val=0;
    for(int i=0;i<n;i++){
        
        if(x*req[i]>have[i]){   //ingre req for  x cookies = req[i]*x
            val+=(x*req[i]-have[i]);
            if(val>k){
                return false; //we cant do this at the end cause val becomes too big and we shall face single integer overflow error
            }
        }
    }
    // here val is the total grams req of magic powder for x cookies bakement
    return true;    //val<=k
}
void solve() {
    cin>>n>>k;
    //bug(n,k);
    req.resize(n);
    have.resize(n);
    for(int i=0;i<n;i++) cin>>req[i];
    for(int i=0;i<n;i++) cin>>have[i];

    int l=0; //f(l=0) is always good   //f(l)-good
    int r=2e9+1;   //f(r==2e9+1) is always bad  //f(r)-bad
    //because if all req[i]=1 and all have[i]=10^9  and k is max = 10^9 then under most optimistic situation we could make 10^9 cookies (without magic powder ) and another 10^9 cookies from 10^9 magic power as all req[i]= 1 so atmost cookies we can make is 2*10^9 cookies then we cant make 2*10^9+1 cookies and hence f(r=2e9+1) is always bad
    while(l+1<r){

        int m=(l+r)/2;
        //bug(m);
        if(good(m)){
            l=m;
        }
        else{
            r=m;
        }
    }
    //the final ans is stored in l as the invariant has equality
    cout<<l<<endl;
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
