/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:34:52 by faikhan           #+#    #+#             */
/*   Updated: 2026/07/05 17:14:07 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}


ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
    return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void){}

static bool isPseudo(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "inf" || literal == "inff" ||
            literal == "+inf" || literal == "-inf" ||
            literal == "+inff" || literal == "-inff");
}

static bool isChar(const std::string &literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') ||
           (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])));
}

static bool isInt(const std::string &literal)
{
    int i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (i < literal.length())
    {
        if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return false;
        i++;
    }
    return true;
}

static bool isDouble(const std::string &literal)
{
    int i = 0;
    bool hasDot = false;
    if (literal[0] == '-' || literal[0] == '+')
        i = 1;
    while (i < literal.length())
    {
        if (literal[i] == '.' && !hasDot)
            hasDot = true;
        else if (!std::isdigit(static_cast<unsigned char>(literal[i])))
            return false;
        i++;
    }
    return hasDot;
}

static bool isFloat(const std::string &literal)
{
    if (literal[literal.length() - 1] != 'f')
        return false;
    std::string withoutF = literal.substr(0, literal.length() - 1);
    return isDouble(withoutF);
}

static void printChar(double value)
{
    std::cout << "char:   ";
    if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value)))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}
static void printInt(double value)
{
    std::cout << "int:    ";
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "Impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    std::cout << "float:  ";
    if (std::fmod(value, 1.0) == 0.0)
        std::cout << static_cast<float>(value) << ".0f" << std::endl;
    else
        std::cout << static_cast<float>(value) << "f" << std::endl;
}
static void printDouble(double value)
{
    std::cout << "double: ";
    if (std::fmod(value, 1.0) == 0.0)
        std::cout << value << ".0" << std::endl;
    else
        std::cout << value << std::endl;
}
static void printPseudo(const std::string &literal)
{
    std::cout << "char:   Impossible" << std::endl;
    std::cout << "int:    Impossible" << std::endl;
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float:  nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float:  -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float:  +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}
void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::setprecision(8);
    double value;
    if (isPseudo(literal))
    {
        printPseudo(literal);
        return ;
    }
    if (isChar(literal))
    {
        if (literal.length() == 1)
            value = static_cast<double>(literal[0]);
        else
            value = static_cast<double>(literal[1]);
    }
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        value = static_cast<double>(std::atof(literal.c_str()));
    else if (isDouble(literal))
        value = std::atof(literal.c_str());
    else
    {
        std::cout << "Error: invalid literal" << std::endl;
        return ;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
