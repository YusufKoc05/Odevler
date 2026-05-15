#pragma once

#include "IParser.h"
#include "BinaryFile.h"

class ELFParser : public IParser
{
private:
    BinaryFile& file;

    bool is64Bit;
    uint64_t entryPoint;

public:
    ELFParser(BinaryFile& binaryFile);

    void parse() override;
    void printReport() const override;
};