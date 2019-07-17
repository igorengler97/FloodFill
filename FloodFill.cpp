#include <iostream>
#include <fstream>
#include <malloc.h>

#define L 10
#define C 10

/*
*   Flood fill for bidimensional arrays
*   Author: https://github.com/igorengler97
*/


using namespace std;

typedef struct queu{ //queue
    int element;
    struct queu *next;
}Queu;

Queu *new_queu(){
    return NULL;
}

bool queu_empty(Queu *f){
    return (f==NULL);
}

Queu *push(Queu *f, int element)
{
    Queu *temp = f;
    Queu *neww = (Queu*)malloc(sizeof(Queu));
    neww->element = element;
    neww->next = NULL;
    if(queu_empty(f)){
        return neww;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = neww;
    return f;
}

Queu* pop(Queu* f)
{
 	if(queu_empty(f)){
       return NULL;
 	}
	Queu *temp = f->next;
	free(f);
	return temp;
}

bool verify_start(int pos1, int pos2){
    return (pos1 >= 0 && pos1 < L && pos2 >= 0 && pos2 < C);
}

bool verify_position(char matrix[L][C], int pos1, int pos2, char firstPos)
{
    return (pos1 >= 0 && pos1 < L && pos2 >= 0 && pos2 < C) && matrix[pos1][pos2] == firstPos;
}

void paint(char matrix[L][C], int pos1, int pos2, char cor,Queu *f){
    int row[] = {-1,0,0,1};
    int column[] = {0,-1,1,0};

    f = push(f, pos1);
    f = push(f, pos2);

    char firstPos = matrix[pos1][pos2];

    while(queu_empty(f)==false){
        pos1 = f->element;
        f = pop(f);
        pos2 = f->element;
        f = pop(f);
        matrix[pos1][pos2] = cor;

        for(int x = 0;x < 4; x++){
            if(verify_position(matrix, pos1+row[x], pos2+column[x], firstPos)){
                f = push(f, pos1 + row[x]);
                f = push(f, pos2 + column[x]);
            }
        }
    }
}

void print_matrix(char matrix[L][C]){
    cout<<endl;
    for (int i = 0; i < L; i++){
        for (int j = 0;j < C; j++){
            cout << matrix[i][j] <<" ";
        }
        cout <<endl;
    }
}

int main(){
    ifstream fileMatrix;
    Queu *f = new_queu();
    int pos1, pos2;
    char cor;
    int i, j;
    char matrix[L][C];

    fileMatrix.open("matrix.txt");
    if(fileMatrix == NULL){
        cout << "erro ao abrir o arquivo!" << endl;
        return 0;
    }
    //fileMatrix >> l >> c;

    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){
            fileMatrix >> matrix[i][j];
        }
    }

    print_matrix(matrix);

    cout << endl << "Type the coordinates you want to paint (Row and Column): ";
    cin >> pos1 >> pos2;
    if((verify_start(pos1, pos2))){
        cout << endl << "What color you want to paint with (char): ";
        cin >> cor;
        paint(matrix, pos1, pos2, cor, f);
        print_matrix(matrix);
    }
    else{
        cout << endl << "Invalid Position!" << endl;
        return 0;
    }
    return 0;
}
