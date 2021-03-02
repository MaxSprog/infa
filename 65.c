#include <stdio.h>
#include <stdlib.h>

struct human{
    int height;
    int weight;
    int age;
};

void swap(struct human*a, struct human*b){
    struct human c = *b;
    *b = *a;
    *a = c;
}

void sort(int n, struct human* p){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(p[j - 1].height > p[j].height){
                swap(&p[j-1], &p[j]);
            }
            else if(p[j - 1].height == p[j].height){
                if(p[j - 1].weight > p[j].weight){
                    swap(&p[j-1], &p[j]);
                }
                else if(p[j - 1].weight == p[j].weight){
                    if(p[j - 1].age > p[j].age){
                        swap(&p[j-1], &p[j]);
                    }
                }
            }
        }
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    struct human person[n];
    for(int i = 0; i < n; i++){
        printf("\nHeight, weight, age: ");
        scanf("%d %d %d", &person[i].height, &person[i].weight, &person[i].age);
    }
    sort(n, person);
    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", person[i].height, person[i].weight, person[i].age);
    }
    return 0;
}
