#include <set>
#include <unordered_map>

class NumberContainers {
public:
    NumberContainers() : m_idxMap(), m_numsMap() {}

    void change(int index, int number) {
        if (m_idxMap.contains(index)) {
            auto old = m_idxMap[index];
            m_numsMap[old].erase(index);
            if (m_numsMap[old].empty()) {
                m_numsMap.erase(old);
            }
        }

        m_idxMap[index] = number;
        m_numsMap[number].insert(index);
    }

    int find(int number) {
        if (!m_numsMap.contains(number)) {
            return -1;
        }

        return *m_numsMap[number].begin();
    }

private:
    std::unordered_map<int, int> m_idxMap;
    std::unordered_map<int, std::set<int>> m_numsMap;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
