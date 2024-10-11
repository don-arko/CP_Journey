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
Editorial

For now, let's ignore the floor operation, so an operation is merging two elements ai and aj into one element ai+aj2.

Consider the end result. Each initial element in a must contribute a fractional coefficient to the final result. 
It turns out that the sum of the coefficients is fixed (it must be 1). That means we can greedily give the biggest 
values in a the biggest coefficients.

One way to do this is by sorting a in ascending order. We merge a1 and a2, then merge that result with a3, then merge 
that result with a4, and so on until an. If we do this, an contributes 1/2 times, an−1 contributes 1/4 times, an−2 contributes 1/8
times, and so on. This is the optimal way to get the maximum final result.
It turns out that the strategy above is also the optimal strategy for the original version of the problem. 
So we can simulate that process to get the answer.

Time complexity for each test case:  O(nlogn)

My Explaination :- 
Srsly just ignore the floor operation .(The entire focus on minimising the fraction getting turncated is useless)

The main idea is simple , the final ans is of the form ((((a1+a2)/2+a3)/2+a4)/2+a5)/2 . If we split it into seperate terms it shall look like, 
a1/2^4 + a2/2^4 + a2/2^3 + a3/2^2 + a4/2^1 . Think of 1/16  as 0.065 and similarly other numbers as numberator Numbers. So the ans is of the form
f1*a1 + f2*a2 + f3*a3... such that f1<f2<f3<f4... and sum of them is constant = 1(1/16+1/8..+1/2=1). So after seeing this from the ans seems greedy, 
we should pick greedily pick and place all the elements of the array in ascending order since the coefficients are in that order so max value coeff is multipied by the max term
and hence the ans is maximised.

*/



const int N = 200005;


void solve() {
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    //print(a);
    int res=a[0];
    for(int i=1;i<n;i++){
        res=(res+a[i])/2;
        //bug(res);
    }
    cout<<res<<endl;


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
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
