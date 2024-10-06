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

I almost did this problem entirely on my own , but WA on test 3 having the same idea as of editorial . 
Editorial

Let's do binary search on the answer. How to check if Frodo can have x pillows or more? We need to calculate the least amount of pillows we need to give to all the hobbits and compare it to m.
The number of pillows is minimized if we give x - 1 pillows to Frodo's neighbors, x - 2 pillows to the hobbits at the distance 2 from Frodo and so on, until we reach 1 pillow or until we reach an
end of beds row. 
The total amount of pillows on one side of Frodo can be calculated using a formula.
Suppose there are y beds on one side of Frodo. There are two cases: if y > x - 1, then the total number of 
pillows is , otherwise the total number of pillows is .


when bed > (x-1)

no. of beds in front of kth bed which as x pillows = k-1
no. of beds in after of kth bed which as x pillows = n-k

this is min pillow req arrangmenet such that no hobbit is hurt (max allowed diff=1 is maintained and sabko atleast ek pillow dera hun) : mountain like struction with gradual slope and peak at k

               1 1 1 1 1 1 1 | 1 2 3 4 ...x-3 x-2 x-1 | x | x-1 x-2 ..........4 2 1 | 1 1 1 1 1 
               {  bed-(x-1) }{         (x-1)          }   {     x-1                 }{bed-(x-1)}
               {                  beds=k-1            }   {      beds=n-k                      }

               min pillow on one side = sum of 1 to x-1 + 1*(bed-(x-1))      the second part is due to the single pillows distributed after (x-1) beds is over 

when bed < (x-1)  : here basially mountain doesnt reach one before that bed ends 

no. of beds in front of kth bed which as x pillows = k-1
no. of beds in after of kth bed which as x pillows = n-k

neighbourwise
1st bed has x-1  pillows
2nd bed is x-2 pillows
last bed at k-1 or n-k th bed has x-bed pillows
                  1st Bed
    1           (temp=x-bed ).........x-3 x-2 x-1 | x | x-1 x-2 ..........x-bed
    ---------------------------------------------> ans=(x-1)*x/2
    ------------>sum=(temp-1)*temp/2

     so min pillow on one side = ans-sum



min pillow req = min side 1 + x + min side 2 and i min pillow req is less than equal to m ( pillows available ) then we kth bed can have x pillows

*/
int n,m,k;


const int N = 200005;
int min_pillow_per_side(int bed, int x){
    int ans=(x-1)*(x)/2;  //when bed=(x-1);
    if(bed>x-1){  //after the mountain the remaining bed-(x-1) beds should have atleast 1 beds
        ans+=bed-(x-1);
    }
    else if(bed<x-1){
        //here mountain doesnt see its ending 
        int temp=x-bed;  //pillows in the first/last bed
        ans-=(temp-1)*(temp)/2;
    }
    return ans;
}

bool good(int x){
    return min_pillow_per_side(k-1,x)+x+min_pillow_per_side(n-k,x)<=m;
}


void solve() {
    cin>>n>>m>>k;
    int l=0; //f(l)=good
    int r=1e9+1; //f(r)=bad
   
    
    while(l+1<r){
        int m=l+(r-l)/2;
        if(good(m)){
            l=m;
        }   
        else{
            r=m;
        }
    }
    cout<<l<<endl;
    
    
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
