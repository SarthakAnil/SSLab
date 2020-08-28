#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct memoryBlock
{
    int state ;         /// 0 if unallocated else 1
    char content;
}memoryBlock;


void main(){
    
    int n,pos,nF=0,j=0,sa,len,i,*status;
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
    printf("\nStarting Address\tLength\t\tFile contents\n");
    while (!feof(fin)){
	fscanf(fin, "%d\t%d\t%s", &sa, &len, c);
	printf("\t%d\t\t%d\t\t%s\n", sa, len, c);
	nF++;
    }
    blocks =( memoryBlock*) malloc(n*sizeof(memoryBlock));
    status = (int*) malloc(nF*sizeof(int));
    for ( i = 0; i < n; i++){
	(blocks + i)->state =0;
	(blocks + i)->content =NULL;
    }

    for ( i = 0; i < nF; i++){
	*(status +i) = 0;   //0 is allocated
    }
        
    fseek(fin,pos,SEEK_SET);
    printf("\nRequest's Starting Address\tStatus\n");
    while (!feof(fin)){
	fscanf(fin, "%d\t%d\t%s", &sa, &len, c);
	if((blocks +sa -1)->state == 0 && (sa+len <n)){
	    for (i = 0; i < len; i++){
		if((blocks +sa -1 +i)->state == 1){
                    *(status +j) = 1;
                    break;
                }

            }
	    if(*(status +j) != 1){
		for ( i = 0; i <strlen(c); i++){
		   (blocks +sa -1+i)->state =1;
		   (blocks +sa -1+i)->content = c[i];
                }
                
            }
            
        }
    else
        *(status +j) = 1;
	
    if (*(status +j) == 1)
        printf("\t%d\t\t\tNot allocated\n",sa);
    else
        printf("\t%d\t\t\tAllocated\n",sa);
    j++;
     
    }
   /*
    for ( i = 0; i < n; i++)
    {
	printf("\nstate :%d \ncontent:%c",(blocks +i)->state,(blocks +i)->content);
    }
    
    for ( i = 0; i < nF ; i++)
    {   if(*(status +i) == 1)
        printf("\nNot allocated");
        else
	printf("\nAllocated");
    }
    */
    free(blocks);
    fclose(fin);
}
                                                                        