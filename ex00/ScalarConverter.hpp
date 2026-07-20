#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cmath>
# include <cstdlib>
# include <limits>
# include <iostream>
# include <cstddef>
# include <iomanip>

class ScalarConverter
{
    public:
        static void convert(const std::string &literal);
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
};

#endif

