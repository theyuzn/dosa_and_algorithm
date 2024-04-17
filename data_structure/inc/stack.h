
#define STACK_MAX_SIZE 100

typedef struct Stack {
    int array[STACK_MAX_SIZE];
    int top;
} Stack_t;


Stack_t* createStack() ;
void    push(Stack_t* stack, int data);
int     pop(Stack_t* stack);
