#include "page.h"


int main(int argc,char** argv){

    int Mem_Ref_Range = atoi(argv[1]);
    int Ref_Times = atoi(argv[2]);
    int Ref_String = atoi(argv[3]);

    PAGE x (Mem_Ref_Range, Ref_Times, Ref_String);
    x.Initialize();
    x.Run();
}