#include "ELFParser.h"

#include <iostream>
#include <iomanip>

using namespace std;

ELFParser::ELFParser(BinaryFile& binaryFile)
    : file(binaryFile), is64Bit(false), entryPoint(0)
{
}

void ELFParser::parse()
{
    uint8_t elfClass = file.readByte(4);

    if (elfClass == 2)
    {
        is64Bit = true;
    }
    else
    {
        is64Bit = false;
    }

    if (is64Bit)
    {
        entryPoint =
            (uint64_t)file.readUInt32(24)
            |
            ((uint64_t)file.readUInt32(28) << 32);
    }
    else
    {
        entryPoint = file.readUInt32(24);
    }
}

void ELFParser::printReport() const
{
    cout << "Dosya tipi: ELF / Linux Binary" << endl;

    if (is64Bit)
    {
        cout << "Mimari: 64-bit" << endl;
    }
    else
    {
        cout << "Mimari: 32-bit" << endl;
    }

    cout << "Entry Point: 0x"
        << hex << entryPoint << dec << endl;
}