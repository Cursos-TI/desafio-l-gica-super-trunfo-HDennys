#include <stdio.h>

// Definimos uma "Carta" como um tipo de dado que armazena:
// - Estado (A-H), código (ex: A01), nome da cidade, população, área, PIB e pontos turísticos.
typedef struct {
    char estado;               // Armazena o estado (ex: 'A', 'B', etc.)
    char codigo[4];            // Código da cidade (ex: "A01" → 3 letras + '\0')
    char cidade[30];           // Nome da cidade (até 29 caracteres + '\0')
    int populacao;             // População (número inteiro)
    float area;                // Área em km² (número decimal)
    float pib;                 // PIB em bilhões (número decimal)
    int pontos_turisticos;     // Número de pontos turísticos (inteiro)
} Carta;

// Função para ler os dados de uma carta.
// Recebe um ponteiro para a carta (*c) e o número dela (num).
void lerCarta(Carta *c, int num) {
    printf("\nCarta %d - Estado (A-H): ", num);
    scanf(" %c", &c->estado);  // Lê um único caractere (ignorando espaços)

    printf("Carta %d - Codigo (ex: A01): ", num);
    scanf("%3s", c->codigo);   // Lê até 3 caracteres (evita buffer overflow)

    printf("Carta %d - Cidade: ", num);
    scanf(" %29[^\n]", c->cidade); // Lê até 29 caracteres (incluindo espaços)

    printf("Carta %d - Populacao: ", num);
    scanf("%d", &c->populacao); // Lê um número inteiro

    printf("Carta %d - Area (km²): ", num);
    scanf("%f", &c->area);      // Lê um número decimal

    printf("Carta %d - PIB (bilhoes): ", num);
    scanf("%f", &c->pib);       // Lê um número decimal

    printf("Carta %d - Pontos turisticos: ", num);
    scanf("%d", &c->pontos_turisticos); // Lê um número inteiro
}

// Função para exibir os dados de uma carta.
// Recebe a carta (c) e seu número (num).
void imprimirCarta(Carta c, int num) {
    printf("\nCarta %d: %s (%s)\n", num, c.cidade, c.codigo);
    printf("Estado: %c, Pop: %d, Area: %.1f km²\n", c.estado, c.populacao, c.area);
    printf("PIB: %.1f bi, Pontos: %d\n", c.pib, c.pontos_turisticos);
}

// Função principal
int main() {
    Carta c1, c2;  // Cria duas cartas (c1 e c2)

    // Lê os dados da Carta 1 e Carta 2
    lerCarta(&c1, 1);  // Passa o endereço de c1 (&c1) para a função lerCarta
    lerCarta(&c2, 2);  // Passa o endereço de c2 (&c2) para a função lerCarta

    // Exibe os dados das duas cartas
    imprimirCarta(c1, 1);
    imprimirCarta(c2, 2);

    return 0;  // Indica que o programa terminou com sucesso
}