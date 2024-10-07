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
f(x)
If I throw a random time x , lets see the  products I cant make in that x time , if no. of products is
atleast t then yes I can make t products in x time or else I cannot 


The number of product I can make is x time is ∑x/a[i] where a[i] is the time req to make 1 product by i th   machine
f(x)={
    good - if in time x ,  no. of products that could be  made is atleast t 
    bad - otherwise
}
Monotocity:- f(x)-good => f(x+1)-good because jyada time to make utna product jo me pahele kam time mebhi kr lera tha 
FFFFFFFFFFTTTTTTTTTTTTT
---------------------->x

I am looking for the first true


*/
int n,t;
vi a;
bool good(int x){
    //calculate the no. of product i can make in x time.
    //each machine shall make x/a[i] floor products
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=x/a[i];
        if(sum>=t){
            return true; //implementing like this to avoid overflow of sum variable 
        }
    }
    return false;

}

const int N = 200005;



void solve() {
    cin>>n>>t;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0; //f(l)=bad , f(l=0) always bad cause if time =0 then product =0 <t min=1
    int r=1e18+1; //f(r)=good,  r should be such that f(r) is always good which means i should always be able to make atleast t products, if all k[i] is max i.e. 10^9,
  //THEN n_min*(x/k[i]max)>tmax (in worst case everything on lhs should be such that lhs is min possible and in that case as well x should be large enough to make the inquality hold)
  //=> x>(tmax X k[i]max)/n_min => x>(10^9 X 10^9)/1  => x> 10^18
    
    //cout<<good(8);
    while(r-l>1){
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
