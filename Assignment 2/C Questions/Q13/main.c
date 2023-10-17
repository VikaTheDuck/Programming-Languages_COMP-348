// October 2020
// Victoria Solodovnikova 40133650
// Sofiya Taver 40095050
// Laurent Cousineau 26773001

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{

   char data[255];
   struct node *next;

}
Node;
Node *head=NULL;

void insert_dictionary_order(char *character)
{
   Node *myNode = (Node*)malloc(sizeof(Node)); 
   strcpy(myNode->data,character); 
   myNode->next=NULL;

   Node *temp=head,*previous=NULL;

   if(temp==NULL)
   {
       head=myNode;  
   }

   else
   { 
       while(temp!=NULL)
       {
           if(0<strcmp(temp->data,character))
           break;
           previous=temp;
           temp=temp->next;  
       }

       if(previous==NULL)
       {
           myNode->next=head;
           head=myNode;  
       }

       else
       {
           myNode->next=previous->next;
           previous->next=myNode;  
       }  
   }
}
 

void print_list()
{
   Node *temp=head;
   while(temp!=NULL)
   {
       printf("%s ",temp->data);
       temp=temp->next;  
   }
   printf("\n");
}
int main()
{
   printf("****************************************************************\nPlease enter strings of words separated by a whitespace. To denote the end of the text, add a single . string or allow it to reach the EOF:\n\n ");
  
   do
   {
       char s[255];
       scanf("%s",s);

       if(strcmp(s,".")==0 || strcmp(s,"EOF")==0)
       {
           insert_dictionary_order(s); 
           break;
       }

       else
       {
           insert_dictionary_order(s); 
       }
   }
   while(1);
   print_list();
   return 0;
}

/*Input to be tested:
*
*This is a sample text. The file will be terminated by a single dot: . The program continues *processing the lines because the dot (.) did not appear at the beginning. . even though this *line starts with a dot, it is not a single dot. The program stops processing lines right here. . *You won't be able to feed any more lines to the program. 
*/
