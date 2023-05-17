#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

struct Tienda
{
	int NumArt = 0;
	string NombreArt, Genero, Clasificacion, Consola, Descripcion;
	float PrecioUnit = 0, IVA = 0, Total = 0;
	string Estado = "Eliminado";
};
Tienda* Art�culos;	//Declaraci�n del arreglo, uso de puntero.

int registros = -1;	//Numero de registros que tendr� el arreglo.

	//Declaraci�n de funciones.
void alta();
void modif();
void baja();
void lista();
void archivo();

int main()
{
	int seleccion;

		//Men� Principal.
	system("cls");
	printf("\t%c %c %c MENU PRINCIPAL %c %c %c\n",4,4,4,4,4,4);
	printf("1.- Alta de Articulos\n");
	printf("2.- Modificacion de Articulos\n");
	printf("3.- Baja de Articulos\n");
	printf("4.- Lista de Articulos\n");
	printf("5.- Limpiar Pantalla\n");
	printf("6.- Salir\n");
	scanf_s("%d", &seleccion);

	switch (seleccion)
	{
	case 1:		//Alta de art�culos.
		system("cls");
		alta();
		return main();
		break;

	case 2:		//Modificaci�n de registros.
		system("cls");
		modif();
		return main();
		break;

	case 3:		//Baja de art�culos.
		system("cls");
		baja();
		return main();
		break;

	case 4:		//Lista de art�culos.
		system("cls");
		lista();
		return main();
		break;

	case 5:		//Limpiar pantalla.
		system("cls");
		return main();
		break;

	case 6:		//Salir. Escritura de archivo.
		system("cls");
		archivo();
		exit(1);
		break;

	default:
		printf("Seleccion invalida\n");
		system("pause");
		return main();
		break;
	}
}

void alta()
{
	printf("\t%c %c %c ALTA DE ARTICULOS %c %c %c\n", 4, 4, 4, 4, 4, 4);
	printf("Indique cantidad de registros a dar de alta: ");
	scanf_s("%d", &registros);
	Art�culos = new Tienda[registros];
	for (int i = 0; i < registros; i++)
	{
		Art�culos[i].NumArt = i + 1;
		Art�culos[i].Estado = "Activo";
		printf("\nRegistro %d\n", Art�culos[i].NumArt);
		cin.ignore();
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
	}
}

void modif()
{
	int NumModif, dato, j, pregunta;
	printf("\t%c %c %c MODIFICACION DE ARTICULOS %c %c %c\n", 4, 4, 4, 4, 4, 4);
	
	if (registros == -1)	//Comprueba si se han dado de alta art�culos.
	{
		printf("No hay articulos para modificar\n");
		system("pause");
	}
	else
	{
		//Selecci�n de art�culo.
		printf("Indique numero de articulo a modificar: ");
		scanf_s("%d", &NumModif);
		j = NumModif - 1;
		if (Art�culos[j].Estado == "Eliminado")
		{
			printf("Registro eliminado. Sin datos para modificar.\n");
			system("pause");
		}
		else
		{
			//Impresi�n de datos de art�culo.
			printf("\nNumero de articulo: %d\n", Art�culos[j].NumArt);
			printf("Nombre del articulo: %s\n", Art�culos[j].NombreArt.c_str());
			printf("Descripcion: %s\n", Art�culos[j].Descripcion.c_str());
			printf("Genero: %s\n", Art�culos[j].Genero.c_str());
			printf("Clasificacion: %s\n", Art�culos[j].Clasificacion.c_str());
			printf("Consola: %s\n", Art�culos[j].Consola.c_str());
			printf("Precio unitario: %.2f\n", Art�culos[j].PrecioUnit);
			printf("IVA: %.2f\n", Art�culos[j].IVA);
			printf("Total: %.2f\n", Art�culos[j].Total);

			//Modificaci�n de datos.
			do
			{

				do
				{
					printf("\nIndique dato a modificar:\n");
					printf("1. Nombre\n2. Descripcion\n3. Genero\n4. Clasificacion\n5. Consola\n6. Precio\n");
					scanf_s("%d", &dato);
				} while (dato > 6 || dato < 1);

				switch (dato)
				{
				case 1:
					printf("Indique nuevo nombre del articulo: ");
					cin.ignore();
					getline(cin, Art�culos[j].NombreArt);
					break;
				case 2:
					printf("Indique nueva descripcion del articulo: ");
					cin.ignore();
					getline(cin, Art�culos[j].Descripcion);
					break;
				case 3:
					printf("Indique nuevo genero del articulo: ");
					cin.ignore();
					getline(cin, Art�culos[j].Genero);
					break;
				case 4:
					printf("Indique nueva clasificacion del articulo: ");
					cin.ignore();
					getline(cin, Art�culos[j].Clasificacion);
					break;
				case 5:
					printf("Indique nueva consola del articulo: ");
					cin.ignore();
					getline(cin, Art�culos[j].Consola);
					break;
				case 6:
					printf("Indique nuevo precio unitario del articulo: ");
					scanf_s("%f", &Art�culos[j].PrecioUnit);
					Art�culos[j].IVA = Art�culos[j].PrecioUnit * 0.16;
					Art�culos[j].Total = Art�culos[j].PrecioUnit + Art�culos[j].IVA;
					break;
				}
				printf("Cambio guardado.\n");
				do
				{
					printf("Modificar otro dato?\n1. Si\n2. No\n");
					scanf_s("%d", &pregunta);
				} while (pregunta != 1 && pregunta != 2);
			} while (pregunta == 1);
		}
	}
}

void baja()
{
	int NumBaja, k, confirmacion, pregunta;

	printf("\t%c %c %c BAJA DE ARTICULOS %c %c %c\n", 4, 4, 4, 4, 4, 4);
	if (registros == -1)	//Comprueba si se han dado de alta art�culos.
	{
		printf("No hay articulos para dar de baja.\n");
		system("pause");
	}
	else
	{
		do
		{
			printf("Indique articulo a dar de baja: ");
			scanf_s("%d", &NumBaja);
			k = NumBaja - 1;

			if (Art�culos[k].Estado == "Eliminado")
			{
				printf("Registro eliminado.\n");
			}
			else
			{
					//Impresi�n de datos de art�culo.
				printf("\nNumero de articulo: %d\n", Art�culos[k].NumArt);
				printf("Nombre del articulo: %s\n", Art�culos[k].NombreArt.c_str());
				printf("Descripcion: %s\n", Art�culos[k].Descripcion.c_str());
				printf("Genero: %s\n", Art�culos[k].Genero.c_str());
				printf("Clasificacion: %s\n", Art�culos[k].Clasificacion.c_str());
				printf("Consola: %s\n", Art�culos[k].Consola.c_str());
				printf("Precio unitario: %.2f\n", Art�culos[k].PrecioUnit);
				printf("IVA: %.2f\n", Art�culos[k].IVA);
				printf("Total: %.2f\n", Art�culos[k].Total);

					//Confirmaci�n.
				do
				{
					printf("\nEliminar registro?\n1. Si\n2.No\n");
					scanf_s("%d", &confirmacion);
				} while (confirmacion != 1 && confirmacion != 2);

				if (confirmacion == 1)
				{
					Art�culos[k].Estado = "Eliminado";
					printf("Registro eliminado.\n");
				}
			}

			do
			{
				printf("\nDar de baja otro articulo?\n1.Si\n2.No\n");
				scanf_s("%d", &pregunta);
			} while (pregunta != 1 && pregunta != 2);

		} while (pregunta == 1);
	}
}

void lista()
{
	printf("\t%c %c %c LISTA DE ARTICULOS %c %c %c\n", 4, 4, 4, 4, 4, 4);
	if (registros == -1)	//Comprueba si se han dado de alta art�culos.
	{
		printf("No se han encontrado articulos.\n");
	}
	else
	{
		for (int i = 0; i < registros; i++)
		{
			if (Art�culos[i].Estado == "Eliminado")
			{
				printf("\nNumero de articulo: %d\n", Art�culos[i].NumArt);
				printf("Registro eliminado\n");
			}
			else
			{
				printf("\nNumero de articulo: %d\n", Art�culos[i].NumArt);
				printf("Nombre del articulo: %s\n", Art�culos[i].NombreArt.c_str());
				printf("Descripcion: %s\n", Art�culos[i].Descripcion.c_str());
				printf("Genero: %s\n", Art�culos[i].Genero.c_str());
				printf("Clasificacion: %s\n", Art�culos[i].Clasificacion.c_str());
				printf("Consola: %s\n", Art�culos[i].Consola.c_str());
				printf("Precio unitario: %.2f\n", Art�culos[i].PrecioUnit);
				printf("IVA: %.2f\n", Art�culos[i].IVA);
				printf("Total: %.2f\n", Art�culos[i].Total);
			}
		}
	}
	system("pause");
}

void archivo()
{
	if (registros == -1)
	{
		printf("Sin datos para guardar. No se generara un archivo al salir.\n");
		system("pause");
	}
	else
	{
		ofstream archivo;
		archivo.open("datos_tienda.txt", ios::out);

		if (archivo.fail())
		{
			printf("No se ha logrado crear el archivo.\n");
			system("pause");
			exit(1);
		}

		archivo << "No." << "\t";
		archivo << "Nombre" << "\t";
		archivo << "Descripcion" << "\t";
		archivo << "Genero" << "\t";
		archivo << "Clasificacion" << "\t";
		archivo << "Consola" << "\t";
		archivo << "Precio" << "\t";
		archivo << "IVA" << "\t";
		archivo << "Total" << "\n";

		for (int i = 0; i < registros; i++)
		{
			if (Art�culos[i].Estado == "Eliminado")
			{
				archivo << Art�culos[i].NumArt << "\tRegistro eliminado.\n";
			}
			else
			{
				archivo << Art�culos[i].NumArt << "\t";
				archivo << Art�culos[i].NombreArt << "\t";
				archivo << Art�culos[i].Descripcion << "\t";
				archivo << Art�culos[i].Genero << "\t";
				archivo << Art�culos[i].Clasificacion << "\t";
				archivo << Art�culos[i].Consola << "\t";
				archivo << Art�culos[i].PrecioUnit << "\t";
				archivo << Art�culos[i].IVA << "\t";
				archivo << Art�culos[i].Total << "\n";
			}
		}
		archivo.close();
		printf("Archivo <<datos_tienda.txt>> generado con exito.\n");
		system("pause");
	}
}