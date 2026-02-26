#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "token.h"

using namespace std;

// Lexer Class
class Lexer {
public:
    Lexer(const string& input) : input(input), position(0) {}

    vector<Token> tokenize() {
        vector<Token> tokens;

        while (position < input.length()) {
            char currentChar = input[position];

            // Skip whitespaces
            if (isspace(currentChar)) {
                position++;
                continue;
            }

            // Match keywords (optional for your DSL)
            if (matchKeyword()) {
                tokens.push_back(Token{TokenType::KEYWORD, input.substr(position - 2, 2)});
                continue;
            }

            // Match numbers (integers or floats)
            if (isdigit(currentChar)) {
                tokens.push_back(Token{TokenType::NUMERIC_LITERAL, extractNumber()});
                continue;
            }

            // Match identifiers (variables or functions)
            if (isalpha(currentChar) || currentChar == '_') {
                tokens.push_back(Token{TokenType::IDENTIFIER, extractIdentifier()});
                continue;
            }

            // Match arithmetic operators (+, -, *, /)
            if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
                tokens.push_back(Token{TokenType::ARITHMETIC_OP, string(1, currentChar)});
                position++;
                continue;
            }

            // Match relational operators (==, !=, <, <=, >, >=)
            if (currentChar == '=' || currentChar == '!' || currentChar == '<' || currentChar == '>') {
                string op = string(1, currentChar);
                position++;
                if (position < input.length() && (input[position] == '=')) {
                    op += "=";
                    position++;
                }
                tokens.push_back(Token{TokenType::RELATIONAL_OP, op});
                continue;
            }

            // Match assignment operator (=)
            if (currentChar == '=') {
                tokens.push_back(Token{TokenType::ASSIGNMENT_OP, "="});
                position++;
                continue;
            }

            // Match string literals (e.g., "Hello")
            if (currentChar == '"') {
                tokens.push_back(Token{TokenType::STRING_LITERAL, extractStringLiteral()});
                continue;
            }

            // Match delimiters like parentheses and semicolons
            if (currentChar == '(' || currentChar == ')' || currentChar == ';') {
                tokens.push_back(Token{TokenType::DELIMITER, string(1, currentChar)});
                position++;
                continue;
            }

            // Invalid character handling
            tokens.push_back(Token{TokenType::INVALID, string(1, currentChar)});
            position++;
        }

        tokens.push_back(Token{TokenType::EOF_TOKEN, ""}); // End of input
        return tokens;
    }

private:
    string input;
    size_t position;

    // Match a keyword (optional for your DSL)
    bool matchKeyword() {
        if (position + 1 < input.length() && isalpha(input[position])) {
            if (input.substr(position, 2) == "if") {
                position += 2;
                return true;
            }
        }
        return false;
    }

    // Extract a number (integer or floating-point)
    string extractNumber() {
        size_t start = position;
        while (position < input.length() && (isdigit(input[position]) || input[position] == '.')) {
            position++;
        }
        return input.substr(start, position - start);
    }

    // Extract an identifier (e.g., variable or function names)
    string extractIdentifier() {
        size_t start = position;
        while (position < input.length() && (isalnum(input[position]) || input[position] == '_')) {
            position++;
        }
        return input.substr(start, position - start);
    }

    // Extract a string literal (text inside quotes)
    string extractStringLiteral() {
        position++; // Skip the opening quote
        size_t start = position;
        while (position < input.length() && input[position] != '"') {
            position++;
        }
        string literal = input.substr(start, position - start);
        position++; // Skip the closing quote
        return literal;
    }
};

// Function to print the tokens
void printTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        switch (token.type) {
            case TokenType::KEYWORD:
                cout << "KEYWORD: " << token.value << endl;
                break;
            case TokenType::IDENTIFIER:
                cout << "IDENTIFIER: " << token.value << endl;
                break;
            case TokenType::ARITHMETIC_OP:
                cout << "ARITHMETIC OPERATOR: " << token.value << endl;
                break;
            case TokenType::RELATIONAL_OP:
                cout << "RELATIONAL OPERATOR: " << token.value << endl;
                break;
            case TokenType::ASSIGNMENT_OP:
                cout << "ASSIGNMENT OPERATOR: " << token.value << endl;
                break;
            case TokenType::NUMERIC_LITERAL:
                cout << "NUMERIC LITERAL: " << token.value << endl;
                break;
            case TokenType::STRING_LITERAL:
                cout << "STRING LITERAL: " << token.value << endl;
                break;
            case TokenType::DELIMITER:
                cout << "DELIMITER: " << token.value << endl;
                break;
            case TokenType::INVALID:
                cout << "INVALID: " << token.value << endl;
                break;
            case TokenType::EOF_TOKEN:
                cout << "END OF INPUT" << endl;
                break;
        }
    }
}

int main() {
    string input = "x = 10 + 3 * (2 - 1);";

    Lexer lexer(input);
    vector<Token> tokens = lexer.tokenize();

    // Print all tokens
    printTokens(tokens);

    return 0;
}