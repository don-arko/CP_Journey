/*

EDITORIAL USACO GUIDE 

To get the current median, we first sort the array in ascending order.

Now, notice that to increase the current value to a value, say $x$.
All values currently greater than or equal to the median, must remain greater than or equal to the median.

For example, say we have the sorted array
$[1,1,2,3,4,4,5,5,6,8,8]$. The current median is x, so to increase the median to $6$, we have to increase the current median by $2$ and we also have to increase the $5$'s to $6$.

Following this idea, to increase the median to x, we need to increase all values in the second half of the array to some value greater than or equal to x.

Then, we binary search for the maximum possible median. We know that the number of operations required to raise
the median to x increases monotonically as x increases, so we can use binary
search. For a given median value $x$, the number of operations required to raise
the median to x is

= i=(n+1/2)-> n ∑ max(0,x-arr[i])

If this value is less than or equal to x, then x can be the median, so our
check function returns true. Otherwise, x cannot be the median, so our check
function returns false.


My idea is more or less the same (slowly slowly me bhi editorial jaisa e sochne lagg gya hun mere bhai...)
- Yeah to increase the median to a value x you have to make sure all the elements to the right of the median should be atleast x 
- In one step we could increase only by 1 value so to total no of min_ops req is i=(n+1/2)-> n ∑ max(0,x-arr[i]) {when the elements is greater than x then ops req is 0}
- Yeah here x is the random input for ans 
- x is good if we can increase the median to x and the no of ops req in doing so is atmost x.
- Lets check the monotonocity for f(x):- if f(x)-good -> f(x-1) good becauase agar x jo ki bara value tha udhar pohuchane k liye jo ops lage <=k the then ab to x-1 hai toh aur kam ops lagenge

    TTTTTTTTTTFFFFFFFFFFFFFFFFFFF
    ------------------------->x
    we are looking for the last true



*/



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




const int N = 200005;

int n,k;
vi a;

bool good(int x){
    int sum=0; //no of ops req to make median =x
    for(int i=n/2;i<n;i++){ //in 0 based indexig median is at n/2
        
        sum+=max(0ll,x-a[i]);
    }
    //bug(sum);
    return sum<=k;
}


void solve() {
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    //cout<<good(5);
    
    int l=a[n/2]; //f(l) - good  //making the x = median already would require 0 no. of ops <kmin=1 so f(l=a[n/2+1]) is always good
    int r=1e11+1; //f(r) - bad //if all tha a[i] is max i.e. 10^9 and also kmax=10^9 the x that will be definitely be bad needs to take ops>10^9 , n/2(max)=10^5 ; so (x-a[i]max)x(n/2 max)>kmax=> (x-10^9)(10^5)>10^9=>x>10^4+10^11=>x> ~10^11
    while(r-l>1){
        int m=(l+r)/2;
        if(good(m)){
            l=m;
        }
        else{
            r=m;
        }
    }

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
  
  */
