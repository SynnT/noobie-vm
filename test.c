#include "vm.h"
#include <stdio.h>
#include <string.h>

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7

extern const char _binary_program_start;
extern const char _binary_program_end;

void print_vm_state(virtual_machine *vm);

int main(void) {
    virtual_machine vm;
    initialize(&vm);

    memcpy(vm.memory, &_binary_program_start, &_binary_program_end - &_binary_program_start);

    do {
        print_vm_state(&vm);       
    } while (execute_next_instruction(&vm));
    
    return 0;
}

void print_vm_state(virtual_machine *vm) {
    printf("0x%08x: ", vm->current_instruction);
    for (int i = 0; i < REGISTERS_COUNT; i++) {
        printf("r%d = 0x%08x ", i, vm->registers[i]);
    }
    printf("\n");  
}
