#include "lib.h"

void menu() {
    int abertura;
    abre:printf("DESEJA ABRIR AS ATIVIDADES DA LANCHONETE?\n - DIGITE 1\n");
    scanf("%d",&abertura);
    if(abertura==1) {
        int op, op2;
        cliente c;
        caixa *caixas = (caixa *) malloc(sizeof(caixa));
        No *cabeca = NULL;
        caixas->num = 1;
        caixas->pedidoNoCaixa = NULL;
        caixas->prioridade = true;
        caixas->quantidadeDeClientes = 0;
        inserirNoComeco(&cabeca, caixas);

        caixas = (caixa *) malloc(sizeof(caixa));
        caixas->num = 2;
        caixas->pedidoNoCaixa = NULL;
        caixas->prioridade = false;
        caixas->quantidadeDeClientes = 0;
        inserirNoComeco(&cabeca, caixas);
        pedido p;
        heapMin *cozinha;
        cozinha = criarHeapSimples(50);
        int quantidade, atvLanchonete = 0, qtdCaixas = TAM;
        int atendimento;
        int senhaPrioritaria = 0;
        int senhaNaoPrioritaria = 1;
        struct tm *timeInfo;
        time_t horaAtual;
        for (int i = 0; i < 50; i++) {
            c.pedido[i].preco = 0;
            c.pedido[i].quantidade = 0;
            strcpy(c.pedido[i].comida, "");
        }
        c.valorTotal = 0;
        c.hora = 0;
        c.segundo = 0;
        c.minuto = 0;
        printf("-----------ABRINDO AS ATIVIDADE DA LANCHONETE-----------\n ");
        printf("DOIS CAIXAS FORAM ABERTOS, UM PRIORITARIO E UM NAO PRIORITARIO\n");
        do {
            listaCaixas(cabeca);

            printf("==================================================");
            printf("\n|| 1 - RECEBER CLIENTE                          ||");
            printf("\n|| 2 - ABRIR MAIS UM CAIXA                      ||");
            printf("\n|| 3 - FECHAR CAIXA                             ||");
            printf("\n|| 4 - PAGAMENTO DE UM CLIENTE                  ||");
            printf("\n|| 5 - CONCLUIR PEDIDO NA COZINHA               ||");
            printf("\n|| 0 - ENCERRAR AS ATIVIDADES DA LANCHONETE     ||");
            printf("\n==================================================\n");

            scanf("%d", &atvLanchonete);
            if (atvLanchonete == 1) {
                LOOP:
                do {
                    system("cls");

                    puts("BEM VINDO A NOSSA LANCHONETE!");
                    puts("================================");
                    puts("|| 1 - PRIORITARIO            ||");
                    puts("|| 2 - NAO PRIORITARIO        ||");
                    puts("|| 0 - VOLTAR                 ||");
                    puts("================================");
                    scanf("%d", &atendimento);
                    time(&horaAtual);
                    timeInfo = localtime(&horaAtual);
                    c.hora = timeInfo->tm_hour;
                    c.minuto = timeInfo->tm_min;
                    c.segundo = timeInfo->tm_sec;
                    if (atendimento == 1 || atendimento == 2) {
                        do {
                            int cont = 0;
                            //--------------- Exibir menu ---------------------//
                            system("cls");
                            puts("\n------------------------LANCHONETE ----------------------------\n");
                            if (atendimento == 1) {
                                c.prioridade = true;
                            }
                            if (atendimento == 2) {
                                c.prioridade = false;
                            }
                            if (atendimento > 2 || atendimento < 1) {
                                puts("OPCAO INCORRETA!");
                            }
                            puts("==================================================================");
                            puts("||------------------------CARDAPIO------------------------------||");
                            puts("|| 1 - Coxinha de frango - R$2,50                               ||");
                            puts("|| 2 - Pastel de frango - R$3,00                                ||");
                            puts("|| 3 - Pastel de queijo - R$3,00                                ||");
                            puts("|| 4 - Pastel de carne - R$3,00                                 ||");
                            puts("|| 5 - Calzone- R$6,00                                          ||");
                            puts("|| 6 - Pizza - R$30,00                                          ||");
                            puts("|| 0 - Sair                                                     ||");
                            puts("||--------------------------------------------------------------||");
                            puts("==================================================================");
                            printf("-----------------------INFORME SUA OPCAO:-----------------------\n");
                            scanf("%d", &op);//Escolha da Opção

                            switch (op) {
                                case 1:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Coxinha de Frango");
                                    c.pedido[cont].preco = 2.50;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 2:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Pastel de Frango");
                                    c.pedido[cont].preco = 3;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 3:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Pastel de Queijo");
                                    c.pedido[cont].preco = 3;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 4:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Pastel de Carne");
                                    c.pedido[cont].preco = 3;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 5:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Calzone");
                                    c.pedido[cont].preco = 6;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 6:
                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    while (c.pedido[cont].preco != 0) {
                                        cont++;
                                    }
                                    c.pedido[cont].quantidade = quantidade;
                                    strcpy(c.pedido[cont].comida, "Pizza");
                                    c.pedido[cont].preco = 30;
                                    c.valorTotal = c.valorTotal + c.pedido[cont].preco * c.pedido[cont].quantidade;
                                    break;
                                case 0:
                                    goto LOOP;
                                    break;
                                default:
                                    system("cls");
                                    puts("OPCAO INCORRETA,TENTAR NOVAMENTE.\n");
                                    system("pause");
                                    break;
                            }
                            printf("\nFINALIZAR PEDIDO? DIGITE 1 PARA SIM E 2 PARA NAO:\n");
                            scanf("%d", &op2);
                            if (op2 == 1) {
                                bool p = c.prioridade;
                                int caixaMenosGente = buscarCaixaMenosCliente(cabeca, p);
                                time(&horaAtual);
                                timeInfo = localtime(&horaAtual);
                                c.horaConclusao = timeInfo->tm_hour;
                                c.minutoConclusao = timeInfo->tm_min;
                                c.segundoConclusao = timeInfo->tm_sec;
                                puts("Pedido cadastrado! Realize o pagamento no caixa\n");
                                c.senha = senhaNaoPrioritaria;
                                heap *novo = cria_heap(c);
                                buscarUmCaixa(cabeca, caixaMenosGente)->pedidoNoCaixa = uniao(
                                        buscarUmCaixa(cabeca, caixaMenosGente)->pedidoNoCaixa, novo);
                                buscarUmCaixa(cabeca, caixaMenosGente)->quantidadeDeClientes =
                                        buscarUmCaixa(cabeca, caixaMenosGente)->quantidadeDeClientes + 1;
                                imprime(buscarUmCaixa(cabeca, caixaMenosGente)->pedidoNoCaixa,
                                        buscarUmCaixa(cabeca, caixaMenosGente));
                                senhaNaoPrioritaria = senhaNaoPrioritaria + 1;
                                for (int i = 0; i < 50; i++) {
                                    c.pedido[i].preco = 0;
                                    c.pedido[i].quantidade = 0;
                                    strcpy(c.pedido[i].comida, "");
                                }
                                c.valorTotal = 0;
                                op = 0;
                            }
                            if (op2 > 2 || op2 < 1) {
                                puts("OPCAO INCORRETA,TENTAR NOVAMENTE.");
                            }
                            getchar();
                        } while (op != 0);
                    } else system("cls");
                    getchar();
                } while (atendimento != 0);
            }
            if (atvLanchonete == 2) {
                int abrirCaixa;
                printf("=============================");
                printf("\n|| 1 - PRIORITARIO         ||");
                printf("\n|| 2 - NAO PRIORITARIO     ||");
                printf("\n|| 0 - VOLTAR              ||");
                printf("\n=============================");

                scanf("%d", &abrirCaixa);
                if (abrirCaixa == 1) {
                    qtdCaixas = qtdCaixas + 1;
                    caixas = (caixa *) malloc(sizeof(caixa));
                    caixas->pedidoNoCaixa = NULL;
                    caixas->quantidadeDeClientes = 0;
                    caixas->prioridade = true;
                    caixas->num = qtdCaixas;
                    inserirNoComeco(&cabeca, caixas);
                    printf("UM NOVO CAIXA PRIORITARIO FOI ABERTO\n");
                }
                if (abrirCaixa == 2) {
                    qtdCaixas = qtdCaixas + 1;
                    caixas = (caixa *) malloc(sizeof(caixa));
                    caixas->pedidoNoCaixa = NULL;
                    caixas->quantidadeDeClientes = 0;
                    caixas->prioridade = false;
                    caixas->num = qtdCaixas;
                    inserirNoComeco(&cabeca, caixas);
                    printf("UM NOVO CAIXA NAO PRIORITARIO FOI ABERTO\n");
                }
                if (abrirCaixa > 2 || abrirCaixa < 0) {
                    printf("OPCAO INVALIDA!\n");
                }
                system("pause");
                system("cls");
            }
            if (atvLanchonete == 3) {
                int caixaVaiFechar, caixaMenosCliente;
                printf("Qual caixa deseja fechar?\n");
                scanf("%d", &caixaVaiFechar);
                if (caixaVaiFechar <= qtdCaixas) {
                    bool p = buscarUmCaixa(cabeca, caixaVaiFechar)->prioridade;
                    caixaMenosCliente = buscarCaixaMenosCliente(cabeca, p);
                    while (buscarUmCaixa(cabeca, caixaVaiFechar)->num ==
                           buscarUmCaixa(cabeca, caixaMenosCliente)->num) {
                        buscarUmCaixa(cabeca, caixaVaiFechar)->quantidadeDeClientes =
                                buscarUmCaixa(cabeca, caixaVaiFechar)->quantidadeDeClientes + 1;
                    }
                    cabeca->caixas.pedidoNoCaixa = uniao(buscarUmCaixa(cabeca, caixaMenosCliente)->pedidoNoCaixa,
                                                         buscarUmCaixa(cabeca, caixaVaiFechar)->pedidoNoCaixa);
                    printf("O CAIXA %d foi o unido com o caixa %d\n", buscarUmCaixa(cabeca, caixaMenosCliente)->num,
                           buscarUmCaixa(cabeca, caixaVaiFechar)->num);
                    removerCaixa(&cabeca, caixaVaiFechar);
                } else {
                    system("cls");
                    printf("ESTE CAIXA NAO EXISTE!\n");
                    system("pause");
                }
            }
            if (atvLanchonete == 4) {
                int caixaPaga = 0, opcao = 0;
                cliente Cliente;
                printf("Qual caixa deseja realizar o pagamento?\n");
                scanf("%d", &caixaPaga);
                if (temCliente(cabeca, caixaPaga) == true) {
                    Cliente = buscarUmCaixa(cabeca, caixaPaga)->pedidoNoCaixa->clientes;
                    printf("Qual a forma de pagamento?\n1 - DINHEIRO\n2 - CARTAO\n");
                    scanf("%d", &opcao);
                    system("cls");
                    if (opcao == 1) {
                        printf("PEDIDO PAGO!\n");
                        printf("-------------NOTA FISCAL-----------");
                        notaFiscal(cabeca, caixaPaga, 1);
                    }
                    if (opcao == 2) {
                        printf("PEDIDO PAGO!\n");
                        printf("-------------NOTA FISCAL-----------");
                        notaFiscal(cabeca, caixaPaga, 2);
                    }
                    inserirHeapSimples(cozinha, Cliente);
                    buscarUmCaixa(cabeca, caixaPaga)->pedidoNoCaixa = remover(
                            buscarUmCaixa(cabeca, caixaPaga)->pedidoNoCaixa);
                } else {
                    system("cls");
                    printf("ESTE CAIXA ESTA VAZIO!\n");
                    system("pause");
                }
            }
            if (atvLanchonete == 5) {
                if (cozinha->v[0].pedido[0].preco != 0) {
                    imprimirSimples(cozinha);
                    removerSimples(cozinha);
                } else {
                    printf("NENHUM PEDIDO NA COZINHA\n");
                    system("pause");
                }
            }
            if (atvLanchonete == 0) {
                while(qtdCaixas!=0){
                    removerCaixa(&cabeca,qtdCaixas);
                    qtdCaixas=qtdCaixas-1;
                }
                liberarCozinha(cozinha);
                system("cls");
                printf("LANCHONETE FECHADA!");
            }
            if (atvLanchonete < 0 || atvLanchonete > 5) {
                printf("OPCAO INVALIDA!");
            }
        } while (atvLanchonete != 0);
    }if(abertura>1 || abertura<1){
        system("cls");
        printf("OPCAO INVALIDA!\n");
        system("pause");
        goto abre;
    }
}
heap* cria_heap(cliente c){
    heap *h = (heap *)malloc(sizeof (heap));
    h->esq=NULL;
    h->dir=NULL;
    h->clientes.valorTotal=0;
    h->clientes.prioridade=false;
    h->clientes.senha=0;
    for(int i=0;i<50;i++){
        strcpy(h->clientes.pedido[i].comida,c.pedido[i].comida);
        h->clientes.pedido[i].preco=c.pedido[i].preco;
        h->clientes.pedido[i].quantidade=c.pedido[i].quantidade;
    }
    h->clientes.valorTotal=c.valorTotal;
    h->clientes.prioridade=c.prioridade;
    h->clientes.senha= c.senha;
    h->clientes.hora=c.hora;
    h->clientes.minuto=c.minuto;
    h->clientes.segundo=c.segundo;
    h->clientes.horaConclusao=c.horaConclusao;
    h->clientes.minutoConclusao=c.minutoConclusao;
    h->clientes.segundoConclusao=c.segundoConclusao;
    h->s=1;
    return h;
}

void troca_filhos (heap* a){
    heap *aux=a->esq;
    a->esq=a->dir;
    a->dir=aux;
}

heap* uniao(heap * h1, heap* h2) {
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->clientes.senha < h2->clientes.senha)
        return uniao_heaps(h1, h2);
    else
        return uniao_heaps(h2, h1);
}

heap * uniao_heaps(heap* h1, heap * h2)
{
    if(h1->esq == NULL){
        h1->esq = h2;
    }
    else{
        h1->dir = uniao(h1->dir,h2);
        if(h1->esq->s <h1->dir->s){
            troca_filhos(h1);
        }
        h1->s=h1->dir->s+1;
    }
    return h1;
}
heap* remover(heap *h){
    if (h == NULL)
        return NULL;

    heap* esquerdo = h->esq;
    heap* direito = h->dir;
    free(h);
    return uniao(esquerdo, direito);
}
caixa* buscarUmCaixa(No* cabeca,int c){
    No* corrente = cabeca;
    while (corrente != NULL) {
        if (corrente->caixas.num == c) {
            return &(corrente->caixas);  // Elemento encontrado
        }
        corrente = corrente->proximo;
    }// Elemento não encontrado
    return NULL;
}

// Função para criar um novo nó com o dado especificado
No* criarNo(caixa* c) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->caixas.quantidadeDeClientes = c->quantidadeDeClientes;
    novoNo->caixas.pedidoNoCaixa = c->pedidoNoCaixa;
    novoNo->caixas.prioridade = c->prioridade;
    novoNo->caixas.num = c->num;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoComeco(No** cabeca, caixa* c) {
    No* novoNo = criarNo(c);
    novoNo->caixas = *c;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}
int buscarCaixaMenosCliente(No* cabeca,bool p){
    int min=100,caixaNum=0;
    if (cabeca == NULL) {
        printf("Nenhum caixa aberto.\n");
        return 0;
    }

    No* menorElemento = cabeca;

    while (menorElemento != NULL) {
            if (min > menorElemento->caixas.quantidadeDeClientes) {
                if(menorElemento->caixas.prioridade==p){
                    min=menorElemento->caixas.quantidadeDeClientes;
                    caixaNum=menorElemento->caixas.num;
                }
            }
        menorElemento = menorElemento->proximo;
    }
    return caixaNum;
}
bool temCliente(No *no,int num){
    while (no != NULL) {
        if(no->caixas.num==num){
            if(no->caixas.quantidadeDeClientes!=0){
                return true;
            }else return false;
        }
        no = no->proximo;
    }
}

// Função para imprimir os elementos da lista
void listaCaixas(No* no) {
    while (no != NULL) {
        letreiro(no->caixas.pedidoNoCaixa,&no->caixas);
        no = no->proximo;
        printf("\n");
    }
    printf("\n\n");
}
void removerCaixa(No** cabeca, int num) {
    No* temp = *cabeca;
    No* prev = NULL;

    // Caso especial: remover o elemento do início da lista
    if (temp != NULL && temp->caixas.num == num) {
        *cabeca = temp->proximo;
        free(temp);
        return;
    }
    // Procurar o elemento a ser removido
    while (temp != NULL && temp->caixas.num!= num) {
        prev = temp;
        temp = temp->proximo;
    }

    // Se o elemento não foi encontrado na lista
    if (temp == NULL) {
        return;
    }

    // Remover o elemento da lista
    prev->proximo = temp->proximo;
    free(temp);
}


heapMin* criarHeapSimples(int maximo) {
    heapMin* heap = (heapMin*)malloc(sizeof(heapMin));
    heap->v = (cliente*)malloc(maximo * sizeof(cliente));
    heap->n = 0;
    return heap;
}

void troca(cliente *a, cliente *b) {
    cliente temp = *a;
    *a = *b;
    *b = temp;
}

void subir(heapMin* heap, int i) {
    if (i == 0)
        return;

    int pai = (i - 1) / 2;
    if (heap->v[pai].senha > heap->v[i].senha) {
        troca(&heap->v[pai], &heap->v[i]);
        subir(heap, pai);
    }
}

void descer(heapMin* heap, int i) {
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int menor = i;

    if (esq < heap->n && heap->v[esq].senha < heap->v[menor].senha)
        menor = esq;

    if (dir < heap->n && heap->v[dir].senha < heap->v[menor].senha)
        menor = dir;

    if (menor != i) {
        troca(&heap->v[menor], &heap->v[i]);
        descer(heap, menor);
    }
}

void inserirHeapSimples(heapMin* heap, cliente c) {
    if (heap->n >= 50) {
        printf("COZINHA LOTADA!\n");
        return;
    }

    heap->v[heap->n] = c;
    subir(heap, heap->n);
    heap->n++;
}

void removerSimples(heapMin* heap) {
    if (heap->n == 0) {
        printf("COZINHA VAZIA\n");
    }
    heap->v[0] = heap->v[heap->n - 1];
    heap->n--;
    descer(heap, 0);
}

void imprimirSimples(heapMin* heap) {
    system("cls");
    printf("-----------PEDIDO PRONTO!-----------");
    printf("\nSENHA: %d", heap->v[0].senha);
    for(int i=0;heap->v[0].pedido[i].preco!=0;i++){
        printf("\nPEDIDO: %s %dx", heap->v[0].pedido[i].comida, heap->v[0].pedido[i].quantidade);
    }
    printf("\n");
    system("pause");
}

void liberarCozinha(heapMin* heap) {
    free(heap->v);
    free(heap);
}

void letreiro(heap *h,caixa *c) {
    if (h != NULL) {
        if(c->prioridade==true){
            printf("\tCAIXA PRIORITARIO: %d\t", c->num);
        }else printf("\n\tCAIXA NAO PRIORITARIO: %d\t",c->num);
        printf("\n\tSENHA: %d\t",h->clientes.senha);
        printf("\n\tREALIZE SEU PAGAMENTO\t");
    }else{
        if(c->prioridade==true){
            printf("\n\tCAIXA PRIORITARIO: %d\t",c->num);
        }else printf("\n\tCAIXA NAO PRIORITARIO: %d\t",c->num);
        printf("\n\tCAIXA LIVRE\t");
    }
}

void notaFiscal(No *no,int caixa,int pagamento) {
    while (no !=NULL){
        if(no->caixas.num==caixa){
            if (no->caixas.pedidoNoCaixa != NULL) {
                printf("\nSENHA: %d",no->caixas.pedidoNoCaixa->clientes.senha);
                if(no->caixas.pedidoNoCaixa->clientes.prioridade==1){
                    printf("\nTIPO ATENDIMENTO: PRIORITARIO\n");
                }else printf("\nTIPO ATENDIMENTO: NAO PRIORITARIO\n");
                printf("HORARIO DE ENTRADA NO SISTEMA: %02d:%02d:%02d\n", no->caixas.pedidoNoCaixa->clientes.hora, no->caixas.pedidoNoCaixa->clientes.minuto, no->caixas.pedidoNoCaixa->clientes.segundo);
                printf("HORARIO DE CONCLUSAO DO PEDIDO: %02d:%02d:%02d\n",no->caixas.pedidoNoCaixa->clientes.horaConclusao, no->caixas.pedidoNoCaixa->clientes.minutoConclusao, no->caixas.pedidoNoCaixa->clientes.segundoConclusao);
                for (int i = 0; no->caixas.pedidoNoCaixa->clientes.pedido[i].preco != 0; i++) {
                    printf("PEDIDO: %s %dx", no->caixas.pedidoNoCaixa->clientes.pedido[i].comida, no->caixas.pedidoNoCaixa->clientes.pedido[i].quantidade);
                }
                printf("\nTOTAL PAGO: R$ %.2f\n", no->caixas.pedidoNoCaixa->clientes.valorTotal);
                if(pagamento==1){
                    printf("FORMA DE PAGAMENTO: DINHEIRO\n");
                }else{
                    printf("FORMA DE PAGAMENTO: CARTAO\n");
                }

                system("pause");
            }
        }no = no->proximo;
    }
}

void imprime(heap *h,caixa *c) {
    if (h != NULL) {
        if(c->prioridade==true){
            printf("\nCAIXA PRIORITARIO: %d",c->num);
        }else printf("\nCAIXA NAO PRIORITARIO: %d",c->num);
        printf("\nSENHA: %d",h->clientes.senha);
        if(h->clientes.prioridade==1){
            printf("\nTIPO ATENDIMENTO: PRIORITARIO\n");
        }else printf("\nTIPO ATENDIMENTO: NAO PRIORITARIO\n");
        printf("HORARIO DE ENTRADA NO SISTEMA: %02d:%02d:%02d\n", h->clientes.hora, h->clientes.minuto, h->clientes.segundo);
        printf("HORARIO DE CONCLUSAO DO PEDIDO: %02d:%02d:%02d\n", h->clientes.horaConclusao, h->clientes.minutoConclusao, h->clientes.segundoConclusao);
        for (int i = 0; h->clientes.pedido[i].preco != 0; i++) {
            printf("PEDIDO: %s %dx", h->clientes.pedido[i].comida, h->clientes.pedido[i].quantidade);
            if (h->esq != NULL)
                printf("(E:%s)", h->esq->clientes.pedido[i].comida);
            if (h->dir != NULL)
                printf("(D:%s)", h->dir->clientes.pedido[i].comida);
            printf("\n");
        }
        printf("TOTAL A PAGAR: R$ %.2f\n", h->clientes.valorTotal);
        imprime(h->esq,c);
        imprime(h->dir,c);
    }
}
