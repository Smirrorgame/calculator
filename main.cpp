#include <iostream>
#include "lexer.hpp"

using namespace std;
int main()
{
    system("clear");
    cout << "Welcome to the calculator!" << endl;
    // TODO: Just for testing -> later read from std::cin
    std::string in = "42.5+0.5-1";
    cout << "The input is: " << endl
         << in << endl
         << endl;
    Lexer l{in};
    vector<Token> tokens = l.getTokens();

    for (Token t : tokens)
    {
        cout << "Token: " << t.to_string() << ", lexem : '" << t.lexem << "'" << endl;
    }
    return EXIT_SUCCESS;
}