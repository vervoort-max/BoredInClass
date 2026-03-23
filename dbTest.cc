#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errMsg = nullptr;

    // Create or open the database file
    int rc = sqlite3_open("mydatabase.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << "\n";
        return 1;
    }

    // SQL to create a table
    const char* sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL);";

    // Execute SQL
    rc = sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << "\n";
        sqlite3_free(errMsg);
    } else {
        std::cout << "Database and table created successfully.\n";
    }

    sqlite3_close(db);
    return 0;
}
