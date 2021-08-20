/********************************
 Anna Carolina Ravazzi Martins
 Engenharia da Computação
 UTFPR 2021.1
 Estrutura de Dados 1
********************************/

#include "queue.h"
#define SIZE 8

/*Checa se o cavalo está dentro dos limites do tabuleiro*/
int valid_pos (int x, int y)
{
	return ((x >= 0 && x < SIZE) && (y >= 0 && y < SIZE));
}

/*Função realiza a BFS e retorna a referência para a célula de destino (com a menor distância
  armazenada no campo "dist" da struct)*/
Cell* bfs_knight (int x_src, int y_src, int x_dest, int y_dest, Queue *q)
{
	/*Movimentos possíveis do cavalo como variações em x e y*/
	int dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
	int dx[8] = {-1, 1, -2, 2, -1, 1, -2, 2};

	/*Matriz mantém o controle das células que já foram visitadas no tabuleiro*/
	int visited[SIZE][SIZE] = {0};

	/*Enfilera a célula de origem com as coordenadas dadas, distância 0 da origem e referência
	  à célula pai como NULL (por ser a primeira)*/
	enqueue(q, x_src, y_src, 0, NULL);
	/*Marca as coordenadas iniciais como visitadas*/
	visited[x_src][y_src] = 1;

	/*Roda até a fila estar vazia*/
	while(!empty_queue(q))
	{
		/*Desenfilera a célula analisada atualmente*/
		Cell *p = dequeue(q);

		/*Se o ponto atual é o destino, retorna a célula correspondente*/
		if(p->x == x_dest && p->y == y_dest)
			return p;

		/*Loop itera por todos os movimentos possíveis ("células vizinhas")*/
		for(int i = 0; i < 8; i++)
		{
			/*Armazena as coordenadas da célula vizinha*/
			int x = p->x + dx[i],
				y = p->y + dy[i];

			/*Se o movimento é válido e o ponto não foi visitado ainda, marca como visitado
			  e enfilera o ponto, com a distância da origem incrementada em 1 e p como a 
			  célula pai*/
			if(valid_pos(x, y) && !visited[x][y])
			{
				visited[x][y] = 1;
				enqueue (q, x, y, (p->dist)+1, p);
			}
		}
	}

	/*Se, no fim, a fila estiver vazia, não tem como chegar ao ponto e retorna NULL*/
	return NULL;
}

/*Imprime as coordenadas do caminho*/
void print_path (Cell *p)
{
	if(p != NULL)
	{
		/*Recursão vai até chegar na célula de origem*/
		print_path(p->parent);

		/*Imprime as coordenadas dos pontos desde a origem até o destino*/
		printf("(%d, %d) ", p->x, p->y);
	}
}

int main ()
{
	int x_src = 0, y_src = 0, x_dest = 7, y_dest = 7;
	//int x_src = 5, y_src = 2, x_dest = 2, y_dest = 4;
	//int x_src = 4, y_src = 0, x_dest = 13, y_dest = 11;

	/*O pior caso para a fila é ter que enfileirar todas as células do tabuleiro,
	  então seu tamanho é SIZE x SIZE*/
	Queue *q = create_queue(SIZE*SIZE);
	Cell *last_cell = bfs_knight(x_src, y_src, x_dest, y_dest, q);

	if(last_cell != NULL)
	{
		printf("Minimum steps: %d\n", last_cell->dist);
		printf("\nPath: ");
		print_path(last_cell);
	}
	else
		printf("Cannot reach finishing point");

	free_queue(q);

	return 0;
}