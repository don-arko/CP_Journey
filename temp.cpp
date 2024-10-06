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

This problem with small constraints can be solved in the following way. Let's bake cookies one by one until it is possible. For every new cookie let's calculate val — how many grams of the magic powder we need to bake it. For this let's brute all ingredients and for the ingredient number i if a[i] ≤ b[i] let's make b[i] = b[i] - a[i], else let's make b[i] = 0 and val = val + a[i] - b[i]. When we bruted all ingredients if val > k than we can't bake more cookies. Else let's make k = k - val and go to bake new cookie.

Brute-Force Idea -

We iterate over all the incredient (one iteration with magic powder req for that iteration = val (say);val<= magic powder available means we can bake one cookie) 

*/
const int N = 200005;


void solve() {
    int n,k;cin>>n>>k;
    int req[n], have[n];
    for(int i=0;i<n;i++) cin>>req[i];
    for(int i=0;i<n;i++) cin>>have[i];
    int ans=0;
    while(k>0){
        int val=0; //calculates the grams of magic powder req for baking of one cookie (=summation req for each ingredient)
        for(int i=0;i<n;i++){
            if(req[i]<=have[i]){
                have[i]-=req[i];
            }
            else{   //req > have
                val+=req[i]-have[i];
            }
        }
        bug(val);

        if(val<=k){
            ans++;
            k-=val;
        }
        else{
            cout<<ans<<endl;
            return;
        }

    }


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
