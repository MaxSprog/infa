#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str){
    size_t i = 0;
    while(str[i++] != '\0'){}
    return i - 1;
}
char *strcpy(char *toHere, const char *fromHere){
    int i = 0;
    do{
        toHere[i] = fromHere[i];
    } while(fromHere[i++] != '\0');
    return toHere;
}
int strcmp(const char *s1, const char *s2){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if((int)s1[i] < (int)s2[i])
            return -1;
        else if((int)s1[i] > (int)s2[i])
            return 1;
        i++;
    }
    if(strlen(s1) > strlen(s2)) {return 1;}
    else if(strlen(s1) < strlen(s2)) {return -1;}
    return 0;
}
char *strcat(char *dest, const char *src){
    int n = (int)strlen(dest);
    int i = n;
    for(; src[i - n] != '\0'; i++){
        dest[i] = src[i - n];
    }
    dest[i] = '\0';
    return dest;
}
char *strstr(const char *haystack, const char *needle){
    char *buf = haystack;
    char *nd = needle;
    while (*haystack != '\0' && *nd != '\0'){
        //printf("%s %s\n", haystack, nd);
        if(*haystack == *nd){
            nd++;
            buf = haystack;
        }
        else if(nd != needle){
            nd = needle;
            haystack = buf;
        }
        haystack++;
    }
    //printf("%s %s\n", haystack, nd);
    if(*nd == '\0'){
        return buf - 1;
    }
    return NULL;
}

int main(){
    char str1[] = "423456";
    char str2[] = "45";
    printf("%d\n", (int)strlen(str1));
    //printf("%s\n", strcpy(str2, str1));
    //printf("%s\n", str2);
    printf("%d\n", strcmp(str1, str2));
    //strcat(str1, str2);
    //printf("%s\n", str1);
    printf("%s", strstr(str1, str2));
    return 0;
}