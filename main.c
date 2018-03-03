#include <stdio.h>

#define TRUE 1
#define FALSE 0

int x[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void show() {
    printf("{");
    for (int i = 1; i <= 10; i++) {
        printf("%d", x[i]);
        if (i != 10)
            printf(",");
    }
    printf("} ");
}

int inc() {
    int sum = 0;
    for (int i = 1; i <= 10; i++)
        sum += x[i];
    if (sum == 4 * 10)
        return FALSE;
    
    for (int i = 1; i <= 10; i++) {
        if (x[i] < 4) {
            x[i]++;
            break;
        } else {
            for (int j = i; j < 10; j++) {
                x[j] = 1;
                if (x[j + 1] < 4) {
                    x[j + 1]++;
                    goto success;
                }
            }
        }
    }
success:
    return TRUE;
}

void count(int c[]) {
    for (int i = 1; i <= 10; i++)
        c[x[i]]++;
}

int which_min(const int c[]) {
    int m = c[1];
    for (int i = 2; i <= 4; i++) {
        if (m > c[i])
            m = c[i];
    }
    for (int i = 1; i <= 4; i++) {
        if (m == c[i])
            return i;
    }
    return -1;
}

void sort(int c[]) {
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4 - i; j++)
            if (c[j] > c[j + 1]) {
                c[0] = c[j];
                c[j] = c[j + 1];
                c[j + 1] = c[0];
            }
}

int which_true(int a, int b, int c, int d) {
    if (a + b + c + d != 1)
        return FALSE;
    else if (a == 1)
        return 1;
    else if (b == 1)
        return 2;
    else if (c == 1)
        return 3;
    else
        return 4;
}

int f2(void) {
    int z = which_true(x[5] == 3,
                       x[5] == 4,
                       x[5] == 1,
                       x[5] == 2);
    printf("f2=%d; ", z);
    return z == x[2];
}

int f3(void) {
    int z = which_true(x[3] != x[6] && x[3] != x[2] && x[3] != x[4],
                       x[6] != x[3] && x[6] != x[2] && x[6] != x[4],
                       x[2] != x[3] && x[2] != x[6] && x[2] != x[4],
                       x[4] != x[3] && x[4] != x[6] && x[4] != x[2]);
    printf("f3=%d; ", z);
    return z == x[3];
}

int f4(void) {
    int z = which_true(x[1] == x[5] && x[2] != x[7] && x[1] != x[9] && x[6] !=x[10],
                       x[1] != x[5] && x[2] == x[7] && x[1] != x[9] && x[6] !=x[10],
                       x[1] != x[5] && x[2] != x[7] && x[1] == x[9] && x[6] !=x[10],
                       x[1] != x[5] && x[2] != x[7] && x[1] != x[9] && x[6] ==x[10]);
    printf("f4=%d; ", z);
    return z == x[4];
}

int f5(void) {
    int z = which_true(x[5] == x[8] && x[5] != x[4] && x[5] != x[9] && x[5] != x[7],
                       x[5] != x[8] && x[5] == x[4] && x[5] != x[9] && x[5] != x[7],
                       x[5] != x[8] && x[5] != x[4] && x[5] == x[9] && x[5] != x[7],
                       x[5] != x[8] && x[5] != x[4] && x[5] != x[9] && x[5] == x[7]);
    printf("f5=%d; ", z);
    return z == x[5];
}

int f6(void) {
    int z =  which_true(x[2] == x[8] && x[4] == x[8],
                        x[1] == x[8] && x[6] == x[8],
                        x[3] == x[8] && x[10] == x[8],
                        x[5] == x[8] && x[9] == x[8]);
    printf("f6=%d; ", z);
    return z == x[6];
}

int f7(void) {
    int c[] = {0, 0, 0, 0, 0};
    count(c);
    int m = which_min(c);
    int z =  which_true(m == 3,
                        m == 2,
                        m == 1,
                        m == 4);
    printf("f7=%d; ", z);
    return z == x[7];
}

int f8(void) {
    int z = which_true(!(x[1] - x[7] == 1 || x[1] - x[7] == -1),
                       !(x[1] - x[5] == 1 || x[1] - x[5] == -1),
                       !(x[1] - x[2] == 1 || x[1] - x[2] == -1),
                       !(x[1] - x[10] == 1 || x[1] - x[10] == -1));
    printf("f8=%d; ", z == x[8]);
    return z == x[8];
}

int f9(void) {
    int z = which_true(x[1] == x[6] ^ x[6] == x[5],
                       x[1] == x[6] ^ x[10] == x[5],
                       x[1] == x[6] ^ x[2] == x[5],
                       x[1] == x[6] ^ x[9] == x[5]);
    printf("f9=%d; ", z);
    return z == x[9];
}

int f10(void) {
    int c[] = {0, 0, 0, 0, 0};
    count(c);
    sort(c);
    int z = which_true(c[4] - c[1] == 3,
                       c[4] - c[1] == 2,
                       c[4] - c[1] == 4,
                       c[4] - c[1] == 1);
    printf("f10=%d; ", z);
    return z == x[10];
}

int main(int argc, const char * argv[]) {
    while (1) {
        show();
        if (f2() && f3() && f4() && f5() && f6() && f7() && f8() && f9() && f10()) {
            printf("Success!\n");
            getchar();
        }
        printf("\n");
        if (!inc())
            break;
    }
    return 0;
}
