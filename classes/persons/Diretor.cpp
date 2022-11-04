#include <iostream>
#include <string>
#include "Person.cpp"

using namespace std;


class Diretor : public Person {

    protected:



    public:

        void CreatePersonMenu(int step){

            string value;
            float salary;

            system("CLS");

            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                      Cadastro de Diretor                                         |" << endl;
            cout << "|                                                                                                  |" << endl;
            
            if(step > 0) cout << "|                                    Codigo do Diretor: " << Person::getCode() << endl;
            if(step > 1) cout << "|                                    Nome do Diretor: " << Person::getName() << endl;
            if(step > 2) cout << "|                                    Endereco do Diretor: " << Person::getAdress() << endl;
            if(step > 3) cout << "|                                    Telefone do Diretor: " << Person::getPhone() << endl;
            if(step > 4) cout << "|                                    Data de Inicio do Diretor: " << Person::getStartDate() << endl;
            if(step > 5) cout << "|                                    Salario do Diretor: " << Person::getSalary() << endl;
            if(step > 6) cout << "|                                    Area de Supervisao do Diretor: " << Person::getArea() << endl;
            if(step > 7) cout << "|                                    Area de Formacao do Diretor: " << Person::getFormation() << endl;


            switch(step){
                case 0: // get the code

                    cout << "|" << endl << "|----------------> Digite o codigo do Diretor: ";

                    getchar(); // to clean for the getline
                    getline(cin, value);  // get the code of the new person
                    Person::setCode(value);

                    break;
            
                case 1:

                    cout << "|" << endl << "|----------------> Digite o nome do Diretor: ";

                    getline(cin, value);  // get the name of the new person
                    Person::setName(value);

                    break;
                
                case 2:

                    cout << "|" << endl << "|----------------> Digite o endereco do Diretor: "; 

                    getline(cin, value);  // get the adress of the new person
                    Person::setAdress(value);

                    break;
                
                case 3:

                    cout << "|" << endl << "|----------------> Digite o telefone do Diretor: "; 
                    
                    getline(cin, value);  // get the phone of the new person
                    Person::setPhone(value);

                    break;

                case 4:
                    cout << "|" << endl << "|----------------> Digite a data de inicio do Diretor: "; 

                    getline(cin, value);  // get the startDate of the new person
                    Person::setStartDate(value);

                    break;
                
                case 5:
                    cout << "|" << endl << "|----------------> Digite o salario do Diretor: "; 

                    cin >> salary; // get the salary of the new person
                    Person::setSalary(salary);

                    break;
                
                case 6: // get the area of the new person
                    cout << "|" << endl << "|----------------> Digite a Area de Supervisao do Diretor: "; 

                    getchar();
                    getline(cin, value);
                    this->setArea(value);

                    break; 

                case 7: // get the formation of the new person
                    cout << "|" << endl << "|----------------> Digite a Area de Formacao do Diretor: "; 

                    getline(cin, value);
                    this->setFormation(value);

                    break; 
            }
        }
};