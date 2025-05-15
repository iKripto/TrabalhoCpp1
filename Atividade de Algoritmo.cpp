#include <iostream>
#include <string>
using namespace std;

struct Cidade {
    int codigo;
    string nome;
    string UF;
};

struct Raca {
    int codigo;
    string descricao;
};

struct Tutor {
    int codigo;
    string nome;
    string CPF;
    string endereco;
    int codigoCidade;
};

struct Animal {
    int codigo;
    string nome;
    int codigoRaca;
    int idade;
    float peso;
    int codigoTutor;
};

struct Veterinario {
    int codigo;
    string nome;
    string endereco;
    int codigoCidade;
};

struct Consulta {
    int codigo;
    int codigoAnimal;
    int codigoVeterinario;
    string data;
    float valor;
};

Cidade lerCidade() {
    Cidade c;
    cout << "Codigo: ";
    cin >> c.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, c.nome);
    cout << "UF: ";
    getline(cin, c.UF);
    return c;
}

Raca lerRaca() {
    Raca r;
    cout << "Codigo: ";
    cin >> r.codigo;
    cin.ignore();
    cout << "Descricao: ";
    getline(cin, r.descricao);
    return r;
}

Veterinario lerVeterinario() {
    Veterinario v;
    cout << "Codigo: ";
    cin >> v.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, v.nome);
    cout << "Endereco: ";
    getline(cin, v.endereco);
    cout << "Codigo da cidade: ";
    cin >> v.codigoCidade;
    cin.ignore();
    return v;
}

bool validarCPF(string cpf) {
    string cpfLimpo;
    for (char c : cpf) {
        if (isdigit(c)) cpfLimpo += c;
    }
    
    if (cpfLimpo.length() != 11) return false;
    
    bool igual = true;
    for (int i = 1; i < 11; i++) {
        if (cpfLimpo[i] != cpfLimpo[0]) {
            igual = false;
            break;
        }
    }
    if (igual) return false;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpfLimpo[i] - '0') * (10 - i);
    }
    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    if (digito1 != (cpfLimpo[9] - '0')) return false;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpfLimpo[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    if (digito2 != (cpfLimpo[10] - '0')) return false;

    return true;
}

void incluirTutor(Tutor tutores[], int &numTutores, Cidade cidades[], int numCidades) {
    Tutor t;
    cout << "Codigo: ";
    cin >> t.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, t.nome);

    bool cpfValido = false;
    do {
        cout << "CPF: ";
        getline(cin, t.CPF);
        cpfValido = validarCPF(t.CPF);
        if (!cpfValido) cout << "CPF invalido!\n";
    } while (!cpfValido);

    cout << "Endereco: ";
    getline(cin, t.endereco);

    cout << "Codigo da cidade: ";
    cin >> t.codigoCidade;
    cin.ignore();

    bool encontrou = false;
    for (int i = 0; i < numCidades; i++) {
        if (cidades[i].codigo == t.codigoCidade) {
            cout << "Cidade: " << cidades[i].nome << "/" << cidades[i].UF << endl;
            encontrou = true;
            break;
        }
    }
    if (!encontrou) cout << "Cidade nao encontrada!\n";

    tutores[numTutores++] = t;
    cout << "Tutor cadastrado!\n";
}

void incluirAnimal(Animal animais[], int &numAnimais, Raca racas[], int numRacas, Tutor tutores[], int numTutores, Cidade cidades[], int numCidades) {
    Animal a;
    cout << "Codigo: ";
    cin >> a.codigo;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, a.nome);

    cout << "Codigo da raca: ";
    cin >> a.codigoRaca;
    cin.ignore();
    bool racaEncontrada = false;
    for (int i = 0; i < numRacas; i++) {
        if (racas[i].codigo == a.codigoRaca) {
            cout << "Raca: " << racas[i].descricao << endl;
            racaEncontrada = true;
            break;
        }
    }
    if (!racaEncontrada) cout << "Raça não encontrada!\n";

    cout << "Idade: ";
    cin >> a.idade;
    cout << "Peso: ";
    cin >> a.peso;
    cin.ignore();

    cout << "Codigo do tutor: ";
    cin >> a.codigoTutor;
    cin.ignore();
    bool tutorEncontrado = false;
    bool cidadeEncontrada = false;
    for (int i = 0; i < numTutores; i++) {
        if (tutores[i].codigo == a.codigoTutor) {
            tutorEncontrado = true;
            cout << "Tutor: " << tutores[i].nome << endl;
            for (int j = 0; j < numCidades; j++) {
                if (cidades[j].codigo == tutores[i].codigoCidade) {
                    cout << "Cidade: " << cidades[j].nome << "/" << cidades[j].UF << endl;
                    cidadeEncontrada = true;
                    break;
                }
            }
            break;
        }
    }
    if (!tutorEncontrado) cout << "Tutor nao encontrado!\n";

    animais[numAnimais++] = a;
    cout << "Animal cadastrado!\n";
}

void incluirConsulta(Consulta consultas[], int &numConsultas, int &proximoCodigo, Animal animais[], int numAnimais, Veterinario veterinarios[], int numVeterinarios, Tutor tutores[], int numTutores, Raca racas[], int numRacas, Cidade cidades[], int numCidades) {
    Consulta c;
    c.codigo = proximoCodigo++;

    cout << "Codigo do animal: ";
    cin >> c.codigoAnimal;
    cin.ignore();
    bool animalEncontrado = false;
    string nomeAnimal, nomeRaca, nomeTutor;
    for (int i = 0; i < numAnimais; i++) {
        if (animais[i].codigo == c.codigoAnimal) {
            animalEncontrado = true;
            nomeAnimal = animais[i].nome;
            for (int j = 0; j < numRacas; j++) {
                if (racas[j].codigo == animais[i].codigoRaca) {
                    nomeRaca = racas[j].descricao;
                    break;
                }
            }
            for (int j = 0; j < numTutores; j++) {
                if (tutores[j].codigo == animais[i].codigoTutor) {
                    nomeTutor = tutores[j].nome;
                    break;
                }
            }
            break;
        }
    }
    if (animalEncontrado) {
        cout << "Animal: " << nomeAnimal << endl;
        cout << "Raca: " << nomeRaca << endl;
        cout << "Tutor: " << nomeTutor << endl;
    } else {
        cout << "Animal nao encontrado!\n";
    }

    cout << "Codigo do veterinario: ";
    cin >> c.codigoVeterinario;
    cin.ignore();
    bool vetEncontrado = false;
    string nomeVet, cidadeVet;
    for (int i = 0; i < numVeterinarios; i++) {
        if (veterinarios[i].codigo == c.codigoVeterinario) {
            vetEncontrado = true;
            nomeVet = veterinarios[i].nome;
            for (int j = 0; j < numCidades; j++) {
                if (cidades[j].codigo == veterinarios[i].codigoCidade) {
                    cidadeVet = cidades[j].nome + "/" + cidades[j].UF;
                    break;
                }
            }
            break;
        }
    }
    if (vetEncontrado) {
        cout << "Veterinario: " << nomeVet << endl;
        cout << "Cidade: " << cidadeVet << endl;
    } else {
        cout << "Veterinario nao encontrado!\n";
    }

    cout << "Data (DD/MM/AAAA): ";
    getline(cin, c.data);
    cout << "Valor: ";
    cin >> c.valor;
    cin.ignore();

    consultas[numConsultas++] = c;
    cout << "Consulta cadastrada! Codigo: " << c.codigo << endl;
}

void exibirConsultasPorData(Consulta consultas[], int numConsultas, Animal animais[], int numAnimais, Veterinario veterinarios[], int numVeterinarios) {
    string inicio, fim;
    cout << "Data inicial (DD/MM/AAAA): ";
    getline(cin, inicio);
    cout << "Data final (DD/MM/AAAA): ";
    getline(cin, fim);

    float total = 0;
    for (int i = 0; i < numConsultas; i++) {
        if (consultas[i].data >= inicio && consultas[i].data <= fim) {
            string nomeAnimal, nomeVet;
            for (int j = 0; j < numAnimais; j++) {
                if (animais[j].codigo == consultas[i].codigoAnimal) {
                    nomeAnimal = animais[j].nome;
                    break;
                }
            }
            for (int j = 0; j < numVeterinarios; j++) {
                if (veterinarios[j].codigo == consultas[i].codigoVeterinario) {
                    nomeVet = veterinarios[j].nome;
                    break;
                }
            }
            cout << "Animal: " << nomeAnimal 
                 << " | Vet: " << nomeVet 
                 << " | Data: " << consultas[i].data 
                 << " | Valor: " << consultas[i].valor << endl;
            total += consultas[i].valor;
        }
    }
    cout << "Total: " << total << endl;
}

void exibirConsultasPorVeterinario(Consulta consultas[], int numConsultas, Animal animais[], int numAnimais, Veterinario veterinarios[], int numVeterinarios) {
    int codVet;
    string inicio, fim;
    cout << "Código do veterinário: ";
    cin >> codVet;
    cin.ignore();
    cout << "Data inicial (DD/MM/AAAA): ";
    getline(cin, inicio);
    cout << "Data final (DD/MM/AAAA): ";
    getline(cin, fim);

    float total = 0;
    for (int i = 0; i < numConsultas; i++) {
        if (consultas[i].codigoVeterinario == codVet && 
            consultas[i].data >= inicio && 
            consultas[i].data <= fim) {
            
            string nomeAnimal, nomeVet;
            for (int j = 0; j < numAnimais; j++) {
                if (animais[j].codigo == consultas[i].codigoAnimal) {
                    nomeAnimal = animais[j].nome;
                    break;
                }
            }
            for (int j = 0; j < numVeterinarios; j++) {
                if (veterinarios[j].codigo == consultas[i].codigoVeterinario) {
                    nomeVet = veterinarios[j].nome;
                    break;
                }
            }
            cout << "Animal: " << nomeAnimal 
                 << " | Vet: " << nomeVet 
                 << " | Data: " << consultas[i].data 
                 << " | Valor: " << consultas[i].valor << endl;
            total += consultas[i].valor;
        }
    }
    cout << "Total: " << total << endl;
}

int main() {
    const int MAX = 100;
    Cidade cidades[MAX];
    Raca racas[MAX];
    Tutor tutores[MAX];
    Animal animais[MAX];
    Veterinario veterinarios[MAX];
    Consulta consultas[MAX];
    int numCidades = 0, numRacas = 0, numTutores = 0, numAnimais = 0, numVeterinarios = 0, numConsultas = 0;
    int proximoCodigoConsulta = 1;

    int opcao;
    do {
        cout << "\n=== MENU ==="
             << "\n1. Cadastrar Cidade"
             << "\n2. Cadastrar Raca"
             << "\n3. Cadastrar Veterinario"
             << "\n4. Cadastrar Tutor"
             << "\n5. Cadastrar Animal"
             << "\n6. Nova Consulta"
             << "\n7. Relatorio por Periodo"
             << "\n8. Relatorio por Veterinario"
             << "\n9. Sair"
             << "\nOpcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1:
                cidades[numCidades++] = lerCidade();
                break;
            case 2:
                racas[numRacas++] = lerRaca();
                break;
            case 3:
                veterinarios[numVeterinarios++] = lerVeterinario();
                break;
            case 4:
                incluirTutor(tutores, numTutores, cidades, numCidades);
                break;
            case 5:
                incluirAnimal(animais, numAnimais, racas, numRacas, tutores, numTutores, cidades, numCidades);
                break;
            case 6:
                incluirConsulta(consultas, numConsultas, proximoCodigoConsulta, animais, numAnimais, veterinarios, numVeterinarios, tutores, numTutores, racas, numRacas, cidades, numCidades);
                break;
            case 7:
                exibirConsultasPorData(consultas, numConsultas, animais, numAnimais, veterinarios, numVeterinarios);
                break;
            case 8:
                exibirConsultasPorVeterinario(consultas, numConsultas, animais, numAnimais, veterinarios, numVeterinarios);
                break;
            case 9:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 9);

    return 0;
}

