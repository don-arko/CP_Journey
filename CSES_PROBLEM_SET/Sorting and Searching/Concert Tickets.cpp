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
Editorial :- https://github.com/ankitpriyarup/CSES_ProblemSet_Solution/blob/master/2%20Sorting_and_Searching.md
We want atmost x value for that we can add greater<int> comparator in our multiset making our lowerbound give atmost x instead of atleast x.




Idea is simple we will take elements from mp[j]=x (say) which is max price that could be given by the jth customer,then, we look 
for the max i in p such that p[i] is closest to x i.e. p[i]<=x  (p<=mp warna khareedna na mumkin maxprice offered is me jyada me nie bech sakta hun )
{and ye jo ham krre hain ye sidhe sidhe q me likha hain ki yei krna hai aur cses ki yehi kash baat hain ko layers nei hoti direct technique sikhne ko milti hain.}

max i ; p[i]<=x => closest to x from left

 =    -> lower_bound is to be used or else implemeting from scratch gives me TLE for 3 test cases.
 <+=  -> lower_bound on decreasingly sorted array.(refer cp notes on upper bound and lower bound) gives me p[i]=atmost x, which is what we required.

*/

const int N = 200005;


void solve() {
    int n,m;
    cin>>n>>m;

    // p for prices
    // mp maximum prices mp[j]=x //though we wont be declaring this.

    multiset<int,greater<int>> p; //multi set is similar to set but in contrast it could store duplicate values and in sorted order, 
                                  //greater<int> will tell the  multi set just to sort in reverse order than usual


    while(n--){int x;cin>>x;p.insert(x);}  //Taking inputs into the set.
    while(m--){
        int x;cin>>x;
        auto it=p.lower_bound(x);
        if(it==p.end()) cout<<-1<<endl;  //all tickets prices p are more the the max price x offered by the jth customer p = atmost x is s.endt().
        else { cout<<*it<<endl;p.erase(it);}  //erased function is use to represent that that ticket is sold it cant be sold again.
    }



------------------------------------------------------------------------------------------------------------------------------------------------------
  // from scratch implementation but gives TLE on 3 test cases

int n,m;
vector<int> p; //prices of tickets
vector<int> mp; //max prices customer will pay

int bs(int x){
    int l=-1;
    int r=p.size();
    //bug(l,r);
    while(r-l>1){
        //bug(l,r);
 
        int m=(l+r)/2;
        
        if(p[m]<=x){
            l=m;
        }
        else{
            r=m;
        }
    }
    return l;
}

void solve1() {
    cin>>n>>m;
    p.resize(n);
    mp.resize(m);
 
 
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<m;i++) cin>>mp[i];
    //print(mp);
 
    sort(p.begin(),p.end());
    //print(p);
 
    int l=bs(4);
    
    
    for(auto x: mp){
        int l=bs(x);
        if(l!=-1){
            cout<<p[l]<<endl;
            p.erase(p.begin()+l);
        }  
        else{
            cout<<-1<<endl;
        } 
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
