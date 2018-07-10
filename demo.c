#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int construct(int cn,int fidx,int lidx,int base_idx, vector<int> &base, vector<int> &check, vector<string> &vs, vector<int> &code){
    vector<char> cset;
    vector<int> cset_idx;
    cset.push_back(code[vs[fidx][cn]]);
    cset_idx.push_back(fidx);
    if(base_idx>= 20) return 0; 
    printf("base: %d, cn: %d fidx: %d, lidx: %d\n", base_idx, cn, fidx, lidx);
    for(int i=1; i< base.size(); i++) printf("%2d ", i);
    cout << endl;
    for(int i=1; i< base.size(); i++) printf("%2d ", base[i]);
    cout << endl;
    for(int i=1; i< base.size(); i++) printf("%2d ", check[i]);
    cout << endl << endl;

    // making next character set.
    for(int i=fidx+1;i <= lidx; i++){
        if(vs[i-1][cn]!=vs[i][cn]){
            cset.push_back(code[vs[i][cn]]);
            cset_idx.push_back(i);
        }
    }
    cset_idx.push_back(lidx+1);

    int bs = 1;
    while(1){
        bool flag = true;        
        for(int i=0;i<cset.size(); i++){
            if(bs + cset[i] > base.size() - 1) break;
            if(base[bs + cset[i]] != 0 || bs + cset[i] == base_idx){
                flag = false;
                break;
            }
        }
        if(flag){
            if(bs + cset[cset.size() -1] >  base.size() - 1){
                base.resize(bs + cset[cset.size()-1] + 1, 0);
                check.resize(bs + cset[cset.size()-1] + 1, 0);
            }
            break;
        }else{
            bs++;
        }
    }
    
    base[base_idx] = bs;
    for(int i=0; i < cset.size();i++)   check[bs + cset[i]] = base_idx;
    
    if(cset[0]==1){
        base[bs + cset[0]] = - (fidx+1);
        for(int i=1;i<cset.size(); i++){
            construct(cn+1, cset_idx[i], cset_idx[i+1]-1, bs + cset[i], base, check, vs,code); 
        }
    }else{
        for(int i=0;i<cset.size(); i++){
            construct(cn+1, cset_idx[i], cset_idx[i+1]-1, bs + cset[i], base, check, vs,code); 
        }
    }

    return 0;
}

int main(){

    int n; 
    /*
    cin >> n;
    vector<string> vs(n);
    for(int i=0;i<n;i++) cin >> vs[i];
    */
//    sort(vs.begin(),vs.end());
    vector<string> vs(3);
    vs[0] = "bird#";
    vs[1] = "bison#";
    vs[2] = "cat#";
    for(int i=0;i<3;i++) cout << vs[i] << endl;
    
    // multikey quick sort is more desarable from the view point of speed than STL quick sort.
    vector<int> base(2), check(2),code(256);
    code['#'] = 1;
    code['a'] = 2;
    code['b'] = 3;
    code['c'] = 4;
    code['d'] = 5;
    code['i'] = 6;
    code['n'] = 7;
    code['o'] = 8;
    code['r'] = 9;
    code['s'] = 10;
    code['t'] = 11;


    base[1] = 1;
    check[1] = 0;
    construct(0, 0, vs.size()-1, 1, base, check, vs, code);

    for(int i=1; i<= 14; i++) printf("%2d ", i);
    cout << endl;
    for(int i=1; i<= 14; i++) printf("%2d ", base[i]);
    cout << endl;
    for(int i=1; i<= 14; i++) printf("%2d ", check[i]);
    cout << endl;

    return 0;
}