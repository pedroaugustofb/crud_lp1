#include <iostream>
#include "classes/Menu.cpp"

using namespace std;


int main(){
    Menu menu;

    while(true){

        /* to get the operation*/
        menu.printMenu(); //responsible to print the initial menu

        int code; //the choosen code from the user
        cin >> code; //get the choosen code

        system("CLS"); //responsible to clear de terminal
        if(code == 0) break; //exit the system when user choose 0 on menu.


        /* to confirm */
        int confirm = menu.confirmCode(); //confirm or not the code


        /* to handle submit */
        if(confirm == 1) menu.handleSubmit(code); //if the code it was confirmed
        
    }

    return 0;
}