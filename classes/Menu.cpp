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
            cout << "|                                   [6] - Salvar alteracoes.                                       |" << endl;
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
                    break;
                case 4:         // [4] - Apagar funcionario.
                    break;
                case 5:         // [5] - Atualizar funcionario.
                    break;
                case 6:         // [6] - Salvar alteracoes.
                    break;
            }
        }

        void createFuncionario(){
            
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
                                    
                                    if(create) repository.addPerson(newPerson);
                                    // Se create for True deve-se salvar a nova Pessoa
                                    // caso não deve se cancelar

                                   if(!create) valid = false;
                                }
                            }


                        } else if(code == 2){ //possibles for new Gerente
                            
                            /* create a new Gerente to the system */
                            Person *newPerson = new Gerente;
                            for(int step = 0; step <= 7; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 7){
                                    bool create = this->confirmCode(13);

                                    if(create) repository.addPerson(newPerson);
                                    // Se create for True deve-se salvar a nova Pessoa
                                    // caso não deve se cancelar

                                    if(!create) valid = false;
                                }
                            }

                        } else if(code == 3){ //possibles for new Diretor
                            
                            /* create a new Gerente to the system */
                            Person *newPerson = new Diretor;

                            for(int step = 0; step <= 8; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 8){
                                    bool create = this->confirmCode(14);
                                    
                                    if(create) repository.addPerson(newPerson);
                                    // Se create for True deve-se salvar a nova Pessoa
                                    // caso não deve se cancelar

                                    if(!create) valid = false;
                                }
                            }


                        } else if(code == 4){ //possibles for new Presidente

                         /* create a new Presidente to the system */
                            Person *newPerson = new Presidente;

                            for(int step = 0; step <= 8; step++){
                                newPerson->CreatePersonMenu(step);

                                if(step == 8){
                                    bool create = this->confirmCode(15);
                                    
                                    if(create) repository.addPerson(newPerson);
                                    // Se create for True deve-se salvar a nova Pessoa
                                    // caso não deve se cancelar

                                    if(!create) valid = false;
                                }
                            }

                        } else if(code != 0) valid = false; // the code is 0
                    } else valid = false; // to cancel de de choosen code
                }


            }while(newPerson == 1); //if the user wants to register another person
        }

        void getAllFuncionarios(){
            vector<Person *> Funcionarios = repository.getAll();
            
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;
            cout << "|                                                                                                  |" << endl;


            for(Person *person : Funcionarios)
                cout << "| " << person->getOfficePost() << " " << person->getCode() << " " << person->getName() << " |";

            cout << "|                                                                                                  |" << endl;
            cout << "|--------------------------------------------------------------------------------------------------|" << endl;

            char res;
            cout << "Digite qualquer coisa para voltar";
            cin >> res;
        }
};