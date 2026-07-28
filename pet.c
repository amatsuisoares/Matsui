#include <stdio.h>
#include <string.h>

// Estrutura que representa o pet
typedef struct {
    char nome[50];
    int fome;
    int felicidade;
    int energia;
    int saude;
} Pet;


// Funcao para alimentar o pet
void alimentar(Pet *pet) {

    if (pet->fome >= 100) {
        printf("\n%s nao esta com fome!\n", pet->nome);
        return;
    }

    pet->fome += 20;

    if (pet->fome > 100) {
        pet->fome = 100;
    }

    printf("\n%s comeu e ficou satisfeito! 🍖\n", pet->nome);
}


// Funcao para brincar com o pet
void brincar(Pet *pet) {

    if (pet->energia < 20) {
        printf("\n%s esta muito cansado para brincar!\n", pet->nome);
        return;
    }

    pet->energia -= 20;
    pet->felicidade += 20;

    if (pet->felicidade > 100) {
        pet->felicidade = 100;
    }

    printf("\nVoce brincou com %s! Ele esta muito feliz! 🎾\n", pet->nome);
}


// Funcao para fazer o pet dormir
void dormir(Pet *pet) {

    if (pet->energia >= 100) {
        printf("\n%s nao esta cansado!\n", pet->nome);
        return;
    }

    pet->energia += 40;

    if (pet->energia > 100) {
        pet->energia = 100;
    }

    printf("\n%s dormiu e recuperou energia! 😴\n", pet->nome);
}


// Funcao para mostrar os status
void mostrarStatus(Pet *pet) {

    printf("\n");
    printf("================================\n");
    printf("        STATUS DO PET\n");
    printf("================================\n");

    printf("Nome:       %s\n", pet->nome);
    printf("Fome:       %d/100\n", pet->fome);
    printf("Felicidade: %d/100\n", pet->felicidade);
    printf("Energia:    %d/100\n", pet->energia);
    printf("Saude:      %d/100\n", pet->saude);

    printf("================================\n");
}


// Funcao principal
int main() {

    Pet pet;
    int opcao;

    // Criando o pet
    printf("================================\n");
    printf("       BEM-VINDO AO PET VIRTUAL\n");
    printf("================================\n");

    printf("\nDigite o nome do seu pet: ");
    fgets(pet.nome, 50, stdin);

    // Remove o '\n' que o fgets coloca no final
    pet.nome[strcspn(pet.nome, "\n")] = '\0';


    // Definindo os status iniciais
    pet.fome = 50;
    pet.felicidade = 50;
    pet.energia = 50;
    pet.saude = 100;


    // Menu principal
    do {

        printf("\n");
        printf("================================\n");
        printf("          MENU PRINCIPAL\n");
        printf("================================\n");

        printf("1 - Alimentar 🍖\n");
        printf("2 - Brincar 🎾\n");
        printf("3 - Dormir 😴\n");
        printf("4 - Ver status ❤️\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);


        // Executa a acao escolhida
        switch (opcao) {

            case 1:
                alimentar(&pet);
                break;

            case 2:
                brincar(&pet);
                break;

            case 3:
                dormir(&pet);
                break;

            case 4:
                mostrarStatus(&pet);
                break;

            case 0:
                printf("\nVoce saiu do jogo. Ate mais! 🐾\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);


    return 0;
}
