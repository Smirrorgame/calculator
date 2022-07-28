#include <iostream>
#include "lexer.hpp"
#include "parser.hpp"
#include "calc.hpp"

using namespace std;
int main()
{
    system("clear");
    cout << "Welcome to the calculator!" << endl;
    // TODO: Just for testing -> later read from std::cin
    std::string in = "2(1.5+1,5)2";
    cout << "The input was: " << endl
         << in
         << endl;
    Lexer l{in};
    vector<Token> tokens = l.getTokens();
    Parser p{tokens};
    Node *root = p.parse();
    double result = calc(root);
    cout << "=" << result << endl;

    return EXIT_SUCCESS;
}
