#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {

    char nome[50];

    int fome;
    int felicidade;
    int energia;
    int saude;

    time_t ultimaAtualizacao;

} Pet;



// FUNCAO PARA LIMITAR OS STATUS ENTRE 0 E 100


void limitarStatus(Pet *pet) {

    if (pet->fome > 100) {
        pet->fome = 100;
    }

    if (pet->fome < 0) {
        pet->fome = 0;
    }


    if (pet->felicidade > 100) {
        pet->felicidade = 100;
    }

    if (pet->felicidade < 0) {
        pet->felicidade = 0;
    }


    if (pet->energia > 100) {
        pet->energia = 100;
    }

    if (pet->energia < 0) {
        pet->energia = 0;
    }


    if (pet->saude > 100) {
        pet->saude = 100;
    }

    if (pet->saude < 0) {
        pet->saude = 0;
    }
}



// FUNCAO PARA ATUALIZAR A SAUDE


void atualizarSaude(Pet *pet) {

    if (pet->fome <= 20) {

        pet->saude -= 10;

        printf("\nCuidado! %s esta com muita fome!\n",
               pet->nome);

        printf("A saude do pet diminuiu.\n");
    }


    if (pet->felicidade <= 20) {

        pet->saude -= 5;

        printf("\n%s esta muito triste!\n",
               pet->nome);

        printf("A saude do pet diminuiu.\n");
    }


    if (pet->fome >= 50 &&
        pet->felicidade >= 50 &&
        pet->energia >= 50) {

        pet->saude += 5;

    }

    limitarStatus(pet);
}



// FUNCAO QUE ATUALIZA O TEMPO DO PET


void atualizarTempo(Pet *pet) {

    time_t agora;

    time_t tempoPassado;

    int minutosPassados;


    // Pega o horario atual

    agora = time(NULL);


    // Calcula quanto tempo passou

    tempoPassado = agora - pet->ultimaAtualizacao;


    // Converte segundos para minutos

    minutosPassados = tempoPassado / 60;


    // Se passou pelo menos 1 minuto

    if (minutosPassados >= 1) {

        printf("\n================================\n");

        printf("O tempo passou...\n");

        printf("Minutos passados: %d\n",
               minutosPassados);

        printf("================================\n");


        // A fome diminui com o tempo

        pet->fome -= minutosPassados * 2;


        // A felicidade diminui um pouco

        pet->felicidade -= minutosPassados;


        // A energia tambem diminui

        pet->energia -= minutosPassados;


        // Atualiza a saúde

        atualizarSaude(pet);


        // Limita os valores

        limitarStatus(pet);


        // Atualiza o momento da ultima atualizacao

        pet->ultimaAtualizacao = agora;
    }
}



// FUNCAO PARA ALIMENTAR


void alimentar(Pet *pet) {

    if (pet->fome >= 100) {

        printf("\n%s nao esta com fome!\n",
               pet->nome);

        return;
    }


    pet->fome += 30;

    pet->felicidade += 5;


    printf("\n%s comeu e ficou satisfeito!\n",
           pet->nome);


    limitarStatus(pet);

    atualizarSaude(pet);
}



// FUNCAO PARA BRINCAR


void brincar(Pet *pet) {

    if (pet->energia < 20) {

        printf("\n%s esta muito cansado para brincar!\n",
               pet->nome);

        return;
    }


    pet->energia -= 20;

    pet->felicidade += 25;

    pet->fome -= 10;


    printf("\nVoce brincou com %s!\n",
           pet->nome);

    printf("%s esta muito feliz!\n",
           pet->nome);


    limitarStatus(pet);

    atualizarSaude(pet);
}



// FUNCAO PARA DORMIR

void dormir(Pet *pet) {

    if (pet->energia >= 100) {

        printf("\n%s nao esta cansado!\n",
               pet->nome);

        return;
    }


    pet->energia += 50;

    pet->fome -= 10;


    printf("\n%s dormiu e recuperou energia!\n",
           pet->nome);


    limitarStatus(pet);

    atualizarSaude(pet);
}



// FUNCAO PARA MOSTRAR STATUS


void mostrarStatus(Pet *pet) {

    printf("\n");
    printf("================================\n");
    printf("          STATUS DO PET\n");
    printf("================================\n");


    printf("Nome:       %s\n",
           pet->nome);

    printf("Fome:       %d/100\n",
           pet->fome);

    printf("Felicidade: %d/100\n",
           pet->felicidade);

    printf("Energia:    %d/100\n",
           pet->energia);

    printf("Saude:      %d/100\n",
           pet->saude);


    printf("================================\n");


    // HUMOR

    if (pet->felicidade >= 80) {

        printf("Humor: Muito feliz!\n");

    } else if (pet->felicidade >= 50) {

        printf("Humor: Feliz!\n");

    } else if (pet->felicidade >= 20) {

        printf("Humor: Triste...\n");

    } else {

        printf("Humor: Muito triste!\n");
    }


    // FOME

    if (pet->fome >= 80) {

        printf("Alimentacao: Muito satisfeito!\n");

    } else if (pet->fome >= 50) {

        printf("Alimentacao: Bem alimentado.\n");

    } else if (pet->fome >= 20) {

        printf("Alimentacao: Com fome...\n");

    } else {

        printf("Alimentacao: MORRENDO DE FOME!\n");
    }


    // ENERGIA

    if (pet->energia >= 80) {

        printf("Energia: Cheio de energia!\n");

    } else if (pet->energia >= 50) {

        printf("Energia: Disposto.\n");

    } else if (pet->energia >= 20) {

        printf("Energia: Cansado...\n");

    } else {

        printf("Energia: Exausto!\n");
    }


    printf("================================\n");
}



// FUNCAO PRINCIPAL


int main() {

    Pet pet;

    int opcao;


    
    // CRIACAO DO PET
    

    printf("================================\n");

    printf("      BEM-VINDO AO PET VIRTUAL\n");

    printf("================================\n");


    printf("\nDigite o nome do seu pet: ");

    fgets(pet.nome, 50, stdin);


    pet.nome[strcspn(pet.nome, "\n")] = '\0';


    // STATUS INICIAL
    

    pet.fome = 50;

    pet.felicidade = 50;

    pet.energia = 50;

    pet.saude = 100;


   
    // REGISTRA O HORARIO INICIAL
  

    pet.ultimaAtualizacao = time(NULL);


    
    // MENU
   

    do {


        // Atualiza os status conforme o tempo

        atualizarTempo(&pet);


        printf("\n");

        printf("================================\n");

        printf("          MENU PRINCIPAL\n");

        printf("================================\n");


        printf("1 - Alimentar\n");

        printf("2 - Brincar\n");

        printf("3 - Dormir\n");

        printf("4 - Ver status\n");

        printf("0 - Sair\n");


        printf("\nEscolha uma opcao: ");

        scanf("%d", &opcao);


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

                printf("\nVoce saiu do jogo!\n");

                printf("Ate mais, %s!\n",
                       pet.nome);

                break;


            default:

                printf("\nOpcao invalida!\n");
        }


    } while (opcao != 0);


    return 0;
}
