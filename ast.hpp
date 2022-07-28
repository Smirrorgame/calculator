#pragma once

#include "token.hpp"

struct Node
{
    Token m_token;
    Node *left;
    Node *right;

    Node(Token token) : m_token{token}, left{nullptr}, right{nullptr} {}
    Node(Token token, Node *lhs, Node *rhs) : m_token{token}, left{lhs}, right{rhs} {}
    ~Node()
    {
        left = nullptr;
        right = nullptr;
    }
};