#include<iostream>
#include<string>
using namespace std;

struct Producto{
	string nombre;
	float precio;
};

struct Venta{
	int codigo;
	string producto;
	int cantidad;
	float Ptotal;
};

Producto Productos[50];
Venta Ventas[50];


int ContadorDeProductos = 0;
int ContadorDeVentas = 0;

void registrarProducto();
void Eleccion(char opcion);

int main(){
	char opcion;
	
	do{
		cout<<"\n";
		cout<<"-------------------------------"<<endl;
		cout<<"MENU DE INVENTARIO DE PRODUCTOS"<<endl;
		cout<<"-------------------------------"<<endl; 
		cout<<endl;
		cout<<"A. Registrar nuevo producto"<<endl;
		cout<<"B. Listar productos"<<endl;
		cout<<"C. Buscar productos"<<endl;
		cout<<"D. Actualizar productos"<<endl;
		cout<<"E. Eliminar producto"<<endl;
		cout<<"F. Registrar venta"<<endl;
		cout<<"G. Listar ventas"<<endl;
		cout<<"H. Calcular total de ventas"<<endl;
		cout<<"S. Salir"<<endl;
		cin>>opcion;
		
		opcion = toupper(opcion);
		Eleccion(opcion);
		
	}while(opcion != 'S');
	
	return 0;
}

void Eleccion(char opcion){
	
	switch (opcion){
		case 'A': registrarProducto(); break;
		//case 'B': 
		//case 'C': 
		//case 'D': 
		//case 'E': 
		//case 'F': 
		//case 'G': 
		//case 'H': 
		case 'S': cout << "Saliendo del sistema..."; break;
		default: cout << "Opción invalida.\n";
	}
}

void registrarProducto(){
	char RP;
	do{
		if(ContadorDeProductos>=50){
			cout<<"Limite excedido.";
			return;
		}
		
		/////////////////////////////////////////////////////
		cin.ignore();
		cout<<"---------------------------------------"<<endl; 
		cout<<"-PROCEDIMIENTO DE REGISTRO DE PRODUCTO-"<<endl;
		cout<<"---------------------------------------"<<endl; 
		cout<<endl;
		cout<<"NOMBRE DEL PRODUCTO: ";
		getline(cin, Productos[ContadorDeProductos].nombre);
		cout<<"$$PRECIO DEL PRODUCTO: ";
		cin>>Productos[ContadorDeProductos].precio;
		/////////////////////////////////////////////////////
		ContadorDeProductos += 1;
		cout<<"El producto ha sido registrado."<<endl;
		cout<<endl;
		cout<<"Desea resgistrar otro producto? S/N"<<endl;
		cin>>RP;
		RP=toupper(RP);
		cout<<endl;	
		
	}while(RP == 'S');
	
	cout<<"Regresando al menu principal..."<<endl;
}



