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

typedef struct priority_queue_element
{
	int x;
	int p;
	struct priority_queue_element *next;
	struct priority_queue_element *prev;
} priority_queue;
typedef priority_queue *priority_queue_el;

typedef struct priority_queue_wsk
{
	priority_queue_el first, last;
} priority_queue_wsk;

typedef struct ow_priority_queue_element
{
	int x;
	int p;
	struct ow_priority_queue_element *next;
} ow_priority_queue;
typedef ow_priority_queue *ow_priority_queue_el;

typedef struct ow_priority_queue_wsk
{
	ow_priority_queue_el first, last;
} ow_priority_queue_wsk;

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

int empty_priority_queue(priority_queue_wsk prior_q_wsk)
{
	if (prior_q_wsk.first == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push_priority_queue(priority_queue_wsk *prior_q_wsk, int x, int p)
{
	priority_queue_el new_element = malloc(sizeof(priority_queue));
	new_element->x = x;
	new_element->p = p;
	new_element->next = NULL;
	new_element->prev = NULL;
	if (empty_priority_queue(*prior_q_wsk) == 1)
	{
		(*prior_q_wsk).first = (*prior_q_wsk).last = new_element;
	}
	else
	{
		if (p >= (*prior_q_wsk).first->p)
		{
			priority_queue_el current_element = (*prior_q_wsk).first;
			new_element->next = current_element;
			current_element->prev = new_element;
			(*prior_q_wsk).first = new_element;
		}
		else if (p <= (*prior_q_wsk).last->p)
		{
			priority_queue_el current_element = (*prior_q_wsk).last;
			new_element->prev = current_element;
			current_element->next = new_element;
			(*prior_q_wsk).last = new_element;
		}
		else
		{
			priority_queue_el current_element = (*prior_q_wsk).first;
			priority_queue_el next_element = current_element->next;
			while (p <= next_element->p)
			{
				current_element = next_element;
				next_element = current_element->next;
			}
			new_element->prev = current_element;
			new_element->next = next_element;
			current_element->next = new_element;
			next_element->prev = new_element;
		}
	}
}
void pop_priority_queue(priority_queue_wsk *prior_q_wsk)
{
	if (empty_priority_queue(*prior_q_wsk) == 0)
	{
		priority_queue_el current_element = (*prior_q_wsk).first;
		if (current_element->next == NULL)
		{
			(*prior_q_wsk).first = NULL;
			(*prior_q_wsk).last = NULL;
			free(current_element);
		}
		else
		{
			priority_queue_el next_element = current_element->next;
			(*prior_q_wsk).first = current_element->next;
			next_element->prev = NULL;
			free(current_element);
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void peek_priority_queue(priority_queue_wsk *prior_q_wsk)
{
	if (empty_priority_queue(*prior_q_wsk) == 0)
	{
		int x, p;
		priority_queue_el current_element = (*prior_q_wsk).first;
		x = current_element->x;
		p = current_element->p;
		printf("x = %d\n", x);
		printf("priority = %d\n", p);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void view_priority_queue(priority_queue_wsk *prior_q_wsk)
{
	int i = 0;
	if (empty_priority_queue(*prior_q_wsk) == 0)
	{
		priority_queue_el current_element = (*prior_q_wsk).first;
		while (current_element != NULL)
		{
			i++;
			printf("%d_el = %d\n", i, current_element->x);
			printf("%d_el priority = %d\n\n", i, current_element->p);
			current_element = current_element->next;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void adjust_priortiy_queue(priority_queue_wsk *prior_q_wsk)
{
	int n, x, p, c=0;
	if (empty_priority_queue(*prior_q_wsk) == 1)
	{
		view_priority_queue(&(*prior_q_wsk));
	}
	else
	{
		view_priority_queue(&(*prior_q_wsk));
		priority_queue_el current_element = (*prior_q_wsk).first;
		priority_queue_el next_element;
		priority_queue_el previous_element;
		while (current_element != NULL)
		{
			c++;
			current_element = current_element->next;
		}
		current_element = (*prior_q_wsk).first;
		printf("\nWhich element would you like to adjust: ");
		scanf(" %d", &n);
		while (n > c || n < 1)
		{
			printf("\nYou can't adjust element that doesn't exist.");
			printf("\nWhich element would you like to adjust: ");
			scanf(" %d", &n);
		}
		printf("\nSet new Priority: ");
		scanf(" %d", &p);
		for (int i = 1; i < n; i++)
		{
			current_element = current_element->next;
			next_element = current_element->next;
		}
		x = current_element->x;
		next_element = current_element->next;
		previous_element = current_element->prev;
		if (next_element == NULL && previous_element == NULL)
		{
			pop_priority_queue(&(*prior_q_wsk));
		}
		else if (next_element == NULL)
		{
			previous_element->next = NULL;
			(*prior_q_wsk).last = previous_element;
			free(current_element);
		}
		else if (previous_element == NULL)
		{
			next_element->prev = NULL;
			(*prior_q_wsk).first = next_element;
			free(current_element);
		}
		else
		{
			next_element->prev = previous_element;
			previous_element->next = next_element;
			free(current_element);
		}
		push_priority_queue(&(*prior_q_wsk), x, p);
	}
}
void clear_priority_queue(priority_queue_wsk *prior_q_wsk)
{
	if (empty_priority_queue(*prior_q_wsk) == 0)
	{
		while ((*prior_q_wsk).first != NULL)
		{
			priority_queue_el current_element = (*prior_q_wsk).first;
			priority_queue_el next_element = current_element->next;
			(*prior_q_wsk).first = next_element;
			free(current_element);
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}

int empty_ow_priority_queue(ow_priority_queue_wsk ow_prior_q_wsk)
{
	if (ow_prior_q_wsk.first == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push_ow_priority_queue(ow_priority_queue_wsk *ow_prior_q_wsk, int x, int p)
{
	ow_priority_queue_el new_element = malloc(sizeof(ow_priority_queue));
	new_element->x = x;
	new_element->p = p;
	new_element->next = NULL;
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 1)
	{
		(*ow_prior_q_wsk).first = (*ow_prior_q_wsk).last = new_element;
	}
	else
	{
		if (p >= (*ow_prior_q_wsk).first->p)
		{
			ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
			new_element->next = current_element;
			(*ow_prior_q_wsk).first = new_element;
		}
		else if (p <= (*ow_prior_q_wsk).last->p)
		{
			ow_priority_queue_el current_element = (*ow_prior_q_wsk).last;
			current_element->next = new_element;
			(*ow_prior_q_wsk).last = new_element;
		}
		else
		{
			ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
			ow_priority_queue_el next_element = current_element->next;
			while (p <= next_element->p)
			{
				current_element = next_element;
				next_element = current_element->next;
			}
			new_element->next = next_element;
			current_element->next = new_element;
		}
	}
}
void pop_ow_priority_queue(ow_priority_queue_wsk *ow_prior_q_wsk)
{
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 0)
	{
		ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
		if (current_element->next == NULL)
		{
			(*ow_prior_q_wsk).first = NULL;
			(*ow_prior_q_wsk).last = NULL;
			free(current_element);
		}
		else
		{
			ow_priority_queue_el next_element = current_element->next;
			(*ow_prior_q_wsk).first = current_element->next;
			free(current_element);
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void peek_ow_priority_queue(ow_priority_queue_wsk *ow_prior_q_wsk)
{
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 0)
	{
		int x, p;
		ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
		x = current_element->x;
		p = current_element->p;
		printf("x = %d\n", x);
		printf("priority = %d\n", p);
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void view_ow_priority_queue(ow_priority_queue_wsk *ow_prior_q_wsk)
{
	int i = 0;
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 0)
	{
		ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
		while (current_element != NULL)
		{
			i++;
			printf("%d_el = %d\n", i, current_element->x);
			printf("%d_el priority = %d\n\n", i, current_element->p);
			current_element = current_element->next;
		}
	}
	else
	{
		printf("Queue is empty!\n");
	}
}
void adjust_ow_priortiy_queue(ow_priority_queue_wsk *ow_prior_q_wsk)
{
	int n, x, p, c=0;
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 1)
	{
		view_ow_priority_queue(&(*ow_prior_q_wsk));
	}
	else
	{
		view_ow_priority_queue(&(*ow_prior_q_wsk));
		ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
		ow_priority_queue_el next_element;
		ow_priority_queue_el previous_element = (*ow_prior_q_wsk).first;
		while (current_element != NULL)
		{
			c++;
			current_element = current_element->next;
		}
		current_element = (*ow_prior_q_wsk).first;
		printf("\nWhich element would you like to adjust: ");
		scanf(" %d", &n);
		while (n > c || n < 1)
		{
			printf("\nYou can't adjust element that doesn't exist.");
			printf("\nWhich element would you like to adjust: ");
			scanf(" %d", &n);
		}
		printf("\nSet new Priority: ");
		scanf(" %d", &p);
		for (int i = 1; i < n; i++)
		{
			previous_element = current_element;
			current_element = current_element->next;
			next_element = current_element->next;
		}
		x = current_element->x;
		next_element = current_element->next;
		if ((*ow_prior_q_wsk).first == (*ow_prior_q_wsk).last)
		{
			pop_ow_priority_queue(&(*ow_prior_q_wsk));
		}
		else if (next_element == NULL)
		{
			previous_element->next = NULL;
			(*ow_prior_q_wsk).last = previous_element;
			free(current_element);
		}
		else if ((*ow_prior_q_wsk).first == current_element)
		{
			pop_ow_priority_queue(&(*ow_prior_q_wsk));
		}
		else
		{
			previous_element->next = next_element;
			free(current_element);
		}
		push_ow_priority_queue(&(*ow_prior_q_wsk), x, p);
	}
}
void clear_ow_priority_queue(ow_priority_queue_wsk *ow_prior_q_wsk)
{
	if (empty_ow_priority_queue(*ow_prior_q_wsk) == 0)
	{
		while ((*ow_prior_q_wsk).first != NULL)
		{
			ow_priority_queue_el current_element = (*ow_prior_q_wsk).first;
			ow_priority_queue_el next_element = current_element->next;
			(*ow_prior_q_wsk).first = next_element;
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
	printf("Program version: 1.32\n");
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
	printf("\n");
	printf("20. Add to Priority queue (push)\n");
	printf("21. Remove from Priority queue (pop)\n");
	printf("22. Peek at Priority queue (peek)\n");
	printf("23. Adjust Priority queue (peek)\n");
	printf("24. View Priority queue\n");
	printf("25. Clear Priority queue\n");
	printf("\n");
	printf("26. Add to one way Priority queue (push)\n");
	printf("27. Remove from one way Priority queue (pop)\n");
	printf("28. Peek at one way Priority queue (peek)\n");
	printf("29. Adjust one way Priority (adjust)\n");
	printf("30. View one way Priority queue\n");
	printf("31. Clear one way Priority queue\n");
	printf("\n");
	printf("32. About\n");
	printf("33. Exit\n");
	printf("\n");
}

int main()
{
	int x, p;

	stack_el s_el = NULL;
	queue_el q_el = NULL;

	queue_wsk q_wsk;
	q_wsk.first = NULL;
	q_wsk.last = NULL;

	tw_queue_el tw_q_el = NULL;
	tw_queue_wsk tw_q_wsk;
	tw_q_wsk.first = NULL;
	tw_q_wsk.last = NULL;

	priority_queue_el prior_q_el = NULL;
	priority_queue_wsk prior_q_wsk;
	prior_q_wsk.first = NULL;
	prior_q_wsk.last = NULL;

	ow_priority_queue_el ow_prior_q_el = NULL;
	ow_priority_queue_wsk ow_prior_q_wsk;
	ow_prior_q_wsk.first = NULL;
	ow_prior_q_wsk.last = NULL;

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
			printf("Put x: ");
			scanf(" %d", &x);
			printf("Set priority: ");
			scanf(" %d", &p);
			push_priority_queue(&prior_q_wsk, x, p);
			system("pause");
			break;
		case 21:
			pop_priority_queue(&prior_q_wsk);
			system("pause");
			break;
		case 22:
			peek_priority_queue(&prior_q_wsk);
			system("pause");
			break;
		case 23:
			adjust_priortiy_queue(&prior_q_wsk);
			system("pause");
			break;
		case 24:
			view_priority_queue(&prior_q_wsk);
			system("pause");
			break;
		case 25:
			clear_priority_queue(&prior_q_wsk);
			system("pause");
			break;
		case 26:
			printf("Put x: ");
			scanf(" %d", &x);
			printf("Set priority: ");
			scanf(" %d", &p);
			push_ow_priority_queue(&ow_prior_q_wsk, x, p);
			system("pause");
			break;
		case 27:
			pop_ow_priority_queue(&ow_prior_q_wsk);
			system("pause");
			break;
		case 28:
			peek_ow_priority_queue(&ow_prior_q_wsk);
			system("pause");
			break;
		case 29:
			adjust_ow_priortiy_queue(&ow_prior_q_wsk);
			system("pause");
			break;
		case 30:
			view_ow_priority_queue(&ow_prior_q_wsk);
			system("pause");
			break;
		case 31:
			clear_ow_priority_queue(&ow_prior_q_wsk);
			system("pause");
			break;
		case 32:
			about();
			system("pause");
			break;
		case 33:
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