

#include "Exception.h"

#include "sqlite3.h"


namespace SQLite
{

Exception::Exception(const char* aErrorMessage) :
    mErrcode(-1), // 0 would be SQLITE_OK, which doesn't make sense
    mExtendedErrcode(-1)
{
}
Exception::Exception(const std::string& aErrorMessage) :
    mErrcode(-1), // 0 would be SQLITE_OK, which doesn't make sense
    mExtendedErrcode(-1)
{
}

Exception::Exception(const char* aErrorMessage, int ret) :
    mErrcode(ret),
    mExtendedErrcode(-1)
{
}

Exception::Exception(const std::string& aErrorMessage, int ret) :
    mErrcode(ret),
    mExtendedErrcode(-1)
{
}

Exception::Exception(sqlite3* apSQLite) :
    mErrcode(sqlite3_errcode(apSQLite)),
    mExtendedErrcode(sqlite3_extended_errcode(apSQLite))
{
}

Exception::Exception(sqlite3* apSQLite, int ret) :
    mErrcode(ret),
    mExtendedErrcode(sqlite3_extended_errcode(apSQLite))
{
}

// Return a string, solely based on the error code
const char* Exception::getErrorStr() const  // nothrow
{
    return sqlite3_errstr(mErrcode);
}


}  // namespace SQLite
