#include "lexer.hpp"

using std::cerr;
using std::endl;
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
 * @brief consumes a given sequence of digits including decimal delimiters
 *
 * @return The length of the (decimal) number (amount of digits and decimal delimiters)
 */
size_t Lexer::consumeNumber()
{
    size_t len = 0;
    char current_peek = peek();
    bool is_decimal = false;
    while (not isAtEnd() and (isdigit(current_peek) or current_peek == '.' or current_peek == ','))
    {
        if (is_decimal and (current_peek == '.' or current_peek == ','))
        {
            cerr << "Found more than one decimal specifier at position " << m_current << ": '" << current_peek << "'" << endl;
            exit(EXIT_FAILURE);
        }
        if (current_peek == '.' or current_peek == ',')
            is_decimal = true;
        ++len;
        consume();
        if (not isAtEnd())
            current_peek = peek();
    }
    return len;
}

/**
 *
 * @param type the type of the token
 * @param lexem the lexem of the token
 */
void Lexer::addToken(TokenType type, string_view lexem)
{
    m_tokens.emplace_back(lexem, type);
}

/**
 * @brief returns a TokenType for a given char
 *
 * @param c the char to get the right TokenType for
 * @return TokenType the corresponding TokenType
 */
TokenType Lexer::tokenTypeFor(const char c)
{
    if (m_lut.find(c) != m_lut.end())
    {
        return m_lut.at(c);
    }
    else
    {
        cerr << "unknown specifier at " << m_current << ": '" << c << "'" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
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