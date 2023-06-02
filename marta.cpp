#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
using namespace std;
int main ()
{
srand(time(NULL)); 
int w, q, i, M[13],E[13],z,b;
float x;
w=13;b=1; z=0; q=0;
cout<<"variable x: ";cin>>x;
cout<<" Aleatorio "<<" Suma ";
for ( i=0; i<w; i++)
{
 z=0;
 M[i]=rand()%10;
     while (z<i)
     {
          b=b*x;
          z++;
     }
 E[i]=b*M[i];
 q=q+E[i];
 cout<<"\n"<<M[i]<<" , "<<q;
 b=1;
}
cout<<"\n";
return 0; 
}

