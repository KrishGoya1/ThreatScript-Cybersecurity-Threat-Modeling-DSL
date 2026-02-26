#include <iostream>
#include <string>
#include <vector>

// 1. Define Token Categories based on Task 1 requirements
enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    NUM_LITERAL,
    STR_LITERAL,
    BOOL_LITERAL,
    REL_OP,        // Relational Operators (<, >, ==, etc.)
    ARITH_OP,      // Arithmetic Operators (+, -, *, /)
    ASSIGN_OP,     // Assignment Operator (=)
    DELIMITER,     // Semicolons, parentheses
    UNKNOWN_ERROR  // Trap/Error state for illegal characters
};

// 2. Token Structure to hold the type and the matched text (lexeme)
struct Token {
    TokenType type;
    std::string lexeme;
};

// 3. Modular Lexer Class
class Lexer {
private:
    std::string sourceCode;
    size_t position;

    // Helper functions for character-by-character analysis
    bool isAtEnd() const {
        return position >= sourceCode.length();
    }

    char advance() {
        return sourceCode[position++];
    }

    char peek() const {
        if (isAtEnd()) return '\0';
        return sourceCode[position];
    }

public:
    Lexer(const std::string& input) : sourceCode(input), position(0) {}

    // Main tokenization function to extract tokens sequentially
    std::vector<Token> tokenize() {
        std::vector<Token> tokens;

        while (!isAtEnd()) {
            char c = peek();

            // Ignore whitespace and comments (Task 5 requirement)
            if (isspace(c)) {
                advance();
                continue;
            }

            // TODO: Implement DFA transition logic here using if/else or switch statements
            // For now, we are just setting up the modular structure as requested!
            
            // Example stub to prevent infinite loop in this skeleton:
            tokens.push_back({TokenType::UNKNOWN_ERROR, std::string(1, advance())});
        }

        return tokens;
    }
};

// 4. Main Function with a Test Case
int main() {
    // A sample ThreatScript statement
    std::string input = "WHEN failed_logins > 5 BLOCK source_ip ;";
    
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "Lexer initialized successfully with input: " << input << std::endl;
    std::cout << "Ready to implement DFA transitions!" << std::endl;

    return 0;
}