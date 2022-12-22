#include <iostream>
#include <ctime>


using namespace std;

struct Node
{
	char Data;
	Node* next_ptr;
};

void s_push(Node** top, char _data) 
{  
	Node* current_node; 
	current_node = new Node(); 
	current_node->Data = _data;
	if (top == NULL) 
	{ 
		*top = current_node; 
	}
	else
	{
		current_node->next_ptr = *top;
		*top = current_node;
	}
}

void s_delete_key(Node** top) 
{
	Node* current_node = *top;
	Node* prev_ptr = NULL;

	cout << "\nВведите ключ узла, который нужно удалить\n";
	char key;
	cin >> key;

	while (current_node != NULL) 
	{
		if (current_node->Data == key)
		{
			if (current_node == *top) 
			{
				*top = current_node->next_ptr;
				free(current_node);
				current_node->Data = NULL;
				current_node->next_ptr = NULL;
			}
			else
			{
				prev_ptr->next_ptr = current_node->next_ptr;
				free(current_node);
				current_node->Data = NULL;
				current_node->next_ptr = NULL;
			}
		}
		prev_ptr = current_node;
		current_node = current_node->next_ptr;
	}
}

void s_print(Node* top)
{ 
	Node* current_node = top;
	while (current_node) 
	{
		cout<<current_node->Data<<" ";
		current_node = current_node->next_ptr;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	cout << "Сколько узлов в стеке?\n";

	Node* top = NULL;
	int kolichestvo_el;
	
	cin >> kolichestvo_el;

	while (kolichestvo_el < 0)
	{
		cout << "Введите количество узлов >= 0\n";
		cin >> kolichestvo_el;
	}

	if (kolichestvo_el == 0)
	{
		cout << "\nСтек пуст\n";
	}
	else
	{	
		char data_uzla;

		for (int i = 1; i <= kolichestvo_el; i++)
		{
			cout << "\nВведите " << i << " элемент списка\n";
			cin >> data_uzla;

			s_push(&top, data_uzla);
		}

		cout << "\nСоздан список: \n";

		s_print(top);

	}
	s_delete_key(&top);

	cout << "Измененный стек: \n";
	s_print(top);

	return 0;
}
