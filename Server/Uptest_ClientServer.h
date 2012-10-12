#ifndef	__CLIENTSERVER_H__
#define	__CLIENTSERVER_H__

#include <list>
#include <iostream>
#include <string>

#include "Socket.h"
#include "Thread.h"
#include "Const.h"
#include "Struct.h"

class Config;
class Logger;
class TiXmlElement;

class	ClientServer : public Socket, public Thread
{
public:
	// コンストラクタ
	ClientServer( int socket, pid_t pid, Config& conf, Logger& logger, char* clientip, int portno );

	// デストラクタ
	virtual	~ClientServer(void);

	// スレッド処理
	virtual void Run(void);

	// 終了時処理
	virtual void EndExit(void);

	// 終了時処理
	virtual void EndClose(void);

private:
	pid_t		m_ParentPID;
	fd_set		m_Target_fds;
	Config&		m_Config;		// 設定ファイル
	Logger&		m_Logger;		// ログオブジェクト
	char*		m_ClientIp;		// クライアントIPアドレス情報
	int		m_MyPort;		// 自ポートNo

	char 		m_ReadBuff[4024];	// 受信バッファ
						// （Read()でリードしたデータを格納）

	//------------ メソッド ----------------------------------------------------------
	// 初期化処理
	virtual void Init( int socket );

	// 終了時処理
	virtual void End(void);

	// 受信メッセージチェック
	virtual void MsgRecv( const char* read_buff, int read_size,
				 struct timeval& tv1, struct timeval& tv2, int selret );
	virtual long MsgRecv_Check( const char* read_buff, long read_size,
				 struct timeval& tv1, struct timeval& tv2, int selret );

	// メッセージ受信処理
	int Recv( char* readp, int readlen );

	// selectタイムアウト値 設定
	virtual void SetSelectTime( struct timeval& waitval );

	//--------------------------------------------------------------------------------
	// メッセージ送受信関連
	//--------------------------------------------------------------------------------
	//データ送信 受信
	virtual long MeasureSend_Rcv( const char* read_buff, long read_size,
				 	struct timeval& tv1, struct timeval& tv2, int selret );

	// 終了時処理
	virtual void MeasureEnd(void);

	// 終了状態セット
	virtual void MeasureStateEnd(void);

	// 受信バッファポインタ取得
	virtual char* GetReadBuffP( int& readlen );

};
#endif // __CLIENTSERVER_H__
