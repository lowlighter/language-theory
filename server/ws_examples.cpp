#include "server_ws.hpp"
#include "client_ws.hpp"

using namespace std;

typedef SimpleWeb::SocketServer<SimpleWeb::WS> WsServer;
typedef SimpleWeb::SocketClient<SimpleWeb::WS> WsClient;

int main() {
    WsServer server(8080, 1);

    auto& echo=server.endpoint["^/echo/?$"];

    echo.onmessage=[&server](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {

        auto message_str=message->string();

        cout << "Server: Message received: \"" << message_str << "\" from " << (size_t)connection.get() << endl;

        cout << "Server: Sending message \"" << message_str <<  "\" to " << (size_t)connection.get() << endl;

        auto send_stream=make_shared<WsServer::SendStream>();
        *send_stream << message_str;
        server.send(connection, send_stream, [](const boost::system::error_code& ec){
            if(ec) {
                cout << "Server: Error sending message. " << "Error: " << ec << ", error message: " << ec.message() << endl;
            }
        });
    };

    echo.onopen=[](shared_ptr<WsServer::Connection> connection) {
        cout << "Server: Opened connection " << (size_t)connection.get() << endl;
    };

    echo.onclose=[](shared_ptr<WsServer::Connection> connection, int status, const string& /*reason*/) {
        cout << "Server: Closed connection " << (size_t)connection.get() << " with status code " << status << endl;
    };

    echo.onerror=[](shared_ptr<WsServer::Connection> connection, const boost::system::error_code& ec) {
        cout << "Server: Error in connection " << (size_t)connection.get() << ". " <<
                "Error: " << ec << ", error message: " << ec.message() << endl;
    };

    return 0;
}
