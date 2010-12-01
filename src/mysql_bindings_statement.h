/*!
 * Copyright by Oleg Efimov and node-mysql-libmysqlclient contributors
 * See contributors list in README
 *
 * See license text in LICENSE file
 */

#ifndef NODE_MYSQL_STATEMENT_H  // NOLINT
#define NODE_MYSQL_STATEMENT_H

#include <mysql.h>

#include <v8.h>
#include <node.h>
#include <node_events.h>

static Persistent<String> statement_affectedRowsSync_symbol;
static Persistent<String> statement_attrGetSync_symbol;
static Persistent<String> statement_attrSetSync_symbol;
static Persistent<String> statement_closeSync_symbol;
static Persistent<String> statement_errnoSync_symbol;
static Persistent<String> statement_errorSync_symbol;
static Persistent<String> statement_executeSync_symbol;
static Persistent<String> statement_numRowsSync_symbol;
static Persistent<String> statement_prepareSync_symbol;
static Persistent<String> statement_resetSync_symbol;
static Persistent<String> statement_storeResultSync_symbol;
static Persistent<String> statement_sqlStateSync_symbol;

class MysqlStatement : public node::EventEmitter {
  public:
    static Persistent<FunctionTemplate> constructor_template;

    static void Init(Handle<Object> target);

  protected:
    MYSQL_STMT *_stmt;

    MysqlStatement();

    explicit MysqlStatement(MYSQL_STMT *my_stmt):
                                    EventEmitter(), _stmt(my_stmt) {}

    ~MysqlStatement();

    static Handle<Value> New(const Arguments& args);

    static Handle<Value> AffectedRowsSync(const Arguments& args);

    static Handle<Value> AttrGetSync(const Arguments& args);

    static Handle<Value> AttrSetSync(const Arguments& args);

    static Handle<Value> CloseSync(const Arguments& args);

    static Handle<Value> ErrnoSync(const Arguments& args);

    static Handle<Value> ErrorSync(const Arguments& args);

    static Handle<Value> ExecuteSync(const Arguments& args);

    static Handle<Value> NumRowsSync(const Arguments& args);
    
    static Handle<Value> PrepareSync(const Arguments& args);

    static Handle<Value> ResetSync(const Arguments& args);

    static Handle<Value> StoreResultSync(const Arguments& args);

    static Handle<Value> SqlStateSync(const Arguments& args);
};

#endif  // NODE_MYSQL_STATEMENT_H  // NOLINT

