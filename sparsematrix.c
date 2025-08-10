#include<stdio.h>
int main(){
    int r,c;
    printf("Enter number of rows: ");
    scanf("%d",&r);
        printf("Enter number of columns: ");
    scanf("%d",&c);
    int sparse[r][c],cnt=0;
    printf("Enter sparse matrix: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j]!=0) cnt++;
        }
    }
    int triplet[cnt+1][3];
    triplet[0][0]=r;
    triplet[0][1]=c;
    triplet[0][2]=cnt;
    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(sparse[i][j]!=0) {
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sparse[i][j];
                k++;
            }
        }
    }
     for(int i=0;i<=cnt;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet[i][j]);
        }printf("\n");
    }
    return 0;
}