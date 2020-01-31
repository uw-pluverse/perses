typedef struct List {
  struct List *next;
  int data;
} List;
List *find(List *head, int data) {
  if (!head)
    return 0;
  if (head->data == data)
    return head;
  return find(head->next, data);
}
