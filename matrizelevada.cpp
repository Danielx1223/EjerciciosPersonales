#include<iostream>
#include<stdlib.h>
#include <fstream>
#include<iomanip>
using namespace std;
int main()
{ 
ofstream myfile;
myfile.open ("prueba.txt");
srand(time(NULL)); 
 int i,x, j, a, s,w;
cout<<" introducir cuadrado de la matriz "; 
cin>>x;
cout<<" introducir  numero  a elevar la matriz";
cin>>a;
double v[x][x],r[x][x],l[x][x],q[x][x];
s=2;
myfile<<"\t Matriz \n";
cout.precision(5);
for(i=1; i<=x; i++)
{
   for (j=1; j<=x; j++)
    { 
     v[i][j]=rand()%10;
     l[i][j]=v[i][j];
     myfile<<"\t"<< v[i][j];
    }
   myfile<<"\n";
   j=1;
}
while(s<=a) 
{
for(w=1; w<=x ; w++)    
{
    for(i=1; i<=x ; i++)
    {
      r[i][w]=0; 
     for (j=1; j<=x; j++)
      { 
       r[i][w]= (v[i][j]*l[j][w])+r[i][w];   
      }
      j=1;
     }
}
myfile<<"\n\t Matriz elevada "<<s<<"\n";
for(i=1; i<=x; i++)
{
   for (j=1; j<=x; j++)
    {
    l[i][j]=r[i][j];
    myfile<<"\t"<<scientific<< r[i][j];
    } 
    myfile<<"\n";
   j=1;
}
s++;
}
return 0;
myfile.close();
}
