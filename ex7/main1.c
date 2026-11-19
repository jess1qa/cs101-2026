#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS_PER_SET 7
#define MAX_NUM 69

int cmp(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

void gen_set(int set[NUMS_PER_SET]) {
    int pool[MAX_NUM];
    int i, j, tmp;

    for (i = 0; i < MAX_NUM; i++)
        pool[i] = i + 1;

    for (i = 0; i < NUMS_PER_SET; i++) {
        j = i + rand() % (MAX_NUM - i);
        tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
        set[i] = pool[i];
    }

    qsort(set, 6, sizeof(int), cmp);
}

int main() {
    int n, i, j;
    int lotto[MAX_SETS][NUMS_PER_SET];
    time_t now;
    char *timestr;
    FILE *fp;

    srand((unsigned)time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
        printf("輸入錯誤，請輸入 1 ~ 5 之間的整數！\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        gen_set(lotto[i]);

    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    now = time(NULL);
    timestr = ctime(&now);
    timestr[strcspn(timestr, "\n")] = '\0';

    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "= %s =\n", timestr);

    for (i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]:", i + 1);
        for (j = 0; j < NUMS_PER_SET; j++) {
            if (i < n)
                fprintf(fp, " %02d", lotto[i][j]);
            else
                fprintf(fp, " --");
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU ==========\n");
    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
