#pragma once

#include <vector>
#include <string>
#include <cstdint>

class BinaryFile
{
private:
    std::vector<uint8_t> data;

public:
    BinaryFile(const std::string& filePath);

    size_t getSize() const;

    uint8_t readByte(size_t offset) const;

    uint16_t readUInt16(size_t offset) const;

    uint32_t readUInt32(size_t offset) const;

    const std::vector<uint8_t>& getData() const;
};