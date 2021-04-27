/*LMC.hpp*/
#ifndef _LITTLEMANCOMPUTER_
#define _LITTLEMANCOMPUTER_

class LittleManComputer{
    private:
    //flags
    bool negative{false};
    bool zero{false};
    bool halted{false};
    
    //registers/memory
    int ram[100];
    int accumulator{0};
    int programCounter{0};
    int input{0};
    int output{0};
    
    //instruction/pieces of instruction
    int instruction{0};
    int opcode{0};
    int operand{0};
    
    public:
    LittleManComputer(){}
    void loadProgram(int * program, int size);
    void cycle();
    bool isHalted();
    
    private:
    void updateFlags();
    void fetch();
    void execute();
    void add();
    void sub();
    void sta();
    void lda();
    void bra();
    void brz();
    void brp();
    void inp();
    void out();
    void hlt();
};
#endif
