#include "NATTable.h"

void NAT::fillTable(string pattern, string target)
{
    table.push_back(pair<string,string>(pattern,target));
}

string NAT::translate(string& address)
{
    vector<pair<string,string>>::iterator itTable;
    for(itTable = table.begin(); itTable != table.end(); ++itTable)
    {
        if(isMatch(itTable->first, address))
        {
            return itTable->second;
        }
    }
    return "no match found";
}

bool NAT::isMatch(string p, string s)
{
    vector<vector<bool>> matchMatrix(p.size()+1, vector<bool> (s.size()+1, false));
    
    matchMatrix[0][0] = true;
    for(int ip=1; ip<=p.size(); ip++)
    {
        if(p[ip-1] == '*')
        {
            matchMatrix[ip][0] = matchMatrix[ip-1][0];
        }
    }
    
    for(int ip=1; ip<=p.size(); ip++)
    {
        for(int is=1; is<=s.size(); is++)
        {
            matchMatrix[ip][is] = (p[ip-1]=='*' && matchMatrix[ip-1][is]) || 
                                    (p[ip-1]=='*' && matchMatrix[ip][is-1]) || 
                                    ((p[ip-1] == s[is-1] || p[ip-1]=='?' || p[ip-1]=='*') && matchMatrix[ip-1][is-1]);
        }
    }
    return matchMatrix[p.size()][s.size()];
}