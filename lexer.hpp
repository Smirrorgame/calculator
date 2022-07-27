#pragma once

#include <vector>
#include <unordered_map>
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
    const std::unordered_map<char, TokenType> m_lut = {
        std::pair<char, TokenType>('+', TokenType::Plus),
        std::pair<char, TokenType>('-', TokenType::Minus),
        std::pair<char, TokenType>('*', TokenType::Asterisk),
        std::pair<char, TokenType>('/', TokenType::ForwardSlash),
        std::pair<char, TokenType>('(', TokenType::LeftParenthesis),
        std::pair<char, TokenType>(')', TokenType::RightParenthesis),
    };

    bool isAtEnd();
    char peek();
    void consume();
    void addToken(TokenType type, string_view lexem);
    size_t consumeNumber();
    TokenType tokenTypeFor(const char c);

public:
    Lexer(string_view input) : m_input{input} {}
    vector<Token> getTokens();
};