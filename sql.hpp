//
//  sql.hpp
//  mysql2
//
//  Created by 贾皓翔 on 2018/12/9.
//  Copyright © 2018 贾皓翔. All rights reserved.
//

#ifndef sql_hpp
#define sql_hpp
#include <map>
#include <vector>
#include <stdio.h>
#include <string>
#include <mysql.h>
namespace SQL{
    struct ConnectError{};
    class Sql{
        MYSQL conn;
    public:
        Sql(const std::string&host,const std::string&user,const std::string &passwd,const std::string &db,unsigned int port=0);
        std::vector<std::map<std::string,std::string>> query(const std::string&);
//        bool update(const std::string&);
//        bool remove(const std::string&);
//        bool add(const std::string&);
    };
};
#endif /* sql_hpp */
