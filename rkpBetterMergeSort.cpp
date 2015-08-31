/*
Program name: "Better Merge Sort"
Author : Rahul Kishore Pinjani
Net id: rkp140230

*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;


void Merge(int*,int*,int,int,int);

void MergeSort(int *a,int *b,int p,int r)
{
    int q=0;
    if(p<r)
    {
        if(r-p>11)
        {

            q=(p+r)/2;

            MergeSort(a,b,p,q);
            MergeSort(a,b,q+1,r);

            Merge(a,b,p,q,r);
        }

        else { // Insertion sort if the number of elements are less than 11.
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

void Merge(int *A,int *B,int p,int q,int r)
{



    for(int i=p; i<=q; i++) B[i] = A[i];                    //Data copied from A to B
	for(int i=q+1; i<=r; i++) B[i] = A[i];



        int i = p; int j = q+1;
        for(int k=p; k<=r; k++) {
	    if ((j>r) || ((i<=q) && (B[i] <= B[j])))
		A[k] =B[i++];                                       //Data Copied back to A from B
	    else
		A[k] = B[j++];
	}



        return;




}
int main(int args,char* argv[])
{
    clock_t c1,c2;
    int n=atoi(argv[1]);
    int* a=new int[n];                              //Creating a dynamic array of size the number of elements passed as command line argument.
    int* b=new int[n];

    for(int i=0;i<n-1;i++){
        a[i]=n-i;
    }

    c1=clock();                                     //start time before call to mergesort
    MergeSort(a,b,0,n);
    c2=clock();                                     //end time after call to mergesort

    for(int i=0;i<n-1;i++)
    {

        if(a[i]>a[i+1])
        {
            cout<<"Sorting failed :-(";
            return 0;
        }
    }

    float timer=((float)c2-(float)c1);              // Differnce between end time and start time.

    cout<<(timer/((CLOCKS_PER_SEC/1000)));          // calculating time elapsed in milliseconds.(Refernce:http://stackoverflow.com/questions/15235218/c-timer-milliseconds)

    cout<<"\nSuccess!";

    cout<<"\nlast-start";

    delete[] a;                                         //deleting the dynamic arrays to release memory
	delete[] b;


    return 0;
}
