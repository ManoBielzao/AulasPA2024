#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo de tela
typedef enum {
    MENU,
    ESCRITA_MENSAGEM,
    TELA_3
} TipoTela;

// Estrutura de tela
typedef struct tela {
    char titulo[40];
    char info[45];
    int opcao;
    TipoTela tipo_tela;
} Tela;

// Definição das telas
Tela Tela_1[3] = {
    {"          ---MENU---", " (1) PC e (2) ARDUINO", 0, MENU},
    {"          ---ESCREVA SUA MENSAGEM---", "", 0, ESCRITA_MENSAGEM},
    {"          ---TELA 3---", "1- p NEMU, 2- p VOLTAR e 3 sair", 0, TELA_3},
};

Tela Tela_2[2] = {
    {"          ---AGUARDANDO---", "", 0, TELA_3},
    {"          ---MENSAGEM RECEBIDA---", "", 0, TELA_3},
};

// Funções para imprimir telas
void imprimirTela(Tela tela) {
    system("cls");
    printf("%s\n", tela.titulo);
    printf("%s\n", tela.info);
}

// Função para enviar mensagem via comunicação serial
void enviarMensagemSerial(char mensagem[]) {
    // Aqui você deve implementar a lógica para enviar a mensagem para o Arduino via comunicação serial
    printf("Enviando mensagem para o Arduino: %s\n", mensagem);
}

// Função para receber mensagem via comunicação serial
void receberMensagemSerial(char mensagem[]) {
    // Aqui você deve implementar a lógica para receber a mensagem do Arduino via comunicação serial
    printf("Aguardando mensagem do Arduino...\n");
    strcpy(mensagem, "Mensagem recebida do Arduino");
}

// Função principal
int main() {
    int estado = 0;
    int escolha = 0;
    char mensagem[17]; // Um caractere extra para o caractere nulo de terminação da string

    while (estado != 100) {
        switch (estado) {
            case 0:
                imprimirTela(Tela_1[0]);
                scanf("%d", &escolha);
                if (escolha == 1) {
                    estado = 1;
                    imprimirTela(Tela_2[0]);
                    receberMensagemSerial(mensagem);
                    printf("Mensagem recebida do Arduino: %s\n", mensagem);
                    printf("Pressione qualquer tecla para continuar...");
                    getchar(); // Limpa o buffer de entrada
                    getchar(); // Aguarda a pressão de qualquer tecla
                    estado = 0; // Volta para o menu principal
                } else if (escolha == 2) {
                    estado = 2;
                    imprimirTela(Tela_1[1]);
                    printf("Digite sua mensagem (max. 16 caracteres): ");
                    scanf("%s", mensagem);
                    enviarMensagemSerial(mensagem);
                    printf("Mensagem enviada para o Arduino.\n");
                    printf("Pressione qualquer tecla para continuar...");
                    getchar(); // Limpa o buffer de entrada
                    getchar(); // Aguarda a pressão de qualquer tecla
                    estado = 0; // Volta para o menu principal
                }
                escolha = 0;
                break;
            default:
                break;
        }
    }

    return 0;
}