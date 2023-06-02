#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
float danielx (float x )
{
     float a;
        a =tan(x*1.262)-(1.84*x); //AQUÍ VA LA FUNCIÓN 
    return a;
}
float dan (float x )
{
    float a;
         a =(1.262/(cos(x*1.262)*cos(x*1.262)))-1.84; //AQUÍ SU DERIVADA
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


myfile<<"\n\n"<< "\thecho por danielx";
myfile.close();
return 0;
}


