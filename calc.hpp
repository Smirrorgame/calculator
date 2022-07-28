#include "token.hpp"
#include "ast.hpp"

double calc(Node *astRoot)
{
    TokenType type = astRoot->m_token.type;
    if (type == TokenType::Number)
    {
        return astRoot->m_token.get_number();
    }
    if (type == TokenType::Asterisk)
    {
        return calc(astRoot->left) * calc(astRoot->right);
    }
    if (type == TokenType::ForwardSlash)
    {
        return calc(astRoot->left) / calc(astRoot->right);
    }
    if (type == TokenType::Plus)
    {
        return calc(astRoot->left) + calc(astRoot->right);
    }
    if (type == TokenType::Minus)
    {
        return calc(astRoot->left) - calc(astRoot->right);
    }

    std::cerr << "Should not get here, did i forget something?!" << std::endl;
    exit(EXIT_FAILURE);
}