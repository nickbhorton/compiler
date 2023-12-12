#include <gtest/gtest.h>
#include "Lexer.h"


TEST(LEXER_BASIC, unique_tokens_no_ws){
    std::vector<Token> tokens = lex_from_string("()+-");
    EXPECT_EQ(tokens.size(), 4);
    EXPECT_EQ(tokens[0].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[0].content.has_value(), false);
    EXPECT_EQ(tokens[1].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[1].content.has_value(), false);
    EXPECT_EQ(tokens[2].name, TokenName::PLUS);
    EXPECT_EQ(tokens[2].content.has_value(), false);
    EXPECT_EQ(tokens[3].name, TokenName::MINUS);
    EXPECT_EQ(tokens[4].content.has_value(), false);
}

TEST(LEXER_BASIC, unique_tokens){
    std::vector<Token> tokens = lex_from_string("( \t\t  \n)  \n+\n - \t    \t\n\n\n");
    EXPECT_EQ(tokens.size(), 4);
    EXPECT_EQ(tokens[0].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[0].content.has_value(), false);
    EXPECT_EQ(tokens[1].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[1].content.has_value(), false);
    EXPECT_EQ(tokens[2].name, TokenName::PLUS);
    EXPECT_EQ(tokens[2].content.has_value(), false);
    EXPECT_EQ(tokens[3].name, TokenName::MINUS);
    EXPECT_EQ(tokens[4].content.has_value(), false);
}

TEST(LEXER_BASIC, single_number_single_digit_no_ws){
    std::vector<Token> tokens = lex_from_string("1");
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1");
}

TEST(LEXER_BASIC, single_number_multiple_digit_no_ws){
    std::vector<Token> tokens = lex_from_string("1234567890");
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1234567890");
}

TEST(LEXER_BASIC, single_number_single_digit){
    std::vector<Token> tokens = lex_from_string("\n\n\t   \t \n   1   \n\n\t    \t\t\t\n\n\n");
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1");
}

TEST(LEXER_BASIC, single_number_multiple_digit){
    std::vector<Token> tokens = lex_from_string("\n\n\t   \t \n   1234567890   \n\n\t    \t\t\t\n\n\n");
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1234567890");
}

TEST(LEXER_BASIC, multiple_number_single_digit_no_ws){
    std::vector<Token> tokens = lex_from_string("1 2 3 4 5 6 7 8 9 0");
    EXPECT_EQ(tokens.size(), 10);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1");
    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "2");
    EXPECT_EQ(tokens[2].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[2].content.has_value(), true);
    EXPECT_EQ(tokens[2].content.value(), "3");
    EXPECT_EQ(tokens[3].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[3].content.has_value(), true);
    EXPECT_EQ(tokens[3].content.value(), "4");
    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "5");
    EXPECT_EQ(tokens[5].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[5].content.has_value(), true);
    EXPECT_EQ(tokens[5].content.value(), "6");
    EXPECT_EQ(tokens[6].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[6].content.has_value(), true);
    EXPECT_EQ(tokens[6].content.value(), "7");
    EXPECT_EQ(tokens[7].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[7].content.has_value(), true);
    EXPECT_EQ(tokens[7].content.value(), "8");
    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "9");
    EXPECT_EQ(tokens[9].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[9].content.has_value(), true);
    EXPECT_EQ(tokens[9].content.value(), "0");
}

TEST(LEXER_BASIC, multiple_number_multiple_digit_no_ws){
    std::vector<Token> tokens = lex_from_string("1234567890 234567890 34567890 4567890 567890 67890 7890 890 90 0");
    EXPECT_EQ(tokens.size(), 10);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1234567890");
    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "234567890");
    EXPECT_EQ(tokens[2].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[2].content.has_value(), true);
    EXPECT_EQ(tokens[2].content.value(), "34567890");
    EXPECT_EQ(tokens[3].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[3].content.has_value(), true);
    EXPECT_EQ(tokens[3].content.value(), "4567890");
    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "567890");
    EXPECT_EQ(tokens[5].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[5].content.has_value(), true);
    EXPECT_EQ(tokens[5].content.value(), "67890");
    EXPECT_EQ(tokens[6].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[6].content.has_value(), true);
    EXPECT_EQ(tokens[6].content.value(), "7890");
    EXPECT_EQ(tokens[7].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[7].content.has_value(), true);
    EXPECT_EQ(tokens[7].content.value(), "890");
    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "90");
    EXPECT_EQ(tokens[9].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[9].content.has_value(), true);
    EXPECT_EQ(tokens[9].content.value(), "0");
}

TEST(LEXER_BASIC, multiple_number_single_digit){
    std::vector<Token> tokens = lex_from_string("\t\n  \n\t1 \t\n  \n\t2 \t\n  \n\t3 \t\n  \n\t4 \t\n  \n\t5 \t\n  \n\t6 \t\n  \n\t7 \t\n  \n\t8 \t\n  \n\t9 \t\n  \n\t0\t\n  \n\t");
    EXPECT_EQ(tokens.size(), 10);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1");
    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "2");
    EXPECT_EQ(tokens[2].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[2].content.has_value(), true);
    EXPECT_EQ(tokens[2].content.value(), "3");
    EXPECT_EQ(tokens[3].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[3].content.has_value(), true);
    EXPECT_EQ(tokens[3].content.value(), "4");
    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "5");
    EXPECT_EQ(tokens[5].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[5].content.has_value(), true);
    EXPECT_EQ(tokens[5].content.value(), "6");
    EXPECT_EQ(tokens[6].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[6].content.has_value(), true);
    EXPECT_EQ(tokens[6].content.value(), "7");
    EXPECT_EQ(tokens[7].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[7].content.has_value(), true);
    EXPECT_EQ(tokens[7].content.value(), "8");
    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "9");
    EXPECT_EQ(tokens[9].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[9].content.has_value(), true);
    EXPECT_EQ(tokens[9].content.value(), "0");
}

TEST(LEXER_BASIC, multiple_number_multiple_digit){
    std::vector<Token> tokens = lex_from_string("\t\n  \n\t1234567890 \t\n  \n\t234567890 \t\n  \n\t34567890 \t\n  \n\t4567890 \t\n  \n\t567890\t\n  \n\t 67890\t\n  \n\t 7890 \t\n  \n\t890 \t\n  \n\t90 \t\n  \n\t0\t\n  \n\t");
    EXPECT_EQ(tokens.size(), 10);
    EXPECT_EQ(tokens[0].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[0].content.has_value(), true);
    EXPECT_EQ(tokens[0].content.value(), "1234567890");
    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "234567890");
    EXPECT_EQ(tokens[2].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[2].content.has_value(), true);
    EXPECT_EQ(tokens[2].content.value(), "34567890");
    EXPECT_EQ(tokens[3].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[3].content.has_value(), true);
    EXPECT_EQ(tokens[3].content.value(), "4567890");
    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "567890");
    EXPECT_EQ(tokens[5].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[5].content.has_value(), true);
    EXPECT_EQ(tokens[5].content.value(), "67890");
    EXPECT_EQ(tokens[6].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[6].content.has_value(), true);
    EXPECT_EQ(tokens[6].content.value(), "7890");
    EXPECT_EQ(tokens[7].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[7].content.has_value(), true);
    EXPECT_EQ(tokens[7].content.value(), "890");
    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "90");
    EXPECT_EQ(tokens[9].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[9].content.has_value(), true);
    EXPECT_EQ(tokens[9].content.value(), "0");
}

TEST(LEXER_BASIC, empty ){
    std::vector<Token> tokens = lex_from_string("");
    EXPECT_EQ(tokens.size(), 0);
}

TEST(LEXER_BASIC, random_example1_no_ws){
    std::vector<Token> tokens = lex_from_string("(141+(2653-((7512+90875)+832)))");
    EXPECT_EQ(tokens.size(), 17);

    EXPECT_EQ(tokens[0].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[0].content.has_value(), false);

    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "141");

    EXPECT_EQ(tokens[2].name, TokenName::PLUS);
    EXPECT_EQ(tokens[2].content.has_value(), false);

    EXPECT_EQ(tokens[3].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[3].content.has_value(), false);

    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "2653");

    EXPECT_EQ(tokens[5].name, TokenName::MINUS);
    EXPECT_EQ(tokens[5].content.has_value(), false);

    EXPECT_EQ(tokens[6].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[6].content.has_value(), false);

    EXPECT_EQ(tokens[7].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[7].content.has_value(), false);

    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "7512");

    EXPECT_EQ(tokens[9].name, TokenName::PLUS);
    EXPECT_EQ(tokens[9].content.has_value(), false);

    EXPECT_EQ(tokens[10].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[10].content.has_value(), true);
    EXPECT_EQ(tokens[10].content.value(), "90875");

    EXPECT_EQ(tokens[11].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[11].content.has_value(), false);

    EXPECT_EQ(tokens[12].name, TokenName::PLUS);
    EXPECT_EQ(tokens[12].content.has_value(), false);

    EXPECT_EQ(tokens[13].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[13].content.has_value(), true);
    EXPECT_EQ(tokens[13].content.value(), "832");

    EXPECT_EQ(tokens[14].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[14].content.has_value(), false);

    EXPECT_EQ(tokens[15].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[15].content.has_value(), false);

    EXPECT_EQ(tokens[16].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[16].content.has_value(), false);
}

TEST(LEXER_BASIC, random_example1){
    std::vector<Token> tokens = lex_from_string("(\t\t\n   \n \t141\t \n+ \t \t \n(\t \n2653\t \n-\t \n(\n\n \t(\t \n7512\t \n+90875\t \n)\t \n+\t \n832)\t \n))");
    EXPECT_EQ(tokens.size(), 17);

    EXPECT_EQ(tokens[0].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[0].content.has_value(), false);

    EXPECT_EQ(tokens[1].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[1].content.has_value(), true);
    EXPECT_EQ(tokens[1].content.value(), "141");

    EXPECT_EQ(tokens[2].name, TokenName::PLUS);
    EXPECT_EQ(tokens[2].content.has_value(), false);

    EXPECT_EQ(tokens[3].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[3].content.has_value(), false);

    EXPECT_EQ(tokens[4].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[4].content.has_value(), true);
    EXPECT_EQ(tokens[4].content.value(), "2653");

    EXPECT_EQ(tokens[5].name, TokenName::MINUS);
    EXPECT_EQ(tokens[5].content.has_value(), false);

    EXPECT_EQ(tokens[6].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[6].content.has_value(), false);

    EXPECT_EQ(tokens[7].name, TokenName::LPAREN);
    EXPECT_EQ(tokens[7].content.has_value(), false);

    EXPECT_EQ(tokens[8].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[8].content.has_value(), true);
    EXPECT_EQ(tokens[8].content.value(), "7512");

    EXPECT_EQ(tokens[9].name, TokenName::PLUS);
    EXPECT_EQ(tokens[9].content.has_value(), false);

    EXPECT_EQ(tokens[10].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[10].content.has_value(), true);
    EXPECT_EQ(tokens[10].content.value(), "90875");

    EXPECT_EQ(tokens[11].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[11].content.has_value(), false);

    EXPECT_EQ(tokens[12].name, TokenName::PLUS);
    EXPECT_EQ(tokens[12].content.has_value(), false);

    EXPECT_EQ(tokens[13].name, TokenName::INTEGER_LITERAL);
    EXPECT_EQ(tokens[13].content.has_value(), true);
    EXPECT_EQ(tokens[13].content.value(), "832");

    EXPECT_EQ(tokens[14].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[14].content.has_value(), false);

    EXPECT_EQ(tokens[15].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[15].content.has_value(), false);

    EXPECT_EQ(tokens[16].name, TokenName::RPAREN);
    EXPECT_EQ(tokens[16].content.has_value(), false);
}