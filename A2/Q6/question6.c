# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct node {
  char * name;
  char * tea;
  struct node * Left;
  struct node * right;
} Node;

int max (int a, int b) {
  if (a < b) {
    return b;
  }
  return a;
}

int depth (Node * root) {
  if (root == NULL) {
    return 0;
  }
  int left_height = depth (root -> Left);
  int right_height = depth (root -> right);

  return 1 + max (left_height, right_height);
}

void dfs_helper (Node * root, char * key, int * comparisons, int * found) {
  if (root == NULL) {
    return;
  }
*comparisons += 1;

 if (strcmp(key, root -> name) == 0) {
   *found = 1;
   return;
}

dfs_helper (root -> Left, key, comparisons, found);
if (*found == 1) {
  return;
}

dfs_helper (root -> right, key, comparisons, found);
}

int dfs (Node * root, char * key) {
  int comparisons = 0;        
  int found = 0;
  dfs_helper(root, key, &comparisons, &found);

  if (found == 0) {
    return -1;
  }
  return comparisons;
}

int main() {
    
    Node *root = malloc(sizeof(Node));
    root->name = "Nicholas";
    root->tea = "Orange Pekoe with Lemon";
    root->left = malloc(sizeof(Node));
    root->left->left = malloc(sizeof(Node));
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right = malloc(sizeof(Node));
    root->right->left = malloc(sizeof(Node));
    root->right->right = malloc(sizeof(Node));
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = malloc(sizeof(Node));
    root->right->left->right->left = malloc(sizeof(Node));
    root->right->left->right->right = NULL;
    root->right->left->right->left->left = NULL;
    root->right->left->right->left->right = NULL;
    
    root->left->name = "Mark";
    root->left->tea = "Green";
    root->right->left->name = "Soroush";
    root->right->left->tea = "Oolong";
    
    root->right->name = "Parker";
    root->right->tea = "Rooibos";
    
    root->right->right->name = "Other Mark";
    root->right->right->tea = "Sencha";
    
    root->left->left->name = "Swaleh";
    root->left->left->tea = "White";
    
    root->right->left->right->name = "Ana";
    root->right->left->right->tea = "Hibiscus";
    
    root->right->left->right->left->name = "Bassel";
    root->right->left->right->left->tea = "Matcha";
    
    printf("The depth of the tree is: %d\n", depth(root));
    // expected result is 5.
    
    printf("Depth First Search for : Nicholas\n");
    printf("result: %d\n", dfs(root, "Nicholas"));
    // expected result is 1
    
    printf("Depth First Search for : Other Mark\n");
    printf("result: %d\n", dfs(root, "Other Mark"));
    // expected result is 8
    
    printf("Depth First Search for : Parker\n");
    printf("result: %d\n", dfs(root, "Parker"));
    
    printf("Depth First Search for : Soroush\n");
    printf("result: %d\n", dfs(root, "Soroush"));
    
    printf("Depth First Search for : Swaleh\n");
    printf("result: %d\n", dfs(root, "Swaleh"));
    
    printf("Depth First Search for : Ana\n");
    printf("result: %d\n", dfs(root, "Ana"));
    // expected result is 4
    
    printf("Depth First Search for : Julius Ceasar\n");
    printf("result: %d\n", dfs(root, "Julius Ceasar"));
    // expected result is -1
    
    free(root->right->left->right->left);
    free(root->right->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root->left->left);
    free(root->left);
    free(root);
  
    return 0;
}
