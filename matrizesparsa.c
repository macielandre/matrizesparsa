#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int dado;
    int coluna;
    struct no *prox;
}no;

typedef no *ptr;

typedef struct matriz{
    ptr *a;
    int linhas,colunas;
}matriz;

void inicializa_matriz(matriz *m,int linha,int coluna);
int atribui_valor(matriz *m,int linha,int coluna,int valor);
int acessa_valor(matriz *m,int lin,int col);
void inicializa_vetor(int *vet,int n);
int multiplica(matriz *m,int *vet,int linha,int coluna,int *resp);

int main(){
    int y,m,n,linha,coluna,valor,*vet,*resp;
    matriz *matriz=malloc(sizeof(matriz));
    scanf("%d%d",&m,&n);
    vet=calloc(n,sizeof(int));
    resp=calloc(m,sizeof(int));
    inicializa_matriz(matriz,m,n);
    inicializa_vetor(vet,n);
    while(scanf("%d%d%d",&linha,&coluna,&valor)!=EOF){
        y=atribui_valor(matriz,linha,coluna,valor);
    }
    multiplica(matriz,vet,m,n,resp);
    free(matriz->a);
    return 0;

}

void inicializa_matriz(matriz *m,int lin,int col){
    int i;
    m->linhas=lin;
    m->colunas=col;
    m->a=malloc(lin*sizeof(ptr));
    for(i=0;i<lin;i++){
        m->a[i]=malloc(sizeof(no*));
        m->a[i]->prox=m->a[i];
    }
}

int atribui_valor(matriz *m,int lin,int col,int val){
    ptr novo=malloc(sizeof(ptr));
    int tmp;
    if(val!=0){
        novo->prox=m->a[lin]->prox;
        m->a[lin]->prox=novo;
        tmp=m->a[lin]->dado;
        m->a[lin]->dado=val;
        m->a[lin]->coluna=col;
        m->a[lin]=novo;
        m->a[lin]->dado=tmp;
        return 1;
    }
    return 0;
}

void inicializa_vetor(int *vet,int n){
    for(int i=0;i<n;i++){
        scanf("%d",&vet[i]);
    }
}

int multiplica(matriz *m,int *vet,int linha,int coluna,int *resp){
    int i,j,soma=0;
    ptr atual;
    for(i=0;i<linha;i++){
        for(atual=m->a[i]->prox;atual!=m->a[i];atual=atual->prox){
            soma+=vet[atual->coluna]*atual->dado;
        }
        printf("%d\n",soma);
        soma=0;
    }
    return 1;
}
