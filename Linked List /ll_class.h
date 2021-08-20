using namespace std;

class Node
{
	public:
		int data;
		Node *next;

		Node(int data)
		{
			this -> data = data;
			this -> next = NULL;
		}

};

/*********************************************************************************************************/
	void print(Node *head)
	{
		if (!head)
			return;

		Node* temp = head;
		while (temp)
		{
			cout << temp -> data << " ";
			temp = temp -> next;
		}
		cout << endl;
	}
	/*********************************************************************************************************/
		int length(Node* head)
		{
			if (!head)
				return 0;

			Node *temp = head;
			int len = 0;
			while (temp)
			{
				temp = temp -> next;
				len++;
			}
			return len;
		}
	/*********************************************************************************************************/
		Node* takeInput()
		{
			int data;
			cin >> data;
			Node *head = NULL;
			Node *tail = NULL;

			while (data != -1)
			{
				Node *newnode = new Node(data);

				if (head == NULL)
				{
					head = newnode;
					tail = newnode;
				}
				else
				{
					tail -> next = newnode;
					tail = newnode;
				}
				cin >> data;
			}
			return head;
		}
	/***************************************************************************************************************/
	Node* deleteNode(Node* head, int i)
	{
		Node *temp = head;
		if (i == 0)
		{
			if (!head)
			{}
			else
			{
				head = head -> next;
				delete temp;
			}
			return head;
		}

		int j = 0;
		while (j < i - 1 && temp) //j < i - 1...in 1,2,3,4,5...we want to delete 4(3)...so we need to reach 3(2)
		{	//but for j = 0 we will reach the second node...so j < i - 1 and not j < i.
			temp = temp -> next;
			j++;
		}

		if (temp) //we reached an existing node
		{
			if (temp -> next)
			{
				Node *temp2 = temp -> next;
				Node *temp3 = temp2 -> next;
				temp -> next = temp3;
				delete temp2;
			}
			else
				temp = NULL;
		}
		return head;
	}
/***************************************************************/
	Node* deleteNodeRec(Node *head, int i)
	{
		if (!head)
			return head;
		if (i == 0)
		{
			Node *temp = head;
			head = head -> next;
			delete temp;
		}
		else
		{
			Node *rec = deleteNodeRec(head -> next, --i);
			head -> next = rec;
		}
		return head;
	}
/**************************************************************************************************************/
	Node *insertNodeRec(Node* head, int data, int i)
	{
		if (!head)
			return head;
		if (i == 0)
		{
			Node *newnode = new Node(data);
			newnode -> next = head;
			head = newnode;
		}
		else
		{
			Node *rec = insertNodeRec(head -> next, data, --i);
			head -> next = rec;
		}
		return head;
	}
/***************************************************************************************************************/
	Node *mid(Node *head)
	{
		if(!head)
			return NULL;
		
		Node *fast = head;
		Node *slow = head;

		while(fast -> next && fast -> next -> next)
		{
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		return slow;
	}
/****************************************************************************************************************/
Node *reverse(Node *head)
{
	if(!head || !head -> next)
		return head;

	Node *rec = reverse(head -> next);
	head -> next -> next = head;
	head -> next = NULL;

	return rec;
}
