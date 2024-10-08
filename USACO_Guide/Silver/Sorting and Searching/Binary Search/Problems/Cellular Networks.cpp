
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
OFFICIAL EDITORIAL CODEFORCES

At first store coordinates of all towers in set towers.
Then let's look through all cities. Let the current city be located in the point cur. 
Let it = towers.lowerbound(cur). Then if it is not equal to the end of the set we put 
in the variable dist the value ( * it - cur) — the distance to the nearest tower on 
the right for the current city. If it is not equal to the beginning of the set we need
to make it –  and update dist = min(dist, cur -  * it) — the distance to the nearest 
tower on the left to the current city. After that we only need to update the answer: ans = max(ans, dist).

Also this problem can be solved with help of two pointers in linear time.

*/

/*
USACO GUIDE EDITORIALS:-https://usaco.guide/problems/cf-cellular-network/solution

THREE SOLUTIONS:-
Bs on sorted Array  O(NlogN)
Two Pointers        O(N)
Set and LowerBound  O(NlogN)

*/
/*
MY Idea : Basic Idea based on cses question on implementation of upper bound and lower bound

My idea is simple , aim is to find the max dist btw any city and tower that is the min r
Now, for each city , there is closest tower on its left and right also( except for edges cities)  say d1 and d2 so d[i] for the ith city is min(d1,d2) why min cause if I have a tower closer why I will use the farther one 

Now I need find max(d[i]): which is the maximum distance between any tower and city

for finding 
d2: Closest tower to the right of the city[i] use lower_bound(towers.begin(),towers.end(),cities[i]) then min d1>=cities , if d1=towers.end(), then city is on the right end so no tower on its right 
d1: Closest tower to the left of the city[i] , just do it--(gives the l pointer), now it doesnt matter if it--(l pointer)<city[i] and not <=, because ultimately ham min(0,0) le aur min(k,0) le ultimately its the same just visualise this.
*/


const int N = 200005;

//my code O(NlogN) :- Gives TLE ON 12 Test Case
void solve() {
    int n,m;cin>>n>>m;

    int cities[n];
    for(int i=0;i<n;i++) cin>>cities[i];

    set<int> towers;    //towers at same coordinate are of no use therefore only considering unique coordinates of towers
    for(int i=0;i<m;i++){
        int temp;cin>>temp;
        towers.insert(temp);
    }
    int r=0;    //min dist possible is 0;
    for(int i=0;i<n;i++){
        int dist=INT_MAX; //dist shall store the closest distance of any tower from ith city = min(closest tower to right , closest tower to left)
        //find the closest tower to the right of the ith city
        auto clossest=lower_bound(towers.begin(),towers.end(),cities[i]);
        if(clossest!=towers.end()){
            //if tower to the right exists update dist
            dist=*clossest-cities[i];
        }
        //find the cloosest tower to the left 
        if(clossest!=towers.begin()){  //then closest-- 
            clossest--;
            //which means tower to the left exists update dist

            dist=min(dist,cities[i]-*clossest);
        }
        r=max(r,dist);
    }
    cout<<r<<endl;
}


//USACO GUIDE SOLUTION : ACCEPTED O(NlogN)
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cities[n];
	set<int> towers;
	int tower;
	for (int i = 0; i < n; i++) { cin >> cities[i]; }
	for (int i = 0; i < m; i++) {
		cin >> tower;
		towers.insert(tower);
	}
	int r = 0;
	for (int i = 0; i < n; i++) {
		int dist = 2e9 + 1;
		// find closest tower to the right of the city
		auto closesttower = towers.lower_bound(cities[i]);
		if (closesttower != towers.end()) {
			// if a tower is found, update the distance
			dist = *closesttower - cities[i];
		}
		// find closest tower to the left of the city
		if (closesttower != towers.begin()) {
			closesttower--;
			// update dist with the minimum of the distances
			dist = min(dist, cities[i] - *closesttower);
		}
		r = max(r, dist);
	}
	cout << r << endl;
	return 0;
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
