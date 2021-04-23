/*
 **************************************************************************************************************************
 * Zachary Hansen Terry: zmht25@gmail.com * https://zmht25.ddns.net/                                                      *
 *                                                                                                                        *
 * This is the 6502 emulator. I made it by watching a tutorial on youtube: https://www.youtube.com/watch?v=qJgsuQoy9bc 
 * Also I used this: http://www.obelisk.me.uk/6502/ resource a lot.   *
 **************************************************************************************************************************
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// The CPU class. Has Byte and Word data types. Has Registers, Program Counter, Stack Pointer.
struct CPU
{
    using Byte = unsigned char; //A unsigned char is 8 bits
    using Word = unsigned short; //A unsigned char is 16 bits. Perfec!

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

    void reset()
    {
        PC = 0xFFFC; // Sets the program counter to $FFFC.
        SP = 0x0100; // Sets the Stack Pointer to $0x0100.
        D = 0;

        A = 0;
        X = 0;
        Y = 0;
    }

};




int main()
{
    CPU cpu;
    cpu.reset();
    return 0;
}