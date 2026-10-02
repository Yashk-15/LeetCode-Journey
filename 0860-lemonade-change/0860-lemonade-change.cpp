class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> change;
        change[5]=0;
        change[10]=0;
        change[20]=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                change[5]++;
            }else if(bills[i]==10){
                if(change[5]==0){
                    return false;
                }
                change[5]--;
                change[10]++;
            }else if(bills[i]==20){
                if(change[5]==0 || (change[10]==0 && change[5]<3)){
                    return false;
                }
                if(change[10]>0){
                    change[10]--;
                    change[5]--;
                }else if(change[5]>=3){
                    change[5]-=3;
                }
                change[20]++;
            }
        }
        return true;
    }
};