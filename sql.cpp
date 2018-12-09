//
//  sql.cpp
//  mysql2
//
//  Created by 贾皓翔 on 2018/12/9.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#include "sql.hpp"
#include <memory>
#include <iostream>
namespace SQL{
    Sql::Sql(const std::string&host,const std::string&user,const std::string &passwd,const std::string &db,unsigned int port){
        mysql_init(&conn);
        if(!mysql_real_connect(&conn,host.c_str(),user.c_str(),passwd.c_str(),db.c_str(),port,NULL,CLIENT_FOUND_ROWS))
            throw ConnectError();
    }
    std::vector<std::map<std::string,std::string>> Sql::query(const std::string& s){
        typedef std::vector<std::map<std::string,std::string>> RT;
        int res=mysql_query(&conn,s.c_str());
        if(res)
            throw ConnectError();
        MYSQL_RES *result=mysql_store_result(&conn);
        long long rowcount = mysql_num_rows(result);
//        std::cout<<rowcount<<std::endl;
        RT r(rowcount);
        int fieldcount = mysql_num_fields(result);
        MYSQL_FIELD *field = NULL;
        for(long long i=0;i<rowcount;i++){
            MYSQL_ROW row = mysql_fetch_row(result);
            for(int j=0;j<fieldcount;j++){
                field = mysql_fetch_field_direct(result,j);
                r[i][field->name]=row[j];
            }
        }
//        int fieldcount = mysql_num_fields(result);
        mysql_free_result(result);
        return r;
    }
    bool Sql::update(const std::string& s){
        int res=mysql_query(&conn,s.c_str());
        if(res)
            return false;
        return true;
    }
    Sql::~Sql(){
        mysql_close(&conn);
    }
}
