#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define max 10
int arow, acol, brow, bcol;


int matrixA[max][max];
int matrixB[max][max];
int matrixC[max][max];

void *readmatrixA(void *arg) {

  FILE *fptr;
  fptr = fopen(arg, "r");

  fscanf(fptr, "%d", &arow);
  fscanf(fptr, "%d", &acol);

  

  for (int i = 0; i < arow; i++) {
    for (int j = 0; j < acol; j++) {

      fscanf(fptr, "%d", &matrixA[i][j]);
      
    }
  }
  pthread_exit(0);

  fclose(fptr);
}
void *readmatrixB(void *arg){
        FILE *fptr;
        fptr = fopen(arg, "r");
    
        fscanf(fptr, "%d", &brow);
        fscanf(fptr, "%d", &bcol);
 
        for(int i=0 ; i<brow; i++){
            for(int j=0; j<bcol; j++){
                fscanf(fptr, "%d", &matrixB[i][j]);
                 
                
            }
        }
        pthread_exit(0);
        fclose(fptr);

    }
void *multi(void *arg) {


  if (acol != brow) {
    printf("Matix Multiplication is not possible \n");
  } else {
    

    for (int i = 0; i < arow; i++) {
      for (int j = 0; j < bcol; j++) {
        long long int sum = 0;
        for (int k = 0; k < acol; k++) {
          sum = sum + matrixA[i][k] * matrixB[k][j];
        }
        matrixC[i][j]=sum;
        
        
      }
     
    }
    
  
  }
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  
  
    
  
  pthread_t thread1,thread2,thread3;
  int status , a;
  if(argc!=4){
    printf("deneme/n");
    exit(0);
  }
  status=pthread_create(&thread1, NULL, readmatrixA, (void *)(argv[1]));
  status=pthread_create(&thread2, NULL, readmatrixB, (void *)(argv[2]));a++;
  status=pthread_create(&thread3, NULL, multi, (void *)(argv[3]));
  
  
  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);
  pthread_join(thread3,NULL);

   FILE *fptr;

    if(argc==4){
      printf("Your file has been created.\n");
      fptr = fopen(argv[3], "w");
      
      
    fprintf(fptr, "%d %d\n", arow, bcol);
    for(int i=0;i<arow;i++){
      for(int j=0;j<bcol;j++){
          fprintf(fptr, "%d ", matrixC[i][j]);
          
        
      }
      fprintf(fptr, "\n");
  
    }
    
    fclose(fptr);
    }

   

return 0;
}