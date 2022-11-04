#include <iostream>
#include "classes/Menu.cpp"

using namespace std;


int main(){
    Menu menu;

    while(true){

        /* to get the operation*/
        menu.printMenu(); //responsible to print the initial menu
        int code = (cin >> (cout << "|----------------> Digite o codigo correspondente a operacao que deseja: ", code), code); // responsible to get code from the user.
        

        system("CLS"); //responsible to clear de terminal

        if(code == 0) break; //exit the system when user choose 0 on menu.

        /* to confirm */
        bool confirm = menu.confirmCode(code); //confirm or not the code


        /* to handle submit */
        if(confirm) menu.handleSubmit(code); //if the code it was confirmed
        
    }

    return 0;
}