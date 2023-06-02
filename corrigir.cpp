#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <fstream>
#define max_items 100

using namespace std;

/**************************************************************************************************************************************************************** 
 ****************************************************************************************************************************************************************
 ** Fecha       : 2016-09-21                                                                                                                                   **
 ** Autor       : NESTOR ALBERTO TORRES CUESTA                                                                                                                 **
 ** Comentarios : Ejercicio con Vectores                                                                                                                       **
 **                                                                                                                                                            **
 ** Resumen     : Ejemplifica múltiples operaciones con vectores con el añadido principal que construye un vector de registros donde cada posición del vector  **
 **               contiene Nombre, Nota 1, Nota 2, nota 3 y Nota Definitiva para un conjunto de estudiantes.                                                   **
 **                                                                                                                                                            **
 ****************************************************************************************************************************************************************
 ****************************************************************************************************************************************************************/
typedef struct 
 {
 	string Nombre;
 	float  N1, N2, N3, ND;
 } rNotas;

// Convierte una cadena a mayúsculas
string Mayusculas(string dato)
 {
 	string resp="";
 	for(int i=0;i<dato.length();i++) resp+=toupper(dato[i]);
 	return resp;
 } 
 
// Calcula la nota promedio del grupo 
float PromedioNotas(int N, rNotas V[])
 {
 	float sNota=0;
	if(N>0)
	 {
	  for(int i=0;i<N;i++)
	   sNota +=V[i].ND;
	  sNota/=N; 
	 }
	return sNota; 
 }
 
// Espera hasta que se presione una tecla, por defecto Enter. 
void Esperar(char op='\r')
 {
  while(getche()!=op); 	
 } 
 
// Envía un mensaje y en caso necesario espera por un enter para continuar 
void Notificar(string MSG, bool espera=true) 
 {
  cout << endl << endl << MSG;	
  if(espera)
    Esperar();
 }

//
// Genera una lista formateada con las notas de todo el grupo.  Por favor analizar como se formatea la salida
//
void ImprimeLista(int N, rNotas V[], float NM=0, string MSG="Listado total")
 {
 	system("CLS");
	cout << endl << endl << "** Listado de Notas ***";
	cout << endl << MSG;
	cout << endl << setw(40)  << left << "Apellidos y Nombres";  
	cout << setw(10) << "Quices";  
	cout << setw(10) << "Talleres";  
	cout << setw(10) << "Parcial";  
	cout << setw(14) << "Definitiva"<<endl;  
	if(N<1)
	 cout << endl << "*** No existen estudiantes que mostrar en la lista ****";
	else
	  for(int i=0;i<N;i++)
	   {
	   	if(V[i].ND>=NM)
	   	{
		cout << endl      << setw(40)        << left  << V[i].Nombre;  
	    cout << setw(6)   << setprecision(1) << right << V[i].N1*1.0;  
	    cout << setw(12)  << setprecision(1) << right << V[i].N2*1.0;  
	    cout << setw(9)   << setprecision(1) << right << V[i].N3*1.0;    
	    cout << setw(13)  << setprecision(1) << right << V[i].ND*1.0;  
	    }
	   } 
	Notificar("Presione <<ENTER>> para continuar");   
 }
// 
// Utiliza el ordenamiento de burbuja mejorada para ordenar la lista en función de los apellidos y nombres
// Se puede indicar si se desea ordenamiento ascendente o descendente. Por defecto será Ascendente
// 
void OrdenaLista(int N, rNotas V[], bool ASC=true)
 {
 	rNotas T;
	if(N<1)
	 cout << endl << "*** No se puede ordenar una lista vacía ****";
	else
	  for(int i=0;i<N;i++)
	   {
	     for(int j=i+1;j<N;j++)
	      if(ASC)
	       if(V[i].Nombre>V[j].Nombre)
	        {
	          T      = V[j];
			  V[j]   = V[i];
			  V[i] = T;	
			}
	      else
	       if(V[i].Nombre<V[j].Nombre)
	        {
	          T      = V[j];
			  V[j]   = V[i];
			  V[i] = T;	
			}
	   }
 }
 
// Lee los datos para cargar en el vector -- los datos de los estudiantes. Observe la forma de leer Apellidos y Nombres
void LeerDatos(int &N, rNotas V[])
 {
 	do 
	 {
 	  cout << endl << "Por favor digite la cantidad de estudiantes del curso (entre 1 y "<<max_items<<") : ";
	  cin  >> N;	
	 } while(N<1 || N>max_items);
	 
 	for(int i=0;i<N;i++)
 	 {
 	   cout << endl << "Datos para el estudiante # " << i+1;
	   cout << endl << "  --> Apellidos y Nombres   : ";
       fflush(stdin);
	   getline(cin, V[i].Nombre);
	   V[i].Nombre = Mayusculas(V[i].Nombre);
	   cout << "  --> Nota Quices (25%)     : ";
	   cin >> V[i].N1;
	   cout << "  --> Nota Talleres (25%)   : ";
	   cin >> V[i].N2;
	   cout << "  --> Nota Parcial (50%)    : ";
	   cin >> V[i].N3;
	   V[i].ND=V[i].N1*0.25+V[i].N2*0.25+V[i].N3*0.50;
	 }
 } 
 
 
//
// Esta rutina se encarga de insertar un estudiante en partidular, ubicándolo en la posición que le corresponde en función del nombre.
// 
void InsertarEnOrden(int &N, rNotas V[], rNotas dato, bool ASC=true) 
 {
  int encontrado=-1;	
  // Primero compruebo que el vector no se encuentre lleno
  if(N<max_items)
   {
   	// Si es el primer estudiante del grupo
   	if(N==0)
   	  V[0]=dato;
   	else
	 {
   	   // Procedo a localizar el estudiante en la lista (Buscar) en función del nombre
   	   string Nombre = Mayusculas(dato.Nombre);
   	
       for(int i=0;i<N;i++)
        if(ASC)
          if(Nombre<V[i].Nombre) 
            {
	  	      encontrado=i; 	
	  	      break;
			}
        else
          if(Nombre>V[i].Nombre) 
            {
	  	      encontrado=i; 	
	  	      break;
			}
   	   if(encontrado!=-1)   // Se encontró el punto de inserción
   	    {
    	 // 1.- Corrimiento de los elementos a la derecha del punto de inserción
         for(int i=N-1;i>=encontrado;i--)
           V[i+1]=V[i]; 	
         // 2.- Inserción
		 V[encontrado] = dato;  
	    }    
	   else                // No se encontró punto de inserción, va al final
	     V[N] = dato; 
     } 
    N++; 
   }   	
  else
   Notificar("No se puede agregar estudiantes a un grupo lleno ...");
 }
 
//
// Esta rutina se encarga de agregar un estudiante al curso, con la característica que el estudiante agregado pasará a ser el primero en la lista.
// 
void InsertarAlPrincipio(int &N, rNotas V[], rNotas D)
 {
  // Primero compruebo que el vector no se encuentre lleno
  if(N<max_items)
   {
   	// Se corren los elementos a la derecha
    for(int i=N;i>0;i--)
      V[i]=V[i-1]; 	
    // Se asigna el estudiante en la primera posición  
    V[0]=D;  
    // Se incrementa N, dado que hay un nuevo elemento en el vector
    N++;
   }   	
  else
   Notificar("No se puede agregar estudiantes a un grupo lleno ...");
 }
 
//
// Esta rutina se encarga de agregar un estudiante al curso, con la característica que el estudiante agregado pasará a ser el último en la lista.
// 
void InsertarAlFinal(int &N, rNotas V[], rNotas D)
 {
  // Primero compruebo que el vector no se encuentre lleno
  if(N<max_items)
   {
    // Se asigna el estudiante a la última posición
    V[N]=D;  
    // Se incrementa N, dado que hay un nuevo elemento en el vector
    N++;
   }   	
  else
   Notificar("No se puede agregar estudiantes a un grupo lleno ...");
 }
 
//
// Esta rutina se encarga de retirar el primer estudiante de la lista.
// 
void RetirarPrimero(int &N, rNotas V[])
 {
  // Primero compruebo que el vector no se encuentre vacío
  if(N>0)
   {
   	// Se corren los elementos a la izquierda
    for(int i=0;i<N-1;i++)
      V[i]=V[i+1]; 	
    // Se decrementa N, dado que se retira un elemento en el vector
    N--;
   }   	
 }
 
//
// Esta rutina se encarga de retirar un estudiante en partidular, tomando como llave de busqueda el nombre del estudiante.
// 
void RetirarEstudiante(int &N, rNotas V[], string Nombre) 
 {
  int encontrado=-1;	
  // Primero compruebo que el vector no se encuentre vacío
  if(N>0)
   {
   	// Procedo a lozalizar el estudiante en la lista (Buscar)
   	Nombre = Mayusculas(Nombre);
   	
    for(int i=0;i<N;i++)
      if(Nombre==V[i].Nombre) encontrado=i; 	
   	if(encontrado!=-1)   // lo encontró
   	 {
   	  // 1.- Corrimiento
      for(int i=encontrado;i<N-1;i++)
        V[i]=V[i+1]; 	
	  // 2.- Disminución de N	   	
	  N--; 
     } 
   	else
   	  Notificar("El estudiante "+Nombre+" no se encuentra en el grupo, no se puede retirar...");
   }   	
 }
 
//
// Esta rutina se encarga de retirar el último estudiante de la lista.
// 
void RetirarUltimo(int &N, rNotas V[])
 {
  // Primero compruebo que el vector no se encuentre vacío
  if(N>0)
   // Se decrementa N, dado que se retira un elemento en el vector
   N--;
 }
 
int main(int argc, char** argv) 
 {
 	rNotas vNotas[max_items];
 	int NumeroEstudiantes;
 	float nPromedio;
 	string Nombre;
 	char opcion;
 	rNotas Nuevo;
 	cout << fixed;
 	float sNotas;
 	setlocale(LC_CTYPE, "spanish");
 	do 
	 {
	 	system("CLS");
	 	cout << endl << "***************************************************************************";
	 	cout << endl << "**                       OPCIONES DISPONIBLES                            **";
	 	cout << endl << "***************************************************************************";
	 	cout << endl << "**                                                                       **";
	 	cout << endl << "** L) Leer datos                                                         **";
	 	cout << endl << "** P) Insertar un elemento al principio de la lista                      **";
	 	cout << endl << "** F) Insertar un elemento al final de la lista                          **";
	 	cout << endl << "** M) Insertar en la posición indicada                                   **";
	 	cout << endl << "** I) Imprimir lista                                                     **";
	 	cout << endl << "** 5) Imprimir lista(Estudiantes que ganan la asignatura)                **";
	 	cout << endl << "** 6) Imprimir lista(Estudiantes por encima del promedio)                **";
	 	cout << endl << "** O) Ordenar lista                                                      **";
	 	cout << endl << "** D) Borrar la lista                                                    **";
	 	cout << endl << "** 1) Eliminar el primer elemento de la lista                            **";
	 	cout << endl << "** 2) Eliminar el último elemento de la lista                            **";
	 	cout << endl << "** 3) Eliminar el elemento con información (dato)                        **";
	 	cout << endl << "** 4) Nota promedio del grupo                                            **";
	 	cout << endl << "** X) salir                                                              **";
	 	cout << endl << "**                                                                       **";
	 	cout << endl << "***************************************************************************";
	 	cout << endl << "** Su elección por favor                                                 **";
	 	cout << endl << "***************************************************************************";
	 	opcion=tolower(getche());
	 	switch(opcion)
	 	 {
	 	  case 'l':
		    LeerDatos(NumeroEstudiantes, vNotas);
			break;
	 	  case 'p':
	 	  	if(NumeroEstudiantes<max_items)
	 	  	 {
 	          cout << endl << "Datos para el nuevo estudiante # ";
	          cout << endl << "  --> Apellidos y Nombres   : ";
	          fflush(stdin);
	          getline(cin, Nuevo.Nombre);
	          Nuevo.Nombre = Mayusculas(Nuevo.Nombre);
   	          cout << "  --> Nota Quices (25%)     : ";
	          cin >> Nuevo.N1;
	          cout << "  --> Nota Talleres (25%)   : ";
	          cin >> Nuevo.N2;
	          cout << "  --> Nota Parcial (50%)    : ";
	          cin >> Nuevo.N3;
	          Nuevo.ND=Nuevo.N1*0.25+Nuevo.N2*0.25+Nuevo.N3*0.50;
		      InsertarAlPrincipio(NumeroEstudiantes, vNotas, Nuevo);
			 }
			else 
			 Notificar("No se pueden agregar mas elementos al grupo..."); 
			break;
	 	  case 'm':
	 	  	if(NumeroEstudiantes<max_items)
	 	  	 {
 	          cout << endl << "Datos para el nuevo estudiante # ";
	          cout << endl << "  --> Apellidos y Nombres   : ";
	          fflush(stdin);
	          getline(cin, Nuevo.Nombre);
	          Nuevo.Nombre = Mayusculas(Nuevo.Nombre);
   	          cout << "  --> Nota Quices (25%)     : ";
	          cin >> Nuevo.N1;
	          cout << "  --> Nota Talleres (25%)   : ";
	          cin >> Nuevo.N2;
	          cout << "  --> Nota Parcial (50%)    : ";
	          cin >> Nuevo.N3;
	          Nuevo.ND=Nuevo.N1*0.25+Nuevo.N2*0.25+Nuevo.N3*0.50;
		      InsertarEnOrden(NumeroEstudiantes, vNotas, Nuevo);
			 }
			else 
			 Notificar("No se pueden agregar mas elementos al grupo..."); 
			break;
	 	  case 'f':
	 	  	if(NumeroEstudiantes<max_items)
	 	  	 {
 	          cout << endl << "Datos para el nuevo estudiante # ";
	          cout << endl << "  --> Apellidos y Nombres   : ";
	          fflush(stdin);
	          getline(cin, Nuevo.Nombre);
	          Nuevo.Nombre = Mayusculas(Nuevo.Nombre);
   	          cout << "  --> Nota Quices (25%)     : ";
	          cin >> Nuevo.N1;
	          cout << "  --> Nota Talleres (25%)   : ";
	          cin >> Nuevo.N2;
	          cout << "  --> Nota Parcial (50%)    : ";
	          cin >> Nuevo.N3;
	          Nuevo.ND=Nuevo.N1*0.25+Nuevo.N2*0.25+Nuevo.N3*0.50;
		      InsertarAlFinal(NumeroEstudiantes, vNotas, Nuevo);
			 }
			else 
			 Notificar("No se pueden agregar mas elementos al grupo..."); 
			break;
	 	  case 'i':
		    ImprimeLista(NumeroEstudiantes, vNotas);
			break;
	 	  case '5':
		    ImprimeLista(NumeroEstudiantes, vNotas,3,"Estudiantes que ganan la asignatura");
			break;
	 	  case '6':
	 	  	nPromedio=PromedioNotas(NumeroEstudiantes, vNotas);
		    ImprimeLista(NumeroEstudiantes, vNotas,nPromedio,"Estudiantes con la nota por encima del promedio");
			break;
	 	  case 'o':
		    OrdenaLista(NumeroEstudiantes, vNotas);
			break;
	 	  case 'd':
	 	  	// Para destruir el arreglo basta con decirle que se encuentra vacio
		    NumeroEstudiantes=0;
			break;
	 	  case '1':
	 	  	if(NumeroEstudiantes>0)
	 	  	 RetirarPrimero(NumeroEstudiantes, vNotas);
	 	  	else
			 Notificar("No se pueden retirar elementos del grupo..."); 
			break;
	 	  case '2':
	 	  	if(NumeroEstudiantes>0)
	 	  	 RetirarUltimo(NumeroEstudiantes, vNotas);
	 	  	else
			 Notificar("No se pueden retirar elementos del grupo..."); 
			break;
			break;
	 	  case '3':
	 	  	cout << endl << "Digite el nombre del estudiante a eliminar : ";
	        cin.ignore();
	        getline(cin, Nombre);
	 	  	RetirarEstudiante(NumeroEstudiantes, vNotas, Nombre);
			break;
	 	  case '4':
	 	  	if(NumeroEstudiantes>0)
	 	  	  cout << endl << "La nota promedio del grupo es : "<<PromedioNotas(NumeroEstudiantes, vNotas);
	 	  	else
	 	  	  cout << endl << "No existen estudiantes matriculados en el grupo.";
	 	  	  Esperar();
			break;
          case 'x':
          	Notificar("Gracias por utilizar nuestro software. Hasta una próxima oportunidad");
		    break;
		  default:
            Notificar("Seleccione una opción valida...");		    					
		 }
	 } while(opcion!='x');
	return 0;
 }
