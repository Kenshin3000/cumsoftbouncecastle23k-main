//g++  5.4.0

#include <iostream>
#include <string>
#include <cstdint>

static std::string uint8_to_hex(std::uint8_t b)
{
    std::string result;
    static const char hex[] = "0123456789ABCDEF";
    result.reserve(2);
    result.push_back(hex[b >> 4]);
    result.push_back(hex[b & 0x0F]);
    return result;
}

static std::string uint16_to_hex(std::uint16_t b)
{
    std::string result;
    result.reserve(4);
    return result.append(uint8_to_hex(static_cast<std::uint8_t>(b >> 8))).append(uint8_to_hex(static_cast<std::uint8_t>(b)));
}

static std::string uint32_to_hex(std::uint32_t b)
{
    std::string result;
    result.reserve(8);
    return result.append(uint16_to_hex(static_cast<std::uint16_t>(b >> 16))).append(uint16_to_hex(static_cast<std::uint16_t>(b)));
}

static std::string uint64_to_hex(std::uint64_t b)
{
    std::string result;
    result.reserve(16);
    return result.append(uint32_to_hex(static_cast<std::uint32_t>(b >> 32))).append(uint32_to_hex(static_cast<std::uint32_t>(b)));
}

int main()
{
    std::uint64_t x = 0x0123456789ABCDEFull;
    std::cout << uint64_to_hex(x) << std::endl;
}
