#include <stdio.h>

main() {
    int i, c, wh, s;
    i = wh = s = 0;

    int first, second;
    first = second = 0;

    int result;
    result = 0;

    int sign;
    sign = 0;

    while ((c = getchar()) != EOF) {
        if ((c == '+') || (c == '*')) {
            sign = c;
        }
        if (c == ' ') {

            if (s != 0) {
                if (result == 0) {
                    result = first;
                } else {
                    if (sign == '+') {
                        result = result + first;
                    } else if (sign == '*') {
                        result = result * first;
                    }
                }
                s = 0;
            }

            ++wh;
        } else if (c >= '0' && c <= '9') {
            if (s == 0) {
                ++s;
                first = c - '0';
            } else {
                first = first * 10 + c - '0';
            }
        } else if (c == '\n') {
            if (sign == '+') {
                printf("sum %d\n", result + first);
            } else if (sign == '*') {
                printf("%d\n", result * first);
            }
            wh = s = result =  second = first = 0;
            sign = 0;
        }
    }
}
