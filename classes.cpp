#include <iostream>
#include <string>
using namespace std;

class cars{
    public: 
    string compmame;
    double price;
    float mileage;

   
    cars(){
        cout << "default constructor" << endl;
    }
    cars(string compname, double price, float mileage){
        this->compmame = compname;
        this->price = price;
        this->mileage = mileage;
    }

    cars(cars &obj){
        cout << "copy constructor " <<  '\n';
        compmame = obj.compmame;
        price = obj.price;
        mileage = obj.mileage;
    }

    void display(){
        cout << "car properties are " << '\n';
        cout << "company name:  " << compmame << '\n';
        cout << "car price: "<< price << '\n';
        cout << "car mileage: "<< mileage << '\n';

    }
};

int main(){
    cars c1, c2("Toyota", 300000, 15.5);
    c1.compmame = "kia";
    c1.price = 450000;
    c1.mileage = 20;

    c1.display();

    cars c3 = c1;
    c3.display();

}