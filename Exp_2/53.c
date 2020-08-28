#include<stdio.h>
#include<stdlib.h>


typedef struct memoryBlock
{
    int state ;         /// 0 if unallocated else 1
    char content;
}memoryBlock;


void main(){
    
    int n,pos,a,b,i;
    char c[30];
    FILE *fin;         
    memoryBlock *blocks;
    //checking if the file exixts if so it will open to input file buffer fin else the program will exit displayin ann error message
    
    if ((fin = fopen("input.txt", "r")) == NULL) {
        fprintf(stderr,"Error! opening file");
        exit(1);
    } 

    //Printing contents of input file

    printf("\nCONTENTS OF INPUT FILE \"input.txt\"\n");
    fscanf(fin,"%d",&n);
    pos=ftell(fin);
    printf("Number of blocks:%d",n);
    printf("\nStarting Address\tLength\tFile contents\n");  
    while (!feof(fin)){
        fscanf(fin, "%d\t%d\t%s", &a, &b, c);
        printf("%d\t\t%d\t\t%s\n", a, b, c);
    }
    blocks =( memoryBlock*) malloc(n*sizeof(memoryBlock));
    fseek(fin,0,pos);
    free(blocks);
    fclose(fin);
}
                                                                        