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

    //Printing contents of input file

    printf("\nCONTENTS OF INPUT FILE \"TCR18CS053_exp1_input.txt\"\n");
    printf("\nArrival Time\tBurst Time\tPriority\n");  
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
    
    //Storing data from file to variables

    rewind(fin);
    i=0;        //to reposition the file pointer to start of file
    while (!feof(fin)){
        fscanf(fin, "%d\t%d\t%d", at+i, bt+i, p+i);
        i++;
    }

    // To find Turn around time and wait time of FCFS First Come First Serve

    printf("\n----------------FCFS First Come First Serve---------------\n\n");


    //Freing up dynamically allocated space

    free(at);
    free(bt);
    free(p);
    free(tat);
    free(wt);
    fclose(fin);

}
