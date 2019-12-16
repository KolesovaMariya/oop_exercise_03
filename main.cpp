#include <iostream>
#include <vector>
#include <fstream>

#include "triangle.h"
#include "square.h"
#include "octagon.h"

int main() {
    std::ifstream in(R"(C:\Users\LENOVO\CLionProjects\OOP\lab3\test_02.txt)");
    std::cin.rdbuf(in.rdbuf());
    std::string command;
    std::vector<figure*> figures;
    while(std::cin >> command) {
        bool flag = true;
        if (command == "exit") {
            break;
        } else if (command == "add") {
            std::string figure_type;
            std::cin >> figure_type;
            figure *ptr;
            if (figure_type == "triangle") {
                ptr = new triangle(std::cin);
            } else if (figure_type == "square") {
                ptr = new square(std::cin);
            } else if(figure_type == "octagon") {
                ptr = new octagon(std::cin);
            } else {
                std::cout << "Invalid input" << std::endl;
                flag = false;
            }
            if(flag && ptr -> is_figure()) {
                figures.push_back(ptr);
                std::cout << "The figure ";
                ptr->print(std::cout);
                std::cout << " was successfully added;" << std::endl;
            }
            if(!ptr->is_figure()) {
                std::cout <<"The figure ";
                ptr->print(std::cout);
                std::cout << " isn't a triangle, square or octagon;" << std::endl;
            }

        } else if (command == "delete") {
            int i;
            std::cin >> i;
            delete figures[i];
            figures.erase(figures.begin() + i);
            std::cout << "Deleted by index " << i << ";" <<  std::endl;
        } else if (command == "areas") {
            std::cout << "Areas " << std::endl;
            for(figure *elem : figures) {
                elem -> print(std::cout);
                std::cout << " Area: " <<  elem->area() << std::endl;
            }
        } else if (command == "centers") {
            std::cout << "Centers " << std::endl;
            for (figure *elem : figures) {
                elem -> print(std::cout);
                std::cout << " Center: " << elem->center() << std::endl;
            }
        } else if (command == "figures") {
            std::cout << "Figures: " << std::endl;
            for (figure *elem : figures) {
                elem->print(std::cout);
                std::cout << std::endl;
            }
        } else if(command == "print") {

            for (figure *elem : figures) {
                elem->print(std::cout);
                std::cout << "; Center: " << elem->center() << "; Area: " << elem->area() << ";" << std::endl;
            }
        } else if (command == "destroy") {
            while(!figures.empty()) {
                delete figures[0];
                figures.erase(figures.begin());
            }
            std::cout << "All figures are destroyed;" << std::endl;
        } else if (command == "help") {
            std::cout << "The program works with figures: triangle, square, octagon.\n "
                         "Available command: \n"
                         "exit - finish the program;\n"
                         "add triangle/ square/ octagon - add figure;\n"
                         "delete i - delete by index i;\n"
                         "areas - output the areas of all figures;\n"
                         "centers - output the centers of all figures;\n"
                         "figures - output all the figures;\n"
                         "print - output all the figures, their areas and centers;\n"
                         "destroy - destroy all the figures;\n";
        }
    }
}