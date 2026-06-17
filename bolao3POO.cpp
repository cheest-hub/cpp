#include <iostream>
#include <string>
#include <windows.h> 

// --- CLASSE JOGO ---
class Jogo {
private:
    std::string timeA;
    std::string timeB;
    int golsA;
    int golsB;
    bool resultadoRegistrado;

public:
    Jogo() : timeA(""), timeB(""), golsA(-1), golsB(-1), resultadoRegistrado(false) {}

    Jogo(std::string tA, std::string tB) : timeA(tA), timeB(tB), golsA(-1), golsB(-1), resultadoRegistrado(false) {}

    void registrarResultado(int gA, int gB) {
        golsA = gA;
        golsB = gB;
        resultadoRegistrado = true;
    }

    std::string getConfronto() const { return timeA + " x " + timeB; }
    int getGolsA() const { return golsA; }
    int getGolsB() const { return golsB; }
    bool foiRegistrado() const { return resultadoRegistrado; }
};

// --- CLASSE APOSTADOR ---
class Apostador {
private:
    std::string nome;
    int* palpitesA; 
    int* palpitesB; 
    int totalJogos;
    int pontuacao;
    bool apostasFeitas;

public:
    Apostador() {
        nome = "Sem Nome";
        totalJogos = 4;
        pontuacao = 0;
        apostasFeitas = false;
        palpitesA = new int[totalJogos];
        palpitesB = new int[totalJogos];
    }

    ~Apostador() {
        delete[] palpitesA;
        delete[] palpitesB;
    }

    void setNome(std::string n) { nome = n; }
    std::string getNome() const { return nome; }
    int getPontuacao() const { return pontuacao; }
    bool jaApostou() const { return apostasFeitas; }

    void registrarPalpite(int indiceJogo, int gA, int gB) {
        if (indiceJogo >= 0 && indiceJogo < totalJogos) {
            palpitesA[indiceJogo] = gA;
            palpitesB[indiceJogo] = gB;
            if (indiceJogo == totalJogos - 1) {
                apostasFeitas = true;
            }
        }
    }

    void calcularPontos(const Jogo jogosOficiais[]) {
        pontuacao = 0; 
        for (int i = 0; i < totalJogos; i++) {
            if (!jogosOficiais[i].foiRegistrado()) continue;

            int realA = jogosOficiais[i].getGolsA();
            int realB = jogosOficiais[i].getGolsB();
            int palpiteA = palpitesA[i];
            int palpiteB = palpitesB[i];

            if (palpiteA == realA && palpiteB == realB) {
                pontuacao += 10;
            }
            else {
                bool realGanhouA = realA > realB;
                bool realGanhouB = realB > realA;
                bool realEmpate = realA == realB;

                bool palpiteGanhouA = palpiteA > palpiteB;
                bool palpiteGanhouB = palpiteB > palpiteA;
                bool palpiteEmpate = palpiteA == palpiteB;

                if ((realGanhouA && palpiteGanhouA) || (realGanhouB && palpiteGanhouB) || (realEmpate && palpiteEmpate)) {
                    pontuacao += 5;
                }

                if ((realA - realB) == (palpiteA - palpiteB)) {
                    pontuacao += 2;
                }
            }
        }
    }
};

// --- FUNÇÃO PRINCIPAL ---
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int TOTAL_JOGOS = 4;
    const int TOTAL_JOGADORES = 3;

    Jogo jogos[TOTAL_JOGOS] = {
        Jogo("BRA", "EGT"),
        Jogo("RSA", "MAR"),
        Jogo("FRA", "ARG"),
        Jogo("GER", "COS")
    };

    Apostador apostadores[TOTAL_JOGADORES];
    int opcao = 0;

    do {
        std::cout << "\n===================================\n";
        std::cout << "      BOLÃO DA COPA DO MUNDO 2026  \n";
        std::cout << "===================================\n";
        std::cout << "(1) Registrar resultados oficiais dos jogos\n";
        std::cout << "(2) Registrar apostas dos jogadores\n";
        std::cout << "(3) Calcular pontuação e exibir ranking\n";
        std::cout << "(4) Sair do programa\n";
        std::cout << "-----------------------------------\n";
        std::cout << "Escolha uma opção: ";
        
        if (!(std::cin >> opcao)) { 
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\nOpção inválida! Digite um número.\n";
            continue;
        }

        switch (opcao) {
            case 1: {
                std::cout << "\n--- REGISTRAR RESULTADOS OFICIAIS ---\n";
                std::cout << "Deseja preencher com os resultados oficiais padrões? (S/N): ";
                char resp;
                std::cin >> resp;
                
                if (resp == 'S' || resp == 's') {
                    // CORREÇÃO DOS ERROS DE SINTAXE: Adicionados os índices, [1], [2], [3]
                    jogos[0].registrarResultado(3, 0);
                    jogos[1].registrarResultado(1, 1);
                    jogos[2].registrarResultado(1, 2);
                    jogos[3].registrarResultado(4, 2);
                    std::cout << "Resultados oficiais gravados com sucesso!\n";
                } else {
                    for (int i = 0; i < TOTAL_JOGOS; i++) {
                        int gA, gB;
                        std::cout << "\nPlacar de " << jogos[i].getConfronto() << "\n";
                        std::cout << "  Gols do " << jogos[i].getConfronto().substr(0,3) << ": "; std::cin >> gA;
                        std::cout << "  Gols do " << jogos[i].getConfronto().substr(6,3) << ": "; std::cin >> gB;
                        jogos[i].registrarResultado(gA, gB);
                    }
                }
                break;
            }
            case 2: {
                std::cout << "\n--- REGISTRAR APOSTAS DOS JOGADORES ---\n";
                for (int i = 0; i < TOTAL_JOGADORES; i++) {
                    std::cin.ignore(1000, '\n'); 
                    
                    std::string nome;
                    std::cout << "\nNome do Apostador #" << (i + 1) << ": ";
                    std::getline(std::cin, nome);
                    apostadores[i].setNome(nome);

                    for (int j = 0; j < TOTAL_JOGOS; j++) {
                        int palpiteA, palpiteB;
                        std::cout << "  Palpite para " << jogos[j].getConfronto() << "\n";
                        std::cout << "    Gols do " << jogos[j].getConfronto().substr(0,3) << ": "; std::cin >> palpiteA;
                        std::cout << "    Gols do " << jogos[j].getConfronto().substr(6,3) << ": "; std::cin >> palpiteB;
                        apostadores[i].registrarPalpite(j, palpiteA, palpiteB);
                    }
                }
                break;
            }
            case 3: {
                if (!jogos[0].foiRegistrado()) { // Ajustado para checar o índice do vetor
                    std::cout << "\n[ERRO] Registre os resultados oficiais (Opção 1) antes de ver o ranking!\n";
                    break;
                }
                if (!apostadores[0].jaApostou()) { // Ajustado para checar o índice do vetor
                    std::cout << "\n[ERRO] Registre as apostas dos jogadores (Opção 2) antes de ver o ranking!\n";
                    break;
                }

                for (int i = 0; i < TOTAL_JOGADORES; i++) {
                    apostadores[i].calcularPontos(jogos);
                }

                Apostador* ranking[TOTAL_JOGADORES];
                for (int i = 0; i < TOTAL_JOGADORES; i++) {
                    ranking[i] = &apostadores[i];
                }

                for (int i = 0; i < TOTAL_JOGADORES - 1; i++) {
                    for (int j = 0; j < TOTAL_JOGADORES - i - 1; j++) {
                        if (ranking[j]->getPontuacao() < ranking[j + 1]->getPontuacao()) {
                            Apostador* temp = ranking[j];
                            ranking[j] = ranking[j + 1];
                            ranking[j + 1] = temp;
                        }
                    }
                }

                std::cout << "\n===================================\n";
                std::cout << "         RANKING DO BOLAÇÃO        \n";
                std::cout << "===================================\n";
                for (int i = 0; i < TOTAL_JOGADORES; i++) {
                    std::cout << " " << (i + 1) << "º Lugar: " 
                              << ranking[i]->getNome() << " - " 
                              << ranking[i]->getPontuacao() << " pontos\n";
                }
                std::cout << "===================================\n";
                break;
            }
            case 4:
                std::cout << "\nEncerrando o programa do Bolão. Até logo!\n";
                break;
            default:
                std::cout << "\nOpção inválida! Tente novamente.\n";
                break;
        }

    } while (opcao != 4);

    return 0;
}