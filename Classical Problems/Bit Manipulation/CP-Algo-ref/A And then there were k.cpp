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

Let T= n & (n−1) & (n−2) & (n−3) & ... (k)

If there is at least one integer from K to N whose bit at the ith index is 0, then the value of the ith
bit in T will also be 0. We can easily observe that the msb (Highest set bit in n) in N will become 0
for the first time when K=2^msb−1. All the other bits will become zero when K=2^msb.


Thus the answer is, K=2^msb−1.



My Explaination.

Idea is you should know the fact that n&(n-1)=0 when n=2^x and n-1= 2^x-1

Now we need the need the maximum k which is nothing but the highest m ; 2^m-1<=n.

Implementation is quite good lets learn it.Here we check the last(leftmost) set bit x of 
n. If the xth bit(0 based ) is the last set bit then bit width is x+1 and the number n is in the range
[2^x,2^(x+1)-1), so x is the highest power of 2 ; 2^x<=n; and cout ans is 2^x -1;



*/

const int N = 200005;


void solve() {
    int n;cin>>n;

    //calculating the last set bit of n

    int last=0; //bit indices starts from 0th index hence last initial value=0, this value will for sure get updated to the last set bit index unless n=0
    for(int i=0;i<30;i++){      //0-29 are the bit indices, we dont need to go till 30 because 2^30>10^9 (which is n max)
        if((n>>i)&1){   //&1 check is the unit place bit or 0-th bit if it is set or not  
                        //i-th bit can be checked by shifting the number n ,i positisions to the right so that i-th bit is at unit position (0 index)
                        //and (the if executes when the ith bit of n is set, yielding value=1)
            last=i;
        }
    }
    cout<<(1<<last)-1<<endl;
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
