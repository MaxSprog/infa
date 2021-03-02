#include <stdio.h>
#include <stdlib.h>

struct list{
    int val;
    struct list *prev;
    struct list *next;
};

int length(struct list *head){
    int cnt = 0;
    while (head != NULL){
        head = head->next;
        cnt++;
    }
    return cnt;
}

void printList(struct list *head){
    while(1){
        printf("|%d", head->val);
        if(head->next == NULL)
            break;
        head = head->next;
    }
    printf("|\n");
    while(1){
        printf("|%d", head->val);
        if(head->prev == NULL)
            break;
        head = head->prev;
    }
    printf("|\n");
}

struct list *insert(struct list *head, int val, int ind){ //ind = -1 -- add to end
    int n = length(head);
    if(ind > n){
        ind = n;
    }
    if(ind < 0){
        if(ind == -1){
            ind = n;
        }
        else{
            ind = 0;
        }
    }
    if(head == NULL){
        struct list *h = (struct list*)malloc(sizeof(struct list));
        h->val = val;
        h->next = NULL;
        h->prev = NULL;
        return h;
    }
    if(ind < n){
        if(ind == 0){
            struct list *h = (struct list*)malloc(sizeof(struct list));
            h->val = val;
            h->next = head;
            head->prev = h;
            h->prev = NULL;
            return h;
        }
        else{
            struct list *temp, *elem;
            elem = head;
            for (int i = 0; i < ind; i++){
                elem=elem->next;
            }
            temp = (struct list*)malloc(sizeof(struct list));
            temp->val = val;
            elem->prev->next = temp;
            temp->prev = elem->prev;
            elem->prev = temp;
            temp->next = elem;
            return head;
        }
    }
    struct list *temp = head;
    struct list *h = (struct list*)malloc(sizeof(struct list));
    
    h->val = val;
    h->next = NULL;
    for(int i = 0; i < ind && temp->next != NULL; i++)
        temp = temp->next;
    temp->next = h;
    h->prev = temp;
    return head;
}

struct list *deleteElement(struct list *head, int val){
    struct list *temp = head;
    if (temp->val == val){
        head = temp->next;
        free(temp);
        head->prev = NULL;
        return head;
    }
    while(temp->val != val){
        printf("%p  %d\n", temp, temp->val);
        temp = temp->next;
        if(temp == NULL)
            break;
    }
    if(temp == NULL)
        return head;
    struct list *nxtemp = temp->next;
    temp->prev->next = nxtemp;
    nxtemp->prev = temp->prev;
    free(temp);
    return head;
}

struct list *cycle(struct list *head, int i, int j){
    int n = length(head);
    struct list *t1 = head;
    struct list *t2 = head;
    while(i >= n || j >= n){
        head = insert(head, 0, -1);
        n = length(head);
    }
    for(int k = 0; k < i; k++){
        t1 = t1->next;
    }
    for(int k = 0; k < j; k++){
        t2 = t2->next;
    }
    t2->next = t1;
    return head;
}

int isCycled(struct list *head){
    struct list *ft = head;
    struct list *sw = head;
    while(ft->next != NULL){
        ft = ft->next;
        if(ft->next == NULL)
            return 0;
        if(ft == sw)
            return 1;
        ft = ft->next;
        sw = sw->next;
    }
    return 0;
}

struct list *sortList(struct list *head){
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    int n = length(head);
    struct list *head2;
    struct list *tmp = head;
    for(int i = 0; i < n / 2 - 1; i++){
        tmp = tmp->next;
    }
    head2 = tmp->next;
    head2->prev = NULL;
    tmp->next = NULL;
    head = sortList(head);
    head2 = sortList(head2);
    if(head->val > head2->val){
        tmp = head2;
        tmp->prev = NULL;
        head2 = head2->next;
    }
    else{
        tmp = head;
        tmp->prev = NULL;
        head = head->next;
    }
    struct list *init = tmp;
    
    while(head != NULL && head2 != NULL){
        if(head->val > head2->val){
            tmp->next = head2;
            head2 = head2->next;
            tmp->next->prev = tmp;
        }
        else{
            tmp->next = head;
            head = head->next;
            tmp->next->prev = tmp;
        }
        printList(tmp);
        tmp = tmp->next;
    }
    if(head2 == NULL && head != NULL){
        tmp->next = head;
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    else if(head == NULL && head2 != NULL){
        tmp->next = head2;
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return init;

}

void freeList(struct list *head){
    struct list *temp = head;
    while(head != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
}


int main(){
    struct list *head = NULL, *head2 = NULL;
    int n = 0, x = 0, ind = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &ind);
        head = insert(head, x, ind);
        head2 = insert(head2, x, ind);
        printList(head);
    }
    printf("_______________\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        head = deleteElement(head, x);
        head2 = deleteElement(head2, x);
        printList(head);
    }
    printf("ok1\n");
    head = sortList(head);
    printList(head);
    /*
    printf("_______________\n");
    printList(head);
    head = sortList(head);
    printList(head);
    freeList(head);*/
    cycle(head, 1, 3);
    printf("%d %d", isCycled(head), isCycled(head2));
    return 0;
}