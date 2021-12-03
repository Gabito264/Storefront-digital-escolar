
#ifndef Client_h
#define Client_h

#include <string.h>

class Client
{
private:
   //variables privadas
   std::string name, address, phone;
   int age; 
    
public:
    //métodos
    Client();
    Client(std::string name, std::string address, std::string phone, int age);
    void setName(std::string name);
    void setAddress(std::string address);
    void setPhone(std::string phone);
    void setAge(int age);
    std::string getName();
    std::string getAddress();
    std::string getPhone();
    int getAge();
    void print();
};

Client:: Client(){
    name = "-";
    address= "-";
    phone = "-";
    age = 0;
    
}
Client:: Client(std::string name, std::string address, std::string phone, int age){
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->age = age;
}
void Client:: setName(std::string name){
    this->name = name;
}
void Client:: setAddress(std::string address){
    this->address = address;
}
void Client:: setPhone(std::string phone){
    this->phone = phone;
}
void Client:: setAge(int age){
    this->age = age;
}
std::string Client:: getName(){
    return name;
}
std::string Client:: getAddress(){
    return address;
}
std::string Client:: getPhone(){
    return phone;
}
int Client:: getAge(){
    return age;
}
void Client:: print(){
    //imprimir las variables juntos
    cout<< "El cliente se llama " <<name <<endl;
    cout<< "Con direccion " << address<<endl;
    cout<< "y telefono " << phone <<endl;
    cout<< "Edad de "<< age<<endl;
}


#endif 