#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "main.h"

using namespace std;

class Menu {
	private:

	public:
		void showdb(int qs, MYSQL* conn, MYSQL_RES* res){
			topo();
			MYSQL_ROW row;
			string query = "SELECT * FROM cliente";
			const char* q = query.c_str();
			qs = mysql_query(conn, q);
			if (!qs)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					printf("CPF: %s, Name: %s, Telefone: %s, Email: %s\n", row[0], row[1], row[2], row[3]);
				}
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
			}
			system("pause");
		}


		void incluirdb(int qs, MYSQL* conn, string n, string c, string e, string t) {
			string query = "INSERT INTO cliente (cpf, nome, telefone, email) VALUES ('" + c + "', '" + n + "', '" + t + "', '" + e + "');";
			const char* q = query.c_str();
			qs = mysql_query(conn, q);
			if (qs)
			{
				topo();
				cout << "Query failed: " << mysql_error(conn) << endl;
				system("pause");
			}
		}

		void criarPerfil(int qs, MYSQL* conn, MYSQL_RES* res) {
			topo();
			string name, cpf, email, telefone;
			cout << "Digite o nome do cliente: ";
			cin >> name;
			topo();
			cout << "Digite o cpf de " << name << ": ";
			cin >> cpf;
			topo();
			cout << "Digite o emiail de " << name << " (opcioinal): ";
			cin >> email;
			topo();
			cout << "Digite o telefone de " << name << " (opcional): ";
			cin >> telefone;
			incluirdb(qs, conn, name,cpf,email,telefone);
		}

		void topo() {
			system("cls");
			cout << "===================================================\n";
			cout << "		 Banco de Dados C++\n";
			cout << "===================================================\n";
		}
};

#endif