#define MAX 50 // define o número máximo de elementos dessa estrutura

typedef int TIPOCHAVE; // cria um novo tipo inteiro para chave, explicitando que trata-se de uma chave

// estrutura em si, que poderá ter os campos úteis para o contexto e a chave
typedef struct
{
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

int tamanho(LISTA *l)
{
    return l->nroElem;
}

void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++)
    {
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}

int buscaSequancial(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    while (i < l->nroElem)
    {
        if (ch == l->A[i].chave)
            return i;
        else
            i++
    }
    return -1;
}

bool inserirElemLista(LISTA *l, REGISTRO reg, int i)
{
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for (j = l->nroElem; j > i; j--)
        l->A[j] = l->A[j - 1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA *l)
{
    int pos, j;
    pos = buscaSequancial(l, ch);
    if (pos == -1)
        return false;
    for (j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j + 1];
    l->nroElem--;
    return true;
}

void reinicializar(LISTA *l)
{
    l->nroElem = 0;
}