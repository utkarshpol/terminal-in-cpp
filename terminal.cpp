#include "terminal.h"
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

vector<string> parseInput(const string& input) {
    vector<string> tokens;
    istringstream tokenStream(input);
    string token;
    while (tokenStream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

bool isBuiltInCommand(const string& command) {
    return command == "greet" || command == "exit";
}

void executeBuiltInCommand(const vector<string>& tokens) {
    if (tokens[0] == "greet") {
        if (tokens.size() > 1) {
            cout << "Hello, " << tokens[1] << "!" << endl;
        } else {
            cout << "Hello, World!" << endl;
        }
    } else if (tokens[0] == "exit") {
        cout << "Exiting terminal..." << endl;
        exit(0);
    }
}

void executeCommand(const vector<string>& tokens) {
    if (isBuiltInCommand(tokens[0])) {
        executeBuiltInCommand(tokens);
    } else {
        pid_t pid = fork();

        if (pid == 0) {
            vector<char*> args;
            for (const auto& token : tokens) {
                args.push_back(const_cast<char*>(token.c_str()));
            }
            args.push_back(nullptr);

            execvp(args[0], args.data());
            cerr << "Command execution failed" << endl;
            exit(1);
        } else if (pid > 0) {
            wait(nullptr);
        } else {
            cerr << "Fork failed" << endl;
        }
    }
}
