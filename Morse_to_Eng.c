#include<stdio.h>
#include<string.h>
#include<ncurses.h>

void func1();
char translator(char temp[]);
char sagan(int i);
void intro();

void main(){
    char i='n';

    initscr();
    raw();
    intro();
    while(i!='y'&&i!='Y'){
        func1();
        printw("END? Y/N: ");
        i = getch();
        getch();
        refresh();
        printf("\n");
    }
    endwin();
}

void func1(){
    char morse[300],temp[6];
    int i,j;

    getstr(morse);
    //fgets(morse, 300,stdin);
    morse[strcspn(morse,"\n")]='\0';
    for(i=0;i<strlen(morse)&&morse[i]!=0;i++){
        if(morse[i]!=46&&morse[i]!=45&&morse[i]!=32&&morse[i]!='/'){
            printf("ERROR DIFFERENT CHARACTER\n");
            return;
        }
    }
    
    i=0;
    while(i<strlen(morse)&&morse[i]!=0){
        
        if(morse[i]==32){
            i++;
            continue;
        }
        if(morse[i]=='/'){
            printw(" ");
            i++;
            continue;
        }
        j=0;
        while(j<5&&morse[i+j]!=32&&morse[i+j]!=0){
            temp[j]=morse[i+j];
            j++;
        }

        if(morse[i+j]==32||morse[i+j]==0){
            j--;
        }
        temp[j+1]='\0';

        
        printw("%c",translator(temp));

        i+=j+2;
    }
    printw("\n");
    

}

char translator(char temp[]){
    int i,k=0,head;
    char a;

    for(i=0;i<strlen(temp);i++){
        if(temp[i]=='-') k=k*2+1;
        else k=k*2+2;
    }

    return sagan(k);
}

char sagan(int i){
    char a[64];
    int j;

    FILE *f = fopen("Morses.data", "r");
    fgets(a, 64, f);
    fclose(f);
    return a[i];
}

void intro(){
    printw("Welcome to this (not good) Morse Code translator\n");
    printw("This Program accepts only dots (DIT) and dashes (DAH)\n");
    printw("You can also do space by writing the character / \n");
    return;
}
