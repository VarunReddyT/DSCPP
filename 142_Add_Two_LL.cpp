#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insert(int val)
    {
        Node *temp = head;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display(Node * third)
    {
        Node *temp = third;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void addTwoList(Node *first, Node *second, LinkedList *ll3)
    {
        Node *temp1 = first;
        Node *temp2 = second;
        int sumT = 0;
        int carry = 0;
        while (temp1 != NULL && temp2 != NULL)
        {
            sumT = temp1->val + temp2->val + carry;

            int digit = sumT % 10;
            carry = sumT / 10;
            ll3->insert(digit);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != NULL)
        {
            int sumT = temp1->val + carry;
            int digit = sumT % 10;
            carry = sumT / 10;
            ll3->insert(digit);
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            int sumT = temp2->val + carry;
            int digit = sumT % 10;
            carry = sumT / 10;
            ll3->insert(digit);
            temp2 = temp2->next;
        }

        if (carry > 0)
        {
            ll3->insert(carry);
        }
        // ll3->reverse();
        // ll3->display();
    }
};
int main()
{
    LinkedList ll1;
    LinkedList ll2;
    LinkedList ll3;
    ll1.insert(5);
    ll1.insert(7);
    ll1.insert(6);

    ll2.insert(5);
    ll2.insert(8);

    ll1.display();
    ll2.display();

    Node *first = ll1.reverse();
    Node *second = ll2.reverse();

    ll3.addTwoList(first, second, &ll3);

    Node * third = ll3.reverse();
    ll3.display(third);
    return 0;
}