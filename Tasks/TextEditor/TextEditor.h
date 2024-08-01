#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "../../Data Structures/Stack/stack.h"

class TextEditor{

    private:

        std::string text;
        Stack<std::string> stack_undo;
        Stack<std::string> stack_redo;

    public:

        void undo(){
            if(!stack_undo.isempty()){
            stack_redo.push(text);
            text = stack_undo.top();
            }else{
                std::cout << "Undo is Empty" << std::endl;
            }
        }
        void redo(){
            if(!stack_redo.isempty()){
                stack_undo.push(text);
                text = stack_redo.top();
            }else{
                std::cout << "Redo is Empty" << std::endl;
            }
        }

        void type(){
            std::string new_str;
            std::cout << "Type text: ";
            std::cin.ignore(); // To ignore any leftover newline characters in the input buffer
            std::getline(std::cin, new_str);
            stack_undo.push(text);
            text += new_str;
            // Clear the redo stack since new text was typed
            while (!stack_redo.isempty()) {
                stack_redo.pop();
            }
        }

        void view_text(){
            std::cout << text << std::endl;
        }
};

#endif