#pragma once

#include <string_view>
#include <algorithm>
#include <iostream>

enum class TokenType
{
    Plus,
    Minus,
    Asterisk,
    ForwardSlash,
    LeftParenthesis,
    RightParenthesis,
    Number,
    EndOfInput,
};

struct Token
{
    std::string_view lexem;
    TokenType type;

    Token(std::string_view lexem, TokenType type) : lexem{lexem}, type{type} {}

    double get_number() const
    {
        if (type != TokenType::Number)
        {
            // TODO: write an error class which can be thrown here and elsewhere
            std::cerr << "Cant get number value from token not being a number" << std::endl;
            std::cerr << "Should throw an Exception later!!" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string s = lexem.data();
        std::replace(s.begin(), s.end(), ',', '.');
        return std::stod(s);
    }

    std::string to_string() const
    {
        switch (type)
        {
        case TokenType::Plus:
            return "PLUS";
            break;
        case TokenType::Minus:
            return "MINUS";
            break;
        case TokenType::Asterisk:
            return "ASTERISK";
            break;
        case TokenType::ForwardSlash:
            return "FORWARD_SLASH";
            break;
        case TokenType::LeftParenthesis:
            return "LEFT_PARENTHESIS";
            break;
        case TokenType::RightParenthesis:
            return "RIGHT_PARENTHESIS";
            break;
        case TokenType::Number:
            return "NUMBER";
            break;
        case TokenType::EndOfInput:
            return "EOF";
            break;
        default:
            // TODO: throw exception later
            std::cerr << "Should never get here!" << std::endl;
            std::cerr << "maybe should throw an Exception later?" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
};