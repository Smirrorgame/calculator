#pragma once

#include "ast.hpp"
#include <vector>

using std::vector;

class Parser
{
private:
    vector<Token> m_tokens;
    size_t m_current = size_t{0};
    Token peek();
    void consume();

public:
    Parser(vector<Token> m_tokens) : m_tokens{m_tokens} {}
    Node *parse();
    Node *parseAddSubExpr();
    Node *parseMulDivExpr();
    Node *parsePrimaryExpr();
};