#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 250

void trocar_caracteres(char *vetor){

    int i, tam, letter, especial;
    tam = strlen(vetor);

    for ( i = 0; i < tam; i++)
    {
        letter = isalpha(vetor[i]);
        if (letter > 0){
            if (vetor[i] == 'a'){
                vetor[i] = '@';
            }
            else if (vetor[i] == 'e'){
                vetor[i] = '&';
            }
            else if (vetor[i] == 'i'){
                vetor[i] = '$';
            }
            else if (vetor[i] == 'o'){
                vetor[i] = '*';
            }
            else if (vetor[i] == 'u'){
                vetor[i] = '#';
            }
            else if (vetor[i] == '@'){
                vetor[i] = 'a';
            }
            else if (vetor[i] == '&'){
                vetor[i] = 'e';
            }
            else if (vetor[i] == '$'){
                vetor[i] = 'i';
            }
            else if (vetor[i] == '*'){
                vetor[i] = 'o';
            }
            else if (vetor[i] == '#'){
                vetor[i] = 'u';
            }
            else{
                continue;
            }
        }
        

    }
    


}

int main(){

    char msg[MAX];
    char msg1[MAX];
    char msg2[MAX];
    
    printf(("MENSAGEM: "));
    scanf("%250[^\n]s", msg);

    trocar_caracteres(msg);

    printf("%s", msg);

}