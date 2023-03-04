#ifndef PATIENT_HPP
#define PATIENT_HPP

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

#endif