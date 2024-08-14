class Solution {
public:
    bool ispossible(int i, vector<int>& gas, vector<int>& cost){
        int x = gas.size();
        int tank = 0;
        for(int j = i;j <i+x; j++){
            tank += (gas[j%x] - cost[j%x]);
            if(tank<0) return false;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1){
            if(gas[0]>=cost[0]) return 0;
            else return -1;
        }
        for(int i = 0;i< gas.size();i++){
            if(gas[i]>cost[i]){
                if(ispossible(i,gas,cost)) return i;
            }
        }
        return -1;
    }
};