//USE CASE OF GOTO:- To break out of more than one nested loop we can use flag(for 2 nested loop) or goto comes in very handy

for (){
  for(){
    for(){
      goto endloops;
    }
  }
}
endloops;
  cout<<ans;


//continue : 

while(condition){
    if(condition){
        continue;  //this would skip the remaining statements for this iteration. bases on the condition.
    }
    //statements 
}

