#include <stdio.h>

int main(){
    // cada uma das variáveis estão seguindo a regra de cada carta onde 1 é para a primeira e 2 para a segunda
    char estado1, estado2, cartacode1[4], cartacode2[4], cidade1[25], cidade2[25];
    unsigned long int populacao1, populacao2;
    int turismo1, turismo2, resultadocarta, opcao; 
    float area1, area2, PIB1, PIB2, dencidade1, dencidade2, PIBper1, PIBper2, superpoder1, superpoder2;

    printf("Bem vindo ao sistema de cadastro de cartas para o jogo Super Trunfo de Países\n");

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

    //  Logica para determinar o vencedor
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n*** Escolha o Atributo para Comparação ***\n");
    printf("1. População (Maior valor vence)\n");
    printf("2. Área (Maior valor vence)\n");
    printf("3. PIB (Maior valor vence)\n");
    printf("4. Número de Pontos Turísticos (Maior valor vence)\n");
    printf("5. Densidade Demográfica (Menor valor vence)\n");
    printf("6. PIB per Capita (Maior valor vence) \n");
    printf("7. Super Poder (Maior valor vence) \n");
    printf("Digite o número da opção (1 a 7): ");
    scanf("%d", &opcao);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    switch (opcao)
    {
    case 1: // logica para população
        printf("Comparação de cartas (Atributo População): \n");
        printf("Carta 1 - (%s): %d \n", cidade1, populacao1);
        printf("Carta 2 - (%s): %d \n", cidade2, populacao2);
        
        // Regra: Maior vence
        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;

    case 2: // Logica para Area
        printf("Comparação de cartas (Atributo Área): \n");
        printf("Carta 1 - (%s): %.2f \n", cidade1, area1);
        printf("Carta 2 - (%s): %.2f \n", cidade2, area2);
        
        // Regra: Maior vence        
        if (area1 > area2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if  (area2 > area1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;

    case 3: // Logica para PIB
        printf("Comparação de cartas (PIB): \n");
        printf("Carta 1 - (%s): %.2f \n", cidade1, PIB1);
        printf("Carta 2 - (%s): %.2f \n", cidade2, PIB2);
        
        // Regra: Maior vence
        if (PIB1 > PIB2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if (PIB2 > PIB1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;
        
    case 4: // Logica para Turismo
        printf("Comparação de cartas (Atributo Pontos Turísticos): \n");
        printf("Carta 1 - (%s): %d \n", cidade1, turismo1);
        printf("Carta 2 - (%s): %d \n", cidade2, turismo2);
        
        // Regra: Maior vence
        if (turismo1 > turismo2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if (turismo2 < turismo1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;
        
    case 5: // Logica para Dencidade
        printf("Comparação de cartas (Atributo Densidade Populacional): \n");
        printf("Carta 1 - (%s): %.2f \n", cidade1, dencidade1);
        printf("Carta 2 - (%s): %.2f \n", cidade2, dencidade2);
        
        // Regra Especial: Menor vence
        if (dencidade1 < dencidade2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            if (dencidade2 < dencidade1) {
                printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            } 
            else {
                printf("Resultado: Empate!\n");
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            }
        }
        break;

    case 6: // Logica para PIB Percapital
        printf("Comparação de cartas (Atributo PIB per capita): \n");
        printf("Carta 1 - (%s): %.2f \n", cidade1, PIBper1);
        printf("Carta 2 - (%s): %.2f \n", cidade2, PIBper2);
        
        // Regra: Maior vence
        if (PIBper1 > PIBper2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if (PIBper2 > PIBper1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;
        
    case 7: // Logica para Super Poder
        printf("Comparação de cartas (Atributo Supor Poder): \n");
        printf("Carta 1 - (%s): %.2f \n", cidade1, superpoder1);
        printf("Carta 2 - (%s): %.2f \n", cidade2, superpoder2);
                
        // Regra: Maior vence
        if (superpoder1 > superpoder2) {
            printf("Resultado: Carta 1 (%s) venceu! \n", cidade1);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else if (superpoder2 > superpoder1) {
            printf("Resultado: Carta 2 (%s) venceu! \n", cidade2);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        } else {
            printf("Resultado: Empate!\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        break;

    default:
        printf("\nOpção inválida! Por favor, escolha um número de 1 a 7.\n");
        break;
    }
    return 0;    
}
