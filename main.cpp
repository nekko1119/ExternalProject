#include <iostream>
#include <network/uri.hpp>

int main() {
    network::uri uri{"https://user@localhost:8080/123/path?query=value&query2=value2"};
    std::cout << uri.host() << std::endl;
    std::cout << uri.query() << std::endl;
    std::cout << uri.scheme() << std::endl;
    std::cout << uri.port() << std::endl;
}
