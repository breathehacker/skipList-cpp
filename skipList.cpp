//
//  main.cpp
//  skipList
//
//  Created by Fadi Khan on 3/6/17.
//  Copyright (c) 2017 __JxtFAdi__. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
using namespace std;
#define maxLevel 5;

struct node{
    double x;
    int key;
    node *next;
    node *up;
    node *bottom;
    node *prev;
};
bool flip()//for Randomly Generating LEVELS
{
    return rand()%2;

}
void add(node *pre, node *curr, double val)//Add NODE after the given node
{
    if (pre->x>val) {
            cout<<"pre\t"<<pre->x<<endl;
       // pre=pre->prev;
        cout<<"pre_after\t"<<pre->x<<endl;

    }

        /*curr->next=pre->next;
        curr->prev=pre;
        pre->next=curr;
         */
    curr->next=pre->next;
    curr->prev=pre;
    pre->next=curr;
        curr->x=val;
        curr->up=NULL;
        curr->bottom=NULL;

    /*
    node *a=pre->prev;
    if (val<=pre->x) {
        if (pre->prev) {
            a->next=curr;
            curr->prev=a;
            curr->next=pre;
            pre->prev=curr;
        }
        else {
            pre->next=curr;
            curr->prev=pre;
            curr->next=NULL;
        }

    }
    else {
        pre->next=curr;
        curr->prev=pre;
        curr->next=NULL;
        curr->bottom=NULL;
        curr->up=NULL;
    }
    curr->up=NULL;
    curr->x=val;
    curr->bottom=NULL;
     */
   }
void display(node *temp)//Display
{
    while (temp) {
        if (temp->prev) {
             cout<<temp->x<<"\t";
        }

        temp=temp->next;
    }
    cout<<endl;
   }
node *bottom(node *temp){
   return temp->bottom;
}
node *up(node *temp){
    return temp->up;
}
node *prev(node *temp){
    return temp->prev;
}
node *next(node *temp){
    return temp->next;
}
node *maxNode(node *temp){
    while (temp->up) {
        temp=temp->up;
    }
    return temp;
}
node *maxNode(node *temp, int level){
    for (int i=2; i<=level; i++) {
        temp=up(temp);
    }
    return temp;
}
node *position(node *temp, double val){
  // cout<<temp->x<<endl;
    int le=1;
        while (temp->bottom) {
            //cout<<temp->x<<endl;
            //cout<<temp->x<<endl;
            if (temp->next) {
                node *a=temp->next;
                //cout<<"bbbbb------>"<<temp->x<<endl;
                while (temp->x<=val && temp->next && a->x<=val )
                {
                    /*
                     if (!temp->prev) {
                     break;
                     //cout<<temp->x<<endl;
                     }
                     else if (temp->prev && temp->x<=val) {
                     temp=temp->next;
                     //cout<<temp->x<<endl;
                     }
                     if (!temp->prev) {
                     if (temp->next) {
                     node *a=temp->next;
                     if (a->x<=val) {
                     temp=temp->next;
                     }
                     }

                     }
                     */

                    //   cout<<temp->x<<endl;
                    a=a->next;
                   // cout<<temp->x<<"\t";
                    temp=temp->next;
                   // cout<<"MOVED :\t"<<temp->x<<endl;

                }
            }

          //  cout<<"Level    " <<le<<endl;
            //cout<<temp->x<<endl;
                       temp=temp->bottom;
            ++le;
        }
  // cout<<"____"<<temp->x<<endl;
   // cout<<"End------------\t"<<temp->x<<endl;
    /*
    if (!temp->prev) {
        temp=temp->next;
    }
    while (temp->next && temp->x<=val){
        temp=temp->next;
        // cout<<temp->x<<endl;
    }
    //cout<<"end------------------pos\n";
    cout<<temp->x<<endl;
     */
    node *v=temp->next;
    while (temp->next && temp->x<=val && v->x<=val) {
       // cout<<temp->x<<"\t";
        temp=temp->next;
        v=v->next;
    }
    //cout<<"\nrt\t"<<temp->x<<endl;
    return temp;
}
void insertAFterAbove(node *temp, node *curr){
    node *a=temp->next;
    curr->next=a;
    if (a) {
         a->prev=curr;
    }

    curr->prev=temp;
    temp->next=curr;

}
node* level(node *temp, int lev){
    node *curr=new node;
    temp->up=curr;
    curr->x=temp->x;
    curr->bottom=temp;
    curr->next=NULL;
    curr->prev=NULL;
    while (temp->prev && !temp->up) {
        temp=prev(temp);
    }
valid:
    int check=1;
    while (check!=lev && temp->up  ) {
        temp=up(temp);
        ++check;
    }
    if (check!=lev) {
        temp=prev(temp);
        while (temp->prev && !temp->up) {
            temp=prev(temp);
        }
        goto valid;
    }
    insertAFterAbove(temp, curr);
    return  curr;
    }
node* creaTenode(node *curr){
    node *temp=new node;
    temp->x=curr->x;
    temp->bottom=curr;
    temp->up=NULL;
    temp->next=NULL;
    temp->prev=NULL;
    curr->up=temp;
    return temp;

}
void deleteNode(node *temp){
    node *pre=temp->prev;
    //pre
    //temp
    pre->next=temp->next;
    temp=temp->next;
    if (temp) {
        temp->prev=pre;
    }

}
void menu(){
    cout<<"1 == > INSERT\n";
    cout<<"2 == > DELETE\n";
     cout<<"3 == > DISPLAY\n";
}
int main(int argc, const char * argv[])
{
   srand (time(NULL));
    node *start;
    start=new node;
    start->next=NULL;
    start->bottom=NULL;
    start->up=NULL;
    start->prev=NULL;
    start->x=-888888888888888;
    node *temp=start;
    int max=maxLevel;
    for (int i=2; i<=max; i++) {
            node *curr=new node;
            curr->next=NULL;
            curr->bottom=temp;
            curr->next=NULL;
            curr->prev=NULL;
            curr->up=NULL;
            curr->x=i*-888888888888888;
            temp->up=curr;
            temp=curr;
        }
           cout<<endl;
    while (1) {
              system("cls");
              system("color 4f");
        if (start->next) {
           // cout<<"\n==================\n";
           // display(start);
         //   cout<<"\n==================\n";
        }
        else {
            cout<<"LIST EMPTY!\n\n";
        }
        menu();
        int choice;
        cout<<"YOUR CHOICE :\t";
        cin>>choice;
          system("color 30");
        switch (choice) {
            case 1:
            {
                system("cls");

                //Initializing...............
                double num;
                temp=start;
                cout<<"ENTER THE NUMBER :\t";
                cin>>num;
                if(!start->next)
                {
                    temp=start;
                    node *curr=new node;
                    curr->prev=start;
                    start->next=curr;
                    curr->x=num;
                    curr->up=NULL;
                    curr->bottom=NULL;
                    curr->next=NULL;
                }
                else {
                    temp=position(maxNode(temp), num);
                    node *curr=new node;
                    add(temp, curr, num);
                    int check=1;
                    while (check!=max) {
                        int coin=flip();
                        if (!coin) {
                            break;
                        }
                        //cout<<"_____"<<check<<"\t"<<flip()<<endl;
                        curr=creaTenode(curr);
                        while (!temp->up) {
                           // cout<<temp->x<<endl;
                            temp=temp->prev;


                        }
                         // cout<<temp->x<<endl;
                        temp=temp->up;
                       // cout<<temp->x<<endl;
                        insertAFterAbove(temp, curr);
                        ++check;

                    }

                }
                system("pause");
                break;
            //case-----1---ends
            }
            case 2:{
                  system("cls");
                if (start->next) {
                        cout<<"\n==================\n";
            display(start);
            cout<<"\n==================\n";
                    cout<<"ENTER THE VALUE TO DELETE :\t";
                    double del;
                    cin>>del;
                    temp=start;
                    temp=position(temp, del);
                    if (temp->x==del) {
                        while (temp) {
                            deleteNode(temp);
                            temp=temp->up;
                        }
                        cout<<"\n------->DELETED!\n";
                    }
                    else {
                            system("color 4f");
                        cout<<"Incorrect Number entered!\n";
                    }

                }
                else {
                        system("color 4f");
                    cout<<"\n==================\n";
                     cerr<<"OOOOOOOPS! LIST IS EMPTY__!\n";
                    cout<<"\n==================\n";
                }
                  system("pause");
                break;

            }//case-----2----ends
            case 3:{
                  system("cls");
                if (start->next) {
                    cout<<"\n==================\n";
                    //int dis=1;
                    temp=start;
                   // while (temp) {
                    //cout<<dis<<"---->\t";
                        display(temp);
                      //  temp=temp->up;
                       // ++dis;
                    //}
                    cout<<"\n==================\n";
                }
                else {
                        system("color 4f");
                    cout<<"\n==================\n";
                    cerr<<"OOOOOOOPS! LIST IS EMPTY__!\n";
                    cout<<"\n==================\n";
                }
                  system("pause");
                break;
            }//case 3 ___ENDs;;;;;;
            default:{
                //display(start->up);
               system("color 4f");
                cerr<<"INCORRRECT CHOICE\n";
                system("pause");
                break;
            }
        }
    }

    return 0;
}
