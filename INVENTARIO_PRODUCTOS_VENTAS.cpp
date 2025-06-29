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
void registrarVenta();
void listarVentas();
void calcularTotalVentas();

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
		case 'F': registrarVenta(); break;
		case 'G': listarVentas(); break; 
		case 'H': calcularTotalVentas(); break; 
		case 'S': cout << "Saliendo del sistema..."; break;
		default: cout << "Opcion invalida.\n";
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
				cout<<"El producto fue eliminado correctamente."<<endl;
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

void registrarVenta(){
	char RESPUESTA;
	do{
		cin.ignore();
		string NombreDelProducto;
		int cantidad;
		bool COINCIDENCIA = false;
		int casillero;
		
		cout<<"-------------------------------------"<<endl; 
		cout<<"-PROCEDIMIENTO DE REGISTRO DE VENTAS-"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Digite el nombre del producto que se vendio: ";
		getline(cin,NombreDelProducto);
		
		for(int i=0; i<ContadorDeProductos; i++){
			if(NombreDelProducto == Productos[i].nombre){
				casillero = i;
				COINCIDENCIA = true;
				break;
			}
		}
		
		if(!COINCIDENCIA){
			cout<<"El producto no fue registrado"<<endl;
		}else{
			cout<<"Cantidad vendida: "<<endl;
			cin >> cantidad;
			
			Ventas[ContadorDeVentas].codigo = ContadorDeVentas + 1;
			Ventas[ContadorDeVentas].producto = Productos[casillero].nombre;
			Ventas[ContadorDeVentas].cantidad = cantidad;
			Ventas[ContadorDeVentas].Ptotal = Productos[casillero].precio*cantidad;
			ContadorDeVentas += 1;
			
			cout<<"La venta fue registrada."<<endl;	
		}
		
		cout<<"Desea registrar otra venta? (S/N)"<<endl;
		cin>>RESPUESTA;
		RESPUESTA = toupper(RESPUESTA);
		
	}while(RESPUESTA == 'S');
	
	cout<<"Regresando al MENU principal..."<<endl;
}

void listarVentas(){
	cout<<"------------------------------------"<<endl; 
	cout<<"-PROCEDIMIENTO DE LISTADO DE VENTAS-"<<endl;
	cout<<"------------------------------------"<<endl;
	
	if(ContadorDeVentas == 0){
		cout<<"Aun no hay ventas que se hayan registrado."<<endl;
		return;
	}
	
	for(int i=0; i<ContadorDeVentas; i++){
		cout<<"Venta numero "<<Ventas[i].codigo<<" | Producto: "<<Ventas[i].producto<<" | Cantidad: "<<Ventas[i].cantidad<<" | Total: "<<Ventas[i].Ptotal<<endl;
	}
	cout<<"Regresando al MENU principal ..."<<endl;
}

void calcularTotalVentas(){
	if(ContadorDeVentas<=0){
		cout<<"------------------------------"<<endl;
		cout<<"\nAun no hay ventas registradas"<<endl;
		cout<<endl;
		cout<<"Regresando al MENU principal..."<<endl;
		cout<<endl;
		return;
	}else{
		cout<<"------------------------------------"<<endl; 
		cout<<"-PROCEDIMIENTO DE TOTAL DE VENTAS-"<<endl;
		cout<<"------------------------------------"<<endl;
	
		float total = 0;
	
		for(int i=0; i<ContadorDeVentas; i++){
			total += Ventas[i].Ptotal;
		}
		cout<<"El total que se vendio es: "<<total<<endl;
	
		cout<<endl;
		cout<<"Regresando al MENU principal..."<<endl;
	}
	
}


