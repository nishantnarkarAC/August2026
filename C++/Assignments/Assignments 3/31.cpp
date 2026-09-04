#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// enum class definition
enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

//Type Aliases definitions
using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

// Function for Part A
void handleResponse(HttpStatus status, const string& endpoint) {
    cout << endpoint << "\n";
  switch (status) {
    case HttpStatus::OK:
        cout << static_cast<int>(status);
        break;
    case HttpStatus::Created:
        cout << static_cast<int>(status);
        break;
    case HttpStatus::BadRequest:
        cout << static_cast<int>(status);
        break;
    case HttpStatus::Unauthorized:
        cout << static_cast<int>(status);
        break;
    case HttpStatus::NotFound:
        cout << static_cast<int>(status);
        break;
    case HttpStatus::ServerError:
        cout << static_cast<int>(status);
        break;
}

}

// Function for Part B
void printHeaders(const HeaderList& headers) {
    cout << "Headers:\n";
    for (const auto& header : headers) {
        cout << header.first << " : " << header.second << "\n";
    }
}

int main() {
    // Testing Part A
    handleResponse(HttpStatus::OK, "GET /api/users");
    handleResponse(HttpStatus::Unauthorized, "POST /api/login");
    handleResponse(HttpStatus::NotFound, "GET /api/products/99");
    handleResponse(HttpStatus::ServerError, "POST /api/order");

    // Testing Part B
    RequestId reqId = 1748293847;
    Port serverPort = 8080;
    IPAddress clientIp = "192.168.1.10";

    HeaderList headers = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    cout << "Request ID : " << reqId << "\n";
    cout << "Server Port : " << serverPort << "\n";
    printHeaders(headers);

    return 0;
}