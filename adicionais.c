#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adicionais.h"

void limpartela(){
    system("clear");
}   

void mudarcor(int cor) {
    switch(cor) {
        case 0: printf("\033[0m"); break;   
        case 1: printf("\033[31m"); break;  // Vermelho
        case 2: printf("\033[32m"); break;  // Verde
        case 3: printf("\033[33m"); break;  // Amarelo
        case 4: printf("\033[34m"); break;  // Azul
        case 5: printf("\033[35m"); break;  // Magenta
        case 6: printf("\033[36m"); break;  // Ciano
        case 7: printf("\033[37m"); break;  // Branco
        case 8: printf("\033[90m"); break;  // Cinza
        case 9: printf("\033[91m"); break;  // Vermelho claro
        case 10: printf("\033[97m"); break; // Branco brilhante (mais forte)
    }
}


void cadastro(){
    mudarcor(10);
    printf("\n==================================================================================================================================================================================================\n");
    mudarcor(3);
    printf(" _______  ______    _______  _______  _______  ___      __   __  _______           _______  ___   ___      _______  _______      _______      _______  ___   ___      __   __  _______  _______   \n"
           "|       ||    _ |  |   _   ||  _    ||   _   ||   |    |  | |  ||       |         |       ||   | |   |    |   _   ||       |    |       |    |       ||   | |   |    |  | |  ||   _   ||       |  \n"
           "|_     _||   | ||  |  |_|  || |_|   ||  |_|  ||   |    |  |_|  ||   _   |   ____  |    ___||   | |   |    |  |_|  ||  _____|    |    ___|    |    _  ||   | |   |    |  |_|  ||  |_|  ||  _____|  \n"
           "  |   |  |   |_||_ |       ||       ||       ||   |    |       ||  | |  |  |____| |   |___ |   | |   |    |       || |_____     |   |___     |   |_| ||   | |   |    |       ||       || |_____   \n"
           "  |   |  |    __  ||       ||  _   | |       ||   |___ |       ||  |_|  |         |    ___||   | |   |___ |       ||_____  |    |    ___|    |    ___||   | |   |___ |       ||       ||_____  |  \n"
           "  |   |  |   |  | ||   _   || |_|   ||   _   ||       ||   _   ||       |         |   |    |   | |       ||   _   | _____| |    |   |___     |   |    |   | |       ||   _   ||   _   | _____| |  \n"
           "  |___|  |___|  |_||__| |__||_______||__| |__||_______||__| |__||_______|         |___|    |___| |_______||__| |__||_______|    |_______|    |___|    |___| |_______||__| |__||__| |__||_______|  \n");
    mudarcor(10);
    printf("\n==================================================================================================================================================================================================\n\n\n");
    mudarcor(0);

}

void exibirpilha(){
    printf("  _____  _____ ___ ___ _  _ ___   ___    ___ ___ _    _  _   _      _______                  __    ___             __  \n");
    printf(" | __\\ \\/ /_ _| _ )_ _| \\| |   \\ / _ \\  | _ \\_ _| |  | || | /_\\    / /_   _|__ _ __  ___   __\\ \\  | _ ) __ _ ___ __\\ \\ \n");
    printf(" | _| >  < | || _ \\| || .` | |) | (_) | |  _/| || |__| __ |/ _ \\  | |  | |/ _ \\ '_ \\/ _ \\ |___> > | _ \\/ _` (_-</ -_) |\n");
    printf(" |___/_/\\_\\___|___/___|_|\\_|___/ \\___/  |_| |___|____|_||_/_/ \\_\\ | |  |_|\\___/ .__/\\___/    /_/  |___/\\__,_/__/\\___| |\n");
    printf("                                                                   \\_\\        |_|                                  /_/  \n");
}

void antesdafila(){
    mudarcor(2);
    printf("Visualização dos Endereços de Memória onde cada pessoa está guardado em minha (RAM) no caso cada Bloco [Nome | Prox: Endereço] é um nó da minha lista.\nNo caso o [PROX] é um ponteiro, em que ele guarda o endereço de onde a próxima pessoa está e um detalhe que o salto de cada endereço é de 64 bytes,\nporque isso é o espaço que o Malloc Reservou para cada estrutura e para a string do Nome xD\n\n");
    mudarcor(0);
}