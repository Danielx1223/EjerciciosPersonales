#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<fstream>
#define GNUPLOT "gnuplot -persist"
using namespace std;
int main()
{
    int i,A,B;
    double X,Y;
    A= pow (X,2);
    B= pow (Y,2);
     srand(time(NULL));
     for(i=1;i<=100;i++)
     {
         X= -2+rand()%(3-1);
        cout<<X<< " ";
     }
     for(i=1;i<=100;i++)
     {
         Y= -2+rand()%(3-1);
        cout<<Y<< " ";
     }
         ofstream myfile;
         myfile.open("archivo.dat");
         if ((X<=2)&&(X>=0)&&(Y<=2)&&(Y>=0)&&(A+B>=4))

         {
             cout<<"El número cumple las condiciones"<<endl;

         }
         myfile.close();
         FILE *gp;
  gp = popen(GNUPLOT,"w"); /* 'gp' is the pipe destrictor */
  if (gp==NULL)
	{
	  printf("Error opening pipe to GNU plot. Check if you have it! \n");
	  return 0;
	}
  fprintf(gp, "set samples 2000\n");
  fprintf(gp, "plot 'archivo.dat' u 1:2 w l \n");
  fprintf(gp, "rep 'archivo.dat' u 1:3 w l \n");
  fclose(gp);
   cout<<endl;
   myfile.close();
 return 0;
}


