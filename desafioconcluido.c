#include <stdio.h>

#define TAM 10
#define NAVIO_TAMANHO 3  // Tamanho do navio

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // Representa a água
        }
    }
}

// Função para mostrar o tabuleiro
void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
    // Exibe as letras de A até J como cabeçalho das colunas
    printf("  ");
    for (int i = 0; i < TAM; i++) {
        printf(" %c", 'A' + i);  // A até J
    }
    printf("\n");

    // Exibe as linhas do tabuleiro (1 até 10)
    for (int i = 0; i < TAM; i++) {
        printf("%2d", i + 1);  // Cabeçalho das linhas (1 até 10)
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0");  // Representa a água
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3");  // Representa as posições dos navios
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar navio horizontal
    int linha1 = 4;  // Linha inicial do navio horizontal
    int coluna1 = 3;  // Coluna inicial do navio horizontal
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        tabuleiro[linha1][coluna1 + i] = 3;  // Posições do navio
    }
    
    // Posicionar navio vertical

    int linha2 = 6;  // Linha inicial do navio vertical 
    int coluna2 = 5;  // Coluna inicial do navio vertical
    
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        tabuleiro[linha2 + i][coluna2] = 3;  // Marca as posições do navio
    }

    // Posicionar navio diagonal crescente (linha e coluna aumentam)
    int linhadiagonal1 = 0;  // Linha do navio diagonal crescente 
    int colunadiagonal1 = 0; // Coluna do navio diagonal crescente 
    
    // Loop aninhado para colocar o navio na diagonal crescente
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
    for(int j = 0; j < 1; j++){
        tabuleiro[linhadiagonal1 + i][colunadiagonal1 + i] = 3;

    }
          // Marca as posições do navio
    }
    
    // Posicionar navio diagonal decrescente (linha aumenta e coluna diminui)
    int linhadiagonal2= 7;  // Linha do navio diagonal decrescente 
    int colunadiagonal2 = 9; // Coluna do navio diagonal decrescente

    // Loop aninhado para colocar o navio na diagonal decrescente
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
    for ( int j = 0; j < 1; j++){
        tabuleiro[linhadiagonal2 + i][colunadiagonal2 - i] = 3;  // Marca as posições do navio
    }}
    
    // Exibe o tabuleiro com os navios
    mostrarTabuleiro(tabuleiro);

    return 0;
}