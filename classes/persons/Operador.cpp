#include <iostream>
#include <string>
#include "Person.cpp"

using namespace std;


class Operador : public Person {


    public:

        void CreatePersonMenu(int step){

            string value;
            float salary;

            system("CLS");
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                      Cadastro de Operador                                        |" << endl;
            cout << "|                                                                                                  |" << endl;

            if(step > 0) cout << "|                                    Codigo do Operador: " << Person::getCode() << endl;
            if(step > 1) cout << "|                                    Nome do Operador: " << Person::getName() << endl;
            if(step > 2) cout << "|                                    Endereco do Operador: " << Person::getAdress() << endl;
            if(step > 3) cout << "|                                    Telefone do Operador: " << Person::getPhone() << endl;
            if(step > 4) cout << "|                                    Data de Inicio do Operador: " << Person::getStartDate() << endl;
            if(step > 5) cout << "|                                    Salario do Operador: " << Person::getSalary() << endl;

            switch(step){

                case 0: // get the code

                    cout << "|" << endl << "|----------------> Digite o codigo do Operador: ";

                    getchar(); // to clean for the getline
                    getline(cin, value);  // get the code of the new person
                    Person::setCode(value);

                    break;
            
                case 1:

                    cout << "|" << endl << "|----------------> Digite o nome do Operador: ";

                    getline(cin, value);  // get the name of the new person
                    Person::setName(value);

                    break;
                
                case 2:

                    cout << "|" << endl << "|----------------> Digite o endereco do Operador: "; 

                    getline(cin, value);  // get the adress of the new person
                    Person::setAdress(value);

                    break;
                
                case 3:

                    cout << "|" << endl << "|----------------> Digite o telefone do Operador: "; 
                    
                    getline(cin, value);  // get the phone of the new person
                    Person::setPhone(value);

                    break;

                case 4:
                    cout << "|" << endl << "|----------------> Digite a data de inicio do Operador: "; 

                    getline(cin, value);  // get the startDate of the new person
                    Person::setStartDate(value);

                    break;
                
                case 5:
                    cout << "|" << endl << "|----------------> Digite o salario do Operador: "; 

                    cin >> salary; // get the salary of the new person
                    Person::setSalary(salary);

                    break;
            }
        }
};