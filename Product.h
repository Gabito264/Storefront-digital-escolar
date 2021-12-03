
#ifndef Product_h
#define Product_h
#include <string.h>

class Product
{
private:
    //variables privadas
    std::string name, description, code;
    int ammount;
    float price;
public:
    //métodos
    Product();
    Product(std::string name, std::string description, std::string code, float price, int ammount);
    void setName(std::string name );
    void setDescription(std::string description);
    void setCode(std::string code);
    void setPrice(float price);
    float getPrice();
    std::string getName();
    std::string getDescription();
    std::string getCode();
    void print();
    void setAmmount(int ammount);
    int getAmmount();
};
    
    Product:: Product(){
        name = "-";
        description = "-";
        code = "-";
        price = 0;
        ammount = 0;
    }
    Product:: Product(std::string name, std::string description, std::string code, float price, int ammount){
        this->name = name;
        this->description = description;
        this->code = code;
        this->price = price;
        this->ammount = ammount;
    }
    void Product:: setName(std::string name ){
        this->name = name;
    }
    void Product:: setDescription(std::string description){
        this->description = description;
    }
    void Product:: setCode(std::string code){
        this->code = code;
    }
    std::string Product:: getName(){
        return name;
    }
    std::string Product:: getDescription(){
        return description;
    }
    std::string Product:: getCode(){
        return code;
    }
    void Product:: print(){
       //imprimir las variables juntos
        cout<< "Producto: " << name << endl;
        cout<< "Descripcion: " << description << endl;
        cout<< "Codigo: " << code <<endl;
        cout<< "Precio: " << price <<endl;
        //cout<<"Cantidad disponible al momento: "<<ammount<<endl;
    }
    void Product:: setPrice(float price){
        this->price = price;
    }
    float Product:: getPrice(){
        return price;
    }
    int Product:: getAmmount(){
        return ammount;
    }
    void Product:: setAmmount(int ammount){
        this->ammount = ammount;
    }
#endif 