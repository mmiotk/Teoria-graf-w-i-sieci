#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i;
  FILE *fp;
  printf("Podaj liczbe elementow: ");
  scanf("%i", &n);

  if((fp=fopen("test.txt", "w"))==NULL){
    printf("BLAD\n");
    exit(1);
  }
  for(i=1; i<=n; i++){
    if(i==1){
      fprintf(fp, "%i %i\n", (2*i-1), (2*i));
      continue;
    }
    fprintf(fp,"%i %i %i\n", (i/2-1), (2*i-1), (2*i));
  }
  fclose (fp);

  return 0;
}
