//
//  main.cpp
//  mysql2
//
//  Created by 贾皓翔 on 2018/12/9.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include <iostream>
#include <mysql.h>
#include "sql.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    SQL::Sql s("localhost","jhx","123456","test");
    auto i=s.query("select * from people");
//    MYSQL conn;
//    mysql_init(&conn);
//    int rs;
//
//    if(mysql_real_connect(&conn,"localhost","jhx","123456","test",0,NULL,CLIENT_FOUND_ROWS)){
//        cout<<"yes"<<endl;
//        rs=mysql_query(&conn,"select * from people");
//        if(rs)
//            cout << "error" << endl;
//        else
//            cout << "OK" << endl;
//        MYSQL_RES *result = mysql_store_result(&conn);
//        long long rowcount = mysql_num_rows(result);
//        cout << rowcount << endl;
//        int fieldcount = mysql_num_fields(result);
//        cout << fieldcount << endl;
//
//
//        cout << endl;
//        MYSQL_FIELD *field = NULL;
//        MYSQL_ROW row = NULL;
//        row = mysql_fetch_row(result);
//        for(int i = 0; i < fieldcount; i++)
//        {
//            field = mysql_fetch_field_direct(result,i);
//            cout << field->name << "\t\t";
//        }
//        while(NULL != row)
//        {
//            for(int i=0; i<fieldcount; i++)
//            {
//                cout << row[i] << "\t\t";
//            }
//            cout << endl;
//            row = mysql_fetch_row(result);
//        }
//        mysql_close(&conn);
//    }else
//        cout<<"no"<<endl;
    return 0;
}
