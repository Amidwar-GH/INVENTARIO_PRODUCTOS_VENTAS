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
void listarProductos();
void buscarProducto();
void actualizarProducto();
void eliminarProducto();

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
		case 'B': listarProductos(); break;
		case 'C': buscarProducto(); break; 
		case 'D': actualizarProducto(); break; 
		case 'E': eliminarProducto(); break; 
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


void listarProductos(){
	cout<<"-------------------------------------"<<endl; 
	cout<<"-PROCEDIMIENTO DE LISTA DE PRODUCTOS-"<<endl;
	cout<<"-------------------------------------"<<endl; 
	cout<<endl;
	
	if(ContadorDeProductos == 0){
		cout<<"No hay productos registrados."<<endl;
		return;
	}
	
	for(int i=0; i<ContadorDeProductos; i++){
		cout<<"["<<i+1<<"]"<<": "<<"NOMBRE: "<<Productos[i].nombre<<endl;
		cout<<"["<<i+1<<"]"<<": PRECIO: "<<Productos[i].precio<<"$"<<endl;
		cout<<".............................................."<<endl;
	}
	
	cout<<"Regresando al MENU principal..."<<endl;
	cout<<endl;
}


void buscarProducto(){
	cin.ignore();
	string Busqueda;
	cout<<"--------------------------------------"<<endl; 
	cout<<"-PROCEDIMIENTO DE BUSQUEDA DE PRODUCTO-"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Digite el nombre del producto que desea buscar: ";
	getline(cin,Busqueda);
	
	bool encontrado = false;
	for(int i=0; i<ContadorDeProductos; i++){
		if(Productos[i].nombre == Busqueda){
			cout<<"EL producto fue encontrado: "<<Productos[i].nombre
				<<"| Precio "<<Productos[i].precio<<endl;
			encontrado = true;
			break;
		}		
	}
	if(!encontrado){
		cout<<"Producto no encontrado"<<endl;
	}
	cout<<endl;
	cout<<"Regresando al MENU principal...";
	cout<<endl;
}

void actualizarProducto(){
	char RPTA;
	
	if(ContadorDeProductos > 0 ){
		cout<<"Esta es la lista de productos actuales"<<endl;
		for(int i=0; i<ContadorDeProductos; i++){
		cout<<"["<<i+1<<"]"<<": "<<"NOMBRE: "<<Productos[i].nombre<<endl;
		cout<<"["<<i+1<<"]"<<": PRECIO: "<<Productos[i].precio<<"$"<<endl;
		cout<<".............................................."<<endl;
		}
	}else{
		cout<<"Aun no hay productos registrados"<<endl;
	}
	
	
	do{
		cin.ignore();
		string Busqueda;
		bool encontrado = false;
		
		
		cout<<"-------------------------------------------"<<endl; 
		cout<<"-PROCEDIMIENTO DE ACTUALIZADOR DE PRODUCTO-"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"Digite el nombre del producto que desea actualizar: ";
		getline(cin, Busqueda);
		
		for(int i=0; i<ContadorDeProductos; i++){
			if(Productos[i].nombre == Busqueda){
				cout<<"Digite el nuevo nombre del producto:"<<endl;
				getline(cin, Productos[i].nombre);
				cout<<"Digite el nuevo precio del producto"<<endl;
				cin>>Productos[i].precio;
				cout<<"El producto"<<Productos[i].nombre<<" fue actualizado"<<endl;
				encontrado = true;
				break;
			}
		}
		
		if(!encontrado){
			cout<<"El producto no fue encontrado."<<endl;
		}
		
		cout<<"Desea actualizar otro producto? (S/N)"<<endl;
		cin>>RPTA;
		RPTA=toupper(RPTA);
		
	}while(RPTA== 'S');
	
	cout<<"\nSaliendo al MENU principal..."<<endl;
}

void eliminarProducto(){
	
	char RESP;
	
	do{
		cin.ignore();
		string Eliminacion;
		bool ELIM = false;
		
		
		cout<<"------------------------------------------"<<endl; 
		cout<<"-PROCEDIMIENTO DE ELIMINACION DE PRODUCTO-"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"Digite el nombre del producto a eliminar"<<endl;
		getline(cin,Eliminacion);
		
		for(int i=0; i<ContadorDeProductos; i++){
			if(Productos[i].nombre == Eliminacion){
				for(int j=i; j<ContadorDeProductos-1; j++){
					Productos[j] = Productos[j+1];
				}
				ContadorDeProductos -= 1;
				cout<<"El producto fue eliminado correctamente.";
				ELIM = true;
				break;
			}
		}
		if(!ELIM){
			cout<<"El producto no esta registrado"<<endl;
		}
		cout<<"Desea eliminar otro producto? (S/N): "<<endl;
		cin>>RESP;
		RESP=toupper(RESP);
		
	}while(RESP == 'S');
	
	cout<<"\nRegresando al MENU principal"<<endl;
}


