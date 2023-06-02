#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
float danielx (float x )
{
 float a;
 a= ( (x*x*x*x*x)+(-x)+(-0.2) );
 return a;
}
float dan (float x )
{
 float a;
 a= ( (5*(x*x*x*x))-1 );
 return a;
}
using namespace std;
int main ()
{
int n;
float a,e,f,r,z,E,b,A[10000];
cout<<"digite a=";cin>>a;
cout<<"digite b=";cin>>b;
cout<<"\n";
e=0.00001;
n=0;
z= ((danielx(b)) * (dan(b)));
  if (z > 0 )
  {
  A[n] = b;
  }
 else 
  {
  A[n]=a;
  }
r=0;
cout<<"n\t\tXn\t\t((Xn)-(Xn-1))\n";

  while ( r!=1 )
   { 
  
    A[n+1]= ( A[n] - (danielx(A[n]) / dan(A[n])));
    cout<<n<<"\t\t"<<A[n]<<"\t\t"<<E<<"\n";
         if (n>=1)
         {
            E= fabs(A[n]-A[n-1]);
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



