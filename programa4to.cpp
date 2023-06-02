#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include<math.h>
float ecu1 (float x )
{
     float a;
         a= ( ((2*(sin(x)*sin(x)))/3)-((3*(cos(x)*cos(x)))/4) );
    return a;
}
float ecu2 (float x )
{
    float a;
         a= (((17*cos(x)*sin(x))/6));
   return a;
}
float ecu3 (float x )
{
    float a;
         a=( (((2*(sin(x)*sin(x)))/3)-((3*(cos(x)*cos(x)))/4)+x) );
  return a;
}
using namespace std;
int main ()
{
    ofstream myfile;
    myfile.open ("resultado.txt");
int n;
float a,e,f,r,z,E,q,b,Z[10000];
e=0.00001;
cout<<"a=";cin>>a;
cout<<" b=";cin>>b;
cout<<"\n  mirar el archivo de texto para ver los resultados.\t\n\n";

myfile<<"\n\n\t METODO DE CUERDAS \t\n";
n=0;
r=0;
if (b>a)
  {
   Z[n]=b;
  }
 else
  {
   Z[n]=a;
  }
myfile<<"n\t\tXn\t\t((Xn)-(Xn-1))\n";

  while ( r!=1 )
   { 
  
    Z[n+1]= ( Z[n] - ((b-a)/(ecu1(b)-ecu2(a))) *ecu1(Z[n]));
    myfile<<n<<"\t\t"<<Z[n]<<"\t\t"<<E<<"\n";
         if (n>=1)
         {
            E= fabs(Z[n]-Z[n-1]);
              if (E<e)
               {
                 r=1;
               } 
        }
    n++;        
    }
    myfile<<"\nla raiz es  "<< Z[n-1];

myfile<<"\n\n\t METODO ITERATIVO \t\n";
n=0;
r=0;
Z[n]=((a+b)/2);
myfile<<"\n\t\tXn\t\t((Xn)-(Xn-1))\n";
  while ( r!=1 )
   { 
    Z[n+1]=ecu3(Z[n]);
    myfile<<n<<"\t\t"<<Z[n]<<"\t\t"<<E<<"\n";
         if (n>=0)
         {
            E= fabs((Z[n]-Z[n-1]));
              if (E<e)
               {
                 r=1;
               } 
        }
    n++;        
    }
    myfile<<"\nla raiz es  "<< Z[n-1];


myfile<<"\n\n\t METODO DE NEWTON \t\n";
n=0;
r=0;
z= ((ecu1(b)) * (ecu2(b)));
  if (z > 0 )
  {
  Z[n] = b;
  }
 else 
  {
  Z[n]=a;
  }
r=0;
myfile<<"n\t\tXn\t\t((Xn)-(Xn-1))\n";

  while ( r!=1 )
   { 
  
    Z[n+1]= ( Z[n] - (ecu1(Z[n]) / ecu2(Z[n])));
    myfile<<n<<"\t\t"<<Z[n]<<"\t\t"<<E<<"\n";
         if (n>=1)
         {
            E= fabs(Z[n]-Z[n-1]);
              if (E<e)
               {
                 r=1;
               } 
        }
    n++;        
    }
    myfile<<"\nla raiz es  "<< Z[n-1];

myfile<<"\n\n\t METODO DE BISECCIÓN \t\n";
n=0;
r=0;
z= ((ecu1(a)) * (ecu1(b)));
myfile<<"n\tXn\tf(Xn)\t\t((Xn)-(Xn-1))\n";
if(z<0)
{
  while ( r!=1 )
   { 
    Z[n]=((a+b)/2);
    r= (ecu1 (a) * ecu2(Z[n]));
    
  if (r < 0 )
  {
    b= Z[n];
  }
  if ( r>0) 
  {
    a= Z[n];
  }
     
  
         if (n>=1)
         {
            E= fabs(Z[n]-Z[n-1]);

              if (E<e)
               {
                 r=1;
               }

         }
          else
	 {
             E= Z[n];
         }
   myfile<<n<<"\t"<<Z[n]<<"\t"<<ecu1(Z[n])<<"\t"<<E<<"\n";
    n++;
   
    }
   myfile<<"\nla raiz es "<< Z[n-1];
}
else
{
myfile<<"\t\tno se puede hacer";
}

myfile.close();
return 0;
}





