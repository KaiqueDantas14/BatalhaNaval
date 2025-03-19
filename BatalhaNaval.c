/*Nível Iniciante
Nesse nível comecei as logicas de impressão de tabuleiro atráves de uma função, 
adicionei a logica dos navio horizontal e vertical e também duas verificações, uma para garantir que os navios não ultrapassem os limites do tabuleiro e outra para que não sobreponha outro navio*/

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
            int linhaH = 2, colunaH = 3; // definição das coordenadas
            if (colunaH + 2 < COLUNAS) // essa verificação impede que o navio ultrapasse o limite do tabuleiro
            {
                for(int i = 0; i < 3; i++)
                {
                    if(tabuleiro[linhaH][colunaH + i] != 0) // verifica se a posição está diferente de 0, caso verdadeiro, print mensagem de erro de sobreposição
                    {
                        printf("Erro: Sobreposição detectada!\n");
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
            printf("\n");

            //navio vertical
            int linhaV = 4, colunaV = 6;
            if (linhaV + 2 < LINHAS)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(tabuleiro[linhaV + j][colunaV] != 0)
                    {
                        printf("Erro: Sobreposição detectada!\n");
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
            return 0;

        case 2:    
            printf("Regras:\n");
            printf("O jogo se passa em um tabuleiro 10x10, onde as colunas e as linhas vão de 0-9\n");
            printf("Os navios podem ser colocados na horizontal e diagonal mas não podem se sobrepor.\n");
        break;

    }        
}