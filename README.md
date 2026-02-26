# ThreatScript Lexical Analyzer - Compiler Front-End

## Overview
This repository contains the C++ implementation of the Lexical Analyzer for **ThreatScript**, a custom Domain-Specific Language (DSL) designed for Cybersecurity Threat Modeling. 

This project was developed as the implementation component of the **CSE353: Compiler Design** course for the **Integrated Assignment: Units 1 & 2**. The objective of this codebase is to transform human-readable domain instructions into formally structured representations through systematic tokenization.

## Features
This lexical analyzer fulfills the implementation requirements of **Phase A: Lexical Analysis** by providing the following features:
*   **Character-by-Character Scanning:** Reads source input sequentially to extract valid language constructs.
*   **Comprehensive Token Recognition:** Accurately categorizes Keywords, Identifiers, Operators, Literals, and Delimiters based on formalized Regular Expressions.
*   **Robust Error Handling:** Features a dedicated trap/error state to detect illegal characters and invalid sequences.
*   **Whitespace Management:** Safely ignores spaces, tabs, newlines, and comments.
*   **Modular Validation:** Utilizes standalone regex validation to mathematically prove token accuracy.

## Assignment Checkpoints
The following table tracks the progress of all required tasks for the CSE353 Integrated Assignment. 

*Note: The numbering reflects the specific task layout provided in the assignment brief.*

| Task Number | Description | Phase Category | Status |
| :--- | :--- | :--- | :--- |
| **Task 1** | Identify and categorize all tokens for the DSL. | Phase A (Lexical) | [x] Completed |
| **Task 2** | Write formal Regular Expressions (REs) for each token. | Phase A (Lexical) | [x] Completed |
| **Task 3** | Construct DFA diagrams including a trap/error state. | Phase A (Lexical) | [ ] Pending |
| **Task 4** | Design a character-by-character tokenization algorithm. | Phase A (Lexical) | [x] Completed |
| **Task 5** | Design strategy for ignoring whitespace and comments. | Phase A (Lexical) | [x] Completed |
| **Task 6** | Resolve token precedence & ambiguity. | Phase A (Lexical) | [ ] Pending |
| **Task 7** | Lexical error handling and invalid token detection. | Phase A (Lexical) | [ ] Pending |
| **Task 8 & 9** | Handle context-sensitive lexical patterns. | Phase A (Lexical) | [ ] Pending |
| **Task 10** | Lexical analyzer optimization and DFA minimization. | Phase A (Lexical) | [ ] Pending |
| **Task 11** | Performance impact evaluation (single vs two-pass). | Phase A (Lexical) | [ ] Pending |
| **Task 12** | Design a bootstrapping strategy (host vs target). | Phase A (Lexical) | [ ] Pending |
| **Task 13 (1)** | Model Traffic Light Controller FSM. | Phase A (Lexical) | [ ] Pending |
| **Task 13 (2)** | Define Context-Free Grammar (CFG) in BNF/EBNF. | Phase B (Syntax) | [ ] Pending |
| **Task 14** | Grammar Cleaning (Left recursion & Left factoring). | Phase B (Syntax) | [ ] Pending |
| **Task 15** | Simulate bottom-up parser with panic mode recovery. | Phase B (Syntax) | [ ] Pending |
| **Task 16** | Evaluate how ambiguity affects parsing tables. | Phase B (Syntax) | [ ] Pending |
| **Task 17 (1)** | Investigate GCC handling of shift-reduce conflicts. | Phase B (Syntax) | [ ] Pending |
| **Task 17 (2)** | Construct SLR parsing table and simulate parsing. | Phase B (Syntax) | [ ] Pending |
| **Task 18** | Design Regular Expression and FA for valid message logic. | Phase B (Syntax) | [ ] Pending |
| **Task 19** | Eliminate left recursion, compute FIRST/FOLLOW, prove LL(1). | Phase B (Syntax) | [ ] Pending |
| **Task 20** | Develop a conflict-free SLR parsing table. | Phase B (Syntax) | [ ] Pending |
| **Task 21** | Calculate LALR state reduction and memory saved. | Phase B (Syntax) | [ ] Pending |
| **Task 22** | Construct LL(1) parsing table and evaluate grammar. | Phase B (Syntax) | [ ] Pending |

## Building and Running
This project is written in standard C++ and is split into modular components for clarity.

**Compiling the Lexical Scanner (Task 4 & 5):**
```bash
g++ -o lexer lexer.cpp
./lexer
```

**Compiling the Formal Regex Validator (Task 2):**
```bash
g++ -o regex_test regex.cpp
./regex_test
```

## Academic Context
*   **Course:** CSE353: Compiler Design
*   **Group ID** 23
*   **Academic Year:** 2025-2026
*   **Batch:** 2023-2027

## Group Members
*   **Krish Pankaj Goyal** 2023359271
*   **Aditya Pandey** 2023336032
*   **Aseem Varshney** 2023379326