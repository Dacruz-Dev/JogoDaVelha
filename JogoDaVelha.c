#include <stdio.h>

char vetorMapa[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char strXO[3] = "*XO"; // * não será utilizado
int player12 = 1;
int jogadorNumero;
int valid_input;

void exibir_tabuleiro() {
    printf("  %c | %c | %c\n", vetorMapa[1], vetorMapa[2], vetorMapa[3]);
    printf("  -----------\n");
    printf("  %c | %c | %c\n", vetorMapa[4], vetorMapa[5], vetorMapa[6]);
    printf("  -----------\n");
    printf("  %c | %c | %c\n", vetorMapa[7], vetorMapa[8], vetorMapa[9]);
}

int check_vitoria(char jogador) {
    for (int i = 1; i <= 7; i += 3) {
        if (vetorMapa[i] == jogador && vetorMapa[i + 1] == jogador && vetorMapa[i + 2] == jogador) {
            return 1;
        }
    }
    for (int i = 1; i <= 3; i++) {
        if (vetorMapa[i] == jogador && vetorMapa[i + 3] == jogador && vetorMapa[i + 6] == jogador) {
            return 1;
        }
    }
    if ((vetorMapa[1] == jogador && vetorMapa[5] == jogador && vetorMapa[9] == jogador) ||
        (vetorMapa[3] == jogador && vetorMapa[5] == jogador && vetorMapa[7] == jogador)) {
        return 1;
    }
    return 0;
}

int main() {
    int variWhile = 0;
    
    do {
        exibir_tabuleiro();
        printf("Jogador %d é %c\n", player12, strXO[player12]);
        printf("Escolha sua posição: ");
        valid_input = scanf("%d", &jogadorNumero);
        
        if (valid_input != 1 || jogadorNumero < 1 || jogadorNumero > 9 || vetorMapa[jogadorNumero] != ' ') {
            printf("Jogada inválida! Digite um número de 1 a 9 e escolha uma posição vazia.\n");
            while (getchar() != '\n');
        } else {
            vetorMapa[jogadorNumero] = strXO[player12];
            if (check_vitoria(strXO[player12])) {
                exibir_tabuleiro();
                printf("Jogador %d venceu!\n", player12);
                break;
            }
            player12 = (player12 == 1) ? 2 : 1;
        }
    } while (1);

    return 0;
}
