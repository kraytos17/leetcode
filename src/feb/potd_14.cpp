#include <cstdint>
#include <deque>

class ProductOfNumbers {
public:
    ProductOfNumbers() : m_stream(), m_prod(1) {}

    void add(int num) {
        m_stream.push_back(num);
        m_prod *= num;
        if (m_stream.size() > m_k) {
            auto removed = m_stream.front();
            m_prod /= removed;
        }
    }

    int getProduct(int k) { return m_stream.size() < k ? -1 : m_prod; }

private:
    std::deque<int> m_stream;
    int64_t m_prod{1};
    int m_k;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
