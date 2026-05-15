#include "BinaryFile.h"

#include <fstream>
#include <stdexcept>
#include <iterator>

using namespace std;

BinaryFile::BinaryFile(const string& filePath)
{
    ifstream file(filePath, ios::binary);

    if (!file)
    {
        throw runtime_error("Dosya acilamadi.");
    }

    data = vector<uint8_t>(
        istreambuf_iterator<char>(file),
        istreambuf_iterator<char>()
    );
}

size_t BinaryFile::getSize() const
{
    return data.size();
}

uint8_t BinaryFile::readByte(size_t offset) const
{
    return data[offset];
}

uint16_t BinaryFile::readUInt16(size_t offset) const
{
    return data[offset]
        | (data[offset + 1] << 8);
}

uint32_t BinaryFile::readUInt32(size_t offset) const
{
    return data[offset]
        | (data[offset + 1] << 8)
            | (data[offset + 2] << 16)
            | (data[offset + 3] << 24);
}

const vector<uint8_t>& BinaryFile::getData() const
{
    return data;
}