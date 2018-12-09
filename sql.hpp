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
    class Sql{
        MYSQL mysql;
    public:
        std::vector<std::map<std::string,std::string>> query(const std::string&);
        bool update(const std::string&);
        bool remove(const std::string&);
        bool add(const std::string&);
    };
};
#endif /* sql_hpp */
