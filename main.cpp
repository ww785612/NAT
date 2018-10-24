#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string p, string s) 
{
    return 1;
}

int main() 
{
    vector<pair<string,string>> NATTable;
    string line;
    int delimiterPos;
    ifstream fNAT("NAT");
    while(fNAT>>line)
    {
        delimiterPos = line.find(',') - 0;
        NATTable.push_back(pair<string,string>(line.substr(0,delimiterPos),
            line.substr(delimiterPos+1, line.size()-(delimiterPos+1))));
    }
    fNAT.close();

    ifstream fFLOW("FLOW");
    ofstream fResult;
    fResult.open("RESULT.txt");
    vector<pair<string,string>>::iterator itNATTable;
    while(fFLOW>>line)
    {
        fResult<<line<<" -> ";
        for(itNATTable = NATTable.begin(); itNATTable != NATTable.end(); ++itNATTable)
        {
            if(isMatch(itNATTable->first, line))
            {
                fResult<<itNATTable->second;
                break;
            }
        }

        if(itNATTable == NATTable.end())
        {
            fResult<<"No nat match";
        }
        fResult<<endl;
    }
    fFLOW.close();
    fResult.close();
    return 0;
}