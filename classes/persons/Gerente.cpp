#include <iostream>
#include <string>
#include "Person.cpp"

using namespace std;

#pragma once

class Gerente : public Person {

    public:

        Gerente(){
            Person::officePost = "Gerente";
        }

        void CreatePersonMenu(int step){

            string value;

            system("CLS");

            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                      Cadastro de Gerente                                         |" << endl;
            cout << "|                                                                                                  |" << endl;
            
            if(step > 0) cout << "|                                    Codigo do Gerente: " << Person::getCode() << endl;
            if(step > 1) cout << "|                                    Nome do Gerente: " << Person::getName() << endl;
            if(step > 2) cout << "|                                    Endereco do Gerente: " << Person::getAdress() << endl;
            if(step > 3) cout << "|                                    Telefone do Gerente: " << Person::getPhone() << endl;
            if(step > 4) cout << "|                                    Data de Inicio do Gerente: " << Person::getStartDate() << endl;
            if(step > 5) cout << "|                                    Salario do Gerente: " << Person::getSalary() << endl;
            if(step > 6) cout << "|                                    Area de Supervisao do Gerente: " << Person::getArea() << endl;

            switch(step){
                case 0: // get the code

                    cout << "|" << endl << "|----------------> Digite o codigo do Gerente: ";

                    getchar(); // to clean for the getline
                    getline(cin, value);  // get the code of the new person
                    Person::setCode(value);

                    break;
            
                case 1:

                    cout << "|" << endl << "|----------------> Digite o nome do Gerente: ";

                    getline(cin, value);  // get the name of the new person
                    Person::setName(value);

                    break;
                
                case 2:

                    cout << "|" << endl << "|----------------> Digite o endereco do Gerente: "; 

                    getline(cin, value);  // get the adress of the new person
                    Person::setAdress(value);

                    break;
                
                case 3:

                    cout << "|" << endl << "|----------------> Digite o telefone do Gerente: "; 
                    
                    getline(cin, value);  // get the phone of the new person
                    Person::setPhone(value);

                    break;

                case 4:
                    cout << "|" << endl << "|----------------> Digite a data de inicio do Gerente: "; 

                    getline(cin, value);  // get the startDate of the new person
                    Person::setStartDate(value);

                    break;
                
                case 5:
                    cout << "|" << endl << "|----------------> Digite o salario do Gerente: "; 

                    getline(cin, value); // get the salary of the new person
                    Person::setSalary(value);

                    break;
                
                case 6: // get the area of the new person
                    cout << "|" << endl << "|----------------> Digite a Area de Supervisao do Gerente: "; 

                    getline(cin, value);
                    this->setArea(value);

                    break; 
            }
        }
};