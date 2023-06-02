#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
using namespace std;
int main ()
{
  ofstream myfile;
   myfile.open ("melissa.txt");
int a,b,c,d; 
cout<<"habitantes población 1: ";cin>>a;
cout<<"habitantes población 2: ";cin>>b;
int W[1000],Q[1000];
c=0; d=0;
W[c]= a;
Q[c]= b; 
cout<<" Ir a archivo de texto para ver los resultados. ";
myfile<<"    Años   Habitantes 1   Habitantes 2 \n";
for (d=0;d!=1;)
{
   Q[c+1]=((2*Q[c])-W[c]);
   W[c+1]=((2*W[c])-Q[c]);

   if(W[c+1]<0)
    { 
      W[c+1]=0;
    }
   if(Q[c+1]<0)
    { 
      Q[c+1]=0;
    }

  myfile<<"\t"<<c<<"\t"<<W[c]<<"\t"<<Q[c]<<"\n";

   if ((W[c]==0)|| (Q[c]==0))
    { 
      d=1;
    }
    
   c=c+1;
}
myfile.close();
return 0;
}
  
