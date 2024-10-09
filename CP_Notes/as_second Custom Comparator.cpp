//for sorting of  vector of pair based on Second Element 


//in Ascending Order

bool as_second(pair<int ,int> a, pair<int,int> b){
  return a.second < b.second();
}


//in Descending Order

bool as_second(pair<int,int> a, pair<int,int> b){
  return a.second > b.second();
}


//syntax of sort
sort(a.begin(),a.end(),as_second);
