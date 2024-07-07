#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 65536 // memory 64k

uint8_t memory[MEMORY_SIZE]; // main memory
uint8_t A, X, Y; // Registers
uint16_t PC; // Program counter
uint8_t SP; // Stack pointer
uint8_t status; // register status

void initialize();
void execute();

int main()
{
    initialize();
    execute();
    return 0;
}

void initialize()
{
    PC = 0x0600; // Initializes PC with tipical address
    SP = 0xFF; // Initializes Stack Pointer
    A = X = Y = 0; // Reset registers
    status = 0; // Reset registry status
    printf("Emulador inicializado. \n");
}

void execute()
{
    printf("Executando emulador...\n");
    uint8_t opcode;

    while (1)
    {
        opcode = memory[PC]; // Search opcode in a currente position of PC
        switch (opcode)
        {
        case 0xA9: // LDA Immediate
            A = memory[PC + 1]; // Load next byte in memory in register A
            PC += 2; // Move PC to next intruction
            break;
        default:
            printf("Opcode not implemented: %02x\n", opcode);
            return; // End loop if opcode not reconized

        }
    }
}