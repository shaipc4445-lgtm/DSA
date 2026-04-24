

struct node { int data; struct node *next; };
struct node *hash_table[TABLE_SIZE];

void initialize()
{
    int i;
    for(i = 0; i < TABLE_SIZE; i++) hash_table[i] = NULL;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key)
{
    int index;
    struct node *newnode, *temp;
    index = hashFunction(key);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key; newnode->next = NULL;
    if(hash_table[index] == NULL) {
        hash_table[index] = newnode;
        printf("Key %d inserted at index %d.\n", key, index);
    } else {
        temp = hash_table[index];
        while(temp->next != NULL) temp = temp->next;
        temp->next = newnode;
        printf("Key %d inserted at index %d (chained).\n", key, index);
    }
}

void display()
{
    int i; struct node *temp;
    printf("\nIndex\tChain\n");
    for(i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        temp = hash_table[i];
        if(temp == NULL) { printf("NULL\n"); continue; }
        while(temp != NULL) { printf("%d -> ", temp->data); temp = temp->next; }
        printf("NULL\n");
    }
}

void search(int key)
{
    int index;
    struct node *temp;
    index = hashFunction(key);
    temp = hash_table[index];
    while(temp != NULL) {
        if(temp->data == key) { printf("Key %d found at index %d.\n", key, index); return; }
        temp = temp->next;
    }
    printf("Key %d NOT found.\n", key);
}

int main()
{
    int ch, key;
    initialize();
    printf("=== Hashing - Separate Chaining ===\n");
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
