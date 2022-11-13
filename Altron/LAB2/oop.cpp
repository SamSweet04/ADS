
#include <iostream>
#include <math.h>

using namespace std;

class Computer{
public:
    string company; 
    string model;
    int year;
    double price;

    Computer(string company, string model, int year, double price){
        this->company = company;
        this->model = model;
        this->year = year;
        this->price = price;
    }

    void updrage(){
        price += 20000;
    }

    void print(){
        cout << company << endl;
        cout << model << endl;
        cout << year << endl;
        cout << price << endl;
    }
};


class Parallelepiped{
    int a, b, c;

public:
    Parallelepiped(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    int volume(){
        return a * b * c;
    }

    int totalArea(){
        return 2 * (a * b) + 2 * (c * b) + 2 * (a * c);
    }

};

int main(){
    Computer macbook("apple", "air", 2020, 550000);

    Computer spectre("spectre", "HP", 2018, 600000);

    Parallelepiped a(1, 2, 3);
    Parallelepiped b(4, 5, 6);
    cout << a.volume() << endl;
    cout << b.totalArea() << endl;

    
}