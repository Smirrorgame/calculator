#include <iostream>
#include "lexer.hpp"

using namespace std;
int main()
{
    system("clear");
    cout << "Welcome to the calculator!" << endl;
    // TODO: Just for testing -> later read from std::cin
    Lexer l{"1+2"};
    vector<Token> tokens = l.getTokens();
    return EXIT_SUCCESS;
}