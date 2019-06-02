#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "error.h"
#include "poly.h"

signed long extract_k(const char* s, int* i, bool negative);
signed long extract_e(const char*s, int* i);
poly_t* new_term();

struct poly_t
{
	poly_t *next;

	bool last;
	signed long k;
	signed long e;
};

poly_t* new_term()
{
	poly_t* term = malloc(sizeof(poly_t));
	term->k = 1;
	term->e = 0;
	term->last = true;
	term->next = term;
	return term;
}

signed long extract_k(const char* s, int* i, bool negative)
{
	if (s[*i] == 'x')
	{
		return 1;
	}
	long k = (s[*i] - '0');
	(*i)++;
	while (isdigit(s[*i]))
	{
		k *= 10;
		k += (s[*i] - '0');
		(*i)++;
	}
	if (negative)
	{
		k*=(-1);
	}
	return k;
}

signed long extract_e(const char*s, int* i)
{
	if (s[(*i)] != 'x')
	{
		return 0;
	}

	(*i)++;

	if (s[(*i)] != '^')
	{
		return 1;
	}

	(*i)++;

	long e = (s[(*i)++] - '0');

	while (isdigit(s[*i]))
	{
		e *= 10;
		e += (s[*i] - '0');
		(*i)++;
	}

	return e;
}

poly_t* new_poly_from_string(const char* s)
{
	poly_t* p = new_term();

	bool head_init = true;

	int i = 0;
	bool negative = false;
	while (s[i] != '\0')
	{

		if (s[i] == '-')
		{
			negative = true;
		}

		if (s[i] == 'x' || isdigit(s[i]))
		{
			signed long k = extract_k(s,&i, negative);
			signed long e = extract_e(s,&i);
			poly_t* t = new_term();
			t->k = k;
			t->e = e;

			if (head_init)
			{
				free(p);
				p = t;
				head_init = false;
			} else {
				poly_t* term = p->next;
				while (!term->last)
				{
					term = term->next;
				}
				term->last = false;
				term->next = t;
			}
			negative = false;
		}
		if (s[i] == '\0')
		{
			break;
		}
		i++;
	}
	return p;
}

void free_poly(poly_t* p)
{
	if (!p->last)
	{
		free_poly(p->next);
	}
	free(p);
}

poly_t* mul(poly_t *a, poly_t *b)
{
	poly_t* head = new_term();
	poly_t* head_a = a;
	poly_t* head_b = b;
	bool head_init = true;
	while (1)
	{
		while (1)
		{
			signed long k = a->k * b->k;
			signed long e = a->e + b->e;

			if (head_init)
			{
				head->e = e;
				head->k = k;
				head_init = false;
			} else {
				poly_t* in = new_term();
				in->e = e;
				in->k = k;
				poly_t* p = head;
				while (!p->last && e < (p->e))
				{
					p = p->next;
				}
				if (e == (p->e))
				{
					(p->k)+=(in->k);
					free(in);
				} else if (p->last) {
					p->last = false;
					p->next = in;
				} else {
					in->last = false;
					in->next = p->next;
					p->next = in;
				}
			}
			if (b->last)
			{
				b = head_b;
				break;
			}
			b = b->next;
		}

		if (a->last)
		{
			a = head_a;
			break;
		}
		a = a->next;
	}

	return head;
}

void print_poly(poly_t* p)
{
	if (p->k == 1)
	{
		if (p->e == 0)
		{
			printf("1");
		} else if (p->e == 1) {
			printf("x");
		} else {
			printf("x^%ld", p->e);
		}
	} else {
		if (p->e == 0)
		{
			printf("%ld", p->k);
		} else if (p->e == 1) {
			printf("%ldx", p->k);
		} else {
			printf("%ldx^%ld",p->k, p->e);
		}
	}
	while (!p->last)
	{
		p = p->next;
		if (p->k == 1)
		{
			if (p->e == 0)
			{
				printf(" + 1");
			} else if (p->e == 1) {
				printf(" + x");
			} else {
				printf(" + x^%ld", p->e);
			}
		} else if (p->k > 1) {
			if (p->e == 0)
			{
				printf(" + %ld", p->k);
			} else if (p->e == 1) {
				printf(" + %ldx", p->k);
			} else {
				printf(" + %ldx^%ld",p->k, p->e);
			}
		} else if (p->k == -1) {
			if (p->e == 0)
			{
				printf(" - 1");
			} else if (p->e == 1) {
				printf(" - x");
			} else {
				printf(" - x^%ld", p->e);
			}
		} else if (p->k < -1){
			if (p->e == 0)
			{
				printf(" - %ld", -(p->k));
			} else if (p->e == 1) {
				printf(" - %ldx", -(p->k));
			} else {
				printf(" - %ldx^%ld",-(p->k), p->e);
			}
		}
	}
	putchar('\n');
}
