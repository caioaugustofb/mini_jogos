#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

void pressioneEnter() {
    printf("Pressione ENTER para continuar...\n");
    while (getchar() != '\n');
    getchar();
}

void exibirComAtraso(const char* texto, int atraso) {
    while (*texto) {
        putchar(*texto);
        fflush(stdout);
        Sleep(atraso);
        texto++;
    }
}

void corTexto(int cor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "pt_BR.UTF-8");
    const char*personagem[] = {
        "Indiana Jones", "Lara Croft", "Nathan Drake", "Aragorn", "Kratos", "Mario", "Link"
    };

    char r1, r2, r3, r4, r5;
    int titulo, menu, cobra, botao, escolha1, escolha2, jogador1, jogador2, primeiroJogador, primeiroJogador2, mitose;
    int gousma[4] = {1, 1, 1, 1};
    int nivelFuria[4] = {1, 1, 1, 1};
    int jogadorGousmas[2] = {2, 2};
    int jogadoresAtacaram = 0;
    int mitoseRealizada[2] = {0, 0};
    int rodada;
    int ativo;


    do { 
        corTexto(11);
        printf("TÍTULO DO JOGO\n\nEscolha um dos jogos a seguir:\n");
        corTexto(2);
        printf("1: Perguntas e Respostas\n");
        corTexto(5);
        printf("2: Cobra na caixa\n");
        corTexto(6);
        printf("3: Gousmas War\n");
        corTexto(12);
        printf("4: Sair\n\n");
        corTexto(7);
        scanf("%d", &titulo);

        if (titulo == 1) { // JOGO 1
            do { 
                corTexto(2);
                printf("Você escolheu o jogo Perguntas e Respostas\n\n");

                // JOGO INICIA
                corTexto(7);
                exibirComAtraso("Neste jogo, você terá que responder 5 perguntas de múltipla escolha.\n", 30);
                exibirComAtraso("Cada pergunta tem 4 alternativas e apenas uma está correta.\n", 30);
                exibirComAtraso("Responda com a letra correspondente à alternativa correta.\n", 30);
                exibirComAtraso("Vamos começar!\n\n", 30);
                pressioneEnter();

                // PERGUNTA 1
                printf("1) Quanto é 2+2?\n\na) 8\nb) 4\nc) 2\nd) 0\n\n");
                scanf(" %c", &r1);
                if (r1 == 'b') {
                    printf("Resposta correta!\n\n");
                    pressioneEnter();
                } else {
                    printf("Resposta incorreta! A resposta correta é a letra b) '4!'\n\n");
                    pressioneEnter();
                }

                // PERGUNTA 2
                printf("2) Quem descobriu o Brasil?\n\na) Pedro Álvares Cabral\nb) Cristóvão Colombo\nc) Índios\nd) Rainha Elizabeth\n\n");
                scanf(" %c", &r2);
                if (r2 == 'a') {
                    printf("Resposta correta!\n\n");
                    pressioneEnter();
                } else {
                    printf("Resposta incorreta! A resposta correta é a letra a) 'Pedro Álvares Cabral!'\n\n");
                    pressioneEnter();
                }

                // PERGUNTA 3
                printf("3) Que tipo de fruta é laranja?\n\na) Toranja\nb) Limão Galego\nc) Tangerina\nd) Todas as anteriores\n\n");
                scanf(" %c", &r3);
                if (r3 == 'd') {
                    printf("Resposta correta!\n\n");
                    pressioneEnter();
                } else {
                    printf("Resposta incorreta! A resposta correta é a letra d) 'Todas as anteriores!'\n\n");
                    pressioneEnter();
                }

                // PERGUNTA 4
                printf("4) Quem vendeu o Alasca para os EUA?\n\na) Rússia\nb) Canadá\nc) Dinamarca\nd) Suécia\n\n");
                scanf(" %c", &r4);
                if (r4 == 'a') {
                    printf("Resposta correta!\n\n");
                    pressioneEnter();
                } else {
                    printf("Resposta incorreta! A resposta correta é a letra a) 'Rússia!'\n\n");
                    pressioneEnter();
                }

                // PERGUNTA 5
                printf("5) Qual o ano que a Seleção Brasileira foi campeã pela primeira vez?\n\na) 1958\nb) 1962\nc) 1970\nd) 1994\n\n");
                scanf(" %c", &r5);
                if (r5 == 'a') {
                    printf("Resposta correta!\n\n");
                    pressioneEnter();
                } else {
                    printf("Resposta incorreta! A resposta correta é a letra a) '1958!'\n\n");
                    pressioneEnter();
                }

                
                exibirComAtraso("Deseja jogar novamente ou voltar ao menu principal?\n\n", 30);
                printf("1) Jogar novamente\n2) Voltar ao menu principal\n\n");
                scanf("%d", &menu);

            } while (menu == 1); 
        } 
        else if (titulo == 2) { //JOGO 2
            do{ 
                corTexto(5);
                printf("Você escolheu o jogo Cobra na Caixa\n\n");
                corTexto(7);
                exibirComAtraso("Neste jogo, você e seu oponente escolherão um personagem e uma caixa.\n", 30);
                exibirComAtraso("Uma das caixas contém uma cobra e a outra um botão.\n", 30);
                exibirComAtraso("O jogador que escolher a caixa da cobra perde o jogo.\n", 30);
                exibirComAtraso("O jogador que escolher a caixa do botão vence o jogo.\n", 30);
                exibirComAtraso("Vamos começar!\n\n", 30);
                pressioneEnter();

                // JOGO INICIA

                // ESCOLHA DE PERSONAGEM
                do{
                    exibirComAtraso("Escolha o personagem do jogador 1 (1-7): \n\n", 30);
                    for (int i = 0; i < 7; i++){
                        printf("%d. %s\n", i+1, personagem[i]);
                    }
                    scanf("%d", &jogador1);

                    exibirComAtraso("Escolha o personagem do jogador 2 (1-7):\n\n", 30);
                    for (int i = 0; i < 7; i++){
                        printf("%d. %s\n", i+1, personagem[i]);
                    }
                    scanf("%d", &jogador2);

                    if(jogador1 == jogador2){
                        printf("\nOs jogadores não podem escolher o mesmo personagem! Escolham novamente!\n\n");
                        pressioneEnter();
                    }else if (jogador1 == jogador2 || jogador1 < 1 || jogador1 > 7 || jogador2 < 1 || jogador2 > 7){
                        printf("Opção inválida! Digite números de 1 a 7!\n");
                        pressioneEnter();
                    }
                }while(jogador1 == jogador2 || jogador1 < 1 || jogador1 > 7 || jogador2 < 1 || jogador2 > 7);

                printf("\nO Jogador 1 será %s\n\n", personagem[jogador1-1]);
                printf("O jogador 2 sera %s\n\n", personagem[jogador2-1]);
                pressioneEnter();

                // RANDOMIZAÇÃO DA CAIXA
                cobra = rand() % 5 + 1; 
                do{
                    botao = rand() % 5 + 1;
                }while (botao == cobra); 

                primeiroJogador = rand() % 2;
                if (primeiroJogador == 0){
                    printf("%s começará o jogo!\n\n", personagem[jogador1-1]);
                }else{
                    printf("%s começará o jogo!\n\n", personagem[jogador2-1]);
                }

                int resultado = 0; 

                // JOGADORES ESCOLHEM CAIXA
                do{
                    printf("%s, escolha uma caixa (1 a 5): \n\n", personagem[jogador1-1]);
                    scanf("%d", &escolha1);
                    printf("%s, escolha uma caixa (1 a 5): \n\n", personagem[jogador2-1]);
                    scanf("%d", &escolha2);

                    if (escolha1 == escolha2){
                        exibirComAtraso("\nOs dois escolheram a mesma caixa! Escolham novamente!\n\n", 30);
                        resultado = 0;
                        pressioneEnter();
                    }
                    else if (escolha1 == cobra){
                        printf("\n%s escolheu a caixa da cobra! %s venceu!\n\n", personagem[jogador1-1], personagem[jogador2-1]);
                        resultado = 1;
                        pressioneEnter();
                    }
                    else if (escolha2 == cobra){
                        printf("\n%s escolheu a caixa da cobra! %s venceu!\n\n", personagem[jogador2-1], personagem[jogador1-1]);
                        resultado = 1;
                        pressioneEnter();
                    }
                    else if (escolha1 == botao){
                        printf("\n%s escolheu a caixa do botão! %s venceu!\n\n", personagem[jogador1-1], personagem[jogador1-1]);
                        resultado = 1;
                        pressioneEnter();
                    }
                    else if (escolha2 == botao){
                        printf("\n%s escolheu a caixa do botão! %s venceu!\n\n", personagem[jogador2-1], personagem[jogador2-1]);
                        resultado = 1;
                        pressioneEnter();
                    }
                    else{
                        exibirComAtraso("\nNinguém escolheu a caixa da cobra ou do botão! O jogo será reiniciado!\n\n", 30);
                        cobra = rand() % 5 + 1;
                        do{
                            botao = rand() % 5 + 1;
                        }while (botao == cobra);
                    }
                }while(resultado == 0);

                exibirComAtraso("Deseja jogar novamente ou voltar ao menu principal?\n\n", 30);
                printf("1) Jogar novamente\n2) Voltar ao menu principal\n\n");
                scanf("%d", &menu);
            }while(menu == 1);
        } 
        else if (titulo == 3) { //JOGO 3
            do{
                corTexto(6);
                printf("Você escolheu o jogo Gousmas War\n\n");
                corTexto(7);
                exibirComAtraso("Neste jogo de estratégia, dois jogadores jogam em formato de turnos.\n", 0);
                exibirComAtraso("Cada jogador controla duas criaturas chamadas de Gousmas que podem se dividir e acumular fúrias quando atacadas.\n", 0);
                exibirComAtraso("O objetivo é destruir as Gousmas do oponente fazendo com que o nível de fúria dela ultrapasse o valor 5.\n", 0);
                exibirComAtraso("Quando uma Gousma ataca a outra, transfere todo o seu nível de fúria para a Gousma atacada.\n", 0);
                exibirComAtraso("O jogador que destruir todas as Gousmas do adversário primeiro é o vencedor!\n", 0);
                corTexto(2);
                exibirComAtraso("DICA: Você pode dividir a sua Gousma, transferindo uma parte do valor de fúria para a nova Gousma.\n", 0);
                corTexto(12);
                exibirComAtraso("AVISO: Você só pode ter no máximo duas Gousmas em campo.\n", 0);
                corTexto(7);
                exibirComAtraso("Vamos começar!\n\n", 0);
                pressioneEnter();

                // JOGO INICIA

                nivelFuria[0] = nivelFuria[1] = nivelFuria[2] = nivelFuria[3] = 1;
                gousma[0] = gousma[1] = gousma[2] = gousma[3] = 1;
                jogadorGousmas[0] = jogadorGousmas[1] = 2;
                mitoseRealizada[0] = mitoseRealizada[1] = 0;
                rodada = 1;
                ativo = 1;

                int primeiroJogador = rand() % 2;
                int jogadorAtual = primeiroJogador;

                if (jogadorAtual == 0) {
                    exibirComAtraso("Jogador 1 começará o jogo!\n\n", 30);
                } else {
                    exibirComAtraso("Jogador 2 começará o jogo!\n\n", 30);
                }

                int ataquesRealizados = 0; // CONTADOR PARA GARANTIR QUE AMBOS ATAQUEM ANTES DE COMEÇAR A PRÓXIMA RODADA

                while (ativo) {
                    printf("=== Rodada %d ===\n\n", rodada);
                    exibirComAtraso("Níveis de fúria:\n", 30);
                    for (int i = 0; i < 4; i++) {
                        if (gousma[i] == 1) {
                            printf("Gousma %d: %d\n", i + 1, nivelFuria[i]);
                        }
                    }
                    pressioneEnter();

                    printf("É a vez do Jogador %d\n", jogadorAtual + 1);
                    pressioneEnter();

                    int acao;
                    int gousmaAtacada = -1;

                   
                    printf("Escolha uma ação:\n\n");
                    if (mitoseRealizada[jogadorAtual] == 0) {
                        printf("1) Atacar\n2) Mitose\n");
                    } else {
                        printf("1) Atacar\n");
                    }

                    scanf("%d", &acao);
                    while (getchar() != '\n');

                    // VALIDAÇÃO DA AÇÃO
                    if (acao == 2 && mitoseRealizada[jogadorAtual] == 1) {
                        printf("Opção inválida! Você já realizou uma mitose e não pode realizar outra.\n");
                        pressioneEnter();
                        continue;
                    }

                    // ATAQUE
                    if (acao == 1) {
                        int atacante, alvo;

                        // GOUSMA ATACANTE
                        while (1) {
                            printf("Escolha a Gousma atacante (%d-%d): ", jogadorAtual * 2 + 1, jogadorAtual * 2 + 2);
                            scanf("%d", &atacante);
                            while (getchar() != '\n');

                            // VERIFICA SE A GOUSMA ATACANTE PERTENCE AO JOGADOR E ESTÁ VIVA
                            if (atacante >= jogadorAtual * 2 + 1 && atacante <= jogadorAtual * 2 + 2 && gousma[atacante - 1] == 1) {
                                break;
                            } else {
                                printf("Seleção inválida! Escolha uma Gousma que pertença a você e esteja viva.\n");
                            }
                        }

                        // GOUSMA ALVO
                        while (1) {
                            printf("Escolha a Gousma alvo (%d-%d): ", (1 - jogadorAtual) * 2 + 1, (1 - jogadorAtual) * 2 + 2);
                            scanf("%d", &alvo);
                            while (getchar() != '\n');

                            // VERIFICA SE A GOUSMA ALVO PERTENCE AO JOGADOR E ESTÁ VIVA
                            if (alvo >= (1 - jogadorAtual) * 2 + 1 && alvo <= (1 - jogadorAtual) * 2 + 2 && gousma[alvo - 1] == 1) {
                                break;
                            } else {
                                printf("Seleção inválida! Escolha uma Gousma do adversário que esteja viva.\n");
                            }
                        }

                        // REALIZA O ATAQUE
                        nivelFuria[alvo - 1] += nivelFuria[atacante - 1];
                        nivelFuria[atacante - 1] = 0;
                        printf("Gousma %d atacou Gousma %d!\n", atacante, alvo);

                        // VERIFICA SE A GOUSMA ATACADA MORREU
                        if (nivelFuria[alvo - 1] >= 6) {
                            printf("Gousma %d morreu!\n", alvo);
                            gousma[alvo - 1] = 0; 
                            if (alvo - 1 < 2) {
                                jogadorGousmas[0]--;
                            } else {
                                jogadorGousmas[1]--;
                            }
                        }
                        pressioneEnter();
                      
                        // MITOSE
                    } else if (acao == 2) { 
                        int origem, destino;

                        // JOGADOR 1
                        if (jogadorAtual == 0) {
                            if (gousma[0] == 1 && gousma[1] == 0) {
                                origem = 1;
                                destino = 2;
                            } else if (gousma[1] == 1 && gousma[0] == 0) {
                                origem = 2;
                                destino = 1;
                            } else {
                                printf("Mitose não permitida! Você já possui duas Gousmas vivas.\n");
                                pressioneEnter();
                                continue;
                            }

                            // JOGADOR 2
                        } else {
                            if (gousma[2] == 1 && gousma[3] == 0) {
                                origem = 3;
                                destino = 4;
                            } else if (gousma[3] == 1 && gousma[2] == 0) {
                                origem = 4;
                                destino = 3;
                            } else {
                                printf("Mitose não permitida! Você já possui duas Gousmas vivas.\n");
                                pressioneEnter();
                                continue;
                            }
                        }

                        // VERIFICA SE PODE REALIZAR MITOSE
                        if (nivelFuria[origem - 1] > 0 && nivelFuria[origem - 1] % 2 == 0) {
                            int metadeFuria = nivelFuria[origem - 1] / 2;
                            nivelFuria[origem - 1] = metadeFuria; 
                            nivelFuria[destino - 1] = metadeFuria; 
                            gousma[destino - 1] = 1;
                            jogadorGousmas[jogadorAtual]++;
                            mitoseRealizada[jogadorAtual] = 1;
                            printf("Mitose realizada! Gousma %d criou Gousma %d com %d de nível de fúria.\n", origem, destino, metadeFuria);
                        } else {
                            printf("Mitose não permitida! A Gousma deve ter um nível de fúria par e maior que 0.\n");
                        }
                        pressioneEnter();
                    }

                    ataquesRealizados++;

                    // INCREMENTO DE NÍVEL DE FÚRIA EM CADA RODADA
                    if (ataquesRealizados == 2) {
                        for (int i = 0; i < 4; i++) {
                            if (gousma[i] == 1) { 
                                nivelFuria[i]++;
                                printf("Gousma %d teve seu nível de fúria incrementado para %d.\n", i + 1, nivelFuria[i]);
                                if (nivelFuria[i] >= 6) {
                                    printf("Gousma %d morreu!\n", i + 1);
                                    gousma[i] = 0;
                                    if (i < 2) {
                                        jogadorGousmas[0]--;
                                    } else {
                                        jogadorGousmas[1]--;
                                    }
                                }
                            }
                        }
                        ataquesRealizados = 0; // RESET DO CONTADOR DE ATAQUES
                        rodada++;
                    }

                    // VERIFICAÇÃO DE VITÓRIA
                    if (jogadorGousmas[0] == 0) {
                        exibirComAtraso("Jogador 2 venceu!\n", 30);
                        pressioneEnter();
                        ativo = 0;
                    } else if (jogadorGousmas[1] == 0) {
                        exibirComAtraso("Jogador 1 venceu!\n", 30);
                        pressioneEnter();
                        ativo = 0;
                    }

                    jogadorAtual = 1 - jogadorAtual; // ALTERNA O JOGADOR ATUAL
                }

                exibirComAtraso("Deseja jogar novamente ou voltar ao menu principal?\n\n", 30);
                printf("1) Jogar novamente\n2) Voltar ao menu principal\n\n");
                scanf("%d", &menu);

            } while (menu == 1);

        }else if (titulo == 4) { //SAIR
            corTexto(12);
            printf("Você escolheu sair. Até a próxima!\n\n");
            corTexto(7);
            menu = 2;
        } else { //OPÇÃO INVÁLIDA
            printf("Opção inválida. Tente novamente!\n\n");
            menu = 1;
        }

    } while (titulo != 4);

    return 0;
}