typedef struct {
    int id;
    char marca[50];
    char modelo[50];
    char matricula[20];
    int ano;
    float preco;
} Carro;

typedef struct{
	Carro *dados;
	int capacidade;
	int tamanho;
}ListaCarros;
