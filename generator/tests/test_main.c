/*
** EPITECH PROJECT, 2019
** <Project_name>
** File description:
** [test_main.c]--No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main(int ac, char **av);

Test(main, test_main_with_expected_result)
{
    char *av1[2] = {"a.out", "foo"};
    char *av2[3] = {"a.out", "foo", "bar"};

    cr_expect_eq(main(2, av1), 0, "F1T1");
    cr_expect_eq(main(3, av2), 84, "F1T2");
}
