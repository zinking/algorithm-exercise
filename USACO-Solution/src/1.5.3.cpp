/*
ID: zinking1
PROG: pprime
LANG: C++
*/

/*
first thinking
within a specific range, I think that the total nubmer of prelindrom must exceeds 
the total nubmer of primes/not proved,instinctly felt/, so first filter out the prime numbers then test if they
are prelindromes is better choice

--^~^ this is definitely the wrong idea
when the upper bound grow up to 100000000, It won't be possible to allocate enough space
for erators prime test
*/

/*
second thinking
prelindrome numbers of course is much less than prime nubmers
so generate prelindrome numbers and then test whether it si primbe

referred to other's hint
number with even count of digits is divided by 11
so only need to check the odd count of digits whether they are prime

*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

//const long int MAX_NUMBER = 100000000;
//bool number[MAX_NUMBER];

//void itoa(int i,char* buf)   /*¶¨Òåitoaº¯Êý*/
//{
//	if (buf) sprintf(buf,"%d",i);
//}
inline bool isPrime( long int number){
	int prime_upper_bound = static_cast<int>( sqrt( (float)number ) );
	for( int i=2; i<=prime_upper_bound; i++ ){
		if( number % i == 0 ) return false;
	}
	return true;
}

//void EratorsPrimeTest(int start, int end ){
//	for( int i=0; i<end; i++ ){
//		number[i] = true;
//	}
//
//	number[0] = false;
//	number[1] = false;
//
//	int c1, c2, c3;
//	int prime_upper_bound = static_cast<int>( sqrt( (float)end ) );
//	//find primes then eliminate their multiples (0 = prime, 1 = composite)
//	for(c2 = 2;c2 <= prime_upper_bound+1;c2++){
//		if(number[c2]){
//			c1=c2;
//			for(c3 = 2*c1;c3 <= end+1; c3 = c3+c1){
//				number[c3] = false;
//			}
//		}
//	}
//}

ofstream fout ("pprime.out");
ifstream fin  ("pprime.in");

void PrimePrelindromeTest( int start, int end ){
	if( start < 12 ){
		for( int i=5;i<10;i++ ) if( i<end && i>=start && isPrime(i) ) fout << i << endl;
		fout << 11 << endl;
	}

	for( int i=10; i<=9999; i++ ){
		char pnumber[20];
		sprintf(pnumber,"%d",i);
		char *p = pnumber + strlen( pnumber );
		char *q = p-1;

		while( --q >= pnumber ) *p++ = *q;
		*p='\0';
		long int number = atol( pnumber );
		if( number>=start && number<=end && isPrime(number) )fout << number << endl;

	}
}


//void PlindromeTest(int start, int end ){
//	char number_character[10];
//	for( int i=start; i<end; i++ ){
//		if( number[i] ){
//			//itoa( i, number_character );
//			sprintf(number_character,"%d",i);
//			bool isPrelindrome = true;
//			char *p= number_character, *q = p+strlen(number_character)-1;
//			for( ; p<=q; p++,q-- ){
//				if( *p != * q ){
//					isPrelindrome = false;
//					break;
//				}
//			}
//
//			if( isPrelindrome ) fout << i << endl;
//		}
//	}
//}

int main() {

	int start=0, end = 0;
	fin >> start >> end;
	//EratorsPrimeTest( start, end );
	//PlindromeTest( start, end );
	PrimePrelindromeTest(start,end);

	fin.close();
	fout.close();
    return 0;
}


//standard program for etoras prime test

//#include <stdio.h>
//#include <math.h>
//#include <assert.h>
//#include <time.h>
//
//int main(){
//	int i;
//	printf("Find primes up to: ");
//	scanf("%i",&i);
//
//	clock_t start, stop;
//	double t = 0.0;
//
//	assert((start = clock())!=-1);
//
//	//create prime list
//	int prime[i];
//	int c1, c2, c3;
//
//	//fill list with 0 - prime
//	for(c1 = 2; c1 <= i; c1++){
//		prime[c1] = 0;
//	}
//
//	//set 0 and 1 as not prime
//	prime[0]=1;
//	prime[1]=1;
//
//	//find primes then eliminate their multiples (0 = prime, 1 = composite)
//	for(c2 = 2;c2 <= (int)sqrt(i)+1;c2++){
//		if(prime[c2] == 0){
//			c1=c2;
//			for(c3 = 2*c1;c3 <= i+1; c3 = c3+c1){
//				prime[c3] = 1;
//			}
//		}
//	}
//
//	stop = clock();
//	t = (double) (stop-start)/CLOCKS_PER_SEC;
//
//	//print primes
//	for(c1 = 0; c1 < i+1; c1++){
//		if(prime[c1] == 0) printf("%i\n",c1);
//	}
//	printf("Run time: %f\n", t); //print time to find primes
//
//	return 0;
//}
