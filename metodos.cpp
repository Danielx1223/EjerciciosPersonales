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
float dan (float x )
{
    float a;
         a= ( (5*(x*x*x*x))-1 );
   return a;
}
float danielx2 (float x )
{
    float a;
         a=( exp((1.0/5)*log(x+0.2)) );
  return a;
}
using namespace std;
int main ()
{
    ofstream myfile;
    myfile.open ("prueba.txt");
int n;
float a,e,f,r,z,E,q,b,A[10000];
e=0.00001;
cout<<"digite a=";cin>>a;
cout<<"digite b=";cin>>b;
cout<<"\n Porfavor señor usuario, dirigirse al archivo de texto para ver los resultados.\t\n\n";
myfile<<"\n\n\t METODO DE NEWTON \t\n";
n=0;
r=0;
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
myfile<<"n\t\tXn\t\t((Xn)-(Xn-1))\n";

  while ( r!=1 )
   { 
  
    A[n+1]= ( A[n] - (danielx(A[n]) / dan(A[n])));
    myfile<<n<<"\t\t"<<A[n]<<"\t\t"<<E<<"\n";
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
    myfile<<"\nla raiz es  "<< A[n-1];

myfile<<"\n\n\t METODO DE CUERDAS \t\n";
n=0;
r=0;
 if (b > a )
  {
  A[n] = b;
  }
 else 
  {
  A[n]=a;
  }
r=0;
myfile<<"n\t\tXn\t\t((Xn)-(Xn-1))\n";

  while ( r!=1 )
   { 
  
    A[n+1]= ( A[n] - ((b-a)/(danielx(b)-danielx(a))) *danielx(A[n]));
    myfile<<n<<"\t\t"<<A[n]<<"\t\t"<<E<<"\n";
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
    myfile<<"\nla raiz es  "<< A[n-1];

myfile<<"\n\n\t METODO ITERATIVO \t\n";
n=0;
r=0;

myfile<<"\nn\t\tXn\t\t((Xn)-(Xn-1))\n";

A[n]=((a+b)/2);
  while ( r!=1 )
   { 
  
    A[n+1]=danielx2(A[n]);
    myfile<<n<<"\t\t"<<A[n]<<"\t\t"<<E<<"\n";
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
    myfile<<"\nla raiz es  "<< A[n-1];

myfile<<"\n\n\t METODO DE BISECCIÓN \t\n";
n=0;
r=0;
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
myfile<<"\t\tquerido usuario no se puede hacer";
}


myfile<<"\n\n"<< "\thecho por danielx";
myfile.close();
return 0;
}






