#pragma once

class IParser
{
public:
    virtual void parse() = 0;
    virtual void printReport() const = 0;
    virtual ~IParser() {}
};
