/*LMC.cpp*/
#include "LMC.hpp"
#include <iostream>
#define LMC LittleManComputer

void LMC::loadProgram(int* program, int size){
    if(size > 100)
        throw "Program size limit exceeded (100)";
    for(int i=0;i<size;++i) ram[i]=program[i];
}

bool LMC::isHalted(){
    return halted;
}

void LMC::cycle(){
    if(halted) return;
    fetch();
    execute();
    updateFlags();
    if(programCounter >= 100) hlt();
}

void LMC::fetch(){
    instruction = ram[programCounter++];
    opcode = instruction/100;
    operand = instruction%100;
}

void LMC::execute(){
    switch(opcode){
        case 1: add();break;
        case 2: sub();break;
        case 3: sta();break;
        case 5: lda();break;
        case 6: bra();break;
        case 7: brz();break;
        case 8: brp();break;
        case 9: if(operand == 1) inp();
                else if(operand == 2) out();
                break;
        case 0: if(operand == 0) hlt();
                break;
    }
}

void LMC::updateFlags(){
    if(!accumulator) zero = true;
    else zero = false;
    if(accumulator < 0) negative = true;
    else negative = false;
}

void LMC::add(){
    accumulator += ram[operand];
}
void LMC::sub(){
    accumulator -= ram[operand];
}
void LMC::sta(){
    ram[operand] = accumulator;
}
void LMC::lda(){
    accumulator = ram[operand];
}
void LMC::bra(){
    programCounter = operand;
}
void LMC::brz(){
    if(zero) programCounter = operand;
}
void LMC::brp(){
    if(!negative) programCounter = operand;
}
void LMC::inp(){
    std::cin >> input;
    accumulator = input;
}
void LMC::out(){
    output = accumulator;
    std::cout << output << std::endl;
}
void LMC::hlt(){
    halted = true;
}

#undef LMC
