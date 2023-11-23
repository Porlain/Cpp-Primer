/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-20 19:09:32
 */
#include <iostream>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;

struct destination
{
    string ip;
    int port;
    destination(string ips, int ports) : ip(ips), port(ports) {}
};

struct connection
{
    string ip;
    int port;
    connection(string ips, int ports) : ip(ips), port(ports) {}
};

connection connect(destination *des)
{
    shared_ptr<connection> con(new connection(des->ip, des->port));
    cout << "creating connection(" << con.use_count() << ")" << endl;
    return *con;
}

void disconnect(connection connect)
{
    cout << "connection close(" << connect.ip << ":" << connect.port << ")" << endl;
}

void function(destination &des)
{
    connection conn = connect(&des);
    shared_ptr<connection> p(&conn, [](connection *p)
                             { return disconnect(*p); });
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main()
{
    destination dest("202.118.176.67", 3316);
    function(dest);

    return 0;
}