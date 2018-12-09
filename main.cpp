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
    cout<<i.size()<<endl;
    return 0;
}
