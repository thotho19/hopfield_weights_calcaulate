#include<iostream>
#include<vector>
using namespace std;
void binaryToBipolar(int x[][4]){
    for(int i=0 ; i<2 ; i++)
        for(int j=0; j<4 ; j++)
            if(x[i][j]==0)
                x[i][j]=-1;

}
void initWeight(int x[][4], int xT[][2]){
    int xT1; int xT2;
    for(int i=0 ; i<2 ; i++)
        for(int j=0; j<4 ; j++)
            xT[j][i]=x[i][j];
    for(int i=0 ;i<4;++i)
    {
        for(int j=0 ; j<2;++j){
            if(j==0)
                xT1 = xT[i][j];
            if(j==1)
                xT2 = xT[i][j];
        }
        int temp = (xT1*1)+(xT2*1);
        if(temp <= 0 )
            temp = -temp;
        else{
            temp = -temp;
        }
        cout<<"T"<<i+1<<":"<<temp<<endl;
    }
}
void finalWeight(int x[][4]){
    int temp;
    vector<int> tempVector;
    vector<vector<int> > tempVector2;
    for(int i=0 ; i<2 ; ++i)
    {
        for(int j=0 ; j<4 ;++j)
        {   temp = x[i][j];
            for(int k=0 ; k<4 ;++k)
            {
                if(j!=k){
                    int temp1 = (temp*x[i][k]);
                    tempVector.push_back(temp1);
                }
            }
            tempVector2.push_back(tempVector);
            tempVector.erase(tempVector.begin(),tempVector.end());
        }
    }
    vector<vector<int> > part1;
    vector<vector<int> > part2;
    for(int i=0 ; i<tempVector2.size()-4 ; ++i)
            part1.push_back(tempVector2[i]);
    for(int i=4 ; i<tempVector2.size() ; ++i)
            part2.push_back(tempVector2[i]);
    vector<vector<int> > finalWeights;
    for(int i = 0 ; i<part1.size();++i)
        {
            for(int j = 0 ; j<part1[i].size();++j)
                {
                    cout<<"W"<<"="<<part1[i][j]+part2[i][j]<<" ";
                }
            cout<<endl;
        }
     
}
int main(){
    int x[2][4] = {
                   {0, 0, 1, 1},
                   {0, 1, 0, 1}
                   };
    int xT[4][2];
    binaryToBipolar(x);
    initWeight(x,xT);
    finalWeight(x);
    
    return 0;
}
