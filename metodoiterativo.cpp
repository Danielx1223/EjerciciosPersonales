#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
float danielx2 (float x )
{
 float a;
 a=( exp((1.0/5)*log(x+0.2)) );
 return a;
}
using namespace std;
int main ()
{
int n;
float a,e,f,r,z,E,b,A[10000];
e=0.00001;
n=0;
r=0;
cout<<"digite a=";cin>>a;
cout<<"digite b=";cin>>b;

cout<<"\nn\t\tXn\t\t((Xn)-(Xn-1))\n";

A[n]=((a+b)/2);
  while ( r!=1 )
   { 
  
    A[n+1]=danielx2(A[n]);
    cout<<n<<"\t\t"<<A[n]<<"\t\t"<<E<<"\n";
         if (n>=0)
         {
            E= fabs((A[n]-A[n-1]));
              if (E<e)
               {
                 r=1;
               } 
        }
    n++;        
    }
    cout<<"\nla raiz es  "<< A[n-1];

cout<<"\n\n"<< "\thecho por danielx";
return 0;
}
