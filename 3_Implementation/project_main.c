// #include <calculator_operations.h>

// /* Status of the operation requested */
// #define VALID   (1)
// #define INVALID (0)

// /* Calculator operation requested by user*/
// unsigned int calculator_operation = 0;

// /* Operands on which calculation is performed */
// int calculator_operand1 = 0;
// int calculator_operand2 = 0;

// /* Valid operations */
// enum operations{ ADD=1, SUBTRACT, MULTIPLY, DIVIDE, EXIT };

// /* Display the menu of operations supported */
// void calculator_menu(void);
// /* Verifies the requested operations validity */
// int valid_operation(int operation);


// /* Start of the application */
// int main(int argc, char *argv[])
// {
//     printf("\n****Calculator****\n");
//     while(1)
//     {
//         calculator_menu();
//     }
// }

// void calculator_menu(void)
// {
//     printf("\nAvailable Operations\n");
//     printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit");
//     printf("\n\tEnter your choice\n");
   
//      __fpurge(stdin);
//     scanf("%d", &calculator_operation);

//     if(EXIT == calculator_operation)
//     {
//         printf("\nThank you. Exiting the Application\n");
//         exit(0);
//     }

//     if(INVALID != valid_operation(calculator_operation))
//     {
//         printf("\n\tEnter your Numbers with space between them\n");
//         __fpurge(stdin);
//         scanf("%d %d", &calculator_operand1, &calculator_operand2);
//     }
//     else
//     {
//         printf("\n\t---Wrong choice---\nEnter to continue\n");
//         __fpurge(stdin);
//         getchar();
//         return;
        
//     }
//     switch(calculator_operation)
//     {
//         case ADD:
//             printf("\n\t%d + %d = %d\nEnter to continue", 
//             calculator_operand1, 
//             calculator_operand2,
//             add(calculator_operand1, calculator_operand2));
            
//             __fpurge(stdin);
//             getchar();
//             break;
//         case SUBTRACT:
//             printf("\n\t%d - %d = %d\nEnter to continue", 
//             calculator_operand1, 
//             calculator_operand2,
//             subtract(calculator_operand1, calculator_operand2));
            
//             __fpurge(stdin);
//             getchar();
//             break;
//         case MULTIPLY:
//             printf("\n\t%d * %d = %d\nEnter to continue", 
//             calculator_operand1, 
//             calculator_operand2,
//             multiply(calculator_operand1, calculator_operand2));
            
//             __fpurge(stdin);
//             getchar();
//             break;
//         case DIVIDE:
//             printf("\n\t%d / %d = %d\nEnter to continue", 
//             calculator_operand1, 
//             calculator_operand2,
//             divide(calculator_operand1, calculator_operand2));
            
//             __fpurge(stdin);
//             getchar();
//             break;
//         case 5:
//             exit(0);
//             break;
//         default:
//             printf("\n\t---It should never come here---\n");
//     }
// }

// int valid_operation(int operation)
// {
//     /* Check if the operation is a valid operation */
//     return ((ADD <= operation) && (EXIT >= operation)) ? VALID: INVALID;
// }

#include<battleships.h>

int dev = 0;

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