#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
using namespace std;
int main ()
{
    ofstream myfile;
    myfile.open ("prueba.txt");
srand(time(NULL)); 
int a, b, c, x, V[13],A[13],D[13],r,w;
double t,q;
a=13;b=1; r=0; q=0; w=1; t=0;
cout<<"Señor usuario digite la variable x: ";cin>>x;
myfile<<" Aleatorio "<<" Elevado (x+10) "<<" elevado (x) "<< " diferencia p(x+10)-p(x)";
for ( c=0; c<a; c++)
{
 V[c]=rand()%10;
     for (r=0;r<c;r++)
     {
          b=b*x;
          w=w*(x+10);
     }
 A[c]=b*V[c];
 D[c]=w*V[c];
 q=q+A[c];
 t=t+D[c];
 myfile<<"\n"<<V[c]<<" \t\t "<<t<<" \t\t "<<q<<" \t\t "<< (t-q) ;
 b=1;
 w=1;
}
myfile.close();
return 0; 
}

