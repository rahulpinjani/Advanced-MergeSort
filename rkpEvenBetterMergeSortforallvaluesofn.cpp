/*
Program name: "Even Better Merge Sort" (Works for all values of n)
Author : Rahul Kishore Pinjani
Net id: rkp140230

*/


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <climits>

#include <cstring>

using namespace std;

int h1=0,h2=0;                          //Global initialization of h1 and h2

void Merge(int*,int*,int,int,int);

int MergeSort(int *a,int *b,int p,int r)
{
    int q=0;
    if(p<r)
    {

     q=(p+r)/2;

    int m1,m2;

    m1=MergeSort(a,b,p,q);

    m2=MergeSort(a,b,q+1,r);
    h1=m1;
    h2=m2;



   if(h1%2!=0)
        Merge(b,a,p,q,r);
    else
        Merge(a,b,p,q,r);




        return h1+1;

    }
    else{

        return 0;

    }


}

void Merge(int *A,int *B,int p,int q,int r)
{


        int i = p; int j = q+1;
        for(int k=p; k<=r; k++) {
	    if ((j>r) || ((i<=q) && (A[i] <= A[j])))
		B[k] =A[i++];
	    else
		B[k] = A[j++];

	}

        return;




}
int main(int args,char* argv[])
{


    clock_t c1,c2;
    int n=atoi(argv[1]);                                        //Converting Command line argument to an integer.

    int next = pow(2, ceil(log(n)/log(2)));                     //if n is not a power of 2 then round n to the immediate next power of 2.(Reference: http://stackoverflow.com/questions/466204/rounding-off-to-nearest-power-of-2)

    int* a=new int[next];
    int* b=new int[next];
    fill_n(a,next,INT_MAX);                                     //Initialize the arrays with the maximum value of an integer
    fill_n(b,next,INT_MAX);



  for(int i=0;i<n;i++){                                         //Fill in the arrays with required values.
        a[i]=n-i;
    }


    c1=clock();                                                 //Start time before merge is called

    MergeSort(a,b,0,next-1);

    int pw=log2(next);


    if(pw%2==0)                                                 //if it is an even power of 2 then only halves of the arrays are sorted so a final call to merge is made to sort the entire array.
        Merge(a,b,0,next/2,next-1);


    c2=clock();                                                 // End time after merge is called


    for(int i=0;i<n-1;i++)
    {

        if(b[i]>b[i+1])
        {
            cout<<"Sorting failed :-(";
            return 0;
        }
    }


    float timer=((float)c2-(float)c1);

    cout<<(timer/((CLOCKS_PER_SEC/1000)));                     // calculating time elapsed in milliseconds.(Refernce:http://stackoverflow.com/questions/15235218/c-timer-milliseconds)

    cout<<"\nSuccess!";

    cout<<"\nlast-start";

    delete[] a;                                         //deleting the dynamic arrays to release memory
	delete[] b;



    return 0;
}
