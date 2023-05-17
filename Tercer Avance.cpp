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
Tienda* Artículos;	//Declaración del arreglo, uso de puntero.

int registros = -1;	//Numero de registros que tendrá el arreglo.

	//Declaración de funciones.
void alta();
void modif();
void baja();
void lista();
void archivo();

int main()
{
	int seleccion;

		//Menú Principal.
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
	case 1:		//Alta de artículos.
		system("cls");
		alta();
		return main();
		break;

	case 2:		//Modificación de registros.
		system("cls");
		modif();
		return main();
		break;

	case 3:		//Baja de artículos.
		system("cls");
		baja();
		return main();
		break;

	case 4:		//Lista de artículos.
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
	Artículos = new Tienda[registros];
	for (int i = 0; i < registros; i++)
	{
		Artículos[i].NumArt = i + 1;
		Artículos[i].Estado = "Activo";
		printf("\nRegistro %d\n", Artículos[i].NumArt);
		cin.ignore();
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
	}
}

void modif()
{
	int NumModif, dato, j, pregunta;
	printf("\t%c %c %c MODIFICACION DE ARTICULOS %c %c %c\n", 4, 4, 4, 4, 4, 4);
	
	if (registros == -1)	//Comprueba si se han dado de alta artículos.
	{
		printf("No hay articulos para modificar\n");
		system("pause");
	}
	else
	{
		//Selección de artículo.
		printf("Indique numero de articulo a modificar: ");
		scanf_s("%d", &NumModif);
		j = NumModif - 1;
		if (Artículos[j].Estado == "Eliminado")
		{
			printf("Registro eliminado. Sin datos para modificar.\n");
			system("pause");
		}
		else
		{
			//Impresión de datos de artículo.
			printf("\nNumero de articulo: %d\n", Artículos[j].NumArt);
			printf("Nombre del articulo: %s\n", Artículos[j].NombreArt.c_str());
			printf("Descripcion: %s\n", Artículos[j].Descripcion.c_str());
			printf("Genero: %s\n", Artículos[j].Genero.c_str());
			printf("Clasificacion: %s\n", Artículos[j].Clasificacion.c_str());
			printf("Consola: %s\n", Artículos[j].Consola.c_str());
			printf("Precio unitario: %.2f\n", Artículos[j].PrecioUnit);
			printf("IVA: %.2f\n", Artículos[j].IVA);
			printf("Total: %.2f\n", Artículos[j].Total);

			//Modificación de datos.
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
					getline(cin, Artículos[j].NombreArt);
					break;
				case 2:
					printf("Indique nueva descripcion del articulo: ");
					cin.ignore();
					getline(cin, Artículos[j].Descripcion);
					break;
				case 3:
					printf("Indique nuevo genero del articulo: ");
					cin.ignore();
					getline(cin, Artículos[j].Genero);
					break;
				case 4:
					printf("Indique nueva clasificacion del articulo: ");
					cin.ignore();
					getline(cin, Artículos[j].Clasificacion);
					break;
				case 5:
					printf("Indique nueva consola del articulo: ");
					cin.ignore();
					getline(cin, Artículos[j].Consola);
					break;
				case 6:
					printf("Indique nuevo precio unitario del articulo: ");
					scanf_s("%f", &Artículos[j].PrecioUnit);
					Artículos[j].IVA = Artículos[j].PrecioUnit * 0.16;
					Artículos[j].Total = Artículos[j].PrecioUnit + Artículos[j].IVA;
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
	if (registros == -1)	//Comprueba si se han dado de alta artículos.
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

			if (Artículos[k].Estado == "Eliminado")
			{
				printf("Registro eliminado.\n");
			}
			else
			{
					//Impresión de datos de artículo.
				printf("\nNumero de articulo: %d\n", Artículos[k].NumArt);
				printf("Nombre del articulo: %s\n", Artículos[k].NombreArt.c_str());
				printf("Descripcion: %s\n", Artículos[k].Descripcion.c_str());
				printf("Genero: %s\n", Artículos[k].Genero.c_str());
				printf("Clasificacion: %s\n", Artículos[k].Clasificacion.c_str());
				printf("Consola: %s\n", Artículos[k].Consola.c_str());
				printf("Precio unitario: %.2f\n", Artículos[k].PrecioUnit);
				printf("IVA: %.2f\n", Artículos[k].IVA);
				printf("Total: %.2f\n", Artículos[k].Total);

					//Confirmación.
				do
				{
					printf("\nEliminar registro?\n1. Si\n2.No\n");
					scanf_s("%d", &confirmacion);
				} while (confirmacion != 1 && confirmacion != 2);

				if (confirmacion == 1)
				{
					Artículos[k].Estado = "Eliminado";
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
	if (registros == -1)	//Comprueba si se han dado de alta artículos.
	{
		printf("No se han encontrado articulos.\n");
	}
	else
	{
		for (int i = 0; i < registros; i++)
		{
			if (Artículos[i].Estado == "Eliminado")
			{
				printf("\nNumero de articulo: %d\n", Artículos[i].NumArt);
				printf("Registro eliminado\n");
			}
			else
			{
				printf("\nNumero de articulo: %d\n", Artículos[i].NumArt);
				printf("Nombre del articulo: %s\n", Artículos[i].NombreArt.c_str());
				printf("Descripcion: %s\n", Artículos[i].Descripcion.c_str());
				printf("Genero: %s\n", Artículos[i].Genero.c_str());
				printf("Clasificacion: %s\n", Artículos[i].Clasificacion.c_str());
				printf("Consola: %s\n", Artículos[i].Consola.c_str());
				printf("Precio unitario: %.2f\n", Artículos[i].PrecioUnit);
				printf("IVA: %.2f\n", Artículos[i].IVA);
				printf("Total: %.2f\n", Artículos[i].Total);
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
			if (Artículos[i].Estado == "Eliminado")
			{
				archivo << Artículos[i].NumArt << "\tRegistro eliminado.\n";
			}
			else
			{
				archivo << Artículos[i].NumArt << "\t";
				archivo << Artículos[i].NombreArt << "\t";
				archivo << Artículos[i].Descripcion << "\t";
				archivo << Artículos[i].Genero << "\t";
				archivo << Artículos[i].Clasificacion << "\t";
				archivo << Artículos[i].Consola << "\t";
				archivo << Artículos[i].PrecioUnit << "\t";
				archivo << Artículos[i].IVA << "\t";
				archivo << Artículos[i].Total << "\n";
			}
		}
		archivo.close();
		printf("Archivo <<datos_tienda.txt>> generado con exito.\n");
		system("pause");
	}
}