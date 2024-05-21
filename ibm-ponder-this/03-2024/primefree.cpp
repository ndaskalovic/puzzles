#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
 
constexpr size_t N = 200000000;


// save a bitset to a file for repeat use
template<size_t N>
void saveBitsetToFile(const std::bitset<N>& bits, const std::string& filename) {
    std::ofstream outfile(filename, std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    size_t numBytes = (N + 7) / 8;
    std::vector<char> buffer(numBytes, 0);

    for (size_t i = 0; i < N; ++i) {
        if (bits[i]) {
            buffer[i / 8] |= (1 << (i % 8));
        }
    }

    outfile.write(buffer.data(), buffer.size());
    outfile.close();
}
template<size_t N>
std::bitset<N>* loadBitsetFromFile(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    size_t numBytes = (N + 7) / 8;
    std::vector<char> buffer(numBytes, 0);

    infile.read(buffer.data(), buffer.size());

    std::bitset<N>* bits = new std::bitset<N>();
    for (size_t i = 0; i < N; ++i) {
        if (buffer[i / 8] & (1 << (i % 8))) {
            bits->set(i);
        }
    }

    return bits;
}

std::bitset<N>* is_prime = new std::bitset<N>();
// This is for loading an already generated bitset
// std::bitset<N>* is_prime = loadBitsetFromFile<N>("is_prime.bin");

void sieve()
{
    is_prime->set();

    is_prime->set(0,0);
    is_prime->set(1,0);
    for (std::size_t i = 2; i * i < is_prime->size(); ++i)
    {
        if ((*is_prime)[i])
        {
            for (std::size_t j = i * i; j < is_prime->size(); j += i)
            {
                is_prime->set(j,0);
            }
        }
    }
}

bool isPrime(long unsigned int num) {
    if (num < 2) {
        return false;
    }
    for (long unsigned int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void find_a0(long n, long start = 1)
{
    size_t sequence[n];
    sequence[0] = 0;

    for (size_t i = 1; i < n; i++)
    {
        sequence[i] = sequence[i - 1] + i;
    };

    std::cout << "-> Finding a0 for n: " << n << '\n';
    int largest_sequence = 0;
    int delta = ((n-1) * n) / 2;

    for (size_t i = start; i < N-delta; i++)
    {
        if ((*is_prime)[i])
        {
            continue;
        }
        for (size_t j = 0; j < n; j++)
        {
            if ((*is_prime)[sequence[j]+i])
            {
                if (j > largest_sequence)
                {
                    largest_sequence = j;
                    std::cout << "-> Largest sequence so far: " << largest_sequence << " at a0: " << i << '\n';
                }
                break;
            } 
            else
            {
                if (j == n - 1)
                {
                    std::cout << "-> Found a0: " << i << '\n';
                    return;
                }
            }
        }
    };
    std::cout << "-> No a0 found for n: " << delta << '\n';;
}


int main()
{
    // compute the bitset up to N
    sieve();
    // saveBitsetToFile<N>(*is_prime, "is_prime.bin");
    find_a0(1000);
}