#include <iostream>
#include <bitset>
#include <vector>

using std::vector;
using std::bitset;

class solution {
  public:
    bool validUtf8(const vector<int> & data) {
        if (data.empty())
            return true;
        else {
            size_t idx = 0;
            bitset<8> curr(data[idx]);
            idx++;
            size_t numOfOnes = 0;
            for (size_t i = curr.size()-1; curr.size() > i && curr.test(i); i--)
                numOfOnes++;
            if (numOfOnes == 0)
                return true;
            else {
                vector<bitset<8>> rest;
                while (idx < data.size() && rest.size() < numOfOnes-1) {
                    rest.push_back(bitset<8>(data[idx++]));
                }
                if (idx == data.size()) {
                    std::cout << "Not enough numbers\n";
                    return false;
                }
                for (const auto & bset : rest)
                    if (bset[bset.size()-1] != 1 || bset[bset.size()-2] != 0) {
                        std::cout << bset << std::endl;
                        std::cout << "Not leading 10\n";
                        return false;
                    }
                vector<int> left(data.begin()+idx, data.end());
                return validUtf8(left);
            }
        }
    }
};

int main() {
    // std::vector<int> data{197,130,1};
    std::vector<int> data{235,140,4};
    
    solution soln;
    bool isValid = soln.validUtf8(data);
    std::cout << std::boolalpha
              << isValid << std::endl;
}
