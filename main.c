#include <stdio.h>
#include <stdlib.h>



typedef struct objeto
{

    int id;
    char* denuncia;
    struct objeto * item;

} Object;

typedef struct fila
{
    Object * inicial;
    Object * fim;

} Fila;


Fila* criar(void);

int main()
{

    printf("CÓDIGO DENÚNCIA:\n");
    Fila* f = criar();
    int value=1;
    char string[50] = "zera@dengue";
    while(value<=20)
    {

        EntrarNaFila(f, 1000+value, string);
        value++;

    }
//    EntrarNaFila(f, 7);
//    removeItem(f);
//    EntrarNaFila(f, 8);
//
//    EntrarNaFila(f, 10);
    imprimir(f);

    printf("%i - valor total de itens da lista", size(f));



    return 0;



}


Fila* criar(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicial = f->fim = NULL;
}

Object* inserir(Object* item, int id, char* denuncia)
{

    Object* nItem = (Object*) malloc(sizeof(Object));
    nItem->id=id;
    nItem->denuncia = denuncia;
    nItem->item = item;
    return nItem;

}

void EntrarNaFila(Fila* f, int value, char* denuncia)
{
    Object* nItem = inserir(f->fim, value, denuncia);

    nItem->item = NULL;

    if(f->fim != NULL)
    {
        f->fim->item = nItem;

    }
    f->fim = nItem;
    if(f->inicial == NULL)
    {
        f->inicial= f->fim;
    }

}

Object* retirar(Object* item)
{

    Object*  aux = item;
    item = aux->item;
    free(aux);
    return item;

}


int vazia(Fila* f)
{

    return (f->inicial == NULL);
}



int removeItem(Fila* f)
{
    int id;
    if(vazia(f))
    {
        printf("Fila está vazia!");
        exit(1);

    }

    id  = f->inicial->id;
    f->inicial = retirar(f->inicial);
    if(f->inicial == NULL)
    {
        f->fim = NULL;

    }

    return id;


}

int size(Fila* f)
{

    int count;
    Object* p;
    for(p=f->inicial; p!=NULL; p = p->item)
    {
        count++;
    }

    return count;
}



void imprimir(Fila* f)
{
    Object* o;
    for(o=f->inicial; o!= NULL; o = o->item)
    {
        printf("%d %s\n", o->id, o->denuncia);
    }
}











