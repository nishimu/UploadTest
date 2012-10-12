#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/signal.h>
#include <sstream>
#include <sys/stat.h>

#include "ClientServer.h"
#include "Config.h"
#include "Logger.h"


// コンストラクタ
//----------------------------------------------------------------------------
ClientServer::ClientServer( int socket, pid_t pid, Config& conf, Logger& logger, char* clientip, int portno):
	m_ParentPID( pid ), m_Config(conf), m_Logger(logger),
        m_ClientIp(clientip), m_MyPort(portno),
	m_Measure(NGS::MEASURE_INVALID)
{
	Init( socket );
}

//----------------------------------------------------------------------------
// デストラクタ
//----------------------------------------------------------------------------
ClientServer::~ClientServer(void)
{
}

//----------------------------------------------------------------------------
// 初期化処理
//----------------------------------------------------------------------------
void ClientServer::Init( int socket )
{
        timerclear( &m_MeasureTv );

        SetSocket( socket );
}

//----------------------------------------------------------------------------
// 終了時処理
//----------------------------------------------------------------------------
void ClientServer::End(void)
{
	FD_CLR( GetSocket(), &m_Target_fds );
	if ( Close() < 0 ) {
		m_Logger.Error("failed to close [portno=%d]", m_MyPort);
	}

        int oldstate;
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &oldstate);
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);

	int     thReturn;
	Exit( &thReturn );
}

//----------------------------------------------------------------------------
// 終了時処理
//----------------------------------------------------------------------------
void ClientServer::EndExit(void)
{
	int     thReturn;
	Exit( &thReturn );
}

//----------------------------------------------------------------------------
// 終了時処理
//----------------------------------------------------------------------------
void ClientServer::EndClose(void)
{
	FD_CLR( GetSocket(), &m_Target_fds );
	if ( Close() < 0 ) {
		m_Logger.Error("failed to close");
	}

}

//----------------------------------------------------------------------------
// スレッドメイン
//----------------------------------------------------------------------------
void ClientServer::Run(void)
{

	fd_set	org_target_fds;
	struct	timeval	waitval;
	int	selret = 0;
	int	readlen = 0;

	// セレクトタイムアウト時間設定
	waitval.tv_sec  = 0;
	waitval.tv_usec = NGS::SELECT_USEC;

	if ( GetSocket() != NGS::SOCKET_INVALID ) {

		// 監視対象のディスクリプタをゼロクリア
		FD_ZERO( &org_target_fds );
		// ソケットを監視対象に追加
		FD_SET( GetSocket(), &org_target_fds );

		while (1) {

			memcpy( &m_Target_fds, &org_target_fds, sizeof(org_target_fds) );
			selret =  select( GetSocket()+1, &m_Target_fds, NULL, NULL, &waitval );

			if ( FD_ISSET( GetSocket(), &m_Target_fds ) ) {
				int	read_size = -1;

				if (m_Measure == NGS::MEASURE_INVALID) {

					if ( !(m_Measure & NGS::MEASURE_RECEIVING) ) {
						if ( gettimeofday ( &m_MeasureTv, NULL ) ) {
							m_Logger.Error("failed to gettimeofday(for m_MeasureTv)");
						}
					}

					m_Measure = NGS::MEASURE_RECEIVING;
				}

				// データ取得
				char* readp = GetReadBuffP( readlen );
				read_size = Recv( readp, readlen );

				if ( read_size <= 0 ) {
m_Logger.Log(LOG_INFO, "Recv read_size <= 0 ... End\n");
					End();	
				} else {
					// 受信メッセージチェック
					MsgRecv( readp, read_size, selret );
				}
			}

		}
	}
}

//----------------------------------------------------------------------------
// 受信メッセージチェック
//----------------------------------------------------------------------------
void ClientServer::MsgRecv(
	const char* read_buff,	// Read()でリードしたデータのみがセットされたバッファ
	int read_size,		// Read()でリードしたデータサイズ
	int selret )
{
	long read_ret     = 0;

	while(1) {

		read_ret += MsgRecv_Check( &read_buff[read_ret], read_size, selret );
		if ( read_ret >= read_size )	break;
	}
}
long ClientServer::MsgRecv_Check( const char* read_buff, long read_size,
				 int selret )
{
	// リードサイズを返却
	long read_ret = MeasureSend_Rcv( read_buff, read_size, selret );

	return( read_ret );
}

//----------------------------------------------------------------------------
// メッセージ受信処理
//----------------------------------------------------------------------------
int ClientServer::Recv( char* readp, int readlen )
{
	int read_size = Read( readp, readlen, false );

	return ( read_size );
}

//----------------------------------------------------------------------------
// データ送信 受信
//----------------------------------------------------------------------------
long ClientServer::MeasureSend_Rcv( const char* read_buff, long read_size,
				 int selret )
{
	long	read_ret = read_size;

	return ( read_ret );
}

//----------------------------------------------------------------------------
// 終了時処理
//----------------------------------------------------------------------------
void ClientServer::MeasureEnd(void)
{
	// 終了状態とする
	MeasureStateEnd();

}

//----------------------------------------------------------------------------
// 終了状態セット
//----------------------------------------------------------------------------
void ClientServer::MeasureStateEnd(void)
{
	m_Measure = NGS::MEASURE_INVALID;
}


//----------------------------------------------------------------------------
// 受信バッファポインタ取得
//----------------------------------------------------------------------------
char* ClientServer::GetReadBuffP( int& readlen )
{
	char*	retp = m_ReadBuff;
	readlen      = sizeof(m_ReadBuff);

	return ( retp );
}

