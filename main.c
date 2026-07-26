#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int A[N][N];
    int local_min_count = 0;
    int sum_above = 0;

    srand(time(NULL));

    printf("Матриця 10x10:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 101 - 50;
            printf("%4d", A[i][j]);

            if (j > i) {
                sum_above += abs(A[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int is_local_min = 1;

            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && !(ni == i && nj == j)) {
                        if (A[i][j] >= A[ni][nj]) {
                            is_local_min = 0;
                            break;
                        }
                    }
                }
                if (!is_local_min) break;
            }

            if (is_local_min) local_min_count++;
        }
    }

    printf("\nРезультати:");
    printf("\n1. Кількість локальних мінімумів: %d", local_min_count);
    printf("\n2. Сума модулів елементів вище головної діагоналі: %d\n", sum_above);

    return 0;
}
