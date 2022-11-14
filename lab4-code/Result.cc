#include "Result.h"



int single_result(std::string f1, std::string f2){
    std::string str;
    vector<std::string> f1c,f2c;
    ifstream fin;
    fin.open(f1);
    cin.rdbuf(fin.rdbuf());
    while(cin>>str) { f1c.push_back(str); }
    fclose(stdin);
    ifstream fin2;
    fin2.open(f2);
    cin.rdbuf(fin2.rdbuf());
    while(cin>>str) { f2c.push_back(str); }
    fclose(stdin);
    if(f1c.size()!= f2c.size()){return 0;};
    for(int i = 0;i<f1c.size();i++){
        if(f1c[i]!= f2c[i]) return 0;
    }
    return 1;
}

int result(std::string path,std::string f1,std::string f2){
    for(int i = 0; i<samples; i++){
        std::string f1p = path + "/_" +to_string(i) + "_" +f1;
        std::string f2p = path + "/_" +to_string(i) + "_" +f2;
        if(single_result(f1p,f2p) == 0) return 0;
    }
    return 1;
}