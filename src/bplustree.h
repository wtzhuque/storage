/*
 * Copyright (C) 2017, Leo Ma <begeekmyfriend@gmail.com>
 */

#ifndef __BPLUS_TREE_H__
#define __BPLUS_TREE_H__

#include <stdint.h>

/* 5 node caches are needed at least for self, left and right sibling, sibling
 * of sibling, parent and node seeking */
#define MIN_CACHE_NUM 5

#define list_entry(ptr, type, member) \
        ((type *)((char *)(ptr) - (size_t)(&((type *)0)->member)))

#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

#define list_last_entry(ptr, type, member) \
	list_entry((ptr)->prev, type, member)

#define list_for_each(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
        for (pos = (head)->next, n = pos->next; pos != (head); \
                pos = n, n = pos->next)

//typedef int key_t;
typedef uint64_t btree_key;
typedef uint32_t btree_off;

struct list_head {
        struct list_head *prev, *next;
};

static inline void list_init(struct list_head *link) {
        link->prev = link;
        link->next = link;
}

static inline void
__list_add(struct list_head *link, struct list_head *prev, struct list_head *next) {
        link->next = next;
        link->prev = prev;
        next->prev = link;
        prev->next = link;
}

static inline void __list_del(struct list_head *prev, struct list_head *next)
{
        prev->next = next;
        next->prev = prev;
}

static inline void list_add(struct list_head *link, struct list_head *prev)
{
        __list_add(link, prev, prev->next);
}

static inline void list_add_tail(struct list_head *link, struct list_head *head)
{
	__list_add(link, head->prev, head);
}

static inline void list_del(struct list_head *link)
{
        __list_del(link->prev, link->next);
        list_init(link);
}

static inline int list_empty(const struct list_head *head)
{
	return head->next == head;
}

typedef struct bplus_node {
        btree_off self;
        btree_off parent;
        btree_off prev;
        btree_off next;
        int type;
        /* If leaf node, it specifies  count of entries,
         * if non-leaf node, it specifies count of children(branches) */
        int children;
} bplus_node;

typedef struct free_block {
        struct list_head link;
        btree_off offset;
} free_block;

struct bplus_tree {
        char *caches;
        int used[MIN_CACHE_NUM];
        char filename[1024];
        int fd;
        int level;
        btree_off root;
        btree_off file_size;
        struct list_head free_blocks;
};
void bplus_tree_dump(struct bplus_tree *tree);
long bplus_tree_get(struct bplus_tree *tree, btree_key key);
int bplus_tree_put(struct bplus_tree *tree, btree_key key, long data);
long bplus_tree_get_range(struct bplus_tree *tree, btree_key key1, btree_key key2);
struct bplus_tree *bplus_tree_init(const char *filename, int block_size);
void bplus_tree_deinit(struct bplus_tree *tree);
int bplus_open(const char *filename);
void bplus_close(int fd);

#endif  // __BPLUS_TREE_H__
