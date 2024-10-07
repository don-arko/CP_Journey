/*

https://codeforces.com/problemset/problem/1809/B

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
Editorial:- Just go through the editorial while visialising it or working it out in white board you will always understand each and every word .

Suppose, the answer is k. What's the maximum number of chips we can place? Firstly, the allowed points (x,y) to place chips are such that |x|+|y|≤k. We can group 
them by x-coordinate: for x=k there is only one y=0, for x=k−1 possible y are −1,0,1; for x=k−2 possible y are in segment [−2,…,2] and so on. For x=0 possible y are in [−k,…,k]. 
The negative x-s are the same.

Let's calculate the maximum number of chips we can place at each "row": for x=k it's 1; for x=k−1 there are three y-s, but since we can't place chips at the neighboring y-s, 
we can place at most 2 chips; for x=k−2 we have 5 places, but can place only 3 chips; for x=0 we have 2k+1 places, but can occupy only k+1 points. (try to draw these points on white board and you will figure out that 
if I take x=k-1 then y=1,0,1 : then I can only take (k-1,1),(k-1,-1) neigbouring y has distance =1 (1->0 or -1->0) (not greater than 1) , then for x=k-2 y=2,1,0,-1,-2: to make distance >1 i should pick alternate(both wrt ys for x-2 and wrt ys for x-1) ys i.e. ys that are not neigbours )


In total, for x∈[0,…,k] we can place at most 1+2+⋯+(k+1)=(k+1)(k+2)2 chips. Analogically, for x∈[−k,…,−1] we can place at most 1+2+⋯+k=k(k+1)2 chips.

In total, we can place at most (k+1)(k+2)2+k(k+1)2=(k+1)2 chips with cost at most k. 


Note that (k+1)2 can actually be reached since the distance between chips on the different rows is greater than 1.So, to solve our task, it's enough to find minimum k
 such that (k+1)^2  >=n that can be done with Binary Search.

Or we can calculate k=⌈√n⌉−1. Note that √n can lose precision, since n is cast to double before taking the square root 
(for example, 975461057789971042 transforms to 9.754610577899711⋅1017=975461057789971100 when converted to double). 
So you should either cast long long to long double (that consists of 80 bits in some C++ compilers) or check value k+1 as a possible answer.




f(k)={
    good-if at cost=k we can make atleast n chips
    bad - if we can't
}
Monotonocity:- if f(k)-good then => f(k+1) is also good , because now we have more money for doing the same lower expenditure

FFFFFFFFFFTTTTTTTTTTTTT    we are looking for the first true
---------------------->k

Let k be the random ans(cost) we are searching to be out ans
now , at cost k we can make some chips say f , if f is atleast n then at cost k we can make n chips




*/
int n;
bool good(int k){
    //instead of x we are using k because x here represents the coordinates.
    if(power(k+1,2)>=n)return true;
    else return false;
}

const int N = 200005;


void solve() {
    cin>>n;
    int l=-1; //f(l) bad; with cost =0 we could make 1 chip ((x,y)=(0,0)) and n min is 1 so 1 is good but f(l)=bad as per invariant 
    int r=1e9+1; //(?) Point is to find a cost which can bear placing f tiles ; f>=nmax , now nmax=10^18 how cost that is always good is 10^9+1 (from test cases it is evident that min cost is by factors less than n by need to figure out that factor)
    //bad me figure out kr lenge.
  
   
    
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
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
