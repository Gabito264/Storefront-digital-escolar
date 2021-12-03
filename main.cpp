#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "Client.h"
#include "Package.h"
#include "Product.h"
#include "Fecha.h"

void dispPedido(Package paquetes[], int size){
    if(size >0){
        bool elegido = false;
        int x = 0;
        while (elegido == false){
            cout<<"Elija el paquete del cliente: "<<endl;
            for(int i= 0; i <size; i++){
                if(paquetes[i].getConsumer().getName()!="-"){
                cout<<i+1<<".-"<< endl;
                cout<< paquetes[i].getConsumer().getName()<<endl;
                cout << ""<<endl;
                }
            }
            cin>>x;
            x-=1;
        
            cout<<x<<endl;
            if(0<= x && x<size){
                paquetes[x].print();
                elegido = true;
            }else{
                cout<<"Eleccion no valida"<<endl;
            }
        }
    }else{
        cout<<"No hay nada en la lista!"<<endl;
    }
}
void dispArticulos(Product productos[], int size){
    if(size >0){
    for(int i= 0; i <size; i++){
            if(productos[i].getName()!="-"){
                cout<<i+1<<".-"<< endl;
                productos[i].print();
                cout << ""<<endl;
            }
        }
        }else{
         cout<<"No hay nada en la lista!"<<endl;
     }
}
void dispListPedidos(Package paquetes[], int size){
     if(size >0){
     for(int i= 0; i <size; i++){
            if(paquetes[i].getConsumer().getName()!="-"){
                cout<<i+1<<"--------------------"<< endl;
                paquetes[i].print();
                cout << ""<<endl;
            }
        }
     }else{
         cout<<"No hay nada en la lista!"<<endl;
     }
}




int main(){
    Package paquetes[20];
    Product productos[20];
    Client clientes[20];
    //Crear productos, clientes y paquetes de ejemplo.
    productos[0]= Product("PolyStation","Consola de videojuegos","1280530",19.95,10);
    productos[1] = Product("Mug Root Beer", "Cerveza de Raiz", "115544", 13.45,13);
    int numProduct = 2;
    clientes[0] = Client("Bob Esponja","124 Calle Concha, Fondo de Bikini","555-5555", 35);
    clientes[1] = Client("Dave el loco", "Suburbia", "999-9999", 40);
    int numClientes = 2;
    paquetes[0].setConsumer(clientes[0]);
    paquetes[0].setProducts(productos, (sizeof(productos)/sizeof(*productos)));
    
    paquetes[1].setConsumer(clientes[1]);
    paquetes[1].setProducts(productos, (sizeof(productos)/sizeof(*productos)));
    int numPaquetes = 2;
    int eleccion=0;
    //Se crean variables para guardar variables antes de introducirlas a los objetos
    string name;
    string descripcion;
    string code;
    float price;
    string direccion;
    string phone;
    int age;
    Product carrito[20];
    int numcarrito = 0;
    bool completado = false;
    int choose = 0;
    int cantidad;
    int day;
    int month;
    int year;
    Fecha test = Fecha();
    int ammount;
    //Elegir para las diferentes funciones
    while(eleccion!=7)
    {
        cout<<"Haga su eleccion"<<endl;
        cout<<"1: Alta articulo"<<endl;
        cout<<"2: Alta cliente"<<endl;
        cout<<"3: Alta pedido"<<endl;
        cout<<"4: Mostrar algun pedido"<<endl;
        cout<<"5: Mostrar lista de articulos"<<endl;
        cout<<"6: Mostrar lista de pedidos"<<endl;
        cout<<"7: Terminar"<<endl;
        cin>>eleccion;
        cin.ignore();
        if(eleccion > 7 || eleccion <=0)
        {
            cout<<"Esa opcion no existe, intente de nuevo"<<endl;
            eleccion=0;
        }

        switch(eleccion){
        case 1:
            //Introducir datos del artículo
            if(numProduct<20){
            cout<<"Introduzca el nombre del articulo "<<endl;
            getline(cin,name);
            
            cout<<"Introduzca una descripcion breve"<<endl;
            getline(cin,descripcion);
            
            cout<<"Introduzca un codigo de articulo"<<endl;
            getline(cin,code);
            
            cout<< "Introduzca el precio" <<endl;
            cin>>price;
            cin.ignore();
            cout<< "Introduzca la cantidad de producto" <<endl;
            cin>>cantidad;
            cin.ignore();
            productos[numProduct] = Product(name,descripcion,code,price, cantidad);
            numProduct+=1;
            } else{
                cout<< "Lista de productos llena!"<< endl;
            }

        break;

        case 2:
        //Introducir los datos del cliente
        if(numClientes<20)
            {

                cout<<"Introduzca el nombre del cliente"<< endl;
            getline(cin,name);
                cout<<"Introduzca direccion del cliente"<<endl;
            getline(cin, direccion);
                cout<<"Introduzca numero telefonico"<<endl;
            getline(cin, phone);
                cout<<"Introduzca edad"<<endl;
                cin>> age;
                cin.ignore();
                clientes[numClientes] = Client(name, direccion, phone, age);
                numClientes+=1;
            } else
            {
                cout<< "Lista de clientes llena!"<< endl;
            }
        break;

        case 3:
            //validar si se puede crear un nuevo paquete
            if (numPaquetes<20)
            {
            while (completado == false)
            {
                while (completado == false)
                {
                cout<<"Elija el cliente del paquete"<<endl;
                    for(int i= 0; i <numClientes; i++)
                    {
                    if(clientes[i].getName()!="-")
                        {
                        cout<<i+1<<"--------------------"<< endl;
                        clientes[i].print();
                        }
                    }
                cin>>choose;
                choose-=1;
                    if (0<=choose && choose<numClientes)
                    {
                    
                    paquetes[numPaquetes].setConsumer(clientes[choose]);
                    completado = true;
                    }else
                    {
                    cout<<"No valido, intente de nuevo"<<endl;
                    }
                }
            completado = false;
            choose = 0;
            while(completado == false)
            {
                if(numcarrito < 20){
            cout<<"Elija el producto que quiera agregar, inserte 21 si ya se completo"<<endl;
            
            dispArticulos(productos,numProduct);

            cin>>choose;
            
            //Elegir el artículo a agregar a su carrito
            if(choose != 21)
            {
                choose -= 1;
                if(0<= choose && choose <numProduct)
                {
                    ammount = productos[choose].getAmmount();
                    if(ammount > 0)
                    {
                        carrito[numcarrito] = productos[choose];
                        ammount-= 1;
                        productos[choose].setAmmount(ammount);
                        numcarrito++;
                    } else
                    {
                        cout<< "Ya no hay! intente otro producto"<<endl;
                    }
                } else 
                    {
                        cout<<"eleccion no valida"<<endl;
                    }
            }else
            {
                completado = true;
            }
                }else{
                    cout << "Carrito lleno"<<endl;
                    completado = true;
                } 
        }
            //copiar la lista de productos al objeto del paquete
            paquetes[numPaquetes].setProducts(carrito, numcarrito);
        
        completado = false;
        //Insertar y crear la fecha de entrega
        while(completado == false){
            
            cout<<"Inserte el anio de entrega"<<endl;
            cin>> year;
            cout<<"Inserte el mes de entrega"<<endl;
            cin>> month;
            cout<<"Inserte el dia de entrega"<<endl;
            cin>> day;
            if(day <=30 && day>0){
            if(month > 0 && month<=12){
                test = Fecha(day,month,year);
                completado = true;
            }
            else{
                cout<< "Error con la fecha, intente de nuevo"<<endl;
            }
            } else{
                cout<< "Error con la fecha, intente de nuevo"<<endl;
            }
        }
        paquetes[numPaquetes].setArrivalDate(test);
        cout<<"Paquete creado -----------------------------------------------------------------"<<endl;
        numPaquetes+=1;
            } 

    }else{
                cout<< "No hay espacio para paquetes!"<<endl;
            }
        for(int i = 0; i< numcarrito; i++){
            carrito[i]= Product();
        }

        numcarrito= 0;
        day = 0;
        month = 0;
        year = 0;
        test = Fecha();
        completado = false;
            

        break;

        case 4:
            //Llama a la función para mostrar un pedido
            dispPedido( paquetes, numPaquetes);
        break;

        case 5:
            //Mostrar todos los artículos
            dispArticulos(productos,numProduct);
        break;

        case 6:
            //Llama a la funcion para mostrar todos los pedidos
            dispListPedidos(paquetes, numPaquetes);
        break;
        
        case 7:
        return 0;
        break;

    }    
}

    //Product* arr = x.getProducts();
}