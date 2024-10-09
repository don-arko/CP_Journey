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
CONCEPT: Manhatten Distance 

Euclidean Distance between 2 point P1(x1,y1) and P2(x2,y2) 
 - is given by dist(P1-P2) = ((x2-x1)^2 + (y2-y1)^2)^0.5


Manhatten Distance between 2 point P1(x1,y1) and P2(x2,y2) 
 - is given by dist(P1-P2) = |x2-x1|+|y2-y1|



 Physical Significance of these distances : Imagine a Grid
 -Euclidean Distance : is the shortest distance between P1 and P2 i.e. it is the distance of the line joining P1 and P2
 -Manhatten Distance : is the shortest distance between P1 and P2 when only horizontal and vertical movement is only allowed . |x2-x1| represents the total horizontal distance to be travelled whereas |y2-y1| represents the total vertical distance to be travelled to reach P2 from P1 using only horizontal and vertical movement.


So whenever a scenario is given to where movements are only horizontal and vertical we should ignore euclidean distance and only consider manhatten distance 
------------------------------------------------------------------------------------------------------------------------

Editorial : cf


Note, that if we can reach the destination in x days, so we can reach it in y≥x days, 
since we can delay reach to the destination point by staying at a same loc by moving to the opposite to the wind direction. 
So, we can binary search the answer. 

To check the possibility to reach the destination point (x2,y2) in k days we should at first look at the position (x3,y3)
the wind moves ship to in k days. Now we can calculate where we can go: since each day we can move in one of four directions
or not move at all, we can reach any point (x,y) with Manhattan distance |x−x3|+|y−y3|≤k. So we need to check that |x2−x3|+|y2−y3|≤k.


To calculate (x3,y3) we can note, that there were ⌊k/n⌋ full cycles and k mod n 
extra days. So it can be calculated with O(1) time using prefix sums.


Finally, about borders of binary search: to reach the destination point we need to move closer at least by one 
(it terms of Manhattan distance) from the full cycle of the wind. So, if answer exists then it doesn't exceed
(|x1−x2|+|y1−y2|)⋅n≤2⋅10^14.

--------------------------------------------------------------------------------------------------------------------------------------------
Since here we are only allowed to move vertically and horizontally all distances to be considered is the manhatten distances.

(x1,y1)-starting point
(x2,y2)-destination point
(x3,y3)- where the wind takes the ship in k days


(This basically says f(x)-good=>f(x+1)-good , which is obvious 
because if we can reach in x days we can always delay the procedure by staying at a single place 
(if wind is moving the ship towards the destination Engine power shall be applied in opposite dir 
to stay in the same position ))

FFFFFFFFFFFTTTTTTTTTTTTTT  we are looking for the first true
------------------------>k


Try to dry run the first sample test case and visualise it , then it will be easy to understand.The distance travelled by the ship is a resultant/superposition
of two forces (i) wind (not in our hands) and (ii) its engine(in out hands ). We can kinda work with them individually (~consider action of single forces at a time then add them to 
get the resultant effect)
Now the effect of wind is not in our hands so first lets see where the wind takes the ship in k days, say to (x3,y3), the one more effect on this is to be considered which is the engine effect of 
k days , if engine effect is used optimally then destination point which is at not greater than k manhatten distance from x3,y3 ,we can reach it in k days from (x1,y1)
So we need to check if the remaining manhatten distance after the wind effect is <=k or not i.e. |x2-x3|+|y2-y3|<=k. <= k -> we can that destination can be reached in k days or else not.



 */

const int N = 200005;
int n;
pair<int,int> st,fi;  // starting point coordinate and final destination point coordinate
string s;

string mv="UDLR";
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

pair<int,int> d[N]; //creates a array of pairs with all pairs initially set to (0,0)
//d[i] = 
//this array stores the change in coordinates after the ith day ; i<=n; starting from (0,0)
//d[0]=(0,0);
//d[1]=(h,k); coordinate where the wind takes the ship after first day
//bascially d[i]= Δd[i] after ith day ; i<=n;
//(x,y) after ith day=(x0 + d[i].first ,yo+d[i].second)   ; i<=n

//(x,y) after ith day=(x0 + d[i%n].first + {i/n}*d[n].first , yo+d[i%n].second + {i/n}*d[n].second)   ; i>n
                        // (Extra Days)    (complete cycle=d[n]*no. of cycles(i/n))

//size of the string is n but size of d is N >> n so we can easily yse d[n] which is the change in displacement after 1 complete cycle n days 
//displacement in x due to wind after i = 2n+3 days = x0 + 2*d[n]+d[3]
//agar n days (one complete cycle of the string) me displacement in x = -4 hain i.e. d[n]=-4, then for i=2n change in displacement shall be 2*d[n];

bool good(int x){
    int cycles=x/n;
    int extra_days=x%n;
    int x3=st.first+d[extra_days].first+cycles*d[n].first;
    int y3=st.second+d[extra_days].second+cycles*d[n].second;

    int dist= abs(fi.first-x3)+abs(fi.second-y3);//remaining manhatten distance that needs to be covered by engine power and engine can cover 1 manhatten distance in 1 day.
    //in x days engine can cover atmost x manhatten distance 
    if(dist<=x){
        return true;
    }
    else{
        return false;
    }

}
void solve() {
    
    cin>>st.first>>st.second>>fi.first>>fi.second;
    cin>>n>>s;
    //bug(n);
    
    //now calculating the change in displacement uptil n days
    for(int i=0;i<n;i++){
        int idx=-1; //
        for(int j=0;j<4;j++){ //for each of the char of the string trying to find if it is U or D ..
            if(mv[j]==s[i]){
                idx=j; //now dx[j] gives the change  in x due to U/D/L/R like that
            }
        }
        //assert(idx!=-1); //the program will terminate if this condition is ever false actually that should not happen if the data is correct.
        d[i+1]=make_pair(d[i].first+dx[idx],d[i].second+dy[idx]); //d[0]=(0,0) if s[0]=U then d[1] becomes (0,1) like that finally d is filled uptil d[n] giving change in coordinates afer n days
    }
    
    
    int l=0;
    int r=1e18; //(?) bad me figure out krna abhi dimaag ka dahi ho rakha hian
    while(r-l>1){
        int m=(l+r)/2;
        if(good(m)){
            r=m;
        }
        else{
            l=m;
        }
    }

    //(?)
    if(r>5e17) r=-1;
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
