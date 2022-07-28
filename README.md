# Calculator

This Program is a Calculator which reads from cin and prints the result to cout

The input runs through following pipeline:
1. Tokenizing in the Lexer
2. Parsing of the tokens and generation of abstract syntax tree (AST) in the parser
3. Execution of the calculation based on the AST

The Calculator supports following:
- [x] Integers
- [x] Decimals (indicated with '.' or ',')
- [x] Addition
- [x] Subtraction
- [x] Multiplication
- [x] Division
- [x] Parenthesis arithmetic
- [x] implicit multiplication: instead of `3*(2+1)` you can also write `3(2+1)` or `(2+1)3`
