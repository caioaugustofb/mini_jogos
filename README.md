# mini_jogos
Jogo dessenvolvido em C pelo aluno Caio Augusto contendo 3 mini jogos selecionados a partir de um menu integrado: 
1) Perguntas e respostas 2) Cobra na caixa 3) Gousmas War


Aqui irei colocar algumas informações relacionadas ao meu jogo e o processo de desenvolvimento incluindo minhas conversas com o Copilot do Vscode
Primeiramente devo informar que minhas conversas foram perdidas devido a eu ter desabilitado o copilot do vscode para tentar solucionar um problema 
de resposta que o próprio chat do Copilot estava oferecendo e eu estava utilizando ele para me ajudar com algumas dúvidas e dificuldades que tive no código. Quando estava configurando tudo que precisava para fazer o commit dos arquivos para o github, fechei o vscode e o projeto para alterar nomes de pasta e etc, com isso meu histórico todo foi apagado e eu não consegui recuperar 
minhas conversas com o copilot, mas irei informar tudo que foi utilizado a partir da IA.
Utilizei o Copilot para me auxiliar a "enfeitar" meu jogo, coisas como: alterar as cores das fontes que estariam sendo executadas em certas
linhas, criar funções que iriam me ajudar com escrita de caracteres um por um, uma função para que eu tenha que pressionar enter antes de 
executar as próximas linhas de código como mostrado a seguir:

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

Também recebi auxílio em relação a bibliotecas como a #include <windows.h> e a #include <time.h> que me permitiram utilizar as funções de cores
e de randomização respectivamente, por exemplo. A função de randomizar também era desconhecida para mim, o Copilot me informou como eu poderia 
fazer essa randomização das caixas e dos jogadores que iriam jogar por primeiro nos dois jogos.

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

int primeiroJogador = rand() % 2;
int jogadorAtual = primeiroJogador;
                
Meu código continha alguns erros que não estava conseguindo resolver, não estava visualizando os erros e pedi ajuda para o Copilot me auxiliar
nisso. O Copilot me forneceu soluções para ajudar no meu código como por exemplo o uso de Arrays para algumas variáveis, demonstrando como 
ficaria e o porque era melhor utilizar dessa forma. Um exemplo disso são as linhas de código a seguir:

 int gousma[4] = {1, 1, 1, 1};
    int nivelFuria[4] = {1, 1, 1, 1};
    int jogadorGousmas[2] = {2, 2};
    int jogadoresAtacaram = 0;
    int mitoseRealizada[2] = {0, 0};

nivelFuria[0] = nivelFuria[1] = nivelFuria[2] = nivelFuria[3] = 1;
gousma[0] = gousma[1] = gousma[2] = gousma[3] = 1;
jogadorGousmas[0] = jogadorGousmas[1] = 2;
mitoseRealizada[0] = mitoseRealizada[1] = 0;

Também pedi ajuda em relação a minha função pressioneEnter que estava fazendo com que o jogador precisasse pressionar a tecla Enter para 
continuar para a próxima linha de código, no caso o que estava acontecendo era que o código estava sendo executado sem chamar a minha 
função criada e eu não estava compreendendo o porque. 

void pressioneEnter() {
    printf("Pressione ENTER para continuar...\n");
    while (getchar() != '\n');
    getchar();
}

O Copilot me informou sobre o buffer de entrada que faz com que após um scanf o código armazena um caractere residual \n que é o mesmo
que apertar Enter para ir para a próxima linha e isso entra em conflito com o getchar() da minha função criada, fazendo com que o código
entenda que toda vez que ele ler o getchar() da função, ele deve eliminar o \n e esperar uma próxima entrada (que seria o jogador pressionar Enter).
Essa função funcionou normalmente para os dois primeiros jogos, porém no Gousmas War houve esse problema e o Copilot me sugeriu adicionar a seguinte 
linha de código em algumas partes do meu código:

while (getchar() != '\n');

Basicamente sendo uma repetição do que já estava na minha função para ver se conseguia resolver o problema, porém infelizmente não consegui
resolver esse problema e após a adição do While o jogador precisa pressionar Enter duas vezes. Quando retirei o While o comportamento se repetiu
de a função não ser chamada em algumas partes do terceiro jogo, pois o jogo estava ignorando minha função pressioneEnter, então por conta disso
decidi manter o While no código e deixar que o jogador precise pressionar duas vezes o Enter, já que a minha função pressioneEnter funcionou 
corretamente para os dois primeiros jogos, mas teve problema apenas para o terceiro.

Essas foram minhas interações com o Copilot. Infelizmente não consegui trazer o histórico de conversas, mas espero que tenha ficado claro 
tudo o que foi feito com o auxilio do mesmo.
