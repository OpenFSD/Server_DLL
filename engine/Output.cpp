#include "Output.h"
#include <cstddef>


namespace Server_Library
{
    class Output_Control* Output::ptr_Control_Of_Output = NULL;
    int* Output::ptr_out_PraiseEventId = NULL;
    class Object* Output::praiseOutputBuffer_Subset = NULL;

    Output::Output()
    {
        praiseOutputBuffer_Subset = NULL;
        int* ptr_out_PraiseEventId = new int(0);
    }

    Output::~Output()
    {
        delete ptr_Control_Of_Output;
        delete praiseOutputBuffer_Subset;
        delete ptr_out_PraiseEventId;
    }

    void Output::Initialise_Control()
    {
        ptr_Control_Of_Output = new class Server_Library::Output_Control();
        while (ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
    }

    class Output_Control* Output::Get_Control_Of_Output()
    {
        return ptr_Control_Of_Output;
    }

    Object* Output::Get_OutputBuffer_Subset()
    {
        return praiseOutputBuffer_Subset;
    }

    int* Output::GetPraiseEventId()
    {
        return ptr_out_PraiseEventId;
    }

    void Output::Set_OutputBuffer_Subset(class Object* value)
    {
        praiseOutputBuffer_Subset = value;
    }

    void Output::SetPraiseEventId(int value)
    {
        ptr_out_PraiseEventId = &value;
    }
}
