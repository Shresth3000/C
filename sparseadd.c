#include<stdio.h>
int main(){
    int r,c;
    printf("Enter number of rows: ");
    scanf("%d",&r);
        printf("Enter number of columns: ");
    scanf("%d",&c);
    int sparse1[r][c],cnt1=0;
    printf("Enter sparse matrix 1: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&sparse1[i][j]);
            if(sparse1[i][j]!=0) cnt1++;
        }
    }
     int sparse2[r][c],cnt2=0;
    printf("Enter sparse matrix 2: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&sparse2[i][j]);
            if(sparse2[i][j]!=0) cnt2++;
        }
    }
    int triplet1[cnt1+1][3];
    triplet1[0][0]=r;
    triplet1[0][1]=c;
    triplet1[0][2]=cnt1;
    int k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(sparse1[i][j]!=0) {
                triplet1[k][0]=i;
                triplet1[k][1]=j;
                triplet1[k][2]=sparse1[i][j];
                k++;
            }
        }
    }
       int triplet2[cnt2+1][3];
    triplet2[0][0]=r;
    triplet2[0][1]=c;
    triplet2[0][2]=cnt2;
    int x=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(sparse2[i][j]!=0) {
                triplet2[x][0]=i;
                triplet2[x][1]=j;
                triplet2[x][2]=sparse2[i][j];
                x++;
            }
        }
    }
    int cnt3=0;
    int res[r][c];
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
          res[i][j]=sparse1[i][j]+sparse2[i][j];
          if(res[i][j]!=0){
            cnt3++;
          }  
        }
     }
     int triplet3[cnt3+1][3];
    triplet3[0][0]=r;
    triplet3[0][1]=c;
    triplet3[0][2]=cnt3;
    x=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(res[i][j]!=0) {
                triplet3[x][0]=i;
                triplet3[x][1]=j;
                triplet3[x][2]=res[i][j];
                x++;
            }
        }
    }
    for(int i=0;i<=cnt3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet3[i][j]);
        }printf("\n");
    }
    return 0;
}