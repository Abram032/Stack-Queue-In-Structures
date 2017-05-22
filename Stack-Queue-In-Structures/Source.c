#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_element
{
	int x;
	struct stack_element *next;
} stack;
typedef stack *stack_el;

typedef struct queue_element
{
	int x;
	struct queue_element *next;
} queue;
typedef queue *queue_el;

typedef struct queue_wsk
{
	queue_el first, last;
} queue_wsk;

typedef struct tw_queue_element
{
	int x;
	struct tw_queue_element *next;
	struct tw_queue_element *prev;
} tw_queue;
typedef tw_queue *tw_queue_el;

typedef struct tw_queue_wsk
{
	tw_queue_el first, last;
} tw_queue_wsk;

int empty_stack(stack_el s_wsk)
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
void push_stack(stack_el *s_wsk)
{
	int x;
	printf("Put x: ");
	scanf(" %d", &x);
	stack_el new_element = malloc(sizeof(stack));
	new_element->x = x;
	new_element->next = *s_wsk;
	*s_wsk = new_element;
}
void pop_stack(stack_el *s_wsk)
{
	if (empty_stack(s_wsk) == 0)
	{
		stack_el current_element = *s_wsk;
		*s_wsk = current_element->next;
		free(current_element);
	}
	else
	{
		printf("Stack is empty!\n");
	}
}
void peek_stack(stack_el *s_wsk)
{
	if (empty_stack(s_wsk) == 0)
	{
		int x;
		stack_el current_element = *s_wsk;
		x = current_element->x;
		printf("x = %d\n", x);
	}
	else
	{
		printf("Stack is empty!\n");
	}
}
void view_stack(stack_el s_wsk)
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
void clear_stack(stack_el *s_wsk)
{
	while (*s_wsk != NULL)
	{
		stack_el current_element = *s_wsk;
		stack_el next_element = current_element->next;
		*s_wsk = next_element;
		free(current_element);
	}
}

int empty_queue(queue_wsk q_wsk)
{
	if (q_wsk.first == NULL)
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
	queue_el new_element = malloc(sizeof(queue));
	new_element->x = x;
	new_element->next = NULL;
	if ((*q_wsk).first == NULL)
	{
		(*q_wsk).first = (*q_wsk).last = new_element;
	}
	else
	{
		(*q_wsk).last->next = new_element;
		(*q_wsk).last = new_element;
	}
}
void pop_queue(queue_wsk *q_wsk)
{
	if (empty_queue(*q_wsk) == 0)
	{
		queue_el current_element = (*q_wsk).first;
		(*q_wsk).first = current_element->next;
		free(current_element);
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
		queue_el current_element = (*q_wsk).first;
		x = current_element->x;
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
		queue_el current_element = (*q_wsk).first;
		while (current_element != NULL)
		{
			i++;
			printf("%d_el = %d\n", i, current_element->x);
			current_element = current_element->next;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void clear_queue(queue_wsk *q_wsk)
{
	if (empty_queue(*q_wsk) == 0)
	{
		while ((*q_wsk).first != NULL)
		{
			queue_el current_element = (*q_wsk).first;
			queue_el next_element = current_element->next;
			(*q_wsk).first = next_element;
			free(current_element);
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}

int empty_tw_queue(tw_queue_wsk tw_q_wsk) 
{
	if (tw_q_wsk.first == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push_tw_queue(tw_queue_wsk *tw_q_wsk)
{
	int x;
	printf("Put x: ");
	scanf(" %d", &x);
	tw_queue_el new_element = malloc(sizeof(tw_queue));
	new_element->x = x;
	new_element->next = NULL;
	new_element->prev = NULL;
	if (empty_tw_queue(*tw_q_wsk) == 1)
	{
		(*tw_q_wsk).first = (*tw_q_wsk).last = new_element;
	}
	else
	{
		tw_queue_el current_element = (*tw_q_wsk).last;
		current_element->next = new_element;
		new_element->prev = current_element;
		(*tw_q_wsk).last = new_element;
	}
}
void push_tw_queue_front(tw_queue_wsk *tw_q_wsk)
{
	int x;
	printf("Put x: ");
	scanf(" %d", &x);
	tw_queue_el new_element = malloc(sizeof(tw_queue));
	new_element->x = x;
	new_element->next = NULL;
	new_element->prev = NULL;
	if (empty_tw_queue(*tw_q_wsk) == 1)
	{
		(*tw_q_wsk).first = (*tw_q_wsk).last = new_element;
	}
	else
	{
		tw_queue_el current_element = (*tw_q_wsk).first;
		current_element->prev = new_element;
		new_element->next = current_element;
		(*tw_q_wsk).first = new_element;
	}
}
void pop_tw_queue(tw_queue_wsk *tw_q_wsk)
{
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		tw_queue_el current_element = (*tw_q_wsk).first;
		tw_queue_el next_element = current_element->next;
		(*tw_q_wsk).first = current_element->next;
		next_element->prev = NULL;
		free(current_element);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void pop_tw_queue_back(tw_queue_wsk *tw_q_wsk)
{
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		tw_queue_el current_element = (*tw_q_wsk).last;
		tw_queue_el prev_element = current_element->prev;
		(*tw_q_wsk).last = current_element->prev;
		prev_element->next = NULL;
		free(current_element);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void peek_tw_queue(tw_queue_wsk *tw_q_wsk)
{
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		int x;
		tw_queue_el current_element = (*tw_q_wsk).first;
		x = current_element->x;
		printf("x = %d\n", x);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void peek_tw_queue_back(tw_queue_wsk *tw_q_wsk)
{
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		int x;
		tw_queue_el current_element = (*tw_q_wsk).last;
		x = current_element->x;
		printf("x = %d\n", x);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void view_tw_queue(tw_queue_wsk *tw_q_wsk)
{
	int i = 0;
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		tw_queue_el current_element = (*tw_q_wsk).first;
		while (current_element != NULL)
		{
			i++;
			printf("%d_el = %d\n", i, current_element->x);
			current_element = current_element->next;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void view_tw_queue_reversed(tw_queue_wsk *tw_q_wsk)
{
	int i = 0;
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		tw_queue_el current_element = (*tw_q_wsk).last;
		while (current_element != NULL)
		{
			i++;
			printf("%d_el = %d\n", i, current_element->x);
			current_element = current_element->prev;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void clear_tw_queue(tw_queue_wsk *tw_q_wsk)
{
	if (empty_tw_queue(*tw_q_wsk) == 0)
	{
		while ((*tw_q_wsk).first != NULL)
		{
			tw_queue_el current_element = (*tw_q_wsk).first;
			tw_queue_el next_element = current_element->next;
			(*tw_q_wsk).first = next_element;
			free(current_element);
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}

void about()
{
	printf("Made by Abram.\n");
	printf("Program version: 1.0\n");
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
	printf("\n");
	printf("11. Add to Two Way Queue (push)\n");
	printf("12. Add to front of Two Way Queue (push)\n");
	printf("13. Remove from Two Way Queue (pop)\n");
	printf("14. Remove from end of Two Way Queue (pop)\n");
	printf("15. Peek at Two Way Queue (peek)\n");
	printf("16. Peek at end of Two Way Queue (peek)\n");
	printf("17. View Two Way Queue\n");
	printf("18. View Two Way Queue Reversed\n");
	printf("19. Clear Two Way Queue\n");
	/*
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
	stack_el s_el = NULL;
	queue_el q_el = NULL;
	queue_wsk q_wsk;
	q_wsk.first = NULL;
	q_wsk.last = NULL;
	tw_queue_el tw_q_el = NULL;
	tw_queue_wsk tw_q_wsk;
	tw_q_wsk.first = NULL;
	tw_q_wsk.last = NULL;
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
			push_stack(&s_el);
			system("pause");
			break;
		case 2:
			pop_stack(&s_el);
			system("pause");
			break;
		case 3:
			peek_stack(&s_el);
			system("pause");
			break;
		case 4:
			view_stack(s_el);
			system("pause");
			break;
		case 5:
			clear_stack(&s_el);
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
			push_tw_queue(&tw_q_wsk);
			system("pause");
			break;
		case 12:
			push_tw_queue_front(&tw_q_wsk);
			system("pause");
			break;
		case 13:
			pop_tw_queue(&tw_q_wsk);
			system("pause");
			break;
		case 14:
			pop_tw_queue_back(&tw_q_wsk);
			system("pause");
			break;
		case 15:
			peek_tw_queue(&tw_q_wsk);
			system("pause");
			break;
		case 16:
			peek_tw_queue_back(&tw_q_wsk);
			system("pause");
			break;
		case 17:
			view_tw_queue(&tw_q_wsk);
			system("pause");
			break;
		case 18:
			view_tw_queue_reversed(&tw_q_wsk);
			system("pause");
			break;
		case 19:
			clear_tw_queue(&tw_q_wsk);
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