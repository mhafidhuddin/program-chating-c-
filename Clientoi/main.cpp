//program client
#include <iostream>
#include <conio.h>
#include <stdio.h>
//socket program
#include <winsock.h>
#include <windows.h>
#include <sstream>
#include <string>


using namespace std;

int main()
{
   SOCKET sock;//socket yang digunakan untuk mengirim ke client
   SOCKADDR_IN address;//address variabel alamat socket

    long ok;//variabel ok tipe data long
    char message[200];//variable untuk pesan chat

    WSADATA wsd;//data socket
    WORD dllversion;
    dllversion = MAKEWORD(2,1);
    ok = WSAStartup(dllversion, &wsd);//mengaktifkan winsock

    while (true)
    {
        //menghubungkan socket ke server
        sock = socket (AF_INET, SOCK_STREAM,NULL);//mengaktifkan socket
        address.sin_addr.s_addr = inet_addr("127.0.0.1");//ip server
        address.sin_family = AF_INET;//setting socket ke socket
        address.sin_port = htons(10102);//port


        connect(sock, (SOCKADDR*)&address, sizeof(address));
        string msg;//variabel pesan
        cout<<"masukkan pesan: \t";//isi pesan
        cin>>msg;
        const char* s = msg.c_str();//fungsi
        ok = send(sock,s,1024,NULL);//mengirim pesan ke server

        ok = recv(sock, message, sizeof(message),NULL);//menerima pesan dari server
        string reply;//variabel pesan server
        reply = message;//disamakan dengan data pesan
        cout <<"server says:\t"<<reply<<endl;//output pesan server
    }
}
