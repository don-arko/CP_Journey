//Pair
pair<int,int> d[N]; //creates a array of pairs of ints of size N  with all pairs initially set to (0,0)


//Map

/*
-Usage of maps is like arrays think of a[i] where i is the key and a[i] is the value 
-Most common usecase is frequency counting cause maps are flexible in term of range of indices.. it could be discrete
where if we use arrays to count frequency then range of indices has to be almost continuous or else there is always wastage of space and it the constraint are high this wastage may not allow us to use arrays at all or limit errors may be raised.
*/

//-printing maps through iterators
map<int,int> m;
auto it=m.begin();
while(it!=m.end()){
    cout<<(*it).first<<" "<<(*it).second<<endl;   //usage of parenthesis is very imp cause dot operator has more precedance hence without () it will cause an error
    //or
    cout<<it->first<<" "<<it-<seconnd<<endl;
    it++;
}




//MULTISET
multiset<int,greater<int>> m;  //creates a multiset(duplicate allowed) and sorts in decreasing order(opposite of default asec sort)

auto it=m.lower_bound(x);  //usage of lower bound. here in desc sorted array lower_bound gives <=





