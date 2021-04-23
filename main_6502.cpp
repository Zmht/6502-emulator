/*
 **************************************************************************************************************************
 * Zachary Hansen Terry: zmht25@gmail.com * https://zmht25.ddns.net/                                                      *
 *                                                                                                                        *
 * This is the 6502 emulator. I made it by watching a tutorial on youtube: https://www.youtube.com/watch?v=qJgsuQoy9bc    *
 * Also I used this: http://www.obelisk.me.uk/6502/ resource a lot.                                                       *
 **************************************************************************************************************************
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char; //A unsigned char is 8 bits
using Word = unsigned short; //A unsigned char is 16 bits. Perfec!
using u32 = unsigned int; //

// A class to represent the memory that the computer needs
struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    // Sets all of the memory adresses to 0.
    void initialise()
    {
        for (u32 i = 0; i < MAX_MEM; i++){
            Data[i] = 0;
        }
    }

    // Reads on byte from memory.
    Byte operator[](u32 Address) const
    {
        // Adress has to be less than MAX_MEM
        return Data[Address];
    }

    // Writes on byte to memory.
    Byte& operator[](u32 Address) 
    {
        // Adress has to be less than MAX_MEM
        return Data[Address];
    }
};


// The CPU class. Has Byte and Word data types. Has Registers, Program Counter, Stack Pointer.
struct CPU
{
    

    Word PC; // The program counter tells you what the next program to run is (16 bit)
    Word SP; // The stack pointer is a 16 bit piece of information that tells you where you were on the 
    
    Byte A, X, Y; //A, X, and Y registers.

    // These are the status flags
    Byte C : 1; // Carry flag.
    Byte Z : 1; // Zero Flag
    Byte I : 1; // Interrupt Disable
    Byte D : 1; // Decimal Bit
    Byte B : 1; // Break Command
    Byte V : 1; // Overflow Flag
    Byte N : 1; // Negative Flag

    // Resests the CPU and inits the memory.
    void reset(Mem& memory)
    {
        PC = 0xFFFC; // Sets the program counter to $FFFC.
        SP = 0x0100; // Sets the Stack Pointer to $0x0100.
        C = Z = I = D = B = V = N = 0; // Sets the flags to 0.
        A = X = Y = 0; // Sets the A, X, and Y registers to 0.
       memory.initialise();
    }

    // Fetches a byte of data from the memory.
    Byte FetchByte(u32& Cycles, Mem& memory)
    {
        Byte Data = memory[PC];
        PC++;
        Cycles--;
        return Data;
    }

    // Op Codes
    static constexpr Byte INS_LDA_IM = 0xA9; //Load A immediate mode.

    void execute(u32 Cycles, Mem& memory)
    {
        while(Cycles > 0)
        {
            Byte Ins = FetchByte(Cycles, memory);  // Uses Fetch
            switch (Ins)
            {
            case INS_LDA_IM:
            {
                Byte Value = FetchByte(Cycles, memory);
                A = Value;
                Z = (A == 0);
                N = (A & 0b10000000) > 0;
            } break;
            default:
            {
                printf("Instruction not handled %d", Ins);
            } break;
                
            }
        }
    }
};




int main()
{
    Mem mem;
    CPU cpu;
    cpu.reset(mem);
    // A little program (start)
    mem[0xFFFC] = CPU::INS_LDA_IM;
    mem[0xFFFD] = 0x42;
    // End of a little program
    cpu.execute(2, mem);
    return 0;
}