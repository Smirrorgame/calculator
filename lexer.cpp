#include "lexer.hpp"

/**
 * checks if the whole input has already been comsumed
 *
 * @return true if the end of input has been reached
 */
bool Lexer::isAtEnd()
{
    return m_current >= m_input.length();
}

/**
 * peeking the input at curent position without consumtion
 *
 * @return the char at curent position
 */
char Lexer::peek()
{
    return m_input.at(m_current);
}

/**
 * consumes the char at 'm_current' and advances to next char
 *
 */
void Lexer::consume()
{
    ++m_current;
}

/**
 * adds a token to the vector of tokens
 *
 * @param type the type of the token
 * @param lexem the lexem of the token
 */
void Lexer::addToken(TokenType type, string_view lexem)
{
    m_tokens.emplace_back(lexem, type);
}

/**
 * tokenizes the input
 *
 * @return a vector of tokens based on the input
 */
vector<Token> Lexer::getTokens()
{
    // TODO: implement tokenizing algorithm
    while (not isAtEnd())
    {
        consume();
    }
    return m_tokens;
}