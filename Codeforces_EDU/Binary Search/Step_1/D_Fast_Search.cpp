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
This code is sufficient to undertand upperbound and lower bound and its implementation from scratch.
*/


const int N = 200005;

//Implementation from scratch for bs
void solve() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int k;cin>>k;
    while(k--){
        int l,r;cin>>l>>r;
        //finding l  eg if I have l=2 and a: 1 2 2 2 3 4 5 then i need the first 2

        int l1=-1; //l1 <l
        int r1=n;  //r2>=l
        while(l1+1<r1){
            int m=(l1+r1)/2;
            if(a[m]<l){
                l1=m;
            }
            else{
                r1=m;
            }
        }
        //as per the invariant ans will be in r1
        bug(r1);

        //10^-9<=a[i],l,r<=10^9 => that l,r will for sure get updated cause l,r always exist in the array and are not out of the range of the array
        //so l2-r1 wont give undesireable results
        // finding r , if r=10 and a : 1 2 3 4 10 10 , I need the last 10 
        
        int l2=-1;  //l2<=10;
        int r2=n;   //r2>10;
        while(l2+1<r2){
            int m=(l2+r2)/2;
            if(a[m]<=r){
                l2=m;
            }
            else{
                r2=m;
            }
        }
        //as per the invariant ans will be in l2
        //bug(l2);

        //here r1=l and l2=r so the range is [r1,l2] so no. of elements in the range is l2-r1+1.
        int ans=l2-r1+1;

        /*
        instead of r1 and l2 if we use r1 and r2 it will be same as the upperbound and lowerbound usage
        int ans = r2-r1; also works and produces the same result.
        */
        cout<<ans<<endl;


    }
}

 
//using lower_bound(>=x) and upper_bound(>x) ~ implementation of Closest from right (r)  (>=X)  and closest from left(r)  (>X) respectiveley , 
//here r returned is not index of the element but iterator to the element.
void solve1(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    //print(a);
    int k;cin>>k;
    while(k--){
        int l,r;cin>>l>>r;
        //bug(l,r);
        //lower_bound >=x ~ r of closest from right >=x
        auto r1=lower_bound(a.begin(),a.end(),l);
        

        //upper_bound >x ~ r of closest from left >x
        auto r2=upper_bound(a.begin(),a.end(),r);
        

        //here r1=l (>=l) and r2 = r+1 (>r)
        // range is [r1,r2) or [r1,r2-1] or [r1,r2-1=l2]
        // ans are  r2-r1     (r2-1)-r1+1   l2(=r2-1)-r1+1

        int ans= r2-r1;         //iterator arithematic...
        cout<<ans<<endl;
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
    while (t--) solve1();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
