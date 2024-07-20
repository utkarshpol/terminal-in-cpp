#include "terminal.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while (true) {
        cout << "simple_terminal> ";
        string input;
        getline(std::cin, input);

        if (input.empty()) continue;

        vector<string> tokens = parseInput(input);

        if (tokens.empty()) continue;

        executeCommand(tokens);
    }
    return 0;
}
