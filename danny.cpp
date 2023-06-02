#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<fstream>
using namespace std;
int main(int argc, char* argv[])
{
    ofstream myfile;
    myfile.open ("prueba.txt");
    srand(time(NULL));
cout<<"\nSeñor usuario porfavor ir al archivo de texto. \n";
cout<<"Gracias por utilizarnos como su programa favorito.\n\n";  
int i, j, b, num, A[100000];
        for(i=1;i<=6;i++)
        {  
            b=0;  
            myfile<<"Fila "<<i<<")";
              for(j=1;j<=24;j++)
              {  
                 num=rand()%190;
                 myfile<<"\t"<<char(num)<<" ";
                   switch(num)
                   { 
                            case 'a':b=b+1;
                            break;
                            case 'A':b=b+1;
                            break;
                            case 'e': b=b+1;
                            break;
                            case 'E':b=b+1;
                            break;
                            case 'i': b=b+1;
                            break;
                            case 'I':b=b+1;
                            break;
                            case 'o': b=b+1;
                            break;
                            case 'O':b=b+1;
                            break;
                            case 'u': b=b+1;
                            break; 
                            case 'U':b=b+1;
                            break; 
                 }
             }
          myfile<<"\n";
          A[i]=b;
        }  
        b=0;  
        for(i=1;i<=6;i++)
        {
           b=b+A[i];
           myfile<<"\n\tLA CANTIDAD DE VOCALES DE LA FILA "<<i<<")=\t"<<A[i];
        } 
           myfile<<"\n\n\tLA CANTIDAD TOTAL DE VOCALES ES= "<<b;
myfile.close();
return 0; 
}
