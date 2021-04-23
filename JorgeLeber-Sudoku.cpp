#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
// Usei desse Define, para sempre que eu usar o termo "linha" ele trocar pelo valor 9
#define linha 9
// Mesma coisa de linha, porem com termo "coluna"
#define coluna 9
//Jorge Leber - Programa para resolver SUDOKU utilizando pilha e matriz
void IniciaMatriz(int **mat){
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			mat[i][j] = 0;
		}
	}
}

int **AlocaMatriz (){
	int **matriz = (int**) malloc(linha*sizeof(int**));
	for(int i=0; i<linha; i++){
		matriz[i] = (int*) malloc(coluna*sizeof(int*));
	}
	IniciaMatriz(matriz);
	return matriz;
}

void IniciaVetor(int *vet){
	for(int i=0;i<linha;i++){
		vet[i] = 1;
	}
}

int *AlocaVetor (){
	int *vet = (int*) malloc(linha*sizeof(int*));
	IniciaVetor(vet);
	return vet;
}

void FreeBolado (int **mat){
  for (int i=0; i<linha; i++) 
  	free (mat[i]);
  free (mat);
}

void ExibeMatriz(int **mat){
	printf("Aperte qualquer tecla para continuar...\n");
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			printf("|%d|",mat[i][j]);
		}
		printf("\n");
	}
}

bool verificaLinha(int **m, int linhaAtual){
	int elemento, linAux = 0;
	for(int colAux =0; colAux<coluna; colAux++){
		for(int i=0; i<coluna; i++){
			elemento = m[linhaAtual][colAux];
			if(elemento != 0 && m[linhaAtual][i] != 0){
				if(colAux != i){
					if(elemento == m[linhaAtual][i])
						return false;
				}
			}
		}
	}
	return true;
}

bool verificaColuna(int **m, int colunaAtual){
	int elemento, colAux = 0, linAux = 0;
	for(int linAux =0; linAux<linha; linAux++){
		for(int i=0; i<linha; i++){
			elemento = m[linAux][colunaAtual];
			if(elemento != 0 && m[i][colunaAtual] != 0){
				if(linAux != i){
					if(elemento == m[i][colunaAtual])
						return false;
				}
			}
		}
	}	
	return true;
}

bool verificaSub(int **m, int linhaAtual, int colunaAtual){
	int elemento;
	if(linhaAtual>=0 && linhaAtual<3){
		if(colunaAtual >=0 && colunaAtual <3){ //spot 7
			for(int linhaAux = 0; linhaAux<3; linhaAux++){
				for(int colunaAux = 0; colunaAux<3; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=0;i<3;i++){
							for(int j=0;j<3;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
		else if(colunaAtual >=3 && colunaAtual <6){ //spot 8
			for(int linhaAux = 0; linhaAux<3; linhaAux++){
				for(int colunaAux = 3; colunaAux<6; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=0;i<3;i++){
							for(int j=3;j<6;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}	
		}
		else{ //spot 9
			for(int linhaAux = 0; linhaAux<3; linhaAux++){
				for(int colunaAux = 6; colunaAux<9; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=0;i<3;i++){
							for(int j=6;j<9;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
	}
	else if(linhaAtual>=3 && linhaAtual<6){ 
		if(colunaAtual >=0 && colunaAtual <3){ //spot 4
			for(int linhaAux = 3; linhaAux<6; linhaAux++){
				for(int colunaAux = 0; colunaAux<3; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=3;i<6;i++){
							for(int j=0;j<3;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
		else if(colunaAtual >=3 && colunaAtual <6){ //spot 5
			for(int linhaAux = 3; linhaAux<6; linhaAux++){
				for(int colunaAux = 3; colunaAux<6; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=3;i<6;i++){
							for(int j=3;j<6;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
		else{ //spot 6
			for(int linhaAux = 3; linhaAux<6; linhaAux++){
				for(int colunaAux = 6; colunaAux<9; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=3;i<6;i++){
							for(int j=6;j<9;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
	}
	else{
		if(colunaAtual >=0 && colunaAtual <3){ //spot 1
			for(int linhaAux = 6; linhaAux<9; linhaAux++){
				for(int colunaAux = 0; colunaAux<3; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=6;i<9;i++){
							for(int j=0;j<3;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
		else if(colunaAtual >=3 && colunaAtual <6){ //spot 2
			for(int linhaAux = 6; linhaAux<9; linhaAux++){
				for(int colunaAux = 3; colunaAux<6; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=6;i<9;i++){
							for(int j=3;j<6;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
		else{ //spot 3
			for(int linhaAux = 6; linhaAux<9; linhaAux++){
				for(int colunaAux = 6; colunaAux<9; colunaAux++){
					elemento = m[linhaAux][colunaAux];
					if(elemento != 0){
						for(int i=6;i<9;i++){
							for(int j=6;j<9;j++){
								if(i != linhaAux || j != colunaAux){
									if(elemento == m[i][j])
										return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

bool isValido(int **m){
	for(int linhaAtual =0;linhaAtual<9;linhaAtual++)
	{
		for(int colunaAtual = 0;colunaAtual <9;colunaAtual++){
			if(!verificaLinha(m,linhaAtual)){
				//printf("erro linha\n");
				return false;
			}
			if(!verificaColuna(m,colunaAtual)){
				//printf("erro coluna\n");
				return false;
			}
			if(!verificaSub(m,linhaAtual,colunaAtual)){
				//printf("erro sub\n");
				return false;
			}
		}
	}
	return true;
}

void PercorrerMatriz(int **m, int *vet){
	int contador = 1;
	int aux;
	for(int linhaAtual =0;linhaAtual<9;linhaAtual++)
	{
		for(int colunaAtual = 0;colunaAtual <9;colunaAtual++){
			if(true){
				aux = m[linhaAtual][colunaAtual];
				contador = aux;
				for(; contador<=10 ; contador++){
					if(aux != contador){
						m[linhaAtual][colunaAtual] = contador;
						getch();
						system("cls");
						ExibeMatriz(m);
						if(isValido(m)){
							contador = 10;
						}
					}
				}
			}
			if(m[linhaAtual][colunaAtual] == 10){
				m[linhaAtual][colunaAtual] = 0;
				if(colunaAtual-1 >= 0){
					colunaAtual-=2;
				}
				else{
					colunaAtual = 8;
					linhaAtual--;
				}
			}
		}
	}
}

int main(){
	int **mat = AlocaMatriz();
	int *vet = AlocaVetor();
	ExibeMatriz(mat);
	PercorrerMatriz(mat,vet);
	printf("###\n");
	ExibeMatriz(mat);
	FreeBolado(mat);
}
