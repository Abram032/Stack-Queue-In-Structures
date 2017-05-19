#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_element
{
	int x;
	struct stack_element *next;
} stack;
typedef stack *stack_top;

typedef struct queue_element
{
	int x;
	struct queue_element *next;
} queue;
typedef queue *queue_top;

typedef struct queue_wsk
{
	queue_top f, l;
} queue_wsk;

int empty_stack(stack_top s_wsk)
{
	if (s_wsk == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push_stack(stack_top *s_wsk)
{
	int x;
	printf("Put x: ");
	scanf(" %d", &x);
	stack_top new_struct = malloc(sizeof(stack));
	new_struct->x = x;
	new_struct->next = *s_wsk;
	*s_wsk = new_struct;
}
void pop_stack(stack_top *s_wsk)
{
	if (empty_stack(s_wsk) == 0)
	{
		stack_top curr_struct = *s_wsk;
		*s_wsk = curr_struct->next;
		free(curr_struct);
	}
	else
	{
		printf("Stack is empty!\n");
	}
}
void peek_stack(stack_top *s_wsk)
{
	if (empty_stack(s_wsk) == 0)
	{
		int x;
		stack_top curr_struct = *s_wsk;
		x = curr_struct->x;
		printf("x = %d\n", x);
	}
	else
	{
		printf("Stack is empty!\n");
	}
}
void view_stack(stack_top s_wsk)
{
	int i = 0;
	if (empty_stack(s_wsk) == 0)
	{
		while (s_wsk != NULL)
		{
			i++;
			printf("%d = %d\n", i, s_wsk->x);
			s_wsk = s_wsk->next;
		}
	}
	else
	{
		printf("Stack is empty!\n");
	}
}
void clear_stack(stack_top *s_wsk)
{
	while (s_wsk != NULL)
	{
		stack_top curr_struct = *s_wsk;
		*s_wsk = curr_struct->next;
		free(curr_struct);
	}
}

int empty_queue(queue_wsk q_wsk)
{
	if (q_wsk.f == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push_queue(queue_wsk *q_wsk)
{
	int x;
	printf("Put x: ");
	scanf(" %d", &x);
	if (empty_queue(*q_wsk) == 1)
	{
		queue_top new_struct = malloc(sizeof(queue));
		new_struct->x = x;
		new_struct->next = NULL;
		if ((*q_wsk).f == NULL)
		{
			(*q_wsk).f = (*q_wsk).l = new_struct;
			//new_struct->next = (*q_wsk).f = (*q_wsk).l;
		}
		else
		{
			//new_struct->next = (*q_wsk).l;
			//(*q_wsk).l = new_struct;
			(*q_wsk).l->next = new_struct;
			(*q_wsk).l = new_struct;
		}
	}
}
void pop_queue(queue_wsk *q_wsk)
{
	if (empty_queue(*q_wsk) == 0)
	{
		queue_top current_struct = (*q_wsk).f;
		(*q_wsk).f = current_struct->next;
		free(current_struct);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void peek_queue(queue_wsk *q_wsk)
{
	if (empty_queue(*q_wsk) == 0)
	{
		int x;
		queue_top current_struct = (*q_wsk).f;
		x = current_struct->x;
		printf("x = %d\n", x);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void view_queue(queue_wsk *q_wsk)
{
	int i = 0;
	if (empty_queue(*q_wsk) == 0)
	{
		queue_top current_struct = (*q_wsk).f;
		while (current_struct != NULL)
		{
			i++;
			printf("%d = %d\n", i, current_struct->x);
			current_struct = current_struct->next;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void clear_queue(queue_wsk *q_wsk)
{

}


void about()
{
	printf("Made by Maissae.\n");
	printf("Program version: 1.1\n");
	printf("You're a stuff! o3o\n");
}
void menu_options()
{
	printf("1. Add to Stack (push)\n");
	printf("2. Remove from Stack (pop)\n");
	printf("3. Peek at Stack (peek)\n");
	printf("4. View Stack\n");
	printf("5. Clear Stack\n");
	printf("\n");
	printf("6. Add to Queue (push)\n");
	printf("7. Remove from Queue (pop)\n");
	printf("8. Peek at Queue (peek)\n");
	printf("9. View Queue\n");
	printf("10. Clear Queue\n");
	/*printf("\n");
	printf("14. Add to Cyclic queue (push)\n");
	printf("15. Remove from Cyclic queue (pop)\n");
	printf("16. Peek at Cyclic queue (peek)\n");
	printf("17. View Cyclic queue\n");
	printf("18. Clear Cyclic queue\n");
	printf("\n");
	printf("19. Add to Priority queue (push)\n");
	printf("20. Remove from Priority queue (pop)\n");
	printf("21. Peek at Priority queue (peek)\n");
	printf("22. Adjust Priority (adjust)\n");
	printf("23. View Priority queue\n");
	printf("24. Clear Priority queue\n");
	printf("\n");*/
	printf("25. About\n");
	printf("26. Exit\n");
}

int main()
{
	stack_top s_wsk = NULL;
	queue_top q_wsk = NULL;
	queue_wsk q_regular;
	q_regular.f = NULL;
	q_regular.l = NULL;
	int menu;
	int loop = 1;
	do
	{
		system("cls");
		menu_options();
		printf("\nChoose option: ");
		scanf(" %d", &menu);
		switch (menu)
		{
		case 1:
			push_stack(&s_wsk);
			system("pause");
			break;
		case 2:
			pop_stack(&s_wsk);
			system("pause");
			break;
		case 3:
			peek_stack(&s_wsk);
			system("pause");
			break;
		case 4:
			view_stack(s_wsk);
			system("pause");
			break;
		case 5:
			clear_stack(&s_wsk);
			system("pause");
			break;
		case 6:
			push_queue(&q_wsk);
			system("pause");
			break;
		case 7:
			pop_queue(&q_wsk);
			system("pause");
			break;
		case 8:
			peek_queue(&q_wsk);
			system("pause");
			break;
		case 9:
			view_queue(&q_wsk);
			system("pause");
			break;
		case 10:
			clear_queue(&q_wsk);
			system("pause");
			break;
		case 11:
			system("pause");
			break;
		case 12:
			system("pause");
			break;
		case 13:
			system("pause");
			break;
		case 14:
			system("pause");
			break;
		case 15:
			system("pause");
			break;
		case 16:
			system("pause");
			break;
		case 17:
			system("pause");
			break;
		case 18:
			system("pause");
			break;
		case 19:
			system("pause");
			break;
		case 20:
			system("pause");
			break;
		case 21:
			system("pause");
			break;
		case 22:
			system("pause");
			break;
		case 23:
			system("pause");
			break;
		case 24:
			system("pause");
			break;
		case 25:
			about();
			system("pause");
			break;
		case 26:
			loop = 0;
			break;
		default:
			printf("Unknown option.\n");
			system("pause");
			break;
		}
	} while (loop == 1);
	system("pause");
	return 0;
}