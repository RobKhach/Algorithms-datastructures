#include "TextEditor.h"
#include <iostream>

void interface(){
    std::cout << "TextEditor Commands" << std::endl;
    std::cout << "1 --> Type" << std::endl;
    std::cout << "2 --> Udno" << std::endl;
    std::cout << "3 --> Redo" << std::endl;
    std::cout << "4 --> View Text" << std::endl;
    std::cout << "9 --> Exit" << std::endl;
}

int main(){
    TextEditor text;

    int choice = 0;
    while(true){
        interface();
        std::cout << "Enter your Choice ---> ";
        std::cin >> choice;
        std::cout << std::endl;


        switch (choice)
        {
        case 1:
            text.type();
            break;
        case 2:
            text.undo();
            break;
        case 3:
            text.redo();
            break;
        case 4:
            text.view_text();
            break;
        case 9:
            std::cout << "Exiting the text editor." << std::endl;
            return 0;
        default:
            std::cout << "Invalide choice.PLease try again.";
        }

        std::cout << std::endl;

    }
}
