#include<iostream>
using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos + delimiter.length());
    }

    ret.push_back(input);
    return ret;
}

int main(void){

    string s = "단어1,단어2,단어3";
    string d = ",";
    vector<string> res = split(s,d);

    for(string s : res){
        cout << s << endl;
    }
    
}
