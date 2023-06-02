#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<fstream>
using namespace std; 

 int main() 
{ 
 int a,b;
cout<<" Señor Usuario digitar los dos números a comparar ";
cin>> a; cout<<" y "; cin>> b;
  
if (a>b)
    {  
         cout << "\n\tEl valor mas grande es : " <<a<<"\n\n";
         cout << "\n\tEl valor mas pequeño es : " <<b<<"\n\n";
    }
else
    {  
         cout << "\n\tEl valor mas grande es : " <<b<<"\n\n";
         cout << "\n\tEl valor mas pequeño es : " <<a<<"\n\n";
    }
  cout << "\n\t HECHO POR DANIELX SA \n\n";
  return 0;
  
}
