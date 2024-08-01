#include <bits/stdc++.h>
#include "mysource.cpp"
#define n 5
#define def "Student_22"
using namespace std;

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
