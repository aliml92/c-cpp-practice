#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20000


// single entry 
typedef struct entry{
    char *key;
    char *value;
    struct entry *next;
} entry;

// hash table
typedef struct {
    entry **entries;
} hashtable;



// hash function
unsigned int hash(const char *key) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);
    for (; i < key_len; ++i) {
        value = value * 37 + key[i];
    }
    value = value % TABLE_SIZE;
    return value;
}

entry* pair(const char *key, const char *value) {
    entry* e = malloc(sizeof(entry) * 1);
    e->key = malloc(strlen(key) + 1);
    e->value = malloc(strlen(value) + 1);
    strcpy(e->key, key);
    strcpy(e->value, value);
    e->next = NULL;
    return e;
}

// creates new base table
hashtable* create_base_table(void) {
    hashtable *ht = malloc(sizeof(hashtable) * 1);
    ht->entries = malloc(sizeof(entry*) * TABLE_SIZE);
    int i = 0;
    for (; i < TABLE_SIZE; ++i) {
        ht->entries[i] = NULL;
    }
    return ht;
}

void set(hashtable *ht, const char *key, const char *value) {
    unsigned int slot = hash(key);
    entry *e = ht->entries[slot];
    if (e == NULL) {
        ht->entries[slot] = pair(key, value);
        return;
    }
    entry *prev;
    while (e != NULL) {
        if (strcmp(e->key, key) == 0) {
            free(e->value);
            e->value = malloc(strlen(value) + 1);
            strcpy(e->value, value);
            return;
        }
        prev = e;
        e = prev->next;
    }
    prev->next = pair(key, value);
}

char* get(hashtable *ht, const char *key) {
    unsigned int slot = hash(key);
    entry *e = ht->entries[slot];
    if (e == NULL) {
        return NULL;
    }
    while (e != NULL) {
        if (strcmp(e->key, key) == 0) {
            return e->value;
        }
        e = e->next;
    }
    return NULL;
}

void del(hashtable *ht, const char *key) {
    unsigned int bucket = hash(key);
    entry *e = ht->entries[bucket];
    if (e == NULL) {
        return;
    }
    entry *prev;
    int idx = 0;
    while (e != NULL) {
        if (strcmp(e->key, key) == 0) {
            if (e->next == NULL && idx == 0) {
                ht->entries[bucket] = NULL;
            }
            if (e->next != NULL && idx == 0) {
                ht->entries[bucket] = e->next;
            }
            if (e->next == NULL && idx != 0) {
                prev->next = NULL;
            }
            if (e->next != NULL && idx != 0) {
                prev->next = e->next;
            }
            free(e->key);
            free(e->value);
            free(e);
            return;
        }
        prev = e;
        e = prev->next;
        ++idx;
    }
}

void dump(hashtable *ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry *e = ht->entries[i];
        if (e == NULL) {
            continue;
        }
        printf("slot[%4d]: ", i);
        for(;;) {
            printf("%s=%s ", e->key, e->value);
            if (e->next == NULL) {
                break;
            }
            e = e->next;
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    hashtable *ht = create_base_table();

    set(ht, "name1", "em");
    set(ht, "name2", "russian");
    set(ht, "name3", "pizza");
    set(ht, "name4", "doge");
    set(ht, "name5", "pyro");
    set(ht, "name6", "joost");
    set(ht, "name7", "kalix");

    dump(ht);

    return 0;
}