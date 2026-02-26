# ThreatScript Lexical Analyzer - Compiler Front-End

## Overview
This repository contains the C++ implementation of the Lexical Analyzer for **ThreatScript**, a custom Domain-Specific Language (DSL) designed for Cybersecurity Threat Modeling. 

This project was developed as the implementation component of the **CSE353: Compiler Design** course for the **Integrated Assignment: Units 1 & 2**. The objective of this lexer is to transform human-readable domain instructions into formally structured representations through systematic tokenization.

## Features
This lexical analyzer strictly fulfills **Phase A: Lexical Analysis** of the compiler design process by implementing the following features:
*   **Character-by-Character Scanning:** Reads source input sequentially to extract valid language constructs.
*   **Comprehensive Token Recognition:** Accurately categorizes Keywords, Identifiers, Operators, Literals, and Delimiters based on predefined Regular Expressions.
*   **Robust Error Handling:** Features a dedicated trap/error state to detect illegal characters and invalid sequences, ensuring the analyzer handles invalid input gracefully.
*   **Whitespace Management:** Safely ignores spaces, tabs, newlines, and comments during the tokenization process.

## Token Specification
ThreatScript recognizes the following token categories:
*   **Keywords:** `WHEN`, `IF`, `BLOCK`, `ALERT`, `ALLOW`, `DENY`
*   **Identifiers:** Alphanumeric strings starting with a letter or underscore (e.g., `failed_logins`).
*   **Literals:** Numeric (integer/float), String, and Boolean values.
*   **Operators:** Relational (`<`, `>`, `==`, etc.), Arithmetic (`+`, `-`, `*`, `/`), and Assignment (`=`).
*   **Delimiters:** Statement terminators (`;`) and parentheses.

## Example Usage
Given a ThreatScript instruction:
`WHEN failed_logins > 5 BLOCK source_ip ;`

The lexer will successfully tokenize the statement into the corresponding internal representations (e.g., `KEYWORD`, `IDENTIFIER`, `REL_OP`, `NUM_LITERAL`, `KEYWORD`, `IDENTIFIER`, `DELIMITER`) to be passed to the upcoming Syntax Analyzer phase.

## Building and Running
This project is written in standard C++ and requires a compiler such as GCC or Clang.

**Compilation:**
```bash
g++ -o lexer token.cpp
```

**Execution:**
```bash
./lexer
```

## Academic Context
*   **Course:** CSE353: Compiler Design
*   **Academic Year:** 2025-2026
*   **Batch:** 2023-2027
*   **Assignment Component:** Implementation Bonus (+3 marks)

**Note on Academic Integrity:** This code is hosted for version control and development purposes. For the official assignment submission, the contents of this implementation will be submitted as a separate file or appendix alongside the main written report, as per the submission requirements.

***
