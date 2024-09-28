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


int n,k; 
vector<double> a;

bool good(double x){
    int s=0;
    for(int i=0;i<n;i++){
        s+=floor(a[i]/x);     //both a[i] and x should be double  in order for the floor function to work so the vecter a should be of doubles.
    }
    //s is the no. of pieces of length x we can cut 
    return s>=k;    //if s is atleast k then we can cut out k pieces of x length
}
const int N = 200005;


void solve() {
    cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n; i++) cin>>a[i];

    double l=0;   // l is bad  so if we cut pieces with size=0 then we could cut infinite pieces this means no. of pieces >= k this means l =0 is definitely good .
    double r=1e8; // 1 <= a[i] <= 10^7 => when l=10^8 then with that lenth we wont get a singles peace of rope i.e. no of pieces <k which means r is difinitely bad.

    for(int i=0; i<100;i++){
        double m=(l+r)/2;
        if(good(m)){        //all nos on the left are also good and hence could be discarded
            l=m;
        }
        else{
            r=m;
        }
    }

    //as per the invariant l stores good x so l shall the store the final ans


    cout<<setprecision(20)<<l<<endl;



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
