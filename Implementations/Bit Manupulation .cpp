
//function to count the no. of set bits in n ,
int countSetBits(int n){
    int count=0;
    while(n){         //n!=0 which means n has atleast one set bit
        n = n&(n-1); //clears the rightmost set bit 
        count++ ;
    }
    return count;   //returning the number of bits cleared when all the set bits are cleared and n is reduced to 0.
}
