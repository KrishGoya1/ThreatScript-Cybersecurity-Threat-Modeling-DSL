#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>
#include <regex>

using namespace std;

// --- Token Types Definitions ---

// Token types for the Arithmetic Expression DSL
enum class TokenType {
    KEYWORD,        // Reserved keywords (e.g., if, else, while)
    IDENTIFIER,     // Variable or function names
    ARITHMETIC_OP,  // +, -, *, /
    RELATIONAL_OP,  // ==, !=, <, <=, >, >=
    ASSIGNMENT_OP,  // =
    NUMERIC_LITERAL,// Integer or floating-point numbers
    STRING_LITERAL, // String literals in quotes
    DELIMITER,      // Parentheses, semicolons, etc.
    INVALID,        // Invalid tokens
    EOF_TOKEN       // End of file/input
};

// --- Token Structure ---

// Token structure holding token type and value
struct Token {
    TokenType type; // Type of token (e.g., identifier, operator, etc.)
    string value;   // Actual value (e.g., "x", "+", "10")
};

// --- Token Definitions --- 

// Regular expressions for token categories
namespace TokenDefinitions {
    // Identifier (variable or function names)
    const regex IDENTIFIER_RE("^[a-zA-Z_][a-zA-Z0-9_]*");

    // Numeric literals (integer or floating-point numbers)
    const regex NUMERIC_LITERAL_RE("^[-]?[0-9]+([.][0-9]+)?");

    // String literals (inside double quotes)
    const regex STRING_LITERAL_RE("^\"[^\"]*\"");

    // Arithmetic operators (+, -, *, /)
    const regex ARITHMETIC_OP_RE("^[\\+\\-\\*/]");

    // Relational operators (==, !=, <, <=, >, >=)
    const regex RELATIONAL_OP_RE("^(==|!=|<|<=|>|>=)");

    // Assignment operator (=)
    const regex ASSIGNMENT_OP_RE("^=");

    // Delimiters (parentheses, semicolons, etc.)
    const regex DELIMITER_RE("^[\\(\\)\\;]");

    // Keyword definitions (optional in your case)
    const regex KEYWORD_RE("^(if|else|while)");

    // Invalid characters (to handle errors)
    const regex INVALID_RE("^.+");
}

#endif