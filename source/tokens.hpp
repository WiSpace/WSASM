#pragma once

namespace Tokens
{
    enum TokenList
    {
        fun,
        val
    };
};

class Token {
    public:
        Tokens::TokenList TokenRes;
        std::string ValRes;

        Token(Tokens::TokenList Token, std::string val)
        {
            TokenRes = Token;
            ValRes = val;
        }
};
