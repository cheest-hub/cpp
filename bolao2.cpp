#include <iostream>
#include <vector>   // Biblioteca essencial para usar vetores dinâmicos
#include <string>
#include <algorithm> // Necessária para o método sort() de vetores

using namespace std;

// Estruturas de dados usando vetores e tipos primitivos
struct Jogo {
    int id;
    string timeCasa;
    string timeFora;
    int golsCasa;
    int golsFora;
};

struct Palpite {
    int idJogo;
    int golsCasa;
    int golsFora;
};

struct Participante {
    string nome;
    vector<Palpite> palpites; // Vetor dinâmico de palpites dentro de cada participante
    int totalPontos = 0;
};

// Função para ordenar o vetor de participantes (maior pontuação primeiro)
bool compararParticipantes(const Participante& a, const Participante& b) {
    return a.totalPontos > b.totalPontos;
}

// Função com a sua regra de pontuação exata (10, 5, 2 ou 0)
int calcularPontosDoPalpite(int pCasa, int pFora, int rCasa, int rFora) {
    if (pCasa == rCasa && pFora == rFora) {
        return 10; // Placar exato
    }
    
    int tendenciaPalpite = (pCasa > pFora) ? 1 : ((pCasa < pFora) ? -1 : 0);
    int tendenciaReal = (rCasa > rFora) ? 1 : ((rCasa < rFora) ? -1 : 0);
    
    if (tendenciaPalpite == tendenciaReal) {
        if (tendenciaReal == 0) {
            return 2; // Acertou empate
        } else {
            return 5; // Acertou ganhador
        }
    }
    return 0; // Errou tudo
}

int main() {
    // 1. VETOR DO BANCO DE DADOS (Resultados Reais)
    // O tamanho do vetor é definido dinamicamente pelos elementos inseridos
    vector<Jogo> resultadosReais = {
        {1, "Brasil", "Argentina", 2, 1},
        {2, "Franca", "Italia",    1, 1},
        {3, "Espanha", "Alemanha",  0, 2}
    };

    // 2. VETOR DE PARTICIPANTES
    vector<Participante> participantes;
    int qtdParticipantes;

    cout << "=== BOLAO C++ UTILIZANDO VETORES ===" << endl;
    cout << "Quantos participantes deseja registrar? ";
    cin >> qtdParticipantes;
    cout << endl;

    // Preenchendo o vetor de participantes através do teclado
    for (int i = 0; i < qtdParticipantes; i++) {
        Participante p;
        cout << "Nome do participante " << i + 1 << ": ";
        cin >> p.nome;

        cout << "--- Digite os palpites para " << p.nome << " ---" << endl;
        
        // Percorrendo o vetor de jogos reais usando um loop range-based
        for (const auto& jogo : resultadosReais) {
            Palpite palpite;
            palpite.idJogo = jogo.id;
            
            cout << jogo.timeCasa << " x " << jogo.timeFora << endl;
            cout << "Gols do " << jogo.timeCasa << ": ";
            cin >> palpite.golsCasa;
            cout << "Gols do " << jogo.timeFora << ": ";
            cin >> palpite.golsFora;
            
            // Inserindo o palpite dentro do vetor interno do participante
            p.palpites.push_back(palpite);
        }
        
        // Inserindo o participante completo no vetor principal
        participantes.push_back(p);
        cout << "-----------------------------------" << endl;
    }

    // 3. PROCESSAMENTO DE DADOS (Cruzamento de Vetores)
    // Usamos referências (&) para modificar os pontos diretamente no vetor original
    for (auto& p : participantes) {
        for (const auto& palpite : p.palpites) {
            for (const auto& jogoReal : resultadosReais) {
                if (jogoReal.id == palpite.idJogo) {
                    int pontos = calcularPontosDoPalpite(
                        palpite.golsCasa, palpite.golsFora, 
                        jogoReal.golsCasa, jogoReal.golsFora
                    );
                    p.totalPontos += pontos;
                }
            }
        }
    }

    // 4. ORDENAÇÃO DO VETOR
    // O algoritmo sort rearranja os elementos do vetor participantes automaticamente
    sort(participantes.begin(), participantes.end(), compararParticipantes);

    // 5. EXIBIÇÃO DO RANKING (Lendo do Vetor Ordenado)
    cout << "\n===================================" << endl;
    cout << "         RANKING DO BOLAO          " << endl;
    cout << "===================================" << endl;
    
    // Acessando os dados do vetor usando índices baseados no tamanho (.size())
    for (size_t i = 0; i < participantes.size(); i++) {
        cout << i + 1 << "º Lugar: " << participantes[i].nome 
             << " - " << participantes[i].totalPontos << " pontos" << endl;
    }
    cout << "===================================" << endl;

    return 0;
}
