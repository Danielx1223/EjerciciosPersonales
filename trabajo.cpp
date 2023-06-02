#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
using namespace std;
int main ()
{
int n,a,b,j,l,r;
cout<<"señor usuario porfavor digite el límite de la serie \t";
cin>>j;
float z,x,w,k;
cout<<"señor usuario porfavor digite x  \t";
cin>>x;
cout<<"señor usuario porfavor digite a  \t";
cin>>a;
cout<<"señor usuario porfavor digite b  \t";
cin>>b;
 k=1; w=1; r=0;
cout<<"\n\t NUMERADOR     DENOMINADOR   FRACCIÓN TOTAL\n";
for(n=1;n<=j;n++)
{ 
      if((n%2)==0) //PAR
          {
              for(l=1;l<=n;l++)  // ESTE SERÁ EL DENOMINADOR
               {
                   k=k*l;
               }
              for(l=1;l<=((2*n)+1);l++) //ESTE ES EL X ELEVADO 
               {
                   w=w*x;
               }
                z=(((-b)*w)/k);
                r=r+z;
               cout<<"\n\t"<<(-b)*w<<"\t\t"<<k<<"\t\t"<<z<<"\n";
          }
      else //IMPAR
        {
             for(l=1;l<=((2*n)-1);l++) // ESTE SERÁ EL DENOMINADOR
               {
                   k=k*l;
               }
              for(l=1;l<=(2*n);l++) // ESTE ES EL X ELEVADO
               {
                   w=w*x;
               }
                 
                z=((a*w)/k);
                r=r+z;
                cout<<"\n\t"<<a*w<<"\t\t"<<k<<"\t\t"<<z<<"\n";
        }
 k=1; w=1;
}
cout<<"\n\n TOTAL SUMA DE SERIE=  "<<r<<"\n\n";
return 0;
}


























