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
USACO EDITORIAL

In this problem, we're asked to divide an array into k subarrays such that the
maximum sum of a subarray is minimized.

Let's begin by making an important observation. First of all, if you can divide
an array such that the maximum sum is at most x, you can also divide the array
such that the maximum sum is at most y > x with the same division (Bade by swapping elements btw the subarrays keeping no. of divisions constant). (MONOTONOCITY)

Now, given some maximum sum x, we can check whether a division is possible
using a greedy algorithm. If we can divide the array into s < k subarrays,
then we can divide it into k subarrays without increasing the maximum sum (aur divisions barayenge to reach  toh max sum aur kamte rahega) of a
subarray. Therefore, we can greedily create subarrays as long as the sum of the
subarray does not exceed x, and check if the number of subarrays is <=k.




Let X be the maximum sum , i.e. the max sum of any sub array is atmost x , following this constraint if I could 
divide the array into divisions = atmost k  then,x is a good number, otherwise x is a bad number.

f(x)={
    x-good , if i could divide the array into divisions maintaining max sum<=x (atmost x) and divisions atmost k 
    x-bad, if divisions >k
}

MONOTONOCITY:- f(x)-good => f(x+1)-good ; because max sum barana (x+1) matlab ek subarray me members barana matlab divisions kamana so division now will be further less than k 

when the x is very less the nos of element in each element has to be very less => larger division 
so as x increases after some some point divisions decreases and comes below k fetching true.
fffffffftttttttttttttttt
------------------------->x
*/

int n,k;
vi a;


const int N = 200005;
bool good(int x){
    int divisions=1; //initially the entire array is one subarray hence divisions =1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>x) return false; // if at any single element >x i cant never attain the max sum of subarray <=x
        
        //now as we consider more and more elements in the subarray size sum  of subarray increases (we should maintain sum<=x) then division is likely to decrease so as to bring it beneath k 
        //trying to decrease the divisions which will eventually increse the size of the subarray and hence its sum but we should maintain sum<=x

        if(sum+a[i]<=x){
            sum+=a[i];
        }
        else{ //sum+a[i]>x cant increase the subarray further as it will violate max sum<=x
            divisions++;//new subarray has to be started.
            sum=a[i]; // now a subarray is starting from this element and mind a[i] is never > x cause we have already checked that earlier so we can safely put sum = a[i] and we know sum<=x;
        }
    }
    return divisions<=k;
}

void solve() {
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int l=0;    //f(l)= bad; x should be such that f(l)is always bad => when sum is atmost x no. of division should be atleast greater than kmax=n, when x=1, a[i]min=1, no. of divisions = n, each subarray has one element which is minimum then divisions=n which is >=kmax=n
    //if I take x=0 divisions shall further increase making it more that kmax=n so that  f(l=0) is always bad
    int r=2e14+1;    //f(r)=good; x should be such that f(r) is always good => when the sum is atmost x no, of divisions atmost k, kmin = 1 i.e. divisions should be <=1 => sub array = entire array of n elements , and their sum is sum of the array = nmax*a[i]max=2*10^5* 10^9=2*10^14 so if x>2*10^9 then division is <= 1 and f(x) is always good 
    while(l+1<r){
        int m=(l+r)/2;
        if(good(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    cout<<r<<endl;
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
