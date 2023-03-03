#include <iostream>
#include <stdlib.h>

#include "main.hpp"
#include "Record.hpp"

using namespace std;

void Display_voidElement(Patient Copy_Data);

string Doctor_ptrcharSlots[5][3] = { {"2PM","2:30PM","av"},
									 {"2:30PM","3PM","av"},
									 {"3PM","3:30PM","av"},
									 {"4PM","4:30PM","av"},
									 {"4:30PM","5PM","av"} };

int main(void)
{
	int mode_value = 0;
	int Pass_Word = 0;
	int Common_Iterator = 0;
	
	Patient P_1;
	Record Clinic_Record;
	
	char P_ptrcharName[20];
	char P_ptrcharGender[20];

	int P_intAge;
	int P_intID;
	int P_ptrcharslot = 0;;
	
	cout<<"1-Admin 2-User \n please Choose mode: ";
	cin>>mode_value;
	if(mode_value==ADMIN_MODE)
	{
		for(Common_Iterator =0;Common_Iterator<3;Common_Iterator++)
		{
				cout<<"please Enter Password: ";
				cin>>Pass_Word;
				if(Pass_Word == CORRECT_PASS_WORD )
				{
					cout<<"Welcome\n";
					cout<<"Which operation would you like to do?\n";
					cout<<"1-Add new Patient \n";
					cout<<"2-Edit Patient Record\n";
					cout<<"3-Reserve a slot with the Doctor\n";
					cout<<"4-Cancel Reservation\n";
					cout<<"5-Display Records.\n";
					cout<<"please choose operation: ";
					cin>>Common_Iterator;
					
					switch (Common_Iterator)
					{
						case ADD_NEW:
							cout<<"please enter patient's name:";
							cin>>P_ptrcharName;
							cout<<"please enter patient's gender:";
							cin>>P_ptrcharGender;
							cout<<"please enter patient's age:";
							cin>>P_intAge;
							cout<<"please enter patient's ID:";
							cin>>P_intID;
							
							P_1.SET_voidName(P_ptrcharName);
							P_1.SET_voidGender(P_ptrcharGender);
							P_1.SET_voidAge(P_intAge);
							//P_1.SET_voidSLOT(0);
							Clinic_Record.Add_voidElement(P_1,P_intID);
						
							break;
						case EDIT_RECORD:
							cout<<"please enter patient's ID:";
							cin>>P_intID;
							if( Clinic_Record.Check_intExsistance(P_intID) )
							{
								cout<<"please enter patient's name:";
								cin>>P_ptrcharName;
								cout<<"please enter patient's gender:";
								cin>>P_ptrcharGender;
								cout<<"please enter patient's age";
								cin>>P_intAge;
								
								P_1.SET_voidName(P_ptrcharName);
								P_1.SET_voidGender(P_ptrcharGender);
								P_1.SET_voidAge(P_intAge);
							
								Clinic_Record.EDIT_voidRecord(P_intID,P_1);
							}else
							{
								cout<<"ID is not Existed\n";	
							}
							break;
						case RESERVE_SLOT:
							cout<<"please enter patient's ID:";
							cin>>P_intID;
							if(Clinic_Record.Check_intExsistance(P_intID))
							{
									for(Common_Iterator=0;Common_Iterator<5;Common_Iterator++)
									{
										if(Doctor_ptrcharSlots[Common_Iterator][2] == AVALIABLE_SLOT)
										{
											cout<<Common_Iterator+1<<"- Slot start at "<<Doctor_ptrcharSlots[Common_Iterator][0]<<" End at "<<Doctor_ptrcharSlots[Common_Iterator][1]<<endl;
										}
									}
									cout<<"please Choose Slot: ";
									cin>>P_ptrcharslot;
									Doctor_ptrcharSlots[P_ptrcharslot-1][2] = not_AVALIABLE_SLOT;

									Clinic_Record.GET_voidData(P_intID, &P_1);
									P_1.SET_voidSLOT(P_ptrcharslot);
									Clinic_Record.EDIT_voidRecord(P_intID,P_1);

							}else
							{
								cout<<"ID is not Existed\n";
							}
							break;
						case CANCEL_SLOT:
							cout<<"please enter patient's ID: ";
							cin>>P_intID;
							if(Clinic_Record.Check_intExsistance(P_intID))
							{
								Clinic_Record.GET_voidData(P_intID, &P_1);
								P_ptrcharslot = P_1.GET_intSLOT();

								Doctor_ptrcharSlots[P_ptrcharslot-1][2] = AVALIABLE_SLOT;

								P_1.SET_voidSLOT(0);
								Clinic_Record.EDIT_voidRecord(P_intID,P_1);
							}else
							{
								cout<<"ID is not Existed\n";
							}
							break;
						case DISPLAY_RECORDS:
							Clinic_Record.Traverse_voidRecord(Display_voidElement);
							break;
						
						
					}
				}else
				{
					cout<<"Wrong Password "<<(2-Common_Iterator)<<" tries left\n";
				}	
		}
		
	}else if(mode_value==USER_MODE)
	{
		cout<<"Welcome\n";
		cout<<"Which operation would you like to do?\n";
		cout<<"1-Display my Record \n";
		cout<<"2-Display Slots \n";
		cout<<"please choose operation: ";
		cin>>Common_Iterator;

		switch (Common_Iterator)
		{
			case DISPLAY_MY_RECORD:

				cout<<"Please enter your ID: ";
				cin>>P_intID;

				if(Clinic_Record.Check_intExsistance(P_intID))
				{
					Clinic_Record.GET_voidData(P_intID, &P_1);
					Display_voidElement(P_1);

				}else
				{
					cout<<"ID is not Existed\n";
				}
				
				break;
			
			case DISPLAY_SLOTS:

				cout<<"Please enter your ID: ";
				cin>>P_intID;

				if(Clinic_Record.Check_intExsistance(P_intID))
				{
					Clinic_Record.GET_voidData(P_intID, &P_1);
					for(Common_Iterator=0;Common_Iterator<5;Common_Iterator++)
					{
						if(Doctor_ptrcharSlots[Common_Iterator][2] == AVALIABLE_SLOT)
						{
							cout<<Common_Iterator+1<<"- Slot start at "<<Doctor_ptrcharSlots[Common_Iterator][0]<<" End at "<<Doctor_ptrcharSlots[Common_Iterator][1]<<"Avalable SLOT\n";
						}else{
							
							if( P_1.GET_intSLOT() == Common_Iterator )
							{

							}else
							{
								cout<<Common_Iterator+1<<"- Slot start at "<<Doctor_ptrcharSlots[Common_Iterator][0]<<" End at "<<Doctor_ptrcharSlots[Common_Iterator][1]<<"Reserved SLOT\n";
							}
						}
					}
					

				}else
				{
					cout<<"ID is not Existed\n";
				}

				break;
		}
	}
	
	return 0;
}

void Display_voidElement(Patient Copy_Data)
{
	cout<<"Patient's Name: "<<Copy_Data.Get_ptrcharName()<<endl;
	cout<<"Patient's Gender: "<<Copy_Data.GET_ptrcharGender()<<endl;
	cout<<"Patient's Age: "<<Copy_Data.GET_intAge();
	if(Copy_Data.GET_intSLOT() != 0)
	{
		cout<<"Patient's Slot: "<<Copy_Data.GET_intSLOT()<<endl;
	}else
	{
		cout<<"Patient did not reserve any slots\n";
	}
}