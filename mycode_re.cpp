#include <bits/stdc++.h>
#define n 5
#define def "Student_22"
using namespace std;

char Grade(float x)
{
    if(x>90)
        return 'A';
    else if(x>80)
        return 'B';
    else if(x>70)
        return 'C';
    else if(x>60)
        return 'D';
    else if(x>50)
        return 'E';
    else
        return 'F';
}

struct node
{
    std::string usr="", pwd="", name="", id="", batch="";
    float marks[10]={0}, total=0.0, avg=0.0;
    char score='\0';
    struct node *next=NULL;
};

void Input(struct node *temp)
{
    string new_name,n_id,n_batch;
    int arr[10];
    float n_total=0.0,n_avg=0.0;
    char n_score;
    cout<<"\nEnter the name: "; cin>>new_name;
    temp->name=new_name;
    temp->usr=new_name; temp->pwd=def;
    cout<<"Enter the id: "; cin>>n_id; temp->id=n_id;
    cout<<"Enter the batch: "; cin>>n_batch; temp->batch=n_batch;
    cout<<"Enter marks for Eng | Math | Physics | Chem | Computers:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        temp->marks[i]=arr[i];
        n_total+=(float)arr[i];
    }
    temp->total=n_total;
    n_avg=n_total/n;
    temp->avg=n_avg;
    n_score=Grade(n_avg);
    temp->score=n_score;
}
void Display_details(struct node *temp)
{
    cout<<"\tName: " << temp->name << "\n\tID: " << temp->id << "\n\tBatch: " << temp->batch <<endl;
}
void Display_result(struct node *temp)
{
    cout<<"Marks: \tEng \tMath \tPhys \tChem \tComputer" <<endl;
    for(int i=0;i<n;i++)
        cout<<"\t"<<temp->marks[i];
    cout<<"\n\tTotal score: " << temp->total << "\tAverage: " << temp->avg;
    cout<<"\n\tGrade: " << temp->score <<"\n\tResult: " << ((temp->score=='F')?"FAIL":"PASS");
}
void Display(struct node *h)
{
    struct node *temp=h;
    while(temp!=NULL){
        cout<<"\t\t" << temp->name;
        temp=temp->next;
    }
}
void add_node(struct node **h)
{
    node *newer=new node();
    Input(newer);
    struct node *temp=*h;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newer;
}
void rem_node(struct node **h, struct node *rem)
{
    struct node *prev=*h, *temp=*h;
    while(temp!=rem)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->next!=NULL)
    prev->next=temp->next;
    else
        prev->next=NULL;
    free(temp);
}
void modify(struct node **h)
{
    cout<<"\n\t\tEnter new details:\n";
    Input(*h);
}

struct node* find(struct node **h, string nm)
{
    struct node *temp=*h;
    while(temp!=NULL && temp->name!=nm)
    {
        temp=temp->next;
    }
    if(temp==NULL){
        struct node* NA=new node();
        NA->usr="";
        //cout<<"\nReturning NUL";
        return NA;
    }

    else if(temp==*h)
        return *h;
    else
        return temp;

};

void Initial(struct node **h, string usr1, string pswd)
{
    (*h)->usr=usr1; (*h)->pwd=pswd;(*h)->name=usr1;
    (*h)->marks[10]={0}; (*h)->total=0.0;(*h)->avg=0.0;
    (*h)->score='\0';
    (*h)->next=NULL;
}
int main()
{
    string user,pass;
    const string user1="ADMIN",pass1="ADMIN12";
    int ct=0;
    int ch;
    node *head=new node();
    Initial(&head,user1,pass1);

    string mod_name="";

    do{
        cout<<"\n\tEnter username as ZERO to exit";
        cout<<"\nEnter username: "; cin>>user;
        if(user=="ZERO")
            break;
        struct node *check=find(&head,user);

        cout<<"Enter password: "; cin>>pass;

        if(check==head && pass==pass1)
        {
            cout<<"\nAccess granted to Admin. Welcome!";
        }
        else if(check!=NULL && check->pwd==pass)
        {
            cout<<"\nAccess granted to User. Welcome!";
            if(pass==def)
            {
                cout<<"\nNeed to change password. Enter new pw: ";
                cin>>pass;
                check->pwd=pass;
                cout<<"\nPlease proceed :D"<<endl;
            }

        }
        else if(check->usr=="")
        {
            cout<<"\nInvalid input details, try again!" << endl;
            continue;
        }
        else if(check!=NULL && check->pwd!=pass)
        {
            cout<<"\nWrong password, try again!";
            continue;
        }
        else
            continue;

        do{
            cout<<"\n1. Add student info \n2. View student details \n3. Modify student details";
            cout<<"\n4. Delete student info \nPress 0 to go back";
            cout<<"\nEnter your choice: "; cin>>ch;

            switch(ch){
            case 1:
                if(check->usr==user1)
                {
                    cout<<"\n\tAccess granted to Admin. Add details of student:\n";
                    add_node(&head);
                }
                else
                    cout<<"\tPermission denied. Kindly contact admin!"<<endl;
                break;
            case 2:

                if(check->usr==user1)
                {
                    mod_name="";
                    Display(head);
                    cout<<"\n\tSelect student: ";
                    cin >> mod_name;
                    node *fn=find(&head,mod_name);
                    if(fn->usr==user1)
                        cout<<"\n\tCANT VIEW ADMIN DETAILS!";
                    else if(fn->usr=="")
                        cout<<"\n\tNO SUCH ENTRY";
                    else
                    {
                        Display_details(fn);
                        Display_result(fn);
                    }
                }
                else
                {
                    Display_details(check);
                    Display_result(check);
                }
                break;
            case 3:
                mod_name="";
                if(check->usr==user1)
                {
                    cout<<"\n\tAccess granted to Admin.\nSelect a student: ";
                    Display(head);
                    cout<<"\nEnter name of student to modify details: "; cin >> mod_name;
                    struct node *check2=find(&head,mod_name);
                    if(check2->usr==user1)
                        cout<<"\n\tCan't modify admin";
                    else if(check2->usr=="")
                        cout<<"\n\tNO SUCH ENTRY";
                    else
                    {
                        cout<<"\n\t\tEnter new details:\n";
                        Input(check2);
                    }
                }
                else
                    cout<<"\tPermission denied. Kindly contact admin!"<<endl;
                break;
            case 4:
                mod_name="";
                if(check->usr==user1)
                {
                    cout<<"\n\tAccess granted to Admin.\nSelect a student:";
                    Display(head);
                    cout<<"\nEnter name of student to remove details: "; cin >> mod_name;
                    struct node *check3=find(&head,mod_name);
                    if(check3->usr==user1)
                        cout<<"\n\tCan't remove admin";
                    else if(check3->usr=="")
                        cout<<"\n\tNO SUCH ENTRY";
                    else
                    {
                        cout<<"\n\t\tRemoving user: " << check3->usr;
                        rem_node(&head,check3);
                    }
                }
                else
                    cout<<"\tPermission denied. Kindly contact admin!"<<endl;
                break;
            case 0:
                cout<<"\nGoing back :D"<<endl;
                break;
            default:
                cout<<"\n\tWrong input, try again"<<endl;
            }
        }while(ch!=0);
    }while((user!="ZERO"));

    cout<<"\n\t\tTHANK YOU! Have a great day!";
    return 0;
}
