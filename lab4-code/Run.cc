#include "Run.h"
using namespace std;


void run_code(string folder, string file, vector<string> &Sample){
    string mid = folder + "/" + file.substr(0,file.length()- 4) + ".o";
    string Com = "g++ " + folder + "/" + file + " -o " + mid; 
    system(Com.c_str());
    for(int i = 0; i<samples;i++){
        string CurIn = folder + "/" + Sample[i];
        string CurOut = folder + "/_"+ to_string(i)+"_"+ file; //.substr(0,file.length()- 4)
        string cmd = mid + " 0< " + CurIn + " 1> "+CurOut ;
        system(cmd.c_str());
    }
    string clear_cmd = "rm -f " + mid;
    system(clear_cmd.c_str());

    return;
}

int pd(string file){
    if(file == "stdin_format.txt") return 2;
    for(int i =0;i<samples;i++){
        if("/"+ file == dataprefix + to_string(i))return 0;
        if(file[0] == '_') return 3; //临时文件
    }
    return 1;
}



int Run(){
    vector<string> Folders;
    //printf("s\n");
    vector<string> CurFiles;
    Ran_in();
    GetFileName(path, Folders);
    //cout<<Folders[1]<<endl;
    
    for(int i = 0;i<Folders.size();i++){
        vector<string> List;
        if(Folders[i][0]!= '.'){
            string CurFolder = path + "/" + Folders[i];
            cout<<CurFolder<<endl;
            GetFileName(CurFolder ,CurFiles);
            vector<string> CurSamples;
            for(int j = 0; j < CurFiles.size(); j++){
                if(pd(CurFiles[j])==0) CurSamples.push_back(CurFiles[j]);
                if(pd(CurFiles[j])==1) List.push_back(CurFiles[j]);
            }
            for(int j = 0; j < CurFiles.size(); j++){
                if(pd(CurFiles[j])==1) {
                    run_code(CurFolder, CurFiles[j], CurSamples);  // 中间不带‘/’
                }
            }
            int tmp =  List.size();
            for(int j = 0;j < List.size() ; j++){
                for(int k = j+1; k < List.size(); k++){
                    string file1 = "input/" + Folders[i] +"/" + List[j];
                    string file2 = "input/" + Folders[i] +"/" + List[k];
                    if( result(CurFolder, List[j], List[k]) == 1 ){
                        freopen((outpath1).c_str(), "a", stdout);
                        printf("%s , %s\n", file1.c_str(), file2.c_str());
                        fclose(stdout);
                        fflush(stdout);
                    } else{
                        freopen((outpath2).c_str(), "a", stdout);
                        printf("%s , %s\n", file1.c_str(), file2.c_str());
                        fclose(stdout);
                        fflush(stdout);
                    }
                }
            }
            for(int j = 0; j<samples;j++){
                string clear_cmd = "rm -f " + CurFolder+"/"+CurSamples[j];
                if(delete_random_in_data == 1) system(clear_cmd.c_str());
            }
            CurFiles.clear();
            CurSamples.clear();
        }
    }


    return 0;
}