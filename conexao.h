#ifndef	CONEXAO_H_INCLUDED
#define CONEXAO_H_INCLUDED

#include "main.h"

class Conexao {
	private:
		

	public:
		MYSQL_ROW* rows;
		MYSQL* conn;
		MYSQL_RES* resultados;

		Conexao(const char* host, const char* user, const char* senha, const char* db) {
			conn = mysql_init(0);
			conn = mysql_real_connect(conn, host, user, senha, db, 3306, NULL, 0);
		}

		void terminar() {
			delete resultados;
			delete conn;
			delete rows;
		}
};

#endif
