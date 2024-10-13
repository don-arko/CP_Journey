//1. Since Modulo operator is very slow we use Const int N=1e9+7 , using  number modulo const int is faster than using a modulo with a random number
  const int mod=1e7+9;

//2. const int inf= INT_MAX>>1; the right shift divides INT_MAX/2 (integer division ~ floor division) this is done so that if we have to add int+int anywhere this wont overflow. So right shift is used to add buffer space before overfllowing.

  const int inf=INT_MAX>>1;
  

