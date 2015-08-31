
/*
Program name: "Merge Sort"
Author : Rahul Kishore Pinjani
Net id: rkp140230

*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>


using namespace std;


void Merge(int*,int,int,int);

void MergeSort(int *a,int p,int r)
{
    int q=0;
    if(p<r)
    {
        if(r-p>11){


        q=(p+r)/2;

        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
   }
    else {  // Insertion sort
		for(int i=p, j=i; i<r; j=++i) {
		    int ai = a[i+1];
		    while(ai < a[j]) {
			a[j+1] = a[j];
			if (j-- == p) {
			    break;
			}
		    }
		    a[j+1] = ai;
	 	}
    }
    }
    else
      return;

}

void Merge(int *A,int p,int q,int r)
{
    const int ls=(q-p)+1;
    const int rs=r-q;



    int *L=new int[ls];     //Creating a dynamic array having size as the number of elements in the left half of the array
    int *R=new int[rs];     //Creating a dynamic array having size as the number of elements in the right half of the array



    for(int i=p; i<=q; i++) L[i-p] = A[i];               //Initializing the left array with the elements in the left half of A
	for(int i=q+1; i<=r; i++) R[i-(q+1)] = A[i];        //Initializing the left array with the elements in the right half of A





        int i = 0; int j = 0;
        for(int k=p; k<=r; k++) {
	    if ((j>=rs) || ((i<ls) && (L[i] <= R[j])))
		A[k] = L[i++];
	    else
		A[k] = R[j++];
	}

	delete[] L;                                         //deleting the dynamic arrays to release memory
	delete[] R;

        return;




}
int main(int args,char* argv[])
{
    clock_t c1,c2;

    int n=atoi(argv[1]);
    int* a=new int[n];                              //Creating a dynamic array os size as the number of elements passed as command line argument.



    for(int i=0;i<n-1;i++){
        a[i]=n-i;
    }
    c1=clock();                                     //start time before call to mergesort
    MergeSort(a,0,n-1);
    c2=clock();                                     //end time after call to mergesort

    for(int i=0;i<n-1;i++)
    {

        if(a[i]>a[i+1])
        {
            cout<<"Sorting failed :-(";
            return 0;
        }
    }
    float timer=((float)c2-(float)c1);

    cout<<(timer/((CLOCKS_PER_SEC/1000)));             // calculating time elapsed in milliseconds.(Refernce:http://stackoverflow.com/questions/15235218/c-timer-milliseconds)

    cout<<"\nSuccess!";

    cout<<"\nlast-start";

    delete[] a;                                         //deleting the dynamic array to release memory



    return 0;
}
