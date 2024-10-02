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

std::list<std::string> split(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::list <std::string> tokens;

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

bool validList(std::list<std::string> &tokens)
{
    std::list <std::string>::iterator it;
    int i = 0;
    
    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (((std::string)*it).empty())
            continue;
        if (i <= 1)
        {
            if (isoperator(*it))
                return false;
        }
        else
        {
            if (!(i % 2) && !isoperator(*it))
                return false;
            if ((i % 2) && isoperator(*it))
                return false;
        }
        i++;
    }
    if (i == 1)
        return true;
    if (i < 3 || i %2 == 0)
        return false;
    return true;
}

std::stack<std::string> parseNotation(const std::string &s)
{
    std::list<std::string> tokens = split(s, ' ');
    std::stack<std::string> stack;
    std::list <std::string>::iterator it;

    if (!validList(tokens))
        throw std::runtime_error("invalid sequence");
    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
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

double doOp(std::stack<std::string> &st, double &nb, std::string &op)
{
    if (st.size() == 1)
    {
        double sb = atoi(st.top().c_str());
        // std::cout << nb << " " << op << " " << sb << std::endl;
        st.pop();
        if (op == "+")
            return nb + sb;
        if (op == "-")
            return sb - nb;
        if (op == "*")
            return nb * sb;
        if (op == "/")
        {
            if (!nb)
                throw std::runtime_error("devision by zero");
            return sb / nb;
        }
    }
    if (op == "+")
        return nb + rpn(st);
    if (op == "-")
        return rpn(st) - nb ;
    if (op == "*")
        return nb * rpn(st);
    if (op == "/")
    {
        if (!nb)
            throw std::runtime_error("devision by zero");
        return rpn(st) / nb;
    }
    return 0;
}

double rpn(std::stack<std::string> &st)
{
    if (st.size() < 3)
        return (atoi(st.top().c_str()));
    std::string op = st.top();
    st.pop();
    double nb = atoi(st.top().c_str());
    st.pop();
    return doOp(st, nb, op);
    // }

}
