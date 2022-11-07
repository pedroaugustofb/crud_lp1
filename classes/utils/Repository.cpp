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

        void addPerson(Person *person){ //to add and save a new Person in the repository

            this->fs.open("classes/utils/repository.txt", fstream::out); //open file to write

            Funcionarios.push_back(person);

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
        };

        vector <Person *> getAll(){ //method to return all Funcionarios
            return Funcionarios;
        }
};