#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 10

int t1[TABLE_SIZE], t2[TABLE_SIZE], t3[TABLE_SIZE];

void init()
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++) t1[i] = t2[i] = t3[i] = -1;
}

int divHash(int key)  { return key % TABLE_SIZE; }

int midHash(int key)
{
    long sq = (long)key * key;
    char buf[40];
    int len, mid, r;
    snprintf(buf, sizeof(buf), "%ld", sq);
    len = strlen(buf);
    mid = len / 2;
    r = (len >= 2) ? (buf[mid-1]-'0')*10 + (buf[mid]-'0') : buf[0]-'0';
    return r % TABLE_SIZE;
}

int foldHash(int key)
{
    int sum = 0;
    while(key > 0) { sum += key % 100; key /= 100; }
    return sum % TABLE_SIZE;
}

void insertAll(int key)
{
    int i1 = divHash(key), i2 = midHash(key), i3 = foldHash(key);
    printf("\nKey %d  =>  Div:%d  Mid:%d  Fold:%d\n", key, i1, i2, i3);
    if(t1[i1] == -1) t1[i1] = key;
    else printf("  Division COLLISION at %d (has %d)\n", i1, t1[i1]);
    if(t2[i2] == -1) t2[i2] = key;
    else printf("  MidSquare COLLISION at %d (has %d)\n", i2, t2[i2]);
    if(t3[i3] == -1) t3[i3] = key;
    else printf("  Folding COLLISION at %d (has %d)\n", i3, t3[i3]);
}

void display()
{
    int i;
    printf("\nIdx\tDiv\tMid\tFold\n");
    for(i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        if(t1[i]==-1) printf("--\t"); else printf("%d\t", t1[i]);
        if(t2[i]==-1) printf("--\t"); else printf("%d\t", t2[i]);
        if(t3[i]==-1) printf("--\n"); else printf("%d\n", t3[i]);
    }
}

int main()
{
    int n, i, key;
    init();
    printf("=== Various Hash Functions ===\n");
    printf("Enter number of values: "); scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter key %d: ", i+1); scanf("%d", &key);
        insertAll(key);
    }
    display();
    return 0;
}
