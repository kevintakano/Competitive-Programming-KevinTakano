#include <stdio.h>
#include <stdlib.h>

int main(){

	int i;
	int n;
	int aux;
	int total;
	int *circulo = NULL;
	int numeros[100001];
	int umTerco = 0;
	int qntTriangulos = 0;
	
	while(scanf("%d", &n)!= EOF){

		//Recebe a quantidade de distâncias dadas na questão

		qntTriangulos = 0;
		total = 0;

		//Le as distâncias e salva cada uma em um vetor
		//Guarda o total das distancias

		for(i = 0; i < n; i++){
			scanf("%d", &aux);
			numeros[i] = aux;
			total = total + aux;
		}

		//Vejo quanto e um terco do total do circulo
		//Porque pra formar o triangulo cada ponto tem que estar
		//A um terco da posicao, sei la, n sei essas coisas de geometria

		umTerco = total/3;

		//Crio meu vetorzao simbolizando meu circulo

		circulo = (int*)calloc(total, sizeof(int));

		//Digo que a primeira posicao tem um ponto
		//Assim todos os outros pontos sao referenciadas
		//a partir desse ponto

		circulo[0] = 1;
		aux = 0;

		//Faco essas distancias virarem posicoes no meu circulo
		//Marco 1 no meu vetor que representa circulo pra dizer
		//Onde tem um ponto

		for(i = 0; i < n; i++){
			aux = aux + numeros[i];
			numeros[i] = aux;
			circulo[aux % total] = 1;
		}

		//Pra cada distancia que eu dei, eu vejo se a minha posicao
		//E 1 ou outra coisa (parece que eu to repetindo um passo)
		//Se tudo der 1, quer dizer que forma um triangulo
		//Logo somo na minha variavel
		//Usei o indice desse vetor pra armazenar as posicoes dos
		//Pontos pra nao ter que percorrer o outro vetor de distancias
		//Um bilhao de vezes pra verificar se os elementos tinham distancias
		//De um terco do tamanho do circulo
		//Teria que andar pelo vetor até ou achar, ou passar dessa distância.
		//Acho que com hash resolveria também, mas não tenho certeza e não sei
		//Usar :v
		for(i = 0; i < n; i++){
			if(circulo[numeros[i]] == 1 && circulo[(numeros[i] + umTerco) % total] == 1 && circulo[(numeros[i] + umTerco + umTerco) % total] == 1){
				circulo[numeros[i]] = 2;
				circulo[(numeros[i] + umTerco) % total] = 2;
				circulo[(numeros[i] + umTerco + umTerco) % total] = 2;
				qntTriangulos++;
			}
		}

		printf("%d\n", qntTriangulos);
		free(circulo);

	}
	return 0;

}