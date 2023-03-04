#ifndef RECORD_HPP
#define RECORD_HPP

#include "Patient.hpp"

typedef Patient Record_Var;

class Rec_Node 
{
	public:
		Record_Var Data;
		int ID_int;
		Rec_Node *next;
		Rec_Node();
};


class Record 
{
	private:
	
		Rec_Node  *Head;
		int Size;
		int  Uniq_voidID(int Copy_ID);
	
	public:
	
		Record();
		void Add_voidElement(Record_Var Copy_Data, int Copy_intID);
		void Delete_voidElement(int Copy_intID);
		void GET_voidData(int Copy_intID, Record_Var *Copy_ptrData);
		void Clear_voidRecord(void);
		void Traverse_voidRecord(void(*func)(Record_Var));	
		void EDIT_voidRecord(int Copy_intID, Record_Var Copy_Newdata);
		int Check_intExsistance(int Copy_intID);
};

#endif
