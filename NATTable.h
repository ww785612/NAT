#ifndef NATTABLE_H
#define NATTABLE_H 1

#include <vector>
#include <string>

using namespace std;

class NAT
{
public:
    void fillTable(string pattern, string target);
    string translate(string& address);

private:
    vector<pair<string,string>> table;

    bool isMatch(string p, string s);
};

#endif