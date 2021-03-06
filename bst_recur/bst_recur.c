#include "bst_recur.h"

struct node *init_node(DTYPE data)
{
    struct node *node = malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct tree *init_tree()
{
    struct tree *tree = malloc(sizeof(struct tree));
    tree->head = NULL;
    return tree;
}

void free_tree_(struct node *node)
{
    if (node != NULL) {
        free_tree_(node->left);
        free_tree_(node->right);
        free(node);
    }
}

void free_tree(struct tree *tree)
{
    free_tree_(tree->head);
    free(tree);
}

void print_tree(struct tree *tree);

static void insert_(struct node *node, DTYPE data)
{
    // If the value is less, branch to the left
    if (data < node->data) {
        if (node->left != NULL) {
            insert_(node->left, data);
        } else {
            node->left = init_node(data);
        }
    }

    // If the value is greater, branch to the right
    else if (data >= node->data) { // Make this >= for dups
        if (node->right != NULL) {
            insert_(node->right, data);
        } else {
            node->right = init_node(data);
        }
    }
}

void insert(struct tree *tree, DTYPE data)
{
    // If there is no head
    if (tree->head == NULL) {
        tree->head = init_node(data);
        return;
    }
    insert_(tree->head, data);
}

static struct node *search_(struct node *node, DTYPE target)
{
    if (node->data == target) {
        return node;
    }

    else if (target < node->data) {
        if (node->left != NULL) {
            return search_(node->left, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    else if (target > node->data) {
        if (node->right != NULL) {
            return search_(node->right, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    return NULL; // Unreachable
}

struct node *search(struct tree *tree, DTYPE target)
{
    if (tree->head == NULL)
        return NULL;
    return search_(tree->head, target);
}

static void delete_(struct node *node, DTYPE data)
{

}

void delete(struct tree *tree, DTYPE data)
{
    if (tree->head == NULL) {
        printf("item not in tree\n");
        return;
    }

    delete_(tree->head, data);
}

static void in_order_s_(struct node *node)
{
    if (node == NULL)
        return;

    in_order_s_(node->left);
    in_order_s_(node->right);
}

// silent in order
void in_order_s(struct tree *tree)
{
    in_order_s_(tree->head);
}

void in_order_(struct node *node)
{
    if (node == NULL)
        return;

    in_order_(node->left);
    printf("%d ", node->data);
    in_order_(node->right);
}

void in_order(struct tree *tree)
{
    in_order_(tree->head);
}

struct node *minimum_(struct node *node)
{
    if (node->left == NULL)
        return node;
    return minimum_(node->left);
}

struct node *minimum(struct tree *tree)
{
    if (tree->head == NULL)
        return NULL;
    return minimum_(tree->head);
}

static struct node *maximum_(struct node *node)
{
    if (node->right == NULL)
        return node;
    return maximum_(node->right);
}

struct node *maximum(struct tree *tree)
{
    if (tree->head == NULL)
        return NULL;
    return maximum_(tree->head);
}

