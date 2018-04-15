

#pragma once

#include <stdexcept>
#include <string>

// Forward declaration to avoid inclusion of <sqlite3.h> in a header
struct sqlite3;

/// Compatibility with non-clang compilers.
#ifndef __has_feature
    #define __has_feature(x) 0
#endif

 

namespace SQLite
{


/**
 * @brief Encapsulation of the error message from SQLite3, based on std::runtime_error.
 */
class Exception /*: public std::runtime_error*/
{
public:
    /**
     * @brief Encapsulation of the error message from SQLite3, based on std::runtime_error.
     *
     * @param[in] aErrorMessage The string message describing the SQLite error
     */
    explicit Exception(const char* aErrorMessage);
    explicit Exception(const std::string& aErrorMessage);

    /**
     * @brief Encapsulation of the error message from SQLite3, based on std::runtime_error.
     *
     * @param[in] aErrorMessage The string message describing the SQLite error
     * @param[in] ret           Return value from function call that failed.
     */
    Exception(const char* aErrorMessage, int ret);
    Exception(const std::string& aErrorMessage, int ret);

   /**
     * @brief Encapsulation of the error message from SQLite3, based on std::runtime_error.
     *
     * @param[in] apSQLite The SQLite object, to obtain detailed error messages from.
     */
    explicit Exception(sqlite3* apSQLite);

    /**
     * @brief Encapsulation of the error message from SQLite3, based on std::runtime_error.
     *
     * @param[in] apSQLite  The SQLite object, to obtain detailed error messages from.
     * @param[in] ret       Return value from function call that failed.
     */
    Exception(sqlite3* apSQLite, int ret);

    /// Return the result code (if any, otherwise -1).
    inline int getErrorCode() const  // nothrow
    {
        return mErrcode;
    }

    /// Return the extended numeric result code (if any, otherwise -1).
    inline int getExtendedErrorCode() const  // nothrow
    {
        return mExtendedErrcode;
    }

    /// Return a string, solely based on the error code
    const char* getErrorStr() const ; // nothrow

private:
    int mErrcode;         ///< Error code value
    int mExtendedErrcode; ///< Detailed error code if any
};


}  // namespace SQLite
