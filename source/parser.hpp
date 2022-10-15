#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include "func.hpp"
#pragma once

class Parser
{
    public:
        vector<unsigned int> parse(vector< Token > TokensRes)
        {
            // walk through the tokens
            for (int i = 0; i < TokensRes.size(); i++)
            {
                // get this token
                Tokens::TokenList tmpToken = TokensRes[i].TokenRes;
                // get value of token
                string tmpValue = TokensRes[i].ValRes;

                // checking token
                switch (tmpToken)
                {
                    case Tokens::fun:
                        // set function name
                        fun = tmpValue;
                        break;
                    case Tokens::val:
                        // set value of function
                        val = tmpValue;
                        // cheking function
                        if (fun=="push") {
                            bits.push_back(0x5a);
                            bits.push_back(stoi(val));
                        }
                        else if (fun=="nop") {
                            bits.push_back(0x1b);
                        }
                        else {
                            cout << "warning: unknow function <" << fun << ">; skip" << endl;
                        }
                        
                        break;
                    default:
                        break;
                }
            }
            return bits;
        }
    private:
        string text;
        string val;
        string fun;
        vector<unsigned int> bits;
};