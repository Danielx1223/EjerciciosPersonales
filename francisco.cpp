#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
using namespace std;
int main ()
{
    ofstream myfile;
    myfile.open ("francisco.txt");
 int q,r,w,z;
cout<<"población 1: ";cin>>q;
cout<<"población 2: ";cin>>r; 
 int P1[1000], P2[1000]; 
w=0;
z=0;
P1[z]=q;
P2[z]=r;
cout<<" En el archivo de texto se encontrarán los resultados. ";
myfile<<"    Años   Población 1   Población 2 \n";
while(w!=1)
{
   P1[z+1]=((2*P1[z])-P2[z]);
   P2[z+1]=((2*P2[z])-P1[z]);
  
   if(P1[z+1]<0)
    { 
      P1[z+1]=0;
    }
   if(P2[z+1]<0)
    { 
      P2[z+1]=0;
    }
   myfile<<"\t"<<z<<"\t"<<P1[z]<<"\t"<<P2[z]<<"\n";
   if ((P1[z]==0)||(P2[z]==0))
    { 
      w=1;
    }
    
   z=z+1;
}
myfile.close();
return 0;
}
