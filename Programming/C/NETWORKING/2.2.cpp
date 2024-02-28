#include <iostream>
#include <string>
#include <sstream>
//#include <bitset>

void split(const std::string &s, char delimiter, std::string parts[4]) {
    std::string token;
    std::istringstream tokenStream(s);
    int i = 0;
    while (std::getline(tokenStream, token, delimiter)) {
        parts[i++] = token;
    }
}

int main() {
    std::string cidr;
    std::cout << "Enter CIDR notation: ";
    std::cin >> cidr;

    std::string ipAndMask[2];
    split(cidr, '/', ipAndMask);
    std::string ipParts[4];
    split(ipAndMask[0], '.', ipParts);

    unsigned int ip = 0;
    for (int i = 0; i < 4; ++i) {
        ip = (ip << 8) + std::stoi(ipParts[i]);
    }

    int mask = std::stoi(ipAndMask[1]);
    unsigned int maskBits = (1 << (32 - mask)) - 1;

    unsigned int network = ip & ~maskBits;
    unsigned int broadcast = network | maskBits;

    std::cout << "First IP: ";
    for (int i = 24; i >= 0; i -= 8) {
        std::cout << ((network >> i) & 0xFF);
        if (i != 0) std::cout << ".";
    }
    std::cout << "\n";

    std::cout << "Last IP: ";
    for (int i = 24; i >= 0; i -= 8) {
        std::cout << ((broadcast >> i) & 0xFF);
        if (i != 0) std::cout << ".";
    }
    std::cout << "\n";

    std::cout << "Total IPs: " << (broadcast - network + 1) << "\n";

    return 0;
}