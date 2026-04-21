#include <stdio.h>
#define TABLE_SIZE 10

int hash_table[TABLE_SIZE];
int cnt = 0;

void initialize()
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++) hash_table[i] = -1;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key)
{
    int index, i;
    if(cnt == TABLE_SIZE) { printf("Table FULL!\n"); return; }
    index = hashFunction(key);
    for(i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if(hash_table[pos] == -1) {
            hash_table[pos] = key;
            cnt++;
            if(i == 0) printf("Key %d inserted at index %d.\n", key, pos);
            else printf("Key %d inserted at index %d (collision, %d probe).\n", key, pos, i);
            return;
        }
    }
    printf("Cannot insert %d.\n", key);
}

void display()
{
    int i;
    printf("\nIndex\tValue\n");
    for(i = 0; i < TABLE_SIZE; i++) {
        if(hash_table[i] == -1) printf("%d\t--\n", i);
        else printf("%d\t%d\n", i, hash_table[i]);
    }
}

void search(int key)
{
    int index, i, pos;
    index = hashFunction(key);
    for(i = 0; i < TABLE_SIZE; i++) {
        pos = (index + i) % TABLE_SIZE;
        if(hash_table[pos] == key) { printf("Key %d found at index %d.\n", key, pos); return; }
        if(hash_table[pos] == -1) break;
    }
    printf("Key %d NOT found.\n", key);
}

int main()
{
    int ch, key;
    initialize();
    printf("=== Hashing - Linear Probing ===\n");
    do {
        printf("\n1.Insert 2.Display 3.Search 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Key: "); scanf("%d",&key); insert(key); break;
            case 2: display(); break;
            case 3: printf("Key: "); scanf("%d",&key); search(key); break;
            case 4: break;
            default: printf("Invalid!\n");
        }
    } while(ch != 4);
    return 0;
}
