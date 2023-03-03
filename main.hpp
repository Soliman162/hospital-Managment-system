#ifndef MAIN_HPP
#define MAIN_HPP


using namespace std;


#define CORRECT_PASS_WORD   1234
#define ADMIN_MODE  1
#define USER_MODE   2

#define AVALIABLE_SLOT			"av"
#define not_AVALIABLE_SLOT		"notav"

#define DISPLAY_MY_RECORD      1
#define DISPLAY_SLOTS          2


#define ADD_NEW			1
#define EDIT_RECORD		2
#define	RESERVE_SLOT 	3
#define CANCEL_SLOT		4
#define DISPLAY_RECORDS 5


class Patient 
{
    private:
        char *  Name;
        char *  Gender;
        int  Age;
        int slot;
    public:

       
        void SET_voidName(char * Copy_ptrcharname);
        void SET_voidGender(char * Copy_ptrcharGender);
        void SET_voidAge(int Copy_intAge);
        void SET_voidSLOT(int Copy_ptrcharSlot);

        char * Get_ptrcharName(void);
        char * GET_ptrcharGender(void);
        int GET_intAge(void);
        int GET_intSLOT(void);

        Patient();
};
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



#endif
