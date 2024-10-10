#include <stdio.h>
#include <string.h>

void registrarProblemas(int *qtd_problemas, int *codigo, char problema[][100]);
void imprimirProblemas(int *qtd_problemas, int *codigo, char problema[][100]);
void registrarSetores(int *qtd_setores, int *codigo_setor, char setor[][100]);
void imprimirSetores(int *qtd_setores, int *codigo_setor, char setor[][100]);
void registrarChamado(int *qtd_chamados, int chamados[2][10], int *qtd_problemas, int *codigo_problema, int *qtd_setores, int *codigo_setor);
void imprimirRelatorio(int *qtd_chamados, int chamados[2][10], int *qtd_problemas, int *codigo_problema, char problema[][100], int *qtd_setores, int *codigo_setor, char setor[][100]);

// MAIN ===============================================================================
int main(){
    char prob[10][100];
    int codigo_problema[10];
    int qtd_problemas = 0;

    char setor[10][100];
    int codigo_setor[10];
    int qtd_setores = 0;

    int chamado[2][10];
    int qtd_chamados = 0;

    int opc;

    do{
        printf("\n=============== SISTEMA DE REGISTRO DE SUPORTE ===============\n");
        printf("\nEscolha umas das opcoes:\n");
        printf("\n1. Registrar problemas");
        printf("\n2. Exibir problemas registrados");
        printf("\n3. Registrar setores");
        printf("\n4. Exibir setores registrados");
        printf("\n5. Registrar chamado");
        printf("\n6. Exibir relatorio");
        printf("\n7. Sair");
        printf("\nFaca sua escolha (1/2/3/4/5/6/7): ");

        scanf("%d", &opc);

        switch (opc){
            case 1:
                registrarProblemas(&qtd_problemas, codigo_problema, prob);
                break;
            case 2:
                imprimirProblemas(&qtd_problemas, codigo_problema, prob);
                break;
            case 3:
                registrarSetores(&qtd_setores, codigo_setor, setor);
                break;
            case 4:
                imprimirSetores(&qtd_setores, codigo_setor, setor);
                break;
            case 5:
                registrarChamado(&qtd_chamados, chamado, &qtd_problemas, codigo_problema, &qtd_setores, codigo_setor);
                break;
            case 6:
                imprimirRelatorio(&qtd_chamados, chamado, &qtd_problemas, codigo_problema, prob, &qtd_setores, codigo_setor, setor);
                break;
            case 7:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("Warning! Opcao invalida. Tente novamente.\n");
        }
    } while(opc != 7);
}

// REGISTRO DO PROBLEMA ================================================================
void registrarProblemas(int *qtd_problemas, int *codigo_problema, char problema[][100]){
    int i, j, codigo, flag;

    printf("\n================= Registrar novos problemas ==================\n");

    for(i = *qtd_problemas; i < 10; i++){
        flag = 0;

        printf("\nDigite o codigo do problema (ou digite '0' para encerrar): ");
        scanf("%d", &codigo);

        if(codigo < 0){
            printf("Warning! Numero menor que 0. Selecione '1.Registrar problemas' novamente e digite um numero valido!\n");
            break;
        }

        if(codigo == 0) {
            break;
        }

        for(j = 0; j < *qtd_problemas; j++){
            if(codigo_problema[j] == codigo){
                printf("Warning! Codigo ja existente. Digite novamente!\n");
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            continue;
        }

        codigo_problema[*qtd_problemas] = codigo;
        
        printf("Digite a descricao do problema: ");
        scanf(" %[^\n]", problema[*qtd_problemas]);
        
        *qtd_problemas += 1;
    }
}

// IMPRIMIR PROBLEMAS =================================================================
void imprimirProblemas(int *qtd_problemas, int *codigo_problema, char problema[][100]){
    printf("\n=============== Exibir problemas registrados =================\n");

    int i, max = *qtd_problemas;

    if(max == 0) {
        printf("\nWarning! Nenhuma problema registrado ainda. Por favor, registre problemas antes de solicitar a impressao.");
    } else {
        for(i = 0; i < max; i++){
            printf("\nCodigo: %d | Problema: %s", codigo_problema[i], problema[i]);
        }
    }

    printf("\n");
}

// REGISTRO DO SETOR ==================================================================
void registrarSetores(int *qtd_setores, int *codigo_setor, char setor[][100]){
    int i, j, codigo, flag;

    printf("\n================== Registrar novos setores ===================\n");

    for(i = *qtd_setores; i < 10; i++){
        flag = 0;

        printf("\nDigite o codigo do setor (ou digite '0' para encerrar): ");
        scanf("%d", &codigo);

        if(codigo < 0){
            printf("Warning! Numero menor que 0. Selecione '3.Registrar setores' novamente e digite um numero valido!\n");
            break;
        }

        if(codigo == 0) {
            break;
        }

        for(j = 0; j < *qtd_setores; j++){
            if(codigo_setor[j] == codigo){
                printf("Warning! Codigo ja existente. Digite novamente!\n");
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            continue;
        }

        codigo_setor[*qtd_setores] = codigo;
        
        printf("Digite o nome do setor: ");
        scanf(" %[^\n]", setor[*qtd_setores]);
        
        *qtd_setores += 1;
    }
}

// IMPRIMIR SETORES ===================================================================
void imprimirSetores(int *qtd_setores, int *codigo_setor, char setor[][100]){
    printf("\n================ Exibir setores registrados ==================\n");

    int i, max = *qtd_setores;

    if(max == 0) {
        printf("\nWarning! Nenhuma setor registrado ainda. Por favor, registre setores antes de solicitar a impressao.");
    } else {
        for(i = 0; i < max; i++){
            printf("\nCodigo: %d | Setor: %s", codigo_setor[i], setor[i]);
        }
    }

    printf("\n");
}

// REGISTRO DE CHAMADO ================================================================
void registrarChamado(int *qtd_chamados, int chamados[2][10], int *qtd_problemas, int *codigo_problema, int *qtd_setores, int *codigo_setor){
    int j, flag, escProblema, escSetor;
    
    printf("\n==================== Registrar chamados ======================\n");

    // Escolher o codigo do setor ===========================================
    do{
        printf("\nDigite o codigo do setor solicitante: ");
        scanf("%d", &escSetor);

        flag = 0;

        for(j = 0; j < *qtd_setores; j++){
            if(codigo_setor[j] == escSetor){
                flag = 1;
            }
        }

        if(flag == 0){
            printf("Warning! Codigo nao existe. Digite um valido!\n");
        }

    } while(flag == 0);

    // Escolher o codigo do problema ========================================
    do{
        printf("Digite o codigo do problema: ");
        scanf("%d", &escProblema);

        flag = 0;

        for(j = 0; j < *qtd_problemas; j++){
            if(codigo_problema[j] == escProblema){
                flag = 1;
            }
        }

        if(flag == 0){
            printf("Warning! Codigo nao existe. Digite um valido!\n");
        }

    } while(flag == 0);

    if(*qtd_chamados < 10){
        chamados[0][*qtd_chamados] = escSetor;
        chamados[1][*qtd_chamados] = escProblema;
        printf("\nChamado registrado com sucesso!\n");

        *qtd_chamados += 1;
    }
    else{
        printf("\nLimite de chamados atingidos. Nao e possivel registrar.\n");
    }
}

// IMPRIMIR CHAMADOS | RELATORIO ======================================================
void imprimirRelatorio(int *qtd_chamados, int chamados[2][10], int *qtd_problemas, int *codigo_problema, char problema[][100], int *qtd_setores, int *codigo_setor, char setor[][100]){
    int i, j, indexProblema, indexSetor, escSetor, escProblema, max = *qtd_chamados;
    
    printf("\n=============== Exibir historico de chamados =================\n");

    if(max == 0) {
        printf("\nWarning! Ainda nao ha chamados para que o relatorio seja impresso. Por favor, registre chamados antes de solicitar a impressao do relatorio.");
    } else { 
        for(i = 0; i < max; i++){
            escSetor = chamados[0][i];
            escProblema = chamados[1][i];

            for(j = 0; j < *qtd_problemas; j++){
                if(codigo_problema[j] == escProblema){
                    indexProblema = j;
                    break;
                }
            }

            for(j = 0; j < *qtd_setores; j++){
                if(codigo_setor[j] == escSetor){
                    indexSetor = j;
                    break;
                }
            }

            printf("\nSetor: %s | Problema: %s", setor[indexSetor], problema[indexProblema]);

        }
    }

    printf("\n");
}