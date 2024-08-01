#include <bits/stdc++.h>
using namespace std;
char Grade(float x);

struct node
{
    std::string usr="", pwd="", name="", id="", batch="";
    float marks[10]={0}, total=0.0, avg=0.0;
    char score='\0';
    struct node *next=NULL;
};
void Input(struct node *temp);
void Display_details(struct node *temp);
void Display_result(struct node *temp);
void Display(struct node *h);
void add_node(struct node **h);
void rem_node(struct node **h, struct node *rem);
void modify(struct node **h);
struct node* find(struct node **h, string nm);
void Initial(struct node **h, string usr1, string pswd);
