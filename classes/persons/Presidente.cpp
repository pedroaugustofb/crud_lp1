#include <iostream>
#include <string>
#include "Person.cpp"

using namespace std;

#pragma once

class Presidente : public Person {

    public:

        Presidente(){
            Person::officePost = "Presidente";
        }

        void CreatePersonMenu(int step){

            string value;

            system("CLS");

            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                      Cadastro de Presidente                                         |" << endl;
            cout << "|                                                                                                  |" << endl;
            
            if(step > 0) cout << "|                                    Codigo do Presidente: " << Person::getCode() << endl;
            if(step > 1) cout << "|                                    Nome do Presidente: " << Person::getName() << endl;
            if(step > 2) cout << "|                                    Endereco do Presidente: " << Person::getAdress() << endl;
            if(step > 3) cout << "|                                    Telefone do Presidente: " << Person::getPhone() << endl;
            if(step > 4) cout << "|                                    Data de Inicio do Presidente: " << Person::getStartDate() << endl;
            if(step > 5) cout << "|                                    Salario do Presidente: " << Person::getSalary() << endl;
            if(step > 6) cout << "|                                    Area de Formacao do Presidente: " << Person::getFormation() << endl;
            if(step > 7) cout << "|                                    Area de Formacao Academica Maxima do Presidente: " << Person::getAcademy() << endl;


            switch(step){
                case 0: // get the code

                    cout << "|" << endl << "|----------------> Digite o codigo do Presidente: ";

                    getchar(); // to clean for the getline
                    getline(cin, value);  // get the code of the new person
                    Person::setCode(value);

                    break;
            
                case 1:

                    cout << "|" << endl << "|----------------> Digite o nome do Presidente: ";

                    getline(cin, value);  // get the name of the new person
                    Person::setName(value);

                    break;
                
                case 2:

                    cout << "|" << endl << "|----------------> Digite o endereco do Presidente: "; 

                    getline(cin, value);  // get the adress of the new person
                    Person::setAdress(value);

                    break;
                
                case 3:

                    cout << "|" << endl << "|----------------> Digite o telefone do Presidente: "; 
                    
                    getline(cin, value);  // get the phone of the new person
                    Person::setPhone(value);

                    break;

                case 4:
                    cout << "|" << endl << "|----------------> Digite a data de inicio do Presidente: "; 

                    getline(cin, value);  // get the startDate of the new person
                    Person::setStartDate(value);

                    break;
                
                case 5:
                    cout << "|" << endl << "|----------------> Digite o salario do Presidente: "; 

                    getline(cin, value); // get the salary of the new person
                    Person::setSalary(value);

                    break;
                
                case 6: // get the formation of the new person

                    cout << "|" << endl << "|----------------> Digite a Area de Formacao do Presidente: "; 

                    getline(cin, value);
                    this->setFormation(value);

                    break; 

                case 7: // get the academy of the new person
                    cout << "|" << endl << "|----------------> Digite a Area de Formacao Academica Maxima do Presidente: "; 

                    getline(cin, value);
                    this->setAcademy(value);

                    break; 
            }
        }
};