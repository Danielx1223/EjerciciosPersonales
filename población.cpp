#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
#define GNUPLOT "gnuplot -persist"
using namespace std;
int main(int argc, char **argv)
{
    ofstream myfile;
    myfile.open ("prueba.dat");
FILE *gp;
  gp = popen(GNUPLOT,"w"); /* 'gp' is the pipe destrictor */
  if (gp==NULL)
	{
	  printf("Error opening pipe to GNU plot. Check if you have it! \n");
	  return 0;
	}
int n,a,b,r;
cout<<"digite población a=";cin>>a;
cout<<"digite población b (diferente a la a)=";cin>>b;
cout<<"\n Porfavor señor usuario, dirigirse al archivo de texto para ver los resultados.\t\n\n";
float V[1000], A[1000];
n=0; 
r=0;
V[n]=a;
A[n]=b;
myfile<<" Años |"<< " Población a |"<< " Población b \n"; 
while (r!=1)
{
   V[n+1]=((2*V[n])-A[n]);
   A[n+1]=((2*A[n])-V[n]);
  
   if(V[n+1]<0)
    { 
      V[n+1]=0;
    }
   if(A[n+1]<0)
    { 
      A[n+1]=0;
    }

  myfile<<n<<"\t "<<V[n]<<" \t\t"<<A[n]<<"\n";

   if ((V[n]==0)|| (A[n]==0))
    { 
      r=1;
    }
    
   n=n+1;
}
myfile.close();

fprintf(gp, "plot 'prueba.dat' u 1:2 t 'población a' w linespoints\n");
fprintf(gp, "rep 'prueba.dat' u 1:3 t 'población b' w linespoints \n");
  fclose(gp);
  return 0;
}

  





