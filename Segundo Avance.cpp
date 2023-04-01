
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Tienda
{
	int NumArt = -1;
	string NombreArt, Genero, Clasificacion, Consola, Descripcion;
	float PrecioUnit = 0, IVA = 0, Total = 0;
};

int i = -1;
Tienda Artículos[20];
int main() 
{
	int Seleccion = 0, Pregunta = 1, ModifNum = 0;

		printf("\t****MENU PRINCIPAL****\n");		//Menu Principal.
		printf("1.- Alta de Articulos\n");
		printf("2.- Modificacion de Articulos\n");
		printf("3.- Baja de Articulos\n");
		printf("4.- Lista de Articulos\n");
		printf("5.- Limpiar Pantalla\n");
		printf("6.- Salir\n");
		scanf_s("%d", &Seleccion);
	
switch (Seleccion) 
	{
	case 1:		//Alta de Artículos.
		
		if (i >= 19)
		{
			system("cls");		//En caso de que ya no haya espacio en el arreglo se imprimirá este mensaje.
			printf("\t****ALTA DE ARTICULOS****\n");
			printf("Se ha excedido el maximo de articulos admitidos.\n");
			system("pause");
		}
		else
		{
			do
			{
				i++;
				Artículos[i].NumArt = i;
				cin.ignore();	//Se requiere este comando para evitar errores con los getline.

				system("cls");
				printf("\t****ALTA DE ARTICULOS****\n");	//Solicitud de datos.
				printf("Nombre del Articulo: ");
				getline(cin, Artículos[i].NombreArt);
				printf("Descripcion: ");
				getline(cin, Artículos[i].Descripcion);
				printf("Genero: ");
				getline(cin, Artículos[i].Genero);
				printf("Clasificacion: ");
				getline(cin, Artículos[i].Clasificacion);
				printf("Consola: ");
				getline(cin, Artículos[i].Consola);
				printf("Precio Unitario: ");
				scanf_s("%f", &Artículos[i].PrecioUnit);

				Artículos[i].IVA = Artículos[i].PrecioUnit * 0.16;		//Cálculo de IVA.
				Artículos[i].Total = Artículos[i].PrecioUnit + Artículos[i].IVA;		//Cálculo del total.

				printf("\n\t****CONFIRMACION DE REGISTRO****\n");		//Impresión de datos registrados.
				printf("Numero de articulo: %d\n", Artículos[i].NumArt);
				printf("Nombre del articulo: %s\n", Artículos[i].NombreArt.c_str());
				printf("Descripcion: %s\n", Artículos[i].Descripcion.c_str());
				printf("Genero: %s\n", Artículos[i].Genero.c_str());
				printf("Clasificacion: %s\n", Artículos[i].Clasificacion.c_str());
				printf("Consola: %s\n", Artículos[i].Consola.c_str());
				printf("Precio unitario: %.2f\n", Artículos[i].PrecioUnit);
				printf("IVA: %.2f\n", Artículos[i].IVA);
				printf("Total: %.2f\n", Artículos[i].Total);

				do
				{
					printf("\nAgregar otro articulo?\n1.- Si\n2.- No\n");		//Pregunta por nuevo registro.
					scanf_s("%d", &Pregunta);
				} while (Pregunta < 1 || Pregunta > 2);
			} while (Pregunta == 1 && i < 19);
		}
		system("cls");
		return main();
		break;

	case 2:		//Modificación de Artículos
		
		do
		{
			system("cls");
			printf("\t****MODIFICACION DE ARTICULOS****\n");
			do
			{
				printf("Indique numero de articulo: ");
				scanf_s("%d", &ModifNum);
				if (ModifNum < 0 || ModifNum>19)
				{
					printf("Numero de articulo fuera de rango.\n");
				}
			} while (ModifNum < 0 || ModifNum>19);
			if (ModifNum == Artículos[ModifNum].NumArt)
			{
				cin.ignore();
				printf("\nNombre del Articulo: ");	//Solicitud de datos nuevos.
				getline(cin, Artículos[ModifNum].NombreArt);
				printf("Descripcion: ");
				getline(cin, Artículos[ModifNum].Descripcion);
				printf("Genero: ");
				getline(cin, Artículos[ModifNum].Genero);
				printf("Clasificacion: ");
				getline(cin, Artículos[ModifNum].Clasificacion);
				printf("Consola: ");
				getline(cin, Artículos[ModifNum].Consola);
				printf("Precio Unitario: ");
				scanf_s("%f", &Artículos[ModifNum].PrecioUnit);

				Artículos[ModifNum].IVA = Artículos[ModifNum].PrecioUnit * 0.16;		//Cálculo de IVA.
				Artículos[ModifNum].Total = Artículos[ModifNum].PrecioUnit + Artículos[ModifNum].IVA;		//Cálculo del total.

				printf("\n\t****CONFIRMACION DE REGISTRO****\n");		//Impresión de datos nuevos.
				printf("Numero de articulo: %d\n", Artículos[ModifNum].NumArt);
				printf("Nombre del articulo: %s\n", Artículos[ModifNum].NombreArt.c_str());
				printf("Descripcion: %s\n", Artículos[ModifNum].Descripcion.c_str());
				printf("Genero: %s\n", Artículos[ModifNum].Genero.c_str());
				printf("Clasificacion: %s\n", Artículos[ModifNum].Clasificacion.c_str());
				printf("Consola: %s\n", Artículos[ModifNum].Consola.c_str());
				printf("Precio unitario: %.2f\n", Artículos[ModifNum].PrecioUnit);
				printf("IVA: %.2f\n", Artículos[ModifNum].IVA);
				printf("Total: %.2f\n", Artículos[ModifNum].Total);
			}
			else
			{
				printf("\nNo se ha encontrado un articulo registrado con este numero.\n");
			}
			do
			{
				printf("\nModificar otro articulo?\n1.- Si\n2.- No\n");		//Pregunta por nuevo registro.
				scanf_s("%d", &Pregunta);
			} while (Pregunta < 1 || Pregunta > 2);
		} while (Pregunta == 1);
		system("cls");
		return main();
		break;

	case 3:		//Placeholder.
		cout << "No disponible" << endl;
		return main();
		break;

	case 4:		//Lista de Artículos.
		
		system("cls");
		printf("\t****LISTA DE ARTICULOS****\n");
		for (int j = 0; j < 20; j++)
		{
			if (Artículos[j].NumArt != -1)
			{
				printf("\nNumero de articulo: %d\n", Artículos[j].NumArt);
				printf("Nombre del articulo: %s\n", Artículos[j].NombreArt.c_str());
				printf("Descripcion: %s\n", Artículos[j].Descripcion.c_str());
				printf("Genero: %s\n", Artículos[j].Genero.c_str());
				printf("Clasificacion: %s\n", Artículos[j].Clasificacion.c_str());
				printf("Consola: %s\n", Artículos[j].Consola.c_str());
				printf("Precio unitario: %.2f\n", Artículos[j].PrecioUnit);
				printf("IVA: %.2f\n", Artículos[j].IVA);
				printf("Total: %.2f\n", Artículos[j].Total);
			}
		}
		system("pause");
		system("cls");
		return main();
		break;

	case 5:		//Limpiar pantalla.
		system("cls");
		return main();
		break;

	case 6:		//Salir.
		exit(1);
		break;

	default:
		cout << "Seleccion invalida" << endl;
		return main();
		break;
	}
return 0;
}