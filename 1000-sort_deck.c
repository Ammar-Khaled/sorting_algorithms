#include "deck.h"
#include <stdio.h>
#include <string.h>

/**
 * get_int_value - convert the value of the card to an int
 * @ch: the first character in the value of the card
 *
 * Return: the value as integer
 */
int get_int_value(char ch)
{
	switch (ch)
	{
	case 'A':
		return (1);
	case 'J':
		return (11);
	case 'Q':
		return (12);
	case 'K':
		return (13);
	default:
		return (atoi(ch));
	}
}

/**
 * compare_cards - compare cards for the qsort function
 * @a: one card
 * @b: another card
 * Return: relative order
 */
int compare_cards(const void *a, const void *b)
{
	card_t *c1, *c2;
	int v1, v2;

	c1 = *(card_t **)a;
	c2 = *(card_t **)b;

	if (c1->kind == c2->kind)
	{
		v1 = get_int_value(c1->value[0]);
		v2 = get_int_value(c2->value[0]);

		return (v1 - v2);
	}

	return (c1->kind - c2->kind);
}

/**
 * sort_deck - sorts a deck of cards.
 * From Ace to King
 * From Spades to Diamonds
 * @deck: pointer to pointer to the head of doubly linked list of cards
 */
void sort_deck(deck_node_t **deck)
{
	int i;
	deck_node_t *cur;
	card_t *arr[52];

	for (i = 0, cur = *deck; i < 52; i++, cur = cur->next)
		arr[i] = (card_t *)cur->card;

	qsort(arr, 52, sizeof(card_t *), compare_cards);

	for (i = 0, cur = *deck; i < 52; i++, cur = cur->next)
		cur->card = arr[i];
}
