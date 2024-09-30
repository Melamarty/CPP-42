#include "RPN.hpp"

std::string trim(const std::string &s)
{
    size_t start = 0;
    size_t end = s.length();

    while (start < end && s[start] == ' ') {
        ++start;
    }

    while (end > start && (s[end - 1] == ' ')) {
        --end;
    }

    return s.substr(start, end - start);
}

std::vector<std::string> split(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector <std::string> tokens;

    while (!ss.eof())
    {
        std::getline(ss, word, del);
        tokens.push_back(trim(word));
    }
    return tokens;
}

bool isoperator(std::string token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool valid_token(std::string &token)
{
    if (token.length() != 1)
        return (false);
    if (!isoperator(token) && !isdigit(token[0]))
        return (false);
    return true;
}

std::stack<std::string> parseNotation(const std::string &s)
{
    std::vector<std::string> tokens = split(s, ' ');
    std::stack<std::string> stack;
    std::vector <std::string>::reverse_iterator it;

    for (it = tokens.rbegin(); it != tokens.rend(); ++it)
    {
        // std::cout << "-" << *it << "-\n" ;
        if (((std::string)(*it)).empty())
            continue;
        if (!valid_token(*it))
            throw std::runtime_error("an invalid token found");
        stack.push(*it);
    }
    return stack;
}

void displayStack(std::stack<std::string> &stack)
{
    if (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
        displayStack(stack);
    }
}