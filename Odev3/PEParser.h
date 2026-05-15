#pragma once

#include "IParser.h"
#include "BinaryFile.h"

#include <string>
#include <vector>

class PEParser : public IParser
{
private:
    BinaryFile& file;

    uint32_t peOffset;
    uint16_t machine;
    uint16_t numberOfSections;
    uint32_t entryPoint;
    uint16_t optionalHeaderSize;

    std::vector<std::string> sectionNames;

public:
    PEParser(BinaryFile& binaryFile);

    void parse() override;
    void printReport() const override;
};