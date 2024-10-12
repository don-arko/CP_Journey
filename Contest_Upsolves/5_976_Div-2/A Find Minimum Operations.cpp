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

If k is 1, we can only subtract 1 in each operation, and our answer will be n.

Now, first, it can be seen that we have to apply at least n mod k operations of subtracting k^0=1 
(as all the other operations will not change the value of n mod k). Now, once n is divisible by k, solving the problem for n is 
equivalent to solving the problem for n/k as subtracting k^0=1 will be useless because if we apply the k^0 subtraction operation, then n
mod k becomes k−1, and we have to apply k−1 more operations to make n divisible by k (as the final result, i.e., 0 is divisible by k). 
Instead of doing these k operations of subtracting k^0, a single operation subtracting k^1 will do the job.
So, our final answer becomes the sum of the digits of n in base k.

The complexity of the solution is O(log(base k) (n)) per testcase.


My idea 1st idea, (Post contest) 
Let x be the highest power of k ; k^x<= n < k^(x+1) so obviously n is of the form = q*(2^x) + r, and also

0<= n-k^x < k^(x+1)-k^x
0<= n-k^x <k^x.(k-1)

Point is n-k^x will be less than k^x when k=2(binar system , cause RHS (k-1)=1) , but here 0<= n-k^x <k^x.(k-1)

n=q*(k^x) + r  ; 0<=r<2^x (so r should be the next value of n , cause it is less 2^x )

q = no. of substractions of k^x from n req (division is repeated substraction). 
q=⌊n/k^x⌋
r=n%k

CODE FOR THIS PART
ans+=n/k^x;
n=n%k;

Then kinda repeating this process, now one observation strikes the mind when we try to dry run this is 


Suppose if k=2 and n=5 , then we need to find out the minimum no. of times we can subtract 2^x from n ; n reduces to 0
Then highest x; 2^x<=5 is 2 
n=1*2^2+1 where q=1 and r = 1
then n=r=1 , now the highest x ; 2^x<=1 is 0
n=1*2^0+0 where q=1 and r=0
then n=r=0 (we stop)

so ans is q1+q3 but observe 5 = 101(2) and the ans q1(=1) + q2(=0) + q3(=1) is nothing but the sum of digits of binary base of 5.
Conclusion :- If we express n as powers of k that is n = q3*k^2+q2*k^1+q1*k^0 , the sum of the digits is the  ans the question is asking for , basically the process
              the question asks us to follow is the standard representation of a number in base k system. 
              For easy visualisation, imagine k=10, then n=q1*10^3 + q2*10^2... we are getting this representaion by following the process the question asks us to , 
              at the same time this is the standard represtentaion of represtation of any number to the base k system.
              And as per the question demand sum of digits to the base k system , is the req ans

Number Thoery Tools

n : a number in any system.
n%k:- fetches the last digit in base k system.
n=n/k: deletes the last digit in base k system.

For Example :n=5(decimal system) say k=2 then n=101 in base k=2 system.
n%k=5%2=1 (last digit of 5 in binary rep)
n=n/k = 5/2=2(=10 in binary,last digit =1 deleted)

n%k=2%2=0 (second last digit of 5 in binary system)
n/k=2/2=1(=1 in binary system second last digit of 5 deleted)

n%k=1 (first digit of 5 in binary system)
n/k=1/2=0 (all digits of 5 in binary system is deleted)




*/
const int N = 200005;


void solve() {
    int n,k;cin>>n>>k;
    if(k==1) {
        cout<<n<<endl;
        return;
    } //when base is 1, there is only one digit in the no. system which is the number n itself or 

    //think like n=q1* 1^all when k=1 all places have the same value as all powers of 1 are equal so, the entire n is the digit or think we need to substact 1 from n each time to make it 0 so the no. of ops = n
    int ans=0;
    while(n){
        ans+=n%k;  //last digit of n is base k system
        n/=k;      //deletes the last digit of n in base k system
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
     cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
