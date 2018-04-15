
#include "Transaction.h"

#include "Database.h"


namespace SQLite
{


// Begins the SQLite transaction
Transaction::Transaction(Database& aDatabase) :
    mDatabase(aDatabase),
    mbCommited(false)
{
    mDatabase.exec("BEGIN");
}

// Safely rollback the transaction if it has not been committed.
Transaction::~Transaction()
{
    if (false == mbCommited)
    {
       // try
        {
            mDatabase.exec("ROLLBACK");
        }
        //catch (SQLite::Exception&)
        {
            // Never throw an exception in a destructor: error if already rollbacked, but no harm is caused by this.
        }
    }
}

// Commit the transaction.
void Transaction::commit()
{
    if (false == mbCommited)
    {
        mDatabase.exec("COMMIT");
        mbCommited = true;
    }
    else
    {
        //throw SQLite::Exception("Transaction already commited.");
    }
}


}  // namespace SQLite
