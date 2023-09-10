#include <iostream>
#include <stack>
#include <string>

class Bracket {
    public:
        char type;
        int position;
        Bracket(char type, int position){
            this->type = type;
            this->position = position;
        }
        bool Matchc(char c){
            if (type == '[' && c == ']')
                return true;
            if (type == '{' && c == '}')
                return true;
            if (type == '(' && c == ')')
                return true;
            return false;
        }
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)){
                opening_brackets_stack.pop();
            } else {
                std::cout << position+1 << std::endl;
                return 0;
            }
        }
    }

    if(opening_brackets_stack.empty()){
        std::cout << "Success" << std::endl;
    } else {
        Bracket first = opening_brackets_stack.top();
        std::cout << first.position << std::endl;
    }

    return 0;
}
