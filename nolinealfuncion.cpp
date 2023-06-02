#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
float danielx (float x )
{
 float a;
 a= ( (x*x*x*x*x)+(-x)+(-0.2) );
 return a;
}
using namespace std;
int main ()
{
  ofstream myfile;
  myfile.open ("prueba.txt");
int n;
float a,e,f,r,z,E,b,A[10000];
cout<<"digite a=";cin>>a;
cout<<"digite b=";cin>>b;
cout<<"\n";
e=0.0001;
n=0;
z= ((danielx(a)) * (danielx(b)));
myfile<<"n\tXn\tf(Xn)\t\t((Xn)-(Xn-1))\n";
if(z<0)
{
  while ( r!=1 )
   { 
    A[n]=((a+b)/2);
    r= (danielx (a) * danielx (A[n]));
    
  if (r < 0 )
  {
    b= A[n];
  }
  if ( r>0) 
  {
    a= A[n];
  }
     
  
         if (n>=1)
         {
            E= fabs(A[n]-A[n-1]);

              if (E<e)
               {
                 r=1;
               }

         }
          else
	 {
             E= A[n];
         }
   myfile<<n<<"\t"<<A[n]<<"\t"<<danielx(A[n])<<"\t"<<E<<"\n";
    n++;
   
    }
   myfile<<"\nla raiz es aproximadamente "<< A[n-1];
}
else
{
cout<<"\t\tquerido usuario no se puede hacer";
}
myfile<<"\n\n"<< "\thecho por danielx";
myfile.close();
return 0;
}




