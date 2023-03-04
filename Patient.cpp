#include <iostream>
#include "Patient.hpp"

void Patient::SET_voidName(char * Copy_ptrcharname)
{
    Name = Copy_ptrcharname;
}
void Patient::SET_voidGender(char * Copy_ptrcharGender)
{
    Gender = (char *)Copy_ptrcharGender;
}
void Patient::SET_voidAge(int Copy_intAge)
{
    Age = Copy_intAge;
}
void Patient::SET_voidSLOT(int Copy_ptrcharSlot)
{
	slot = Copy_ptrcharSlot;
}

char * Patient::Get_ptrcharName(void)
{
    return Name;
}
char * Patient::GET_ptrcharGender(void)
{
    return Gender;
}
int Patient::GET_intAge(void)
{
    return Age;
}
int  Patient::GET_intSLOT(void)
{
    return slot;
}

Patient::Patient():Name((char*)""),Gender((char*)""),Age(0),slot(0)
{

}