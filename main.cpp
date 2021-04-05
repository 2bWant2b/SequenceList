#include <cstdio>
#include <malloc.h>
#define MaxSize 50
typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void createList(SqList *&L,ElemType a[],int n){
    L=(SqList * )malloc(sizeof (SqList));
    for (int i=0;i<n;i++){
        L->data[i]=a[i];
    }
    L->length=n;
}

void initList(SqList *&L){
    L=(SqList*)malloc(sizeof(SqList));
    L->length=0;
}

void destroyList(SqList *&L){
    free(L);
}

bool isEmpty(SqList *L){
    return (L->length==0);
}

int  getListLength(SqList *L){
    return (L->length);
}

void dispList(SqList *L){
    for (int i=0;i<L->length;i++){
        printf("%c",L->data[i]);
    }
    printf("\n");
}

bool getElem(SqList *L,int i,ElemType &e){
    if (i<1 || i>L->length){
        return false;
    }
    e=L->data[i-1];
    return true;
}

int getLocateElem(SqList *L,ElemType e){
    int i=0;
    while (i<L->length&&L->data[i]!=e){
        i++;
    }
    if (i>=L->length){
        return 0;
    } else{
        return i+1;
    }
}

bool insertElem(SqList *L,int i,ElemType e){
    int j;
    if(i<1 || i>L->length+1){
        return false;
    }
    i--;
    for (j=L->length;j>i;j--){
        L->data[j]=L->data[j-1];
    }
    L->data[i]=e;
    L->length++;
    return true;
}

bool deleteElem(SqList *L,int i,ElemType &e){
    int j;
    if (i<1 || i>L->length){
        return false;
    }
    i--;
    e=L->data[i];
    for (j=i; j < L->length-1; j++) {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

void deleteRepeatedElem(SqList *L){
    int slow=0;
    int fast=0;
    int count=0;
    for (;fast<L->length;fast++) {
        if (L->data[fast + 1] > L->data[fast]) {
            L->data[slow]=L->data[fast];
            slow++;
        } else{
            count++;
        }
    }
    L->length-=count;
}

int main() {
    printf("-------------Basic questions 1(1)---------------\n");
    SqList *L;
    ElemType e;
    initList(L);
    printf("%s\n",(isEmpty(L)?"yes":"no"));
    insertElem(L,1,'a');
    insertElem(L,2,'b');
    insertElem(L,3,'c');
    insertElem(L,4,'d');
    insertElem(L,5,'e');
    dispList(L);
    printf("%d\n",getListLength(L));
    getElem(L,3,e);
    printf("%c\n",e);
    printf("%d\n",getLocateElem(L,'a'));
    insertElem(L,4,'f');
    dispList(L);
    deleteElem(L,3,e);
    dispList(L);
    printf("%s\n",(isEmpty(L)?"yes":"no"));
    destroyList(L);
    printf("%s\n",(isEmpty(L)?"yes":"no"));
    printf("-------------Basic questions 1(2)---------------\n");
    SqList *N;
    char a[5]={'q','w','e','r','d'};
    createList(N, reinterpret_cast<ElemType *>(a), 5);
    dispList(N);
    printf("-------------Additional questions 1---------------\n");
    SqList *M;
    initList(M);
    insertElem(M,1,'0');
    insertElem(M,2,'0');
    insertElem(M,3,'2');
    insertElem(M,4,'4');
    insertElem(M,5,'4');
    insertElem(M,6,'4');
    insertElem(M,7,'7');
    insertElem(M,8,'7');
    dispList(M);
    deleteRepeatedElem(M);
    dispList(M);
    printf("%d\n",getListLength(M));
    printf("-------------Additional questions 2(1&2)---------------\n");
    int var1;
    printf("var1 : %p\n", &var1  );
    char var2[5];
    for(int i=0; i<2; i++) {
        printf("char_var2[%d] : %p\n", i, &var2[i]);
    }
    int var3[5];
    for(int i=0; i<2; i++) {
        printf("int_var3[%d] : %p\n", i, &var3[i]);
    }
    float var4[5];
    for(int i=0; i<2; i++) {
        printf("float_var4[%d] : %p\n", i, &var4[i]);
    }
    double var5[5];
    for(int i=0; i<2; i++) {
        printf("double_var5[%d] : %p\n", i, &var5[i]);
    }
    printf("-------------Additional questions 2(3)---------------\n");
    struct player{
        int number;
        int age;
    }team[3];
    for (int i=0;i<3;i++){
        printf("team_age : %p\n", i, &team[i].age);
    }
    for (int i=0;i<3;i++){
        printf("team_number : %p\n", i, &team[i].number);
    }
}

