#include <iostream>
#include "ClassOfDevice.h"

int main(int argc, char** argv){
    uint32_t cod_in;
    std::cout << "Enter Class of device in HEX 0x: ";
    std::cin >> std::hex >> cod_in;
    std::cout << "You entered: 0x" << std::hex << cod_in << std::endl;
    ClassOfDevice cod(cod_in);
    cod.PrintClassOfDevice();
   
    return 0;
}
