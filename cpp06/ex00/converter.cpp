
#include "ScalarConverter.hpp"

void intToOther ( int intValue )
{
	char	charValue;
	float	floatValue;
	double	doubleValue;

	charValue = static_cast<char>(intValue);
	floatValue = static_cast<float>(intValue);
	doubleValue = static_cast<double>(intValue);

	if (intValue < 0 || intValue >= 128)
		std::cout << "char  : impossible" << std::endl;
	else if (intValue < 32 || intValue >= 127)
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : " << charValue << "'" << std::endl;
	std::cout << "int   : " << intValue << std::endl;
	std::cout << "float : " << floatValue << ".0f" << std::endl;
	std::cout << "double: " << doubleValue << ".0" << std::endl;
}

void charToOther( char charValue )
{
	int		intValue;
	float	floatValue;
	double	doubleValue;

	intValue = static_cast<int>(charValue);
	floatValue = static_cast<float>(charValue);
	doubleValue = static_cast<double>(charValue);

	std::cout << "char  : " << charValue << "'" << std::endl;
	std::cout << "int   : " << intValue << std::endl;
	std::cout << "float : " << floatValue << ".0f" << std::endl;
	std::cout << "double: " << doubleValue << ".0" << std::endl;
	return ;
}

void	floatToOther( float floatValue ) {
	char	charValue;
	int		intValue;
	double	doubleValue;

	charValue = static_cast<char>(floatValue);
	intValue = static_cast<int>(floatValue);
	doubleValue = static_cast<double>(floatValue);

	if (floatValue < 0 || floatValue >= 128 || floatValue != floatValue) {
		std::cout << "char  : impossible" << std::endl;
	}
	else if (floatValue < 32 || floatValue >= 127)
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : '" << charValue << "'" << std::endl;

		
	if (floatValue < std::numeric_limits<int>::lowest()
		|| floatValue > std::numeric_limits<int>::max()
		|| floatValue != floatValue)
		std::cout << "int   : impossible" << std::endl;
	else
		std::cout << "int   : " << intValue << std::endl;


	if (floatValue - static_cast<float>(intValue) == 0)
	{
		std::cout << "float : " << floatValue << ".0f" << std::endl;
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	}
	else
	{
		std::cout << "float : " << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
	}
}

void doubleToOther ( double doubleValue ) {

	char	charValue;
	int		intValue;
	float	floatValue;

	charValue = static_cast<char>(doubleValue);
	intValue = static_cast<int>(doubleValue);
	floatValue = static_cast<float>(doubleValue);

	if (doubleValue < 0 || doubleValue >= 128 || doubleValue != doubleValue)
		std::cout << "char  : impossible" << std::endl;
	else if (doubleValue < 32 || doubleValue >= 127)
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : '" << charValue << "'" << std::endl;


	if (doubleValue < std::numeric_limits<int>::lowest()
		|| doubleValue > std::numeric_limits<int>::max()
		|| doubleValue != doubleValue)
		std::cout << "int   : impossible" << std::endl;
	else
		std::cout << "int   : " << intValue << std::endl;


	if (doubleValue < std::numeric_limits<float>::lowest()
		|| doubleValue > std::numeric_limits<float>::max())
		std::cout << "float : impossible" << std::endl;
	else if (doubleValue - static_cast<double>(intValue) == 0)
		std::cout << "float : " << floatValue << ".0f" << std::endl;
	else
		std::cout << "float : " << floatValue << "f" << std::endl;


	if (doubleValue - static_cast<double>(intValue) == 0)
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	else
		std::cout << "double: " << doubleValue << std::endl;
}

void ScalarConverter::convertEachType( int type ) {

	if (type == INT)
		intToOther(_intValue);
	else if (type == CHAR)
		charToOther( _charValue );
	else if (type == FLOAT)
		floatToOther( _floatValue );
	else if (type == DOUBLE)
		doubleToOther( _doubleValue );
	else {
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} 

}