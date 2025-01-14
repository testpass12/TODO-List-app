#include <bits/stdc++.h>
#include<ncurses.h>
struct node
{
    std::string data;
    bool flag;
    node *next;
    node(std::string data)
    {
        this->data = data;
        this->flag = false;
        next = nullptr;
    }
};

int displaydashboard(node *head)
{
    if (head->next == nullptr)
    {
        std::cout << "No Task Available" << std::endl;
        std::cout << "***************" << std::endl;
        return 0;
    }
    int i = 0;
    node *temp = head->next;
    while (temp != nullptr)
    {
        if(!temp->flag){
            std::cout << i << ":" << temp->data << "\t Pending" << std::endl;    
        }
        else{
            std::cout << i << ":" << temp->data << "\t Completed"<< std::endl;
        }
        temp = temp->next;
        i++;
    }
    std::cout << "***************" << std::endl;
    return i;
}
void createtask(node *head)
{
    std::string task;
    std::cout << "Enter the Task:";
    std::cin >> task;
    node *add = new node(task);
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = add;
}
void removetask(node *head, int index)
{
    node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    node *trash = temp->next;
    temp->next = trash->next;
    delete (trash);
}
void mark(node *head,int size){
    node *temp = head->next;
    for(int i = 0;i<size;i++){
        temp = temp->next;
    }
    if(temp->flag)temp->flag = false;
    else temp->flag = true;
}
void deletell(node *head){
    if(head == nullptr){
        return;
    }
    deletell(head->next);
    delete(head);
}
int main()
{
    int size = 0,i;
    node *head = new node("");
    std::string options = "1.Create the Task\n"
                          "2.Mark the Complete Task\n"
                          "3.Remove Complete task\n"
                          "4.Exit";
    int ch;
    while (true)
    {
        std::cout << "***TODO List***" << std::endl;
        size = displaydashboard(head);
        std::cout << options << std::endl;
        std::cout << "Select the option:";
        std::cin >> ch;
        if(ch == 1){
                createtask(head);
        }
        else if(ch == 2){
                std::cout << "Enter the Num of task:";
                std::cin >> i;
                if(i > size){
                    std::cout << "Invalid task num" << std::endl;
                    break;
                }
                mark(head,i);}
        else if(ch == 3){
                std::cout << "Enter the Num of task:";
                std::cin >> i;
                if(i > size){
                    std::cout << "Invalid task num" << std::endl;
                    break;
                }
                removetask(head, i);
        }
        else if(ch == 4){
                std::cout << "Exited" << std::endl;
                break;
        }
        else std::cout << "Invalid Option" << std::endl;
        sleep(1);
    }
    deletell(head);
    return 0;
}