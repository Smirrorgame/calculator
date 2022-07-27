#include "lexer.hpp"

using std::cerr;
using std::endl;

/**
 * @brief checks if the whole input has already been comsumed
 *
 * @return true if the end of input has been reached
 */
bool Lexer::isAtEnd()
{
    return m_current >= m_input.length();
}

/**
 * @brief peeking the input at curent position without consumtion
 *
 * @return the char at curent position
 */
char Lexer::peek()
{
    return m_input.at(m_current);
}

/**
 * @brief consumes the char at 'm_current' and advances to next char
 *
 * @return void
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
 * @brief adds a token to the vector of tokens
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
 * @brief tokenizes the string_view m_input
 *
 * @return a vector of tokens based on m_input
 */
vector<Token> Lexer::getTokens()
{
    while (not isAtEnd())
    {
        const char current_char = peek();
        if (isdigit(current_char))
        {
            size_t num_start = m_current;
            size_t len_number = consumeNumber();
            addToken(TokenType::Number, m_input.substr(num_start, len_number));
            continue;
        }
        const TokenType type = tokenTypeFor(current_char);
        addToken(type, m_input.substr(m_current, 1));
        consume();
    }
    addToken(TokenType::EndOfInput, m_input.substr(m_current, 1));

    return std::move(m_tokens);
}