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
            cout << "|                                         Bem Vindo                                                |" << endl ;
            cout << "|                                                                                                  |" << endl;
            cout << "|                                   [0] - Fechar sistema.                                          |" << endl;
            cout << "|                                   [1] - Cadastrar funcionario.                                   |" << endl;
            cout << "|                                   [2] - Consultar funcionarios.                                  |" << endl;
            cout << "|                                   [3] - Consultar funcionarios por tipo.                         |" << endl;
            cout << "|                                   [4] - Apagar funcionario.                                      |" << endl;
            cout << "|                                   [5] - Atualizar funcionario.                                   |" << endl;
            cout << "|                                   [6] - Salvar alteracoes.                                       |" << endl;
            cout << "|                                                                                                  |" << endl;
            cout << "|--------------------------------------------------------------------------------------------------|" << endl << endl;
            cout << "|----------------> Digite o codigo correspondente a operacao que deseja: "; 
        }

        //print the confirm menu
        int confirmCode(){
            int confirm;
            do{
                cout << "|--------------------------------------------------------------------------------------------------|" << endl;
                cout << "|                                                                                                  |" << endl;
                cout << "|                                 Por Favor, confirme sua escolha:                                 |" << endl;
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
                    int code;

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
                    cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ";

                    cin >> code; // get user choose

                    system("CLS");

                    /* confirm */
                    int confirm = this->confirmCode();

                    if(confirm == 1){
                        switch(code){
                            case 0: 
                                valid = true;
                                break;
                            default:
                                break;
                        } 
                    }
                }


            }while(newPerson == 1); //if the user wants to register another person
        }

};

