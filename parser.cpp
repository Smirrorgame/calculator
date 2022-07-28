#include "parser.hpp"

/**
 * @brief invokes the parsing algorithm
 *
 * @return the root node of the token tree
 */
Node *Parser::parse()
{
    return parseAddSubExpr();
}

/**
 * @brief tries to parse addition and subtraction
 *
 * @return A node object from a tree of tokens containing lhs expression and rhs expression
 */
Node *Parser::parseAddSubExpr()
{
    Node *lhs = parseMulDivExpr();
    Token token = peek();
    while (token.type == TokenType::Plus or token.type == TokenType::Minus)
    {
        consume();
        Node *rhs = parseAddSubExpr();
        lhs = new Node(token, lhs, rhs);
        token = peek();
    }
    return lhs;
}

/**
 * @brief tries to parse multiplication and division
 *
 * @return A node object from a tree of tokens containing lhs expression and rhs expression
 */
Node *Parser::parseMulDivExpr()
{
    Node *lhs = parsePrimaryExpr();
    Token token = peek();
    while (token.type == TokenType::Asterisk or token.type == TokenType::ForwardSlash)
    {
        consume();
        Node *rhs = parsePrimaryExpr();
        lhs = new Node{token, lhs, rhs};
        token = peek();
    }
    return lhs;
}

/**
 * @brief tries to parse Numbers and Parenthesis
 *
 * @return A node object from a tree of tokens
 */
Node *Parser::parsePrimaryExpr()
{
    const Token token = peek();
    if (token.type == TokenType::Number)
    {
        consume();
        return new Node{token};
    }
    if (token.type == TokenType::LeftParenthesis)
    {
        consume();
        Node *innerExpr = parseAddSubExpr();
        if (peek().type != TokenType::RightParenthesis)
        {
            // TODO: throw Exception
            std::cerr << "Expected \")\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        consume();
        return innerExpr;
    }
    std::cerr << "Expected a Number or a parenthesis!" << std::endl;
    exit(EXIT_FAILURE);
}

/**
 * @brief peeks current Token in m_tokens
 *
 * @return The token at the index m_current
 */
Token Parser::peek()
{
    if (m_current >= m_tokens.size())
    {
        // TODO: throw exception
        std::cerr << "exceeded token list index: " << m_current << "/" << m_tokens.size() << std::endl;
        std::cerr << "item before: " << m_tokens.at(m_current - 1).lexem << std::endl;
        exit(EXIT_FAILURE);
    }
    return m_tokens.at(m_current);
}

/**
 * @brief consumes the Token at the index m_current
 *
 */
void Parser::consume()
{
    ++m_current;
}