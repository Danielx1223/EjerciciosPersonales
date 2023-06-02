#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<fstream>
using namespace std;
int main()
{
  int i,x;
  cout<<" Señor Usuario porfavor decir cantidad de numeros de la frecuencia:  ";
  cin>>x;
  float A[x],B,C;
B=0;
C=1;
cout<<" \n Señor usuario la frecuencia de fibonacci es \n";
for (i=0; i<x; i++)
{    
   if(i>=1)
   { 
     A[i]= B+C;
     C=B;
   }      
   else 
   { 
     A[i]= B;
   } 
    B= A[i];
    cout<<A[i]<<"\t";

    if ( (i>0) && ((i % 5) == 0))
    {  
         cout<<"\n\t";
    }
}
cout<<"\n\n DANIELX ES EL MEJOR \n\n " ;
return 0;
}
