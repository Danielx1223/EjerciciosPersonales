#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
using namespace std;
int main ()
{
int n,i,j,a;
cout<<" Usuario digite numero de filas y columnas  ";
cin>>n;
float V[n][n],F[n][n],A[n][n];
cout<<"\tdigite la matriz\n";
 for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    cin>>V[i][j];
   A[i][j]=V[i][j];
   }
}
cout<<"\tla matriz es |\t\tla matriz unitaria \n";
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    cout<<"\t"<<V[i][j];
    
   }
    for (j=1; j<=n; j++)
   {
    if (j==i)
    { 
      F[i][j]=1;
    }
    else 
    { 
     F[i][j]=0;
    }
   cout<<"\t"<<F[i][j];
  }
 cout<<"\n";
 j=1;
}
if (V[1][1]==0)
{
 for (j=1; j<=n; j++)
 {
 V[1][j]=A[2][j];
 V[2][j]=A[1][j];
 }
 for (j=1; j<=n; j++)
 {
 A[1][j]=V[1][j];
 A[2][j]=V[2][j];
 }
cout<<"\tla matriz se convierte en ( porque V[1][1]=0)\n";
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    cout<<"\t"<<V[i][j];
   }
    for (j=1; j<=n; j++)
   {
      cout<<"\t"<<F[i][j];

    }
 cout<<"\n";
 j=1;
}
}for ( (j=1); (j<=n);(j++))
{
   V[1][j]=V[1][j]/A[1][1];
   F[1][j]=F[1][j]/A[1][1];
}
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    A[i][j]=V[i][j];
   }
 j=1;
}
for ( i=2; i<=n; i++)
{
    for ((j=1);(j<=n);(j++))
     {
       V[i][j]=V[i][j]+(V[1][j]*(A[i][1]*(-1)));
       F[i][j]=F[i][j]+(F[1][j]*(A[i][1]*(-1)));
     }
 j=1;
}
cout<<"\tla matriz va\n";
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    cout<<setprecision(3)<<"\t"<<V[i][j];
   }
    for (j=1; j<=n; j++)
   {
      cout<<"\t"<<setprecision(3)<<F[i][j];

    }
 cout<<"\n";
 j=1;
}
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    A[i][j]=V[i][j];
   }
 j=1;
}
i=1;
for ( a=2; a<=n; a++)//aaaaaaaaaaaaaaaaaaaaaaaaa
{
for ( j=1; j<=n;j++)
{
   V[a][j]=V[a][j]/A[a][a];
   F[a][j]=F[a][j]/A[a][a];
}
for ((i=1); i<=n; i++)
{
    for (j=1;j<=n;j++)
     {
       V[i][j]=V[i][j]+(V[a][j]*(A[i][a]*(-1)));
       F[i][j]=F[i][j]+(F[a][j]*(A[i][a]*(-1)));
     }
 j=1;
if (a==(i+1))
{
 i=i+1;
}
}
cout<<"\tla matriz va\n";
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    cout<<setprecision(3)<<"\t"<<V[i][j];
   }
    for (j=1; j<=n; j++)
   {
      cout<<"\t"<<setprecision(3)<<F[i][j];

    }
 cout<<"\n";
 j=1;
}
for (i=1;i<=n; i++)
{
  for (j=1; j<=n; j++)
   {
    A[i][j]=V[i][j];
   }
 j=1;
}
}
return 0;
}





