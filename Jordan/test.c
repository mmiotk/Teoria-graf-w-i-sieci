#include <stdio.h>
#include <stdlib.h>

int main(){
  int n, i, parent, left, right;
  FILE *fp;
  printf("Podaj liczbe elementow: ");
  scanf("%i", &n);

  if((fp=fopen("test.txt", "w"))==NULL){
    printf("BLAD\n");
    exit(1);
  }

  fprintf(fp,"%i\n", n);

  for(i=1; i<=n; i++){
    parent = i/2-1;
    left = 2*i-1;
    right = 2*i;
    if(i==1){
      fprintf(fp, "%i %i -1\n", left, right);
      continue;
    }
    if(right < n && left < n){
      fprintf(fp,"%i %i %i -1\n", parent, left, right);
      continue;
    }
    if(right >= n && left < n){
      fprintf(fp, "%i %i -1\n", parent, left);
      continue;
    }
    if(left >= n){
      fprintf(fp, "%i -1\n", parent);
      continue;
    }
  }
  fclose (fp);

  return 0;
}
