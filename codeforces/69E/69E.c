/*
Ray Hong
20120928
Unique number in a segment
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define MAX_INT 1000000001

typedef struct qnode Qnode;
struct qnode {
  int data;
  Qnode * next;
};

typedef struct {
  Qnode * head;
  Qnode * tail;
} List;

typedef struct snode Snode;
struct snode {
  int data;
  int count;
  Snode * next;
};

List  * make_list   (List * list);
Qnode * make_Qnode  (int data);
List  * push_back   (Qnode * newNode, List * list);
Qnode *  pop_front  (List * list);
void   print_list   (List * list);
Snode * make_Snode  (int data);
Snode * insert_value(int data, Snode * head);
Snode * reduce_value(int data, Snode * head);
int search_unique_value (Snode * head);

int main() {
  int i;
  int n, k;
  int v;
  int unique;
  List * list = NULL;
  Snode * head = NULL;
  Qnode * qnode = NULL;
  list = make_list(list);
  printf("Enter n, k: ");
  scanf("%d %d", &n, &k);
  for (i=0; i<k; i++) { // initializing
    scanf("%d", &v);
    list = push_back(make_Qnode(v), list);
    head = insert_value(v, head);
  }
  unique = search_unique_value(head);
  if (unique!=MAX_INT) {
    printf("%d\n", unique);
  } else {
    printf("Nothing\n");
  }
  for (i=0; i<n-k; i++) {
    scanf("%d", &v);
    list = push_back(make_Qnode(v), list);
    head = insert_value(v, head);
    qnode = pop_front(list);
    head = reduce_value(qnode->data, head);
    free(qnode);
    unique = search_unique_value(head);
    if (unique!=MAX_INT) {
      printf("%d\n", unique);
    } else {
      printf("Nothing\n");
    }
  }
  //print_list(list);
  return 0;
}

/**************************************************/
// input a list
// return a list
List * make_list(List * list) {
  list = malloc(sizeof(*list));
  list->head = NULL;
  list->tail = NULL;
  return list;
}
/**************************************************/
// input a data
// return a node
Qnode * make_Qnode(int data) {
  Qnode * node = malloc(sizeof(*node));
  node->data = data;
  node->next = NULL;
  return node;
}
/**************************************************/
// input a newNode pointer and a list pointer
// return the list pointer 
List * push_back(Qnode * newNode, List * list) {
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    newNode->next = NULL; //not sure, just put it here first
    list->tail = newNode;
  }
  return list;
}

/**************************************************/
// input a list pointer
// return the head node
Qnode * pop_front(List * list) {
  Qnode * node = NULL;
  if (list->head!=NULL) {
    node = list->head;
    list->head = list->head->next;
  }
  return node;
}
/**************************************************/
// input a list
// return none
void print_list (List * list) {
  Qnode * node;
  node = list->head;
  while (node!=NULL) {
    printf("one node: %d\n", node->data);
    node = node->next;
  }
  return;
}



/**************************************************/
// input a dat
// return a Snode
Snode * make_Snode(int data) {
  Snode * node = malloc(sizeof(*node));
  assert(node != NULL);
  node->data = data;
  node->count = 1;
  node->next = NULL;
  return node;
}
/**************************************************/
// input a data to take out and a head pointer
// return a head with the data reduced
Snode * reduce_value(int data, Snode * head) {
  Snode * node = NULL;
  Snode * prev = NULL;
  if (head != NULL) {
    node = head;
    while (node->data != data) { // find the node with that value
      prev = node;
      node = node->next;
    }
    node->count--; 
    if (node->count == 0) { // eliminate the node
      if (node == head) {
        head = head->next;
      } else {
        prev->next = node->next;
        free(node);
      }
    }
  }
  return head;
}
/**************************************************/
// input a node with data in it and a head pointer
// return the head pointer with a new value added
Snode * insert_value (int data, Snode * head) {
  Snode * nodeData = make_Snode(data);
  Snode * node = head;
  Snode * prev = NULL;
  int cont = TRUE;
  if (head == NULL) {
    head = nodeData;
  } else {
    while (node!=NULL && cont) {
      if (node->data == nodeData->data) {
        (node->count)++;
        free(nodeData);
        cont = FALSE;
      } else if (node->data < nodeData->data) {
        if (node==head) {
          nodeData->next = head;
          head = nodeData;
        } else {
          prev->next = nodeData;
          nodeData->next = node;
        }
        cont = FALSE;
      } else {
        prev = node;
        node = node->next;
      }
    }
    if (node==NULL) { // if data is the smallest one
      prev->next = nodeData;
    }
  }
  return head;
}
/**************************************************/
// input a head pointer
// return 1 largest unique value
int search_unique_value (Snode * head) {
  Snode * node = head;
  int reVal;
  assert(head != NULL);
  while (node!=NULL && node->count!=1) {
    node = node->next;
  }
  if (node!= NULL) {
    reVal = node->data;
  } else {
    reVal = MAX_INT;
  }
  return reVal;
}
