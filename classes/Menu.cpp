#include <iostream>
#include <string>
#include "persons/Person.cpp"

using namespace std;


class Menu {
    private:

    public:
        //constructor
        Menu(){};
         
        //print the inital menu
        void printMenu(){
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
        int confirmCode(int type){
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

                }

                cout << "|                                                                                                  |" << endl;
                cout << "|                             [1] - Confirmar   [2] - Voltar ao menu                               |" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cin >> confirm;

                if(confirm != 1 && confirm != 2) confirm = 0; // not valid awanser
                system("CLS"); //responsible to clear de terminal

            }while(confirm == 0);

            return confirm;
        }

        //to handle the user submit (code from menu)
        void handleSubmit(int code){

            switch(code){
                case 1:         // [1] - Cadastrar funcionario.
                    this->cadastrarFuncionario();
                    break;
                case 2:         // [2] - Cadastrar funcionarios.
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

        void cadastrarFuncionario(){
            
            int personType; //new person type
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
                    int code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ", code), code);

                    system("CLS");

                    /* confirm */
                    int confirm = this->confirmCode(code + 7);

                    if(confirm == 1){

                        if(code == 1 || code == 2 || code == 3 || code == 4){ //possibles for new Person
                            
                            /* create a new person to the system */
                            Person newPerson = Person(code);



                        } else if(code != 0) valid = false; // the code is 0
                    } else valid = false; // to cancel de de choosen code
                }


            }while(newPerson == 1); //if the user wants to register another person
        }

};

