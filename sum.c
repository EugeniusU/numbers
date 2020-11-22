#include <stdio.h>

main() {
    int i, wh, c;
    int first, second;
    int s;

    i = wh = 0;
    first = second = 0;
    s = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++wh;
            if (wh < 2) {
                second = first;
                first = 0;
//                printf("1s %d\n", second);
            } else {
                second = first + second;
                first = 0;
            }
        } else if (c >= '0' && c <= '9') {

            if (s == 0) {
                first = c - '0';
                ++s;
            } else {
                first = makeNum(c, first);
//                printf("%d\n", first);
             ++s;
            }
        }
        if (c == '\n') {
            printf("%d\n", second + first);
            wh = s = first = 0;
        }
    }
}

int makeNum(int c, int first) {
     first = first * 10 + c - '0';

     return first;
}
