#include <iostream>
#include <string>
using namespace std;


class Person {

    protected:
    
        string code;
        string name;
        string adress;
        string phone;
        string startDate;
        string officePost;
        float salary;

    public:
        Person(int type){
            switch(type){
                case 1: this->officePost = "Operador";
                case 2: this->officePost = "Gerente";
                case 3: this->officePost = "Diretor";
                case 4: this->officePost = "Presidente";
            }
        };

};