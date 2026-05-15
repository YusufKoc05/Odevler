#include <iostream>
#include "BinaryFile.h"
#include "PEParser.h"
#include "ELFParser.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Kullanim: BinaryAnalyzer.exe dosya_yolu" << endl;
        cout << "Ornek: BinaryAnalyzer.exe C:\\Windows\\System32\\notepad.exe" << endl;
        return 1;
    }

    string filePath = argv[1];

    try
    {
        BinaryFile binary(filePath);

        cout << "Dosya basariyla okundu." << endl;
        cout << "Dosya boyutu: " << binary.getSize() << " byte" << endl;
        cout << endl;

        if (binary.readByte(0) == 'M' && binary.readByte(1) == 'Z')
        {
            PEParser parser(binary);
            parser.parse();
            parser.printReport();
        }
        else if (
            binary.readByte(0) == 0x7F &&
            binary.readByte(1) == 'E' &&
            binary.readByte(2) == 'L' &&
            binary.readByte(3) == 'F')
        {
            ELFParser parser(binary);
            parser.parse();
            parser.printReport();
        }
        else
        {
            cout << "Bilinmeyen dosya tipi." << endl;
        }
    }
    catch (const exception& e)
    {
        cout << "Hata: " << e.what() << endl;
    }

    return 0;
}