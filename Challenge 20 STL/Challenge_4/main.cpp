// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

bool is_palindrome(std::string s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.

    s = clean_string(s);

    std::stack<char> stack;
    std::queue<char> queue;

    for (char &c : s) {
        stack.push(c);
        queue.push(c);
    }

    char stack_char;
    char queue_char;

    while (!stack.empty()) {
        stack_char = stack.top();
        queue_char = queue.front();
        stack.pop();
        queue.pop();
        if (stack_char != queue_char) return false;
    }

    return stack.empty();
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}