
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
Tienda Art�culos[20];
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
	case 1:		//Alta de Art�culos.
		
		if (i >= 19)
		{
			system("cls");		//En caso de que ya no haya espacio en el arreglo se imprimir� este mensaje.
			printf("\t****ALTA DE ARTICULOS****\n");
			printf("Se ha excedido el maximo de articulos admitidos.\n");
			system("pause");
		}
		else
		{
			do
			{
				i++;
				Art�culos[i].NumArt = i;
				cin.ignore();	//Se requiere este comando para evitar errores con los getline.

				system("cls");
				printf("\t****ALTA DE ARTICULOS****\n");	//Solicitud de datos.
				printf("Nombre del Articulo: ");
				getline(cin, Art�culos[i].NombreArt);
				printf("Descripcion: ");
				getline(cin, Art�culos[i].Descripcion);
				printf("Genero: ");
				getline(cin, Art�culos[i].Genero);
				printf("Clasificacion: ");
				getline(cin, Art�culos[i].Clasificacion);
				printf("Consola: ");
				getline(cin, Art�culos[i].Consola);
				printf("Precio Unitario: ");
				scanf_s("%f", &Art�culos[i].PrecioUnit);

				Art�culos[i].IVA = Art�culos[i].PrecioUnit * 0.16;		//C�lculo de IVA.
				Art�culos[i].Total = Art�culos[i].PrecioUnit + Art�culos[i].IVA;		//C�lculo del total.

				printf("\n\t****CONFIRMACION DE REGISTRO****\n");		//Impresi�n de datos registrados.
				printf("Numero de articulo: %d\n", Art�culos[i].NumArt);
				printf("Nombre del articulo: %s\n", Art�culos[i].NombreArt.c_str());
				printf("Descripcion: %s\n", Art�culos[i].Descripcion.c_str());
				printf("Genero: %s\n", Art�culos[i].Genero.c_str());
				printf("Clasificacion: %s\n", Art�culos[i].Clasificacion.c_str());
				printf("Consola: %s\n", Art�culos[i].Consola.c_str());
				printf("Precio unitario: %.2f\n", Art�culos[i].PrecioUnit);
				printf("IVA: %.2f\n", Art�culos[i].IVA);
				printf("Total: %.2f\n", Art�culos[i].Total);

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

	case 2:		//Modificaci�n de Art�culos
		
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
			if (ModifNum == Art�culos[ModifNum].NumArt)
			{
				cin.ignore();
				printf("\nNombre del Articulo: ");	//Solicitud de datos nuevos.
				getline(cin, Art�culos[ModifNum].NombreArt);
				printf("Descripcion: ");
				getline(cin, Art�culos[ModifNum].Descripcion);
				printf("Genero: ");
				getline(cin, Art�culos[ModifNum].Genero);
				printf("Clasificacion: ");
				getline(cin, Art�culos[ModifNum].Clasificacion);
				printf("Consola: ");
				getline(cin, Art�culos[ModifNum].Consola);
				printf("Precio Unitario: ");
				scanf_s("%f", &Art�culos[ModifNum].PrecioUnit);

				Art�culos[ModifNum].IVA = Art�culos[ModifNum].PrecioUnit * 0.16;		//C�lculo de IVA.
				Art�culos[ModifNum].Total = Art�culos[ModifNum].PrecioUnit + Art�culos[ModifNum].IVA;		//C�lculo del total.

				printf("\n\t****CONFIRMACION DE REGISTRO****\n");		//Impresi�n de datos nuevos.
				printf("Numero de articulo: %d\n", Art�culos[ModifNum].NumArt);
				printf("Nombre del articulo: %s\n", Art�culos[ModifNum].NombreArt.c_str());
				printf("Descripcion: %s\n", Art�culos[ModifNum].Descripcion.c_str());
				printf("Genero: %s\n", Art�culos[ModifNum].Genero.c_str());
				printf("Clasificacion: %s\n", Art�culos[ModifNum].Clasificacion.c_str());
				printf("Consola: %s\n", Art�culos[ModifNum].Consola.c_str());
				printf("Precio unitario: %.2f\n", Art�culos[ModifNum].PrecioUnit);
				printf("IVA: %.2f\n", Art�culos[ModifNum].IVA);
				printf("Total: %.2f\n", Art�culos[ModifNum].Total);
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

	case 4:		//Lista de Art�culos.
		
		system("cls");
		printf("\t****LISTA DE ARTICULOS****\n");
		for (int j = 0; j < 20; j++)
		{
			if (Art�culos[j].NumArt != -1)
			{
				printf("\nNumero de articulo: %d\n", Art�culos[j].NumArt);
				printf("Nombre del articulo: %s\n", Art�culos[j].NombreArt.c_str());
				printf("Descripcion: %s\n", Art�culos[j].Descripcion.c_str());
				printf("Genero: %s\n", Art�culos[j].Genero.c_str());
				printf("Clasificacion: %s\n", Art�culos[j].Clasificacion.c_str());
				printf("Consola: %s\n", Art�culos[j].Consola.c_str());
				printf("Precio unitario: %.2f\n", Art�culos[j].PrecioUnit);
				printf("IVA: %.2f\n", Art�culos[j].IVA);
				printf("Total: %.2f\n", Art�culos[j].Total);
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