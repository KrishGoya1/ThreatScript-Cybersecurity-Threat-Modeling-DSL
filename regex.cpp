#include <iostream>
#include <string>
#include <regex>
#include <vector>

// Modular Class to store and test Task 2 Formal Regular Expressions
class RegexValidator {
private:
    // We use raw string literals R"(...)" in C++ to make the regex cleaner
    // and avoid having to double-escape backslashes.
    
    std::regex keyword_re{ R"(^(WHEN|IF|BLOCK|ALERT|ALLOW|DENY)$)" };
    std::regex identifier_re{ R"(^[a-zA-Z_][a-zA-Z0-9_]*$)" };
    std::regex num_literal_re{ R"(^+(\.+)?$)" };
    std::regex str_literal_re{ R"(^"[a-zA-Z0-9_ ]*"$)" };
    std::regex bool_literal_re{ R"(^(TRUE|FALSE)$)" };
    std::regex rel_op_re{ R"(^(<|>|==|<=|>=|!=)$)" };
    std::regex arith_op_re{ R"(^(\+|-|\*|/)$)" };
    std::regex assign_op_re{ R"(^=$)" };
    std::regex delimiter_re{ R"(^(;|\(|\))$)" };

public:
    // Function to test a string against all predefined formal REs
    void validateLexeme(const std::string& lexeme) {
        std::cout << "Testing Lexeme: [" << lexeme << "] -> ";

        if (std::regex_match(lexeme, keyword_re)) {
            std::cout << "Match: KEYWORD\n";
        } 
        else if (std::regex_match(lexeme, bool_literal_re)) {
            std::cout << "Match: BOOLEAN LITERAL\n";
        }
        else if (std::regex_match(lexeme, identifier_re)) {
            std::cout << "Match: IDENTIFIER\n";
        } 
        else if (std::regex_match(lexeme, num_literal_re)) {
            std::cout << "Match: NUMERIC LITERAL\n";
        } 
        else if (std::regex_match(lexeme, str_literal_re)) {
            std::cout << "Match: STRING LITERAL\n";
        } 
        else if (std::regex_match(lexeme, rel_op_re)) {
            std::cout << "Match: RELATIONAL OPERATOR\n";
        } 
        else if (std::regex_match(lexeme, arith_op_re)) {
            std::cout << "Match: ARITHMETIC OPERATOR\n";
        } 
        else if (std::regex_match(lexeme, assign_op_re)) {
            std::cout << "Match: ASSIGNMENT OPERATOR\n";
        } 
        else if (std::regex_match(lexeme, delimiter_re)) {
            std::cout << "Match: DELIMITER\n";
        } 
        else {
            std::cout << "Match: UNKNOWN / INVALID (Error State Triggered)\n";
        }
    }
};

// Main function to demonstrate the REs in working condition for the bonus marks
int main() {
    RegexValidator validator;

    std::cout << "--- ThreatScript Formal Regular Expression Validator ---\n\n";

    // Test cases covering all categories required by Task 2
    std::vector<std::string> test_lexemes = {
        "BLOCK",          // Keyword
        "failed_logins",  // Identifier
        "192.168",        // Numeric Literal (Float)
        "\"malware\"",    // String Literal
        "TRUE",           // Boolean Literal
        ">=",             // Relational Operator
        "+",              // Arithmetic Operator
        "=",              // Assignment Operator
        ";",              // Delimiter
        "123bad_var",     // Invalid Identifier (Starts with number)
        "@"               // Illegal Character
    };

    for (const std::string& lexeme : test_lexemes) {
        validator.validateLexeme(lexeme);
    }

    return 0;
}