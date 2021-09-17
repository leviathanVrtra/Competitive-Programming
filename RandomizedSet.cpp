// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    unordered_map<int, int>IdxMap;
    vector<int>dB;
    
    RandomizedSet() {
        IdxMap.clear();
        dB.clear();
    }
    
    bool insert(int val) {
        if (IdxMap.find(val) != IdxMap.end()) {
            return false;
        }
        
        dB.push_back(val);
        IdxMap[val] = dB.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if (IdxMap.find(val) == IdxMap.end()) {
            return false;
        }
        
        int last = dB[dB.size() - 1];
        IdxMap[last] = IdxMap[val];
        dB[IdxMap[val]] = last;
        
        dB.pop_back();
        IdxMap.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int val = dB[rand() % dB.size()];
        return val;
    }
};
