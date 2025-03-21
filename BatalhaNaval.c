/* Nível mestre, 
nesse nível criei novas logicas para as habilidades que vão ser representadas pelo numero 1, 
optei por fazer isso com funções para simplificar o código, 
melhorei comentários 
e me certifiquei que as novas habilidades não ultrapassem os limites do tabuleiro*/
#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS]){ // função para imprimir tabuleiro
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

void desenharCone(int tabuleiro[LINHAS][COLUNAS], int cone[3][5], int linhacone, int colunacone) 
{
    /* 
     Verifica se o cone está dentro dos limites do tabuleiro (10x10)
     O cone ocupa 3x5, então checa se a posição inicial + 2 (altura do cone) 
     e + 4 (largura do cone) não ultrapassam os limites do tabuleiro (linhas de 0 a 9, colunas de 0 a 9).
    */
    if (linhacone < 0 || linhacone + 2 >= LINHAS || colunacone < 0 || colunacone + 4 >= COLUNAS)
    {
        printf("Habilidade Cone Fora dos limites do tabuleiro!\n");
        return;
    }
    
    // Caso a habilidade esteja dentro dos limites, desenha o cone
    for (int i = 0; i < 3; i++) // percorre as linhas
    {   
        for (int j = 0; j < 5; j++) // percorre as colunas
        {
            tabuleiro[linhacone + i][colunacone + j] = cone[i][j]; // desenha
        }
    }
}

void desenharCruz(int tabuleiro[LINHAS][COLUNAS], int cruz[3][5], int linhacruz, int colunacruz)
{
    /*
      Verifica se a cruz está dentro dos limites do tabuleiro (10x10)
      A cruz ocupa 3x5, então checa se a posição inicial + 2 (altura da cruz) 
      e + 4 (largura da cruz) não ultrapassam os limites do tabuleiro (linhas de 0 a 9, colunas de 0 a 9).
      Como a cruz tem um deslocamento de -1, o cálculo é ajustado para garantir que o desenho não saia dos limites.
    */
    if (linhacruz < 0 || linhacruz + 2 >= LINHAS || colunacruz < 0 || colunacruz + 4 >= COLUNAS)
    {
        printf("Habilidade Cruz Fora dos limites do tabuleiro!\n");
        return;
    }

    // Caso a habilidade esteja dentro dos limites, desenha a cruz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tabuleiro[linhacruz + i - 1][colunacruz + j - 1] = cruz[i][j]; // ajusta o deslocamento
        }
    }
}

void desenharOctaedro(int tabuleiro[LINHAS][COLUNAS], int octaedro[3][3], int linhaocta, int colunaocta)
{
    /* 
     Verifica se o octaedro está dentro dos limites do tabuleiro (10x10)
     O octaedro ocupa 3x3, então checa se a posição inicial + 2 (tamanho do octaedro) 
     não ultrapassa os limites do tabuleiro (linhas e colunas de 0 a 9). 
    */
    if (linhaocta < 0 || linhaocta + 2 >= LINHAS || colunaocta < 0 || colunaocta + 2 >= COLUNAS)
    {
        printf("Habilidade Octaedro Fora dos limites do tabuleiro!\n");
        return;
    }

    // Caso a habilidade esteja dentro dos limites, desenha o octaedro
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[linhaocta + i - 1][colunaocta + j - 1] = octaedro[i][j]; // ajusta o deslocamento
        }
    }
}

int main()
{
    int navioH[3] = {3,3,3};
    int navioV[3] = {3,3,3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};
    int tabuleiro[LINHAS][COLUNAS] = {0};
    int opcao;

    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    int octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };


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
            int linhaH = 4, colunaH = 3; // definição das coordenadas
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

            //segundo navio diagonal
            int linhaD2 = 7, colunaD2 = 7;
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

            //cone
            desenharCone(tabuleiro, cone, 4, 3);

            desenharCruz(tabuleiro, cruz, 2, 5);

            desenharOctaedro(tabuleiro, octaedro, 7, 1);

            printf("\n");
            imprimirTabuleiro(tabuleiro);
            return 0;

        case 2:    
            printf("Regras:\n");
            printf("O jogo se passa em um tabuleiro 10x10, onde as colunas e as linhas vão de 1-10\n");
            printf("Os navios podem ser colocados na horizontal, vertical e diagonal mas não podem se sobrepor.\n");
            printf("As habilidades são representadas pelo numero '1', e no tabuleiro podemos ver a sua área de efeito\n");
        break;

        case 3:
        printf("Obrigado por jogar!");
        return 0;

        default:
            printf("Erro: Opção Inválida!\n");
    }        
}