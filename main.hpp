#ifndef MAIN_HPP
#define MAIN_HPP

using namespace std;

#define NUMBER_OF_SLOTS     5

#define CORRECT_PASS_WORD   1234

#define ADMIN_MODE          1
#define USER_MODE           2

#define AVALIABLE_SLOT			"av"
#define not_AVALIABLE_SLOT		"notav"

/* User OP */
#define DISPLAY_MY_RECORD      1
#define DISPLAY_SLOTS          2

enum ADMIN_OP
{
    ADD_NEW =1 ,		
    EDIT_RECORD,		
    RESERVE_SLOT, 	
    CANCEL_SLOT	,	
    DISPLAY_RECORDS
};

#endif
