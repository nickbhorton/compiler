#ifndef LEXER_HEADER_
#define LEXER_HEADER_

#include <vector>

#include "Token.h"

std::vector<Token> lex_from_string(const std::string_view &str);

#endif