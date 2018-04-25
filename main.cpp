#include <bits/stdc++.h>

using namespace std;

map <char , int> k;
map <int , char> k2;
long double f[1000], l[1000], u[1000] , td , tag, mi;
ifstream inFile;
vector <string> input;
string choice , s, choice2, output = "";
stringstream ss;
int n, ti, x, p = 1, st, kl, m;

void encode(){
    for(int i = 0 ; i<(int) input.size() ; i++){
        for(int j = 0 ; j<(int) input[i].size() ; j++){

            x = k[input[i][j]];//get x of that character //x is where that character is in the set

            l[p] = l[p-1] + (u[p-1] - l[p-1])*f[x-1];
            u[p] = l[p-1] + (u[p-1] - l[p-1])*f[x];

            //scaling
            while(((l[p] <= 0.5) && (u[p] <= 0.5)) || ((l[p] > 0.5) && (u[p] > 0.5))){
                if((l[p] <= 0.5) && (u[p] <= 0.5)){
                    output += '0';
                    l[p] *= 2.0;
                    u[p] *= 2.0;
                }
                else{
                    output += '1';
                    l[p] = 2.0*(l[p] - 0.5);
                    u[p] = 2.0*(u[p] - 0.5);
                }
            }
            p++;
        }
    }
    output += "1000000000000000000000000000000000";
}

void decode(){
    /*mi = 2.0;
    foor(i,0,n)//getting the minimum difference between two consecutive accumulative functions
        mi = min(mi , f[i+1] - f[i]);
    kl = ceil(-log2(mi));//getting k which is the word length*/

    while(p <= m){
            mi = 0.5;//power of two

            //read k bit and calculate their value
            tag = 0;
            for(int i = st ; i<(int) input[0].size() ; i++){
                if(input[0][i] == '1')
                    tag += mi;
                mi /= 2.0;
            }


            //find the correct value of x
            for(int i = 1 ; i<n+1 ; i++){
                l[p] = l[p-1] + (u[p-1] - l[p-1])*f[i-1];
                u[p] = l[p-1] + (u[p-1] - l[p-1])*f[i];
                if(tag <= u[p] && tag >= l[p]){
                    output += k2[i];//adding the correct character to the output
                    break;
                }
            }

            if(p == m)//if the word is finished
                break;

            //scaling
            while(((l[p] <= 0.5) && (u[p] <= 0.5)) || ((l[p] > 0.5) && (u[p] > 0.5))){
                if((l[p] <= 0.5) && (u[p] <= 0.5)){
                    l[p] *= 2.0;
                    u[p] *= 2.0;
                }
                else{
                    l[p] = 2.0*(l[p] - 0.5);
                    u[p] = 2.0*(u[p] - 0.5);
                }
                st++;//shift 1 bit
            }
            p++;
    }

}


int main()
{
    u[0] = 1.0;
    //determine the choice of user
    cout<<"What do you want ?\n\t1-Encode\n\t2-decode\n";
    cin>>choice;
    while(choice != "1" && choice != "2"){
        cout<<"Invalid Choice\n";
        cout<<"What do you want ?\n\t1-Encode\n\t2-decode\n";
        cin>>choice;
    }

    //determine if he will give us the probabilities or accumulative functions
    cout<<"Fine.\nWhat do you have ?\n\t1-probabilities\n\t2-accumulative functions\n";
    cin>>choice2;
    while(choice2 != "1" && choice2 != "2"){
        cout<<"Invalid Choice\n";
        cout<<"What do you have ?\n\t1-probabilities\n\t2-accumulative functions\n";
        cin>>choice2;
    }



    //reading the set
    inFile.open("set.txt");

    //read characters
    getline(inFile , s);
    for(int i = 0 ; i<(int) s.size() ; i++){
        if(k[s[i]] || s[i] == ' ')
            continue;
        k[s[i]] = ++n;
        k2[n]  = s[i];
    }

    //read probabilities or accumulative functions
    getline(inFile , s);
    ss<<s;
    while(ss>>td){
        f[++ti] = td;
        if(choice2 == "1")
            f[ti] += f[ti-1];
    }

    inFile.close();

    //for(auto it : k)
    //    cout<<it.ff<<" "<<it.ss<<ndl;

    //cout<<ndl;

    //foor(i,0,n+1)
    //    cout<<i<<" "<<f[i]<<ndl;

    //reading the input
    inFile.open("input.txt");
    if(choice == "2"){//if decode then it reads the number of characters first and stores it at m
        getline(inFile , s);
        ss.clear();
        ss<<s;
        ss>>m;
    }


    while(getline(inFile , s)){
        input.push_back(s);
        if(choice == "2")//if decode then it is only one line
            break;
    }

    inFile.close();

    freopen("output.txt", "w", stdout);

    if(choice == "1"){
        encode();
        cout<<output;
    }
    else{
        decode();
        cout<<output;
    }

    return 0;
}
