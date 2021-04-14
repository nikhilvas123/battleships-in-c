#include<battleships.h>
/* Global dev variable */
int dev = 0;

/* Main function */
int main(int argc, char **argv){
    if(argc == 2){
        if(strcmp("dev",argv[1]) == 0)
            dev = 1;
        else{
            printf("Invalid arguments. Use dev for development, else no arguments\n");
            return 0;
        }
    }
    else if(argc >2){
        printf("Invalid arguments. Use dev for development, else no arguments\n");
        return 0;
    }
    int choice;
    char ch;
    option op;
    print_menu();
    scanf("%d",&choice);
    op = choice;
    while(1){
        switch(op){
            case START:
                play_game();
                printf("Do you want to play again ? (y/n)\n");
                scanf(" %c",&ch);
                while(ch != 'y' && ch != 'n'){
                    printf("Wrong input. Enter y/n\n");
                    scanf(" %c",&ch);
                }
                if(ch == 'y')
                    break;
            case EXIT:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                print_menu();
                scanf(" %d", &choice);
                op = choice;
                break;
        }
    }
    return 0;
}