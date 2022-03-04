#include <iostream>
#include <map>
#include <vector>
#include <utility>

void thin_out(std::map<int, int> &sequence, unsigned n)
{
    if (n < 3) {
        std::cout << "n must be at least 3" << std::endl;
        return;
    }

    unsigned sub_length{0};
    int dot_key = sequence.cbegin()->first;
    int dot_value = sequence.cbegin()->second;

    for (auto &it : sequence) {
        if (it.second == dot_value) {
            ++sub_length;

            if (it.first != sequence.rbegin()->first) {
                continue;
            }
        }

        // End of subsequence reached
        if (sub_length > 1) {
            for (int i = 2; i < sub_length; ++i) {
                if (i % n) {
                    sequence.erase(dot_key - 1 + i);
                }
            }

            sub_length = 1;
        }

        dot_key = it.first;
        dot_value = it.second;
    }
}

void output(std::map<int, int> &sequence)
{
    for (auto &it : sequence) {
        std::cout << "(" << it.first << ", " << it.second << ")" << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::map<int, int> seq;

    seq.emplace(1, 10);
    seq.emplace(2, 11);
    seq.emplace(3, 11);
    seq.emplace(4, 11);
    seq.emplace(5, 11);
    seq.emplace(6, 11);
    seq.emplace(7, 11);
    seq.emplace(8, 11);
    seq.emplace(9, 9);
    seq.emplace(10, 11);
    seq.emplace(11, 11);
    seq.emplace(12, 11);
    seq.emplace(13, 11);
    seq.emplace(14, 11);
    seq.emplace(15, 11);
    seq.emplace(16, 11);
    seq.emplace(17, 11);
    seq.emplace(18, 11);
    seq.emplace(19, 10);

    std::cout << "Before thinning out:" << std::endl;
    output(seq);

    thin_out(seq, 4);

    std::cout << "After:" << std::endl;
    output(seq);


    return 0;
}
