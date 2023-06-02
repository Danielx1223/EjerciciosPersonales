#include<iostream>
 #include<stdio.h>
 #include<stdlib.h> 
#include<math.h> 
#include<iomanip> 
using namespace std;
 int main () 
{
int n,i,j,r, l,m;
 float V[1000],A[1000];
cout<<" para terminar de poner cifras poner el número 10 \n";
l=0;
 for (i=1;i<=1000; i++)
 {
cout<<"\n Señor Usuario digite las cifras a usar dando enter para pasar a la siguiente ";
 cin>>j;
 V[i]=j; 
if (j==10)
{
   i=1001;
}
 l= l+1; 
} 
l=l-1;
r=0;
for (i=1;i<=l; i++)
{
    r=r+V[i]; 
}
for (i=1;i<=l; i++)
{
    if((i%2)==0)
   { 
      A[i]=V[i];
   }
   else 
   {
      A[i]=((-1)*V[i]);
   }
}
m=0;
for (i=1;i<=l; i++)
{
    m=m+A[i]; 
}
cout<<"\n El número es = "; for (i=1; i<=l; i++) { cout<<V[i]; }
cout<<"\n cantidad de cifras = "<< l;
cout<<"\n suma de todas las cifras = "<< r;
cout<<"\n Primera cifra ="<< V[1];
cout<<"\n sumas de las cifras alternadas = "<< m <<"\n\n";

cout<<"\n HECHO POR DANIELX S.A "<<"\n\n";

 return 0; 
}
