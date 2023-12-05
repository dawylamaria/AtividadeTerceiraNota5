#include <iostream>
using namespace std;
struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;
};

void percorrerPreOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

void encontrarCaminhos(NoArvore* raiz, int caminho[], int nivel) {
    if (raiz == NULL)
        return;

    caminho[nivel] = raiz->data;
    nivel++;

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        cout << "Caminho: ";
        for (int i = 0; i < nivel; i++) {
            cout << caminho[i] << " ";
        }
        cout << endl;
    } else {
        encontrarCaminhos(raiz->esquerda, caminho, nivel);
        encontrarCaminhos(raiz->direita, caminho, nivel);
    }
}

int main() {
    
    NoArvore *raiz = new NoArvore;
    raiz -> data = 1;
    raiz -> esquerda = NULL;
    raiz -> direita = NULL;

    NoArvore* elementoEsquerda = new NoArvore;
    elementoEsquerda -> data = 2;
    elementoEsquerda -> esquerda = NULL;
    elementoEsquerda -> direita = NULL;
    
    raiz -> esquerda = elementoEsquerda;
    
    NoArvore* elementoDireita = new NoArvore;
    elementoDireita->data = 5;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;

    elementoEsquerda -> direita = elementoDireita;
    
    NoArvore* elementoDireita2 = new NoArvore;
    elementoDireita2 -> data = 3;
    elementoDireita2 -> esquerda = NULL;
    elementoDireita2 -> direita = NULL;
    
    raiz -> direita = elementoDireita2;

    cout << "Arvore em pre-ordem: ";
    percorrerPreOrdem(raiz);
    cout << endl;

    int caminho[100]; 
    encontrarCaminhos(raiz, caminho, 0);

    return 0;
}

