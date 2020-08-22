#include<stdio.h>
#include<stdlib.h>

void main(){
    int *at,*bt,*p,*tat,*wt; //pointers for Arrival Time(*at) Burst Time(*bt) Priority(*p) Turn Around Time(*tat) Wait Time(*wt)
    int a,b,c,i,n=0;             // Temp variables and loop variables
    FILE *fin;               
    
    //checking if the file exixts if so it will open to input file buffer fin else the program will exit displayin ann error message
    if ((fin = fopen("TCR18CS053_exp1_input.txt", "r")) == NULL) {
        fprintf(stderr,"Error! opening file");
        exit(1);
    } 
    printf("CONTENTS OF INPUT FILE \"TCR18CS053_exp1_input.txt\"\n");
    printf("Arrival Time\tBurst Time\tPriority\n");  
    while (!feof(fin)){
       fscanf(fin,"%d\t%d\t%d", &a, &b, &c);
       printf("%d\t\t%d\t\t%d\n", a, b, c);
       n++;
    }
    
    //Dynamic allocation of memory depending up on number of process in file
    
    at = (int*) malloc(n * sizeof(int));
    bt = (int*) malloc(n * sizeof(int));
    p = (int*) malloc(n * sizeof(int));
    tat = (int*) malloc(n * sizeof(int));
    wt = (int*) malloc(n * sizeof(int));
    
    // To find Turn around time and wait time of FCFS First Come First Serve

    printf("");



    free(at);
    free(bt);
    free(p);
    free(tat);
    free(wt);
    fclose(fin);

}
