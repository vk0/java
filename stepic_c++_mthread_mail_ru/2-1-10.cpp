// Посмотрим, насколько хорошо вы умеете обращаться с контейнерами!?

// Задача простая - найти производную многочлена. Многочлен может быть большой, но только с неотрицательными целыми степенями и целыми коэффициентами. Подумайте, каким образом его лучше представить в памяти? Вывод должен быть без пробелов и в порядке убывания степеней, хотя ввод этому правилу может не удовлетворять. Также на ввод может быть подан многочлен с неприведенными слагаемыми.

// Для этой задачи существует 10 тестов, созданных вручную (3 из них вы можете увидеть ниже) и 90 тестов, созданных автоматически случайным образом.

// Sample Input 1:

// x^2+x

// Sample Output 1:

// 2*x+1


// Sample Input 2:

// 2*x^100+100*x^2

// Sample Output 2:

// 200*x^99+200*x


// Sample Input 3:

// x^10000+x+1

// Sample Output 3:

// 10000*x^9999+1


// Sample Input 4:

// -x^2-x^3

// Sample Output 4:

// -3*x^2-2*x


// Sample Input 5:

// x+x+x+x+x+x+x+x+x+x

// Sample Output 5:

// 10

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Term
{
    Term(const std::string &str) : coef(1), degree(0)
    {
        long sign = 1;
        auto begin = str.begin();
        if (*begin == '-') {
            sign = -1;
            ++begin;
        }
        else if (*begin == '+') {
            sign = 1;
            ++begin;
        }
        coef *= sign;

        auto end = begin + 1;
        if (std::isdigit(*begin)) { // extract coef
            while (end != str.end()) {
                if (*end == '*') break;
                ++end;
            }
            std::string c(begin, end);
            coef = std::stol(c);
            coef *= sign;

            if (end != str.end()) {
                begin = ++end;
                ++end;
            }
        }

        if (std::isalpha(*begin)) { // extract nom
            while (end != str.end()) {
                if (end == str.end() || !std::isalpha(*end)) {
                    break;
                }
                ++end;
            }
            nom = std::string(begin, end);
            degree = 1;
        }

        if (end != str.end()) {// extract degree
            begin = ++end;
            ++end;
            while (end != str.end() ) {
                if (!std::isdigit(*end)) {
                    break;
                }
                ++end;
            }
            degree = std::stol(std::string(begin, end));
        }
    }

    std::string to_string() const
    {
        std::string t;
        if (coef >= 0) {
            t.append("+");
            if (coef != 1 || degree == 0) {
                t.append(std::to_string(coef));
            }
        }
        else {
            if (coef == -1) {
                t.append("-");
            }
            else {
                t.append(std::to_string(coef));
            }
        }
        if (degree != 0) {
            t.append("*" + nom);
            if (degree != 1) {
                t.append("^" + std::to_string(degree));
            }
        }
        return std::move(t);
    }

    long long coef;
    unsigned long long degree;
    std::string nom;
};

using polynom_t = std::map<unsigned long, Term,
      std::greater<unsigned long>>;

std::string to_string(const polynom_t &polynom)
{
    std::string polynomial;
    if (polynom.size() == 1) {
        polynomial.append(polynom.begin()->second.to_string());
    }
    else {
        for (auto& t : polynom) {
            if (t.second.coef != 0)
                polynomial.append(t.second.to_string());
        }
    }
    if (polynomial[0] == '+') {
        polynomial.erase(0, 1);
    }
    return std::move(polynomial);
}

std::vector<std::string> tokenize(const std::string &input)
{
    std::vector<std::string> tokens;
    decltype(input.begin()) token_begin;
    auto token_end = input.begin();
    do {
        token_begin = token_end;
        ++token_end;
        while (true) {
            if (*token_end == '+'
                    || *token_end == '-'
                    ||  token_end == input.end()) {
                break;
            }
            ++token_end;
        }
        tokens.emplace_back(token_begin, token_end);
    } while (token_end != input.end());
    return std::move(tokens);
}

polynom_t parse_polynomial(const std::string &polynomial)
{
    auto tokens = tokenize(polynomial);
    polynom_t polynom;
    for (const auto& t : tokens) {
        Term new_term = Term(t);
        auto term = polynom.find(new_term.degree);
        if (term != polynom.end()) {
            term->second.coef += new_term.coef;
        }
        else {
            polynom.insert(std::make_pair(new_term.degree, new_term));
        }
    }
    return std::move(polynom);
}

void simplify_polynomial(polynom_t &polynom)
{
    auto linear = polynom.find(1);
    if (linear != polynom.end()) {
        auto cnst = polynom.find(0);
        if (cnst != polynom.end()) {
            cnst->second.coef += linear->second.coef;
            polynom.erase(linear);
        }
    }
}

std::string derivative(std::string polynomial)
{
    auto polynom = parse_polynomial(polynomial);

    for (auto& t : polynom) {
        if (t.second.degree == 0) {
            t.second.coef = 0;
        }
        else {
            t.second.coef *= t.second.degree--;
        }
    }
    // FIXME: polynom is invalid now!
    // because Key is greater than degree of term

    // simplify_polynomial(polynom);

    return to_string(polynom);
}

int main()
{
    std::string input;
    getline(std::cin, input);
    std::cout << derivative(input) << std::endl;

    return EXIT_SUCCESS;
}