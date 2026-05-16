#include "hashing.h"

#include <array>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

string sha1_hex_upper(const string &input) {
    const auto left_rotate = [](uint32_t value, uint32_t bits) -> uint32_t {
        return (value << bits) | (value >> (32U - bits));
    };

    vector<uint8_t> message(input.begin(), input.end());
    const uint64_t bit_len = static_cast<uint64_t>(message.size()) * 8ULL;

    message.push_back(0x80U);
    while ((message.size() % 64U) != 56U) {
        message.push_back(0x00U);
    }

    for (int shift = 56; shift >= 0; shift -= 8) {
        message.push_back(static_cast<uint8_t>((bit_len >> shift) & 0xFFU));
    }

    uint32_t h0 = 0x67452301U;
    uint32_t h1 = 0xEFCDAB89U;
    uint32_t h2 = 0x98BADCFEU;
    uint32_t h3 = 0x10325476U;
    uint32_t h4 = 0xC3D2E1F0U;

    array<uint32_t, 80> w{};

    for (size_t chunk_start = 0; chunk_start < message.size(); chunk_start += 64U) {
        for (size_t i = 0; i < 16U; ++i) {
            const size_t j = chunk_start + i * 4U;
            w[i] = (static_cast<uint32_t>(message[j]) << 24U) |
                   (static_cast<uint32_t>(message[j + 1U]) << 16U) |
                   (static_cast<uint32_t>(message[j + 2U]) << 8U) |
                   static_cast<uint32_t>(message[j + 3U]);
        }
        for (size_t i = 16U; i < 80U; ++i) {
            w[i] = left_rotate(w[i - 3U] ^ w[i - 8U] ^ w[i - 14U] ^ w[i - 16U], 1U);
        }

        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;

        for (size_t i = 0; i < 80U; ++i) {
            uint32_t f = 0;
            uint32_t k = 0;

            if (i < 20U) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999U;
            } else if (i < 40U) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1U;
            } else if (i < 60U) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDCU;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6U;
            }

            const uint32_t temp = left_rotate(a, 5U) + f + e + k + w[i];
            e = d;
            d = c;
            c = left_rotate(b, 30U);
            b = a;
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    ostringstream out;
    out << uppercase << hex << setfill('0');
    out << setw(8) << h0
        << setw(8) << h1
        << setw(8) << h2
        << setw(8) << h3
        << setw(8) << h4;
    return out.str();
}
