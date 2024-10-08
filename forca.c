#include <stdio.h>
#include <string.h>

void abertura() {
    printf("*************************\n");
    printf("*     Jogo da forca     *\n");
    printf("*************************\n\n");
}

void chuta(char chutes[], int *tentativas){
    char chute;
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;

}

int main(){
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do {

        for (int i = 0; i < strlen(palavrasecreta); i++){

            int achou = 0;

            for (int j = 0; j < tentativas; j++){ // Será procurado na lista dos chutes, um caractere que corresponda ao da palavra secreta, caso 'true', aparecerá a letra entre os espaços
                if(chutes[j] == palavrasecreta[i]){
                    achou = 1;
                    break;
                }
            }

            if (achou){
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }

        printf("\n\n");

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
}