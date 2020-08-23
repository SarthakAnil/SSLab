#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Function t
void fcfs(int *at, int *bt, int *tat, int *wt, int n){
    int cumulative = 0 ,i;
    for ( i = 0; i < n; i++){
        cumulative += *(bt + i);
        *(tat + i) = cumulative - *(at + i) ;
        *(wt + i) = *(tat + i) - *(bt + i);
        
    }
    
}

void sjf(int *at, int *bt, int *tat, int *wt, int n){
    int cumulative = 0 ,i,min,pid,t=0,c=0;
    while(1){
        min =INT_MAX;
        pid = -1;
        for (i = 0; i < n; i++){
           if(*(at +i) <=t && *(bt + i) < min  && *(at + i) != INT_MIN){
               min =*(bt + i);
               pid = i;
           }
        }
        if(pid == -1){
            min++;
            continue;
        }
        t+=min;
        cumulative = *(bt + pid);
        *(tat + pid) = cumulative - *(at + pid);
        *(wt + pid) = *(tat + pid) - *(bt + pid);
        *(at + pid) = INT_MIN;       //This is done to exclude process which is alredy completed
        c++;
        if (c == n){
            break;
        }

    }
}
    


void printData(int *tat, int *wt, int n){
    int i;
    printf("\nProcess\t\tTurnAround Time\t\tWait Time\n");
    for ( i = 0; i < n; i++){
        printf("P%d\t\t\t%d\t\t%d\n",i,*(tat +i),*(wt + i));        
    }
    

}

void main(){
    int *at,*bt,*p,*tat,*wt; //pointers for Arrival Time(*at) Burst Time(*bt) Priority(*p) Turn Around Time(*tat) Wait Time(*wt)
    int a,b,c,i,n=0;             // Temp variables and loop variables
    FILE *fin;         
    printf("%d",INT_MIN);
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
    if(at == NULL || bt == NULL || tat == NULL || wt == NULL){
        printf("Error! memory not allocated.");
        exit(1);
    }
    
    //Storing data from file to variables

    rewind(fin);
    i=0;        //to reposition the file pointer to start of file
    while (!feof(fin)){
        fscanf(fin, "%d\t%d\t%d", at+i, bt+i, p+i);
        i++;
    }

    // To find Turn around time and wait time of FCFS First Come First Serve

    printf("\n----------------FCFS First Come First Serve---------------\n\n");
    fcfs(at,bt,tat,wt,n);
    printData(tat,wt,n);

    // Reseting tat and wt values
    for (i = 0; i < n; i++){
        *(tat + i) = INT_MIN;
        *(wt + i) = INT_MIN;
    }
    
    // To find Turn around time and wait time of FCFS First Come First Serve

    printf("\n----------------SJF Shortest Job First---------------\n\n");
    sjf(at,bt,tat,wt,n);
    printData(tat,wt,n);
    //Freing up dynamically allocated space

    free(at);
    free(bt);
    free(p);
    free(tat);
    free(wt);
    fclose(fin);

}
