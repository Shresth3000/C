#include<stdio.h>
int main(){
    int r,c;
    printf("Enter number of rows & columns: ");
    scanf("%d %d",&r,&c); 
    int sparse1[r][c],cnt1=0,sparse2[r][c],cnt2=0;
    printf("Enter sparse matrix 1: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&sparse1[i][j]);
            if(sparse1[i][j]!=0) cnt1++;
        }
    }
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
   
int triplet3[cnt1+cnt2+1][3];
int rt=triplet1[0][2]+triplet2[0][2];
triplet3[0][0]=triplet1[0][0];
triplet3[0][1]=triplet1[0][1];
int i=1,j=1;
k=1;
while(i<=cnt1&&j<=cnt2){
    if(triplet1[i][0]==triplet2[j][0]){
        if(triplet1[i][1]==triplet2[j][1])
        {
            triplet3[k][0]=triplet1[i][0];
            triplet3[k][1]=triplet1[i][1];
            triplet3[k][2]=triplet1[i][2]+triplet2[j][2];
            k++;
            i++;
            j++;
        }
        else if(triplet1[i][1]<triplet2[j][1]){
          triplet3[k][0]=triplet1[i][0];
          triplet3[k][1]=triplet1[i][1];
          triplet3[k][2]=triplet1[i][2];
            k++;
            i++;  
        }
        else{
          triplet3[k][0]=triplet2[j][0];
          triplet3[k][1]=triplet2[j][1];
          triplet3[k][2]=triplet2[j][2];
            k++;
            j++; 
        }
    }
    else if(triplet1[i][0]<triplet2[j][0]){
        triplet3[k][0]=triplet1[i][0];
          triplet3[k][1]=triplet1[i][1];
          triplet3[k][2]=triplet1[i][2];
            k++;
            i++; 
    }
    else{
        triplet3[k][0]=triplet2[j][0];
          triplet3[k][1]=triplet2[j][1];
          triplet3[k][2]=triplet2[j][2];
            k++;
            j++; 
    }

}
while(i<=cnt1)
{
    triplet3[k][0]=triplet1[i][0];
          triplet3[k][1]=triplet1[i][1];
          triplet3[k][2]=triplet1[i][2];
            k++;
            i++; 
}
while(j<=cnt2)
{
    triplet3[k][0]=triplet2[j][0];
          triplet3[k][1]=triplet2[j][1];
          triplet3[k][2]=triplet2[j][2];
            k++;
            j++; 
}
triplet3[0][2]=k-1;
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d ",triplet3[i][j]);
        }printf("\n");
    }
    return 0;
}