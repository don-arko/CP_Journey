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

Two pointer technique-If apartment size is greater than x+k then upper pointer will increase or
less than x-k then lower pointer will increase otherwise both the pointer increase along with counter. 

NB.Don't forget to sort both the arrays.


*/

const int N = 200005;


void solve() {
    int n,m,k;cin>>n>>m>>k;
    int a[n];   //applicants demand
    int b[m];   //appartment sizes
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<m;i++) cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);

    //now a[0](= smallest applicant demand) and b[0](=smallest appartment available) are respectively the smalles among them

    //if a[0]-k <= b[0] <= a[0]+k, we can give the smallest available appartment to the smallest demanding applicant move to a[1] and b[1] (++i,++j,++count(one flat distributed))
    // else if b[0]<a[0]-k, a[0]-k is the minmum size of the apartment demanded by any of the applicant so when b[0] is even less than that it could be not distributed so b[0] unsold , move the pointer to b[1]
    //else if b[0]>a[0]+k, a[0]+k is the highest acceptance of the lowest demanding applicant and my min, availble dimension of flat is more than that so a[0] wont get an appartment lets move to the next applicant who has higher demands

    // try to generlise these for a[i],b[j] and they work exactly in the same way since the arrays are sorted


    int i=0;
    int j=0;
    int count=0;
    while(i<n and j<m){     //while we have both the apartments and applicants left we continue , if either gets exhausted we cant just distribute (quite obvious and logical)
        if(b[j]<a[i]-k){
            j++;
        }
        else if(b[j]>a[i]+k){
            i++;
        }
        else{   //a[i]-k<=b[j]<=a[i]+k, appartment could be distributed and we move to the next appli and appartment
            ++i;
            ++j;
            ++count;
        }
    }
    cout<<count<<endl;

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
