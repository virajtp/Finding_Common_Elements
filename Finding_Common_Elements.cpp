#include<iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};


class LinkedList{
        private:
            Node* start=NULL;
        public:
            void insertEnd(int X);	//Insert a new node at the beginning
			void print();			//print linked list values
			int checkDuplicate(int y);		//cheking if there are duplicate values in the list
			void findCommon(LinkedList a, LinkedList b);		//find the common values to both lists
    };


void LinkedList::insertEnd(int x)
{
	struct Node* newNode;
	newNode = new Node;

	if (start == NULL)
	{
		newNode->data = x;
		newNode->next = NULL;
		newNode->prev = NULL;
		start = newNode;
	}
	else
	{
		struct Node* temp = start;
		newNode->data = x;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		newNode->prev = temp;
		newNode->next = NULL;
		temp->next = newNode;
		return;
	}
}

void LinkedList::print()
{
	struct Node* tempNode = start;
	
	while (tempNode != NULL)
	{
		cout << " " << tempNode->data;
		tempNode = tempNode->next;
	}
}

int LinkedList::checkDuplicate(int y)
{
	struct Node* temp1 = start;
	struct Node* temp2;

	while (temp1!= NULL)
	{
		temp2 = temp1->next;
			while(temp2 != NULL)
			{
				if (temp1->data == temp2->data)
				{
					return 0;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
	}
}

void LinkedList::findCommon(LinkedList a , LinkedList b)
{
	struct Node* temp1 = a.start;
	struct Node* temp2;
	int flag=0;
	while (temp1 != NULL)
	{
		temp2 = b.start;
		while (temp2 != NULL)
		{
			if (temp1->data == temp2->data)
			{
				insertEnd(temp1->data);
				flag = 1;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	if (flag == 0)
		cout << "There are no common values to both lists...\n";
}


int main()
{
	//declare variables
	int n = 8, m = 7, nodeValue;
	LinkedList list1, list2, list3;
	cout << "Enter Number of nodes in list 1 : ";		//user is asked to enter number of nodes
	cin >> n;											//getting the user input
	cout << "Enter List 1 Values : ";

	//creating the linked list 1
	for (int i = 0; i < n; i++)
	{
		cin >> nodeValue;
		list1.insertEnd(nodeValue);
	}
	list1.checkDuplicate(1);

	if (list1.checkDuplicate(1) == 0)
	{
		cout << "\nThere are duplicate values in list 1 !!!\n\n";
		system("pause");
		return 0;
	}
	cout << endl;

	cout << "Enter Number of nodes in list 2 : ";		//user is asked to enter number of nodes
	cin >> m;											//getting the user input

	cout << "Enter List 2 Values : ";
	//creating the linked list 2
	for (int i = 0; i < m; i++)
	{
		cin >> nodeValue;
		list2.insertEnd(nodeValue);
	}
	list2.checkDuplicate(2);

	if (list2.checkDuplicate(2) == 0)
	{
		cout << "There are duplicate values in list 2" << " !!!\n\n";
		system("pause");
		return 0;
	}
	cout << endl ;

	cout << "\tLinked List 1 -> ";
	list1.print();		//print initial list 1
	cout << endl;
	cout << "\tLinked List 2 -> ";
	list2.print();		//print initial list 2
	cout << endl << endl;

	cout << endl;

	cout << "Common values to both lists : ";
	list3.findCommon(list1, list2);		
	list3.print();		//print common values list
	cout << endl << endl;;

	system("pause");
	return 0;
}