#include <iostream>
#include <string>
#include <vector>
#include "../persons/Person.cpp"
#include "../persons/Operador.cpp"
#include "../persons/Gerente.cpp"
#include "../persons/Diretor.cpp"
#include "../persons/Presidente.cpp"
#include <sstream>
#include <fstream>

using namespace std;

#pragma once

class Repository {
    private:
        vector<Person *> Funcionarios;
        fstream fs;

    public:
        //constructor
        Repository(){
            fs.open("classes/utils/repository.txt", fstream::in); // open file to read
            
            string line;
            vector<string> lines;

            if(fs.is_open()){
                
                while(getline(fs, line)){  //getting all data
                    lines.push_back(line);
                }

                int linesSize = lines.size();

                for(int LineIndex = 0; LineIndex < linesSize; LineIndex++){ // to separate the persons and push_back in Funcionarios vector
                    if(lines[LineIndex] == "Operador"){
                        Person *person = new Operador;
                        person->setCode(lines[LineIndex + 1]); 
                        person->setName(lines[LineIndex + 2]); 
                        person->setAdress(lines[LineIndex + 3]); 
                        person->setPhone(lines[LineIndex + 4]); 
                        person->setStartDate(lines[LineIndex + 5]); 
                        person->setSalary(lines[LineIndex + 6]); 

                        Funcionarios.push_back(person);
                    
                    } else if(lines[LineIndex] == "Gerente"){
                        Person *person = new Gerente;
                        person->setCode(lines[LineIndex + 1]); 
                        person->setName(lines[LineIndex + 2]); 
                        person->setAdress(lines[LineIndex + 3]); 
                        person->setPhone(lines[LineIndex + 4]); 
                        person->setStartDate(lines[LineIndex + 5]); 
                        person->setSalary(lines[LineIndex + 6]);
                        person->setArea(lines[LineIndex + 7]);

                        Funcionarios.push_back(person);

                    } else if(lines[LineIndex] == "Direitor"){
                        Person *person = new Diretor;
                        person->setCode(lines[LineIndex + 1]); 
                        person->setName(lines[LineIndex + 2]); 
                        person->setAdress(lines[LineIndex + 3]); 
                        person->setPhone(lines[LineIndex + 4]); 
                        person->setStartDate(lines[LineIndex + 5]); 
                        person->setSalary(lines[LineIndex + 6]);
                        person->setArea(lines[LineIndex + 7]);
                        person->setFormation(lines[LineIndex + 8]);

                        Funcionarios.push_back(person);

                    } else if(lines[LineIndex] == "Presidente"){
                        Person *person = new Diretor;
                        person->setCode(lines[LineIndex + 1]); 
                        person->setName(lines[LineIndex + 2]); 
                        person->setAdress(lines[LineIndex + 3]); 
                        person->setPhone(lines[LineIndex + 4]); 
                        person->setStartDate(lines[LineIndex + 5]); 
                        person->setSalary(lines[LineIndex + 6]);
                        person->setFormation(lines[LineIndex + 7]);
                        person->setAcademy(lines[LineIndex + 8]);

                        Funcionarios.push_back(person);
                    }
                }

            }

            fs.close();
        };

        void saveRepository(){ //methos responsible to rewrite the repository (txt) basesed in the Funcionarios vector

            this->fs.open("classes/utils/repository.txt", fstream::out); //open file to write

            for(Person *person : Funcionarios){
                string officePost = person->getOfficePost();

                if(officePost == "Operador")
                    this->fs << person->getOfficePost() << endl << person->getCode() << endl << person->getName() << endl << person->getAdress() 
                    << endl << person->getPhone() << endl << person->getStartDate() << endl << person->getSalary() << endl;

                else if(officePost == "Gerente")
                    this->fs << person->getOfficePost() << endl << person->getCode() << endl << person->getName() << endl << person->getAdress() 
                    << endl << person->getPhone() << endl << person->getStartDate() << endl << person->getSalary() << endl << person->getArea() << endl;
                
                else if(officePost == "Diretor")
                    this->fs << person->getOfficePost() << endl << person->getCode() << endl << person->getName() << endl << person->getAdress() 
                    << endl << person->getPhone() << endl << person->getStartDate() << endl << person->getSalary() << endl << person->getArea() << endl << person->getFormation() << endl;
                
                else if(officePost == "Presidente")
                    this->fs << person->getOfficePost() << endl << person->getCode() << endl << person->getName() << endl << person->getAdress() 
                    << endl << person->getPhone() << endl << person->getStartDate() << endl << person->getSalary() << endl << person->getFormation() << endl << person->getAcademy();
            }
        
            this->fs.close();
        }

        void addPerson(Person *person){ //to add and save a new Person in the repository
        
            Funcionarios.push_back(person);
            this->saveRepository();
 
        };

        void deletePerson(string code){

            int PersonIndex = 0;

            for( Person *person : Funcionarios)
                if(person->getCode() == code)
                    break;
                else PersonIndex++;
            
            Funcionarios.erase(Funcionarios.begin() + PersonIndex);
                
            this->saveRepository();

        }

        void updatePerson(Person *person){

            string code = person->getCode();
            int index = 0;

            for(Person *person : Funcionarios)
                if(person->getCode() == code) break;
                else index++;
            
            Funcionarios.erase(Funcionarios.begin() + index);
            Funcionarios.push_back(person);

            this->saveRepository();
        }

        vector <Person *> getAll(){ //method to return all Funcionarios
            return Funcionarios;
        }

        vector <Person *> getByType(string type){ //method to returl all Funcionarios by type (string)
        
            vector <Person *> FilteredFuncionarios;

            for(Person *person : Funcionarios){
                
                string officePost = person->getOfficePost();

                if(officePost == type) FilteredFuncionarios.push_back(person);
            }

            return FilteredFuncionarios;
        }

        void showPersonByCode(string code){
            
            if(this->verifyPersonByCode(code))
                for( Person *person : this->Funcionarios){
                        if(person->getCode() == code ){
                            
                            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                            cout << "|                                                                                                  |" << endl;
                            cout << "|                    Cargo:                      "<< person->getOfficePost() << "                                            |" << endl;
                            cout << "|                    Codigo:                     "<< person->getCode() << "                                            |" << endl;
                            cout << "|                    Nome:                       "<< person->getName() << "                                            |" << endl;
                            cout << "|                    Endereco:                   "<< person->getAdress() << "                                            |" << endl;
                            cout << "|                    Telefone:                   "<< person->getPhone() << "                                            |" << endl;
                            cout << "|                    Data de Inicio:             "<< person->getStartDate() << "                                            |" << endl;
                            cout << "|                    Salario:                    "<< person->getSalary() << "                                            |" << endl;

                            if(person->getOfficePost() == "Gerente")
                                cout << "|                    Area de Supervisao:         "<< person->getArea() << "                                            |" << endl;
                            if(person->getOfficePost() == "Diretor"){
                                cout << "|                    Area de Supervisao:         "<< person->getArea() << "                                            |" << endl;
                                cout << "|                    Area de Formacao:           "<< person->getFormation() << "                                            |" << endl;
                            }
                            if(person->getOfficePost() == "Presidente"){
                                cout << "|                    Area de Formacao:           "<< person->getFormation() << "                                            |" << endl;
                                cout << "|                    Area de Formacao Academica: "<< person->getAcademy() << "                                            |" << endl;
                            }
                            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                            cout << "|                                                                                                  |" << endl;
                
                        }  
                    }
            else cout << "Pessoa nao encontrada." << endl;
                
        }

        bool verifyPersonByCode(string code){

            bool founded = false;

            for( Person *person : Funcionarios)
                if(person->getCode() == code){
                    founded = true;
                }
            
            return founded;
        }
};