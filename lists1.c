#include "shell.h"

/**
 * list_len - determines the lenth of a singly linked list
 * @h: pointer to head node
 *
 * Return: length of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{

		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{

	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs = NULL;
	char *str = NULL;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{

		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints all elements of a sinlgy linked list
 * @h: pointer to fists node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{

	size_t i = 0;

	while (h)
	{

		_puts(convert_number(h->num, 10, 0)); /*convert_number to convert_num*/
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_putchar('\n');
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns the node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after matched prefix
 *
 * Return: node with matched string, null if none
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{

	char *p = NULL;

	while (node)
	{

		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to first node
 * @node: pointer to node to be indexed
 *
 * Return: index of node, -1 if unsuccessful
 */
ssize_t get_node_index(list_t *head, list_t *node)
{

	size_t i = 0;

	while (head)
	{

		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
