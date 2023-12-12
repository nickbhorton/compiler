#include "Lexer.h"

#include <iostream>

inline void check_number_finished(const size_t digit_buffer_size, std::vector<Token>& tokens, std::string& digit_buffer){
    if (digit_buffer_size > 0){
        tokens.push_back(Token{TokenName::INTEGER_LITERAL, std::optional<std::string>(digit_buffer)});
        digit_buffer.clear();
    }
}

std::vector<Token> lex_from_string(const std::string_view &str) {
    std::vector<Token> tokens {};
    std::string digit_buffer {};
    size_t digit_buffer_size = 0;
    for (const auto c : str) {
        digit_buffer_size = digit_buffer.size();
        switch (c) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                digit_buffer.push_back(c);
                break;
            case ' ': case '\n': case '\t':
                check_number_finished(digit_buffer_size, tokens, digit_buffer);
                break;
            case '(':
                check_number_finished(digit_buffer_size, tokens, digit_buffer);
                tokens.push_back(Token{TokenName::LPAREN, std::optional<std::string>()});
                break;
            case ')':
                check_number_finished(digit_buffer_size, tokens, digit_buffer);
                tokens.push_back(Token{TokenName::RPAREN, std::optional<std::string>()});
                break;
            case '+':
                check_number_finished(digit_buffer_size, tokens, digit_buffer);
                tokens.push_back(Token{TokenName::PLUS, std::optional<std::string>()});
                break;
            case '-':
                check_number_finished(digit_buffer_size, tokens, digit_buffer);
                tokens.push_back(Token{TokenName::MINUS, std::optional<std::string>()});
                break;
            
            default:
                std::cout << "Unrecognized char in string being lexed\n";
                exit(EXIT_FAILURE);
                break;
        }
    }
    if (digit_buffer.size() > 0){
        tokens.push_back(Token{TokenName::INTEGER_LITERAL, std::optional<std::string>(digit_buffer)});
    }
    return tokens;
}
