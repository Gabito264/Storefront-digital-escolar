
#ifndef Fecha_h
#define Fecha_h


class Fecha
{
private:
    //variables privadas
    int day,month,year;

public:
    //métodos
    Fecha();
    Fecha(int day, int month, int year);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int getDay();
    int getMonth();
    int setYear();
    void print();
};

Fecha:: Fecha(){
    day = 20;
    month = 4;
    year = 1969;
}
Fecha:: Fecha(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}
void Fecha:: setDay(int day){
    this->day = day;
}
void Fecha:: setMonth(int month){
    this->month = month;
}
void Fecha:: setYear(int year){
    this->year = year;
}
int Fecha:: getDay(){
    return day;
}
int Fecha:: getMonth(){
    return month;
}
int Fecha:: setYear(){
    return year;
}
void Fecha:: print(){
    //imprimir las variables juntos
    cout<<"La fecha de entrega es "<<month <<"/"<< day <<"/" << year<<endl;
}

#endif 