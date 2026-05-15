#include "PEParser.h"
#include "MalwareAnalyzer.h"

#include <iostream>
#include <iomanip>

using namespace std;

PEParser::PEParser(BinaryFile& binaryFile)
    : file(binaryFile), peOffset(0), machine(0),
    numberOfSections(0), entryPoint(0), optionalHeaderSize(0)
{
}

void PEParser::parse()
{
    peOffset = file.readUInt32(0x3C);

    machine = file.readUInt16(peOffset + 4);
    numberOfSections = file.readUInt16(peOffset + 6);
    optionalHeaderSize = file.readUInt16(peOffset + 20);
    entryPoint = file.readUInt32(peOffset + 40);

    uint32_t sectionTableOffset = peOffset + 24 + optionalHeaderSize;

    sectionNames.clear();

    for (int i = 0; i < numberOfSections; i++)
    {
        uint32_t sectionOffset = sectionTableOffset + (i * 40);

        string name = "";

        for (int j = 0; j < 8; j++)
        {
            char c = file.readByte(sectionOffset + j);

            if (c != '\0')
            {
                name += c;
            }
        }

        sectionNames.push_back(name);
    }
}

void PEParser::printReport() const
{
    cout << "Dosya tipi: PE / Windows EXE-DLL" << endl;
    cout << "PE Header Offset: 0x" << hex << peOffset << dec << endl;
    cout << "Machine Type: 0x" << hex << machine << dec << endl;
    cout << "Section sayisi: " << numberOfSections << endl;
    cout << "Entry Point: 0x" << hex << entryPoint << dec << endl;
    cout << "Optional Header Size: " << optionalHeaderSize << " byte" << endl;

    cout << endl;
    cout << "Sections:" << endl;

    for (const string& section : sectionNames)
    {
        cout << "- " << section << endl;
    }

    MalwareAnalyzer::analyze(sectionNames, file.getData());
}