// 1. Створити файл для свого варіанту даних, табл. 1.
// 2. Реалізувати функцію зчитування вузлів дерева з файла, створеного у пп.1.
// 3. Реалізувати друк ключів вузлів дерева (у консоль або файл), використовуючи обходи:
// а) прямий;
// б) симетричний;
// в) зворотній;
// г) по рівнях.
// 4. Розробити та реалізувати алгоритм розв’язання задачі згідно з номером варіанту.
// 5. Результати оформити в звіт.
// 24 варіант. Обчислити різницю сум парних та непарних ключів вузлів, що є листям.
// 594, 813, 483, 438, 926, 433, 516, 280, 162, 287, 954, 430, 350, 855, 36, 322, 973, 325, 957, 506

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//#define SIZE 20

typedef struct treeNode {
    int key;
    struct treeNode * left;
    struct treeNode * right;
} tree;

typedef struct {
	tree ** array;
	int n;
	int head;
	int tail;
} queue;

void enqueue(queue*, tree*);
tree* dequeue(queue*);
queue * initQueue(int size);
int isEmpty(queue*);
int isFull(queue*);
void freeQueue(queue**);

int requestFileName(char fileName[]);

tree * buildTree(tree*, int);
tree * createNode(int);
int readTreeFromFile(char*, tree**);
void freeNode(tree*);
int freeTree(tree*);
void printPreOrder(tree*);
void printInOrder(tree*);
void printPostOrder(tree*);
void printLevelOrder(tree*, int);
int calcDiffOddEvenLeafs(tree*); //Обчислити різницю сум парних та непарних ключів вузлів, що є листям.

int main() {
    tree * root = NULL;
    int size = 0;
    char fileName[256]; fileName[255] = 0;
    int diffLeafs = 0;
    
    if (requestFileName(fileName) < 1) //request filename. If wrong => exit from program with error 1.
    {
        printf("File Name is not set\n");
        exit(1);
    }

    size = readTreeFromFile( fileName, &root); //"tree.txt"
    if (size == -1) //request filename. If wrong => exit from program with error 1.
    {
        printf("File not found\n");
        exit(2);
    } else if (size == 0) {
        printf("Data is not read\n");
        exit(3);
    }
    
    printf("----------------------------------- PREORDER ------------------------------------\n");
    printPreOrder(root);
    printf("\n---------------------------------------------------------------------------------\n");
    
    printf("------------------------------------ INORDER ------------------------------------\n");
    printInOrder(root);
    printf("\n--------------------------------------------------------------------------------\n");
    
    printf("----------------------------------- POSTORDER -----------------------------------\n");
    printPostOrder(root);
    printf("\n---------------------------------------------------------------------------------\n");
    
    printf("------------------------------------ LEVELORDER ---------------------------------\n");
    printLevelOrder(root, size);
    printf("\n---------------------------------------------------------------------------------\n");
    
    printf("------------ LEAFS&diff (summ even - summ odd) -------------\nCount: 0");
    diffLeafs = calcDiffOddEvenLeafs(root);
    printf(" = %d\n Difference of summ of Even and summ of Odd leafs is:%d", diffLeafs, diffLeafs);
    printf("\n------------------------------------------------------------\n");
    
    printf("Clean Tree: %d nodes were deleted\n", freeTree(root));

    return 0;
}

int requestFileName(char * fileName)
{
    int chLeftInBuff = 0;
    int scanfResult = 0;
    printf("Set please the name of file with a keys for tree.\n\
File should be in same path as program or relative/full path to file \
(<=255 symbols): ");
    
    scanfResult = scanf("%255s", fileName);
    while(getchar()!='\n') {++chLeftInBuff;}
    if(chLeftInBuff > 0) { printf("!!!User input contains more than 255 symbols (%d is extra)!!!\n"
                                , chLeftInBuff); }
    return scanfResult;
}

int readTreeFromFile(char * fileName, tree ** root)
{
    int size = 0;
    FILE *in = fopen(fileName, "r");
    
    if (in == NULL) { return -1; }; //check for error of opening file. If file wasn't open - not necessary to close it
    printf("File: \"%s\"\nKeys:", fileName);
    for( int key = 0; fscanf(in, "%d", &key) == 1; size++) {
        printf("%4d", key);
        *root = buildTree(*root, key);
    }
    printf("\n%d keys read\n\n", size);
    fclose(in);
    
    return size;
}

tree * buildTree(tree* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else {
        if (key < root->key) {
            root->left = buildTree(root->left, key);
        } else {
            root->right = buildTree(root->right, key);
        }
    }

    return root;
}

tree * createNode(int key) {
    tree * new = (tree*) malloc(sizeof(tree));
    assert(new != NULL);
    new->left = NULL;
    new->right = NULL;
    new->key = key;
    return new;

}

void printPreOrder(tree* root) {
    if (root != NULL) {
        printf("%4d", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(tree* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%4d", root->key);
        printInOrder(root->right);
    }
}

void printPostOrder(tree* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%4d", root->key);
    }
}

int freeTree(tree* root) {
    static int counter;
    
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        freeNode(root);
        counter++;
    }

    return counter;
}

void freeNode(tree* addrOfNodeInHeap) {
    //printf("%3d was successfuly cleared\n", addrOfNodeInHeap->key);    
    free(addrOfNodeInHeap);
}

void printLevelOrder(tree* root, int size) {
	queue * q = initQueue(size);
	assert(root != NULL);
	enqueue(q, root);
	while (isEmpty(q) == 0) {
		tree * node = dequeue(q);
		printf("%4d", node->key);
		if (node->left != NULL) enqueue(q, node->left);
		if (node->right != NULL) enqueue(q, node->right);
	}
	freeQueue(&q);
	assert(q == NULL);
}

void freeQueue(queue** q) {
	free((*q)->array);
	free(*q);
	*q = NULL;
}

queue * initQueue(int size) {
	queue * newQueue = (queue*) malloc(sizeof(queue));
	assert(newQueue != NULL);
	newQueue->n = size;
	newQueue->head = 0;
	newQueue->tail = 0;
	newQueue->array = (tree**) malloc(sizeof(tree*) * newQueue->n);
	assert(newQueue->array != NULL);
	return newQueue;
}

int isFull(queue * q) {
	if (q->tail == q->n - 1 && q->head == 0) return 1;
	if (q->tail + 1 == q-> head) return 1;
	return 0;
}

int isEmpty(queue * q) {
	if (q->tail == q-> head) return 1;
	return 0;
}

void enqueue(queue* q, tree* node) {
	if (isFull(q) == 1) exit(4);
	else {
		(q->array)[q->tail] = node;
		if (q->tail == q->n - 1) {
			q->tail = 0;
		} else {
			q->tail = q->tail + 1;
		}
	}
}

tree* dequeue(queue* q) {
	tree * result;
	if (isEmpty(q) == 1) exit(5);
	result = (q->array)[q->head];

	if (q->head == q->n - 1) {
		q->head = 0;
	} else {
		q->head = q->head + 1;
	}

	return result;
}

int calcDiffOddEvenLeafs(tree* root) {
    static int diff = 0;
    
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL ) { //leaf detected
            if (root->key%2 == 0) { // even
                diff+=root->key;
                printf(" + %d", root->key);
            } else {  // odd
                diff-=root->key;
                printf(" - %d", root->key);
            }
        } else {
            calcDiffOddEvenLeafs(root->left);
            calcDiffOddEvenLeafs(root->right);
        }
    }
    
    return diff;
}
