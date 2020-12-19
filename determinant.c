#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Tmax 100

int det(int A[Tmax][Tmax], int dim);

int main()
{
    int A[Tmax][Tmax];
    int i,j,k,dim,resultat;
    do{
        printf("Entrer la dimention du matrice:\n");
        scanf("%d", &dim);
    } while (dim<0 || dim>Tmax);
    printf("\nVeuillez entrer les elements du matrice un par un: \n");
    for(i = 0 ; i < dim ; i++)
    {
        for(j = 0 ; j < dim ; j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i = 0 ; i < dim ; i++){
        for(j = 0 ; j < dim ; j++){
            printf("%5d",A[i][j]);
        }
        printf("\n");
    }
    resultat = det(A,dim);
    printf("Le determinant est : %d",resultat);
}



int det(int A[Tmax][Tmax], int dim)
{
    int tabbar[100][100];
    int i,j,k,a1,a2;
    int determinant=0;
    int un=1;

    if(dim == 2){
        determinant = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        return determinant;
    }
    else
    {
        for(i = 0 ; i < dim ; i++){
            a1 = 0;
            a2 = 0;
            for(j = 0 ; j < dim ; j++){
                for(k = 0 ; k < dim ; k++){
                    if(j != 0 && k != i){
                        tabbar[a1][a2] = A[j][k];
                        a2++;
                        if(a2 > dim-2){
                            a2=0;
                            a1++;
                        }
                    }
                }
            }
            determinant = determinant + un *(A[0][i]*det(tabbar,dim-1));
            un = un * -1;
        }
    }
    return determinant;
}
