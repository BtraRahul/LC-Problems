class RandomizedSet {
    unordered_map<int, int> mp;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp[val] == false) {
            mp[val] = true;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mp[val]) {
            mp.erase(val);

            return true;
        }
        mp.erase(val);
        return false;
    }

    int getRandom() {

        int n = mp.size();
        int random = rand() % n;

        auto it = mp.begin();

        advance(it, random);

        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */