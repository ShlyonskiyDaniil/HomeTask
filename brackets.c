#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int check_left_bracket(char bracket)
{
    return (bracket == '(' || bracket == '{'
            || bracket == '[' || bracket == '<');
}

int check_right_bracket(char bracket)
{
    return (bracket == ')' || bracket == '}'
            || bracket == ']' || bracket == '>');
}

char get_the_bracket_left_pair(char bracket)
{
    if (bracket == ')') return '(';
    else if (bracket == '}') return '{';
    else if (bracket == ']') return '[';
    else if (bracket == '>') return '<';
    else bracket;
}
void brackets_succession_checker()
{
    int good_brackets_succession = 1;
    tStack open_brackets = create_stack();
    char bracket = getchar();
    while (bracket != '\n') {
        if (check_left_bracket(bracket)) {
            stack_push(&open_brackets, bracket);
        } else if (check_right_bracket(bracket)) {
            if (stack_empty(&open_brackets)) {
                good_brackets_succession = 0;
                break;
            }
            char pair_candidate = stack_pop(&open_brackets);
            if (get_the_bracket_left_pair(bracket) != pair_candidate) {
                good_brackets_succession = 0;
                break;
            }
        } 

        bracket = getchar();
    }
    if (good_brackets_succession
        && !stack_empty(&open_brackets)) {
        //остались незакрытые левые скобки
        good_brackets_succession = 0;
    }

    if (good_brackets_succession) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }
}
int main () {
    return 0;
}
