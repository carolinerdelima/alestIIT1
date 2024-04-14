#include <stdio.h>
#include <stdlib.h>

// Limite para o tamanho da matriz
#define MAX_TAMANHO 1000

int main() {
    FILE *arquivo;
    int linhas, colunas;

    // A matriz que armazena o conteúdo do arquivo
    char matriz[MAX_TAMANHO][MAX_TAMANHO];
    int i, j;

    // Indicador para parar a leitura
    int parar_leitura = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("casoJ50.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê a primeira linha para obter o número de linhas e colunas
    if (fscanf(arquivo, "%d %d", &linhas, &colunas) != 2) {
        perror("Erro ao ler as dimensões da matriz");
        fclose(arquivo);
        return 1;
    }

    // Verifica se o tamanho excede o limite permitido
    if (linhas > MAX_TAMANHO || colunas > MAX_TAMANHO) {
        printf("Tamanho da matriz excede o limite permitido.\n");
        fclose(arquivo);
        return 1;
    }

    // Lê o restante do arquivo para preencher a matriz
    for (i = 0; i < linhas && !parar_leitura; i++) {
        // Lê cada linha
        if (fgets(matriz[i], sizeof(matriz[i]), arquivo) == NULL) {
            perror("Erro ao ler linha do arquivo");
            fclose(arquivo);
            return 1;
        }

        // Verifica se a linha contém o caractere '#'
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] == '#') {
                printf("Caractere '#' encontrado na linha %d, coluna %d. Interrompendo leitura.\n", i + 1, j + 1);
                // Sinaliza que deve parar a leitura
                parar_leitura = 1;
                break;
            }
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Descomente as linhas abaixo para exibir a matriz
    printf("Matriz lida do arquivo:\n");
    for (i = 0; i < linhas; i++) {
        printf("%s", matriz[i]);
    }

    return 0;
}
