#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * add_node - adds new nodes at beginning of list
 * @head: pointer to beginning of list
 * @str: pointer to string
 * @num: node index used by history
 *
 * Return: Address of new element
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	char *str2 = strdup(str);
	list_t *new_n = (list_t *)malloc(sizeof(list_t));

	if (!head)
		return (NULL);

	if (!new_n)
		return (NULL);

	_memset((void *)new_n, 0, sizeof(list_t));

	if (str)
	{
		new_n->str = str2;
		if (!new_n->str)
		{
			free(new_n);
			return (NULL);
		}
	}
	new_n->num = num;
	new_n->next = *head;
	*head = new_n;

	return (new_n);

}

/**
 * add_node_end - adds node to end of list
 * @head: pointer to pointer to list
 * @str: new data
 * @num: node number used by history
 *
 * Return: pointer to new element
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{

	char *copy = strdup(str);
	list_t *temp = (list_t *)malloc(sizeof(list_t));
	list_t *new = *head;

	if (!temp)
		return (NULL);

	_memset((void *)temp, 0, sizeof(list_t));
	temp->num = num;

	if (str)
	{
		temp->str = copy;
		if (!temp->str)
		{
			free(temp);
			return (NULL);
		}
	}
	temp->next = NULL;

	if (*head == NULL)
		*head = temp;
	else
	{
	while (new->next != NULL)
		new = new->next;
	new->next = temp;
	}
	return (new);

}

/**
 * print_list_str - prints the str element of a list_t singly linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes the node at a given index
 * @head: pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node = NULL, *prev_node = NULL;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head: pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head)
{

	list_t *node = NULL, *next_node = NULL, *head2 = NULL;

	if (!head || !*head)
		return;
	head2 = *head;
	node = head2;

	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head = NULL;
}
