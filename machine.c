#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 250

//FUNCAO PARA TROCAR VOGAIS
void trocar_vogais(char *letra){
        
    switch (*letra)
    {
    case 'a':
        *letra = '@';
        break;
    case 'e':
        *letra = '&';
        break;
    case 'i':
        *letra = '$';
        break;
    case 'o':
        *letra = '*';
        break;
    case 'u':
        *letra = '#';
        break;            
    default:
        break;
    }
        
}

//FUNCAO PARA TROCAR CARACTERES ESPECIAIS
void trocar_especiais(char *c_especial){
    switch (*c_especial)
    {
    case '@':
        *c_especial = 'a';
        break;
    case '&':
        *c_especial = 'e';
        break;
    case '$':
        *c_especial = 'i';
        break;
    case '*':
        *c_especial = 'o';
        break;
    case '#':
        *c_especial = 'u';
        break;
    default:
        break;
    }
}

//CHAMADA DAS FUNCOES DE TROCA
void trocar_caracteres(char *vetor){

    int i, tam, letra;
    tam = strlen(vetor);

    for ( i = 0; i < tam; i++)
    {
        letra = isalpha(vetor[i]);
        if (letra > 0)
        {
            trocar_vogais(&vetor[i]);
        }
        else{
            trocar_especiais(&vetor[i]);
        }        
    }
}

//PARA COLOCAR OS ELEMENTOS DE INDICE PAR NO VETOR PAR
void pares(char *vetor, char * vetor_par){
    
    int i, tamanho_vetor, indice_par;
    indice_par = 0;
    tamanho_vetor = strlen(vetor);

    for ( i = 0; i < tamanho_vetor; i++){
        if ((i % 2) == 0){
            vetor_par[indice_par] = vetor[i];
            indice_par++;
        }
    }
    vetor_par[indice_par] = '\0';
}

//PARA COLOCAR ELEMENTOS DE INDICE IMPAR NO VETOR IMPARES
void impar(char *vetor, char *vetor_impar){

    int i, tamanho_vetor, indice_impar;
    indice_impar = 0;
    tamanho_vetor = strlen(vetor);

    for ( i = tamanho_vetor - 1; i >= 0; i--)
    {
        /* code */
        if ((i % 2) != 0){
            vetor_impar[indice_impar] = vetor[i];
            indice_impar++;
        }
    }
    vetor_impar[indice_impar] = '\0';    
}

//PARA INTERCALAR UM DO VETOR PAR E OUTRO DO VETOR IMPAR
void intercalar(char *vetor_final, char *par, char *impar){

    int i, tamanho, indice_par, indice_impar;
    indice_par = 0;
    indice_impar = 0;
    tamanho = (strlen(par) + strlen(impar));
    for ( i = 0; i < tamanho; i++)
    {
        /* code */
        if ((i % 2) == 0){
            vetor_final[i] = par[indice_par];
            indice_par++;
        }
        else{
            vetor_final[i] = impar[indice_impar];
            indice_impar++;
        }
    }
    
    vetor_final[i] = '\0';
    
    
}

//PROGRAMA PRINCIPAL
int main(){

    // PARA RECEBER AS MENSAGENS
    char msg[MAX];
    char par[MAX];
    char impares[MAX];
    char final_cripto[MAX];

    //PARA LIMPAR AS STRINGS
    char limpar[MAX];

    // CRIPTOGRAFAR
    
    printf(("\n\nMENSAGEM: "));
    scanf("%250[^\n]s", msg);

    trocar_caracteres(msg);
    pares(msg, par);
    impar(msg, impares);
    intercalar(final_cripto, par, impares);
    printf("\n\n%s\n\n", final_cripto);

    //LIMPAR O BUFFER
    setbuf(stdin, NULL);

    //AGUARDAR PARA DESCRIPTOGRAFRAR
    printf("PRESSIONE ENTER PARA DESCRIPTOGRAFAR\n");
    getchar();

    //PARA REINICIAR O PROCESSO
    strcpy(msg, final_cripto);
    strcpy(par, limpar);
    strcpy(impares, limpar);
    strcpy(final_cripto, limpar);

    //DESCRIPTOGRAFANDO
    
    trocar_caracteres(msg);
    pares(msg, par);
    impar(msg, impares);
    intercalar(final_cripto, par, impares);
    printf("\n\n%s\n\n", final_cripto);

    return 0;
}