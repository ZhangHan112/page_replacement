#include "page.h"

void PAGE::FIFO(int mode){

    string s;
    switch (mode){
    case RANDOM:
        s = "Random.txt";
        break;
    case LOCALITY:
        s = "Locality.txt";
        break;
    case My_REF_STRING:
        s = "My_Ref_String.txt";
        break;

    default:
        break;
    }

    ifstream inputFile(s);
    int read=0;
    while(!inputFile.eof()){
        inputFile>>str[read];
        read++;
    }
    inputFile.close();

    cout << endl << "===============FIFO + " << s << "===============" << endl;

    ofstream output("FIFO.dat");
    for(int i=10;i<=100;i+=10){
        int page_fault = 0;
        MEM_REF ref = MEM_REF(i);
        int pos = 0;
        for(int iter=0;iter<times;iter++){
            bool flag = false;
            for(int j=0;j<i;j++){
                if(ref[j]==str[iter]) //hit
                    flag = true;
            }

            if(flag==false){
                page_fault++;
                ref[pos] = str[iter];
                pos = (pos+1)%i;  
            }
        }
        output << i << " " << page_fault << endl;
        cout << "Frame number = " << i << " ,page fault: " << page_fault << endl;
    }
    output.close();
}


void PAGE::Optimal(int mode){
    string s;
    switch (mode){
    case RANDOM:
        s = "Random.txt";
        break;
    case LOCALITY:
        s = "Locality.txt";
        break;
    case My_REF_STRING:
        s = "My_Ref_String.txt";
        break;

    default:
        break;
    }

    ifstream inputFile(s);
    int read=0;
    while(!inputFile.eof()){
        inputFile>>str[read];
        read++;
    }
    inputFile.close();

    cout << endl << "===============Locality + " << s << "===============" << endl;

    ofstream output("Optimal.dat");
    for(int i=10;i<=100;i+=10){
        int page_fault = 0;
        int cnt = 0;
        MEM_REF ref = MEM_REF(i);
        
        for(int iter=0;iter<times;iter++){
            bool flag = false;
            for(int j=0;j<i;j++){
                if(ref[j]==str[iter]){// hit
                    flag = true;
                    break;
                }
            } 
            if(flag==true)  continue;

            // miss
            page_fault++;
            bool empty = false; 

            for(int j=0;j<i;j++)
                if(ref[j]==0){
                    ref[j] = str[iter];
                    cnt++;
                    empty = true;
                    break;
                } 
            if(empty==true)
                continue;

            MEM_REF future_ued = MEM_REF(i);

            for(int j=0;j<i;j++){
                int count = 0;
                for(int find=iter;find<times;find++){
                    if(str[find]==ref[j]){
                        future_ued[j] = count;
                        break;
                    }
                    else
                        count++;
                }
                if(future_ued[j]==0)
                    future_ued[j] = count;
            }
            

            int max=0,pos=0;
            for(int j=0;j<i;j++)
                if(max<future_ued[j]){
                    max = future_ued[j];
                    pos = j;
                }

            ref[pos] = str[iter];
            
        }
        output << i << " " << page_fault << endl;
        cout << "Frame number = " << i << " ,page fault: " << page_fault << endl;
    }
    output.close();
}

void PAGE::My_Algo(int mode){
    string s;
    switch (mode){
    case RANDOM:
        s = "Random.txt";
        break;
    case LOCALITY:
        s = "Locality.txt";
        break;
    case My_REF_STRING:
        s = "My_Ref_String.txt";
        break;

    default:
        break;
    }

    ifstream inputFile(s);
    int read=0;
    while(!inputFile.eof()){
        inputFile>>str[read];
        read++;
    }
    inputFile.close();

    cout << endl << "===============My_Algo + " << s << "===============" << endl;

    ofstream output("My_Algo.dat");
    for(int i=10;i<=100;i+=10){
        int page_fault = 0;
        int cnt = 0;
        MEM_REF ref = MEM_REF(i);
        
        for(int iter=0;iter<times;iter++){
            bool flag = false;
            for(int j=0;j<i;j++){
                if(ref[j]==str[iter]){// hit
                    flag = true;
                    break;
                }
            } 
            if(flag==true)  continue;

            
            
            bool empty = false; 

            for(int j=0;j<i;j++)
                if(ref[j]==0){
                    ref[j] = str[iter];
                    cnt++;
                    empty = true;
                    break;
                } 
            if(empty==true)
                continue;

            // miss
            page_fault++;

            MEM_REF rank = MEM_REF(i);
            int cnt = i;
            
            for(int find=iter-1;cnt!=0;find--){
                for(int j=0;j<i;j++){
                    if(ref[j]==str[find]&&rank[j]==0){
                        rank[j] = cnt;
                        cnt--;
                        break;
                    }
                }
            }

            int ratio = i*0.05+1;



            for(int j=0;j<i;j++){
                if(rank[j]<=ratio){
                    ref[j] = str[iter];
                    break;
                }
            }

            
            
        }
        output << i << " " << page_fault << endl;
        cout << "Frame number = " << i << " ,page fault: " << page_fault << endl;
    }
    output.close();
}