#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a,int rcount,int dcount,int score,int pointer){
    if(pointer>=a.size()){
        return score;
    }
    //try to ding
    int ding=0;
    int ring=0;
    if(dcount<3){
        int sc=0;
        if(a[pointer]<0){
            sc=abs(a[pointer]);
        }
        else{
            sc=a[pointer]*-1;
        }
        ding=solve(a,0,dcount+1,score+sc,pointer+1);
    }
    else{
        //ring always
        ring=solve(a,rcount+1,0,score+a[pointer],pointer+1);
    }

    //try for ring
    if(rcount<3){
        int sc=0;
        ring=solve(a,rcount+1,0,score+a[pointer],pointer+1);
    }
    else{
        int sc=0;
        if(a[pointer]<0){
            sc=abs(a[pointer]);
        }
        else{
            sc=a[pointer]*-1;
        }
        ding=solve(a,0,dcount+1,score+sc,pointer+1);
    }
    score=max(ding,ring);
    return score;
}

int main() {
    // Example usage
    vector<int> A = {-10 ,-20, -30, -40, -50, -60, -70 ,-80, -90, -100, -110, -120 ,-130, -140, -150};
    int result = solve(A,0,0,0,0);

    cout << "The largest number of chickens earned by Mr. Fox is: " << result << endl;

    return 0;
}
 