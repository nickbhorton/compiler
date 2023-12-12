#ifndef TOKEN_HEADER_
#define TOKEN_HEADER_

#include <optional>
#include <string>

enum class TokenName {
    LPAREN,
    RPAREN,
    PLUS,
    MINUS
};

struct Token {
    TokenName name;
    std::optional<std::string> content;
};

#endif