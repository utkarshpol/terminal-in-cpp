#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
#include <vector>

using namespace std;

// Function to parse the input string into a vector of tokens
vector<string> parseInput(const string& input);

// Function to check if a command is a built-in command
bool isBuiltInCommand(const string& command);

// Function to execute a built-in command
void executeBuiltInCommand(const vector<string>& tokens);

// Function to execute any command (built-in or external)
void executeCommand(const vector<string>& tokens);

#endif // TERMINAL_H
