#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/signal.h>
#include <time.h>
#include <netdb.h>
#include <list>
#include <vector>
#include <map>

#include "Const.h"
#include "ClientServer.h"
#include "Config.h"
#include "Logger.h"
#include "Struct.h"

//
// 外部データ
//

// オブジェクトとして残ったままとなった場合を考慮して
// タイムアウト処理を追加
std::map<long, ClientServer*>	g_CObjList;		// クライアントオブジェクトリスト
Socket				g_Serv;			// サーバクラスオブジェクト

Config*				g_conf;			// 設定ファイル
Logger				g_Logger;		// ログオブジェクト

// サーバクローズ
void sigkill_handler( int sig )
{
// DELLOG
g_Logger.Log(LOG_INFO, "signal SIGINT/SIGKILL called (sig=%d)\n", sig);
g_Logger.Print("signal SIGINT/SIGKILL called (sig=%d)\n", sig);

	// リスニングソケット クローズ
	if ( g_Serv.Close() < 0 ) {
		perror( "socket close failure" );
		g_Logger.Error("socket close failure");
	}

	g_Logger.Log(LOG_INFO, "Shutdown %s", (*g_conf)["logger"]["progname"].c_str());
	g_Logger.Print("Shutdown %s\n", (*g_conf)["logger"]["progname"].c_str());

	exit(0);
}

//----------------------------------------------------------------------------
// メインプロセス
//----------------------------------------------------------------------------
int MainProc(void)
{
	fd_set	target_fds;
	fd_set	org_target_fds;

	g_Logger.Log(LOG_INFO, "- Start Main proccess");
	g_Logger.Print("- Start Main proccess\n");

	// バインドアドレス取得
	ulong bindaddr = htonl(INADDR_ANY);
	std::string bindaddr_str = (*g_conf)["server"]["address"];
	if (!bindaddr_str.empty()) {
		bindaddr = inet_addr(bindaddr_str.c_str());
	}
	g_Logger.Log(LOG_INFO, "- Address = %s", bindaddr_str.c_str());
	g_Logger.Print("- Address = %s\n", bindaddr_str.c_str());

	// バインドポート取得
	int portno = NGS::PORT_NO;
	std::string portno_str = (*g_conf)["server"]["portno"];
	if (!portno_str.empty()) {
		portno = atoi(portno_str.c_str());
	}
	g_Logger.Log(LOG_INFO, "- Port No. = %d", portno);
	g_Logger.Print("- Port No. = %d\n", portno);

g_Logger.Print("### server   = %s:%d\n", bindaddr_str.c_str(), portno);

	// プロセスID取得
	pid_t	pid = getpid();
	g_Logger.Log(LOG_INFO, "- PID = %d", pid);
	g_Logger.Print("- PID = %d\n", pid);

	// シグナルハンドラを設定
	signal( SIGINT,   sigkill_handler );
	signal( SIGTERM,  sigkill_handler );

	// サーバ リスニングソケットオープン
	if ( g_Serv.Open() == NGS::SOCKET_INVALID ) {
		perror("socket open");
		g_Logger.Error("socket open");
		exit(1);
	}

	// リスニングソケット オプション設定
	if ( g_Serv.SetSockOpt( SOL_SOCKET, SO_REUSEADDR ) < 0) {
		perror("setsockopt");
		g_Logger.Error("setsockopt");
		exit(1);
	}

	// 接続要求の監視
	if ( g_Serv.Listen( bindaddr, portno, NGS::MAX_CONNECT) < 0 ) {
		exit(1);
	}

	// 監視対象のディスクリプタをゼロクリア
	FD_ZERO(&org_target_fds);
	// リスニングソケットを監視対象に追加
	FD_SET( g_Serv.GetSocket(), &org_target_fds);

	// Portnoチェック
	std::string chkport_str = (*g_conf)["server"]["portno"];
	int chkport = atoi(chkport_str.c_str());

	while (1) {
		memcpy (&target_fds, &org_target_fds, sizeof(org_target_fds));
		pselect( g_Serv.GetSocket()+1, &target_fds, NULL, NULL, NULL, NULL );

		if ( FD_ISSET (g_Serv.GetSocket(), &target_fds) ) {

			int	new_socket = NGS::SOCKET_INVALID;
			new_socket = g_Serv.Accept();

			if ( new_socket != NGS::SOCKET_INVALID ) {
				g_Logger.Print("Cliend accept...\n");

				// クライアントオブジェクト生成
				char* clientip = g_Serv.ClientIp();
				ClientServer* p = new ClientServer( new_socket, pid, *g_conf, g_Logger, clientip, chkport);

                                time_t  timer;
                                time(&timer);
                                struct tm*      local;
                                local = localtime(&timer);
                                struct tm tmvalue = *local;
                                time_t result = mktime(&tmvalue);

                                g_CObjList.insert( std::map<long, ClientServer*>::value_type((long)result, p) );
				if (p) {
					if ( p->Start() != 0 ) {
						g_Logger.Error("[ポート%d] Client Start ERROR\n", chkport);
                                                sleep(1);
                                                exit(1);
					}
				}
			}
			else {
				sleep(1);
			}
		}		
	}

	return (0);
}

//----------------------------------------------------------------------------
// メイン
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	// 設定ファイル読み込み
	int c;
	std::string conffile = "";
	while (( c = getopt(argc, argv, "dc:")) != -1) {
		switch (c) {
		case 'd':
			g_isDaemon = 1;
			break;
		case 'c':
			conffile = optarg;
			break;
		}
	}
	g_conf = new Config(conffile);

	// Loggerオブジェクト初期化
	g_Logger.Init(g_conf);
	g_Logger.Log(LOG_INFO, "Start %s", (*g_conf)["logger"]["progname"].c_str());
	g_Logger.Print("Start %s\n", (*g_conf)["logger"]["progname"].c_str());
	g_Logger.Log(LOG_INFO, "- Config File = %s", conffile.c_str());
	g_Logger.Print("- Config File = %s\n", conffile.c_str());

	// オブジェクトクリア
	g_CObjList.clear();

	int pid = 0;
	if (g_isDaemon) {
		pid = fork();
	}

	int ret = 0;
	if (pid == 0) {
		// ポート番号取得
		int portno = NGS::PORT_NO;
		const char* portno_ch = 0;
		std::string portno_c = (*g_conf)["server"]["portno"];
		if (!portno_c.empty()) {
			portno_ch = portno_c.c_str();
			sscanf(portno_ch, "%d", &portno);
		}

		char pidfile[255];
		if (portno == NGS::PORT_NO) {
			sprintf(pidfile, "/var/run/ngspeed.pid");
		} else {
			sprintf(pidfile, "/var/run/ngspeed-%d.pid", portno);
		}

		// save Pid
		FILE* lfp = fopen(pidfile, "w+");
		if (lfp) {
			fprintf(lfp,"%d",getpid());
			fclose(lfp);
		} else {
			g_Logger.Error("PID file open error.");
		}

		//while (!isTerminate)
		//{
			ret = MainProc();
		//}

	}
	else if (pid < 0) {
		ret = -1;
	}

	return (ret);
}

