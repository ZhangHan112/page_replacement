#include "page.h"

PAGE::PAGE(int Mem_Ref_Range, int Ref_Times, int Ref_String):
            range(Mem_Ref_Range),times(Ref_Times),ref_str(Ref_String){
    
    str = MEM_REF(times);
    srand(time(NULL));
}

void PAGE::Run(){

    FIFO(ref_str);
    Optimal(ref_str);
    My_Algo(ref_str);
}

void PAGE::Initialize(){
    Random();
    Locality(0.05);
    My_Ref_String();
}

void PAGE::Random(){
    ofstream file("Random.txt");
    for(int i=0;i<times;i++){
        int random = (int)(rand()%range)+1;
        file << random << endl;
    }
    file.close();
}

void PAGE::Locality(float portion){
    

    ofstream file("Locality.txt");

    int count=0;
    int len = portion*range;
    int start = 0;
    while(true){
        start = (int)(rand()%range)+1;

        for(int i=0;i<len;i++){
            if(count<times){
                int pos = rand()%len; 
                file << (start+pos)%range << " ";
                count++;
            }
            else
                break;     
        }
        
        if(count==times)
            break;   
    }
    file.close();

}

void PAGE::My_Ref_String(){

    ofstream file;
    file.open("My_Ref_String.txt");

    int count = 0;
    while(true){
        count++;
        int start = (rand()%range)+1;

        double random = (double) (rand()%RAND_MAX)/RAND_MAX;
        int len = random*range;
        int upper_bound = rand()%100+1;
        len = (len>1)?len:1;
        len = (len<upper_bound)?len:upper_bound;

        for(int i=0;i<len/2;i++){
            if(count<times){
                start++;
                file << start << " ";
                start = start%range;
                count++;
            }
            else
                break;     
        }
        for(int i=0;i<len/2;i++){
            if(count<times){
                file << start << " ";
                start--;
                start = (start==0)?range:start;
                count++;
            }
            else
                break;     
        }

        if(count==times)
            break;   
    }
    
    file.close();
}



