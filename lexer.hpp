#pragma once

#include <vector>
#include "token.hpp"

using std::size_t;
using std::string_view;
using std::vector;

class Lexer
{
private:
    size_t m_current{0};
    string_view m_input;
    vector<Token> m_tokens;

    bool isAtEnd();
    char peek();
    void consume();

    void addToken(TokenType type, string_view lexem);

public:
    Lexer(string_view input) : m_input{input} {}
    vector<Token> getTokens();
};