#include <iostream>
#include <stdlib.h>

#include "Record.hpp"

using namespace std;


Rec_Node::Rec_Node():next(NULL)
{
	
}

Record::Record()
{
	Head = NULL;
	Size = 0;
}
void Record::Add_voidElement(Record_Var Copy_Data, int Copy_intID)
{
		Copy_intID = Record::Uniq_voidID(Copy_intID);
		Rec_Node *New_Node = (Rec_Node *)malloc(sizeof(Rec_Node));
		
		New_Node->Data = Copy_Data;
		New_Node->ID_int = Copy_intID;
		
		if( Head == NULL )
		{
			Head = New_Node;

		}else
		{
			Rec_Node *temp = Head;

			while( temp->next != NULL )
			{
				temp = temp->next;
			}
			temp->next = New_Node;
		}

		New_Node->next = NULL; 
		Size++;
}

void Record::Delete_voidElement(int Copy_intID)
{
	Rec_Node *temp = Head;
	if( temp->ID_int == Copy_intID )
	{
		Head = Head->next;
		free(temp);
		
	}else
	{
		Rec_Node *temp_2 ;
		do
		{
			
			if( temp->next->ID_int != Copy_intID )
			{
				temp_2 = temp->next;
				temp->next = temp->next->next;
				free(temp_2);
				cout<<"Element is deleted\n";
				Size--;
				break;
			}
			else if( temp->next == NULL )
			{
				cout<<"ID is not exist.";
				break;
			}
			temp=temp->next;

		}while(temp != NULL);
	}
}
void Record::GET_voidData(int Copy_intID, Record_Var *Copy_ptrData)
{
		Rec_Node *temp = Head;
		while( temp != NULL )
		{
			if(temp->ID_int == Copy_intID)
			{
				*Copy_ptrData = temp->Data;
				cout<<"Data is Captured.\n";
				break;
			}
			temp = temp->next;
		}
		if( temp == NULL )
		{
			cout<<"ID is not exist.\n";
		}
}
int Record::Uniq_voidID(int Copy_ID)
{
		Rec_Node *temp = Head;
		while( temp!=NULL )
		{
			if( temp->ID_int == Copy_ID )
			{
				cout<<"ID is Reserved,try again\n";
				cout<<"please enter ID:";
				cin>>Copy_ID;
				temp = Head;
				continue;
			}
			temp = temp->next;
		}
		return Copy_ID;
}
void Record::Traverse_voidRecord(void(*func)(Record_Var))
{
		Rec_Node *temp = Head;
		int Counter = 0;
		while(temp != NULL)
		{
			cout<<Counter+1<<endl;
			(*func)(temp->Data);
			temp = temp->next;
		}
}

void Record::Clear_voidRecord(void)
{
		Rec_Node *temp = Head;
		
		while(temp!=NULL)
		{
			Head = Head->next;
			free(temp);
			temp = Head;
		}
		Size = 0;
}
void Record::EDIT_voidRecord(int Copy_intID, Record_Var Copy_Newdata)
{
	Rec_Node *temp = Head;
	
	while(temp!=NULL)
	{
		if(temp->ID_int == Copy_intID)
		{
			temp->Data = Copy_Newdata;
			break;			
		}
		temp=temp->next;
	}
}
int Record::Check_intExsistance(int Copy_intID)
{
	Rec_Node *temp = Head;
	while(temp != NULL)
	{
		if(temp->ID_int ==Copy_intID)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;

}