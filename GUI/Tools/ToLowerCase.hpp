/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ToLowerCase
*/

#ifndef TOLOWERCASE_HPP_
#define TOLOWERCASE_HPP_

#include <string>

inline std::string toLowerCase(const std::string& str) {
    std::string result;
    result.reserve(str.length());
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

inline std::string getStringAfterDelimiter(const std::string& str, const std::string& delimiter) {
    size_t delimiterPos = str.find(delimiter);
    if (delimiterPos != std::string::npos) {
        return str.substr(delimiterPos + delimiter.length());
    }
    return "";
}

#endif /* !TOLOWERCASE_HPP_ */
