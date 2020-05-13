#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


typedef struct node
{
    int st;
    int ko;
    struct node* next;
} node;
typedef node* list;

void menu()
{
    setlocale(LC_ALL,"Rus");
    const char* menu = "1: Добавить(в конец).\n"
                       "2: Распечатать.\n"
                       "3: Многочлен в точке.\n"
                       ;
    printf("%s\n", menu);
}





void print(list* L)
{
    node* rn = *L;
    if (rn == NULL)
        printf("0\n");
    else
        while (rn)
        {
            if (rn == *L && rn->st != 0 && rn->ko != 1 && rn->ko != -1 && rn->st != 1)
                printf("%dx^%d ", rn->ko, rn->st);

            if (rn == *L && rn->st != 0 && rn->ko != 1 && rn->ko != -1 && rn->st == 1)
                printf("%dx ", rn->ko);

            if (rn == *L && rn->st != 0 && rn->ko == 1 && rn->st != 1)
                printf("x^%d ", rn->st);

            if (rn == *L && rn->st != 0 && rn->ko == 1 && rn->st == 1)
                printf("x ", rn->st);

            if (rn == *L && rn->st != 0 && rn->ko == -1 && rn->st != 1)
                printf("-x^%d ", rn->st);

            if (rn == *L && rn->st != 0 && rn->ko == -1 && rn->st == 1)
                printf("-x ", rn->st);

            if (rn == *L && rn->st == 0)
                printf("%d ", rn->ko);






            if (rn != *L && rn->st != 0 && rn->ko != 1 && rn->ko > 0 && rn->st != 1)
                printf("+ %dx^%d ", rn->ko, rn->st);

            if (rn != *L && rn->st != 0 && rn->ko != 1 && rn->ko > 0 && rn->st == 1)
                printf("+ %dx ", rn->ko);

            if (rn != *L && rn->st != 0 && rn->ko != -1 && rn->ko < 0 && rn->st != 1)
                printf("- %dx^%d ", (-1)*rn->ko, rn->st);

            if (rn != *L && rn->st != 0 && rn->ko != -1 && rn->ko < 0 && rn->st == 1)
                printf("- %dx ", (-1)*rn->ko);

            if (rn != *L && rn->st != 0 && rn->ko == 1 && rn->st != 1)
                printf("+ x^%d ", rn->st);

            if (rn != *L && rn->st != 0 && rn->ko == 1 && rn->st == 1)
                printf("+ x ");

            if (rn != *L && rn->st != 0 && rn->ko == -1 && rn->st != 1)
                printf("- x^%d ", rn->st);

            if (rn != *L && rn->st != 0 && rn->ko == -1 && rn->st == 1)
                printf("- x ");

            if (rn != *L && rn->st == 0 && rn->ko > 0)
                printf("+ %d ", rn->ko);

            if (rn != *L && rn->st == 0 && rn->ko < 0)
                printf("- %d ", (-1)*rn->ko);

            rn = rn->next;
        }
        printf("\n");
}


void push_end(list* L, int n, int a)
{
    if ((*L) == NULL)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->st = n;
        new_node->ko = a;
        new_node->next = (*L);
        (*L) = new_node;
    } else
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->st = n;
        new_node->ko = a;
        node* rn = *L;
        while (rn->next != NULL)
            rn = rn->next;
        new_node->next = rn->next;
        rn->next = new_node;
    }
}


void upor(list* L, double b)
{
    int i;
    double z = 0;
    double x;
    node* rn = *L;
    if (rn == NULL)
    {
        printf("P(%lf) = %lf\n", b, z);
        return;
    }
    else
    {
        while (rn)
        {
            x = b;
            if (rn->st == 0)
                z += rn->ko;
            else
            {
                for (i = 1; i < rn->st; i++)
                    x *= b;
                z += (rn->ko)*x;
            }
            rn = rn->next;
        }
    }
    printf("P(%lf) = %lf\n", b, z);
    return;
}









int main()
{
    setlocale(LC_ALL,"Rus");
    int n, a;
    double b;
    list L = NULL;
    menu();
    while (1)
        {
        int action;
        scanf("%d", &action);
        switch (action)
        {
            case 0:
                return 0;

            case 2:
                print(&L);
                break;

            case 1:
                printf("Сначала введите степень, потом ненулевой коэффициент.\n");
                scanf("%d %d", &n, &a);
                push_end(&L, n, a);
                break;

            case 3:
                scanf("%lf", &b);
                upor(&L, b);
                break;
    return 0;
        }
        }
}
