#include <iostream>
#include "func.hpp"
#pragma once

vector<string> split(string str, char symbol)
{
    string buff;
    vector<string> res_r;

    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]==symbol)
        {
            res_r.push_back(buff);
            buff = "";
        }
        else {
            buff += str[i];
        }
    }
    res_r.push_back(buff);

    return res_r;
};

bool in(vector<string> vect, string find)
{
    for (int i = 0; i<vect.size(); i++)
    {
        if (vect[i]==find)
        {
            return true;
        }
    }
    return false;
}

class Lexer
{
    public:
        vector< Token > lex(string code)
        {
            // read all code
            vector<string> lines = split(code, '\n');
            // cout << lines.at(0) << " >> " << lines.at(1) << endl;
            // cout << lines.size() << endl;

            for (int l = 0; l<lines.size(); l++)
            {
                // this line
                string line = lines[l];
                // cout << line << endl;
                vector<string> words = split(line, ' ');
                // cout << words.size() << endl;
                
                for (int w = 0; w<words.size(); w++)
                {
                    string word = words[w];
                    cout << word << endl;
                    cout << "NOW IS " << now << endl;
                    
                    if ( now=="fun" )
                    {
                        cout << "fun add" << endl;
                        Token tmptoken = Token(Tokens::fun, word);
                        TokensRes.push_back(tmptoken);

                        // if (!in(fun_hasnt_val, word))
                        //  {
                            now = "val";
                        // }
                    }
                    else
                    {
                        cout << "val add" << endl;
                        Token tmptoken = Token(Tokens::val, word);
                        TokensRes.push_back(tmptoken);
                        now = "fun";
                    }
                }
            }
            return TokensRes;
        }
    private:
        char* now = "fun";
        vector< Token > TokensRes;
        vector< string > fun_hasnt_val = {"nop"};
};
