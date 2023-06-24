/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ToLowerCase
*/

#ifndef TOLOWERCASE_HPP_
    #define TOLOWERCASE_HPP_

    #include <string>

/**
 * @brief Convert a string to lower case
 * Call this function for convert a string to lower case
 * Example: "Hello World" -> "hello world"
 * @param str          The string to convert
 * @return std::string The converted string
 */
inline std::string toLowerCase(const std::string &str)
{
    std::string result;

    result.reserve(str.length());
    for (char c : str)
        result += std::tolower(c);
    return result;
}

/**
 * @brief Get the String After Delimiter object
 * Call this function for get the string after a delimiter
 * Example: "Hello World" with delimiter " " -> "World"
 * @warning If the delimiter is not found, the function return an empty string
 * @param str          The string to get the string after delimiter
 * @param delimiter    The delimiter
 * @return std::string The string after delimiter
 */
inline std::string getStringAfterDelimiter(const std::string &str, const std::string &delimiter)
{
    size_t delimiterPos = str.find(delimiter);

    if (delimiterPos != std::string::npos)
        return str.substr(delimiterPos + delimiter.length());
    return "";
}

#endif /* !TOLOWERCASE_HPP_ */
