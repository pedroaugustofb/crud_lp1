#include <iostream>
#include <string>
#include <vector>
#include "utils/Repository.cpp"

#include "persons/Person.cpp"
#include "persons/Operador.cpp"
#include "persons/Gerente.cpp"
#include "persons/Diretor.cpp"
#include "persons/Presidente.cpp"

using namespace std;

#pragma once

class Menu {
    private:
        Repository repository;

    public:
        //constructor
        Menu(){};
         
        void printMenu(){ //print the inital menu
            system("CLS");
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                    Cadastro de Funcionarios                                      |" << endl;
            cout << "|                                                                                                  |" << endl;
            cout << "|                                   [0] - Fechar sistema.                                          |" << endl;
            cout << "|                                   [1] - Cadastrar funcionario.                                   |" << endl;
            cout << "|                                   [2] - Consultar funcionarios.                                  |" << endl;
            cout << "|                                   [3] - Consultar funcionarios por tipo.                         |" << endl;
            cout << "|                                   [4] - Apagar funcionario.                                      |" << endl;
            cout << "|                                   [5] - Atualizar funcionario.                                   |" << endl;
            cout << "|                                                                                                  |" << endl;
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;

        }

        //print the confirm menu
        bool confirmCode(int type){
            int confirm;
            do{
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;

                switch(type){
                    case 0: //standart confirm
                cout << "|                                 Por Favor, confirme sua escolha:                                 |" << endl;
                    break;

                    case 1: // first menu [1]
                cout << "|                                  [1] - Cadastrar funcionario?                                    |" << endl;
                    break;

                    case 2: // first menu [2]
                cout << "|                                  [2] - Consultar funcionarios?                                   |" << endl;
                    break;

                    case 3: // first menu [3]
                cout << "|                               [3] - Consultar funcionarios por tipo.                             |" << endl;
                    break;

                    case 4: // first menu [4]
                cout << "|                                     [4] - Apagar funcionario?                                    |" << endl;
                    break;

                    case 5: // first menu [5]
                cout << "|                                   [5] - Atualizar funcionario?                                   |" << endl;
                    break;

                    case 6: // first menu [6]
                cout << "|                                     [6] - Salvar alteracoes?                                     |" << endl;
                    break;

                    case 7: // second menu [0]
                cout << "|                                     [0] - Cancelar Operacao?                                     |" << endl;
                    break;

                    case 8: // second menu [1]
                cout << "|                                    [1] - Cadastrar Operador?                                     |" << endl;
                    break;

                    case 9: // second menu [2]
                cout << "|                                     [2] - Cadastrar Gerente?                                     |" << endl;
                    break;

                    case 10: // second menu [3]
                cout << "|                                     [3] - Cadastrar Diretor?                                     |" << endl;
                    break;

                    case 11: // second menu [4]
                cout << "|                                   [4] - Cadastrar Presidente?                                    |" << endl;
                    break;

                    case 12: // Confimar Cadastrar Operador
                cout << "|                                        Cadastrar Operador?                                       |" << endl;
                    break;

                    case 13: // Confimar Cadastrar Gerente
                cout << "|                                        Cadastrar Gerente?                                        |" << endl;
                    break;

                    case 14: // Confimar Cadastrar Diretor
                cout << "|                                        Cadastrar Diretor?                                        |" << endl;
                    break;

                    case 15: // Confimar Cadastrar Presidente
                cout << "|                                       Cadastrar Presidente?                                      |" << endl;
                    break;

                    case 16: // Deletar Usuario
                cout << "|                                          Deletar Usuario?                                        |" << endl;
                    break;

                    default:
                cout << "|                                             Confimar?                                            |" << endl;
                    break;
                }

                cout << "|                                                                                                  |" << endl;
                cout << "|                             [1] - Confirmar   [2] - Voltar ao menu                               |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cin >> confirm;

                if(confirm != 1 && confirm != 2) confirm = 0; // not valid awanser
                system("CLS"); //responsible to clear de terminal

            }while(confirm == 0);

            if(confirm == 1) return true;
            else return false;
        }

        //to handle the user submit (code from menu)
        void handleSubmit(int code){

            switch(code){
                case 1:         // [1] - Cadastrar funcionario.
                    this->createFuncionario();
                    break;
                case 2:         // [2] - Consultar funcionarios.
                    this->getAllFuncionarios();
                    break;
                case 3:         // [3] - Cosultar funcionarios por tipo.
                    this->getFuncionariosByType();
                    break;
                case 4:         // [4] - Apagar funcionario.
                    this->deleteFuncionario();
                    break;
                case 5:         // [5] - Atualizar funcionario.
                    this->updateFuncionario();
                    break;
            }
        }

        void createFuncionario(){ // to create a new Person
            
            int newPerson = 0; //to create another person

            do{

                bool valid = false; //valid the code of person input

                while(valid == false){
                    valid = true;

                    cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                    cout << "|                                                                                                  |" << endl;
                    cout << "|                            Escolha o tipo de funcionario para cadastrar:                         |" << endl;
                    cout << "|                                                                                                  |" << endl;
                    cout << "|                                     [0] - Cancelar Operacao.                                     |" << endl;
                    cout << "|                                     [1] - Cadastrar Operador.                                    |" << endl;
                    cout << "|                                     [2] - Cadastrar Gerente.                                     |" << endl;
                    cout << "|                                     [3] - Cadastrar Diretor.                                     |" << endl;
                    cout << "|                                     [4] - Cadastrar Presidente.                                  |" << endl;
                    cout << "|                                                                                                  |" << endl;
                    cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                    int code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ",code), code);

                    system("CLS");

                    /* confirm */
                    bool confirm = this->confirmCode(code + 7);

                    if(confirm){

                        if(code == 1){ //possibles for new Operador
                            
                            /* create a new Operador to the system */
                            Person *newPerson = new Operador;
                            for(int step = 0; step <= 6 ; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 6){
                                    bool create = this->confirmCode(12);
                                    if(repository.verifyPersonByCode(newPerson->getCode())){

                                        if(create) repository.addPerson(newPerson);
                                        // Se create for True deve-se salvar a nova Pessoa
                                        // caso não deve se cancelar

                                        if(!create) valid = false;
                                    
                                    }else{
                                        system("CLS");
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|                         Codigo de Funcionario ja existente no sistema.                           |" << endl;
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        system("pause");
                                    }
                                }
                            }


                        } else if(code == 2){ //possibles for new Gerente
                            
                            /* create a new Gerente to the system */
                            Person *newPerson = new Gerente;
                            for(int step = 0; step <= 7; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 7){
                                    bool create = this->confirmCode(13);

                                    if(repository.verifyPersonByCode(newPerson->getCode())){

                                        if(create) repository.addPerson(newPerson);
                                        // Se create for True deve-se salvar a nova Pessoa
                                        // caso não deve se cancelar

                                        if(!create) valid = false;
                                    
                                    }else{
                                        system("CLS");
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|                         Codigo de Funcionario ja existente no sistema.                           |" << endl;
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        system("pause");
                                    }
                                }
                            }

                        } else if(code == 3){ //possibles for new Diretor
                            
                            /* create a new Gerente to the system */
                            Person *newPerson = new Diretor;

                            for(int step = 0; step <= 8; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 8){
                                    bool create = this->confirmCode(14);
                                    if(repository.verifyPersonByCode(newPerson->getCode())){

                                        if(create) repository.addPerson(newPerson);
                                        // Se create for True deve-se salvar a nova Pessoa
                                        // caso não deve se cancelar

                                        if(!create) valid = false;
                                    
                                    }else{
                                        system("CLS");
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|                         Codigo de Funcionario ja existente no sistema.                           |" << endl;
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        system("pause");
                                    }
                                }
                            }


                        } else if(code == 4){ //possibles for new Presidente

                         /* create a new Presidente to the system */
                            Person *newPerson = new Presidente;

                            for(int step = 0; step <= 8; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 8){
                                    bool create = this->confirmCode(15);
                                    
                                    if(repository.verifyPersonByCode(newPerson->getCode())){

                                        if(create) repository.addPerson(newPerson);
                                        // Se create for True deve-se salvar a nova Pessoa
                                        // caso não deve se cancelar

                                        if(!create) valid = false;
                                    
                                    }else{
                                        system("CLS");
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|                         Codigo de Funcionario ja existente no sistema.                           |" << endl;
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        system("pause");
                                    }
                                }
                            }

                        } else if(code != 0) valid = false; // the code is 0
                    } else valid = false; // to cancel de de choosen code
                }


            }while(newPerson == 1); //if the user wants to register another person
        }

        void getAllFuncionarios(){ // to show all funcionarios
            vector<Person *> Funcionarios = repository.getAll();
            
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                                                                                  |" << endl;


            for(Person *person : Funcionarios)
                cout << "| " << person->getOfficePost() << " " << person->getCode() << " " << person->getName() << " |" << endl;

            cout << "|                                                                                                  |" << endl;
            cout << "|--------------------------------------------------------------------------------------------------|" << endl << endl;

            string code;

            getchar();
            getline(cin, code);

            repository.showPersonByCode(code);

            system("pause"); //responsible to pause de terminal
        }

        void getFuncionariosByType(){ // to show funcionarios by type
            
            system("CLS"); //responsible to clear de terminal

            bool valid = false;
            int code;

            while(!valid){

                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                          Escolha o Tipo de Funcionario para consultar.                           |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                                     [0] - Cancelar Operacao.                                     |" << endl;
                cout << "|                                     [1] - Consultar Operador.                                    |" << endl;
                cout << "|                                     [2] - Consultar Gerente.                                     |" << endl;
                cout << "|                                     [3] - Consultar Diretor.                                     |" << endl;
                cout << "|                                     [4] - Consultar Presidente.                                  |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ",code), code);

                if(code > 0 && code <= 4) valid = true;

            }

            string type = "indefinido";

            switch (code){
            case 1:
                type = "Operador";
                break;
            case 2:
                type = "Gerente";
                break;
            case 3:
                type = "Diretor";
                break;
            case 4:
                type = "Presidente";
                break;
            
            default:
                break;
            }

            if(type != "indefinido"){

                vector<Person *> Funcionarios = repository.getByType(type);
                
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;

                if(Funcionarios.size() == 0)
                    cout << "|                        Nenhum Funcionario desse tipo encontrado.                                 |" << endl;

                else for(Person *person : Funcionarios)
                    cout << "| " << person->getOfficePost() << " " << person->getCode() << " " << person->getName() << " |" << endl;

                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl << endl;

                string code;

                getchar();
                getline(cin, code);

                repository.showPersonByCode(code);
                
                system("pause");
            } 

        }

        void deleteFuncionario(){ //menu to delete funcionario 
            
            bool valid = false;
            int code;

            while(!valid){
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                          Escolha o Tipo de Funcionario para consultar.                           |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                                     [0] - Cancelar Operacao.                                     |" << endl;
                cout << "|                                     [1] - Consultar Funcionarios.                                |" << endl;
                cout << "|                                     [2] - Deletar pelo codigo de Funcionario.                    |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ",code), code);

                if(code > 0 && code <= 2) valid = true;
            }
            getchar();

            if(code == 1){
                this->handleSubmit(2);
            
            }else if(code == 2){
                
                
                cout << "|----------------> Digite o codigo do funcionario que deseja deletar: ";
                string personId;
                getline(cin, personId);

                repository.showPersonByCode(personId);

                bool founded = repository.verifyPersonByCode(personId);

                /* confirm */
                if(founded) {
                    bool confirm = this->confirmCode(16);

                    if(confirm)
                        repository.deletePerson(personId);
                }

            }

        }

        void updateFuncionario(){ //menu to update funcionario
            bool valid = false;
            int code;

            system("CLS");

            while(!valid){
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                          Escolha o Tipo de Funcionario para consultar.                           |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                                     [0] - Cancelar Operacao.                                     |" << endl;
                cout << "|                                     [1] - Consultar Funcionarios.                                |" << endl;
                cout << "|                                     [2] - Achar pessoa pelo codigo de Funcionario.               |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ",code), code);

                if(code > 0 && code <= 2) valid = true;
            }
            getchar();


            if(code == 1) this->handleSubmit(2);

            else if(code == 2){

                cout << "|----------------> Digite o codigo do funcionario que deseja alterar: ";
                string personId;
                getline(cin, personId); 

                vector <Person *> Funcionarios = repository.getAll();               

                if(repository.verifyPersonByCode(personId)) // verify if the code is linked with a person in the system.
                    for(Person *person : Funcionarios)    // find the person if the inputed code
                        if(person->getCode() == personId){

                            system("CLS");
                            
                            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                            cout << "|                                                                                                  |" << endl;
                            cout << "| " << person->getOfficePost() << " " << person->getCode() << " " << person->getName() << " |" << endl;
                            cout << "|                                                                                                  |" << endl;
                            cout << "|--------------------------------------------------------------------------------------------------|" << endl;

                            bool validInput = false;
                            int atributeCode;

                            while(!validInput){

                                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                cout << "|                                                                                                  |" << endl;
                                cout << "|                          Escolha o Atributo do Funcionario para alterar.                         |" << endl;
                                cout << "|                                                                                                  |" << endl;
                                cout << "|                                     [0] - Cancelar Operacao.                                     |" << endl;
                                cout << "|                                     [1] - Alterar Codigo.                                        |" << endl;
                                cout << "|                                     [2] - Alterar Nome.                                          |" << endl;
                                cout << "|                                     [3] - Alterar Endereco.                                      |" << endl;
                                cout << "|                                     [4] - Alterar Telefone.                                      |" << endl;
                                cout << "|                                     [5] - Alterar Data de Inicio.                                |" << endl;
                                cout << "|                                     [6] - Alterar Salario.                                       |" << endl;
                                cout << "|                                     [7] - Alterar Cargo.                                         |" << endl;

                                if(person->getOfficePost() == "Gerente"){
                                cout << "|                                     [8] - Alterar Area de Supervisao.                            |" << endl;
                                }
                                if(person->getOfficePost() == "Diretor"){
                                cout << "|                                     [8] - Alterar Area de Supervisao.                            |" << endl;
                                cout << "|                                     [9] - Alterar Area de Formacao.                              |" << endl;
                                }
                                if(person->getOfficePost() == "Presidente"){
                                cout << "|                                     [8] - Alterar Area de Formacao.                              |" << endl;
                                cout << "|                                     [9] - Alterar Area de Formacao Academica Maxima.             |" << endl;
                                }


                                cout << "|                                                                                                  |" << endl;
                                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                atributeCode = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ",atributeCode), atributeCode);


                                if(person->getOfficePost() == "Operador" && code > 0 && code <= 7)
                                    validInput = true;
                                else if(person-> getOfficePost() == "Gerente" && code > 0 && code <= 8)
                                    validInput = true;
                                else if(person-> getOfficePost() == "Diretor" && code > 0 && code <= 9)
                                    validInput = true;
                                else if(person-> getOfficePost() == "Presidente" && code > 0 && code <= 9)
                                    validInput = true;
                            }

                            getchar();
                            string value;
                            int officePostCode;

                            switch(atributeCode){
                                case 1:
                                    cout << "|----------------> Digite o novo codigo: "; 
                                    getline(cin, value);
                                    person->setCode(value);
                                case 2:
                                    cout << "|----------------> Digite o novo nome: "; 
                                    getline(cin, value);
                                    person->setName(value);
                                case 3:
                                    cout << "|----------------> Digite o novo endereco: "; 
                                    getline(cin, value);
                                    person->setAdress(value);
                                case 4:
                                    cout << "|----------------> Digite o novo telefone: "; 
                                    getline(cin, value);
                                    person->setPhone(value);
                                case 5:
                                    cout << "|----------------> Digite a nova data de inicio: "; 
                                    getline(cin, value);
                                    person->setStartDate(value);
                                case 6:
                                    cout << "|----------------> Digite o novo salario: "; 
                                    getline(cin, value);
                                    person->setSalary(value);
                                case 7:

                                    system("CLS");
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|                                        Mudar para:                                               |" << endl;
                                    if(person->getOfficePost() != "Operador")
                                        cout << "|                                     [0] - Operador.                                              |" << endl;
                                    if(person->getOfficePost() != "Gerente")
                                        cout << "|                                     [1] - Gerente.                                               |" << endl;
                                    if(person->getOfficePost() != "Diretor")
                                        cout << "|                                     [2] - Diretor.                                               |" << endl;
                                    if(person->getOfficePost() != "Presidente")
                                        cout << "|                                     [3] - Presidente.                                            |" << endl;
                                        cout << "|                                                                                                  |" << endl;
                                        cout << "|--------------------------------------------------------------------------------------------------|" << endl;

                                    officePostCode = (cin >> (cout << "|----------------> Digite o codigo correspondente ao cargo que deseja: ",officePostCode), officePostCode);

                                    switch (officePostCode){
                                    case 0:
                                        person->setOfficePost("Operador");
                                        break;
                                    case 1:
                                        person->setOfficePost("Gerente");
                                        break;
                                    case 2:
                                        person->setOfficePost("Diretor");
                                        break;
                                    case 3:
                                        person->setOfficePost("Presidente");
                                        break;
                                    
                                    default:
                                        break;
                                    }
                                
                                case 8:
                                    getchar();
                                    if(person->getOfficePost() == "Gerente")
                                        cout << "|----------------> Digite a nova Area de Supervisao: "; 
                                    if(person->getOfficePost() == "Diretor")
                                        cout << "|----------------> Digite a nova Area de Supervisao: "; 
                                    if(person->getOfficePost() == "Presidente")
                                        cout << "|----------------> Digite a nova Area de Formacao: "; 
                                    
                                    getline(cin, value);

                                    if(person->getOfficePost() == "Gerente" || person->getOfficePost() == "Diretor")
                                        person->setArea(value);
                                    else if(person->getOfficePost() == "Presidente")
                                        person->setFormation(value);

                                case 9:
                                    getchar();

                                    if(person->getOfficePost() == "Diretor")
                                        cout << "|----------------> Digite a nova Area de Formacao: "; 
                                    if(person->getOfficePost() == "Presidente")
                                        cout << "|----------------> Digite a nova Area de Formacao Maxima Academica: "; 
                                    
                                    getline(cin, value);

                                    if(person->getOfficePost() == "Diretor")
                                        person->setArea(value);
                                    else if(person->getOfficePost() == "Presidente") 
                                        person->setFormation(value);

                            }


                            repository.updatePerson(person);

                            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                            cout << "|                                                                                                  |" << endl;
                            cout << "|                                      Usuario Atualizado!                                         |" << endl;
                            cout << "|                                                                                                  |" << endl;
                            cout << "|--------------------------------------------------------------------------------------------------|" << endl << endl;

                            system("pause");
                            

                        }
            }
        }
};