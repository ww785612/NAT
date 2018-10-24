#include <fstream>
#include <iostream>
#include "NATTable.h"

using namespace std;

int main() 
{
    NAT natTable;
    int delimiterPos;
    string line;
    ifstream fNAT("NAT");
    while(fNAT>>line)
    {
        delimiterPos = line.find(',') - 0;
        natTable.fillTable(line.substr(0,delimiterPos), line.substr(delimiterPos+1, line.size()-(delimiterPos+1)));
    }
    fNAT.close();

    ifstream fFLOW("FLOW");
    ofstream fResult;
    fResult.open("RESULT.txt");
    
    while(fFLOW>>line)
    {
        fResult<<line<<" -> "<<natTable.translate(line)<<endl;
    }
    fFLOW.close();
    fResult.close();
    return 0;
}