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
Two pointer technique-First sort the array. Then we have to minimize the number .
So if the pointers value over flow the limit(a[i]+a[r]>x) then we decrease the upper pointer. otherwise decrease the number(count).



Idea :- Two pointer

Idea is to sort the array so that smallest number could be paired with largest numeber  (when pairing possible). This is the most optimal way or else largest nos always
has to be single on gondola so we should try to pair them with smallest nos available so that gondola req could be minimised.


For each child we are initially considering a gondola, if we are able to pair two child then instead 
of 2 gondola we shall require one, hence will do count --(one pairing possible matlab ab 1 gondola kam lagega)


We cant count from 0 to min. no. of gondola req:-  cause as per the constrant l<r  (pointers shouldnt coincide)
if suppost l is at first pos and r points to 3rd pos and a[l]+a[r]<=x i.e. we can pair the children, then both l and r 
comes to 2nd child but due to l<r this condition never occurs and second child go gondola less which shouldnt happen, hence 
we should start with 1 gondola for each child so that every child gets atleast one gondola and then try to minimise gondola (count--) 
whenever pairing possible.


We start with l=0(first child lighest) and r=n-1 (last child heaviest) 

if(a[0]+a[n-1]<=x) pairing possible then reduce gondla nos by 1 --count, also skip both the child and lets move to the next ones ++l,--r,

else //when a[0]+a[n-1]>x pariring not possible, then last child has to go alone cause he is so heavy that he cant even be paired with the lightest
      child 1st child. so he has to go alone , and we move to second last child for next possible pairing as we want to reduce the sum a[0]+a[n-1] .

This conditions are generally true for all l and r.

*/


const int N = 200005;


void solve() {
    int n,x;cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>> a[i];



    int i=0;
    int j=n-1;
    int count=n;    
    sort(a,a+n);
    while(i<j){    
        if(a[i]+a[j]<=x){ 
            --j;
            ++i;
            count--;
        }
        else{
            //a[i]+a[j]>x  => jth child has to go alone and we move to j-1th child for possible pairing
            j--;
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
