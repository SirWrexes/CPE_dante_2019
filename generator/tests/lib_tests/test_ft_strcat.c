/*
** EPITECH PROJECT, 2019
** <Project_name>
** File description:
** [test_ft_strcat.c]--No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char *ft_strcat(char *src, char *dest);

char *ft_strcpy(char *src, char *dest);

Test(ft_strcat, test_ft_strcat_with_expected_result)
{
    char t1[] = "1";
    cr_expect_str_eq(ft_strcat("1", t1), "11", "F1T1");
    char t2[] = "12345";
    cr_expect_str_eq(ft_strcat("67890", t2), "1234567890", "F1T2");
    char t3[] = "";
    cr_expect_str_eq(ft_strcat("1234567890", t3), "1234567890", "F1T3");
    char t4[] = "1234567890";
    cr_expect_str_eq(ft_strcat("", t4), "1234567890", "F1T4");
    char t6[] = "";
    cr_expect_str_eq(ft_strcat("", t6), "", "F1T6");
    char t7[] = "0987654321";
    cr_expect_str_eq(ft_strcat(NULL, t7), t7, "F1T7");
}
