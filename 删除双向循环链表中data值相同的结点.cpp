#include <iostream>  
#include <time.h>  
typedef int datatype;  
using namespace std;  


typedef struct node
{
	datatype data;
	struct node* front ,* next;
	
}Node;

Node* insertNode(Node* head,datatype val){
	Node *tmpNode = (Node*)malloc(sizeof(Node));
	tmpNode->data = val;
	
	if(head->next == head){
		head->next = tmpNode;
		head->front = tmpNode;
		tmpNode->next = head;
		tmpNode->front = head;
	}
	else{
		tmpNode->next = head->next;
		tmpNode->front = head;
		head->next->front = tmpNode;
		head->next = tmpNode;		
	}
	return head;
}

void initNode(Node *head)
{
	head->data = 0xFFFFFFFF;
	head->front  = head;
	head->next = head;
}

void printNode(Node *head)
{
	Node *p ;
	if(head->next == head)
	{
		cout<<"the list is empty"<<endl;
		
	}
	else
	{
		p = head->next;
		while(p != head)
		{
			cout<<"p->data"<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

Node* delNode(Node *head, Node *del){
	
	Node *pre, *next;
	pre = del->front;
	next = del->next;
	pre->next = next;
	next->front = pre;
	return next;
}

int DeleteSameNode(Node *pHeadA, Node *pHeadB){
	
	Node *pa, *pb, *tmp;
	int flag;
	if(pHeadA->next == pHeadA || pHeadB->next == pHeadB)
	{
		return 0;
	}
	else{
		pa = pHeadA->next;
		while(pa != pHeadA)
		{
			flag = 0;
			pb = pHeadB->next;
			while(pb != pHeadB)
			{
				if(pa->data == pb->data)
				{
					pb = delNode(pHeadB,pb);
					flag = 1;
					
				}
				else{
					pb = pb->next;
					
				}
			}
			if(flag)
			{
				cout<<"the same data is :"<<pa->data<<endl;
				tmp = pa->next;
				while(tmp != pHeadA)
				{
					if(tmp->data == pa->data)
					{
						tmp = delNode(pHeadA,tmp);
					}
					else
					{
						tmp = tmp->next;
					}
				}
				pa = delNode(pHeadA,pa);
			}
			else{
				pa = pa->next;
			}
		}
	}
	return 1;
}

int main()  
{  
    Node *pHeadA, *pHeadB;  
    pHeadA = (Node*)malloc(sizeof(Node));  
    pHeadB = (Node*)malloc(sizeof(Node));  
    srand(time(NULL));  
    initNode(pHeadA);  
    initNode(pHeadB);  
    int i;  
    for (i = 0; i < 10; i++)  
    {  
        pHeadA = insertNode(pHeadA, rand()%10);  
    }  
    for (i = 0; i < 10; i++)  
    {  
        pHeadB = insertNode(pHeadB, rand()%10);  
    }  
    printNode(pHeadA);  
    printNode(pHeadB);  
    cout << "After Delettion!" << endl;  
    DeleteSameNodes(pHeadA, pHeadB);  
    printNode(pHeadA);  
    printNode(pHeadB);  
    system("PAUSE");  
    return 0;  
}