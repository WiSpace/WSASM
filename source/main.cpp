#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "lexer.hpp"
#include "func.hpp"
#include "parser.hpp"

void write(vector<unsigned int> bits) {
    FILE *output = fopen("output.exe", "wb");
    fclose(output);
    output = fopen("output.exe", "a+");
    cout << bits.size() << endl;
    for (int i=0; i<bits.size(); i++)
    {
        unsigned int bit = bits[i];
        printf("%d", bit);
        fwrite(&bit, sizeof(bit), 1, output);
    }
    fclose(output);
}

int main(int argc, char* argv[]) 
{
    if ( argc == 1 )
    {
        cout << "ERROR: No first argument (path to file)" << endl;
        system("pause");
        return 0;
    }

    // path to file
    string path = argv[1];

    // file
    ifstream fin(path);

    // if can't open the file
    if ( !fin.is_open() )
    {
        cout << "ERROR: Can't open file \"" << path << "\"!" << endl;
        system("pause");
        return 0;
    }
    // Read file
    string buff;
    string res;

    // read all file
    while( !fin.eof() )
    {
        getline( fin, buff );
        res += buff;
        if ( !fin.eof() ) {
            res += '\n';
        }
    }
    // close file
    fin.close();

    // Lexer
    Lexer lex;
    // Parser
    Parser parse;

    // get tokens
    vector< Token > TokensRes = lex.lex(res);

    for (int i = 0; i<TokensRes.size(); i++)
        cout << TokensRes[i].TokenRes << " : " << TokensRes[i].ValRes << endl;
    // vector<unsigned int> bits = {0x5b, 0x6a};
    // char c2 = static_cast<char>(bits.at(0));

    // parsing
    vector<unsigned int> bits = parse.parse(TokensRes);
    write(bits);

    return 0; 
}
