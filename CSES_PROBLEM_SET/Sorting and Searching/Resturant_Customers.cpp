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

lets consider arrival time +1 and leaving time -1.So we use pair sorting to find the maximum amount of arrival times of the customers.





Brillitant and yet so simple technique....Basically we plol all the points (time) on the number line and sort them . 
Only additional thing is we have and extra identificationwith each of the points as +1 and -1 where +1 represents the
time is arrival time and -1 represents the time is departure time.Now we iterate through all the times 
(which are in sorted order) ~ we move ahead in normal time . Each time a point is encountered , it means 
some has come to the resturant or hasleft the resturant . So if if its former than we should add +1 to current 
count or if its the later then we should add -1 to current count if someone leaves the resturant.So count represents 
the instantaneous count of customers in the resturant.Now max count at any point is time is out final answer.

*/

const int N = 200005;




void solve() {
    int n;cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        v.pb({x,1});
        v.pb({y,-1});
    }
    sort(v.begin(),v.end());
    //print1(v);

    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<2*n;i++){ //for n customers there are total 2n times including arrival and departure times both.
        //bug(v[i].second);
        sum+=v[i].second;
        ans=max(sum,ans);
    }
    cout<<ans<<endl;

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
