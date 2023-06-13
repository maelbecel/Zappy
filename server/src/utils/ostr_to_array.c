/*
** EPITECH PROJECT, 2022
** olympe-lib
** File description:
** array - ostr_to_array
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"

/**
 * The function checks if a character is not a separator by comparing
 * it to a list of separators.
 *
 * @param c The character being checked for separation.
 * @param separators The `separators` parameter is a pointer to a
 * character array that contains a list of separator characters.
 * The function `is_not_separator` checks if a given character `c`
 * is not a separator by iterating through the `separators` array
 * and counting the number of times `c`
 *
 * @return a boolean value (either true or false) depending on whether
 * the character passed as the first argument is a separator or not.
 * If the character is not a separator, the function returns true (1),
 * otherwise it returns false (0).
 */
static bool is_not_separator(char c, char *separators)
{
    uint a = 0;

    for (uint y = 0; separators[y] != '\0'; y++) {
        if (c == separators[y]) {
            a++;
        }
    }
    if (a == 0)
        return (1);
    else
        return (0);
    return (0);
}

/**
 * The function counts the number of characters in a word within a
 * string, delimited by specified separators.
 *
 * @param str The string that the function is analyzing.
 * @param i The parameter "i" in the function "word_size" is the index of the
 * character in the string "str" from where the function starts counting the
 * size of the word.
 * @param separators The "separators" parameter is a string containing
 * characters that are considered as separators between words in the input
 * string "str". The function "word_size" uses this parameter to determine
 * when a word ends and another begins.
 *
 * @return The function `word_size` is returning the number of characters in a
 * word in a given string `str` starting from index `i` and delimited by any
 * of the characters in the string `separators`. The return value is of type
 * `uint`, which is an unsigned integer.
 */
static uint word_size(char *str, int i, char *separators)
{
    uint count = 0;

    while (is_not_separator(str[i], separators) && str[i] != '\0') {
        count++;
        i++;
    }
    return (count);
}

/**
 * The function counts the number of occurrences of specified separators in a
 * given string.
 *
 * @param str The input string that needs to be checked for the number of
 * occurrences of the specified separators.
 * @param separators The `separators` parameter is a string containing the
 * characters that are considered as separators. The function `spcount`
 * counts the number of occurrences of these separator characters in the
 * input string `str`.
 *
 * @return the number of occurrences of characters in the `separators`
 * string within the `str` string.
 */
static uint spcount(char *str, char *separators)
{
    uint count = 0;
    for (uint i = 0; str[i] != '\0'; i++) {
        for (uint y = 0; separators[y] != '\0'; y++) {
            count += (str[i] == separators[y]) ? 1 : 0;
        }
    }
    return (count);
}

/**
 * The function iterates through a string until it reaches a separator and
 * copies the non-separator characters into a result string.
 *
 * @param str A pointer to a string that contains the characters to be parsed.
 * @param separators The separators parameter is a string containing
 * characters that are used to separate words or tokens in the input string.
 * The function is_not_separator() is used to check if a character in the
 * input string is a separator or not.
 * @param result The "result" parameter is a pointer to a character array
 * where the function will store the characters extracted from the "str"
 * parameter.
 * @param i The parameter "i" is an unsigned integer that represents the
 * current index position in the string "str". It is used in a loop to iterate
 * through the string and extract a substring until a separator character is
 * encountered. The function returns the updated value of "i" after the loop
 * completes.
 *
 * @return the updated value of the variable `i`.
 */
static uint for_boucle(char *str, char *separators, char *result, uint i)
{
    uint k = 0;

    for (k = 0; str[i] != '\0'; k++, i++) {
        if (is_not_separator(str[i], separators))
            result[k] = str[i];
        else
            break;
    }
    return (i);
}

/**
 * The function `ostr_to_array` splits a string into an array of substrings
 *  based on given separators.
 *
 * @param str The input string that needs to be split into an array of strings
 *  based on the given separators.
 * @param separators The separators parameter is a string containing all the
 * characters that can be used to separate words in the input string. The
 * function uses these separators to split the input string into an array
 * of strings.
 *
 * @return The function `ostr_to_array` returns a pointer to a dynamically
 * allocated array of strings (i.e., a pointer to a pointer to char).
 * The strings in the array are the substrings of the input string `str`
 * that are separated by any of the characters in the input string
 * `separators`. The array is terminated by a NULL pointer.
 */
char **ostr_to_array(char *str, char *separators)
{
    char **result = NULL;
    uint j = 0;

    if (!str || !separators)
        return NULL;
    result = calloc(sizeof(char *), (spcount(str, separators) + 2));
    if (!result)
        return NULL;
    for (uint i = 0; str[i]; i++) {
        while (is_not_separator(str[i], separators) == 0 && str[i] != '\0')
            i++;
        result[j] = calloc(sizeof(char), (word_size(str, i, separators) + 1));
        if (!result[j])
            return NULL;
        i = for_boucle(str, separators, result[j], i);
        j++;
        if (i >= strlen(str))
            break;
    } return result;
}
