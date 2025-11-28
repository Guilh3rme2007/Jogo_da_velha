#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void) {
    char done;

    printf("Este é um jogo da valha!\n");
    printf("Você estará jogando contra um computador \n");

    disp_matrix();

    done = ' ';
    init_matrix();
    do{
    get_player_move();
    done = check();
    disp_matrix();
    if (done != ' ') {
        break;
    }
    get_computer_move();
    done = check();
    disp_matrix();
} while (done == ' ');

if(done == 'X') {
    printf("Você ganhou \n");
} else {
    printf("O computador ganhou \n");
}

disp_matrix();

}

void init_matrix(void) {
    int l, c;

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            matrix[l][c] = ' ';
        }
    }
}

void get_player_move(void) {
    int x, y;

    printf("Digite sua jogada (linha): ");
    scanf("%d", &x);

    printf("Digite sua jogada (coluna): ");
    scanf("%d", &y);

    x--;
    y--;

    if (matrix[x][y] != ' '){
        printf("jogada inválida, tente novamente.\n");
        get_player_move();
    } else {
        matrix[x][y] = 'X';
    }
}

void get_computer_move(void) {
    int l, c;

    for(l = 0; l < 3; l++) {
        for(c =0; c < 3; c++) {
            if(matrix[l][c] == ' ') {
                matrix[l][c] = '0';
                return;
            }
        }
    }

    if(l * c == 9) {
        printf("Empate/n");
        exit(0);
    } else {
        matrix[l][c] = '0';
    }
}

void disp_matrix(void) {
    int t;

    for(t = 0; t < 3; t++) {
        printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

char check(void) {
    int i;

    for(i = 0; i < 3; i++) {
        if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
            return matrix[i][0];
        }
    }
    for(i = 0; i < 3; i++) {
        if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) {
            return matrix[0][i];
        }
    }
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        return matrix[0][0];
    }
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        return matrix[0][2];
}
    return ' ';
}