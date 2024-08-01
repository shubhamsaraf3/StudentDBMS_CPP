#include "myheader.h"
#define n 5
#define def "Student_22"
using namespace std;

char Grade(float x)
{
    if (x > 90)
        return 'A';
    else if (x > 80)
        return 'B';
    else if (x > 70)
        return 'C';
    else if (x > 60)
        return 'D';
    else if (x > 50)
        return 'E';
    else
        return 'F';
}

void Initial(struct node **h, string usr1, string pswd)
{
    (*h)->usr = usr1;
    (*h)->pwd = pswd;
    (*h)->name = usr1;
    (*h)->marks[10] = {0};
    (*h)->total = 0.0;
    (*h)->avg = 0.0;
    (*h)->score = '\0';
    (*h)->next = NULL;
}

void Input(struct node *temp)
{
    string new_name, n_id, n_batch;
    int arr[10];
    float n_total = 0.0, n_avg = 0.0;
    char n_score;
    cout << "\nEnter the name: ";
    cin >> new_name;
    temp->name = new_name;
    temp->usr = new_name;
    temp->pwd = def;
    cout << "Enter the id: ";
    cin >> n_id;
    temp->id = n_id;
    cout << "Enter the batch: ";
    cin >> n_batch;
    temp->batch = n_batch;
    cout << "Enter marks for Eng | Math | Physics | Chem | Computers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp->marks[i] = arr[i];
        n_total += (float)arr[i];
    }
    temp->total = n_total;
    n_avg = n_total / n;
    temp->avg = n_avg;
    n_score = Grade(n_avg);
    temp->score = n_score;
}
void Display_details(struct node *temp)
{
    cout << "\tName: " << temp->name << "\n\tID: " << temp->id << "\n\tBatch: " << temp->batch << endl;
}
void Display_result(struct node *temp)
{
    cout << "Marks: \tEng \tMath \tPhys \tChem \tComputer" << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << temp->marks[i];
    cout << "\n\tTotal score: " << temp->total << "\tAverage: " << temp->avg;
    cout << "\n\tGrade: " << temp->score << "\n\tResult: " << ((temp->score == 'F') ? "FAIL" : "PASS");
}
void Display(struct node *h)
{
    struct node *temp = h;
    while (temp != NULL)
    {
        cout << "\t\t" << temp->name;
        temp = temp->next;
    }
}
void add_node(struct node **h)
{
    node *newer = new node();
    Input(newer);
    struct node *temp = *h;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newer;
}
void rem_node(struct node **h, struct node *rem)
{
    struct node *prev = *h, *temp = *h;
    while (temp != rem)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next != NULL)
        prev->next = temp->next;
    else
        prev->next = NULL;
    free(temp);
}
void modify(struct node **h)
{
    cout << "\n\t\tEnter new details:\n";
    Input(*h);
}

struct node *find(struct node **h, string nm)
{
    struct node *temp = *h;
    while (temp != NULL && temp->name != nm)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        struct node *NA = new node();
        NA->usr = "";
        // cout<<"\nReturning NUL";
        return NA;
    }

    else if (temp == *h)
        return *h;
    else
        return temp;
};


