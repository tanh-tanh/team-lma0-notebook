#include <bits/stdc++.h>
using namespace std;
void printSet(int vS) {                         // in binary representation
  printf("S = %2d = ", vS);
  stack<int> st;
  while (vS)
    st.push(vS%2), vS /= 2;
  while (!st.empty())                         // to reverse the print order
    printf("%d", st.top()), st.pop();
  printf("\n");
  //other way to print n in binary but for 32bit
  /*
  for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
   */
}
void turnon(){
	//Set/turn on the 3-rd item of the set
	int s = 34, 
	j=3;
	s |= (1<<j); 
	/*
	  s =    100010
	  1<<j = 001000
	         ------ OR
	s=       101010 (base-2) -> 42 (base-10)
	*/
}
void checkon(){
	// Check if the 3-rd and then 2-nd item of the set is on?
	int s = 42,       
	j = 3; 
	int t = s&(1<<j); 
	/*
		   101010
	1<<j = 001000 (base-2) bit 1 is shifted to the left 3 times 
		   ------ AND
		   001000 (base-2) -> 8 (base 10), item 3rd is on
	*/
	s = 42;       
	j = 2; 
	t = s&(1<<j);
	/*
	s =	   101010
	1<<j = 000100 
		   ------ AND
		   000000 (base-2) -> 0 item 2nd is off
	*/
}
void turnoff(){
	//Clear/turn off the 1-st item of the set
	int s = 42,                      
	j = 1; 
	s &=~(1<<j);

	/*
	s =					  101010
	~(1<<j) = ~(000010) = 111101
						  ------ AND
						  101000 (base-2) -> 40 (base-10)
	*/
}
void toggle(){
	//Toggle the 2-nd item and then 3-rd item of the set
	int s = 40, j=2;
	s^=(1<<j);

	/*
	s =     101000
	1<<j =  000100
			------ XOR
			101100
	*/
}
void LSOne(){
	//Check the first bit from right that is on
	int s = 40;
	int t =((s)&-(s));
	/*
	 s = 40 =  000...000101000
	-s =-40 =  111...111011000
			   --------------- AND
	t = 	   000...000001000  = 8(base-10) 
	(this is always a power of 2)   
	*/
}
void turnon(){
	//Turn on all bits in a set of size n = 6
	int s = 1<<6;
	s-=1;
	cout<<"urn on all bits in a set of size n = 6: \n";
	printSet(s);
	/*
	s = 1<<6 = 64 = 1000000
	s-1 = 63      = 0111111
	*/
}
void othertrick(){
	//check s is power of 2
	int S =9;
	cout<<"is 9 is power of 2: "<<(!(S & (S-1)));
	S =8;
	cout<<"\nis 8 is power of 2: "<<(!(S & (S-1)));
	//find nearest power of s
	S = 1;
	cout<<"\nNearest power of two of 1 is "<<(1<<lround(log2(S)));
}
void cppbuiltin(){
	__builtin_popcount(32) //=1 | 100000 (base 2), only 1 bit is on
	__builtin_popcount(30) //4 | 11110 (base 2), 4 bits are on 
	__builtin_popcountl((1l<<62)-1l) // 2^62-1 has 62 bits on (near limit) 
	// idk but __builtin_popcountl((1l<<62)-1l) is not giving the true ans is 62 instead it give 32 ??
	__builtin_ctz(32) //=5 | 100000 (base 2), 5 trailing zeroes 
	__builtin_ctz(30) //=1 | 11110 (base 2), 1 trailing zero 
	__builtin_ctzl(1l<<62) // 2^62 has 62 trailing zeroes
	// same issue like __builtin_popcountl((1l<<62)-1l)
}
int main() {
  turnon();
  checkon();
  turnoff();
  toggle();
  LSOne();
  turnon();
  othertrick();
  cppbuiltin();
  return 0;
}