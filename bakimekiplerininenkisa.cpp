#include <stdio.h>
#include <conio.h>

#define INF 10000
 
void floyd(int n, long W[][12], long D[][12], long P[][12]);
void path(int q, int r, long P[][12]);
 
int main(void)
{
   //MATRÝS TANIMLAMA
   int i, j;
   long W[12][12] = {{0,26,35,375,INF,512,INF,INF,351,357,322,404},
                   {26,0,13,376,409,INF,INF,INF,362,370,340,424},
                   {35,13,0,388,INF,INF,INF,INF,INF,INF,INF,439},
                   {375,376,388,0,70,150,209,INF,122,135,INF,306},
                   {INF,409,INF,70,0,109,INF,184,78,91,164,250},
				   {512,INF,INF,150,109,0,61,76,177,183,INF,312},
				   {INF,INF,INF,209,INF,61,0,23,INF,240,INF,354},
				   {INF,INF,INF,INF,184,76,23,0,240,245,INF,346},
                   {351,362,INF,122,78,177,INF,240,0,17,88,INF},
                   {357,370,INF,135,91,183,240,245,17,0,75,168},
                   {322,340,INF,INF,164,INF,INF,INF,88,75,0,114},
				   {404,424,439,306,250,312,354,346,INF,168,114,0}};
   long D[12][12];
   long P[12][12];
 //FLOYD ÝÞLETME FONKSÝYON
   floyd(12, W, D, P);
   printf("All of the shortest paths:\n\n");      
   printf("press any key to exit\n");
   getch();
 //MATRÝS HALÝNDE YAZDIRMA 
    for(i=0;i<12;i++)
    {
                        printf("\n");       
                        for(j=0;j<12;j++)
                        {
                        printf("%5d",D[i][j]);
                        }
                        }
    
	 printf("\n");
	for(i=0;i<12;i++)
    {
                        printf("\n");       
                        for(j=0;j<12;j++)
                        {
                        printf("%5d",P[i][j]);
                        }
                        }
                       
   return 0;
}

/****************************************/
//FLOYD ÝÞLETME
void floyd(int n, long W[][12], long D[][12], long P[][12])
{
   int i, j, k;
 
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) 
	  {
         D[i][j] = W[i][j];
         P[i][j] = (i == j) ? 0 : j+1;
      }
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         for (k = 0; k < n; k++)
            if (D[i][j] > D[i][k] + D[k][j])
		    {
               D[i][j] = D[i][k] + D[k][j];
               P[i][j]=k+1;  
            }         
}

