# Calculator

This Program is a Calculator which reads from cin and prints the result to cout

The input runs through following pipeline:
1. Tokenizing in the Lexer
2. Parsing of the tokens and generation of abstract syntax tree (AST) in the parser
3. Execution of the calculation based on the AST

The Calculator supports following:
- Integers
- Decimals (indicated with '.' or ',')
- Addition
- Subtraction
- Multiplication
- Division
- Parenthesis arithmetic

For Parenthesis there's no implicit multiplication, so you need to write an asterisk: Write `3*(2+1)` instead of `3(2+1)`
