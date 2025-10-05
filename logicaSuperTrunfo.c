#include <stdio.h>

int main(){
    // cada uma das variáveis estão seguindo a regra de cada carta onde 1 é para a primeira e 2 para a segunda
    char estado1, estado2, cartacode1[4], cartacode2[4], cidade1[25], cidade2[25];
    unsigned long int populacao1, populacao2;
    int turismo1, turismo2, resultadocarta, opcao1, opcao2; 
    float area1, area2, PIB1, PIB2, dencidade1, dencidade2, PIBper1, PIBper2, superpoder1, superpoder2;

    // Variaveis para comparação das cartas
    float valorprincipal1, valorprincipal2;  //Valores de atributo principal
    float valordesempate1, valordesempate2;  //Valores de atributo de desempate
    int menor_vence_p, menor_vence_d; // Flags: 1 "Menor vence", 0 "Maior vence"
    int vencedor_final; // Flags: 1 para carta 1, 2 cara carta 2, 0 para empate
    const char *nome_atributo_p, *nome_atributo_d; // Exibir nome

    printf("Bem vindo ao sistema de cadastro de cartas para o jogo Super Trunfo de Cidades\n");

    // inicio de input das informações
    printf("Informações a seguir são para a primeira carta.\n");

    printf("Digite a primeira letra entre 'A' a 'H': "); 
    scanf(" %c", &estado1);
    
    printf("Digite a letra do estado e um número de 01 a 04 (ex: A01, B03): ");
    scanf("%s", cartacode1);

    printf("Digite o nome da cidade Sem espaços (Ex: SãoPaulo ou São_Paulo): ");
    scanf("%s", cidade1);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade em quilômetros quadrados: ");
    scanf("%f", &area1);

    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &PIB1);

    printf("Digite quantos pontos turísticos a cidade possui: ");
    scanf("%d", &turismo1);

    // Calculos para carta 1
    dencidade1 = (float)populacao1 / area1;  // calculo para dencidade
    PIBper1 = (PIB1 * 1000000000.0) / (float)populacao1;    //calculo para PIB per capita

    printf("Cadastro da primeira carta concluído!\n"); //confirmação visual para o usuário

    // inicio de input das informações para a segunda carta
    printf("Informações a seguir são para a segunda carta.\n");

    printf("Digite a primeira letra entre 'A' a 'H': "); 
    scanf(" %c", &estado2);
    
    printf("Digite a letra do estado e um número de 01 a 04 (ex: A01, B03): ");
    scanf("%s", cartacode2);

    printf("Digite o nome da cidade Sem espaços (Ex: SãoPaulo ou São_Paulo): ");
    scanf("%s", cidade2);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade em quilômetros quadrados: ");
    scanf("%f", &area2);

    printf("Digite o PIB (Produto Interno Bruto) da cidade: ");
    scanf("%f", &PIB2);

    printf("Digite quantos pontos turísticos a cidade possui: ");
    scanf("%d", &turismo2);

    // Calculos para carta 2
    dencidade2 = (float)populacao2 / area2; // calculo para dencidade
    PIBper2 = (PIB2 * 1000000000.0) / (float) populacao2;   //calculo para PIB per capita

    printf("Cadastro da segunda carta concluído!\n");   //confirmação visual para o usuário

    // exibi as cartas para melhor visualização do usuario

    // resultado das informações para a primeira carta
    printf("\n=============== Carta: 1 ===============\n");
    printf("Carta 1: \n");
    printf("Estado: %c \n", estado1);
    printf("Código: %s \n", cartacode1);
    printf("Nome da Cidade: %s \n", cidade1);
    printf("População: %lu \n", populacao1);
    printf("Área: %.2f Km² \n", area1);
    printf("PIB: %.2f bilhões de reais \n", PIB1);
    printf("Número de Pontos Turísticos: %d \n", turismo1);
    printf("Densidade Populacional: %.2f hab/Km² \n", dencidade1);
    printf("PIB per Capita: %.2f reais \n", PIBper1);
    printf("======================================\n");

    // resultado das informações para a segunda carta
    printf("\n=============== Carta: 2 ===============\n");
    printf("Carta 2: \n");
    printf("Estado: %c \n", estado2);
    printf("Código: %s \n", cartacode2);
    printf("Nome da Cidade: %s \n", cidade2);
    printf("População: %lu \n", populacao2);
    printf("Área: %.2f Km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", PIB2);
    printf("Número de Pontos Turísticos: %d \n", turismo2);
    printf("Densidade Populacional: %.2f hab/Km²\n", dencidade2);
    printf("PIB per Capita: %.2f reais\n", PIBper2);
    printf("======================================\n");
    
    printf("\nCartas cadastradas! Boa sorte no jogo!\n");   // Mensagem de encerramento
    
    // abaixo esta o resultado da carta que ganhou

    // Comparação entre as cartas para fazer a de Super Poder
    superpoder1 = (float)populacao1 + area1 + PIB1 + (float)turismo1 + PIBper1 + (1.0 / dencidade1);
    superpoder2 = (float)populacao2 + area2 + PIB2 + (float)turismo2 + PIBper2 + (1.0 / dencidade2);

    //  Logica de comparação dos atributos
    
    // 1 - Escolha do primeiro atributo
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n*** Escolha o Primeiro atributo para comparação ***\n");
    printf("[1]. População (Maior valor vence)\n");
    printf("[2]. Área (Maior valor vence)\n");
    printf("[3]. PIB (Maior valor vence)\n");
    printf("[4]. Número de Pontos Turísticos (Maior valor vence)\n");
    printf("[5]. Densidade Demográfica (Menor valor vence)\n");
    printf("[6]. PIB per Capita (Maior valor vence) \n");
    printf("[7]. Super Poder (Maior valor vence) \n");
    printf("Digite uma opção de (1 a 7): ");
    scanf("%d", &opcao1);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    // 2 - Escolha do segundo atributo
    printf("***  Escolha o Segundo atributo para comparação ***\n");
    printf("Caso o atributo seja o mesmo não haverá desempate.\n");
    printf("Digite uma segunda opção de (1 a 7): ");
    scanf("%d", &opcao2);

    // Configuração do switch para valores e regras

    // Configuração do atributo principal.
    switch (opcao1){
    case 1: valorprincipal1 = (float)populacao1; valorprincipal2 = (float)populacao2; menor_vence_p = 0; nome_atributo_p = "População (Maior)"; break;
    case 2: valorprincipal1 = area1; valorprincipal2 = area2; menor_vence_p = 0; nome_atributo_p = "Área (Maior)"; break;
    case 3: valorprincipal1 = PIB1; valorprincipal2 = PIB2; menor_vence_p = 0; nome_atributo_p = "PIB (Maior)"; break;
    case 4: valorprincipal1 = (float)turismo1; valorprincipal2 = (float)turismo2; menor_vence_p = 0; nome_atributo_p = "Pontos Turísticos (Maior)"; break;
    case 5: valorprincipal1 = dencidade1; valorprincipal2 = dencidade2; menor_vence_p = 1; nome_atributo_p = "Densidade Demográfica (Menor)"; break;
    case 6: valorprincipal1 = PIBper1; valorprincipal2 = PIBper2; menor_vence_p = 0; nome_atributo_p = "PIB per Capita (Maior)"; break;
    case 7: valorprincipal1 = superpoder1; valorprincipal2 = superpoder2; menor_vence_p = 0; nome_atributo_p = "Super Poder (Maior)"; break;
    default: printf("Erro: Opção Inválida.\n"); return 1;
    }

    // Configuração do atributo de desempate.
    switch (opcao2){
    case 1: valordesempate1 = (float)populacao1; valordesempate2 = (float)populacao2; menor_vence_d = 0; nome_atributo_d = "População (Maior)"; break;
    case 2: valordesempate1 = area1; valordesempate2 = area2; menor_vence_d = 0; nome_atributo_d = "Área (Maior)"; break;
    case 3: valordesempate1 = PIB1; valordesempate2 = PIB2; menor_vence_d = 0; nome_atributo_d = "PIB (Maior)"; break;
    case 4: valordesempate1 = (float)turismo1; valordesempate2 = (float)turismo2; menor_vence_d = 0; nome_atributo_d = "Pontos Turísticos (Maior)"; break;
    case 5: valordesempate1 = dencidade1; valordesempate2 = dencidade2; menor_vence_d = 1; nome_atributo_d = "Densidade Demográfica (Menor)"; break;
    case 6: valordesempate1 = PIBper1; valordesempate2 = PIBper2; menor_vence_d = 0; nome_atributo_d = "PIB per Capita (Maior)"; break;
    case 7: valordesempate1 = superpoder1; valordesempate2 = superpoder2; menor_vence_d = 0; nome_atributo_d = "Super Poder (Maior)"; break;
    default: printf("Erro: Opção Inválida.\n"); return 1;
    }

    printf("\n======================================\n");
    printf("--- RESULTADO DA BATALHA ---\n");
    printf("Atributo Principal: %s Carta 1: %.2f | Carta 2: %.2f\n", nome_atributo_p, valorprincipal1, valorprincipal2);

    // Lógica de decisão para ganhador

    // Logica para atributo principal
    if (menor_vence_p ? (valorprincipal1 < valorprincipal2) : (valorprincipal1 > valorprincipal2)){
        vencedor_final = 1;
        printf("Carta 1 (%s) Vence no Principal!\n", cidade1);
    } 
    else if (menor_vence_p ? (valorprincipal2 < valorprincipal1) : (valorprincipal2 > valorprincipal1)){
        vencedor_final = 2;
        printf("Carta 2 (%s) Vence no Principal!\n", cidade2);
    }
    else {
        // Empate no Atributo principal, vai para a logica de desempate
        printf("Empate do principal. Atributo de Desenpate: %s Carta 1: %.2f | Carta 2: %.2f\n", nome_atributo_d, valordesempate1, valordesempate2);

        // Determina o vencedor do desempate
        // checa se a carta 1 vence no desempate (retorna 1)
        vencedor_final = (menor_vence_d ? (valordesempate1 < valordesempate2) : (valordesempate1 > valordesempate2)) ? 1 :
        // checa se a carta 2 vence no desempate (retorna 2), caso não vença (retorna 0) para empate
        ((menor_vence_d ? (valordesempate2 < valordesempate1) : (valordesempate2 > valordesempate1)) ? 2 : 0);

        // Resultado final do desempate
        if (vencedor_final == 1){
            printf("Resultado Final: Carta 1 (%s) VENCEU no Desempate!\n", cidade1);
        } else if (vencedor_final == 2) {
            printf("Resultado Final: Carta 2 (%s) VENCEU no Desempate!\n", cidade2);
        } else {
            printf("Resultado Final: EMPATE GERAL!\n");
        }
    }
    printf("======================================\n");
    return 0;    
}
