class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int , int> m;
    RandomizedSet() {
       
    }
    bool insert(int val) {
        if(m.find(val) != m.end()){
            return false;
        }

        m[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()){
            return false;
        }
        int index = m[val];
        int last = arr.back();

        arr[index] = last;
        m[last] = index;

        arr.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int ind = rand() % arr.size();
        return arr[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
