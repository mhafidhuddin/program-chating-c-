//program server
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
    SOCKET consock;//socket yang digunakan untuk mengirim ke client
    SOCKET listensock;//listensock variabel untuk menerima socket dari client
    SOCKADDR_IN address;//address variabel alamat socket
    int addrsize = sizeof(address);

    long ok;//variabel ok tipe data long
    //long tipe data melebihi int

    char message[200];//variable untuk pesan chat

    WSADATA wsd;//data socket
    WORD dllversion;
    dllversion = MAKEWORD(2,1);
    ok = WSAStartup(dllversion, &wsd);//mengaktifkan winsock


    //mengaktifkan socket ke client
    consock = socket(AF_INET,SOCK_STREAM,NULL);//mengaktifkan socket
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//ip server
    address.sin_family = AF_INET;//setting ip ke socket
    address.sin_port = htons(10102);//port

    //menghubungkan untuk menerima pesan dari client
    listensock = socket(AF_INET,SOCK_STREAM,NULL);//menghubungkan socket ke client
    bind(listensock,(SOCKADDR*)&address, sizeof (address));//mengaktifkan penghubung socket
    listen(listensock, SOMAXCONN);//fungsi

    //menunggu connet muncul pesan ini
    cout << "server waitting for connet\n\n";

    //pengulangan pesan yang berulang dari client ke server dan server ke client
    while(true)
    {
        if(consock = accept(listensock,(SOCKADDR*)&address, &addrsize))//megaktifkan socket dan alamat socket
        {
          ok =recv(consock, message, sizeof(message),NULL);//menerima data pesan

          //pesan dari client
          string msg;//variabel pesan client
          msg = message;//disamakan dengan data pesan
          cout<<"client :\t"<<msg<<endl;//output pesan client

          //isi pesan ke client
          string reply;//variabel pesan server
          cout<<"enter reply:\t";//isi pesan
          cin>>reply;

          //mengirim ke client
          const char* s = reply.c_str();
          ok= send(consock,s,1024,NULL);//mengirim data pesan

        }
    }
}
