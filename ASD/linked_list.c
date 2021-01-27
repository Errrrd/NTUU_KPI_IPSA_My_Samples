// Для циклічного однозв’язного списку книг (поля: title, year)

// реалізувати функції:
// а) додавання елемента у порядку зростання року видання, для книжок одного року за спаданням назви;
// б) видалення елемента з голови списку;
// в) циклічно зсунути список на k (введення з клавіатури) елементів ліворуч;
// г) надрукувати весь список, починаючи з найменшого, формат: “Title, year”;
// д) видалити весь список.

//Одна за найдовших назв (772 символи):
//История достопримечательной, полной бурных приключений, жизни высокочтимого полковника Жака, в просторечье именуемого полковником Джеком, урожденного дворянина, отданного в ученики к карманному вору, процветавшего на поприще воровства целых двадцать шесть лет, насильно увезенного в Виргинию, откуда он вернулся купцом; пять раз был женат на четырех шлюхах, участвовал в войнах, выказал отвагу, был произведен в полковники, возвратился в Англию, удостоился чести именоваться кавалером Ордена Святого Георга, был схвачен во время Престонского восстания, помилован покойным королем, остается и поныне командиром своего полка, сражающегося в царицыных войсках против турок, и завершает свою удивительную жизнь, рассчитывая умереть генералом. Написана автором Робинзона Крузо

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#define TITLESZ 1024
#define RAND_Y() (1900+rand()%121)

typedef struct linkedListBook { //книга (поля: title, year)
    char title[TITLESZ];
    int  year;
    struct linkedListBook * next;
} book;

book * createBook(char title[], int year);
void addNewBook(book** headAddr, book* newTail); // а) додавання елемента у порядку зростання року видання, для книжок одного року за спаданням назви;
void removeFromHead(book** headAddr);// б) видалення елемента з голови списку;
void shiftLeft(book** headAddr, int k); // в) циклічно зсунути список на k (введення з клавіатури) елементів ліворуч;
void printList (Book * head); //г) надрукувати весь список, починаючи з найменшого, формат: “Title, year”;
void freeList(Book** headAddr ); //д) видалити весь список.

int main(){
    book * head = NULL;
    srand( time(NULL) ); // using rand from current time
    
    freeList(&head);
    assert(head == NULL);
    
    return 0;
}

book * createBook(char title, int year)
{
    book * newBook = (Book *) malloc (sizeof(Book));
    assert(newBook != NULL);
    
    newBook->next = NULL;
    newBook->title = title;
    newBook->year = year;
    
    return newBook;
}

void addNewBook(Book** headAddr, book* newTail)
{
    
}

void removeFromHead(book** headAddr)
{
    
}
void shiftLeft(book** headAddr, int k)
{
    
}

void printList (book * head){
    printf("\n---------- Linked List ----------\n[ ");
    book * root = head;
    if(head == NULL){
        printf("is empty\n");
    } else {
        while(head->next != root){
            printf("\"%s\", %d\n", head->title, head->year);
            head = head->next;
        }
    }
}

void freeList(Book** headAddr ){
    book * temp;
    while (*headAddr !=NULL){
        temp = (*headAddr)->next;
        free(*headAddr);
        *headAddr = temp;
    }
    *headAddr = NULL;
}
