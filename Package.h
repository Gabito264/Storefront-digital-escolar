
#ifndef Package_h
#define Package_h

#include "Client.h"
#include "Product.h"
#include "Fecha.h"
#include <string.h>

class Package
{
private:
    //variables privadas
    Product products[20];
    Client consumer;
    Fecha arrivalDate;
    int size;
public:
    //métodos 
    Package();
    Package(Product products[], int size, Client consumer, Fecha arrivalDate);
    void setProducts(Product products[], int size);
    void setConsumer(Client consumer);
    void setArrivalDate(Fecha arrivalDate);
    Product* getProducts();
    Client getConsumer();
    Fecha getArrivalDate();
    void print();
};
    Package:: Package(){
        consumer = Client();
        arrivalDate = Fecha();
        size = 20;
    }
    Package:: Package(Product products2[],int size, Client consumer, Fecha arrivalDate){
        for( int i = 0; i < size; i++){
            products[i] = products2[i];
        }
        this-> consumer = consumer;
        this-> arrivalDate = arrivalDate;
        this->size = size;
    }
    void Package:: setProducts(Product products2[], int size){
        for( int i = 0; i < size; i++){
            products[i] = products2[i];
        }
        this-> size= size;
    }
    void Package:: setConsumer(Client consumer){
        this-> consumer = consumer;
    }
    void Package:: setArrivalDate(Fecha arrivalDate){
        this-> arrivalDate = arrivalDate;
    }
    Product* Package:: getProducts(){
        return products;
    }
    Client Package:: getConsumer(){
        return consumer;
    }
    Fecha Package:: getArrivalDate(){
        return arrivalDate;
    }
    void Package:: print(){
        //imprimir toda la lista del paquete dada size, o numCarrito, junto con el total
        consumer.print();
        arrivalDate.print();
        float total=0;
        for(int i= 0; i <size; i++){
            if(products[i].getName()!="-"){
                cout<<i+1<<".-"<< endl;
                products[i].print();
                total += products[i].getPrice();
            }
        }
        cout<< "Total: $ " << total<<endl;
    }
    //setter size


#endif 