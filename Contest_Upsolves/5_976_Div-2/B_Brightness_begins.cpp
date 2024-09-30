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
Hint- 1
The final state of ith bulb (on or off) is independent of n.

Hint - 2
The final state of the ith bulb tells us about the parity of number of divisors of i.

Editorial

For any bulb i, its final state depends on the parity of the number of divisors of i. 
If i has an even number of divisors, then bulb i will be on; else it will be off. 
This translates to, if i is not a perfect square, bulb i will be on; else it will be off.
So now the problem is to find the kth number which is not a perfect square. This can be
done by binary searching the value of n such that n−⌊√n⌋=k or the direct formula n = ⌊k+k−−√+0.5⌋.
----------------------------------------------------------------------------------------------------------------------------------------------

The idea of the number theory which I observed during the contest is that , the no. of bulbs = no of ops , i.e. if there is n bulbs there shall be n ops .(Also given in question but didnt spotted)
Now if I take any ith bulb(i<=n where n is the no. or min no. of bulbs), it will go through atleast ith ops (atleast-hits when ith bulb is the nth bulb) which means after ith operation all ops-val>i 
so ops after ith one no longer divide the ith bulb as op-value>i , so for any ith bulb its state changes only uptil i for any n , i.e. final state of the bulb is independent of n
as mentioned in the first hint . 

Summary : for any ith bulb(<=n) we will have k ops where k>=i(always as per the Q constraint if we have bulbs then we shall have exactlyl n ops) , but the state change of i-th bulb occurs only untill ith
ops, and till ith ops we cover all the divisors of i as we go from 1-i, now if these divisors are even the state doesnt change from initial one which means it stays on, and if the no. of divisors is
odd the state changes.

Parity of Number of divisors of Natural Numbers:-

     1 2 3 4 5 6 7 8 9 10 11
nd   1 2 2 3 2 4 2 4 3 4  2
Par  O E O E E O E E O E  E

Observation (except 1) only Perfect Sqs have odd no. of divisors : which can be proven, since every nos(prime/composite) has atleast 2 divs(1 and itselt, except 1),
now, if the non is non prime it has more divisors then 2 , but these divisors always occur in pairs i.e. if i is a div of n , then n/i is also a div of n , except for the 
case when i=n/i => i^2=n i.e. n is a perfect sq , in that case n has odd divisors (cause is pair div, happens to coincide making them odd)

Obs; The first bulb will always be off, from 2 onwards all the non sq nos numbered bulbs will be always on, and pefect nos bulb will be always off.

    1 2 3 4 5 6 7 8 9 10 11
    O N N O N N N N O N  N
K=    1 2   3 4 5 6   7  8

So for K=3 ans is 5 , which means that 5 is the 3rd or kth non perfect sq no. starting from 2


Task is to find the kth non perfect sq number (This is a standard Number theory Q , found a solution is gfg)

Method 1 :- N(minimum No. of bulbs)=⌊k+√k+0.5⌋  (Normal Method)  
     N Bulbs  a[n]    2 3 5 6 7 8 10 11 12 13 14 15 17
     K         (n)    1 2 3 4 5 6 7  8  9  10 11 12 13

               We can come upto the constant time formula for the nth number in this sequence, by inspection. 
               nth term = n+⌊√n+0.5⌋ (Standard Resutl)

Method 2 :- Binary Search Method
  
          We can check if a number x is good or not which means is x is atleast kth non perfect sq or not 
          obviously if x is good , then x+1 is also good (A number on the right will be atleat (k+1)th non sq n if x is the kth non sq number)

          what if (x+1) is sq number.  (Search Space is only monotonic if we ommit the square no. so we sqaure nos first but i think even if we dont remove then also probablity wise chances of encountering sq nos are less hence even without removing sq nos the thing work)

Search space:        2 3 5 6 7 8 10 11 12 13
 x-⌊√x⌋      :-       1 2 3 4 5 6 7  8  9  10        k=8
                     0 0 0 0 0 1 1  1   1  1      (Monotonic Search space)
                               ^ (we are looking for the first one)

                      
                              
 
        x-⌊√x⌋:- how this formula arrives , on succesful overvation that ⌊√x⌋  is the no. of square nos before x (1 is  included as a sq no.) so substracting ⌊√x⌋
                from x gives position of x among the nonperfect sq nos.

                so non perfect sq pos of x (x is the k1 th non perfect sq nos) , k1 = x-⌊√x⌋  and if k1 is atleast k i.e. then x is a good number.

Square Root Implementation:
Return type of each:

sqrt (double)
sqrtf (float)
sqrtl (long double)  : editorial author used ll k1 = x- int(sqrtl(x)) so here int is the normal int , in my template which is int32_t , which works


-----------------------------x-----------------------------------x-------------------------------x------------------------------------x--------------------


*/



const int N = 200005;
int k;  
int good(int x){
    int k1 = x-int32_t(sqrtl(x));                  //x is the k1-th non sq no. , is x is a sq no. k1 becomes zero
    return k1>=k;
}
//Method 2 Binary Search
void solve() {
    cin>>k;

    int l=0; //l is a bad number which means l<k. As kmin=1(constraint in Q) which requires x =2 so l=1 is always bad.
    int r=2e18;   // kmax = 10^18 so r sufficiently kmax is always good (which means r>=k). why sufficiently greater req because 
    //at such big k, perfect sq before k is also many, so r should be large so that r-root r >=kmax

    while(l+1<r){
        int m = (l+r)/2;
        if(good(m)){
            r=m;             //x on right of m are also good 
        }   
        else{
            l=m;
        }
    }
    //as per the invariant the ans will be stored in r;
    cout<<r<<endl;

}


//Method 1 Direct arithematic constant time method


//learn the type conversation implementation from here.
int findNthNonSquare(int n)
{
    // conversion from int(long long) to  double(long double) is
    // necessary in order to preserve decimal 
    // places after square root.
    double x = (double)n;
 
    // calculating the result
    double ans = x + floor(0.5 + sqrt(x));
 
    return (int)ans;
}
void solve2(){
    int k; cin>>k;
    int ans=findNthNonSquare(k);
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
    cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
