#ifndef __PAGE_H__
#define __PAGE_H__

#include<iostream>
#include<vector>
#include<ctime>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

#define RANDOM 0
#define LOCALITY 1
#define My_REF_STRING 2

class PAGE{
typedef vector<int> MEM_REF;
    int range;
    int times;
    int ref_str;

    MEM_REF str;
    
    void Random();
    void Locality(float portion);
    void My_Ref_String();
    
    void FIFO(int mode);
    void Optimal(int mode);
    void Enhanced_Second_Chance(int mode);
    void My_Algo(int mode);

public:
   
    void Run();
    void Initialize();
    PAGE(int Mem_Ref_Range, int Ref_Times, int Ref_String);

};

#endif
