
#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int NumArt = 0, Seleccion, Pregunta;
	string NombreArt, Genero, Clasificacion, Consola, Descripcion;
	float PrecioUnit, IVA, Total;

	cout <<endl<< "\t****MENU PRINCIPAL****" << endl;		//Menu Principal.
	cout << "1.- Alta de Articulos" << endl;
	cout << "2.- Modificacion de Articulos" << endl;
	cout << "3.- Baja de Articulos" << endl;
	cout << "4.- Lista de Articulos" << endl;
	cout << "5.- Limpiar Pantalla" << endl;
	cout << "6.- Salir" << endl<<">";
	cin >> Seleccion;

switch (Seleccion) 
	{
	case 1:		//Alta de Artículos.
		NumArt = NumArt + 1;
		
		cin.ignore();	//Debido a que la variable solicitada enterior es un entero, se necesita este comando para que los getline funcionen correctamente.
		
		cout << endl<<"\t****ALTA DE ARTICULOS****" << endl;	//Solicitud de datos.
		cout << "Nombre del Articulo: ";
		getline(cin, NombreArt);
		cout << "Descripcion: ";
		getline(cin, Descripcion);
		cout << "Genero: ";
		getline(cin, Genero);
		cout << "Clasificacion: ";
		getline(cin, Clasificacion);
		cout << "Consola: ";
		getline(cin, Consola);
		cout << "Precio Unitario: ";
		cin >> PrecioUnit;

		IVA = PrecioUnit * 0.16, Total = PrecioUnit + IVA;		//Calculo del total.

		cout << endl << "\t****CONFIRMACION DE REGISTRO****" << endl;		//Impresión de datos registrados.
		cout << "Nombre del Articulo: " << NombreArt << endl;
		cout << "Descripcion: " << Descripcion << endl;
		cout << "Genero: " << Genero << endl;
		cout << "Clasificacion: " << Clasificacion << endl;
		cout << "Consola: " << Consola << endl;
		cout << "Precio Unitario: " << PrecioUnit << endl;
		cout << "IVA: " << IVA << endl;
		cout << "Total: " << Total << endl;

		cout << endl << "Agregar otro articulo?" << endl;		//Pregunta por nuevo registro.
		cout << "1.- Si" << endl << "2.- No" << endl << ">";
		cin >> Pregunta;
		if (Pregunta == 1)
		{
			return main();
		}
		else
		{
			return 0;
		}
		break;

	case 2:		//Placeholder.
		cout << "No Disponible" << endl;
		return main();
		break;

	case 3:		//Placeholder.
		cout << "No Disponible" << endl;
		return main();
		break;

	case 4:		//Placeholder.
		cout << "No Disponible" << endl;
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
		cout << "Selección inválida" << endl;
		return main();
		break;
	}
return 0;
}