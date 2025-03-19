/*Nivel Intermediario
Nesse nivel implementei os novos navios diagonais, 
algumas melhorias como: correções nas informações das regras 
deixei as mensagens de erro mais clara para que possam ser corrigidas da forma correta*/
#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]){
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhas[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("    ");
    for(int k = 0; k < 10; k++)
    {
        printf("%c  ", letras[k]);
    }

    printf("\n");
    for (int i = 0; i < LINHAS; i++)
    {   
        printf("%2d  ", linhas[i]);
        for(int j = 0; j < COLUNAS; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }


}

int main(){
    int navioH[3] = {3,3,3};
    int navioV[3] = {3,3,3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};
    int tabuleiro[LINHAS][COLUNAS] = {0};
    int opcao;
    
    printf("Escolha uma opção: \n");
    printf("1. Jogar Batalha Naval\n");
    printf("2. Regras\n");
    printf("3. Sair\n");
    printf("> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("     =========================\n");
            printf("           Batalha Naval      \n");
            printf("     =========================\n");

            imprimirTabuleiro(tabuleiro);
            printf("\n");

            //inserção dos dados dos navios

            //navio horizontal
            int linhaH = 3, colunaH = 5; // definição das coordenadas
            if (colunaH + 2 < COLUNAS) // essa verificação impede que o navio ultrapasse o limite do tabuleiro, se colunaH (posição inicial) + 2 (os outros dois '3') forem menor do que 10 executa o proximo bloco
            {
                for(int i = 0; i < 3; i++)
                {
                    if(tabuleiro[linhaH][colunaH + i] != 0) // verifica se a posição está diferente de 0, caso verdadeiro, print mensagem de erro de sobreposição
                    {
                        printf("Erro: Sobreposição detectada no navio horizontal!\n");
                        return 0; //encerra o programa
                    }
                    tabuleiro[linhaH][colunaH + i] = navioH[i];
                }
            } else 
            {
                printf("Erro: Posição inválida para o navio horizontal! \n"); 
                return 0;
            }

            printf("\n");
            imprimirTabuleiro(tabuleiro);

            //navio vertical
            int linhaV = 3, colunaV = 1;
            if (linhaV + 2 < LINHAS)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(tabuleiro[linhaV + j][colunaV] != 0)
                    {
                        printf("Erro: Sobreposição detectada no navio vertical!\n");
                        return 0; //encerra o programa
                    }
                    tabuleiro[linhaV + j][colunaV] = navioV[j];
                }
            } else 
            {
                printf("Erro: Posição inválida para o navio vertical! \n"); 
                return 0;
            }

            printf("\n");
            imprimirTabuleiro(tabuleiro);

            //Primeiro Navio Diagonal
            int linhaD1 = 0, colunaD1 = 0;
            if(linhaD1 + 2 < LINHAS && colunaD1 + 2 < COLUNAS) // verificação das duas dimensões porem seguindo a mesma logica das anteriores 
            {
                for(int i = 0; i < 3; i++){
                    if(tabuleiro[linhaD1 + i][colunaD1 + i] != 0) // como os navios diagonais trabalham tanto com a coluna quanto com a linha varias vezes, a verificação deve acontecer 3 vezes
                    {
                        printf("Erro: Sobreposição detectada no navio diagonal 1!\n");
                        return 0;
                    }
                    tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
                }
            } else 
            {
                printf("Erro: Posição inválida para o navio diagonal 1! \n"); 
                return 0;
            }

            printf("\n");
            imprimirTabuleiro(tabuleiro);

            //segundo navio diagonal
            int linhaD2 = 5, colunaD2 = 3;
            if(linhaD2 + 2 < LINHAS && colunaD2 + 2 < COLUNAS) // verificação das duas dimensões porem seguindo a mesma logica das anteriores 
            {
                for(int i = 0; i < 3; i++){
                    if(tabuleiro[linhaD2 + i][colunaD2 + i] != 0) // como os navios diagonais trabalham tanto com a coluna quanto com a linha varias vezes, a verificação deve acontecer 3 vezes
                    {
                        printf("Erro: Sobreposição detectada diagonal 2!\n");
                        return 0;
                    }
                    tabuleiro[linhaD2 + i][colunaD2 + i] = navioDiagonal2[i];
                }
            } else 
            {
                printf("Erro: Posição inválida para o navio diagonal 2! \n"); 
                return 0;
            }

            printf("\n");
            imprimirTabuleiro(tabuleiro);
            return 0;

        case 2:    
            printf("Regras:\n");
            printf("O jogo se passa em um tabuleiro 10x10, onde as colunas e as linhas vão de 1-10\n");
            printf("Os navios podem ser colocados na horizontal, vertical e diagonal mas não podem se sobrepor.\n");
        break;

        case 3:
        printf("Obrigado por jogar!");
        return 0;

        default:
            printf("Erro: Opção Inválida!\n");
    }        
}