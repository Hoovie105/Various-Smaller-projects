#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct snode {
  int id;
  char * name;
  struct snode * next;
};


struct slist {
  struct snode * front;
};


struct slist * create_list()
{
  struct slist *lst = malloc(sizeof(struct slist));
  lst->front = NULL;
  return lst;
};


bool remove_student(int id, struct slist * lst){ 
  if (lst->front == NULL){
    return false;
  }

  struct snode *temp = NULL; 
  if (lst->front->id == id) {
    temp = lst->front;
    lst->front = lst->front->next;
    free(temp->name);
    free(temp);
    return true;
  }

  struct snode *curnode = lst->front;
  while (curnode->next && id != curnode->next->id) {
    curnode = curnode->next;
  }

  if (curnode->next == NULL) {
    return false;
  }
  struct snode *old_node = curnode->next;
  curnode->next = curnode->next->next;
  free(old_node->name);
  free(old_node);
  return true;
}

char * find_student(int id, struct slist * lst){ 
  struct snode *node = lst->front;
  while (node != NULL) { 
    if(node ->id == id) {
      char *name = malloc(sizeof(char) * strlen(node->name) + 1);
      if (name == NULL)
      return NULL;
      strcpy(name, node->name);
      return name;
    }
    node = node->next;
  }
return NULL;
}
bool insert_student(int id, char name[], struct slist * lst) {
  struct snode * newnode = malloc(sizeof(struct snode)); 
  if (newnode == NULL)
    return NULL;

  newnode->name = malloc((strlen(name) + 1) * sizeof(char));
  if (newnode->name == NULL)
    return NULL;

  newnode->id = id;
  strcpy(newnode->name, name);
  
 
  if (lst->front == NULL || id < lst->front->id) {
    newnode->next = lst->front;
    lst->front = newnode;
    return true;
  }

  
  struct snode *curnode = lst->front;
  while (curnode) {  
    if (curnode->id == id) {
      return false;
    }
    curnode = curnode->next;
  }
  curnode = lst->front;
  while(curnode->next != NULL) {
    if(id < curnode->next->id) {
      break;
    }
    curnode = curnode->next;
  }
  newnode->next = curnode->next;
  curnode->next = newnode;
  return true;
}

void free_list(struct slist * lst){
  struct snode *curnode = lst->front;
  struct snode *nextnode = NULL;
  while (curnode) {
    struct snode * nextnode = curnode->next;
    free(curnode->name);
    free(curnode);
    curnode = nextnode;
  }
  free(lst);
}


bool is_sorted(struct slist * lst){ 
  struct snode *curnode = lst->front;
  struct snode *nextnode = NULL;
  if(lst->front == NULL){
    return false;
  }
  while (curnode->next){
    if(curnode->id > curnode->next->id){
      return false;
    }
    curnode = curnode -> next;
  }
 return true;
}

int main (void) {
  struct slist * Student_Names = create_list();
  insert_student(6,"Hooves", Student_Names);
  insert_student(12,"Trevor", Student_Names);
  insert_student(321,"Geko", Student_Names);
  insert_student(123,"Hey_Arnold", Student_Names);
  insert_student(1234,"Sandal_Man", Student_Names);
    
    
  char * name = find_student(6, Student_Names);
  assert(strcmp (name, "Hooves") == 0);
  assert(find_student(0, Student_Names)== NULL);
  assert(insert_student(2, "Trevor", Student_Names) == true);
  assert(insert_student(1234, "Sandal_Man", Student_Names) == false);
  assert(insert_student(123, "Hey_Arnold", Student_Names) == false);
  assert(remove_student(12, Student_Names)== true);
  assert(is_sorted(Student_Names)== true);
  
  free(name);
  free_list(Student_Names);
}
